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

  // CR();
  // ECHO(int x = 5);
  // ECHO(double y = x * 3.1415);
  // CR();
  OUTPUT("The above C++ code will print the following to stdout in the terminal (actual screen capture):");
  OUTPUT("| <sub>Light mode in Ubuntu WSL2 terminal on Windows</sub> |");
  OUTPUT("| --- |");
  OUTPUT("| ![echo](https://user-images.githubusercontent.com/11559541/189542553-6190eb19-ca59-4a1e-92a3-debd5aa71335.png) |");
  CR();

  GMD_VSPACE();
  GMD_HEADER2("ETV() for C++ variables and expressions");
  OUTPUT("`ETV` stands for 'Expression Type Value', and that is what it prints.  All results are preceded by the `☀` Unicode character to distinguish results from code.");
  {
    GMD_CODE_START("C++");
    OUTPUT("ECHO(int x = 5);");
    OUTPUT("ETV(x);");
    OUTPUT("ETV(3 * 25 * std::sin(3.1415/20));");
    OUTPUT("ETV(mathq::Vector<double> {1, 2, 3});");
    GMD_CODE_END();
  }

  OUTPUT("The above C++ code will print the following the terminal (actual screen captures):");

  // CR();
  // ECHO(int x = 5);
  // ETV(x);
  // ETV(3 * 25 * std::sin(3.1415/20));
  // ETV(mathq::Vector<double> {1, 2, 3});
  // CR();

  OUTPUT("The above C++ code will print the following to stdout in the terminal (actual screen captures):");
  OUTPUT("| <sub>Light mode in Ubuntu WSL2 terminal on Windows</sub> |");
  OUTPUT("| --- |");
  OUTPUT("| ![etv-light mode](https://user-images.githubusercontent.com/11559541/189542566-fcb8bd50-b9ea-4fcc-9c89-5b7c287d5487.png) |");
  OUTPUT("| <sub>Dark mode in VS Code terminal</sub> |");
  OUTPUT("| --- |");
  OUTPUT("| ![etv-dark mode](https ://user-images.githubusercontent.com/11559541/189542572-43356054-59e2-4861-9d35-a004dc1215b5.png) |");
  CR();

  GMD_VSPACE();
  GMD_HEADER2("Markdown code box generation");
  OUTPUT("In fact these online documentation files are automatically created using C++ files, python scripts for the table of contents and numbering, and make files that put it all together during the build process.");
  OUTPUT("The documentation is generated for every new version.");
  OUTPUT("This ensures that results shown for every example in the documenation will match what you compile.");

  {
    GMD_CODE_START("C++");
    OUTPUT("GMD_CODE_START(\"C++\");");
    OUTPUT("ECHO(int x = 5);");
    OUTPUT("ECHO(mathq::Vector<double> v{1, 2, 3});");
    OUTPUT("ETV(10*v + 100*x);");
    OUTPUT("GMD_CODE_END();");
    GMD_CODE_END();
  }
  GMD_VSPACE();

  OUTPUT("The above C++ code generates the following markdown code box:");
  {
    GMD_CODE_START("C++");
    ECHO(int x = 5);
    ECHO(mathq::Vector<double> v{ 1, 2, 3 });
    ETV(10*v + 100*x);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  OUTPUT("Other macros and functions are also available, including macros that aid in creating[github markdown]() files.");
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
