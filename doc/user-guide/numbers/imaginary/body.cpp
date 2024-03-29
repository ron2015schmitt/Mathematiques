#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  using namespace mathq::unit_imaginary;

  using std::sqrt;

  GMD_HEADER2("Introduction");

  OUTPUT("The [imaginary numbers](https://mathworld.wolfram.com/Imaginary.html) are a non-communative [division algebra](https://en.wikipedia.org/wiki/Division_algebra).");


  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER2("Size of imaginary numbers");

  OUTPUT("The size of a imaginary numbers is the same size of the underlying arithmetic type:");

  CR();
  CR();
  GMD_CODE_START("C++");
  SRDISP(" bits", CHAR_BIT);
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(int));
  SRDISP(" bits", CHAR_BIT*sizeof(Imaginary<int>));
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(double));
  SRDISP(" bits", CHAR_BIT*sizeof(Imaginary<double>));
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(long double));
  SRDISP(" bits", CHAR_BIT*sizeof(Imaginary<long double>));
  CR();
  GMD_CODE_END();

  GMD_HEADER2("Declaration and initialization");


  OUTPUT("Declaring quaternion variables in Mathématiques");


  CR();
  CR();
  GMD_CODE_START("C++");
  ECHO(using namespace mathq);
  ECHO(using namespace mathq::unit_imaginary);
  CR();
  ECHO(Imaginary<double> q1 = Imaginary<double>(2.5));
  ECHO(auto q2 = Imaginary<double>() = 2*i);
  ECHO(auto q = Imaginary<double>() = -i/0.25);
  CR();
  ETV(q1);
  ETV(q2);
  ETV(q);
  GMD_CODE_END();

  MOUT << "In the above expressions we used the constant `i` which is defined as follows:\n";
  CR();
  GMD_CODE_START("C++");
  ETV(mathq::unit_imaginary::i);
  GMD_CODE_END();

  OUTPUT("Unlike the standard C++ `i`, which is an operator, the Mathématiques `i`, `j`, and `k` are constants");

  GMD_HEADER2("Arithmetic");

  OUTPUT("The 4 fundamental arithmetic operators can be used with imaginary numbers.");

  OUTPUT("Mathématiques supports the four arithmetic operators for imaginary numbers:");
  CR();
  GMD_CODE_START("C++");
  ETV(q1+q2);
  ETV(q1-q2);
  ETV(q1*q2);
  ETV(q2/q1);
  GMD_CODE_END();


  GMD_HEADER2("Methods");

  OUTPUT("Assume `q`  is of type `Imaginary<D>` with \n");


  OUTPUT("| syntax | modifies q? | description | ");
  OUTPUT("| :---: | :---: | :---: | ");
  OUTPUT("| `Imaginary<D> invert()` | yes | q := 1/q, returns `q` | ");
  OUTPUT("| `Imaginary<D> negate()` | yes | q := -q, returns `q` | ");
  OUTPUT("| `Imaginary<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | ");
  OUTPUT("| `D real()` | no | returns the real part of `q`, ie zero | ");
  OUTPUT("| `D imag()` | no | returns the i-component part of `q` | ");
  OUTPUT("| `D value()` | no | returns the i-component part of `q` | ");
  OUTPUT("| `D abs()` | no | returns \\|_q_\\|, the magnitude of `q` | ");
  OUTPUT("| `D normsqr()` | no | returns the magnitude-squared of `q` | ");


  OUTPUT("A few examples are shown below.");

  CR();
  GMD_CODE_START("C++");
  ETV(q1);
  ETV(q1.real());
  ETV(q1.imag());
  ETV(q1.value());
  ETV(q1.abs());
  ETV(q1.normsqr());
  GMD_CODE_END();



  GMD_HEADER2("Operators & Functions");
  CR();
  OUTPUT("C++ supports many functions and Mathématiques provides several more.  These are listed in detail in the sections on opetators and functions.  C++ supports mixed type arithmetic between all the real types.");
  OUTPUT("Below are a few examples.\n");
  CR();


  CR();
  GMD_CODE_START("C++");
  ECHO(double pi = 3.14159265358979311599796346854);
  ETV(2*i*i);
  ETV(20*i*i/(4*i));
  ETV(2*i*i + 3);
  ETV(i/i + i/5 +4*i + 4);
  ETV(1 + i);
  ETV(20 + i/0.25);
  ETV(10*exp(i*pi/4));
  ETV(10*cos(pi/4) + 10*i*sin(pi/4));
  ETV(exp(1+i*pi/4)/2.71828);
  CR();
  ETV(q);
  ETV(pow(q, 7));
  GMD_CODE_END();

  GMD_HEADER2("Containers of Imaginary numbers");
  CR();
  OUTPUT("Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `MultiArray<D>` can have imaginary numbers as their underlying type.");
  OUTPUT("Below are examples of container math with imaginary numbers.  Mixed math is allowed.\n");
  CR();



  GMD_CODE_START("C++");
  ECHO(auto v = Vector<Imaginary<double>>({ i, i, -i, i }));
  GMD_CODE_END();


  GMD_CODE_START("C++");
  ETV(q);
  CR();
  ETV(v);
  CR();
  ETV(v + q);
  CR();
  ETV(exp(v));
  CR();
  ETV(exp(v) + v);
  ETV(exp(v) + 1);
  ETV(exp(v) + 2.3);
  ETV(exp(v) + complex(1, 2));
  ETV(2*exp(v) + Imaginary<double>(2));
  // ETV(exp(v)*Imaginary<double>(1));  // bug?
//  auto y = exp(v)*Imaginary<double>(1);  // yes, this also fails
  // ETV(exp(v)*4);  // works
  // ETV(v*i);  // fails

  GMD_CODE_END();


  return 0;
}
