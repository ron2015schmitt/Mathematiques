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

  GMD_HEADER2("Pretty Printing");
  OUTPUT("Mathématiques supports the follow number systems:");

  {  GMD_CODE_START("C++");
  ECHO(bool q = (5 > 3));
  ETV(q);
  ETV(!q);
  CR();
  ETV(true || false);
  ETV(true && false);
  CR();
  ETV(true + 9);
  GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER2("Debugging Modes");
  OUTPUT("Mathématiques supports mixed math and automatically promotes numbers as needed");

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


  return 0;
}
