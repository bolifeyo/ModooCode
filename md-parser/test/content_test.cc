#include "../src/content.h"
#include "../src/util.h"
#include "gtest/gtest.h"

namespace md_parser {

string CreateBoldHtml(const string& s) {
  return StrCat("<span class='font-weight-bold'>", s, "</span>");
}

string CreateItalicHtml(const string& s) {
  return StrCat("<span class='font-italic'>", s, "</span>");
}

string CreateInlineCode(const string& s) {
  return StrCat("<span class='inline-code'>", s, "</span>");
}

string CreateLinkHtml(const string& link_name, const string& link) {
  return StrCat("<a href='", link, "'>", link_name, "</a>");
}

string CreateImageHtml(const string& img_name, const string& img) {
  return StrCat("<img src='", img, "' alt='", img_name, "'>");
}

string SurroundP(const string& s) { return StrCat("<p>", s, "</p>"); }

static char kFormattedCode[] =
    "<pre class=\"chroma\"><span class=\"n\">print</span> <span "
    "class=\"err\">&#39;</span><span class=\"n\">hi</span><span "
    "class=\"err\">&#39;</span>\n</pre>";

TEST(ContentTest, BasicContent) {
  Content plain_content("abcd");
  EXPECT_EQ(SurroundP("abcd"), plain_content.OutputHtml());

  Content simple_italic("*abc*");
  EXPECT_EQ(SurroundP(CreateItalicHtml("abc")), simple_italic.OutputHtml());

  Content simple_bold("**abc**");
  EXPECT_EQ(SurroundP(CreateBoldHtml("abc")), simple_bold.OutputHtml());

  Content simple_bold_and_italic("***abc***");
  EXPECT_EQ(SurroundP(CreateBoldHtml(CreateItalicHtml("abc"))),
            simple_bold_and_italic.OutputHtml());

  Content simple_bold_and_italic_mixed("*__abc__*");
  EXPECT_EQ(SurroundP(CreateItalicHtml(CreateBoldHtml("abc"))),
            simple_bold_and_italic_mixed.OutputHtml());
}

TEST(ContentTest, ComplexContent) {
  // Interpreted as <b>abc <i> a b c </i></b>abc.
  Content content_1("**abc * a b c ***abc");

  EXPECT_EQ(
      SurroundP(StrCat(
          CreateBoldHtml(StrCat("abc ", CreateItalicHtml(" a b c "))), "abc")),
      content_1.OutputHtml());

  // Interpreted as abc <i>abc<b>a</b>b<b>cc</b></i>.
  Content content_2("abc *abc**a**b**cc***");
  EXPECT_EQ(SurroundP(StrCat(
                "abc ", CreateItalicHtml(StrCat("abc", CreateBoldHtml("a"), "b",
                                                CreateBoldHtml("cc"))))),
            content_2.OutputHtml());

  Content content_3("****abc****");
  EXPECT_EQ(SurroundP(StrCat(CreateBoldHtml(""), "abc", CreateBoldHtml(""))),
            content_3.OutputHtml());
}

TEST(ContentTest, Link) {
  Content plain_link("[Modoo Code](http://modoocode.com)");

  EXPECT_EQ(SurroundP(CreateLinkHtml("Modoo Code", "http://modoocode.com")),
            plain_link.OutputHtml());

  Content empty_name("[](http://modoocode.com)");
  EXPECT_EQ(SurroundP(CreateLinkHtml("", "http://modoocode.com")),
            empty_name.OutputHtml());

  Content empty_link("[link]()");
  EXPECT_EQ(SurroundP(CreateLinkHtml("link", "")), empty_link.OutputHtml());

  Content not_valid_link1("abc[");
  Content not_valid_link2("abc[abc]");
  Content not_valid_link3("abc[abc](");
  Content not_valid_link4("abc[abc]ab()");

  EXPECT_EQ(SurroundP("abc["), not_valid_link1.OutputHtml());
  EXPECT_EQ(SurroundP("abc[abc]"), not_valid_link2.OutputHtml());
  EXPECT_EQ(SurroundP("abc[abc]("), not_valid_link3.OutputHtml());
  EXPECT_EQ(SurroundP("abc[abc]ab()"), not_valid_link4.OutputHtml());

  Content link_in_between("this is the [link](http://google.com) thanks");
  EXPECT_EQ(
      SurroundP(StrCat("this is the ",
                       CreateLinkHtml("link", "http://google.com"), " thanks")),
      link_in_between.OutputHtml());

  Content link_in_bold("can __[link](http://google.com) in bold? __ maybe");
  EXPECT_EQ(SurroundP(StrCat(
                "can ",
                CreateBoldHtml(StrCat(
                    CreateLinkHtml("link", "http://google.com"), " in bold? ")),
                " maybe")),
            link_in_bold.OutputHtml());

  Content bold_in_link_ignored("[**bold**]()");
}

TEST(ContentTest, Image) {
  Content plain_image("![The Image](/img/a.png)");
  EXPECT_EQ(CreateImageHtml("The Image", "/img/a.png"),
            plain_image.OutputHtml());

  Content excl_and_link("! [a](b)");
  EXPECT_EQ(SurroundP(StrCat("! ", CreateLinkHtml("a", "b"))),
            excl_and_link.OutputHtml());
}

TEST(ContentTest, Code) {
  Content code("```cpp\nprint 'hi'```");
  EXPECT_EQ(string(kFormattedCode), code.OutputHtml());

  Content code_in_middle("something ```cpp\nprint 'hi'``` and else");
  EXPECT_EQ(
      StrCat(SurroundP("something "), kFormattedCode, SurroundP(" and else")),
      code_in_middle.OutputHtml());
}

TEST(ContentTest, InlineCode) {
  Content inline_code("this is `print` command");
  EXPECT_EQ(SurroundP(StrCat("this is ", CreateInlineCode("print"), " command")),
            inline_code.OutputHtml());


  Content ignore_other_stuff("this is `a * some_var__x` command");
  EXPECT_EQ(SurroundP(StrCat("this is ", CreateInlineCode("a * some_var__x"), " command")),
            ignore_other_stuff.OutputHtml());
}
}  // namespace md_parser
