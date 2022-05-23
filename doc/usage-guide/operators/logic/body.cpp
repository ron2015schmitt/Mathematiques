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

  GMD_VSPACE();
  GMD_HEADER2("Logic Operators");
  OUTPUT("For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).\n");

  CR();
  OUTPUT("| operator | operation | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `!` | logical NOT | ");
  OUTPUT("| `\\|\\|` | logical OR | ");
  OUTPUT("| `&&` | logical AND | ");
  CR();

  OUTPUT("**CAVEAT**: C++ also has binary bit-wise operators `&` and `|`.  Mistyping the above operators can cause painful bugs. \n");

  CR();
  OUTPUT("Examples:\n");
  GMD_CODE_START("C++");
  TRDISP(true);
  TRDISP(false);
  TRDISP(!true);
  TRDISP(!false);
  TRDISP(true && true);
  TRDISP(true && false);
  TRDISP(true || false);
  GMD_CODE_END();

  OUTPUT("* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`\n");
  GMD_CODE_START("C++");
  TRDISP(!true);
  TRDISP(!8);
  TRDISP(!!8.293);
  TRDISP(true && 3);
  TRDISP(true && 0);
  GMD_CODE_END();

  GMD_VSPACE();

  return 0;
}
