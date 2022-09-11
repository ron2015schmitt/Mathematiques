#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>
#include <variant>
#include <cmath>
#include "mathq.h"

inline double fradius2(double x, double y) { return  std::sqrt(x*x + y*y); }
inline double fradius3d_2(double x, double y, double z) { return  std::sqrt(x*x + y*y + z*z); }



const double pi = 3.141592653589793238462643383;






int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;



  CR();
  CR();

  using namespace mathq::unit_quaternion;
  using namespace mathq::unit_imaginary;

  using std::sqrt;

  GMD_HEADER2("Introduction");





  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER3("Grids, Functions, and Vector Calculus");

  CR();
  CR();


  // TODO: give in terms of the size of the data
  GMD_CODE_START("C++");
  CR();

  Nabla d1;
  ETV(d1);

  // TargetSet<std::complex<double>> u(1, 0);
  // ETV(u);

  // ECHO(GridSet<double> gs);
  // ETV(gs);

  // ECHO(Interval<double> x_interval(-1, 1, 5));
  // ETV(x_interval);


  GMD_CODE_END();


  return 0;
}
