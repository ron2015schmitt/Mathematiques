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

  using namespace mathq::unit_quaternion;
  using namespace mathq::unit_imaginary;

  using std::sqrt;

  GMD_HEADER2("Introduction");

  OUTPUT("The [quaternions](https://mathworld.wolfram.com/Quaternion.html) are a non-communative [division algebra](https://en.wikipedia.org/wiki/Division_algebra).");
  OUTPUT("The quaternions are the third algebra in the sequence of [Cayley–Dickson algebras](https://en.wikipedia.org/wiki/Cayley%E2%80%93Dickson_construction), with the first two algebras being the reals and the complex numbers. ");
  OUTPUT("They were [invented by Hamilton in 1843](https://en.wikipedia.org/wiki/Quaternion), as a generalization of complex numbers.  ");
  CR();
  OUTPUT("A quaternion can be written in terms of a real number, imaginary number, and two other numbers:");
  CR();
  OUTPUT("q = a + b **i** + c **j** + d **k**");

  CR();
  OUTPUT("Multiplication of the basis elements is defined as follows.  Note that multiplication is not commutative ");
  CR();
  OUTPUT("\
| × | 1 | **i** | **j** | **k** | \n\
| :---: | :---: | :---: | :---: | :---: |");

  // first row
  OUTPUT_NOCR("| 1 |");
  OUTPUT_NOCR(1*1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1*i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1*j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1*k);
  OUTPUT_NOCR(" | ");
  CR();

  // 2nd row
  OUTPUT_NOCR("| **i** |");
  OUTPUT_NOCR(i*1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i*i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i*j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i*k);
  OUTPUT_NOCR(" | ");
  CR();

  // third row
  OUTPUT_NOCR("| **j** |");
  OUTPUT_NOCR(j*1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j*i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j*j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j*k);
  OUTPUT_NOCR(" | ");
  CR();

  // 4th row
  OUTPUT_NOCR("| **k** |");
  OUTPUT_NOCR(k*1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k*i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k*j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k*k);
  OUTPUT_NOCR(" | ");
  CR();

  CR();
  OUTPUT("The above table is referred to as the [Cayley Table](https://en.wikipedia.org/wiki/Cayley_table) for Quaternions.  Each entry is the product of the row label times the col label.");

  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER2("Size of quaternionss");

  OUTPUT("The size of a quaternions is simply _four times_ the size of the underlying arithmetic type:");

  CR();
  CR();
  GMD_CODE_START("C++");
  SRDISP(" bits", CHAR_BIT);
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(int));
  SRDISP(" bits", CHAR_BIT*sizeof(Quaternion<int>));
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(double));
  SRDISP(" bits", CHAR_BIT*sizeof(Quaternion<double>));
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(long double));
  SRDISP(" bits", CHAR_BIT*sizeof(Quaternion<long double>));
  CR();
  GMD_CODE_END();

  GMD_HEADER2("Declaration and initialization");


  OUTPUT("Declaring quaternion variables in Mathématiques");


  CR();
  CR();
  GMD_CODE_START("C++");
  ECHO_CODE(using namespace mathq);
  ECHO_CODE(using namespace mathq::unit_imaginary);
  ECHO_CODE(using namespace mathq::unit_quaternion);
  CR();
  ECHO_CODE(auto q1 = Quaternion<double>(1, 2, -1, -3));
  ECHO_CODE(auto q2 = Quaternion<double>(4, 3, -2, -5));
  ECHO_CODE(auto q = Quaternion<double>() = 16 + 2*i + 3*j + 13*k);
  ECHO_CODE(auto p = Quaternion<double>() = 0.53767 + 0.86217*i - 0.43359*j + 2.7694*k);
  GMD_CODE_END();

  MOUT << "In the above expressions we used the constants `i`, `j`, and `k`, which are defined as follows:\n";
  CR();
  GMD_CODE_START("C++");
  TRDISP(mathq::unit_imaginary::i);
  TRDISP(mathq::unit_quaternion::j);
  TRDISP(mathq::unit_quaternion::k);
  GMD_CODE_END();

  OUTPUT("Unlike the standard C++ `i`, which is an operator, the Mathématiques `i`, `j`, and `k` are constants");

  GMD_HEADER2("Arithmetic Operators");

  OUTPUT("The 4 fundamental arithmetic operators can be used with quaternions.");

  OUTPUT("Mathématiques supports the four arithmetic operators for quaternions:");
  CR();
  GMD_CODE_START("C++");
  TRDISP(q1+q2);
  TRDISP(q1-q2);
  TRDISP(q1*q2);
  TRDISP(q2/q1);
  GMD_CODE_END();


  GMD_HEADER2("Methods");

  OUTPUT("Assume `q`  is of type `Quaternion<D>` with \n");
  OUTPUT("> _q_ = _a_ + _b_ **i** + _c_ **j** + _d_ **k** \n");
  OUTPUT("The scalar+vector form of q is \n");
  OUTPUT(">  _q_ = _a_ + **v**. \n");
  OUTPUT("The polar form of q is: \n");
  OUTPUT("> _q_ = ||_q_|| ( cos _φ_ + **n\u0302** sin _φ_ ). \n");
  OUTPUT("where  \n");
  OUTPUT("> _φ_ ≐  cos<sup-1></sup>( _a_/||_q_|| ). \n");
  OUTPUT("and  \n");
  OUTPUT("> **n\u0302** ≐ **v**/||**v**||\n");
  OUTPUT("Note that for complex numbers **n\u0302** = +i or -i.  \n");


  OUTPUT("| syntax | modifies q? | description | ");
  OUTPUT("| :---: | :---: | :---: | ");
  OUTPUT("| `Quaternion<D> invert()` | yes | q := 1/q, returns `q` | ");
  OUTPUT("| `Quaternion<D> negate()` | yes | q := -q, returns `q` | ");
  OUTPUT("| `Quaternion<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | ");
  OUTPUT("| `D real()` | no | returns the real part of `q` | ");
  OUTPUT("| `D imag()` | no | returns the i-component part of `q` | ");
  OUTPUT("| `D jmag()` | no | returns the j-component part of `q` | ");
  OUTPUT("| `D kmag()` | no | returns the k-component of `q` | ");
  OUTPUT("| `D abs()` | no | returns \\|\\|_q_\\|\\|, the magnitude of `q` | ");
  OUTPUT("| `D normsqr()` | no | returns the magnitude-squared of `q` | ");
  OUTPUT("| `D scalar()` | no | same as real() | ");
  OUTPUT("| `Quaternion<D> normalized()` | no | returns _q_/\\|\\|_q_\\|\\| | ");
  OUTPUT("| `Vector<D,3> vector()` | no | returns **v**, the vector part of `q` | ");
  OUTPUT("| `Vector<D,3> unitvector()` | no | returns **n\u0302**, the vector part of `q` normalized to 1 | ");
  OUTPUT("| `D vabs()` | no | returns, _v_=\\|\\|**v**\\|\\| the magnitude of `q.vector()` | ");
  OUTPUT("| `D vnormsqr()` | no | returns \\|\\|**v**\\|\\|<sup>2</sup> | ");
  OUTPUT("| `D angle()` | no | returns φ as defined above | ");
  OUTPUT("| `std::tuple<D, D, Vector<D, 3>> polar()` | no | returns { \\|\\|_q_\\|\\|, φ, **n\u0302** } as a tuple | ");
  OUTPUT("| `Matrix<std::complex<D>, 2, 2> matrix2by2()` | no | returns **Q**, the 2x2 matrix form<sup>1</sup> of _q_ | ");

  CR();
  OUTPUT("1. **Q** = [  _a_ + **i** _b_,  _c_ + **i** _d_; ");
  OUTPUT("             -_c_ + **i** _d_,  _a_ - **i** _b_  ]");
  CR();


  OUTPUT("A few examples are shown below."); 

  CR();
  GMD_CODE_START("C++");
  TRDISP(q1);
  TRDISP(q1.real());
  TRDISP(q1.imag());
  TRDISP(q1.jmag());
  TRDISP(q1.kmag());
  TRDISP(q1.abs());
  TRDISP(q1.scalar());
  TRDISP(q1.vector());
  TRDISP(q1.vabs());
  TRDISP(q1.unitvector());
  TRDISP(q1.angle());
  TRDISP(q1.polar());
  TRDISP(q1.matrix2by2());
  GMD_CODE_END();

  // MOUT << "sizeof tuple = " << display::tuple_size_v<std::tuple<double, double, Vector<double, 3>>> << endl;

  MOUT << "typename = "  << getTypeName(q1.polar()) << endl;


  GMD_HEADER2("Functions");
  CR();
  OUTPUT("Mathématiques supports several quaternion functions.  These are listed in detail in the section on functions.");
  OUTPUT("Below are a few examples.\n");
  CR();


  CR();
  GMD_CODE_START("C++");
  TRDISP(q);
  TRDISP(exp(q));
  TRDISP(log(q));
  TRDISP(pow(q, 2));
  TRDISP(pow(q, 0.5));
  TRDISP(inv(q));
  TRDISP(conj(q));
  GMD_CODE_END();


  GMD_HEADER2("Containers of Quaternions");
  CR();
  OUTPUT("Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>` can have quaternions as their underlying type.");
  OUTPUT("Below are examples of container math with quaternions.  Mixed math is allowed.\n");
  CR();



  FormatDataVector::string_opening = "{\n";
  FormatDataVector::max_elements_per_line = 1;
  FormatDataVector::string_endofline = "\n";
  GMD_CODE_START("C++");
  ECHO_CODE(auto v = Vector<Quaternion<double>>({ 16 + 2*i + 3*j + 13*k,
                                                 5 + 11*i + 10*j + 8*k,
                                                 9 + 7*i + 6*j + 12*k,
                                                 4 + 14*i + 15*j + 1*k }));
  GMD_CODE_END();


  GMD_CODE_START("C++");
  TRDISP(q);
  CR();
  TRDISP(v);
  CR();
  TRDISP(v + q);
  CR();
  TRDISP(exp(v));
  CR();
  // TRDISP(exp(v) + v);
  // TRDISP(exp(v) + 1);
  // TRDISP(exp(v) + 2.3);
  // TRDISP(exp(v) + complex(1,2));
  // TRDISP(exp(v) + Imaginary<double>(2));
  // TRDISP(exp(v) + Quaternion<double>(1, 2, -1, -3));
  GMD_CODE_END();

  return 0;
}
