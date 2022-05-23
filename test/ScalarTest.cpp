#define MATHQ_DEBUG 0
#include "mathq.h"
#include "test.h"



template <class D>
D clip(D x) {
  return (x >= 0) ? (x) : 0;
}

template <class D>
D paste(D x, D y) {
  return (x >= 0) ? (y) : 0;
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
  MOUT << CREATESTYLE(BOLD + MAGENTA1).apply(__FILE__) << " - scalar tests" << std::endl;
  CR();
  CR();

  bool allpass = true;
  int testnum = 0;
  int failnum = 0;
  double tol = 5e-16;
  const double pi = M_PI;


  // -------------- constructors etc ------------------------

  {
    // dynamic cast
    // just use Material for expressions and typedecl() forconcrete
    // printStart(++testnum);
    // Scalar<int> s1 = 1;
    // testtext( "dynamic casting" );
    // TensorRW<int,Scalar<int> > &s2 = s1;
    // Scalar<int> *sp1 = dynamic_cast<Scalar<int>*>(&s2);
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
  //   Scalar<int> s1 = 1;
  //   testtext( "is_instance test #1" );
  //   bool result = std::is_same<decltype(s1), Scalar>;
  //   bool expected = true;
  //   bool pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   //
  //   printStart(++testnum);
  //   Scalar<double> s1 = 1.1;
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
  //   Scalar<std::complex<double> > s1 = std::complex<double>(1.1,2.2);
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
  //   Vector<int> s1 = {1};
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

    Scalar<int> s1 = 1;
    bool result;
    testcode(result = (s1.size() == 1) && (s1.dims().datasize() == 1) && (s1.ndims() == 0) && (s1.dims().size() == 0));
    bool expected = true;
    bool pass = result;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // -------------- element access ------------------------


  {
    //  element access ()
    printStart(++testnum);
    Scalar<int> s = 14;
    int expected = 14;
    int result;
    testcode(result = s());
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    //  element access [0]
    printStart(++testnum);
    Scalar<int> s = 24;
    int expected = 24;
    int result;
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
    Scalar<int> s1 = 24;
    Scalar<int> s2 = 24;
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
    Scalar<int> s1 = 24;
    Scalar<int> s2 = -24;
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
    Scalar<double> s1 = 1;
    Scalar<double> s2 = 1.001;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (approx(s1, s2, 0.0011)));
    bool pass = (result() == expected());
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    //  approx
    printStart(++testnum);
    Scalar<double> s1 = 1;
    Scalar<double> s2 = 1.001;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (approx(s1, s2, 0.0009)));
    bool pass = (result() == expected());
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  // -------------- equal (all) ------------------------
  {
    //  equal
    printStart(++testnum);
    Scalar<int> s1 = 24;
    Scalar<int> s2 = 24;
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
    Scalar<int> s1 = 24;
    Scalar<int> s2 = -24;
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
    Scalar<double> s1 = 1;
    Scalar<double> s2 = 1.001;
    bool expected = true;
    bool result;
    testcode(result = equal_approx(s1, s2, 0.0011));
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    //  equal_approx
    printStart(++testnum);
    Scalar<double> s1 = 1;
    Scalar<double> s2 = 1.001;
    bool expected = false;
    bool result;
    testcode(result = equal_approx(s1, s2, 0.0009));
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  // -------------- constructors  ------------------------

  // -------------- assignment =  ------------------------
  // TODO:


  // -------------- arithmetic ------------------------

  {
    // +(s)
    printStart(++testnum);
    Scalar<double> s = pi;
    Scalar<double> expected = pi;
    Scalar<double> result;
    testcode(result = +s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // -(s)
    printStart(++testnum);
    Scalar<double> s = pi;
    Scalar<double> expected = -pi;
    Scalar<double> result;
    testcode(result = -s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar = numbercast(Scalar)
    printStart(++testnum);
    Scalar<int> s1 = 10;
    Scalar<double> s2 = 10.;
    Scalar<double> expected = 10.;
    Scalar<double> result;
    testcode(result = numbercast<double>(s1));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar + Scalar
    printStart(++testnum);
    Scalar<int> s1 = 10;
    Scalar<int> s2 = -1;
    Scalar<int> expected = 9;
    Scalar<int> result;
    testcode(result = s1 + s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar - Scalar
    printStart(++testnum);
    Scalar<int> s1 = 10;
    Scalar<int> s2 = -1;
    Scalar<int> expected = 11;
    Scalar<int> result;
    testcode(result = s1 - s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // Scalar * Scalar
    printStart(++testnum);
    Scalar<int> s1 = 10;
    Scalar<int> s2 = 3;
    Scalar<int> expected = 30;
    Scalar<int> result;
    testcode(result = s1 * s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar / Scalar
    printStart(++testnum);
    Scalar<int> s1 = 27;
    Scalar<int> s2 = 9;
    Scalar<int> expected = 3;
    Scalar<int> result;
    testcode(result = s1 / s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }





  // --------------real math functions------------------------


  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************

  {
    // sqr(s)
    printStart(++testnum);
    Scalar<double> s = pi;
    Scalar<double> expected = 9.869604401089358;
    Scalar<double> result;
    testcode(result = sqr(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // cube(s)
    printStart(++testnum);
    Scalar<double> s = 3;
    Scalar<double> expected = 27;
    Scalar<double> result;
    testcode(result = cube(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // sqrt(s)
    printStart(++testnum);
    Scalar<double> s = 1000;
    Scalar<double> expected = 31.622776601683793;
    Scalar<double> result;
    testcode(result = sqrt(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // exp(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 1.688091794964469;
    Scalar<double> result;
    testcode(result = exp(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = -0.647029583378655;
    Scalar<double> result;
    testcode(result = log(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log2(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = -0.933466371248838;
    Scalar<double> result;
    testcode(result = log2(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log10(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = -0.281001377689510;
    Scalar<double> result;
    testcode(result = log10(s));
    bool pass = equal_approx(result, expected, 5 * tol); // relaxed tolerance
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************


  {
    // sin(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 0.5;
    Scalar<double> result;
    testcode(result = sin(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // cos(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 0.866025403784439;
    Scalar<double> result;
    testcode(result = cos(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // tan(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 0.577350269189626;
    Scalar<double> result;
    testcode(result = tan(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // asin(s)
    printStart(++testnum);
    Scalar<double> s = 0.5;
    Scalar<double> expected = 0.523598775598299;
    Scalar<double> result;
    testcode(result = asin(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // acos(s)
    printStart(++testnum);
    Scalar<double> s = 0.5;
    Scalar<double> expected = 1.047197551196598;
    Scalar<double> result;
    testcode(result = acos(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // atan(s)
    printStart(++testnum);
    Scalar<double> s = 0.5;
    Scalar<double> expected = 0.463647609000806;
    Scalar<double> result;
    testcode(result = atan(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // atan2(s1,s2)
    printStart(++testnum);
    Scalar<double> s1 = -2;
    Scalar<double> s2 = -1;
    Scalar<double> expected = -2.034443935795703;
    Scalar<double> result;
    testcode(result = atan2(s1, s2));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // sinh(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 0.547853473888040;
    Scalar<double> result;
    testcode(result = sinh(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // cosh(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 1.140238321076429;
    Scalar<double> result;
    testcode(result = cosh(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // tanh(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 0.480472778156452;
    Scalar<double> result;
    testcode(result = tanh(s));
    bool pass = equal_approx(result, expected, 5 * tol); // relaxed tolerance
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


  {
    // abs(s)
    printStart(++testnum);
    Scalar<double> s = -pi;
    Scalar<double> expected = pi;
    Scalar<double> result;
    testcode(result = abs(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // sgn(s)
    printStart(++testnum);
    Scalar<double> s = -pi;
    Scalar<double> expected = -1;
    Scalar<double> result;
    testcode(result = sgn(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // round(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 1;
    Scalar<double> result;
    testcode(result = round(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // floor(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    Scalar<double> expected = 0;
    Scalar<double> result;
    testcode(result = floor(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // ceil(s)
    printStart(++testnum);
    Scalar<double> s = 0.01;
    Scalar<double> expected = 1;
    Scalar<double> result;
    testcode(result = ceil(s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // roundzero(s,0.01)
    printStart(++testnum);
    Scalar<double> s = 0.0099999999;
    Scalar<double> expected = 0;
    Scalar<double> result;
    testcode(result = roundzero(s, 0.01));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  // {
  //   // op1<double,clip>(s)
  //   printStart(++testnum);
  //   Scalar<double> s = 0.01;
  //   Scalar<double> expected = 0.01;
  //   Scalar<double> result;
  //   testcode( result = op1<double,clip>(s) );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   // op2<double,paste>(s)
  //   printStart(++testnum);
  //   Scalar<double> s1 = 0.01;
  //   Scalar<double> s2 = 4;
  //   Scalar<double> expected = 4;
  //   Scalar<double> result;
  //   testcode( result = op2<double,paste>(s1,s2) );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  {
    // Test of a large scalar math expression

    printStart(++testnum);
    Scalar<double> s1 = 40;
    Scalar<double> s2 = -4;
    Scalar<double> expected = 25;
    Scalar<double> result;
    testcode(result = 2 * log10(abs(s1 / s2) * 100) + 3 + pow(-s2, 2));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  // ***********************************************************************
  // *              Logic
  // ***********************************************************************
  {
    // !(s)
    printStart(++testnum);
    Scalar<bool> s = true;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = !s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 && s2
    printStart(++testnum);
    Scalar<bool> s1 = false;
    Scalar<bool> s2 = false;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = s1 && s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 && s2
    printStart(++testnum);
    Scalar<bool> s1 = true;
    Scalar<bool> s2 = false;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = s1 && s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 && s2
    printStart(++testnum);
    Scalar<bool> s1 = true;
    Scalar<bool> s2 = true;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = s1 && s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // s1 || s2  #1
    printStart(++testnum);
    Scalar<bool> s1 = false;
    Scalar<bool> s2 = false;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = s1 || s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 || s2 #2
    printStart(++testnum);
    Scalar<bool> s1 = true;
    Scalar<bool> s2 = false;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = s1 || s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 || s2 #3
    printStart(++testnum);
    Scalar<bool> s1 = true;
    Scalar<bool> s2 = true;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = s1 || s2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }




  // ************************************************************************
  // *              Relational ops (return a bool from two Ds)
  // ************************************************************************


  {
    // s1 == s2 #1
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = -11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 == s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 == s2 #2
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 == s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // s1 != s2 #1
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = -11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 != s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 != s2 #2
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 != s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  {
    // s1 >= s2 #1
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 >= s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // s1 >= s2 #2
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = -11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 >= s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 >= s2 #3
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 12;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 >= s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // s1 > s2 #1
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 > s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // s1 > s2 #2
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = -11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 > s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 > s2 #3
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 12;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 > s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // s1 < s2 #1
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 < s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // s1 < s2 #2
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = -11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 < s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 < s2 #3
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 12;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 < s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  {
    // s1 <= s2 #1
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 <= s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 <= s2 #2
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = -11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s1 <= s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // s1 <= s2 #3
    printStart(++testnum);
    Scalar<int> s1 = 11;
    Scalar<int> s2 = 12;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s1 <= s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  /****************************************************************************
   * transpose, cojugate, adjoint
   ****************************************************************************
   */


   // -------------- transpose------------------------

  {
    // transpose(z)
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double>> z = complex<double>(1, 2);
    Scalar<complex<double>> expected = complex<double>(1, 2);
    Scalar<complex<double>> result;
    testcode(result = transpose(z));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // transpose(x)
    using namespace std;
    printStart(++testnum);
    Scalar<double> x = 25.1;
    Scalar<double> expected = 25.1;
    Scalar<double> result;
    testcode(result = transpose(x));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  //-------------------COMPLEX NUMBERS----------------------------

  {
    // conj(z)
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double>> z = complex<double>(1, 2);
    Scalar<complex<double>> expected = complex<double>(1, -2);
    Scalar<complex<double>> result;
    testcode(result = conj(z));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // z.conj()
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double>> z = complex<double>(1, 2);
    Scalar<complex<double>> expected = complex<double>(1, -2);
    Scalar<complex<double>> result;
    testcode(result = z.conj());
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // x.conj() - does not exist
    // using namespace std;
    // printStart(++testnum);
    // Scalar<double> x = 22;
    // Scalar<ComplexDouble> expected = ComplexDouble(22,0);
    // Scalar<ComplexDouble> result;
    // testcode( result = x.conj() );
    // bool pass = alltrue(result==expected);
    // printEnd(pass,result,expected);
    // allpass = allpass && pass;
    // failnum += (!pass);

  }

  {
    // adjoint(z)
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double>> z = complex<double>(1, 2);
    Scalar<complex<double>> expected = complex<double>(1, -2);
    Scalar<complex<double>> result;
    testcode(result = adjoint(z));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // ~z
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double>> z = complex<double>(1, 2);
    Scalar<complex<double>> expected = complex<double>(1, -2);
    Scalar<complex<double>> result;
    testcode(result = ~z);
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  {
    // sum(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    double expected = pi / 6;
    double result;
    testcode(result = sum(s));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // prod(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    double expected = pi / 6;
    double result;
    testcode(result = sum(s));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // norm(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    double expected = pi / 6;
    double result;
    testcode(result = norm(s));
    bool pass = approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // min(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    double expected = pi / 6;
    double result;
    testcode(result = min(s));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // max(s)
    printStart(++testnum);
    Scalar<double> s = pi / 6;
    double expected = pi / 6;
    double result;
    testcode(result = max(s));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  /****************************************************************************
   * Unary Functions/Operators that bools or index_type Tensors
   ****************************************************************************
   */

  {
    // alltrue(s)
    printStart(++testnum);
    Scalar<int> s1 = 42;
    Scalar<int> s2 = 42;
    bool expected = true;
    bool result;
    testcode(result = alltrue(s1 >= s2));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // alltrue(s)
    printStart(++testnum);
    Scalar<int> s1 = 42;
    Scalar<int> s2 = 42;
    bool expected = false;
    bool result;
    testcode(result = alltrue(s1 > s2));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // anytrue(s)
    printStart(++testnum);
    Scalar<int> s1 = 42;
    Scalar<int> s2 = 42;
    bool expected = true;
    bool result;
    testcode(result = alltrue(s1 >= s2));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // anytrue(s)
    printStart(++testnum);
    Scalar<int> s1 = 42;
    Scalar<int> s2 = 42;
    bool expected = false;
    bool result;
    testcode(result = alltrue(s1 > s2));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // numtrue(s)
    printStart(++testnum);
    Scalar<int> s1 = 42;
    Scalar<int> s2 = 42;
    int expected = 1;
    int result;
    testcode(result = numtrue(s1 >= s2));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // numtrue(s)
    printStart(++testnum);
    Scalar<int> s1 = 42;
    Scalar<int> s2 = 42;
    int expected = 0;
    int result;
    testcode(result = numtrue(s1 > s2));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // findtrue(s)
    printStart(++testnum);
    Scalar<int> s1 = 42;
    Scalar<int> s2 = 42;
    Vector<index_type> expected(1, 0);
    TLDISP(expected);
    Vector<index_type> result;
    testcode(result = findtrue(s1 >= s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    Scalar<bool> s2 = true;
    Vector<index_type> result;
    result = findtrue(s2);
  }
  {
    // findtrue(s)
    printStart(++testnum);
    Scalar<int> s1 = 42;
    Scalar<int> s2 = 42;
    Vector<index_type> expected(0);
    Vector<index_type> result;
    testcode(result = findtrue(s1 > s2));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  /************************************************************
   *               Scalar/scalar mix
   ************************************************************
   */

   //---------- Scalar/scalar mix: arithmetic -----------------

   // addition
  {
    // Scalar + scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    double n = -2.;
    Scalar<double> expected = 40.;
    Scalar<double> result;
    testcode(result = s + n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar + int
    printStart(++testnum);
    Scalar<double> s = 42.;
    int n = -2;
    Scalar<double> expected = 40.;
    Scalar<double> result;
    testcode(result = s + n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> + int
    printStart(++testnum);
    Scalar<int> s = 42;
    int n = -2;
    Scalar<int> expected = 40;
    Scalar<int> result;
    testcode(result = s + n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // scalar + Scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    double n = -2.;
    Scalar<double> expected = 40.;
    Scalar<double> result;
    testcode(result = n + s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int + Scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    int n = -2;
    Scalar<double> expected = 40.;
    Scalar<double> result;
    testcode(result = n + s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int + Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 42;
    int n = -2;
    Scalar<int> expected = 40;
    Scalar<int> result;
    testcode(result = n + s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // subtraction
  {
    // Scalar - scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    double n = -2.;
    Scalar<double> expected = 44.;
    Scalar<double> result;
    testcode(result = s - n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar - int
    printStart(++testnum);
    Scalar<double> s = 42.;
    int n = -2;
    Scalar<double> expected = 44.;
    Scalar<double> result;
    testcode(result = s - n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> - int
    printStart(++testnum);
    Scalar<int> s = 42;
    int n = -2;
    Scalar<int> expected = 44;
    Scalar<int> result;
    testcode(result = s - n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // scalar - Scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    double n = -2.;
    Scalar<double> expected = -44.;
    Scalar<double> result;
    testcode(result = n - s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int - Scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    int n = -2;
    Scalar<double> expected = -44.;
    Scalar<double> result;
    testcode(result = n - s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int - Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 42;
    int n = -2;
    Scalar<int> expected = -44.;
    Scalar<int> result;
    testcode(result = n - s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  // multiplication
  {
    // Scalar * scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    double n = -2.;
    Scalar<double> expected = -84.;
    Scalar<double> result;
    testcode(result = s * n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar * int
    printStart(++testnum);
    Scalar<double> s = 42.;
    int n = -2;
    Scalar<double> expected = -84.;
    Scalar<double> result;
    testcode(result = s * n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> * int
    printStart(++testnum);
    Scalar<int> s = 42;
    int n = -2;
    Scalar<int> expected = -84;
    Scalar<int> result;
    testcode(result = s * n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // scalar * Scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    double n = -2.;
    Scalar<double> expected = -84.;
    Scalar<double> result;
    testcode(result = n * s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int * Scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    int n = -2;
    Scalar<double> expected = -84.;
    Scalar<double> result;
    testcode(result = n * s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int * Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 42;
    int n = -2;
    Scalar<int> expected = -84.;
    Scalar<int> result;
    testcode(result = n * s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  // division
  {
    // Scalar / scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    double n = -2.;
    Scalar<double> expected = -21.;
    Scalar<double> result;
    testcode(result = s / n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar / int
    printStart(++testnum);
    Scalar<double> s = 42.;
    int n = -2;
    Scalar<double> expected = -21.;
    Scalar<double> result;
    testcode(result = s / n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> / int
    printStart(++testnum);
    Scalar<int> s = 42;
    int n = -2;
    Scalar<int> expected = -21;
    Scalar<int> result;
    testcode(result = s / n);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // scalar / Scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    double n = -2.;
    Scalar<double> expected = -0.047619047619048;
    Scalar<double> result;
    testcode(result = n / s);
    bool pass = equal_approx(result, expected, 100 * tol); // relaxed tolerance
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int / Scalar
    printStart(++testnum);
    Scalar<double> s = 42.;
    int n = -2;
    Scalar<double> expected = -0.047619047619048;
    Scalar<double> result;
    testcode(result = n / s);
    bool pass = equal_approx(result, expected, 100 * tol); // relaxed tolerance
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int / Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 42;
    int n = -420;
    Scalar<int> expected = -10;
    Scalar<int> result;
    testcode(result = n / s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  // pow
  {
    // pow(Scalar , scalar)
    printStart(++testnum);
    Scalar<double> s = 3;
    double n = 4;
    Scalar<double> expected = 81;
    Scalar<double> result;
    testcode(result = pow(s, n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // pow(Scalar , int)
    printStart(++testnum);
    Scalar<double> s = 3;
    int n = 4;
    Scalar<double> expected = 81;
    Scalar<double> result;
    testcode(result = pow(s, n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // pow(Scalar<int> , int)
    printStart(++testnum);
    Scalar<int> s = 3;
    int n = 4;
    Scalar<int> expected = 81;
    Scalar<int> result;
    testcode(result = pow(s, n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // pow(scalar , Scalar)
    printStart(++testnum);
    Scalar<double> s = 3;
    double n = 4;
    Scalar<double> expected = 64;
    Scalar<double> result;
    testcode(result = pow(n, s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // pow(int , Scalar)
    printStart(++testnum);
    Scalar<double> s = 3;
    int n = 4;
    Scalar<double> expected = 64;
    Scalar<double> result;
    testcode(result = pow(n, s));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // pow(int , Scalar<int>)
    printStart(++testnum);
    Scalar<int> s = 3;
    int n = 4;
    Scalar<int> expected = 64;
    Scalar<int> result;
    testcode(result = pow(n, s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  //---------- Tensor-scalar mix: logic -----------------
  {
    // Scalar && scalar
    printStart(++testnum);
    Scalar<bool> s = true;
    bool b = true;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = s && b);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // scalar && Scalar
    printStart(++testnum);
    Scalar<bool> s = true;
    bool b = true;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = b && s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar || scalar
    printStart(++testnum);
    Scalar<bool> s = true;
    bool b = false;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = s || b);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // scalar || Scalar
    printStart(++testnum);
    Scalar<bool> s = true;
    bool b = false;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = b || s);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  //---------- Tensor scalar mix: relational -----------------

  {
    // Scalar == scalar
    printStart(++testnum);
    Scalar<double> s = 11.5;
    double d = 11.5;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s == d));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // scalar == Scalar
    printStart(++testnum);
    Scalar<double> s = 11.5;
    double d = 11.5;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (d == s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // Scalar == int
    printStart(++testnum);
    Scalar<double> s = 11;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s == n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int == Scalar
    printStart(++testnum);
    Scalar<double> s = 11;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (n == s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> == int
    printStart(++testnum);
    Scalar<int> s = 11;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s == n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int == Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 11;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (n == s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // Scalar != scalar
    printStart(++testnum);
    Scalar<double> s = 11.5;
    double d = 11.5;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s != d));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // scalar != Scalar
    printStart(++testnum);
    Scalar<double> s = 11.5;
    double d = 11.5;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (d != s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar != int
    printStart(++testnum);
    Scalar<double> s = 11;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s != n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int != Scalar
    printStart(++testnum);
    Scalar<double> s = 11;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (n != s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> != int
    printStart(++testnum);
    Scalar<int> s = 11;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s != n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int != Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 11;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (n != s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar >= scalar
    printStart(++testnum);
    Scalar<double> s = 12.5;
    double d = 11.5;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s >= d));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // scalar >= Scalar
    printStart(++testnum);
    Scalar<double> s = 12.5;
    double d = 11.5;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (d >= s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar >= int
    printStart(++testnum);
    Scalar<double> s = 12;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s >= n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int >= Scalar
    printStart(++testnum);
    Scalar<double> s = 12;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (n >= s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> >= int
    printStart(++testnum);
    Scalar<int> s = 12;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s >= n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int >= Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 12;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (n >= s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar > scalar
    printStart(++testnum);
    Scalar<double> s = 12.5;
    double d = 11.5;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s > d));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // scalar > Scalar
    printStart(++testnum);
    Scalar<double> s = 12.5;
    double d = 11.5;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (d > s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar > int
    printStart(++testnum);
    Scalar<double> s = 12;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s > n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int > Scalar
    printStart(++testnum);
    Scalar<double> s = 12;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (n > s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> > int
    printStart(++testnum);
    Scalar<int> s = 12;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (s > n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int > Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 12;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (n > s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // Scalar <= scalar
    printStart(++testnum);
    Scalar<double> s = 12.5;
    double d = 11.5;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s <= d));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // scalar <= Scalar
    printStart(++testnum);
    Scalar<double> s = 12.5;
    double d = 11.5;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (d <= s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar <= int
    printStart(++testnum);
    Scalar<double> s = 12;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s <= n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int <= Scalar
    printStart(++testnum);
    Scalar<double> s = 12;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (n <= s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> <= int
    printStart(++testnum);
    Scalar<int> s = 12;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s <= n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int <= Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 12;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (n <= s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // Scalar < scalar
    printStart(++testnum);
    Scalar<double> s = 12.5;
    double d = 11.5;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s < d));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // scalar < Scalar
    printStart(++testnum);
    Scalar<double> s = 12.5;
    double d = 11.5;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (d < s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar < int
    printStart(++testnum);
    Scalar<double> s = 12;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s < n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int < Scalar
    printStart(++testnum);
    Scalar<double> s = 12;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (n < s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // Scalar<int> < int
    printStart(++testnum);
    Scalar<int> s = 12;
    int n = 11;
    Scalar<bool> expected = false;
    Scalar<bool> result;
    testcode(result = (s < n));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // int < Scalar<int>
    printStart(++testnum);
    Scalar<int> s = 12;
    int n = 11;
    Scalar<bool> expected = true;
    Scalar<bool> result;
    testcode(result = (n < s));
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  printSummary(__FILE__, testnum, failnum);
  return failnum;
}
