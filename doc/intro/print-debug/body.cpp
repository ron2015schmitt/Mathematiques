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

  GMD_HEADER2("Pretty Printing to a Terminal");
  OUTPUT("Mathématiques provides functions and macros for printing of ASCII and Unicode text that is cleanly formatted, colored and stylized.");
  OUTPUT("Colors and styles require a terminal that support [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code). ");


  GMD_HEADER3("ECHO for C++ statements");
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
  GMD_HEADER3("ETV for C++ variables and expressions");
  OUTPUT("`ETV` stands for 'Expression Type Value', and that is what it prints.  All results are preceded by the `☀` Unicode character to distinguish results from code.");
  {
    GMD_CODE_START("C++");
    OUTPUT("ECHO(int x = 5);");
    OUTPUT("ETV(x);");
    OUTPUT("ETV(3 * 25 * std::sin(3.1415/20));");
    OUTPUT("ETV(mathq::Vector<double> {1, 2, 3});");
    GMD_CODE_END();
  }

  OUTPUT("The above C++ code will print the following to stdout in the terminal (actual screen captures):");

  // CR();
  // ECHO(int x = 5);
  // ETV(x);
  // ETV(3 * 25 * std::sin(3.1415/20));
  // ETV(mathq::Vector<double> {1, 2, 3});
  // CR();

  CR();
  OUTPUT("| <sub>Light mode in Ubuntu WSL2 terminal on Windows</sub> |");
  OUTPUT("| --- |");
  OUTPUT("| ![etv-light mode](https://user-images.githubusercontent.com/11559541/189542566-fcb8bd50-b9ea-4fcc-9c89-5b7c287d5487.png) |");
  CR();
  OUTPUT("| <sub>Dark mode in VS Code terminal</sub> |");
  OUTPUT("| --- |");
  OUTPUT("| ![etv-dark mode](https://user-images.githubusercontent.com/11559541/189542572-43356054-59e2-4861-9d35-a004dc1215b5.png) |");
  CR();

  GMD_VSPACE();
  GMD_HEADER3("GMD_CODEBOX for Markdown code box generation");
  OUTPUT("The macros `GMD_CODEBOX_START` and `GMD_CODEBOX_END` can be used to create a codebox using the [github markdown language](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).");
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

  OUTPUT("The above C++ code generates text for the following markdown code box:");
  {
    GMD_CODE_START("C++");
    ECHO(int x = 5);
    ECHO(mathq::Vector<double> v{ 1, 2, 3 });
    ETV(10*v + 100*x);
    GMD_CODE_END();
  }

  GMD_VSPACE();
  GMD_HEADER3("Other printing functionality");
  OUTPUT("Other macros and functions are also available.");
  OUTPUT("A full refactoring of the printing functionality is underway.");


  GMD_VSPACE();
  GMD_HEADER2("Compilation Modes and Debugging Support");
  OUTPUT("Mathématiques supports various compilations modes to aid in debugging using the tab `MATHQ_DEBUG`.");

  // describe what it does
  OUTPUT("");

  GMD_VSPACE();
  GMD_HEADER3("Setting the compilation mode");
  OUTPUT("To compile in DEBUG mode, include `MATHQ_DEBUG=n` with your make command, where `n` is the DEBUG level. ");
  OUTPUT("Using `MATHQ_DEBUG=0` is equivalent to not specifying a value, ie the production compilation mode is used.");
  {
    GMD_CODE_START("make");
    OUTPUT("make filename MATHQ_DEBUG=1");
    GMD_CODE_END();
  }
  OUTPUT("The makefile then adds `-D \"MATHQ_DEBUG = n\"` to the compiler options.");
  CR();
  OUTPUT("In the C++ code, compilation will take place with the [C++ preprocessor](https://cplusplus.com/doc/tutorial/preprocessor/) symbol `MATHQ_DEBUG` defined and set to `n`.");
  OUTPUT("That is, it will be as if the line `#define MATHQ_DEBUG n` is include at the top of each source file.");


  GMD_VSPACE();
  GMD_HEADER3(".compiler files");
  // compilation info stored in files. 
  OUTPUT("");

  GMD_VSPACE();
  GMD_HEADER3("Printing information about the compilation mode from C++");
  // can display
  OUTPUT("");

  {
    GMD_CODE_START("C++");
    OUTPUT("display::print_mathq_info();");
    GMD_CODE_END();
  }

  {
    GMD_CODE_START("make");
    display::print_mathq_info();
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER3("Current Status");
  OUTPUT("A full refactoring of the debug functionality is planned.");
  OUTPUT("Currently all debug messages are disabled until the printing code is refactored.");

  return 0;
}
