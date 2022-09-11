#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>


#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  // using namespace mathq::unit_quaternion;
  // using namespace mathq::unit_imaginary;
  // using std::sqrt;

  GMD_HEADER2("Pretty Printing to a terminal");
  OUTPUT("Mathématiques provides printing of ASCII and Unicode text that is cleanly formatted, colored and stylized.");
  OUTPUT("Colors and styles require a terminal that support [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code). ");


  GMD_HEADER2("ECHO() for C++ statements");
  OUTPUT("The `ECHO` macro prints the enclosed C++ statement to the stdout, in addition to the statement being compiled and included in the executable.");
  {
    GMD_CODE_START("C++");
    OUTPUT("ECHO(int x = 5);");
    OUTPUT("ECHO(double y = x * 3.1415);");
    GMD_CODE_END();
  }
  GMD_VSPACE();

  OUTPUT("will print the following the terminal (actual screen captures)");

  OUTPUT("Light mode in Ubuntu WSL2 terminal on Windows");

  OUTPUT("Dark mode in VS Code terminal");


  GMD_HEADER2("ETV() for the value of C++ variables and C++ expressions");
  OUTPUT("`ETV` stands for 'Expression Type Value'.  All results are preceded by the `☀` Unicode character to distinguish results from code.");
  {
    GMD_CODE_START("C++");
    OUTPUT("ECHO(int x = 5);");
    OUTPUT("ETV(x);");
    OUTPUT("ETV(3 * 25 * std::sin(3.1415/20));");
    OUTPUT("ETV(mathq::Vector<double> {1, 2, 3});");
    CR();
    GMD_CODE_END();
  }
  GMD_VSPACE();

  OUTPUT("will print the following the terminal (actual screen captures)");
  OUTPUT("Light mode in Ubuntu WSL2 terminal on Windows");
  OUTPUT("Dark mode in VS Code terminal");

  GMD_HEADER2("Markdown code box generation");
  OUTPUT("In fact these online documentation files are automatically created using C++ files, python scripts for the table of contents and numbering, and make files that put it all together during the build process.");
  OUTPUT("The documentation is generated for every new version.");
  OUTPUT("This ensures that results shown for every example in the documenation will match what you compile.");

  {
    GMD_CODE_START("C++");
    OUTPUT("GMD_CODE_START(\"C++\");");
    OUTPUT("ECHO(int x = 5);");
    OUTPUT("ECHO(double y = x * 3.1415);");
    OUTPUT("GMD_CODE_END();");
    GMD_CODE_END();
  }
  GMD_VSPACE();

  OUTPUT("");
  {
    GMD_CODE_START("C++");
    ETV(3 * 25 * std::sin(3.1415/20));
    ETV(mathq::Vector<double> {1, 2, 3});
    CR();
    GMD_CODE_END();
  }
  GMD_VSPACE();

  OUTPUT("Other MACROS and functions are also available, including marcros that aid in creating[github markdown]() files.");
  OUTPUT("A full refactoring of the printing functionality is underway.");

  GMD_HEADER2("Compilation Modes and Debugging Support");
  OUTPUT("Mathématiques supports various compilations modes to aid in debugging:");

  // make with tag
  // levels
  // use in files
  // can display
  // compilation info stored in files. can also display

  {
    GMD_CODE_START("C++");
    ECHO(unsigned int n = 23);
    ETV(n);
    ETV(n + 102 - 2*4);
    ETV(n - 24);
    ETV(n/2);
    ETV(n % 2);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  OUTPUT("A full refactoring of the printing functionality is planned.  Currently all debug messages are disabled until the printing code is refactored.");
  OUTPUT("However, the `` preprocessor symbol can be utilized in user code at present.");

  return 0;
}
