


#include "mathq.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>




int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  int Nex = 1;
  
  mathq_toc();
  CR();CR();
  GMD_TITLE("Element-wise Vector math");
  mathq_preamble();

  GMD_HEADER3("Element-wise arithmetic");
  OUTPUT("The operators +,-,*,/ perform element-wise addition, subtraction, multiplication, and division respectively");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"Element-wise `Vector` math");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v1(4) );
    codemultiNoteC11Array(v1 = {10,20,30,40});
    ECHO_CODE( Vector<double> v2(4) );
    codemultiNoteC11Array(v2 = {1,2,3,4});
    GMD_CODE_END();
    CR();
    DISP(v1);
    DISP(v1+v2);
    //(cout << "here")<<std::end;
    DISP(v1);
   
    resultstart2("");
    resultmulti(v1 + v2);
    resultmulti(v1 - v2);
    resultmulti(v1 * v2);
    resultmulti(v1 / v2);
    resultend();
  }


  GMD_HEADER3("Vector-scalar arithmetic");
  OUTPUT("* The binary operators +,-,*,/ can each be used to pair a scalar and a `Vector`.");
  OUTPUT("* In this case the scalar is operated on each element of the vector");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"math with scalars and `Vector`s");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v1(4) );
    codemultiNoteC11Array(v1 = {10,20,30,40});
    GMD_CODE_END();
    CR();

    resultstart2("");
    resultmulti(v1 + 1);
    resultmulti(1 + v1);
    resultmulti(v1 - 10);
    resultmulti(40 - v1);
    resultmulti(v1 * 2);
    resultmulti(2 * v1);
    resultmulti(v1 / 10);
    resultmulti(120 / v1);
    resultmulti(1 + 120 / v1 - 8/8 + 5*v1*2);
    resultend();
  }


  GMD_HEADER3("Vector math functions");
  OUTPUT("* A large number of functions is supported.  ");
  OUTPUT("* A function of a `Vector` operates on each element.  ");
  
  {
    CR();
    CR();
    EXAMPLE(Nex++,"functions of a `Vector`—rounding and sign-related ");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v(7) );
    codemultiNoteC11Array(v = {-2.5,-2.25,-1,0,1,2.25,2.5});
    GMD_CODE_END();
    CR();

    resultstart2(": rounding and sign-related");
    resultmulti( floor(v)  );
    resultmulti( ceil(v)  );
    resultmulti( round(v)  );
    resultmulti( sgn(v)  );
    resultmulti( abs(v)  );
    resultend();
    CR();
  }
    
  {
    CR();
    CR();
    EXAMPLE(Nex++,"functions of a `Vector`—powers, roots, and exponentiation");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v(5) );
    codemultiNoteC11Array(v = {-1,0,1,2,4});
    GMD_CODE_END();
    CR();
    resultstart2(": powers, roots, and exponentiation");
    resultmulti( pow(2, v)  );
    resultmulti( pow(v, 2)  );
    resultmulti( pow(v,v)  );
    resultmulti( exp(v)  );
    resultmulti( log(v)  );
    resultmulti( log10(v)  );
    resultmulti( log2(v)  );
    resultmulti( sqr(v)  );
    resultmulti( cube(v)  );
    resultmulti( sqrt(v)  );
    resultend();
    CR();
  }


  {
    CR();
    CR();

    EXAMPLE(Nex++,"functions of a `Vector`—trig");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v(5) );
    ECHO_CODE_W_COMMENT("C++11 constexpr",constexpr double pi = std::acos(-1) );
    codemultiNoteC11Array(v = {-pi, -pi/2, 0, pi/2, pi});
    ECHO_CODE( const double tol = 2e-16 );
    GMD_CODE_END();
    CR();

    resultstart2(": trig");
    resultmulti( sin(v)  );
    resultmulti( cos(v)  );
    resultmulti( tan(v)  );
    resultend();
    CR();
    OUTPUT("The results are cleaner, when we round to a tolerance");
    CR();
    resultstart2(": trig with rounded zeros");
    resultmulti( roundzero(sin(v),tol)  );
    resultmulti( roundzero(cos(v),tol)  );
    resultmulti( roundzero(tan(v),tol)  );
    resultend();
    
  }

  
  {
    CR();
    CR();
    EXAMPLE(Nex++,"functions of a `Vector`—rounding and sign-related ");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v(3) );
    codemultiNoteC11Array(v = {-1,0,1});
    GMD_CODE_END();
    CR();

    resultstart2(": hyperbolic trig");
    resultmulti( sinh(v)  );
    resultmulti( cosh(v)  );
    resultmulti( tanh(v)  );
    resultend();
    CR();
  }


  {
    CR();
    CR();
    EXAMPLE(Nex++,"functions of a `Vector`—inverse trig");
    GMD_CODE_START("C++");
    ECHO_CODE( double pi = std::acos(-1) );
    ECHO_CODE( Vector<double> v(3) );
    ECHO_CODE( Vector<double> v1(9) );
    ECHO_CODE( Vector<double> v2(9) );
    codemultiNoteC11Array(v = {-1,0,1});
    codemultiNoteC11Array(v1 = {-1,-1,-1, 0, 0, 0, 1, 1, 1});
    codemultiNoteC11Array(v2 = {-1, 0, 1,-1, 0, 1,-1, 0, 1});
    GMD_CODE_END();
    CR();

    resultstart2(": inverse trig");
    resultmulti( asin(v)/pi  );
    resultmulti( acos(v)/pi  );
    resultmulti( atan(v)/pi  );
    resultmulti( atan2(v1, v2)/pi  );
    resultend();
  }



  GMD_HEADER3("Arbitrary combinations of the above functionality are supported");
  OUTPUT("* Because Mathématiques uses expression templating:");
  OUTPUT("  * no intermediate objects are created");
  OUTPUT("  * the expression is calculated in a single for loop");


    {
    CR();
    CR();
    EXAMPLE(Nex++,"A huge expression");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v1(4) );
    codemultiNoteC11Array(v1 = {10,20,30,40});
    ECHO_CODE( Vector<double> v2(4) );
    codemultiNoteC11Array(v2 = {-1,-2,-3,-4});
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti(2*log10(abs(v1/v2)*100) + 3 + pow(-v2,2) );
    resultend();
  }

  mathq_toc();


  return 0;
}
