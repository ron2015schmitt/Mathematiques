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

  OUTPUT("Mathématiques supports vectors, matrices and arbitrary rank multi-arrays.   These containers can be nested any number of levels.");


  GMD_HEADER2("Vectors");
  OUTPUT("Vectors can be fixed length, with length determined at compile-time, or dynamic length.");

  GMD_HEADER3("Fixed-length Vectors");
  {
    GMD_CODE_START("C++");
    ECHO(Vector<double, 3> v{ 1,2,3 });
    CR();
    TRDISP(v);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER3("Dynamic-length Vectors");
  {
    GMD_CODE_START("C++");
    ECHO(Vector<double> v{ 1,2,3,4,5 });
    CR();
    TRDISP(v);
    ECHO(v = 100*v);
    TRDISP(v);
    ECHO(v.resize(10));
    TRDISP(v);
    ECHO(v = linspace<double>(0, 1, 10));
    TRDISP(v);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER3("Element access");
  {
    GMD_CODE_START("C++");
    ECHO(Vector<double, 3> v{ 1,2,3 });
    CR();
    TRDISP(v[0]);
    TRDISP(v[1]);
    TRDISP(v[2]);
    ECHO(v[0] = 200);
    TRDISP(v);
    ECHO(v[2] = v[1] = v[0]);
    TRDISP(v);
    GMD_CODE_END();
  }
  GMD_VSPACE();


  GMD_HEADER2("Vectors");
  OUTPUT("Vectors can be fixed length, with length determined at compile-time, or dynamic length.");

  GMD_HEADER3("Fixed-length Vectors");
  {
    GMD_CODE_START("C++");
    ECHO(Vector<double, 3> v{ 1,2,3 });
    CR();
    TRDISP(v);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER3("Dynamic-length Vectors");
  {
    GMD_CODE_START("C++");
    ECHO(Vector<double> v{ 1,2,3,4,5 });
    CR();
    TRDISP(v);
    ECHO(v = 100*v);
    TRDISP(v);
    ECHO(v.resize(10));
    TRDISP(v);
    ECHO(v = linspace<double>(0, 1, 10));
    TRDISP(v);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER3("Element access");
  {
    GMD_CODE_START("C++");
    ECHO(Vector<double, 3> v{ 1,2,3 });
    CR();
    TRDISP(v[0]);
    TRDISP(v[1]);
    TRDISP(v[2]);
    ECHO(v[0] = 200);
    TRDISP(v);
    ECHO(v[2] = v[1] = v[0]);
    TRDISP(v);
    GMD_CODE_END();
  }
  GMD_VSPACE();


  return 0;
}
