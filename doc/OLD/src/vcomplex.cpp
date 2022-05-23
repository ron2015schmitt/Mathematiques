


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
  GMD_TITLE("Complex-valued Vectors");
  mathq_preamble();

  GMD_HEADER3("Representing the unit imaginary _i_");

  OUTPUT("* In C++, there is no definition for pure imaginary numbers.");
  OUTPUT("* This is in contrast to Fortran.");
  OUTPUT("* The unit imaginary is thus `complex<D>(0,1`");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"The unit imaginary _i_ in C++14");
    CR();
    OUTPUT("* In C++14, the unit imaginary is defined by the product operator `operator\"\"i`");
#if CPP14 == 1
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( using namespace literals );
    ECHO_CODE( using namespace complex_literals );
    ECHO_CODE(complex<double> z1 = 1i );
    ECHO_CODE(complex<double> z2 = 1+1i );
    ECHO_CODE(complex<double> z3 = -5i );
    ECHO_CODE(complex<double> z4 = 5 );
    GMD_CODE_END();
    resultstart2("");
    resultmulti(z1);
    resultmulti(z2);
    resultmulti(~z2);
    resultmulti(z3);
    resultmulti(z4);
    resultend();
  }
#endif
    
  {
    CR();
    CR();
    EXAMPLE(Nex++,"The unit imaginary _i_ (works in any version)");
    CR(); 
    OUTPUT("In earlier versions of C++, the unit imaginary can be defined by");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( const complex<double> i = complex<double>(0,1) );
    ECHO_CODE(complex<double> z1 = 1.*i );
    ECHO_CODE(complex<double> z2 = 1. + 1.*i );
    ECHO_CODE(complex<double> z3 = -5.*i );
    ECHO_CODE(complex<double> z4 = 5 );
    GMD_CODE_END();
    CR();
    resultstart2("");
    resultmulti(z1);
    resultmulti(z2);
    resultmulti(z3);
    resultmulti(z4);
    resultend();

  }



  GMD_HEADER3("Declaring a complex-valued `Vector`");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"Complex  `Vector` ");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( Vector<complex<double> > v(4) );
#if CPP14 == 1
    ECHO_CODE( using namespace literals );
    ECHO_CODE( using namespace complex_literals );
    ECHO_CODE_W_COMMENT("C++11 list and C++14 literal `i` for unit imaginary ", v = { 1+1i, 1, 1i, 1-1i } );
#else
#endif
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti(v);
    resultend();
  }



  GMD_HEADER3("Arithmetic with complex-valued `Vector`'s");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"Complex `Vector` arithmetic");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( Vector<complex<double> > v1(4) );
    ECHO_CODE( Vector<complex<double> > v2(4) );
#if CPP14 == 1
    ECHO_CODE( using namespace literals );
    ECHO_CODE( using namespace complex_literals );
    ECHO_CODE_W_COMMENT("C++11 list and C++14 literal `i` for unit imaginary ", v1 = { -1i, 0, 1-1i, 1+1i } );
    ECHO_CODE_W_COMMENT("C++11 list and C++14 literal `i` for unit imaginary ", v2 = { 1+1i, 1, 1i, -1i } );
#else
#endif
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti(v1+v2);
    resultmulti(v1-v2);
    resultmulti(v1*v2);
    resultmulti(v1/v2);
    resultend();
  }


  GMD_HEADER3("Mixed arithmetic with complex and real vectors and scalars `Vector`'s");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"Mixed real and complex arithmetic ");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( Vector<double > vr(4) );
    ECHO_CODE( Vector<complex<double> > vc(4) );
#if CPP14 == 1
    ECHO_CODE( using namespace literals );
    ECHO_CODE( using namespace complex_literals );
    ECHO_CODE_W_COMMENT("C++11 list ", vr = { 1, 2, 3, 4 } );
    ECHO_CODE_W_COMMENT("C++11 list and C++14 literal `i` for unit imaginary ", vc = { 1+1i, 1, 1i, -1i } );
