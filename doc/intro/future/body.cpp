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
  TRDISP(q);
  TRDISP(!q);
  CR();
  TRDISP(true || false);
  TRDISP(true && false);
  CR();
  TRDISP(true + 9);
  GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER2("Debugging Modes");
  OUTPUT("Mathématiques supports mixed math and automatically promotes numbers as needed");

  {
    GMD_CODE_START("C++");
    ECHO(unsigned int n = 23);
    TRDISP(n);
    TRDISP(n + 102 - 2*4);
    TRDISP(n - 24);
    TRDISP(n/2);
    TRDISP(n % 2);
    GMD_CODE_END();
  }
  GMD_VSPACE();


  return 0;
}
