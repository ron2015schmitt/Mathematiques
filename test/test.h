#ifndef MATHQ__TEST_H
#define MATHQ__TEST_H 1

void printStart(const int n) {
  using namespace display;
  std::string s = "Test#" + num2string(n) + ":";
  s = printf2str("%-10s", s.c_str());
  MOUT << CREATESTYLE(BLUE2 + BOLD).apply(s);
}

template <class T>
void printEnd_(const bool pass, const T& result, const T& expected, const int linenum) {
  using namespace display;
  if (pass) {
    MOUT << "          "
      << "       = ";
    DISPVAL(result);
    MOUT << std::endl;
    MOUT << "          ";
    MOUT << CREATESTYLE(GREEN1 + BOLD).apply("Passed") << std::endl;
  }
  else {
    FormatData<double>::format_string = "%.16g";
    MOUT << "          "
      << "       = ";
    DISPVAL(result);
    MOUT << std::endl;
    MOUT << "        " << CREATESTYLE(BLUE2).apply("Expected");
    std::stringstream ss;
    dispval_strm(ss, expected);
    MOUT << " = " << CREATESTYLE(BOLD).apply(ss.str()) << std::endl;
    MOUT << "          ";
    MOUT << CREATESTYLE(RED + BOLD).apply("FAILED");
    std::string s = CREATESTYLE(BOLD).apply(num2string(linenum));
    MOUT << CREATESTYLE(BLUE2).apply("  Refer to line#" + s) << std::endl;
    FormatData<double>::format_string = "%g";
  }
  MOUT << std::endl;
}

#define printEnd(pass, result, expected) printEnd_(pass, result, expected, __LINE__)

void printCode(const std::string& str) {
  using namespace display;
  MOUT << CREATESTYLE(GRAY1).apply(str) << std::endl;
}

#define testcode(...)                \
  printCode(stringify(__VA_ARGS__)); \
  __VA_ARGS__

#define testtext(...) printCode(stringify(__VA_ARGS__))

void printSummary(const std::string filename, const int testnum, const int failnum) {
  using namespace display;

  MOUT << StyledString::get(HORLINE);
  MOUT << CREATESTYLE(BLUE2 + BOLD).apply("SUMMARY:");
  MOUT << "  " << CREATESTYLE(BOLD + MAGENTA1).apply(filename) << std::endl;

  std::string s = printf2str("%-4d", testnum);
  MOUT << "          " << CREATESTYLE(BOLD).apply(s);
  MOUT << CREATESTYLE(BOLD).apply("TOTAL") << std::endl;

  s = printf2str("%-4d", (testnum - failnum));
  MOUT << "          " << CREATESTYLE(GREEN1 + BOLD).apply(s);
  MOUT << CREATESTYLE(GREEN1 + BOLD).apply("PASSED") << std::endl;

  if (failnum > 0) {
    s = printf2str("%-4d", (failnum));
    MOUT << "          " << CREATESTYLE(RED + BOLD).apply(s);
    MOUT << CREATESTYLE(RED + BOLD).apply("FAILED") << std::endl;
  }

  MOUT << StyledString::get(HORLINE);
  CR();
}

#endif