#endif
    GMD_CODE_END();
    CR();

   
    resultstart2("");
    resultmulti(vr+vc);
    resultmulti(vr-vc);
    resultmulti(vr*vc);
    resultmulti(vr/vc);
    resultmulti(2.*vr + vc/2. + 1);
    // C++14 complex objects are of class "__complex__ double" 
    //    resultmulti( (1.i)*vr + (5.+2.i)*vc);  // C++14
    resultmulti( complex<double>(0,1)*vr + complex<double>(5,2)*vc);
    resultend();
  }


  GMD_HEADER3("real and imag parts of `Vector`'s");


  {
    CR();
    CR();
    EXAMPLE(Nex++,"get the real and imaginary part of a complex vector");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( Vector<complex<double> > v(4) );
#if CPP14 == 1
    ECHO_CODE_W_COMMENT("C++11 list and C++14 imag", v = {1+1.i, 1., 1.i, 2-5.i});
#else
    ECHO_CODE( v = (const complex<double>[]) {complex<double>(1,1), complex<double>(1,0), complex<double>(0,1), complex<double>(2,-5)} );
#endif
    GMD_CODE_END();
    CR();

    resultstart2(": real and imaginary parts");
    resultmulti( v  );
    resultmulti( real(v)  );
    resultmulti( imag(v)  );
    resultend();
    CR();
  }


  GMD_HEADER3("creating complex Vectors from real vectors and scalars");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"create a complex vector from two real vectors");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( Vector<complex<double> > vc(4) );
    ECHO_CODE( Vector<double> vr( range<double>(1,4) ));
    ECHO_CODE( Vector<double> vi( range<double>(-1,-4) ));
    ECHO_CODE( vc = Complex(vr, vi) );
    GMD_CODE_END();
    CR();

    resultstart2(": create a complex vector from two real vectors");
    resultmulti( vr  );
    resultmulti( vi  );
    resultmulti( vc  );
    resultmulti( real(vc)  );
    resultmulti( imag(vc)  );
    resultend();
    CR();
  }

  {
    CR();
    CR();
    EXAMPLE(Nex++,"create a complex vector from a real vector and a scalar");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( Vector<double> v( range<double>(1,4) ));
    GMD_CODE_END();
    CR();

    resultstart2(": create a complex vector from a real vector and a scalar");
    resultmulti( Complex(v, 0.) );
    resultmulti( Complex(v, 1.) );
    resultmulti( Complex(0., v) );
    resultmulti( Complex(1., v) );
    resultend();
    CR();
  }


  GMD_HEADER3("Complex Conjugation");

  OUTPUT("Complex cojugation can be performed via the function `conj` or via the operator `~`");
  {
    CR();
    CR();
    EXAMPLE(Nex++,"compute the complex conjugate of a vector");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace std );
    ECHO_CODE( Vector<complex<double> > vc(3) );
    ECHO_CODE( Vector<double> vr( range<double>(1,3) ));
    ECHO_CODE( Vector<double> vi( range<double>(-1,1) ));
    ECHO_CODE( vc = Complex(vr, vi) );
    GMD_CODE_END();
    CR();

    resultstart2(": compute the complex conjugate of a vector");
    resultmulti( vr  );
    resultmulti( vi  );
    resultmulti( vc  );
    resultmulti( conj(vc)  );
    resultmulti( ~vc  );
    resultend();
    CR();
  }




  
  OUTPUT("* Functions defined for complex vectors  ");
  
  {
    CR();
    CR();
    EXAMPLE(Nex++,"functions of complex vectors");
    GMD_CODE_START("C++");
    ECHO_CODE(const double pi = M_PI);
    ECHO_CODE( using namespace std );
    ECHO_CODE( Vector<complex<double> > v(3) );
    ECHO_CODE( Vector<double> vr( range<double>(1,3) ));
    ECHO_CODE( Vector<double> vi( range<double>(-1,1) ));
    ECHO_CODE( v = Complex(vr, vi) );
    GMD_CODE_END();
    CR();

    resultstart2(": functions of complex vectors");
    // TODO: need to implement these for complex numbers and then for Tensors
    //  resultmulti( floor(v)  );
    //  resultmulti( ceil(v)  );
    // resultmulti( sgn(v)  );
    resultmulti( v  );
    resultmulti( abs(v)* ( cos(arg(v)) + Complex(0., sin(arg(v))) ) );
    resultmulti( abs(v)  );
    resultmulti( pow(2., v)  );
    resultmulti( pow(v, 2.)  );
    resultmulti( pow(v,v)  );
    resultmulti( exp(v)  );
    resultmulti( round(exp(v))  );
    resultmulti( roundzero(v+1e-16) );
    resultmulti( log(v)  );
    resultmulti( log10(v)  );
    //    resultmulti( log2(v)  );
    resultmulti( sqr(v)  );
    resultmulti( cube(v)  );
    resultmulti( sqrt(v)  );
    resultmulti( sin(v)  );
    resultmulti( cos(v)  );
    resultmulti( tan(v)  );
    resultmulti( sinh(v)  );
    resultmulti( cosh(v)  );
    resultmulti( tanh(v)  );
    resultmulti( asin(v)  );
    resultmulti( acos(v)  );
    resultmulti( atan(v)  );
    resultmulti( atan2(vr, vi)  );
    resultend();
    CR();
    resultstart3("Aritmetic with scalars");
    resultmulti( v + 0.1 );
    resultmulti( 0.1 + v );
    resultmulti( v - 0.1 );
    resultmulti( 0.1 - v );
    resultend();
    CR();

  }




  mathq_toc();

  return 0;
}
