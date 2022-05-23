#ifndef MATHQ__DISPLAY
#define MATHQ__DISPLAY

#include <unistd.h>
#include <stdarg.h>
#include <functional>
#include <tuple>

//****************************************************************************
//                      MACROS
//
// REMINDER: In terms of calls to functions etc, the scope of a macros
//           is where it is used!!!
//           For this reason always use th efull symbol name with namespaces
//****************************************************************************

//
// > END USER MACROS <
//

//
// MOUT
//
// The stream from the Terminal class is used to output text to
// stdout with colors and styles.
//
// NOT THAT THIS IS NOT A FUNCTION

#define MOUT (display::Terminal::getmout())


//
// CREATESTYLE(stylestring)
//
// Create a Style object via factory pattern.  The styles are stored
// in a factory. Each style is given a key based on the input string.
// If the style already exists in the factory, then that Style instance.
// Else a new Style instance is created, stored in the factory, and returned.
//
//   stylestring -> string with style and color escape codes

#define CREATESTYLE(...) display::Style::create(__VA_ARGS__, #__VA_ARGS__)


//
// OUTPUT(x)
//
// sends x to MOUT with CR
//
//   x -> variable or expression that has >> operator defined

#define OUTPUT(x) MOUT << x << std::endl

//
// OUTPUT_NOCR(x)
//
// sends x to MOUT
//
//   x -> variable or expression that has >> operator defined

#define OUTPUT_NOCR(x) MOUT << x;


//
// DISPVAL(x)
//
// displays value of variable or expression x, ie sends x to MOUT
// Effectively the same as OUTPUT(x) but handled by Display::expression
// before being send to the Terminal
//
//   x -> variable or expression that has >> operator defined
//
// EXAMPLES:
//   DISPVAL(1+3); // "4"

#define DISPVAL(...) display::dispval_strm(MOUT, __VA_ARGS__)


//
// DISP(x)
//
// displays variable x as follows to MOUT
//    MOUT << Display::expressionStyle[stringify(x)]
//    MOUT << Display::equalsStyledString
//    MOUT << (value of x styled according to data type)
//    MOUT << Display::terminatorStyledString
//
//   x -> variable or expression that has >> operator defined
//
// EXAMPLES:
//   DISP(1+3); // "1+3  ➜  4"

#define DISP(...) display::Display::mydispcr(MOUT, __VA_ARGS__, #__VA_ARGS__)

//
// DISP_NOCR(x)
//
// displays variable x as follows to MOUT
//    MOUT << Display::expressionStyle[stringify(x)]
//    MOUT << Display::equalsStyledString
//    MOUT << (value of x styled according to data type)
//    MOUT << Display::terminatorStyledString
//
//   x -> variable or expression that has >> operator defined
//
// EXAMPLES:
//   DISP_NOCR(1+3); // "1+3  ➜  4"

#define DISP_NOCR(...) display::Display::mydisp_notype(MOUT, __VA_ARGS__, #__VA_ARGS__, false)

//
// SRDISP(str,x)
//
//
// same as DISP(x) but prints str on the right before the terminator
//
//   x -> variable or expression that has >> operator defined
//
// EXAMPLES:
//   SRDISP(" bits",CHAR_BIT); // "CHAR_BIT  ➜  8 bits"

#define SRDISP(str,...) display::Display::mydispcr(MOUT, __VA_ARGS__, #__VA_ARGS__,str)


//
// TLDISP(x)
//
// same as DISP(x) but prints the typename on the LHS
//
// EXAMPLES:
//   TLDISP(1+3); // "int 1+3  ➜  4"

#define TLDISP(...) display::Display::tmydispcr(MOUT, __VA_ARGS__, #__VA_ARGS__)


//
// TRDISP(x)
//
// same as DISP(x) but prints the typename on the RHS
//
// EXAMPLES:
//   TRDISP(1+3); // "1+3  ➜  int 4"

#define TRDISP(...) display::Display::trmydispcr(MOUT, __VA_ARGS__, #__VA_ARGS__)


//
// MDISP(x)
//
// same as DISP(x) but can print up to 10 expressions on the same line
//
// EXAMPLES:
//   MDISP(1+3, 22/7); // "1 + 3 ➜  4; 22 / 7 ➜  3; "

#define MDISP(...) _MDISP_X(, ##__VA_ARGS__, _DISP_10(MOUT, __VA_ARGS__), _DISP_9(MOUT, __VA_ARGS__), _DISP_8(MOUT, __VA_ARGS__), _DISP_7(MOUT, __VA_ARGS__), _DISP_6(MOUT, __VA_ARGS__), _DISP_5(MOUT, __VA_ARGS__), _DISP_4(MOUT, __VA_ARGS__), _DISP_3(MOUT, __VA_ARGS__), _DISP_2(MOUT, __VA_ARGS__), _DISP_1(MOUT, __VA_ARGS__), _DISP_0(MOUT))


//
// CR(x)
//
// issue a carriage return (line break)

#define CR() display::Display::issuecr(MOUT)




//
// ECHO_CODE
//
// line of code is both executed and printted to MOUT

#define ECHO_CODE(...)                                                                                        \
  MOUT << Display::codePrefixStyledString << display::printf2str(stringify(__VA_ARGS__)) << ";" << std::endl; \
  __VA_ARGS__

//
// ECHO_CODE_W_COMMENT
//
// line of code is both executed and printted to MOUT
// the string ("// " + str) is appended to the output

#define ECHO_CODE_W_COMMENT(str, ...)                                                                                   \
  MOUT << Display::codePrefixStyledString << display::printf2str(stringify(__VA_ARGS__)) << "; // " + str << std::endl; \
  __VA_ARGS__




//
// duplicate of above functions but send output to stream
//
#define DISPVAL_STRM(stream, ...) display::dispval_strm(stream, __VA_ARGS__)
#define DISP_STRM(stream, ...) display::Display::mydispcr(stream, __VA_ARGS__, #__VA_ARGS__)
#define TDISP_STRM(stream, ...) display::Display::tmydispcr(stream, __VA_ARGS__, #__VA_ARGS__)
#define TRDISP_STRM(stream, ...) display::Display::trmydispcr(stream, __VA_ARGS__, #__VA_ARGS__)
#define CR_STRM(stream) display::Display::issuecr(stream)
#define MDISP_STRM(stream, ...) _MDISP_X(, ##__VA_ARGS__, _DISP_10(stream, __VA_ARGS__), _DISP_9(stream, __VA_ARGS__), _DISP_8(stream, __VA_ARGS__), _DISP_7(stream, __VA_ARGS__), _DISP_6(stream, __VA_ARGS__), _DISP_5(stream, __VA_ARGS__), _DISP_4(stream, __VA_ARGS__), _DISP_3(stream, __VA_ARGS__), _DISP_2(stream, __VA_ARGS__), _DISP_1(stream, __VA_ARGS__), _DISP_0(stream))
#define ECHO_CODE_STRM(stream, ...)                                                                             \
  stream << Display::codePrefixStyledString << display::printf2str(stringify(__VA_ARGS__)) << ";" << std::endl; \
  __VA_ARGS__
#define ECHO_CODE_W_COMMENT_STRM(stream, str, ...)                                                                        \
  stream << Display::codePrefixStyledString << display::printf2str(stringify(__VA_ARGS__)) << "; // " + str << std::endl; \
  __VA_ARGS__


//
// THESE FUNCTIONS ONLY APPEAR IN DEBUG MODES
// ie they have zero run-time cost when the DEBUG level is less than the number specified
//

