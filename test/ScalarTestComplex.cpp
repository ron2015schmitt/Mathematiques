#define MATHQ_DEBUG 0
#include "mathq.h"
#include "test.h"


template <class D>
std::complex<D> average(std::complex<D> x) {
  D avg = (real(x) + imag(x)) / 2.;
  return std::complex<D>(avg, avg);
}

template <class D>
D average(D x, D y) {
  return (x + y) / 2.;
}


int main(int argc, char* argv[]) {
  std::string myname = argv[0];

  using namespace mathq;
  using namespace display;

  FormatData<bool>::string_for_true = "true";
  FormatData<bool>::string_for_false = "false";

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  print_mathq_info();
  MOUT << CREATESTYLE(BOLD + MAGENTA1).apply(__FILE__) << " - Scalar-complex numbers tests" << std::endl;
  CR();
  CR();

  bool allpass = true;
  int testnum = 0;
  int failnum = 0;
  double tol = 5e-15;
  const double pi = M_PI;



  // -------------- constructors etc ------------------------
  // just use Material for expressions and typedecl() forconcrete

  {
    // dynamic cast
    // printStart(++testnum);
    // Scalar<ComplexInt> s1 = ComplexInt(1,1);
    // testtext( "dynamic casting" );
    // TensorRW<ComplexInt, Scalar<ComplexInt> > &s2 = s1;
    // Scalar<ComplexInt> *sp1 = dynamic_cast< Scalar<ComplexInt>* >(&s2);
    // void* result = (void*)&s1;
    // void* expected = (void*)sp1;
    // bool pass = (result==expected);
    // printEnd(pass,result,expected);
    // allpass = allpass && pass;
    // failnum += (!pass);
  }




  // {
  //   //
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = ComplexInt(1,1);
  //   testtext( "is_instance test #1" );
  //   bool result = is_instance<decltype(s1), Scalar>{};
  //   bool expected = true;
  //   bool pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   //
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s1 = ComplexDouble(1.1,1.1);
  //   testtext( "is_instance test #2" );
  //   bool result = is_instance<decltype(s1), Scalar>{};
  //   bool expected = true;
  //   bool pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   //
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s1 = ComplexDouble(1.1,2.2);
  //   testtext( "is_instance test #3" );
  //   bool result = is_instance<decltype(s1), Scalar>{};
  //   bool expected = true;
  //   bool pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   //
  //   printStart(++testnum);
  //   Vector<ComplexInt> s1 = {ComplexInt(1,1)};
  //   testtext( "is_instance test #4" );
  //   bool result = is_instance<decltype(s1), Scalar>{};
  //   bool expected = false;
  //   bool pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  {
    //  dimensions and size
    printStart(++testnum);

    Scalar<ComplexInt> s1 = ComplexInt(1, 1);
    bool result;
    testcode(result = (s1.size() == 1) && (s1.dims().datasize() == 1) && (s1.ndims() == 0) && (s1.dims().size() == 0));
    bool expected = true;
    bool pass = result;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // // -------------- element access ------------------------


  {
    //  element access ()
    printStart(++testnum);
    Scalar<ComplexInt> s = ComplexInt(14, 7);
    ComplexInt expected = ComplexInt(14, 7);
    ComplexInt result;
    testcode(result = s());
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    //  element access [0]
    printStart(++testnum);
    Scalar<ComplexInt> s = ComplexInt(14, 71);
    ComplexInt expected = ComplexInt(14, 71);
    ComplexInt result;
    testcode(result = s[0]);
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // -------------- equal (elementwise) ------------------------
  {
    //  ==
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(14, 71);
    Scalar<ComplexInt> s2 = ComplexInt(14, 71);
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 == s2));
    bool pass = (result() == expected());
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    //  ==
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(14, 71);
    Scalar<ComplexInt> s2 = ComplexInt(14, 711);
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 == s2));
    bool pass = (result() == expected());
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    //  approx
    printStart(++testnum);
    Scalar<ComplexDouble> s1 = ComplexDouble(14., 71.);
    Scalar<ComplexDouble> s2 = ComplexDouble(14.01, 71.);
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (approx(s1, s2, 0.015)));
    bool pass = (result() == expected());
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    //  approx
    printStart(++testnum);
    Scalar<ComplexDouble> s1 = ComplexDouble(14., 71.);
    Scalar<ComplexDouble> s2 = ComplexDouble(14.01, 71.);
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (approx(s1, s2, 0.0005)));
    bool pass = (result() == expected());
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  // -------------- equal (all) ------------------------
  {
    //  equal
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(24, -1);
    Scalar<ComplexInt> s2 = ComplexInt(24, -1);
    bool expected = true;
    bool result;
    testcode(result = (equal(s1, s2)));
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    //  equal
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(24, -1);
    Scalar<ComplexInt> s2 = ComplexInt(24, -2);
    bool expected = false;
    bool result;
    testcode(result = (equal(s1, s2)));
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    //  equal_approx
    printStart(++testnum);
    Scalar<ComplexDouble> s1 = ComplexDouble(1, -25);
    Scalar<ComplexDouble> s2 = ComplexDouble(1.001, -25);
    bool expected = true;
    bool result;
    testcode(result = equal_approx(s1, s2, 0.002));
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    //  equal_approx
    printStart(++testnum);
    Scalar<ComplexDouble> s1 = ComplexDouble(1, -25);
    Scalar<ComplexDouble> s2 = ComplexDouble(1.001, -25);
    bool expected = false;
    bool result;
    testcode(result = equal_approx(s1, s2, 0.0005));
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  // // -------------- constructors  ------------------------

  // // -------------- assignment =  ------------------------
  // // TODO:


  // // -------------- arithmetic ------------------------

  {
    // +(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(pi, 1.2);
    Scalar<ComplexDouble> expected = ComplexDouble(pi, 1.2);
    Scalar<ComplexDouble> result;
    testcode(result = +s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // -(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(pi, 1.2);
    Scalar<ComplexDouble> expected = ComplexDouble(-pi, -1.2);
    Scalar<ComplexDouble> result;
    testcode(result = -s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar = numbercast(Scalar)
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(10, 1);
    Scalar<ComplexDouble> expected = ComplexDouble(10., 1.);
    Scalar<ComplexDouble> result;
    testcode(result = numbercast<ComplexDouble>(s1));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar + Scalar
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(10, 1);
    Scalar<ComplexInt> s2 = ComplexInt(-1, 1);
    Scalar<ComplexInt> expected = ComplexInt(9, 2);
    Scalar<ComplexInt> result;
    testcode(result = s1 + s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar - Scalar
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(10, 1);
    Scalar<ComplexInt> s2 = ComplexInt(-1, 1);
    Scalar<ComplexInt> expected = ComplexInt(11, 0);
    Scalar<ComplexInt> result;
    testcode(result = s1 - s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // Scalar * Scalar
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(10, 1);
    Scalar<ComplexInt> s2 = ComplexInt(-1, 1);
    Scalar<ComplexInt> expected = ComplexInt(-11, 9);
    Scalar<ComplexInt> result;
    testcode(result = s1 * s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar / Scalar
    printStart(++testnum);
    Scalar<ComplexInt> s1 = ComplexInt(20, 2);
    Scalar<ComplexInt> s2 = ComplexInt(-1, 1);
    Scalar<ComplexInt> expected = ComplexInt(-9, -11);
    Scalar<ComplexInt> result;
    testcode(result = s1 / s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }





  // // --------------real math functions------------------------


  // // ************************************************************************
  // // *            Powers and logs
  // // ************************************************************************

  {
    // sqr(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(90.130395598910638, 62.831853071795862);
    Scalar<ComplexDouble> result;
    testcode(result = sqr(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // cube(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(7.039118679673193e2, 9.114715193966381e2);
    Scalar<ComplexDouble> result;
    testcode(result = cube(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // sqrt(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(3.20014611167193, 0.490851439896983);
    Scalar<ComplexDouble> result;
    testcode(result = sqrt(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // exp(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(-22026.4657948067, 2.69746408321387e-12);
    Scalar<ComplexDouble> result;
    testcode(result = exp(s));
    bool pass = equal_approx(result, expected, 5 * tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(2.34964712404865, 0.304395797364615);
    Scalar<ComplexDouble> result;
    testcode(result = log(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log2(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(3.38982425370401, 0.439150307325372);
    Scalar<ComplexDouble> result;
    testcode(result = log2(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log10(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(1.02043878039418, 0.132197415109993);
    Scalar<ComplexDouble> result;
    testcode(result = log10(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // // ************************************************************************
  // // *            trig, inverse trig, hyperbolic trig
  // // ************************************************************************


  {
    // sin(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(-6.30626729832689, -9.69021839139966);
    Scalar<ComplexDouble> result;
    testcode(result = sin(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // cos(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(-9.72647795987463, 6.28275801450715);
    Scalar<ComplexDouble> result;
    testcode(result = cos(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // tan(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(10, pi);
    Scalar<ComplexDouble> expected = ComplexDouble(0.00340454507051446, 0.998471220959037);
    Scalar<ComplexDouble> result;
    testcode(result = tan(s));
    bool pass = equal_approx(result, expected, 5 * tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // asin(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(-6.30626729832689, -9.69021839139966);
    Scalar<ComplexDouble> expected = ComplexDouble(-0.57522203923062, -3.14159265358979);
    Scalar<ComplexDouble> result;
    testcode(result = asin(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // acos(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(-9.72647795987463, 6.28275801450715);
    Scalar<ComplexDouble> expected = ComplexDouble(2.56637061435917, -3.14159265358979);
    Scalar<ComplexDouble> result;
    testcode(result = acos(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // atan(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(0.00340454507051453, 0.998471220959037);
    Scalar<ComplexDouble> expected = ComplexDouble(0.57522203923062028, 3.1415926535897932);
    Scalar<ComplexDouble> result;
    testcode(result = atan(s));
    bool pass = equal_approx(result, expected, 100 * tol); // relax the tolerance for this
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // complex atan2 is not part of std.  not even implemented in matlab
  // {
  //   // atan2(s1,s2)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s1 = ComplexDouble(0.1,0.2);
  //   Scalar<ComplexDouble> s2 = ComplexDouble(0.4,-0.1);
  //   Scalar<ComplexDouble> expected = ComplexDouble(1,1);
  //   Scalar<ComplexDouble> result;
  //   testcode( result = atan2(s1,s2) );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  {
    // sinh(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(0.1, pi / 6);
    Scalar<ComplexDouble> expected = ComplexDouble(0.0867469501317104, 0.502502084027902);
    Scalar<ComplexDouble> result;
    testcode(result = sinh(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // cosh(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(0.1, pi / 6);
    Scalar<ComplexDouble> expected = ComplexDouble(0.870359140445571, 0.050083375009922);
    Scalar<ComplexDouble> result;
    testcode(result = cosh(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // tanh(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(0.1, pi / 6);
    Scalar<ComplexDouble> expected = ComplexDouble(0.132452079355618, 0.569728533686492);
    Scalar<ComplexDouble> result;
    testcode(result = tanh(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // // ************************************************************************
  // // *            sign-related and rounding
  // // ************************************************************************


  {
    // abs(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(1, -2);
    Scalar<double> expected = 2.23606797749979;
    Scalar<double> result;
    testcode(result = real(abs(s)));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // sgn(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(1, -2);
    Scalar<ComplexDouble> expected = ComplexDouble(1, -1);
    Scalar<ComplexDouble> result;
    testcode(result = sgn(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // round(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(1.5, 1.4);
    Scalar<ComplexDouble> expected = ComplexDouble(2, 1);
    Scalar<ComplexDouble> result;
    testcode(result = round(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // floor(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(1.5, 1.4);
    Scalar<ComplexDouble> expected = ComplexDouble(1, 1);
    Scalar<ComplexDouble> result;
    testcode(result = floor(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // ceil(s)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(1.01, 1.99);
    Scalar<ComplexDouble> expected = ComplexDouble(2, 2);
    Scalar<ComplexDouble> result;
    testcode(result = ceil(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // roundzero(s,0.01)
    printStart(++testnum);
    Scalar<ComplexDouble> s = ComplexDouble(0.009, 0.011);
    Scalar<ComplexDouble> expected = ComplexDouble(0, 0.011);
    Scalar<ComplexDouble> result;
    testcode(result = roundzero(s, 0.01));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // {
  //   // op1<double,clip>(s)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = ComplexDouble(2,3);
  //   Scalar<ComplexDouble> expected = ComplexDouble(2.5,2.5);
  //   Scalar<ComplexDouble> result;
  //   testcode( result = op1<ComplexDouble,average>(s) );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // op2<double,paste>(s)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s1 = ComplexDouble(2,3);
  //   Scalar<ComplexDouble> s2 = ComplexDouble(10,3);
  //   Scalar<ComplexDouble> expected = ComplexDouble(6,3);
  //   Scalar<ComplexDouble> result;
  //   testcode( result = op2<ComplexDouble,average>(s1,s2) );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  {
    // Test of a large Scalar math expression

    printStart(++testnum);
    Scalar<ComplexDouble> s1 = ComplexDouble(2, 3);
    Scalar<ComplexDouble> s2 = ComplexDouble(10, 3);
    Scalar<ComplexDouble> expected = ComplexDouble(97.07651685436622, 60);
    Scalar<ComplexDouble> result;
    testcode(result = 2 * log10(abs(s1 / s2) * 100) + 3 + pow(-s2, 2));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  // // ***********************************************************************
  // // *              Logic
  // // ***********************************************************************

  // not applicable since they require bool types


  // // ************************************************************************
  // // *            Bit wise operators for unisgned types
  // // ************************************************************************

  CR();
  const unsigned short usmax = std::numeric_limits<unsigned short>::max();
  printf("          std::numeric_limits<unsigned short>::max() = %0x\n", usmax);
  CR();
  // {
  //   // bitwise not ~
  //   printStart(++testnum);
  //   Scalar<ComplexUnsignedShort> s1 = ComplexUnsignedShort(usmax-3, usmax-10);
  //   Scalar<ComplexUnsignedShort> expected = ComplexUnsignedShort(3, 10);
  //   Scalar<ComplexUnsignedShort> result;
  //   testcode( result = ~s1 );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // bitwise  OR |
  //   printStart(++testnum);
  //   Scalar<ComplexUnsignedShort> s1 = ComplexUnsignedShort(9, 0);
  //   Scalar<ComplexUnsignedShort> s2 = ComplexUnsignedShort(7, 1);
  //   Scalar<ComplexUnsignedShort> expected = ComplexUnsignedShort(15, 1);
  //   Scalar<ComplexUnsignedShort> result;
  //   testcode( result = (s1 | s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // bitwise XOR ^
  //   printStart(++testnum);
  //   Scalar<ComplexUnsignedShort> s1 = ComplexUnsignedShort(9, 3);
  //   Scalar<ComplexUnsignedShort> s2 = ComplexUnsignedShort(7, 1);
  //   Scalar<ComplexUnsignedShort> expected = ComplexUnsignedShort(14, 2);
  //   Scalar<ComplexUnsignedShort> result;
  //   testcode( result = (s1 ^ s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // bitwise AND &
  //   printStart(++testnum);
  //   Scalar<ComplexUnsignedShort> s1 = ComplexUnsignedShort(9, 3);
  //   Scalar<ComplexUnsignedShort> s2 = ComplexUnsignedShort(7, 1);
  //   Scalar<ComplexUnsignedShort> expected = ComplexUnsignedShort(1, 1);
  //   Scalar<ComplexUnsignedShort> result;
  //   testcode( result = (s1 & s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // bitwise <<
  //   printStart(++testnum);
  //   Scalar<ComplexUnsignedShort> s1 = ComplexUnsignedShort(1, 3);
  //   unsigned short n2 = 2;
  //   Scalar<ComplexUnsignedShort> expected = ComplexUnsignedShort(4, 6);
  //   Scalar<ComplexUnsignedShort> result;
  //   testcode( result = (s1 << n2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // bitwise >>
  //   printStart(++testnum);
  //   Scalar<ComplexUnsignedLong> s1 = ComplexUnsignedShort(4, 15);
  //   unsigned short n2 = 2;
  //   Scalar<ComplexUnsignedLong> expected = ComplexUnsignedShort(1, 3);
  //   Scalar<ComplexUnsignedLong> result;
  //   testcode( result = (s1 >> n2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  // // ************************************************************************
  // // *              Relational ops (return a bool from two Ds)
  // // ************************************************************************


  // {
  //   // s1 == s2 #1
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = -11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s1==s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // s1 == s2 #2
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s1==s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // s1 != s2 #1
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = -11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s1!=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // s1 != s2 #2
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s1!=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }



  // {
  //   // s1 >= s2 #1
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s1>=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // s1 >= s2 #2
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = -11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s1>=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // s1 >= s2 #3
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 12;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s1>=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  // {
  //   // s1 > > s2 #1
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s1>s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // s1 > > s2 #2
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = -11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s1>s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // s1 > > s2 #3
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 12;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s1>s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  // {
  //   // s1 < s2 #1
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s1<s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // s1 < s2 #2
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = -11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s1<s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // s1 < s2 #3
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 12;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s1<s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }



  // {
  //   // s1 <= s2 #1
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s1<=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // s1 <= s2 #2
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = -11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s1<=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // s1 <= s2 #3
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 11;
  //   Scalar<ComplexInt> s2 = 12;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s1<=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }



  // /****************************************************************************
  //  * transpose, cojugate, adjoint
  //  ****************************************************************************
  //  */


  // // -------------- transpose------------------------

  // {
  //   // transpose(z)
  //   using namespace std;
  //   printStart(++testnum);
  //   Scalar<std::complex<complex<double> > z = complex<double>(1,2);
  //   Scalar<std::complex<complex<double> > expected = complex<double>(1,2);
  //   Scalar<std::complex<complex<double> > result;
  //   testcode( result = transpose(z) );
  //   bool pass = alltrue(result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // transpose(x)
  //   using namespace std;
  //   printStart(++testnum);
  //   Scalar<ComplexDoublex = 25.1;
  //   Scalar<ComplexDouble> expected = 25.1;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = transpose(x) );
  //   bool pass = alltrue(result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }



  // //-------------------COMPLEX NUMBERS----------------------------

  // {
  //   // conj(z)
  //   using namespace std;
  //   printStart(++testnum);
  //   Scalar<std::complex<complex<double> > z = complex<double>(1,2);
  //   Scalar<std::complex<complex<double> > expected = complex<double>(1,-2);
  //   Scalar<std::complex<complex<double> > result;
  //   testcode( result = conj(z) );
  //   bool pass = alltrue(result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // z.conj()
  //   using namespace std;
  //   printStart(++testnum);
  //   Scalar<std::complex<complex<double> > z = complex<double>(1,2);
  //   Scalar<std::complex<complex<double> > expected = complex<double>(1,-2);
  //   Scalar<std::complex<complex<double> > result;
  //   testcode( result = z.conj() );
  //   bool pass = alltrue(result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  // }
  // {
  //   // x.conj()
  //   using namespace std;
  //   printStart(++testnum);
  //   Scalar<ComplexDoublex = 22;
  //   Scalar<ComplexDouble> expected = 22;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = x.conj() );
  //   bool pass = alltrue(result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  // }

  // {
  //   // adjoint(z)
  //   using namespace std;
  //   printStart(++testnum);
  //   Scalar<std::complex<complex<double> > z = complex<double>(1,2);
  //   Scalar<std::complex<complex<double> > expected = complex<double>(1,-2);
  //   Scalar<std::complex<complex<double> > result;
  //   testcode( result = adjoint(z) );
  //   bool pass = alltrue(result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // ~z
  //   using namespace std;
  //   printStart(++testnum);
  //   Scalar<std::complex<complex<double> > z = complex<double>(1,2);
  //   Scalar<std::complex<complex<double> > expected = complex<double>(1,-2);
  //   Scalar<std::complex<complex<double> > result;
  //   testcode( result = ~z );
  //   bool pass = alltrue(result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }



  // /****************************************************************************
  //  * Unary Functions/Operators that return scalars
  //  ****************************************************************************
  //  */

  // {
  //   // sum(s)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = pi/6;
  //   double expected = pi/6;
  //   double result;
  //   testcode( result = sum(s) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // prod(s)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = pi/6;
  //   double expected = pi/6;
  //   double result;
  //   testcode( result = sum(s) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // norm(s)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = pi/6;
  //   double expected = pi/6;
  //   double result;
  //   testcode( result = norm(s) );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // min(s)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = pi/6;
  //   double expected = pi/6;
  //   double result;
  //   testcode( result = min(s) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // max(s)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = pi/6;
  //   double expected = pi/6;
  //   double result;
  //   testcode( result = max(s) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // /****************************************************************************
  //  * Unary Functions/Operators that bools or index_type Tensors
  //  ****************************************************************************
  //  */

  // {
  //   // alltrue(s)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 42;
  //   Scalar<ComplexInt> s2 = 42;
  //   bool expected = true;
  //   bool result;
  //   testcode( result = alltrue(s1>=s2) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // alltrue(s)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 42;
  //   Scalar<ComplexInt> s2 = 42;
  //   bool expected = false;
  //   bool result;
  //   testcode( result = alltrue(s1>s2) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // anytrue(s)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 42;
  //   Scalar<ComplexInt> s2 = 42;
  //   bool expected = true;
  //   bool result;
  //   testcode( result = alltrue(s1>=s2) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // anytrue(s)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 42;
  //   Scalar<ComplexInt> s2 = 42;
  //   bool expected = false;
  //   bool result;
  //   testcode( result = alltrue(s1>s2) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // numtrue(s)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 42;
  //   Scalar<ComplexInt> s2 = 42;
  //   int expected = 1;
  //   int result;
  //   testcode( result = numtrue(s1>=s2) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // numtrue(s)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 42;
  //   Scalar<ComplexInt> s2 = 42;
  //   int expected = 0;
  //   int result;
  //   testcode( result = numtrue(s1>s2) );
  //   bool pass = result==expected;
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // findtrue(s)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 42;
  //   Scalar<ComplexInt> s2 = 42;
  //   Vector<index_type> expected(1,0);
  //   Vector<index_type> result;
  //   testcode( result = findtrue(s1>=s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // findtrue(s)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s1 = 42;
  //   Scalar<ComplexInt> s2 = 42;
  //   Vector<index_type> expected(0);
  //   Vector<index_type> result;
  //   testcode( result = findtrue(s1>s2) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // /************************************************************
  //  *               Scalar/scalar mix
  //  ************************************************************
  //  */

  // //---------- Scalar/scalar mix: arithmetic -----------------

  // // addition
  // {
  //   // Scalar + scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   double n = -2.;
  //   Scalar<ComplexDouble> expected = 40.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = s+n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar + int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   int n = -2;
  //   Scalar<ComplexDouble> expected = 40.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = s+n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt + int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 42;
  //   int n = -2;
  //   Scalar<ComplexInt expected = 40;
  //   Scalar<ComplexInt result;
  //   testcode( result = s+n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // scalar + Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   double n = -2.;
  //   Scalar<ComplexDouble> expected = 40.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = n+s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int + Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   int n = -2;
  //   Scalar<ComplexDouble> expected = 40.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = n+s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int + Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 42;
  //   int n = -2;
  //   Scalar<ComplexInt expected = 40;
  //   Scalar<ComplexInt result;
  //   testcode( result = n+s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // // subtraction
  // {
  //   // Scalar - scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   double n = -2.;
  //   Scalar<ComplexDouble> expected = 44.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = s-n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar - int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   int n = -2;
  //   Scalar<ComplexDouble> expected = 44.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = s-n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt - int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 42;
  //   int n = -2;
  //   Scalar<ComplexInt expected = 44;
  //   Scalar<ComplexInt result;
  //   testcode( result = s-n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // scalar - Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   double n = -2.;
  //   Scalar<ComplexDouble> expected = -44.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = n-s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int - Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   int n = -2;
  //   Scalar<ComplexDouble> expected = -44.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = n-s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int - Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 42;
  //   int n = -2;
  //   Scalar<ComplexInt expected = -44.;
  //   Scalar<ComplexInt result;
  //   testcode( result = n-s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  // // multiplication
  // {
  //   // Scalar * scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   double n = -2.;
  //   Scalar<ComplexDouble> expected = -84.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = s*n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar * int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   int n = -2;
  //   Scalar<ComplexDouble> expected = -84.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = s*n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt * int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 42;
  //   int n = -2;
  //   Scalar<ComplexInt expected = -84;
  //   Scalar<ComplexInt result;
  //   testcode( result = s*n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // scalar * Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   double n = -2.;
  //   Scalar<ComplexDouble> expected = -84.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = n*s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int * Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   int n = -2;
  //   Scalar<ComplexDouble> expected = -84.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = n*s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int * Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 42;
  //   int n = -2;
  //   Scalar<ComplexInt expected = -84.;
  //   Scalar<ComplexInt result;
  //   testcode( result = n*s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  // // division
  // {
  //   // Scalar / scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   double n = -2.;
  //   Scalar<ComplexDouble> expected = -21.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = s/n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar / int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   int n = -2;
  //   Scalar<ComplexDoubleexpected = -21.;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = s/n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt / int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 42;
  //   int n = -2;
  //   Scalar<ComplexInt expected = -21;
  //   Scalar<ComplexInt result;
  //   testcode( result = s/n );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // scalar / Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   double n = -2.;
  //   Scalar<ComplexDoubleexpected = -0.047619047619048;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = n/s );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int / Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 42.;
  //   int n = -2;
  //   Scalar<ComplexDoubleexpected = -0.047619047619048;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = n/s );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int / Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 42;
  //   int n = -420;
  //   Scalar<ComplexInt expected = -10;
  //   Scalar<ComplexInt result;
  //   testcode( result = n/s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }



  // // pow
  // {
  //   // pow(Scalar , scalar)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 3;
  //   double n = 4;
  //   Scalar<ComplexDoubleexpected = 81;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = pow(s,n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // pow(Scalar , int)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 3;
  //   int n = 4;
  //   Scalar<ComplexDoubleexpected = 81;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = pow(s,n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // pow(Scalar<ComplexInt , int)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 3;
  //   int n = 4;
  //   Scalar<ComplexInt expected = 81;
  //   Scalar<ComplexInt result;
  //   testcode( result = pow(s,n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // pow(scalar , Scalar)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 3;
  //   double n = 4;
  //   Scalar<ComplexDoubleexpected = 64;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = pow(n,s) );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // pow(int , Scalar)
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 3;
  //   int n = 4;
  //   Scalar<ComplexDoubleexpected = 64;
  //   Scalar<ComplexDoubleresult;
  //   testcode( result = pow(n,s) );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // pow(int , Scalar<ComplexInt)
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 3;
  //   int n = 4;
  //   Scalar<ComplexInt expected = 64;
  //   Scalar<ComplexInt result;
  //   testcode( result = pow(n,s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  //---------- Tensor-scalar mix: logic -----------------
  // {
  //   // Scalar && scalar
  //   printStart(++testnum);
  //   Scalar<bool> > s = true;
  //   bool b = true;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = s && b );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // scalar && Scalar
  //   printStart(++testnum);
  //   Scalar<bool> > s = true;
  //   bool b = true;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = b && s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // Scalar || scalar
  //   printStart(++testnum);
  //   Scalar<bool> > s = true;
  //   bool b = false;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = s || b );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // scalar || Scalar
  //   printStart(++testnum);
  //   Scalar<bool> > s = true;
  //   bool b = false;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = b || s );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }



  // //---------- Tensor scalar mix: relational -----------------

  // {
  //   // Scalar == scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 11.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s==d) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // scalar == Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 11.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (d==s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  // {
  //   // Scalar == int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 11;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s==n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int == Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 11;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (n==s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt == int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 11;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s==n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int == Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 11;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (n==s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  // {
  //   // Scalar != scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 11.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s!=d) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // scalar != Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 11.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (d!=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar != int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 11;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s!=n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int != Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 11;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (n!=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt != int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 11;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s!=n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int != Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 11;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (n!=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // Scalar >= scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s>=d) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // scalar >= Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (d>=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar >= int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s>=n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int >= Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (n>=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt>= int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s>=n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int >= Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (n>=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // Scalar > > scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s>d) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // scalar > > scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (d>s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar > int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s>n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int > > scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (n>s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt> int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (s>n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int > > scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (n>s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  // {
  //   // Scalar <= scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s<=d) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // scalar <= Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (d<=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar <= int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s<=n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int <= Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (n<=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt <= int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s<=n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int <= Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (n<=s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // Scalar < scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s<d) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // scalar < Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12.5;
  //   double d = 11.5;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (d<s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar < int
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s<n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int < Scalar
  //   printStart(++testnum);
  //   Scalar<ComplexDouble> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (n<s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // Scalar<ComplexInt < int
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = false;
  //   Scalar<bool> result;
  //   testcode( result = (s<n) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // int < Scalar<ComplexInt
  //   printStart(++testnum);
  //   Scalar<ComplexInt> s = 12;
  //   int n = 11;
  //   Scalar<bool> expected = true;
  //   Scalar<bool> result;
  //   testcode( result = (n<s) );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }


  printSummary(__FILE__, testnum, failnum);
  return failnum;
}
