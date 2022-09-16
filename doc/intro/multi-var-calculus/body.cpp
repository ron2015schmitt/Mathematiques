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

  OUTPUT("Mathématiques supports ");


  GMD_VSPACE();
  GMD_HEADER2("Vectors");
  OUTPUT("Vectors can be fixed length, with length determined at compile-time, or dynamic length.  Fixed-length vectors allow for better optimzation by the compiler.");

  GMD_HEADER3("Fixed-length Vectors");
  {
    GMD_CODE_START("C++");
    GMD_CODE_END();
  }

  {
    OUTPUT("3D curl of a CurvilinearField - ex1: output is curlA = {0,1,0}");

    using namespace cross_product;
    CartesianCoords<double, 3, false> coords({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
      });
    ETV(coords);
    ECHO(CurvilinearField<double, 1, CartesianCoords<double, 3, false>> A(coords));
    A = 0.;
    ECHO(A[0] = coords.z());
    ECHO(auto B = curl(A));
    ETV(B);
    // OUTPUT("=========================");
    // Nabla<> nabla;
    // ECHO(B = nabla ^ A);
    // OUTPUT("=========================");
  }

  GMD_VSPACE();
  return 0;
}
