#include "remote_execute.h"

#include <fcntl.h>
#include <linux/seccomp.h>
#include <seccomp.h>
#include <sys/prctl.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>

constexpr int kOneMb = 1024 * 1024;
static char kGppName[] = "/usr/bin/g++";
static char kGppReadFromStdin[] = "-x";
static char kGppLanguage[] = "c++";
static char kDash[] = "-";
static char kGppOutputFlag[] = "-o";
static char kGppOutputFile[] = "./tmp/";
static char kPath[] = "PATH=/usr/bin";

// Max program output : 256 kb.
static const size_t kMaxProgramOutput = 256 * 1024;

// Instructions
//
// 1) Mount tmp directory as tmpfs;
// sudo mount -t tmpfs -o size=16m tmpfs ./tmp
//
//
namespace remo_code {
namespace {

void WeakProcessLimit() {
  // Restrict the amount of CPU time for the compilation.
  const struct rlimit cpu_limit = {10, 10};
  setrlimit(RLIMIT_CPU, &cpu_limit);

  // Restrict the virtual memory size.
  const struct rlimit mem_limit = {128 * kOneMb, 128 * kOneMb};
  setrlimit(RLIMIT_AS, &mem_limit);

  // Restrict the output file size.
  const struct rlimit fs_limit = {2 * kOneMb, 2 * kOneMb};
  setrlimit(RLIMIT_FSIZE, &fs_limit);
}

void StrictProcessLimit() {
  // Restrict the amount of CPU time for the compilation.
  const struct rlimit cpu_limit = {5, 5};
  setrlimit(RLIMIT_CPU, &cpu_limit);

  // Restrict the virtual memory size.
  const struct rlimit mem_limit = {128 * kOneMb, 128 * kOneMb};
  setrlimit(RLIMIT_AS, &mem_limit);

  // Restrict the data segment size.
  const struct rlimit data_seg_limit = {64 * kOneMb, 64 * kOneMb};
  setrlimit(RLIMIT_AS, &data_seg_limit);

  // Restrict the output file size.
  const struct rlimit fs_limit = {0 * kOneMb, 0 * kOneMb};
  setrlimit(RLIMIT_FSIZE, &fs_limit);
}

zmq::message_t str_to_zmq_msg(const string& s) {
  zmq::message_t msg(s.size());
  memcpy(msg.data(), s.c_str(), s.size());
  return msg;
}

}  // namespace

string RemoteExecuter::SyncCompile(const string& code, int index) {
  int pipe_p2c[2], pipe_c2p[2];
  if (pipe(pipe_p2c) != 0 || pipe(pipe_c2p) != 0) {
    return "Pipe is broken :(";
  }

  auto pid = fork();
  if (pid < 0) {
    // Fork error :(
    return "Something went wrong :(";
  } else if (pid == 0) {
    // We are in the child process.

    // Close write end and link STDIN through the pipe.
    close(pipe_p2c[1]);
    dup2(pipe_p2c[0], STDIN_FILENO);
    dup2(pipe_c2p[1], STDERR_FILENO);
    close(pipe_p2c[0]);

    // Build a output file name.
    char output_file_name[100];
    snprintf(output_file_name, 100, "%s%d", kGppOutputFile, index);

    // Build argv and env for execve.
    char* gpp_argv[] = {kGppName,       kGppReadFromStdin, kGppLanguage, kDash,
                        kGppOutputFlag, output_file_name,  NULL};
    char* env[] = {kPath, NULL};

    // Apply weak process limits.
    WeakProcessLimit();

    // Execute the g++.
    int ret = execve(gpp_argv[0], gpp_argv, env);
    return std::to_string(ret);  // Should not be reached if success.
  } else {
    // We are in the parent process.
    close(pipe_p2c[0]);
    close(pipe_c2p[1]);
    // Send the code through the pipe.
    write(pipe_p2c[1], code.c_str(), code.size());
    close(pipe_p2c[1]);

    char buf[1024];
    int read_cnt;
    string compiler_output;
    while ((read_cnt = read(pipe_c2p[0], buf, 1024)) > 0) {
      auto current_size = compiler_output.size();
      compiler_output.reserve(current_size + read_cnt + 1);
      for (int i = 0; i < read_cnt; i++) {
        compiler_output.push_back(buf[i]);
      }
    }
    close(pipe_c2p[0]);

    int status;
    waitpid(pid, &status, 0);  // Wait for the compile to end.
    if (!WIFEXITED(status)) {
      return "Compilation went wrong.. :(";
    }
    return compiler_output;
  }
  return "";
}

string RemoteExecuter::SyncExecute(const string& std_input, int index) {
  // Now we have the compiled executable.
  int pipe_p2c[2], pipe_c2p[2];
  if (pipe(pipe_p2c) != 0 || pipe(pipe_c2p) != 0) {
    return "Pipe is broken (during Execution) :(";
  }
  auto pid = fork();
  if (pid < 0) {
    // Fork error :(
    return "Something went wrong :(";
  } else if (pid == 0) {
    // We are in the child process.

    // Close write end and link STDIN through the pipe.
    close(pipe_p2c[1]);
    dup2(pipe_p2c[0], STDIN_FILENO);
    dup2(pipe_c2p[1], STDOUT_FILENO);
    close(pipe_p2c[0]);

    // Build a output file name.
    char file_to_exec[100];
    snprintf(file_to_exec, 100, "%s%d", kGppOutputFile, index);

    // Build argv and env for execve.
    char* gpp_argv[] = {file_to_exec, NULL};

    // Apply strict process limits to prevent abnormal activities.
    StrictProcessLimit();

    // Restrict the possible syscalls (only allow read, write, exit).
    // Also we have to allow execve on itself for once.
    scmp_filter_ctx ctx;

    // Kill the process immediately upon violation.
    ctx = seccomp_init(SCMP_ACT_KILL);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigreturn), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(brk), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munmap), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mprotect), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigprocmask), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(close), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstat), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(arch_prctl), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(access), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(openat), 0);

    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(execve), 1,
                     SCMP_A0(SCMP_CMP_EQ, (scmp_datum_t)(file_to_exec)));
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 1,
                     SCMP_CMP(1, SCMP_CMP_MASKED_EQ, O_RDONLY, O_RDONLY));
    seccomp_load(ctx);

    int ret = execvp(file_to_exec, gpp_argv);
    return std::to_string(ret);  // Should not be reached if success.
  } else {
    // We are in the parent process.
    close(pipe_p2c[0]);
    close(pipe_c2p[1]);

    // Send the input (stdin) through the pipe.
    write(pipe_p2c[1], std_input.c_str(), std_input.size());
    close(pipe_p2c[1]);

    char buf[1024];
    int read_cnt;
    string program_output;
    while ((read_cnt = read(pipe_c2p[0], buf, 1024)) > 0) {
      auto current_size = program_output.size();
      program_output.reserve(current_size + read_cnt + 1);
      for (int i = 0; i < read_cnt; i++) {
        program_output.push_back(buf[i]);
      }
      if (program_output.length() > kMaxProgramOutput) {
        // If the program output exceeds max size, then just kill the process.
        kill(pid, SIGKILL);

        program_output.append("... (too long; omitted) ...");
        break;
      }
    }
    close(pipe_c2p[0]);

    int status;
    waitpid(pid, &status, 0);  // Wait for the compile to end.
    if (!WIFEXITED(status)) {
      return "Program has terminated in an abnormal way.. :(";
    }
    return program_output;
  }
  return "";
}