#if MATHQ_DEBUG >= 1
#define PRINTF1(...) MOUT << display::printf2str(__VA_ARGS__)
#define MDISP1(...) MDISP(__VA_ARGS__)
#define DISP1(...) DISP(__VA_ARGS__)
#define TLDISP1(...) TLDISP(__VA_ARGS__)
#define TRDISP1(...) TRDISP(__VA_ARGS__)
#else
#define PRINTF1(...) \
  {}
#define MDISP1(...) \
  {}
#define DISP1(...) \
  {}
#define TLDISP1(...) \
  {}
#define TRDISP1(...) \
  {}
#endif

#if MATHQ_DEBUG >= 2
#define PRINTF2(...) MOUT << display::printf2str(__VA_ARGS__)
#define MDISP2(...) MDISP(__VA_ARGS__)
#define DISP2(...) DISP(__VA_ARGS__)
#define TLDISP2(...) TLDISP(__VA_ARGS__)
#define TRDISP2(...) TRDISP(__VA_ARGS__)
#else
#define PRINTF2(...) \
  {}
#define MDISP2(...) \
  {}
#define DISP2(...) \
  {}
#define TLDISP2(...) \
  {}
#define TRDISP2(...) \
  {}
#endif

#if MATHQ_DEBUG >= 3
#define PRINTF3(...) MOUT << display::printf2str(__VA_ARGS__)
#define MDISP3(...) MDISP(__VA_ARGS__)
#define DISP3(...) DISP(__VA_ARGS__)
#define TLDISP3(...) TLDISP(__VA_ARGS__)
#define TRDISP3(...) TRDISP(__VA_ARGS__)
#else
#define PRINTF3(...) \
  {}
#define MDISP3(...) \
  {}
#define DISP3(...) \
  {}
#define TLDISP3(...) \
  {}
#define TRDISP3(...) \
  {}
#endif



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// **deprecated**
#define codemultiNoteC11Array(...)                       \
  printf("%s; // C++11 list\n", stringify(__VA_ARGS__)); \
  __VA_ARGS__
#define resultstart() printf("**The result is**\n```C++\n")
#define resultstart2(str) printf("**Some expressions with results**%s\n```C++\n", str)
#define resultstart3(str) printf("**Results**%s\n```C++\n", str)
#define resultmulti(...) \
  printf("  ");          \
  DISP(__VA_ARGS__)
#define resultend() printf("```\n\n")
#define RESULT(...)         \
  resultstart();            \
  resultmulti(__VA_ARGS__); \
  resultend()
#define EXAMPLE(n, str) MOUT << "**EXAMPLE" << std::setw(2) << n << "**: " << str << std::endl
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



//
// SPECIFIC TO GITHUB MARKDOWN
//

#define GMD_PREAMBLE() printf("_This document was generated from the C++ file_ `%s` _using macros and functions (in namespace `mathq::display`) from the header_ `\"mathq.h\"`. ", __FILE__);


//
// Creating markdown code blocks
//
// place code between these two macros
//
// EXAMPLE:
//  GMD_CODE_START();
//  x = 0;  // line of code is executed
//  ECHO_CODE( x = (43.2 - 1)/2 );  // line of code is both executed and also put in the Markdown code block
//  GMD_CODE_END()
//

#define GMD_CODE_START(lang) MOUT << std::string("```") << std::string(lang) << std::endl
#define GMD_CODE_END() printf("```\n")


// for a one-liner code block

#define GMD_CODE_BLOCK(...) \
  GMD_CODE_START();         \
  ECHO_CODE(__VA_ARGS__);   \
  GMD_CODE_END()

// for providing some vertical space

#define GMD_VSPACE() MOUT << "\n<br>\n" \
                          << std::endl

// header macros

#define GMD_HEADER1(str) MOUT << "# " << str << std::endl
#define GMD_HEADER2(str) MOUT << "## " << str << std::endl
#define GMD_HEADER3(str) MOUT << "### " << str << std::endl
#define GMD_HEADER4(str) MOUT << "#### " << str << std::endl


//
// > _HELPER macros intended only for use by other macros internal to this file <
//

