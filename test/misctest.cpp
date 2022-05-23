#define MATHQ_DEBUG 0
#include "mathq.h"
#include "test.h"


int main() {

  using namespace mathq;
  using namespace display;

  print_mathq_info();
  MOUT << CREATESTYLE(BOLD + MAGENTA1).apply(__FILE__) << " - miscellaneous tests" << std::endl;
  CR();
  CR();
  bool allpass = true;
  int testnum = 0;
  int failnum = 0;
  double tol = 5e-16;


  {
    // dimensions
    printStart(++testnum);
    Dimensions d1;
    Dimensions d2;
    bool expected = true;
    bool result = (d1 == d2);
    testtext("Dimension test 1");
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  printSummary(__FILE__, testnum, failnum);
  return failnum;
}
