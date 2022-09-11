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


  return 0;
}