void RemoteExecuter::CodeExecutionThread(int thread_index) {
  while (true) {
    // Wait for the codes.
    std::unique_lock<std::mutex> lock(code_q_lock_);
    cond_code_q_.wait(lock, [this]() { return codes_.size() > 0; });

    // Fetch the first code to execute.
    auto index_and_code = codes_.front();
    codes_.pop();
    lock.unlock();

    // Notify other threads to wake up since there might be other codes in the
    // queue.
    cond_code_q_.notify_all();

    // Execute the code and save it to the result queue.
    string result = SyncCompile(index_and_code.second, thread_index);

    // If compilation is succeeded, then we execute the program.
    string program_output = SyncExecute("", thread_index);

    result = std::to_string(index_and_code.first) + ":" + result + ":" +
             program_output;
    zmq_sock_mutex_.lock();
    publisher_->send(str_to_zmq_msg(result));
    zmq_sock_mutex_.unlock();
  }
}

void RemoteExecuter::AddCodeToExecute(const string& code, int index) {
  std::unique_lock<std::mutex> lock(code_q_lock_);
  codes_.push(std::make_pair(index, code));
  lock.unlock();

  // Nofity one of the thread.
  cond_code_q_.notify_one();
}

RemoteExecuter::RemoteExecuter(zmq::socket_t* publisher)
    : publisher_(publisher) {
  // Build a thread pool.
  for (int i = 0; i < 3; i++) {
    threads_.emplace_back(
        std::thread(&RemoteExecuter::CodeExecutionThread, this, i + 1));
  }
}
}  // namespace remo_code
