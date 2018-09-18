import os


def handle(data):

  def check_line(line):

    def check_char(c):
      if 'a' <= c <= 'z' or 'A' <= c <= 'Z' or '0' <= c <= '9':
        return True
      elif c in {
          '(', ')', '{', '}', ',', '.', '!', '+', '-', '*', '/', '=', '[', ']',
          '<', '>', '~', '_', '&', '%', '|', '?'
      }:
        return True
      return False

    def is_code_chunk(s):
      for c in s:
        if not check_char(c):
          return False
      return True

    words = line.split(' ')

    i = 0
    inline_code_start = False
    while i < len(words):
      w = words[i]
      if not is_code_chunk(w):
        if inline_code_start:
          words[i - 1] = words[i - 1] + '`'
        inline_code_start = False

      if is_code_chunk(w):
        if w.startswith('('):
          while i < len(words):
            if ')' in words[i]:
              break
            i += 1
        elif not inline_code_start:
          inline_code_start = True
          words[i] = '`' + w
      i += 1

    if inline_code_start:
      words[-1] = words[-1] + '`'

    annotated = ' '.join(words)
    annotated = annotated.replace("``", "")

    i = 0
    while i < len(annotated):
      if annotated[i] == '`':
        end = annotated.find('`', i + 1)
        w = annotated[i + 1:end]
        if w in {'C', 'C++', 'Psi', 'C++ 11'}:
          annotated = annotated[:i] + w + annotated[end + 1:]
          continue
        elif w.isdigit() or (w.startswith('-') and w[1:].isdigit()):
          annotated = annotated[:i] + w + annotated[end + 1:]
          continue

      i += 1

    return annotated

  lines = data.split('\n')

  fixed_lines = []
  in_code = False
  in_header = False
  cnt = 0
  for line in lines:
    cnt += 1
    if line[:5] == '-----':
      in_header = not in_header
      fixed_lines.append(line)
      continue

    if line[:3] == '###':
      fixed_lines.append(line)
      continue

    if in_header:
      fixed_lines.append(line)
      continue

    if line[:3] == '```':
      in_code = not in_code
      fixed_lines.append(line)
      continue

    if not in_code:
      fixed_lines.append(check_line(line))
    else:
      fixed_lines.append(line)

  return '\n'.join(fixed_lines)


if __name__ == "__main__":
  for filename in os.listdir("../md"):
    real_filename = "../md/" + filename
    with open(real_filename, "r+") as f:
      data = f.read()
      f.seek(0)
      f.write(handle(data))