// for how this works, refer to
// https://stackoverflow.com/questions/3046889/optional-parameters-with-c-macros
#define _DISP_0(stream) display::Display::issuecr(stream)
#define _DISPX(stream, A) display::Display::multidisp_notype(stream, A, #A)
#define _DISP_1(stream, A) \
  _DISPX(stream, A, #A);   \
  CR_STRM(stream)
#define _DISP_2(stream, A, B) \
  _DISPX(stream, A);          \
  _DISPX(stream, B);          \
  CR_STRM(stream)
#define _DISP_3(stream, A, B, C) \
  _DISPX(stream, A);             \
  _DISPX(stream, B);             \
  _DISPX(stream, C);             \
  CR_STRM(stream)
#define _DISP_4(stream, A, B, C, D) \
  _DISPX(stream, A);                \
  _DISPX(stream, B);                \
  _DISPX(stream, C);                \
  _DISPX(stream, D);                \
  CR_STRM(stream)
#define _DISP_5(stream, A, B, C, D, E) \
  _DISPX(stream, A);                   \
  _DISPX(stream, B);                   \
  _DISPX(stream, C);                   \
  _DISPX(stream, D);                   \
  _DISPX(stream, E);                   \
  CR_STRM(stream)
#define _DISP_6(stream, A, B, C, D, E, F) \
  _DISPX(stream, A);                      \
  _DISPX(stream, B);                      \
  _DISPX(stream, C);                      \
  _DISPX(stream, D);                      \
  _DISPX(stream, E);                      \
  _DISPX(stream, F);                      \
  CR_STRM(stream)
#define _DISP_7(stream, A, B, C, D, E, F, G) \
  _DISPX(stream, A);                         \
  _DISPX(stream, B);                         \
  _DISPX(stream, C);                         \
  _DISPX(stream, D);                         \
  _DISPX(stream, E);                         \
  _DISPX(stream, F);                         \
  _DISPX(stream, G);                         \
  CR_STRM(stream)
#define _DISP_8(stream, A, B, C, D, E, F, G, H) \
  _DISPX(stream, A);                            \
  _DISPX(stream, B);                            \
  _DISPX(stream, C);                            \
  _DISPX(stream, D);                            \
  _DISPX(stream, E);                            \
  _DISPX(stream, F);                            \
  _DISPX(stream, G);                            \
  _DISPX(stream, H);                            \
  CR_STRM(stream)
#define _DISP_9(stream, A, B, C, D, E, F, G, H, I) \
  _DISPX(stream, A);                               \
  _DISPX(stream, B);                               \
  _DISPX(stream, C);                               \
  _DISPX(stream, D);                               \
  _DISPX(stream, E);                               \
  _DISPX(stream, F);                               \
  _DISPX(stream, G);                               \
  _DISPX(stream, H);                               \
  _DISPX(stream, I);                               \
  CR_STRM(stream)
#define _DISP_10(stream, A, B, C, D, E, F, G, H, I, J) \
  _DISPX(stream, A);                                   \
  _DISPX(stream, B);                                   \
  _DISPX(stream, C);                                   \
  _DISPX(stream, D);                                   \
  _DISPX(stream, E);                                   \
  _DISPX(stream, F);                                   \
  _DISPX(stream, G);                                   \
  _DISPX(stream, H);                                   \
  _DISPX(stream, I);                                   \
  _DISPX(stream, J);                                   \
  CR_STRM(stream)

// The interim macro that simply strips the excess and ends up with the required macro
#define _MDISP_X(x, A, B, C, D, E, F, G, H, I, J, FUNC, ...) FUNC;


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^







//****************************************************************************
//
//                        NAMESPACE display
//
//****************************************************************************


namespace display {

  extern const char blankline[];
  //****************************************************************************
  //                          Some declarations. Definitions below
  //****************************************************************************

  inline void log(const std::string spaceName, const std::string className, const std::string funcName, const std::string s);
  inline void log1(const std::string spaceName, const std::string className, const std::string funcName, const std::string s);
  inline void log2(const std::string spaceName, const std::string className, const std::string funcName, const std::string s);
  inline void log3(const std::string spaceName, const std::string className, const std::string funcName, const std::string s);
  inline void print1(const std::string s);
  inline void print2(const std::string s);
  inline void print3(const std::string s);

  //****************************************************************************
  //                        String functions
  //****************************************************************************

  inline std::string replaceAll(std::string s, std::string s1, std::string s2) {
    size_t pos = s.find(s1);
    while (pos != std::string::npos) {
      s.replace(pos, s1.size(), s2);
      pos = s.find(s1, pos + s2.size());
    }
    return s;
  }

  //------------------------------------------------------------
  //                        printf2str
  //------------------------------------------------------------

  inline std::string printf2str(const char* format, ...) {
    const size_t BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    size_t n = vsnprintf(buffer, BUFFER_SIZE, format, args);
    if (n < 0) {
      // TODO: format error and throw
    }
    else if (n >= BUFFER_SIZE) {
      // TODO: string too long error and throw
    }
    va_end(args);
    return std::string(buffer);
  }

  //------------------------------------------------------------
  //                        num2string
  //------------------------------------------------------------

  template <class D>
  inline std::string num2string(D x) {
    std::ostringstream strm;
    strm << x;
    return strm.str();
  }


  //****************************************************************************
  //                          Terminal
  //****************************************************************************

  class Terminal {
  private:
    static bool isInitialized;
    static bool colorOverride;
    static bool overrideValue;
    static std::ostream* outputstream;

  public:
    Terminal() {
      // for initializing the class
      if (!isInitialized) {
        outputstream = &std::cout;
      }
      isInitialized = true;
    }

    inline static bool getUseColor() {
      bool useColor = false;
      if (Terminal::outputstream == &std::cout) {
        useColor = (isatty(STDOUT_FILENO) == 1);
      }
      else if (Terminal::outputstream == &std::cerr) {
        useColor = (isatty(STDERR_FILENO) == 1);
      }
      if (colorOverride) {
        return overrideValue;
      }
      else {
        return useColor;
      }
    }

    inline static void setColorOverride(bool val) {
      colorOverride = val;
    }
    inline static void setOverrideValue(bool val) {
      overrideValue = val;
    }
    inline static void setmout(std::ostream& os) {
      outputstream = &os;
    }
    inline static bool getColorOverride() {
      return colorOverride;
    }
    inline static bool getOverrideValue() {
      return overrideValue;
    }
    inline static std::ostream& getmout() {
      return *outputstream;
    }
  };


  //****************************************************************************
  //                       Terminal escape codes for color etc
  //****************************************************************************

  const std::string ESC = "\033[";
  const std::string FORE = ESC + "38;";
  const std::string BACK = ESC + "48;";

  const std::string RESET = ESC + "0m";
  const std::string BOLD = ESC + "1m";
  const std::string DIM = ESC + "2m";    // not widely supported
  const std::string ITALIC = ESC + "3m"; // not widely supported
  const std::string UNDERLINE = ESC + "4m";
  const std::string SLOWBLINK = ESC + "5m";
  const std::string RAPIDBLINK = ESC + "6m"; // not widely supported
  const std::string REVERSED = ESC + "7m";
  const std::string CROSSEDOUT = ESC + "9m";
  const std::string FONT2 = ESC + "11m";     // not widely supported
  const std::string FRAKTUR = ESC + "20m";   // not widely supported
  const std::string FRAMED = ESC + "51m";    // not widely supported
  const std::string ENCIRCLED = ESC + "52m"; // not widely supported
  const std::string OVERLINE = ESC + "53m";

  const std::string BLACK = FORE + "5;232m"; // in Ubuntu color=0 is sloghtly gray
  const std::string DEFCLR = FORE + "39m";
  const std::string GRAY2 = ESC + "30m";
  const std::string GRAY1 = FORE + "5;240m";
  const std::string WHITE = ESC + "37m";

  // organized per ROYGBIV
  const std::string RED = ESC + "31m";
  const std::string ORANGE = FORE + "5;208m";
  const std::string ORANGE1 = FORE + "5;172m";
  const std::string ORANGE2 = FORE + "5;166m";
  const std::string YELLOW = ESC + "33m";
  const std::string YELLOWBRIGHT = ESC + "93m";
  const std::string GREEN = ESC + "32m";
  const std::string GREENBRIGHT = ESC + "92m";
  const std::string GREEN1 = FORE + "5;22m";
  const std::string CYAN = ESC + "36m";
  const std::string BLUE = ESC + "34m";
  const std::string BLUEBRIGHT = ESC + "94m";
  const std::string BLUE1 = FORE + "5;18m";
  const std::string BLUE2 = FORE + "5;21m";
  const std::string BLUE3 = FORE + "5;27m";
  const std::string MAGENTA = ESC + "35m";
  const std::string MAGENTA1 = FORE + "5;129m";
  const std::string VIOLET1 = FORE + "5;54m";

  const std::string BLACKBACK = BACK + "5;16m";
  const std::string REDBACK = BACK + "5;160m";
  const std::string ORANGEBACK = BACK + "5;208m";
  const std::string YELLOWBACK = BACK + "5;226m";
  const std::string GREENBACK = BACK + "5;46m";

  //****************************************************************************
  //                       Style
  //****************************************************************************

  class Style {
  private:
    std::string stylestr_;
    std::string stylename_;

  public:
    static Style& create(const std::string stylestr, const std::string stylename);

    static Style& create(const unsigned int n) {
      Style* style = new Style(n);
      return *style;
    }

    inline Style() : stylestr_(""), stylename_("") {
    }
    inline Style(const std::string stylestr) : stylestr_(stylestr), stylename_("") {
    }
    inline Style(const std::string stylestr, const std::string stylename) : stylestr_(stylestr), stylename_(stylename) {
    }
    inline Style(const Style& style) : stylestr_(style.getStyleString()), stylename_(style.getName()) {
    }
    inline Style(const unsigned int n) {
      stylestr_ = FORE + printf2str("5;%um", n);
      stylename_ = "";
    }
    inline Style(const unsigned int n, const unsigned int m) {
      stylestr_ = FORE + printf2str("5;%um", n) + BACK + printf2str("5;%um", m);
      stylename_ = "";
    }
    inline Style(const std::string attributestr, const unsigned int n, const unsigned int m) {
      stylestr_ = attributestr + FORE + printf2str("5;%um", n) + BACK + printf2str("5;%um", m);
      stylename_ = "";
    }
    inline std::string apply(const std::string s) const {
      if (Terminal::getUseColor()) {
        return stylestr_ + s + RESET;
      }
      else {
        return s;
      }
    }
    inline std::string getStyleString() const {
      return stylestr_;
    }

    inline std::string getName() const {
      return stylename_;
    }

    inline std::string classname() const {
      return "Style";
    }

    inline Style& operator+(const Style& style2) const {
      Style* style3 = new Style(this->getStyleString() + style2.getStyleString(), this->getName() + "+" + style2.getName());
      return *style3;
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const Style& style) {
      std::string s = style.getName();
      if (s.empty()) {
        s = "style";
      }
      stream << style.apply(s);
      return stream;
    }
  };


  inline Style functor_namestyle = CREATESTYLE(display::ORANGE2);
  inline Style functor_style = CREATESTYLE(display::BOLD);
  inline Style userfunctor_style = CREATESTYLE(display::BOLD + display::BLUE1);

  //****************************************************************************
  //                       StyledString
  //****************************************************************************

  enum SSEnum {
    INDENT,
    ERROR,
    WARNING,
    MATHQ,
    MATHEMATIQUES,
    VERSION,
    DLEVEL0,
    DLEVEL1,
    DLEVEL2,
    DLEVEL3,
    HORLINE,
    ANGLE1,
    ANGLE2,
    PAREN1,
    PAREN2,
    BRACKET1,
    BRACKET2,
    BRACE1,
    BRACE2,
    COMMA,
    COLON,
    SEMICOLON,
    PERIOD
  };

  class StyledString {
  private:
    static bool isInitialized;
    static std::map<SSEnum, StyledString> Map;
    Style& style_;
    std::string text_;

  public:
    static void add(const SSEnum ss, StyledString& styledString);
    static void del(const SSEnum ss);
    static StyledString& get(const SSEnum ss);
    static void initialize();
    static StyledString& create(Style& style, const std::string text) {
      return *(new StyledString(style, text));
    }

    inline StyledString() : style_(CREATESTYLE(CROSSEDOUT)),
      text_(std::string("hello world")) {
      if (!StyledString::isInitialized) {
        StyledString::initialize();
      }
    }
    inline StyledString(Style& style, const std::string text) : style_(style), text_(text) {
    }
    inline StyledString(const StyledString& styledstring) : style_(styledstring.getStyle()), text_(styledstring.getString()) {
    }
    inline std::string get() const {
      return style_.apply(text_);
    }
    inline std::string getString() const {
      return text_;
    }
    inline StyledString& setString(const std::string text) {
      text_ = text;
      return *this;
    }
    inline Style& getStyle() const {
      return style_;
    }

    StyledString& operator=(const StyledString& styledstring) {
      style_ = styledstring.getStyle();
      text_ = styledstring.getString();
      return *this;
    }

    inline std::string classname() const {
      return "StyledString";
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const StyledString& ss) {
      stream << ss.get();
      return stream;
    }
  };

  //---------------------------------------------------------------------------------
  //       getTypeStyle
  //---------------------------------------------------------------------------------

  template <typename T>
  inline Style getTypeStyle(const T& var) {
    return CREATESTYLE(CYAN);
  }
  template <>
  inline Style getTypeStyle(const std::string& var) {
    return CREATESTYLE(GREEN);
  }

#define SPECIALIZE_getTypeStyle(TYPE)          \
  template <>                                  \
  inline Style getTypeStyle(const TYPE &var) { \
    return CREATESTYLE(MAGENTA);               \
  }

  SPECIALIZE_getTypeStyle(float);
  SPECIALIZE_getTypeStyle(double);
  SPECIALIZE_getTypeStyle(long double);

  SPECIALIZE_getTypeStyle(char);
  SPECIALIZE_getTypeStyle(signed char);
  SPECIALIZE_getTypeStyle(short);
  SPECIALIZE_getTypeStyle(int);
  SPECIALIZE_getTypeStyle(long);
  SPECIALIZE_getTypeStyle(long long);

  SPECIALIZE_getTypeStyle(unsigned char);
  SPECIALIZE_getTypeStyle(unsigned short);
  SPECIALIZE_getTypeStyle(unsigned int);
  SPECIALIZE_getTypeStyle(unsigned long);
  SPECIALIZE_getTypeStyle(unsigned long long);

  SPECIALIZE_getTypeStyle(wchar_t);
  SPECIALIZE_getTypeStyle(bool);

  // container type
  template <typename D, template <typename> typename C>
  inline Style getTypeStyle(const C<const D>& var) {
    Style style = CREATESTYLE(CYAN);
    return style;
  }

  // container type2
  template <typename D1, typename D2, template <typename, typename> typename C>
  inline Style getTypeStyle(const C<const D1, const D2>& var) {
    Style style = CREATESTYLE(CYAN);
    return style;
  }


  template <typename... Ts>
  Style getTypeStyle(const std::tuple<Ts...>& var) {
    Style style = CREATESTYLE(CYAN);
    return style;
  }

  template <class D>
  Style getTypeStyle(const mathq::Domain<D>& var) {
    Style style = CREATESTYLE(CYAN);
    return style;
  }

  template <class T>
  Style getTypeStyle(const mathq::Nabla<T>& var) {
    Style style = CREATESTYLE(CYAN);
    return style;
  }

  inline Style getFunctionTypeStyle() {
    return CREATESTYLE(BLUE);
  }

  //------------------------------------------------------------------
  //       Has_classname
  //------------------------------------------------------------------

  // I sued this version:
  // https://stackoverflow.com/questions/257288/is-it-possible-to-write-a-template-to-check-for-a-functions-existence
  // It doesn;t check the signature

  // other solutions:
  // https://stackoverflow.com/questions/36079170/how-to-check-if-a-member-name-variable-or-function-exists-in-a-class-with-or
  // https://stackoverflow.com/questions/87372/check-if-a-class-has-a-member-function-of-a-given-signature
  // https://stackoverflow.com/questions/41936763/type-traits-to-check-if-class-has-member-function

  template <typename T>
  class Has_classname {
    typedef char one;
    struct two {
      char x[2];
    };

    template <typename C>
    static one test(decltype(&C::classname));
    template <typename C>
    static two test(...);

  public:
    enum { value = sizeof(test<T>(0)) == sizeof(char) };
  };

  //------------------------------------------------------------------
  //       getTypeName
  //------------------------------------------------------------------

  template <class T>
  inline std::string getTypeName(const T& var) {
    std::string s = typeid(var).name();
    if constexpr (Has_classname<T>::value) {
      s = var.classname();
    }
    return getTypeStyle(var).apply(s);
  }

#define SPECIALIZE_getTypeName(TYPE)                \
  template <>                                       \
  inline std::string getTypeName(const TYPE &var) { \
    return getTypeStyle(var).apply(#TYPE);          \
  }

  SPECIALIZE_getTypeName(float);
  SPECIALIZE_getTypeName(double);
  SPECIALIZE_getTypeName(long double);

  SPECIALIZE_getTypeName(char);
  SPECIALIZE_getTypeName(signed char);
  SPECIALIZE_getTypeName(short);
  SPECIALIZE_getTypeName(int);
  SPECIALIZE_getTypeName(long);
  SPECIALIZE_getTypeName(long long);

  SPECIALIZE_getTypeName(unsigned char);
  SPECIALIZE_getTypeName(unsigned short);
  SPECIALIZE_getTypeName(unsigned int);
  SPECIALIZE_getTypeName(unsigned long);
  SPECIALIZE_getTypeName(unsigned long long);

  SPECIALIZE_getTypeName(wchar_t);

  SPECIALIZE_getTypeName(std::string);
  SPECIALIZE_getTypeName(bool);

  // std::complex
  template <class D>
  inline std::string getTypeName(const std::complex<D>& var) {
    std::string s = getTypeStyle(var).apply("std::complex");
    s += getBracketedTypeName(var.real());
    return s;
  }

  // T[]
  template <typename T, size_t N>
  inline std::string getTypeName(const T(&a)[N]) {
    std::string tname = getTypeName(a[0]);
    std::ostringstream stream;
    stream << tname << StyledString::get(BRACKET1).get() << N << StyledString::get(BRACKET2).get();
    return stream.str();
  }

  // This does not overridfe the default
  //  template <class D>
  //  inline std::string getTypeName(typename mathq::FunctionTypes<D>::unary_func var) {
  //  std::string s = display::getFunctionTypeStyle().apply("userfunc");
  //  double d = 0;
  //  std::string sd = display::getTypeName(d);
  //  s = sd + "(*"+s+")"+"("+sd+")";
  //  return s;
  //}

  // this works
  // inline std::string getTypeName(typename mathq::FunctionTypes<double>::unary_func var) {
  //   std::string sfunc = display::getFunctionTypeStyle().apply("func");
  //   double d;
  //   std::string sd = display::getTypeName(d);
  //   return sd + " "+sfunc+ StyledString::get(PAREN1).get()+sd+","+sd+StyledString::get(PAREN2).get();
  // }

#define SPECIALIZE_getTypeName_CONTAINER(TYPE)         \
  template <typename D>                                \
  inline std::string getTypeName(const TYPE<D> &var) { \
    std::string s = getTypeStyle(var).apply(#TYPE);    \
    D d;                                               \
    s = s + getBracketedTypeName(d);                   \
    return s;                                          \
  }

  SPECIALIZE_getTypeName_CONTAINER(std::vector);
  SPECIALIZE_getTypeName_CONTAINER(std::valarray);
  SPECIALIZE_getTypeName_CONTAINER(std::list);
  SPECIALIZE_getTypeName_CONTAINER(std::queue);
  SPECIALIZE_getTypeName_CONTAINER(std::initializer_list);
  SPECIALIZE_getTypeName_CONTAINER(mathq::Domain);

#define SPECIALIZE_getTypeName_CONTAINER2(TYPE)             \
  template <typename D1, typename D2>                       \
  inline std::string getTypeName(const TYPE<D1, D2> &var) { \
    std::string s = getTypeStyle(var).apply(#TYPE);         \
    D1 d1;                                                  \
    D2 d2;                                                  \
    s += StyledString::get(ANGLE1).get();                   \
    s += getTypeName(d1);                                   \
    s += StyledString::get(COMMA).get();                    \
    s += getTypeName(d2);                                   \
    s += StyledString::get(ANGLE2).get();                   \
    return s;                                               \
  }

  SPECIALIZE_getTypeName_CONTAINER2(std::map);

  template <typename T>
  inline std::string getTypeName(const mathq::Nabla<T>& var) {
    std::string s = getTypeStyle(var).apply("mathq::Nabla");
    return s;
  }


  template <typename D, unsigned long int N>
  inline std::string getTypeName(const std::array<D, N>& var) {
    std::string s = getTypeStyle(var).apply("std::array");
    D d;
    s += StyledString::get(ANGLE1).get();
    s += getTypeName(d);
    s += StyledString::get(COMMA).get();
    s += num2string(N);
    s += StyledString::get(ANGLE2).get();
    return s;
  }


  // template< class T >
  // inline constexpr std::size_t tuple_size_v = std::tuple_size<T>::value;

  template <size_t I = 0, typename... Ts>
  constexpr std::string getTypeName(const std::tuple<Ts...>& var, std::string s = std::string("")) {
    if constexpr (I == sizeof...(Ts)) {
      return s+StyledString::get(ANGLE2).get();
    }
    else {
      using SelectedType = std::tuple_element_t<I, std::tuple<Ts...> >;
      if constexpr (I == 0) {
        std::string s1 = getTypeStyle(var).apply("std::tuple");
        s += s1;
        s += StyledString::get(ANGLE1).get();
      }
      else {
        s += StyledString::get(COMMA).get();
      }
      s += getTypeName(SelectedType());
      return getTypeName<I + 1, Ts...>(var, s);
    }
  }


  // template <size_t I = 0, typename... Ts>
  // constexpr std::string getTypeName(const std::tuple<Ts...>& var, std::string& s = "") {
  //   if constexpr (I == sizeof...(Ts)) {
  //     return s;
  //   }
  //   else {
  //     s += std::tuple_element_t<I, Ts...>;
  //     return getTypeName<I + 1, Ts...>(var, s);
  //   }
  // }

  // s += StyledString::get(ANGLE1).get();
  // s += std::tuple_element_t<I, T>;
  // s += StyledString::get(COMMA).get();
  // s += getTypeName(d2);
  // s += StyledString::get(ANGLE2).get();


//---------------------------------------------------------------------------------
//       getBracketedTypeName
//-------------------------------------------------------------------------------

  template <typename T>
  inline std::string getBracketedTypeName(const T& var) {
    std::string name = getTypeName(var);
    return StyledString::get(ANGLE1).get() + getTypeStyle(var).apply(name) + StyledString::get(ANGLE2).get();
  }

  //****************************************************************************
  //                       FormatData
  //****************************************************************************

  class FormatBase {
  };

  template <typename T>
  class FormatData {
  public:
  };

  template <typename T>
  inline std::string getFormatString() {
    return FormatData<T>::format_string;
  }
  template <typename T>
  inline std::string getDefaultFormatString() {
    return FormatData<T>::format_string_default;
  }

#define SPECIALIZE_FormatData_mathtype(TYPE)        \
  template <>                                       \
  class FormatData<TYPE> {                          \
  public:                                           \
    static Style style_for_value;                   \
    static Style style_for_zero;                    \
    const static std::string format_string_default; \
    static std::string format_string;               \
  };

  SPECIALIZE_FormatData_mathtype(short);
  SPECIALIZE_FormatData_mathtype(int);
  SPECIALIZE_FormatData_mathtype(long);
  SPECIALIZE_FormatData_mathtype(long long);

  SPECIALIZE_FormatData_mathtype(unsigned short);
  SPECIALIZE_FormatData_mathtype(unsigned int);
  SPECIALIZE_FormatData_mathtype(unsigned long);
  SPECIALIZE_FormatData_mathtype(unsigned long long);

#define SPECIALIZE_FormatData_floating(TYPE)        \
  template <>                                       \
  class FormatData<TYPE> {                          \
  public:                                           \
    static Style style_for_type_name;               \
    static Style style_for_value;                   \
    static Style style_for_zero;                    \
    const static std::string format_string_default; \
    static std::string format_string;               \
    static bool tens;                               \
  };

  SPECIALIZE_FormatData_floating(float);
  SPECIALIZE_FormatData_floating(double);
  SPECIALIZE_FormatData_floating(long double);

  // string
  template <>
  class FormatData<std::string> {
  public:
    static Style style_for_type_name;
    static Style style_for_value;
    const static std::string format_string_default;
    static std::string format_string;
  };

  // char
  template <>
  class FormatData<char> {
  public:
    static Style style_for_type_name;
    static Style style_for_value;
    const static std::string format_string_default;
    static std::string format_string;
  };

  // bool
  template <>
  class FormatData<bool> {
  public:
    static Style style_for_type_name;
    static Style style_for_true;
    static Style style_for_false;
    static std::string string_for_true;
    static std::string string_for_false;
  };

  // Vector
  class FormatDataVector {
  public:
    static mathq::index_type max_elements_per_line;
    static Style style_for_punctuation;
    static std::string string_opening;
    static std::string string_delimeter;
    static std::string string_endofline;
    static std::string string_closing;
  };

  // Matrix
  class FormatDataMatrix {
  public:
    static mathq::index_type max_elements_per_line;
    static Style style_for_punctuation;
    static std::string string_opening;
    static std::string string_delimeter;
    static std::string string_row_opening;
    static std::string string_row_closing;
    static std::string string_lastrow_closing;
    static std::string string_endofline;
    static std::string string_closing;
  };

  //****************************************************************************
  //       FormatString
  //****************************************************************************

  template <typename D>
  inline bool checkFormatString(const std::string formatstr, const D& x = D(1)) {
    using namespace std;
    if (formatstr.empty()) {
      return false;
    }

    bool passed = true;
    std::string s("");
    try {
      s = printf2str(formatstr.c_str(), x);
    }
    catch (...) {
      // rethrow
      passed = false;
    }
    size_t found = s.find("(nil)");
    if (found != string::npos)
      passed = false;
    D x2 = D(0);
    D* x2ptr = &x2;
    string format = FormatData<D>::format_string_default;
    int ret = std::sscanf(s.c_str(), format.c_str(), x2ptr);
    if (ret != 1)
      passed = false;
    if (x2 != x)
      passed = false;

    if (!passed) {
      MOUT << StyledString::get(HORLINE);
      MOUT << StyledString::get(ERROR);
      MOUT << " illegal format string";
      MOUT << CREATESTYLE(BOLD).apply(string(" \"") + formatstr + "\"");
      MOUT << " passed to Format";
      MOUT << display::getBracketedTypeName(x);
      MOUT << endl;
      MOUT << StyledString::get(HORLINE);
      return false;
    }
    return true;
  }

  template <typename T>
  inline void setFormatString(const std::string fstring) {
    T* xptr = new T(25);
    bool valid = checkFormatString<T>(fstring, *xptr);
    if (valid) {
      FormatData<T>::format_string = fstring;
    }
  }

  //---------------------------------------------------------------------------------
  //       dispvalstrm
  //---------------------------------------------------------------------------------

  template <typename T>
  inline void dispval_strm(std::ostream& stream, const T& d) {
    stream << d;
  }

#define SPECIALIZE_mathtypes_dispval_strm(TYPE)                           \
  template <>                                                             \
  inline void dispval_strm<TYPE>(std::ostream & stream, const TYPE &d) {  \
    using namespace std;                                                  \
    string sval = printf2str(FormatData<TYPE>::format_string.c_str(), d); \
    Style style = FormatData<TYPE>::style_for_value;                      \
    TYPE zero = 0;                                                        \
    if (d == zero) {                                                      \
      style = FormatData<TYPE>::style_for_zero;                           \
    }                                                                     \
    stream << style.apply(sval);                                          \
  }

  SPECIALIZE_mathtypes_dispval_strm(short);
  SPECIALIZE_mathtypes_dispval_strm(int);
  SPECIALIZE_mathtypes_dispval_strm(long);
  SPECIALIZE_mathtypes_dispval_strm(long long);

  SPECIALIZE_mathtypes_dispval_strm(unsigned short);
  SPECIALIZE_mathtypes_dispval_strm(unsigned int);
  SPECIALIZE_mathtypes_dispval_strm(unsigned long);
  SPECIALIZE_mathtypes_dispval_strm(unsigned long long);

#define SPECIALIZE_floating_dispval_strm(TYPE)                            \
  template <>                                                             \
  inline void dispval_strm<TYPE>(std::ostream & stream, const TYPE &d) {  \
    using namespace std;                                                  \
    string sval = printf2str(FormatData<TYPE>::format_string.c_str(), d); \
    if (FormatData<TYPE>::tens) {                                         \
      sval = replaceAll(sval, "E", " 10^");                               \
      sval = replaceAll(sval, "e", " 10^");                               \
    }                                                                     \
    Style style = FormatData<TYPE>::style_for_value;                      \
    TYPE zero = 0;                                                        \
    if (d == zero) {                                                      \
      style = FormatData<TYPE>::style_for_zero;                           \
    }                                                                     \
    stream << style.apply(sval);                                          \
  }

  SPECIALIZE_floating_dispval_strm(float);
  SPECIALIZE_floating_dispval_strm(double);
  SPECIALIZE_floating_dispval_strm(long double);


  // mathq::Domain
  template <typename T>
  inline void dispval_strm(std::ostream& stream, const mathq::Domain<T>& var) {
    stream << "(";
    dispval_strm(stream, var.a);
    stream << ",";
    dispval_strm(stream, var.b);
    stream << ",";
    dispval_strm(stream, var.N);
    stream << ")";
  }

  // mathq::Nabla
  template <typename D>
  inline void dispval_strm(std::ostream& stream, const mathq::Nabla<D>& var) {
    stream << "(Ndims=";
    dispval_strm(stream, var.Ndims);
    stream << ", Nwindow=";
    dispval_strm(stream, var.Nwindow);
    stream << ", periodic=";
    dispval_strm(stream, var.periodic);
    stream << ")";
  }



  // string
  template <>
  inline void dispval_strm<std::string>(std::ostream& stream, const std::string& str) {
    using namespace std;
    string s = printf2str(FormatData<std::string>::format_string.c_str(), str.c_str());
    Style style = FormatData<std::string>::style_for_value;
    stream << style.apply(s);
  }

  // char
  template <>
  inline void dispval_strm<char>(std::ostream& stream, const char& c) {
    using namespace std;
    string s = printf2str(FormatData<char>::format_string.c_str(), c);
    Style style = FormatData<char>::style_for_value;
    stream << style.apply(s);
  }

  // bool
  template <>
  inline void dispval_strm<bool>(std::ostream& stream, const bool& b) {
    using namespace std;
    if (b) {
      Style style = FormatData<bool>::style_for_true;
      string s = FormatData<bool>::string_for_true;
      stream << style.apply(s);
    }
    else {
      Style style = FormatData<bool>::style_for_false;
      string s = FormatData<bool>::string_for_false;
      stream << style.apply(s);
    }
  }

  // T[N]
  template <typename T, size_t N>
  inline void dispval_strm(std::ostream& stream, const T(&a)[N]) {
    stream << "{";
    for (size_t ii = 0; ii < N; ii++) {
      if (ii > 0)
        stream << ", ";
      dispval_strm(stream, a[ii]);
    }
    stream << "}";
  }

  // char[N]
  template <size_t N>
  inline void dispval_strm(std::ostream& stream, const char(&a)[N]) {
    stream << a;
  }

  // std::vector
  template <typename D>
  inline void dispval_strm(std::ostream& stream, const std::vector<D>& var) {
    stream << "{";
    for (size_t ii = 0; ii < var.size(); ii++) {
      if (ii > 0)
        stream << ", ";
      dispval_strm(stream, var[ii]);
    }
    stream << "}";
  }

  // std::valarray
  template <typename D>
  inline void dispval_strm(std::ostream& stream, const std::valarray<D>& var) {
    stream << "{";
    for (size_t ii = 0; ii < var.size(); ii++) {
      if (ii > 0)
        stream << ", ";
      dispval_strm(stream, var[ii]);
    }
    stream << "}";
  }

  // std::array
  template <typename D, unsigned long int N>
  inline void dispval_strm(std::ostream& stream, const std::array<D, N>& var) {
    stream << "{";
    for (size_t ii = 0; ii < var.size(); ii++) {
      if (ii > 0)
        stream << ", ";
      dispval_strm(stream, var[ii]);
    }
    stream << "}";
  }

  // std::list
  template <typename D>
  inline void dispval_strm(std::ostream& stream, const std::list<D>& var) {
    stream << "{";
    size_t ii = 0;
    for (typename std::list<D>::const_iterator it = var.begin(); it != var.end(); ++it) {
      if (ii++ > 0)
        stream << ", ";
      dispval_strm(stream, *it);
    }
    stream << "}";
  }

  // std::initializer_list
  template <typename D>
  inline void dispval_strm(std::ostream& stream, const std::initializer_list<D>& var) {
    stream << "{";
    size_t ii = 0;
    for (auto it = var.begin(); it != var.end(); ++it) {
      if (ii++ > 0)
        stream << ", ";
      dispval_strm(stream, *it);
    }
    stream << "}";
  }

  // std::queue
  template <typename D>
  void dispval_strm(std::ostream& stream, const std::queue<D>& var) {
    // ** We have to copy the queue to iterate through contents since this is a desrtuctive process
    std::queue<D> myq = var;

    stream << "{";
    const size_t N = myq.size();
    for (size_t ii = 0; ii < N; ii++) {
      if (ii > 0)
        stream << ", ";
      D val = myq.front();
      myq.pop();
      dispval_strm(stream, val);
    }
    stream << "}";
  }

  // std::map
  template <typename D1, typename D2>
  void dispval_strm(std::ostream& stream, const std::map<D1, D2>& mymap) {
    stream << "{" << std::endl;
    for (typename std::map<D1, D2>::const_iterator it = mymap.begin(); it != mymap.end(); it++) {
      stream << " " << it->first << ":" << it->second << std::endl;
    }
    stream << "}";
  }




  // template< class T >
  // inline constexpr std::size_t tuple_size_v = std::tuple_size<T>::value;

  // template <size_t I = 0, typename... Ts>
  // constexpr std::string getTypeName(const std::tuple<Ts...>& var, std::string s = std::string("")) {
  //   if constexpr (I == sizeof...(Ts)) {
  //     return s+StyledString::get(ANGLE2).get();
  //   }
  //   else {
  //     using SelectedType = std::tuple_element_t<I, std::tuple<Ts...> >;
  //     if constexpr (I == 0) {
  //       std::string s1 = getTypeStyle(var).apply("std::tuple");
  //       s += s1;
  //       s += StyledString::get(ANGLE1).get();
  //     }
  //     else {
  //       s += StyledString::get(COMMA).get();
  //     }
  //     s += getTypeName(SelectedType());
  //     return getTypeName<I + 1, Ts...>(var, s);
  //   }
  // }

  // // std::tuple

  template <size_t I = 0, typename... Ts>
  inline void dispval_strm(std::ostream& stream, const std::tuple<Ts...>& var) {
    if constexpr (I == sizeof...(Ts)) {
      stream << "}";
    }
    else {
      using SelectedType = std::tuple_element_t<I, std::tuple<Ts...> >;
      if constexpr (I == 0) {
        stream << "{";
      }
      else {
        stream <<  StyledString::get(COMMA).get();
      }
      stream << std::get<I>(var);
      dispval_strm<I + 1, Ts...>(stream, var);
    }
  }


  // std::cout << "index " << I << " has type: ";
  // using SelectedType = std::tuple_element_t<I, T>;

//---------------------------------------------------------------------------------
//       specialize for complex
//---------------------------------------------------------------------------------

  class FormatDataComplex {
  public:
    static Style style_for_punctuation;
    static std::string format_string;
    const static std::string format_string_default;
  };

  inline bool checkFormatStringComplex(const std::string formatstr) {
    using namespace std;
    if (formatstr.empty()) {
      return false;
    }

    bool passed = true;
    string sr = string("%f");
    string si = string("%f");
    string s;
    try {
      s = printf2str(formatstr.c_str(), sr.c_str(), si.c_str());
    }
    catch (...) {
      passed = false;
    }
    size_t found = s.find("(nil)");
    if (found != string::npos)
      passed = false;

    string formatfloats = s;
    float xreal = 3.1415;
    float ximag = 2.72;
    try {
      s = printf2str(formatfloats.c_str(), xreal, ximag);
    }
    catch (...) {
      passed = false;
    }
    found = s.find("(nil)");
    if (found != string::npos)
      passed = false;

    //    printf("formatstr = %s\n",formatstr.c_str());
    //    printf("formatfloats = %s\n",formatfloats.c_str());

    float xreal2 = 3.1415;
    float ximag2 = 2.72;
    int ret = std::sscanf(s.c_str(), formatfloats.c_str(), &xreal2, &ximag2);
    //    printf("xreal2=%f ximag2=%f\n",xreal2,ximag2);
    if (ret != 2)
      passed = false;
    if (xreal2 != xreal)
      passed = false;
    if (ximag2 != ximag)
      passed = false;

    if (!passed) {
      MOUT << StyledString::get(HORLINE);
      MOUT << StyledString::get(ERROR);
      MOUT << " illegal format string";
      MOUT << CREATESTYLE(BOLD).apply(string(" \"") + formatstr + "\"");
      MOUT << " passed to setFormatStringComplex";
      MOUT << endl;
      MOUT << StyledString::get(HORLINE);
      return false;
    }
    return true;
  }

  inline std::string getFormatStringComplex() {
    return FormatDataComplex::format_string;
  }

  inline void setFormatStringComplex(const std::string fstring) {
    bool valid = checkFormatStringComplex(fstring);
    if (valid) {
      FormatDataComplex::format_string = fstring;
    }
  }

  template <class D>
  void dispval_strm(std::ostream& stream, const std::complex<D>& d) {
    using namespace std;
    using namespace mathq;

    // print the real and imaginary parts to strings
    string sr = printf2str(getFormatString<D>().c_str(), d.real());
    string si = printf2str(getFormatString<D>().c_str(), d.imag());

    // decompose the format string so we can apply style to the punctuation
    string fs = getFormatStringComplex();
    int m1 = fs.find("%s");
    string fs1 = fs.substr(0, m1);
    int m2 = fs.find("%s", m1 + 2);
    string fs2 = fs.substr(m1 + 2, m2 - m1 - 2);
    string fs3 = fs.substr(m2 + 2, fs.size() - m2 - 2);
    Style style = FormatDataComplex::style_for_punctuation;
    fs = style.apply(fs1) + "%s" + style.apply(fs2) + "%s" + style.apply(fs3);

    // put it all together
    stream << printf2str(fs.c_str(), sr.c_str(), si.c_str());
  }

  //****************************************************************************
  //                       Log
  //****************************************************************************

  class Log {
  public:
    static Style style_log0;
    static Style style_log1;
    static Style style_log2;
    static Style style_log3;
    static Style style_nspace;
    ;
    static Style style_class;
    static Style style_func;
    static Style style_str;

    static void log(const int level, const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "");
    static void print(const int level, std::string s);
    static void warning(const std::string s);
    static void error(const std::string s);
    static void indent(const std::string s);

    Log();

  }; // class  Log

  inline void log(const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "") {
    display::Log::log(0, spaceName, className, funcName, s);
    //    MOUT << __PRETTY_FUNCTION__;
  }

  inline void log1(const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "") {
#if MATHQ_DEBUG >= 1
    display::Log::log(1, spaceName, className, funcName, s);
#endif
  }

  inline void log2(const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "") {
#if MATHQ_DEBUG >= 2
    display::Log::log(2, spaceName, className, funcName, s);
#endif
  }

  inline void log3(const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "") {
#if MATHQ_DEBUG >= 3
    display::Log::log(3, spaceName, className, funcName, s);
#endif
  }

  inline void print1(const std::string s) {
#if MATHQ_DEBUG >= 1
    display::Log::print(1, s);
#endif
  }
  inline void print2(const std::string s) {
#if MATHQ_DEBUG >= 2
    display::Log::print(2, s);
#endif
  }
  inline void print3(const std::string s) {
#if MATHQ_DEBUG >= 3
    display::Log::print(3, s);
#endif
  }

  //****************************************************************************
  //                       Display
  //****************************************************************************

  // TODO:
  //       add method that supports ECHO_CODE?
  //       add class variable that if defined overrides the default, taken from the Format class

  class Display {
  private:
    static bool isInitialized;

  public:
    static StyledString codePrefixStyledString;
    static StyledString prefixStyledString;
    static Style expressionStyle;
    static StyledString equalsStyledString;
    static StyledString multiSeparatorStyledString;
    static StyledString terminatorStyledString;


  public:
    static void initialize() {
      //      log3("display","Display","initialize","()");

      Display::isInitialized = true;
    }
    Display() {
      if (!isInitialized) {
        Display::initialize();
      }
    }

    // NOTE: do NOT try to combine mydisp_notype and mydisp_type
    //       this wil causes compilation failure if X.classname() does not
    //       exists, EVEN if you put getTypeName(x) inside an if clause

    template <typename X>
    static void mydisp_notype(std::ostream& stream, const X& x, const std::string name, const bool issueCR, const std::string postString = "") {
      using namespace std;
      //      log3("display","Display","mydisp_notype","(const X& x, const std::string name)");
      stream << prefixStyledString;
      stream << StyledString(expressionStyle, name);
      stream << equalsStyledString;
      dispval_strm(stream, x);
      stream << postString;
      stream << terminatorStyledString;
      if (issueCR) {
        stream << endl;
      }
    }
    template <typename X>
    static void multidisp_notype(std::ostream& stream, const X& x, const std::string name) {
      using namespace std;
      //      log3("display","Display","mydisp_notype","(const X& x, const std::string name)");
      stream << prefixStyledString;
      stream << StyledString(expressionStyle, name);
      stream << equalsStyledString;
      dispval_strm(stream, x);
      stream << multiSeparatorStyledString;
    }

    template <typename X>
    static void mydispcr(std::ostream& stream, const X& x, const std::string name, const std::string postString = "") {
      using namespace std;
      mydisp_notype(stream, x, name, true, postString);
    }

    template <typename X>
    static void mydisp_type(std::ostream& stream, const X& x, const std::string name, const bool issueCR) {
      using namespace std;
      //      log3("display","Display","mydisp_type","(const X& x, const std::string name)");
      stream << prefixStyledString;
      stream << StyledString(expressionStyle, name);
      stream << equalsStyledString;
      dispval_strm(stream, x);
      stream << terminatorStyledString;
      if (issueCR) {
        stream << endl;
      }
    }

    template <typename X>
    static void mydisp_type_rhs(std::ostream& stream, const X& x, const std::string name, const bool issueCR) {
      using namespace std;
      //      log3("display","Display","mydisp_type_rhs","(const X& x, const std::string name)");
      stream << prefixStyledString;
      stream << StyledString(expressionStyle, name);
      stream << equalsStyledString;
      stream << getTypeName(x) << " ";
      dispval_strm(stream, x);
      stream << terminatorStyledString;
      if (issueCR) {
        stream << endl;
      }
    }
    template <typename X>
    static void tmydisp(std::ostream& stream, const X& x, const std::string name) {
      using namespace std;
      mydisp_type(stream, x, name, false);
    }
    template <typename X>
    static void tmydispcr(std::ostream& stream, const X& x, const std::string name) {
      using namespace std;
      mydisp_type(stream, x, name, true);
    }

    template <typename X>
    static void trmydisp(std::ostream& stream, const X& x, const std::string name) {
      using namespace std;
      mydisp_type_rhs(stream, x, name, false);
    }
    template <typename X>
    static void trmydispcr(std::ostream& stream, const X& x, const std::string name) {
      using namespace std;
      mydisp_type_rhs(stream, x, name, true);
    }

    static void issuecr(std::ostream& stream) {
      stream << std::endl;
    }
  }; // class Display


  //****************************************************************************
  //                       print_mathq_info
  //****************************************************************************

  inline void print_debug_level(void) {
    StyledString ss;
#if (MATHQ_DEBUG == 0)
    ss = StyledString::get(SSEnum::DLEVEL0);
#elif (MATHQ_DEBUG == 1)
    ss = StyledString::get(SSEnum::DLEVEL1);
#elif (MATHQ_DEBUG == 2)
    ss = StyledString::get(SSEnum::DLEVEL2);
#elif (MATHQ_DEBUG >= 3)
    ss = StyledString::get(SSEnum::DLEVEL3);
#endif
    MOUT << "  " << ss << " " << std::endl;
  }

  inline void print_mathq_info(void) {
    using namespace std;
    using namespace display;
    MOUT << StyledString::get(HORLINE);
    MOUT << StyledString::get(MATHEMATIQUES) << " ";
    MOUT << StyledString::get(VERSION) << " ";
    MOUT << endl
      << endl;
    MOUT << "compile-time settings" << endl;
    print_debug_level();
    MOUT << CREATESTYLE(BOLD).apply("  C++ version: ");
    MOUT << CREATESTYLE(CYAN).apply(printf2str("%lu", __cplusplus)) << endl;
#ifdef MATHQ_COPTS
    MOUT << CREATESTYLE(BOLD).apply("  g++ OPTIMIZATION FLAGS: ");
    MOUT << CREATESTYLE(CYAN).apply(string(COMPILER_OPT_STR)) << endl;
#endif
    MOUT << StyledString::get(HORLINE);
  }

  inline void set_default_format() {
    using namespace display;
    // TODO: include all default styles

    // TODO: put these into an intilization and share it here as well as in cpp file
    FormatDataVector::style_for_punctuation = CREATESTYLE(GRAY1);
    FormatDataVector::string_endofline = "\n";
    FormatDataVector::string_opening = "{";
    FormatDataVector::string_delimeter = ",";
    FormatDataVector::max_elements_per_line = mathq::maxsize;
    FormatDataVector::string_closing = "}";

    // TODO: put these into an intilization and share it here as well as in cpp file
    FormatDataMatrix::max_elements_per_line = mathq::maxsize;
    FormatDataMatrix::style_for_punctuation = CREATESTYLE(GRAY1);
    FormatDataMatrix::string_opening = "{";
    FormatDataMatrix::string_delimeter = ", ";
    FormatDataMatrix::string_row_opening = " {";
    FormatDataMatrix::string_row_closing = "},";
    FormatDataMatrix::string_lastrow_closing = "} ";
    FormatDataMatrix::string_endofline = "\n";
    FormatDataMatrix::string_closing = "}";

    setFormatStringComplex("(%s, %s)");

    FormatData<double>::format_string = FormatData<double>::format_string_default;
    FormatData<double>::tens = false;
    FormatData<float>::format_string = FormatData<float>::format_string_default;
    FormatData<long double>::format_string = FormatData<long double>::format_string_default;
    FormatData<short>::format_string = FormatData<short>::format_string_default;
    FormatData<int>::format_string = FormatData<int>::format_string_default;
    FormatData<long>::format_string = FormatData<long>::format_string_default;
    FormatData<unsigned short>::format_string = FormatData<unsigned short>::format_string_default;
    FormatData<unsigned int>::format_string = FormatData<unsigned int>::format_string_default;
    FormatData<unsigned long>::format_string = FormatData<unsigned long>::format_string_default;
    FormatData<char>::format_string = FormatData<char>::format_string_default;

    FormatData<std::string>::format_string = FormatData<std::string>::format_string_default;

    FormatData<bool>::string_for_true = "1";
    FormatData<bool>::string_for_false = "0";
  }

  inline void set_mathematica_var_format() {
    using namespace display;
    FormatDataVector::string_opening = "{\n    ";
    FormatDataVector::string_delimeter = ", ";
    FormatDataVector::max_elements_per_line = 5;
    FormatDataVector::string_endofline = "\n    ";
    FormatDataVector::string_closing = "\n}";
    setFormatString<double>("% 10.8e");
    setFormatStringComplex("%s + I*%s");
    FormatData<double>::tens = true;
  }

  inline void set_matlab_var_format() {
    using namespace display;
    FormatDataVector::string_opening = "[ ...\n    ";
    FormatDataVector::string_delimeter = ", ";
    FormatDataVector::max_elements_per_line = 5;
    FormatDataVector::string_endofline = " ...\n    ";
    FormatDataVector::string_closing = " ...\n]";
    setFormatString<double>("% 10.8e");
    setFormatStringComplex("%s + i*%s");
    FormatData<double>::tens = false;
  }



}; // namespace display




#endif // file