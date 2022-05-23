


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
  GMD_TITLE("Vector functions that return a scalar (dot product, sum, min, max etc)");
  mathq_preamble();

  GMD_HEADER3("dot product—the `|` operator");
  OUTPUT("* The dot product is accomplished via the `|` operator, such that the dot product takes a form similar to P.A.M. Dirac's 'bra-ket' notation.");
  OUTPUT("* This definition becomes very useful for taking the product of matrices because any number of matrices can be multiplied in a single line of code.");
  
  {
    CR();
    CR();
    EXAMPLE(Nex++,"Dot product of two real vectors `(v1|v2)`");
    GMD_CODE_START("C++");
    ECHO_CODE(Vector<double> v1(range<double>(1,4)));
    codemultiNoteC11Array(Vector<double> v2({1,-1,1,-1}));
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti( (v1|v1) );
    resultmulti( (v2|v2) );
    resultmulti( (v1|v2) );
    resultmulti( (v2|v1) );
    resultmulti( (v1|(2*v2+1)) );
    resultend();
  }


    {
    CR();
    CR();
    EXAMPLE(Nex++,"Dot product of two complex vectors `(~v1|v2)=(conj(v1)|v2)`");
    CR();
    OUTPUT("The complex dot product is defined such that the first vector conjugated.  In this manner, the dot product of a complex vector with itself produces a real number.");
    GMD_CODE_START("C++");
    ECHO_CODE(using namespace std);
    ECHO_CODE(const double tol = 2e-16);
    ECHO_CODE(Vector<complex<double> > v1);
    ECHO_CODE(v1 = Complex(range<double>(1,2), 0.));
    ECHO_CODE(v1.roundzero(tol));
    ECHO_CODE(Vector<complex<double> > v2);
    ECHO_CODE(v2 = Complex(range<double>(-1,-2), range<double>(2,3)));
    ECHO_CODE(v2.roundzero(tol));
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti( v1 );
    resultmulti( v2 );
    resultmulti( (~v1|v1) );
    resultmulti( (~v2|v2) );
    resultmulti( (~v1|v2) );
    resultmulti( (~v2|v1) );
    resultmulti( (~v1|(2*v2+1)) );
    resultend();
  }


  {
    CR();
    CR();
    EXAMPLE(Nex++,"`sum` the elements of a vector");
    GMD_CODE_START("C++");
    ECHO_CODE_W_COMMENT("C++11 list initialization", Vector<double> v({1,2,3,4}));
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti( sum(v) );
    resultmulti( sum(2*exp(v)+1) );
    resultend();
  }


    {
    CR();
    CR();
    EXAMPLE(Nex++,"`sum` the elements of a vector");
    GMD_CODE_START("C++");
    ECHO_CODE_W_COMMENT("C++11 list initialization", Vector<double> v({1,2,3,4}));
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti( sum(v) );
    resultmulti( sum(2*exp(v)+1) );
    resultend();
  }


  {
    CR();
    CR();
    EXAMPLE(Nex++,"`integrate_a2b` a vector over the interval [a,b]");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v );
    ECHO_CODE( v = exp(linspace<double>(-1,1,13)));
    GMD_CODE_END();
    CR();
   
    resultstart2(" precise value to 16 digits is 2.35040238729 (via Mathematica)");
    resultmulti( integrate_a2b(v,-1.,1.) );
    resultmulti( integrate_a2b(v,-1.,1.,2) );
    resultmulti( integrate_a2b(v,-1.,1.,3) );
    resultmulti( integrate_a2b(v,-1.,1.,4) );
    resultend();
  }

  
  {
    CR();
    CR();
    EXAMPLE(Nex++,"Compute the _product_ of the elements of a vector");
    GMD_CODE_START("C++");
    ECHO_CODE_W_COMMENT("C++11 list initialization", Vector<double> v({1,2,3,4}));
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti( prod(v) );
    resultmulti( prod(2*exp(v)+1) );
    resultend();
  }



    {
    CR();
    CR();
    EXAMPLE(Nex++,"Find the _minimum_ of the elements of a vector");
    GMD_CODE_START("C++");
    ECHO_CODE_W_COMMENT("C++11 list initialization", Vector<double> v({1,20,-1,0}));
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti( v );
    resultmulti( min(v) );
    resultmulti( 2*exp(v)+1 );
    resultmulti( min(2*exp(v)+1) );
    resultend();
  }


      {
    CR();
    CR();
    EXAMPLE(Nex++,"Find the _maximum_ of the elements of a vector");
    GMD_CODE_START("C++");
    ECHO_CODE_W_COMMENT("C++11 list initialization", Vector<double> v({1,20,-1,0}));
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti( v );
    resultmulti( max(v) );
    resultmulti( 2*exp(v)+1 );
    resultmulti( max(2*exp(v)+1) );
    resultend();
  }

  
  mathq_toc();
  return 0;
}
