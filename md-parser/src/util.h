#include <experimental/optional>
#include <iostream>
#include <string>
#include <utility>
#define LOG \
  Log::GetInstance().SetCurrentDebugInfo(__FILE__, __LINE__).PrintDebugInfo()

using std::string;
namespace md_parser {
std::experimental::optional<size_t> ReadUntilEndOfLine(const string& content,
                                                       size_t start);
std::pair<int, int> TrimLeft(string* str);
string FetchFirstToken(const string& line);
string::const_iterator FindFirstOfAny(const string& str,
                                      const string& matching_chars);

// Concatenates strings into one.
string StrCat(const string& s);

template <typename... Ts>
string StrCat(const string& s, Ts... args) {
  return s + StrCat(args...);
}

template <typename T>
T Max(const T& a, const T& b) {
  return a > b ? a : b;
}

template <typename... Ts, typename T>
T Max(const T& a, Ts... args) {
  const T& b = Max(args...);
  return a > b ? a : b;
}

// Class for a convenient logging. This is a singleton class.
class Log {
 public:
  static const Log& GetInstance() {
    static const Log log;
    return log;
  }

  template <typename T>
  const Log& operator<<(const T& t) const {
    std::cout << t;
    return *this;
  }

  const Log& PrintDebugInfo() const {
    std::cout << std::endl << "(" << file_name_ << ":" << line_ << ") ";
    return *this;
  }

  const Log& SetCurrentDebugInfo(const char* f, int line) const {
    file_name_ = f;
    line_ = line;
    return *this;
  }

 private:
  Log() {}

  mutable const char* file_name_;
  mutable int line_;

 public:
  Log(const Log&) = delete;
  void operator=(const Log&) = delete;
};

}  // namespace md_parser
