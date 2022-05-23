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

  GMD_HEADER2("Introduction");

  OUTPUT("C++ supports [complex numbers](https://mathworld.wolfram.com/ComplexNumber.html) via the template class `std::complex<D>`, where D is some integer or real type. ");
  CR();
  OUTPUT("In this documentation, we denote complex number types using the symbol, ℂ.");

  OUTPUT("\n<br>\n");
  GMD_HEADER2("Size of complex numbers");

  OUTPUT("The size of a complex number is simply _twice_ the size of the underlying arithmetic type:");

  CR();
  CR();
  GMD_CODE_START("C++");
  printf("CHAR_BIT = %d bits\n", CHAR_BIT);
  CR();
  printf("CHAR_BIT*sizeof(int) = %ld bits\n", CHAR_BIT*sizeof(int));
  printf("CHAR_BIT*sizeof(complex<int>) = %ld bits\n", CHAR_BIT*sizeof(complex<int>));
  CR();
  printf("CHAR_BIT*sizeof(double) = %ld bits\n", CHAR_BIT*sizeof(double));
  printf("CHAR_BIT*sizeof(complex<double>) = %ld bits\n", CHAR_BIT*sizeof(complex<double>));
  CR();
  printf("CHAR_BIT*sizeof(long double) = %ld bits\n", CHAR_BIT*sizeof(long double));
  printf("CHAR_BIT*sizeof(complex<long double>) = %ld bits\n", CHAR_BIT*sizeof(complex<long double>));
  CR();
  GMD_CODE_END();


  GMD_HEADER2("Declaration and initialization");


  OUTPUT("Complex numbers can be declared and initialized in a variety of ways.");

  CR();
  CR();
  GMD_CODE_START("C++");
  OUTPUT("#include <complex>;");
  OUTPUT("#include <cmath>;");
  OUTPUT("...");
  ECHO_CODE(using namespace std);
  ECHO_CODE(using namespace std::complex_literals);
  CR();
  ECHO_CODE(complex<double> c1);
  ECHO_CODE(complex<double> c2 = complex<double>(2, -3.5));
  ECHO_CODE(complex<double> c3(1, 2.3));
  ECHO_CODE(complex<double> c4 = 1.4 + 3.5i);
  ECHO_CODE(auto c5 = complex<double>(1.3, -10.5));
  CR();
  TRDISP(c1);
  TRDISP(c2);
  TRDISP(c3);
  TRDISP(c4);
  TRDISP(c5);
  GMD_CODE_END();

  OUTPUT("In the above expression `c4 = 1.4 + 3.5i`, the C++ operator `std::complex_literals::i` is used. ");
  OUTPUT("This operator can only be used after a number and there can NOT be a space between the number and `i`.  ");
  OUTPUT("The operator `i` is a `double`, while `if` and `il` are a `float` and a `long double` respectively.");
  CR();


  GMD_HEADER2("Arithmetic");


  OUTPUT("The 4 fundamental arithmetic operators can be used with complex numbers.");
  GMD_CODE_START("C++");
  CR();
  TRDISP(1.4 + 3.5i  +  2.6 + 1.5i);
  TRDISP(complex<double>(1.3, -10.5) - complex<double>(1.3, -10.5));
  TRDISP(2 + 4.5i  *  2 + 3i);
  TRDISP(2 + 4.5i / 2 + 3i);
  CR();
  GMD_CODE_END();

  GMD_HEADER2("Methods");

  OUTPUT("Assume `z`  is of type `std::complex<D>` with \n");


  OUTPUT("| syntax | modifies q? | description | ");
  OUTPUT("| :---: | :---: | :---: | ");
  OUTPUT("| `D real()` | no | returns the real part of `z`, ie zero | ");
  OUTPUT("| `D imag()` | no | returns the i-component part of `z` | ");


  OUTPUT("A few examples are shown below.");

  CR();
  GMD_CODE_START("C++");
  {
    ECHO_CODE(complex<double> z = 1.5 + 3.5i);
    TRDISP(z);
    TRDISP(z.real());
    TRDISP(z.imag());
  }
  GMD_CODE_END();



  GMD_HEADER2("Math with mixed types");

  OUTPUT("Mathématiques extends the C++ functionality so that mixed math (ints, floating pt, complex<int>, complex<floating pt>) is possible.");
  GMD_CODE_START("C++");
  CR();
  TRDISP(1 + 10i);
  TRDISP(complex<double>(1.3, -10.5) - complex<int>(1, 3));
  TRDISP(complex<double>(1.3, -10.5) - complex<float>(1.2, 5));
  TRDISP(5 + complex<double>(1.3, -10.5));
  TRDISP(int(100) + complex<double>(1.3, -10.5));
  TRDISP(float(100) + complex<double>(1.3, -10.5));
  CR();
  GMD_CODE_END();

  OUTPUT("**Without Mathématiques, all of the above expressions will fail to compile!**\n");

  OUTPUT("Let `OP` be `+`, `-`, `*`, or `/`.\n");
  OUTPUT("1. `complex<D1> OP complex<D2>` will fail to compile without Mathématiques unless D1==D2\n");
  OUTPUT("1. `complex<D1> OP D2` will fail to compile without Mathématiques unless D1==D2\n");
  CR();
  OUTPUT("The philosophy behind Mathématiques is that the user would rather be concerned with math and algorithms than overly-rigid syntax.\n");

  CR();

  GMD_HEADER2("Functions");
  CR();
  OUTPUT("Many functions also work on complex numbers.  These are listed in detail in the section on functions.");
  OUTPUT("Below are a few examples.\n");
  CR();

  GMD_CODE_START("C++");
  CR();
  TRDISP(sin(1.4 + 3.5i));
  TRDISP(exp((3.1415/2)*1i));
  TRDISP(pow(1.5 + 3i, 0.5));
  CR();
  GMD_CODE_END();


  GMD_HEADER2("Containers of std::complex numbers");
  CR();
  OUTPUT("Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>`) can have complex numbers as their underlying type.");
  OUTPUT("Below are examples of container math with complex numbers.  Mixed math is allowed.\n");
  CR();



  GMD_CODE_START("C++");
  {
    ECHO_CODE(using namespace std);
    ECHO_CODE(using namespace std::complex_literals);
    CR();
    ECHO_CODE(complex<double> z = 1.5 + 3.5i);
    ECHO_CODE(Vector<complex<double>> v = Vector<complex<double>>({ 1, 1i, 1 + 1i, 1 - 1i }));
    CR();
    TRDISP(z);
    TRDISP(v);
    CR();
    TRDISP(v + z);
    TRDISP(v*1i);
    TRDISP(exp(v));
    TRDISP(exp(v) + 1);
    TRDISP(exp(v) + complex(1, 2));
    TRDISP(exp(v) + v);
    TRDISP(exp(v)/v + v);
  }
  GMD_CODE_END();

  return 0;
}
