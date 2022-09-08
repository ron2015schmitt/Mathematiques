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

  OUTPUT("Mathématiques supports vectors, matrices and arbitrary rank multi-arrays.");


  GMD_VSPACE();
  GMD_HEADER2("Vectors");
  OUTPUT("Vectors can be fixed length, with length determined at compile-time, or dynamic length.  Fixed-length vectors allow for better optimzation by the compiler.");

  GMD_HEADER3("Fixed-length Vectors");
  {
    GMD_CODE_START("C++");
    ECHO(Vector<double, 3> v{ 1,2,3 });
    CR();
    TRDISP(v);
    GMD_CODE_END();
  }

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
  GMD_HEADER2("Matrices");
  OUTPUT("Matrices can be fixed dimensions, with dimensions determined at compile-time, or dynamic dimensions.");

  GMD_HEADER3("Fixed-dimensions Matrices");
  {
    GMD_CODE_START("C++");
    ECHO(Matrix<double, 2, 2> A{ {1,2}, {3,4} });
    CR();
    TRDISP(A);
    GMD_CODE_END();
  }

  GMD_HEADER3("Dynamic-dimensions Matrices");
  {
    GMD_CODE_START("C++");
    ECHO(Matrix<double> A{ {1,2}, {3,4}, {5,6} });
    CR();
    TRDISP(A);
    GMD_CODE_END();
  }

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
  GMD_HEADER2("General MultiArrays");
  OUTPUT("MultiArrays can be created of arbitrary rank via the syntax `MultiArray<double,[rank]]>`, where `[rank]` is a whole number.");
  OUTPUT("In fact a `Vector` is simply an alias for a `MultiArray` of rank 1. ");
  OUTPUT("A `Matrix` is simply an alias for a `MultiArray` of rank 2.  ");
  OUTPUT("Multiarrays are sometimes referred to as tensors.  To be accurate, multiarrays are Cartesian algebraic tensors.  General tensors are also supported by Mathématiques, but described later in this introduction.");

  GMD_VSPACE();
  return 0;
}
