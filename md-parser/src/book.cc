#include "book.h"

#include <fstream>

#include "util.h"

namespace md_parser {
namespace {
struct Package {
  string package_name;
  string package_option;

  Package(const string& package_name, const string& package_option = "")
      : package_name(package_name), package_option(package_option) {}
};

string AddPackage(const Package& package) {
  if (package.package_option.empty()) {
    return StrCat("\\usepackage{", package.package_name, "}\n");
  } else {
    return StrCat("\\usepackage[", package.package_option, "]{",
                  package.package_name, "}\n");
  }
}

string AddBunchOfPackages(const std::vector<Package> package_list) {
  string tex;
  for (const auto& pkg : package_list) {
    tex += AddPackage(pkg);
  }
  return tex;
}

string BookTypeToDirName(BookType type) {
  switch (type) {
    case C:
      return "c";
    case CPP:
      return "cpp";
  }
  return "";
}
// Creates a tex comment in a following format
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// % some tex comment comes here %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
string AddFancyComment(const string& comment, const int comment_width = 55) {
  string long_tex_comment(comment_width, '%');
  long_tex_comment += "\n";

  string tex = "\n";
  tex.reserve(long_tex_comment.size() * 2 + comment.size());
  tex += long_tex_comment;
  tex += "% ";

  int current_line_len = 0;
  for (char c : comment) {
    current_line_len++;

    if (c == '\n') {
      tex.append(
          StrCat(string(comment_width - 2 - current_line_len, ' '), "%\n"));
      tex.append("% ");
      current_line_len = 0;
    } else {
      tex.push_back(c);
      if (current_line_len % (comment_width - 4) == 0) {
        tex.append(" %\n% ");
        current_line_len = 0;
      }
    }
  }
  if (current_line_len > 0) {
    tex.append(
        StrCat(string((comment_width - 3) - current_line_len, ' '), "%\n"));
  }
  tex += long_tex_comment;
  return tex;
}

}  // namespace

BookManager::BookManager(
    BookType book_type,
    const std::map<string, std::map<string, string>>* file_info)
    : book_type_(book_type), file_info_(file_info) {
  if (book_type_ == BookType::C) {
    book_list_.push_back("5");
  } else if (book_type_ == BookType::CPP) {
    book_list_.push_back("134");
  }

  // Create the list of included file names.
  while (true) {
    const auto& current_file = book_list_.back();
    const auto current_file_info_itr = file_info_->find(current_file);
    if (current_file_info_itr == file_info_->end()) {
      break;
    }
    const auto next_page_itr = current_file_info_itr->second.find("next_page");
    if (next_page_itr == current_file_info_itr->second.end()) {
      break;
    }
    book_list_.push_back(next_page_itr->second);
  }
}

void BookManager::GenerateMainTex() {
  string tex = "\\documentclass[a4paper, 10pt]{memoir}\n";
  std::vector<Package> package_list = {{"inputenc", "utf8"},
                                       {"lmodern"},
                                       {"minted"},
                                       {"ulem", "normalem"},
                                       {"kotex"},
                                       {"amsmath"},
                                       {"amssymb"},
                                       {"geometry"},
                                       {"listings"},
                                       {"xspace"},
                                       {"epigraph"},
                                       {"xcolor"},
                                       {"graphicx"},
                                       {"grffile"},
                                       {"pygmentize"},
                                       {"tcolorbox"},
                                       {"csquotes"},
                                       {"caption"},
                                       {"fancyvrb"},
                                       {"hyperref", "pdfencoding=auto"},
                                       {"titlesec"},
                                       {"verbatim"},
                                       {"spverbatim"},
                                       {"marginnote"},
                                       {"mdframed", "framemethod=TikZ"},
                                       {"fontenc", "T1"},
                                       {"adjustbox", "export"},
                                       {"svg"},
                                       {"color"},
                                       {"beramono"},
                                       {"letltxmacro"},
                                       {"sourcecodepro"}};
  tex += AddBunchOfPackages(package_list);

  // Add note for generating pygmentize.sty
  tex += AddFancyComment(
      "Note: To generate pygmentize.sty, use \npygmentize -S default -f tex > "
      "pygments.sty");

  // Relative path for all image files.
  tex += "\\graphicspath {{../../static/}}\n";

  // Define mdprogout and sidenote box.
  tex += R"(
\newmdenv[%
  backgroundcolor=black!5,
  frametitlebackgroundcolor=black!10,
  roundcorner=5pt,
  skipabove=\topskip,
  innertopmargin=\topskip,
  splittopskip=\topskip,
  frametitle={실행 결과},
  frametitlerule=true,
  nobreak=false,
  usetwoside=false
]{mdprogout}

\newmdenv[leftline=false,rightline=false,font=\footnotesize]{sidenotebox}
)";

  tex += R"(
\setminted[cpp]{
  frame=single,
  framesep=2mm,
  baselinestretch=1.2,
  tabsize=2,
  fontsize=\small
}
)";

  // Set Paragraph indent size and paragraph skip size.
  tex += R"(
\setlength{\parindent}{0em}
\setlength{\parskip}{0.5em}
)";

  // Geometry
  tex += R"(
\geometry {
  bottom=30mm
}
\semiisopage[12]
)";

  // Spacing between lines.
  tex += R"(
\renewcommand{\baselinestretch}{1.3}
)";

  // Fixing minted spacing issue.
  tex += R"(
\setlength\partopsep{-\topsep}
\addtolength\partopsep{-\parskip}
\addtolength\partopsep{0.3cm}
)";

  // TOC only shows up to the subsection.
  tex += R"(
\setcounter{tocdepth}{4}
\setcounter{secnumdepth}{4}
)";

  tex += "\\begin{document}\n";

  // Choose English font
  tex += R"(\fontfamily{cmss}\selectfont)";

  // Introduction page.
  tex += AddFancyComment("Introduction Page");
  tex += R"(
\thispagestyle{empty}
~\vfill
\noindent Copyright \textcopyright\  2017 이재범

\noindent
이 책은 \textbf{모두의 코드}에 연재된 씹어먹는 C++ 강좌를 책으로 옮긴 것입니다.해당 강좌는 자세한 내용은
\url{https://modoocode.com} 에서 볼 수 있습니다
\newpage
)";

  tex += "\\tableofcontents\n\\mainmatter\n";
  // Add \include{filename}
  tex += AddFancyComment("List of book files.");
  for (const string& file_name : book_list_) {
    auto chapter_itr = file_info_->at(file_name).find("chapter");
    if (chapter_itr != file_info_->at(file_name).end()) {
      string chapter = chapter_itr->second;
      tex += StrCat("\n\\chapter{", chapter, "}\n");
    }
    auto title_itr = file_info_->at(file_name).find("tex_title");
    if (title_itr != file_info_->at(file_name).end()) {
      string title = title_itr->second;
      tex += StrCat("\n\\section*{", title, "}\n");
    }
    tex += StrCat("\\input{", file_name, "}\n");
  }

  tex += "\\end{document}";

  // Generate main.tex
  std::ofstream tex_out(
      StrCat("../book/", BookTypeToDirName(book_type_), "/main.tex"));
  tex_out << tex;
}

bool BookManager::IsBookFile(const string& filename) {
  for (const string& f : book_list_) {
    if (f == filename) return true;
  }
  return false;
}

string BookManager::GetBookType() { return BookTypeToDirName(book_type_); }

}  // namespace md_parser
