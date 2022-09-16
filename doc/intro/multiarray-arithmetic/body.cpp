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

  OUTPUT("Mathématiques supports arithmetic, relational, and logic operators for MultiArrays");

  GMD_HEADER2("Arithmetic Operators");
  OUTPUT("The operators `+, -, *, /` are the addition, subtraction, multiplication, and division operators respectively.\n");
  OUTPUT("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  CR();
  OUTPUT("| operator | operation | types | ");
  OUTPUT("| :---: | :---: | :---: | ");
  OUTPUT("| `+` | addition | 𝕤, 𝕌 | ");
  OUTPUT("| `-` | subtraction | 𝕤, 𝕌 | ");
  OUTPUT("| `*` | multiplication | 𝕤, 𝕌 | ");
  OUTPUT("| `/` | division | 𝕤, 𝕌 | ");
  CR();

  OUTPUT("For container types, the following rules apply for `x op y`:\n");
  OUTPUT("* For two (zero-depth) containers of the same `rank` and `dimensions`, `x op y` yields the element-wise operation a container of the same `rank` and `dimensions\n");
  OUTPUT("* All other cases are invalid and will produce unpredictable results or a run-time error. Debug modes will send useful error messages to the stderr.\n");




  GMD_VSPACE();
  GMD_HEADER2("Relational Operators");

  OUTPUT("For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).\n");

  CR();
  OUTPUT("| operator | operation | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `==` | equal to | ");
  OUTPUT("| `!=` | not equal to | ");
  OUTPUT("| `<` | less than | ");
  OUTPUT("| `<=` | less than or equal to | ");
  OUTPUT("| `>` | greater than | ");
  OUTPUT("| `>=` | greater than or equal to | ");
  // OUTPUT("| `<=>` | three-way comparison | ");
  CR();

  OUTPUT("**CAVEAT**: C++ allows assigment `=` inside `if` statements (eg, `if (a = true) return;`).  Mistyping the equals operator `==` can cause painful bugs. \n");

  CR();
  OUTPUT("Examples:\n");
  GMD_CODE_START("C++");
  ETV((2 == 2));
  ETV((1 / 2 == 0.5));
  ETV((1. / 2 == 0.5));
  ETV((-2 < 34.2));
  ETV((2 > 0));
  GMD_CODE_END();


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


  GMD_HEADER4("Containers");
  CR();
  GMD_CODE_START("C++");
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Nested Containers");
  CR();
  GMD_CODE_START("C++");
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Mixed Rank Math");
  CR();
  GMD_CODE_START("C++");
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Mixed depth Math");
  CR();
  GMD_CODE_START("C++");
  GMD_CODE_END();
  CR();


  GMD_VSPACE();
  return 0;
}
