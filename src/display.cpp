
#define MATHQ_DEBUG 1

#include "mathq.h"

namespace display {

  const char blankline[] = "                                                                               \n";

  //****************************************************************************
  //                          Terminal
  //****************************************************************************

  std::ostream* Terminal::outputstream;

  bool Terminal::isInitialized = false;
  bool Terminal::colorOverride = false;
  bool Terminal::overrideValue = false;

  Terminal Terminal_dummy = *(new Terminal());

  //****************************************************************************
  //                       Style
  //****************************************************************************

  Style& Style::create(const std::string stylestr, const std::string stylename) {
    return *(new Style(stylestr, stylename));
  }

  //****************************************************************************
  //                       StyledString
  //****************************************************************************

  bool StyledString::isInitialized = false;
  std::map<SSEnum, StyledString> StyledString::Map = *(new std::map<SSEnum, StyledString>());
  void StyledString::add(const SSEnum sse, StyledString& styledString) {
    StyledString::Map.insert(std::pair<SSEnum, StyledString>(sse, styledString));
  }
  void StyledString::del(const SSEnum sse) {
    StyledString::Map.erase(sse);
  }
  StyledString& StyledString::get(const SSEnum sse) {
    return StyledString::Map[sse];
  }
  void StyledString::initialize() {
    StyledString::isInitialized = true;
    StyledString* indent = new StyledString(CREATESTYLE(RESET), "                     ");
    StyledString::add(SSEnum::INDENT, *indent);
    StyledString* error = new StyledString(CREATESTYLE(BOLD + RED), "** mathq ERROR:   ");
    StyledString::add(SSEnum::ERROR, *error);
    ;
    StyledString* warning = new StyledString(CREATESTYLE(BOLD + ORANGE), "** mathq WARNING: ");
    StyledString::add(SSEnum::WARNING, *warning);
    StyledString* mathq = new StyledString(CREATESTYLE(BOLD + BLUE2), "mathq");
    StyledString::add(SSEnum::MATHQ, *mathq);

    StyledString* mathematiques = new StyledString(CREATESTYLE(BOLD + BLUE2), "Mathématiques");
    StyledString::add(SSEnum::MATHEMATIQUES, *mathematiques);

    StyledString* version = new StyledString(CREATESTYLE(BOLD + BLUE2), vers_mathq);
    StyledString::add(SSEnum::VERSION, *version);
    StyledString* dlevel0 = new StyledString(CREATESTYLE(BOLD + GREENBACK), "MATHQ_DEBUG 0 (off/fast)");
    StyledString::add(SSEnum::DLEVEL0, *dlevel0);
    StyledString* dlevel1 = new StyledString(CREATESTYLE(BOLD + YELLOWBACK), "MATHQ_DEBUG 1 (errors/warnings)");
    StyledString::add(SSEnum::DLEVEL1, *dlevel1);
    StyledString* dlevel2 = new StyledString(CREATESTYLE(BOLD + ORANGEBACK), "MATHQ_DEBUG 2 (verbose)");
    StyledString::add(SSEnum::DLEVEL2, *dlevel2);
    StyledString* dlevel3 = new StyledString(CREATESTYLE(BOLD + REDBACK), "MATHQ_DEBUG 3 (developer)");
    StyledString::add(SSEnum::DLEVEL3, *dlevel3);

    StyledString* horline = new StyledString(CREATESTYLE(CROSSEDOUT), blankline);
    StyledString::add(SSEnum::HORLINE, *horline);
    StyledString* angle1 = new StyledString(CREATESTYLE(GRAY1), "<");
    StyledString::add(SSEnum::ANGLE1, *angle1);
    StyledString* angle2 = new StyledString(CREATESTYLE(GRAY1), ">");
    StyledString::add(SSEnum::ANGLE2, *angle2);

    StyledString* paren1 = new StyledString(CREATESTYLE(GRAY1), "(");
    StyledString::add(SSEnum::PAREN1, *paren1);
    StyledString* paren2 = new StyledString(CREATESTYLE(GRAY1), ")");
    StyledString::add(SSEnum::PAREN2, *paren2);

    StyledString* bracket1 = new StyledString(CREATESTYLE(GRAY1), "[");
    StyledString::add(SSEnum::BRACKET1, *bracket1);
    StyledString* bracket2 = new StyledString(CREATESTYLE(GRAY1), "]");
    StyledString::add(SSEnum::BRACKET2, *bracket2);

    StyledString* brace1 = new StyledString(CREATESTYLE(GRAY1), "{");
    StyledString::add(SSEnum::BRACE1, *brace1);
    StyledString* brace2 = new StyledString(CREATESTYLE(GRAY1), "}");
    StyledString::add(SSEnum::BRACE2, *brace2);

    StyledString* comma = new StyledString(CREATESTYLE(GRAY1), ",");
    StyledString::add(SSEnum::COMMA, *comma);

    StyledString* colon = new StyledString(CREATESTYLE(GRAY1), ":");
    StyledString::add(SSEnum::COLON, *colon);

    StyledString* semicolon = new StyledString(CREATESTYLE(GRAY1), ";");
    StyledString::add(SSEnum::SEMICOLON, *semicolon);

    StyledString* period = new StyledString(CREATESTYLE(GRAY1), ".");
    StyledString::add(SSEnum::PERIOD, *period);
  }

