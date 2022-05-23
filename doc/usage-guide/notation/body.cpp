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

  GMD_PREAMBLE();

  GMD_VSPACE();

  GMD_HEADER2("Code and results");

  OUTPUT("In this documentation, code is shown inline as `int x` and in code blocks:");

  CR();
  CR();
  GMD_CODE_START("C++");
  ECHO_CODE(double pi = 3.14);
  ECHO_CODE(double r = 2.5);
  ECHO_CODE(double area = pi * pow(r, 2));
  GMD_CODE_END();

  MOUT << "Results are also shown in code blocks but with each line preceded by the symbol `" << Display::prefixStyledString << "`";
  CR();

  CR();
  CR();
  GMD_CODE_START("C++");
  TRDISP(pi);
  TRDISP(r);
  TRDISP(area);
  GMD_CODE_END();

  OUTPUT("This is also how the results are output in a linux terminal, albeit with slightly different coloring.  A screen shot of the same results are shown below\n");
  OUTPUT("![linux-terminal-example-output](linux-terminal-example-output.png)\n");
  CR();

  OUTPUT("The code used to display these results is:\n");
  CR();
  CR();
  GMD_CODE_START("C++");
  OUTPUT("TRDISP(pi);");
  OUTPUT("TRDISP(r);");
  OUTPUT("TRDISP(area);");
  GMD_CODE_END();

  OUTPUT("This topic is covered in detail in the Display section of this guide.\n");


  MOUT << "Often we will display code and results together, with the symbol `" << Display::prefixStyledString << "` distinguishing results from code:";

  CR();
  CR();
  GMD_CODE_START("C++");
  ECHO_CODE(double x = 1.52);
  TRDISP(x);
  GMD_CODE_END();


  GMD_HEADER2("Numbers and containers");


  OUTPUT("The following notation shorthand is used in the User Guide (but certainly not in C++ code!).\n");

  GMD_HEADER3("Scalars");
  CR();
  OUTPUT("| symbol | C++ types |");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| ℤ | any C++ real signed integral type: `bool`, `int`, `long`, etc | ");
  OUTPUT("| ℕ | any C++ real unsigned integral type: `unsigned int`, `unsigned long`, etc | ");
  OUTPUT("| ℝ | any C++ real floating-point type: `float`, `double`, `long double`) | ");
  OUTPUT("| ℂ | any `std::complex<ℝ>` | ");
  OUTPUT("| 𝕁 | any `Imaginary<ℝ>` | ");
  OUTPUT("| ℍ | any `Quaternion<ℝ>` | ");
  OUTPUT("| 𝕂 | any ℝ, ℂ, 𝕁, ℍ | ");
  OUTPUT("| 𝕤 | any ℤ, 𝕂 | ");

  CR();
  OUTPUT("Lower case 𝕤 was chosen because 𝕊 is commonly used in mathematics for the spherical groups\n");



  GMD_VSPACE();

  GMD_HEADER3("Containers");
  CR();
  OUTPUT("| symbol | C++ types |");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| 𝕍 | any `Vector<T>` for any scalar or container type or type symbol T | ");
  OUTPUT("| 𝕄 | any `Matrix<T>` for any scalar or container type or type symbol T | ");
  OUTPUT("| 𝕥 | any `Tensor<T>` for any scalar or container type or type symbol T | ");
  OUTPUT("| 𝕌 | any 𝕍, 𝕄, 𝕥 | ");
  CR();
  OUTPUT("Lower case 𝕥 was chosen because 𝕋 is commonly used in mathematics for the torus groups\n");

  CR();
  GMD_VSPACE();

  return 0;
}
