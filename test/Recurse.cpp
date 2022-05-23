#define MATHQ_DEBUG 0
#include "mathq.h"
#include "test.h"



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

  //--------------------------------------------------------


  //--------------------------------------------
  // Scalar<Scalar<double>>
  //--------------------------------------------
  {
    Scalar<Scalar<double>> s{ {2.2} };
    size_type expected;
    size_type result;
    bool pass;

    // ndims()
    printStart(++testnum);
    expected = 0;
    testcode(result = s.ndims());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // dims()
    printStart(++testnum);
    Dimensions Dexpected;
    Dimensions Dresult;
    testcode(Dresult = s.dims());
    pass = (Dresult == Dexpected);
    printEnd(pass, Dresult, Dexpected);
    allpass = allpass && pass;
    failnum += (!pass);

    // isExpression()
    printStart(++testnum);
    bool bexpected = false;
    bool bresult;
    testcode(bresult = s.isExpression());
    pass = (bresult == bexpected);
    printEnd(pass, bresult, bexpected);
    allpass = allpass && pass;
    failnum += (!pass);

    // getAddresses()
    printStart(++testnum);
    VectorofPtrs pexpected;
    pexpected.add((void*)&s);
    VectorofPtrs presult;
    testcode(presult = s.getAddresses());
    pass = (presult == pexpected);
    printEnd(pass, presult, pexpected);
    allpass = allpass && pass;
    failnum += (!pass);

    // getEnum()
    printStart(++testnum);
    Tensors Eexpected = T_SCALAR;
    Tensors Eresult;
    testcode(Eresult = s.getEnum());
    pass = (Eresult == Eexpected);
    printEnd(pass, Eresult, Eexpected);
    allpass = allpass && pass;
    failnum += (!pass);

    // size()
    printStart(++testnum);
    expected = 1;
    testcode(result = s.size());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // depth()
    printStart(++testnum);
    expected = 2;
    testcode(result = s.depth());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // elsize()
    printStart(++testnum);
    expected = 1;
    testcode(result = s.elsize());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // eldeepsize()
    printStart(++testnum);
    expected = 1;
    testcode(result = s.eldeepsize());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // deepsize()
    printStart(++testnum);
    expected = 1;
    testcode(result = s.deepsize());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    printStart(++testnum);
    Scalar<Scalar<double>> s{ {2.2} };
    Scalar<double> expected{ 2.2 };
    Scalar<double> result;
    testcode(result = s());
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    printStart(++testnum);
    Scalar<Scalar<double>> s{ {2.2} };
    double expected = 2.2;
    double result;
    testcode(result = s()());
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  // {
  //   printStart(++testnum);
  //   Scalar<Scalar<double>> s1 {{2.2}};
  //   Scalar<Scalar<double>> s2 {{1.1}};
  //   Scalar<Scalar<double>> expected {{3.3}};
  //   Scalar<Scalar<double>> result;
  //   testcode( result = s1+s2 );
  //   bool pass = equal_approx(result,expected,tol);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }




  //--------------------------------------------
  // Scalar<Vector<double>>
  //--------------------------------------------

  {
    Scalar<Vector<double>> s{ {1.1, 2.2} };
    size_type expected;
    size_type result;
    bool pass;

    // ndims()
    printStart(++testnum);
    expected = 0;
    testcode(result = s.ndims());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // dims()
    printStart(++testnum);
    Dimensions Dexpected;
    Dimensions Dresult;
    testcode(Dresult = s.dims());
    pass = (Dresult == Dexpected);
    printEnd(pass, Dresult, Dexpected);
    allpass = allpass && pass;
    failnum += (!pass);

    // isExpression()
    printStart(++testnum);
    bool bexpected = false;
    bool bresult;
    testcode(bresult = s.isExpression());
    pass = (bresult == bexpected);
    printEnd(pass, bresult, bexpected);
    allpass = allpass && pass;
    failnum += (!pass);

    // getAddresses()
    printStart(++testnum);
    VectorofPtrs pexpected;
    pexpected.add((void*)&s);
    VectorofPtrs presult;
    testcode(presult = s.getAddresses());
    pass = (presult == pexpected);
    printEnd(pass, presult, pexpected);
    allpass = allpass && pass;
    failnum += (!pass);

    // getEnum()
    printStart(++testnum);
    Tensors Eexpected = T_SCALAR;
    Tensors Eresult;
    testcode(Eresult = s.getEnum());
    pass = (Eresult == Eexpected);
    printEnd(pass, Eresult, Eexpected);
    allpass = allpass && pass;
    failnum += (!pass);

    // size()
    printStart(++testnum);
    expected = 1;
    testcode(result = s.size());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // depth()
    printStart(++testnum);
    expected = 2;
    testcode(result = s.depth());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // elsize()
    printStart(++testnum);
    expected = 2;
    testcode(result = s.elsize());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // eldeepsize()
    printStart(++testnum);
    expected = 2;
    testcode(result = s.eldeepsize());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);

    // deepsize()
    printStart(++testnum);
    expected = 2;
    testcode(result = s.deepsize());
    pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    printStart(++testnum);
    Scalar<Vector<double>> s{ {1.1, 2.2} };
    Vector<double> expected{ 1.1, 2.2 };
    Vector<double> result;
    testcode(result = s());
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    printStart(++testnum);
    Scalar<Vector<double>> s{ {1.1, 2.2} };
    double expected = 2.2;
    double result;
    testcode(result = s()(1));
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    printStart(++testnum);
    Scalar<Vector<double>> s{ {1.1, 2.2} };
    double expected = 1.1;
    double result;
    testcode(result = s.dat(0));
    bool pass = (result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    printStart(++testnum);
    Scalar<Vector<double>> s{ {1.1, 2.2} };
    double expected = 2.2;
    double result;
    testcode(result = s.dat(1));
    bool pass = result == expected;
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }




  //--------------------------------------------
  // Scalar<Matrix<double>>
  //--------------------------------------------

  // {
  //   Scalar<Matrix<double>> s { {{1.1,2.2},{3.3,4.4}} };
  //   size_type expected;
  //   size_type result;
  //   bool pass;

  //   // ndims()
  //   printStart(++testnum);
  //   expected = 0;
  //   testcode( result = s.ndims() );
  //   pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);


  //   // dims()
  //   printStart(++testnum);
  //   Dimensions Dexpected;
  //   Dimensions Dresult;
  //   testcode( Dresult = s.dims() );
  //   pass = (Dresult==Dexpected);
  //   printEnd(pass,Dresult,Dexpected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // isExpression()
  //   printStart(++testnum);
  //   bool bexpected = false;
  //   bool bresult;
  //   testcode( bresult = s.isExpression() );
  //   pass = (bresult==bexpected);
  //   printEnd(pass,bresult,bexpected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // getAddresses()
  //   printStart(++testnum);
  //   VectorofPtrs pexpected;
  //   pexpected.add((void*)&s);
  //   VectorofPtrs presult;
  //   testcode( presult = s.getAddresses() );
  //   pass = (presult==pexpected);
  //   printEnd(pass,presult,pexpected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // getEnum()
  //   printStart(++testnum);
  //   Tensors Eexpected = T_SCALAR;
  //   Tensors Eresult;
  //   testcode( Eresult = s.getEnum() );
  //   pass = (Eresult==Eexpected);
  //   printEnd(pass,Eresult,Eexpected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // size()
  //   printStart(++testnum);
  //   expected = 1;
  //   testcode( result = s.size() );
  //   pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // depth()
  //   printStart(++testnum);
  //   expected = 2;
  //   testcode( result = s.depth() );
  //   pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // elsize()
  //   printStart(++testnum);
  //   expected = 4;
  //   testcode( result = s.elsize() );
  //   pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // eldeepsize()
  //   printStart(++testnum);
  //   expected = 4;
  //   testcode( result = s.eldeepsize() );
  //   pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // deepsize()
  //   printStart(++testnum);
  //   expected = 4;
  //   testcode( result = s.deepsize() );
  //   pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);

  //   // s().dims()
  //   printStart(++testnum);
  //   Dexpected = *(new Dimensions(2,2));
  //   Dresult;
  //   testcode( Dresult = s().dims() );
  //   pass = (Dresult==Dexpected);
  //   printEnd(pass,Dresult,Dexpected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   printStart(++testnum);
  //   Scalar<Matrix<double>> s { {{1.1,2.2},{3.3,4.4}}};
  //   Matrix<double> expected  {{1.1,2.2},{3.3,4.4}};
  //   Matrix<double> result;
  //   testcode( result = s() );
  //   bool pass = equal(result,expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   printStart(++testnum);
  //   Scalar<Matrix<double>> s  { {{1.1,2.2},{3.3,4.4}}};
  //   TLDISP(s());
  //   double expected = 2.2;
  //   double result;
  //   testcode( result = s()(0,1) );
  //   bool pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   printStart(++testnum);
  //   Scalar<Matrix<double>> s  { {{1.1,2.2},{3.3,4.4}}};
  //   double expected = 1.1;
  //   double result;
  //   testcode( result = s[0] );
  //   bool pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }
  // {
  //   printStart(++testnum);
  //   Scalar<Matrix<double>> s  { {{1.1,2.2},{3.3,4.4}}};
  //   double expected = 2.2;
  //   double result;
  //   testcode( result = s[1] );
  //   bool pass = (result==expected);
  //   printEnd(pass,result,expected);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }



  //--------------------------------------------------------
  printSummary(__FILE__, testnum, failnum);
  return failnum;
}