  //****************************************************************************
  //                       FormatData
  //****************************************************************************

  //---------------------------------------------------------------------------------
  //       specialize
  // ** DO NOT CHANGE THE DEFAULT TYPE BECAUSE THESE ARE USED FOR SCANNING  **
  //------------------------------------------------------------------------------

  // float
  Style FormatData<float>::style_for_value = CREATESTYLE(DEFCLR);
  Style FormatData<float>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<float>::format_string_default = "%g";
  std::string FormatData<float>::format_string = format_string_default;
  bool FormatData<float>::tens = false;

  // double
  Style FormatData<double>::style_for_value = CREATESTYLE(DEFCLR);
  Style FormatData<double>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<double>::format_string_default = "%lg";
  std::string FormatData<double>::format_string = format_string_default;
  bool FormatData<double>::tens = false;

  // long double
  Style FormatData<long double>::style_for_value = CREATESTYLE(DEFCLR);
  Style FormatData<long double>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<long double>::format_string_default = "%llg";
  std::string FormatData<long double>::format_string = format_string_default;
  bool FormatData<long double>::tens = false;

  // short
  Style FormatData<short>::style_for_value = CREATESTYLE(BLUE2);
  Style FormatData<short>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<short>::format_string_default = "%d";
  std::string FormatData<short>::format_string = format_string_default;

  // int
  Style FormatData<int>::style_for_value = CREATESTYLE(BLUE2);
  Style FormatData<int>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<int>::format_string_default = "%d";
  std::string FormatData<int>::format_string = format_string_default;

  // long
  Style FormatData<long>::style_for_value = CREATESTYLE(BLUE2);
  Style FormatData<long>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<long>::format_string_default = "%ld";
  std::string FormatData<long>::format_string = format_string_default;

  // long long
  Style FormatData<long long>::style_for_value = CREATESTYLE(BLUE2);
  Style FormatData<long long>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<long long>::format_string_default = "%lld";
  std::string FormatData<long long>::format_string = format_string_default;

  // unsigned short
  Style FormatData<unsigned short>::style_for_value = CREATESTYLE(VIOLET1);
  Style FormatData<unsigned short>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<unsigned short>::format_string_default = "%u";
  std::string FormatData<unsigned short>::format_string = format_string_default;

  // unsigned int
  Style FormatData<unsigned int>::style_for_value = CREATESTYLE(VIOLET1);
  Style FormatData<unsigned int>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<unsigned int>::format_string_default = "%u";
  std::string FormatData<unsigned int>::format_string = format_string_default;

  // unsigned long
  Style FormatData<unsigned long>::style_for_value = CREATESTYLE(VIOLET1);
  Style FormatData<unsigned long>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<unsigned long>::format_string_default = "%lu";
  std::string FormatData<unsigned long>::format_string = format_string_default;

  // unsigned long long
  Style FormatData<unsigned long long>::style_for_value = CREATESTYLE(VIOLET1);
  Style FormatData<unsigned long long>::style_for_zero = CREATESTYLE(GRAY1);
  const std::string FormatData<unsigned long long>::format_string_default = "%llu";
  std::string FormatData<unsigned long long>::format_string = format_string_default;

  // string
  Style FormatData<std::string>::style_for_value = CREATESTYLE(DEFCLR);
  const std::string FormatData<std::string>::format_string_default = "%s";
  std::string FormatData<std::string>::format_string = format_string_default;

  // char
  Style FormatData<char>::style_for_value = CREATESTYLE(DEFCLR);
  const std::string FormatData<char>::format_string_default = "%c";
  std::string FormatData<char>::format_string = format_string_default;

  // bool
  Style FormatData<bool>::style_for_true = CREATESTYLE(GREEN1);
  Style FormatData<bool>::style_for_false = CREATESTYLE(GRAY1);
  std::string FormatData<bool>::string_for_true = "1";
  std::string FormatData<bool>::string_for_false = "0";

  // Vector
  // TODO: this shoudl be size_type
  // TODO: put these into an intilization func and share it here as well as in h file
  mathq::index_type FormatDataVector::max_elements_per_line = mathq::maxsize;
  Style FormatDataVector::style_for_punctuation = CREATESTYLE(GRAY1);
  std::string FormatDataVector::string_opening = "{";
  std::string FormatDataVector::string_delimeter = ", ";
  std::string FormatDataVector::string_endofline = "\n";
  std::string FormatDataVector::string_closing = "}";

