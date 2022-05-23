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

  CR();
  CR();
  OUTPUT("C++ also provides support for integer division witjh remainder.\n");
  OUTPUT("If both numerator and denominator are integers, the division operator gives the integer division result.\n");
  OUTPUT("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  CR();
  OUTPUT("| operator | operation | types | ");
  OUTPUT("| :---: | :---: | :---: | ");
  OUTPUT("| `/` | integer division | 𝕤, 𝕌 | ");
  OUTPUT("| `%` | modulus | ℤ | ");
  CR();

  GMD_VSPACE();
  GMD_HEADER3("Examples: integer division");
  GMD_CODE_START("C++");
  TRDISP(7 / 2);
  GMD_CODE_END();
  OUTPUT("* The modulus operator `a % b`, gives the remainder after integer divison of `a` by `b`.\n");
  GMD_CODE_START("C++");
  TRDISP(7 % 2);
  GMD_CODE_END();
  OUTPUT("* The function [`std::div`](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.\n");

  GMD_CODE_START("C++");
  ECHO_CODE(div_t result = div(7, 2));
  GMD_CODE_END();
  OUTPUT("With result:\n");
  GMD_CODE_START("C++");
  TRDISP(result.quot);
  TRDISP(result.rem);
  GMD_CODE_END();

  return 0;
}
