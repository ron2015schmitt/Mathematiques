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

  GMD_HEADER2("Number Systems Currently Supported");

  OUTPUT("Mathématiques supports the follow number systems:");
  OUTPUT("* Boolean numbers");
  OUTPUT("* signed and unsigned integers");
  OUTPUT("* real numbers, as approximated by floating point values");
  OUTPUT("* pure imaginary numbers, which saves memory for imaginary matrices");
  OUTPUT("* complex numbers");
  OUTPUT("* quaternions");

  GMD_HEADER2("Examples");
  OUTPUT("Mathématiques supports mixed math and automatically promotes numbers as needed");


  GMD_HEADER3("Boolean");
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

  GMD_HEADER3("Unsigned integers");
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

  GMD_HEADER3("Signed integers");
  {
    GMD_CODE_START("C++");
    ECHO(int n = 23);
    TRDISP(n);
    TRDISP(n + 102 - 2*4);
    TRDISP(n - 24);
    TRDISP(n/2);
    CR();
    TRDISP(2 + 4/2);
    TRDISP(2 + 0.5);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER3("Floating point (reals)");
  {
    GMD_CODE_START("C++");
    ECHO(double x = 23);
    TRDISP(x);
    TRDISP(4.5*x + 35/(2+3));
    CR();
    TRDISP(25.);
    TRDISP(2. + 4/2);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER3("Imaginary");
  {
    GMD_CODE_START("C++");
    ECHO(Imaginary<double> y{ 4 });
    TRDISP(y);
    CR();
    ECHO(double x{ 3 });
    TRDISP(x);
    TRDISP(x + y);
    CR();
    ECHO(using namespace mathq::unit_imaginary);
    TRDISP(3 + 4*i);
    GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER3("Complex");
  {
    GMD_CODE_START("C++");
    ECHO(using std::complex);
    ECHO(complex<double> z(10, -20));
    TRDISP(z);
    TRDISP(abs(z));
    CR();
    TRDISP(z/complex(1, 2));
    CR();
    ECHO(using namespace mathq::unit_imaginary);
    TRDISP(z/(1 + i*2));
    GMD_CODE_END();
  }
  GMD_VSPACE();

  GMD_HEADER3("Quaternion");
  {
    GMD_CODE_START("C++");
    ECHO(auto q1 = Quaternion<double>(1, 2, -1, -3));
    ECHO(auto q2 = Quaternion<double>(4, 3, -2, -5));
    TRDISP(q1);
    TRDISP(q2);
    TRDISP(q1+q2);
    TRDISP(q1-q2);
    TRDISP(q1*q2);
    TRDISP(q2/q1);

    CR();
    ECHO(using namespace mathq::unit_imaginary);
    ECHO(using namespace mathq::unit_quaternion);
    ECHO(auto q = Quaternion<double>() = 16 + 2*i + 3*j + 13*k);
    ECHO(auto p = Quaternion<double>() = 0.53767 + 0.86217*i - 0.43359*j + 2.7694*k);
    TRDISP(q);
    TRDISP(p);

    CR();
    ECHO(double x{ 3 });
    TRDISP(x);
    ECHO(Imaginary<double> y{ 4 });
    TRDISP(y);
    ECHO(std::complex<double> z(1, 2));
    TRDISP(x + y + z + 5*j);

    GMD_CODE_END();
  }
  GMD_VSPACE();

  return 0;
}