  // Matrix
  //  TODO: this shoudl be size_type
  mathq::index_type FormatDataMatrix::max_elements_per_line = mathq::maxsize;
  Style FormatDataMatrix::style_for_punctuation = CREATESTYLE(GRAY1);
  std::string FormatDataMatrix::string_opening = "{";
  std::string FormatDataMatrix::string_delimeter = ", ";
  std::string FormatDataMatrix::string_row_opening = " {";
  std::string FormatDataMatrix::string_row_closing = "},";
  std::string FormatDataMatrix::string_lastrow_closing = "} ";
  std::string FormatDataMatrix::string_endofline = "\n";
  std::string FormatDataMatrix::string_closing = "}";

  //---------------------------------------------------------------------------------
  //       specialize for complex<double>
  //---------------------------------------------------------------------------------

  Style FormatDataComplex::style_for_punctuation = CREATESTYLE(GRAY1);
  const std::string FormatDataComplex::format_string_default = "(%s,%s)";
  std::string FormatDataComplex::format_string = format_string_default;

  //****************************************************************************
  //                       Log
  //****************************************************************************

  Style Log::style_log0;
  Style Log::style_log1;
  Style Log::style_log2;
  Style Log::style_log3;
  Style Log::style_nspace;
  Style Log::style_class;
  Style Log::style_func;
  Style Log::style_str;

  Log::Log() {
    using namespace std;
    using namespace display;
    Log::style_log0 = CREATESTYLE(BOLD + BLUE1);
    Log::style_log1 = CREATESTYLE(BOLD + BLUE2);
    Log::style_log2 = CREATESTYLE(BOLD + BLUE3);
    Log::style_log3 = CREATESTYLE(BOLD + CYAN);
    Log::style_nspace = CREATESTYLE(MAGENTA1);
    Log::style_class = CREATESTYLE(CYAN);
    Log::style_func = CREATESTYLE(BLUE1);
    Log::style_str = CREATESTYLE(DEFCLR);
  };

  void Log::print(const int level, std::string s) {
    using namespace std;
    switch (level) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    }
    MOUT << s << endl;
  }

  void Log::log(const int level, const std::string nspaceName, const std::string className, const std::string funcName, const std::string s) {
    using namespace std;
    switch (level) {
    case 0:
      MOUT << Log::style_log0.apply("log:");
      break;
    case 1:
      MOUT << Log::style_log1.apply("log1:");
      break;
    case 2:
      MOUT << Log::style_log2.apply("log2:");
      break;
    case 3:
      MOUT << Log::style_log3.apply("log3:");
      break;
    }
    MOUT << " in function ";
    MOUT << Log::style_nspace.apply(nspaceName);
    MOUT << "::";
    MOUT << Log::style_class.apply(className);
    MOUT << "::";
    MOUT << Log::style_func.apply(funcName);
    MOUT << Log::style_str.apply(s);
    MOUT << endl;
  };

  void Log::error(const std::string s) {
    using namespace std;
    MOUT << StyledString::get(ERROR);
    MOUT << s;
    MOUT << endl;
  }
  void Log::warning(const std::string s) {
    using namespace std;
    MOUT << StyledString::get(WARNING);
    MOUT << s;
    MOUT << endl;
  }

  Log Log_dummy = *(new Log());

  //****************************************************************************
  //                       Display
  //****************************************************************************

  bool Display::isInitialized = false;
  Style Display::expressionStyle = CREATESTYLE(BOLD);


  StyledString Display::codePrefixStyledString = StyledString(CREATESTYLE(""), "");

  // prefix for display C++ in git markdown so that syntax highlighting works fully
  // ☀ ☘ ☯ ☄ " " (U+00A0) 📣 ⚡ ⚟  ⚠ ☼ ☠  ☒  ☑ ★ ☾  ♫  ⛏  ⛒ ⛭  ⛯  ✅  ✬  ✦ ❀ ❉ ❋ ❌ ❗ ❶ ❷ ❸ ➀ ➊ ➿ ➾ ⛔ ✔ ✖ ✴❓🔧  🛑 🔥🗣 🛠 🛎
  StyledString Display::prefixStyledString = StyledString(CREATESTYLE(GREEN), "☀ ");

  StyledString Display::equalsStyledString = StyledString(CREATESTYLE(GRAY1), " ➜ ");
  //StyledString Display::equalsStyledString = StyledString(CREATESTYLE(GRAY1), "  =  ");
  StyledString Display::multiSeparatorStyledString = StyledString(CREATESTYLE(GRAY1), "; ");
  StyledString Display::terminatorStyledString = StyledString(CREATESTYLE(GRAY1), ";");  // need the terminator for markdown to color correctly
  Display display_dummy = Display();

}; // namespace display
