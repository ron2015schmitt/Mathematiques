#define MATHQ_DEBUG 0
#include "mathq.h"
#include "test.h"


int main() {

  using namespace mathq;
  using namespace display;

  print_mathq_info();
  MOUT << CREATESTYLE(BOLD + MAGENTA1).apply(__FILE__) << " - vector tests" << std::endl;
  CR();
  CR();
  bool allpass = true;
  int testnum = 0;
  int failnum = 0;
  double tol = 5e-16;

  // TODO: add a test for every function and functionality
  //       check math with matlab or mathematica


  {
    // vector + vector

    printStart(++testnum);
    Vector<int> v1 = { 10, 20, 30, 40 };
    Vector<int> v2 = { -1, -2, -3, -4 };
    Vector<int> expected = { 9, 18, 27, 36 };
    Vector<int> result;
    TLDISP(v1);
    TLDISP(v2);
    result = v1 + v2;
    TLDISP(result);
    testcode(result = v1 + v2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // vector - vector

    printStart(++testnum);
    Vector<int> v1 = { 10, 20, 30, 40 };
    Vector<int> v2 = { -1, -2, -3, -4 };
    Vector<int> expected = { 11, 22, 33, 44 };
    Vector<int> result;
    testcode(result = v1 - v2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // vector * vector

    printStart(++testnum);
    Vector<int> v1 = { 10, 20, 30, 40 };
    Vector<int> v2 = { -1, -2, 3, 0 };
    Vector<int> expected = { -10, -40, 90, 0 };
    Vector<int> result;
    testcode(result = v1 * v2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // vector / vector

    printStart(++testnum);
    Vector<int> v1 = { 10, 20, 30, 40 };
    Vector<int> v2 = { -1, -2, 3, 10 };
    Vector<int> expected = { -10, -10, 10, 4 };
    Vector<int> result;
    testcode(result = v1 / v2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  {
    // Test of a large vector math expression

    printStart(++testnum);
    Vector<double> v1 = { 10., 20., 30., 40. };
    Vector<double> v2 = { -1, -2, -3, -4 };
    Vector<double> expected = { 10, 13, 18, 25 };
    Vector<double> result;
    testcode(result = 2 * log10(abs(v1 / v2) * 100) + 3 + pow(-v2, 2));
    bool pass = equal_approx(result, expected, tol);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  //-------------------COMPLEX NUMBERS----------------------------

  {
    // conj(z)
    using namespace std;
    printStart(++testnum);
    Vector<complex<double>> z(2);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    Vector<complex<double>> expected(2);
    expected[0] = complex<double>(1, -2);
    expected[1] = complex<double>(-1.5, -26.7);
    Vector<complex<double>> result;
    testcode(result = conj(z));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // ~z
    using namespace std;
    printStart(++testnum);
    Vector<complex<double>> z(2);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    Vector<complex<double>> expected(2);
    expected[0] = complex<double>(1, -2);
    expected[1] = complex<double>(-1.5, -26.7);
    Vector<complex<double>> result;
    testcode(result = ~z);
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // z.conj()
    using namespace std;
    printStart(++testnum);
    Vector<complex<double>> z(2);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    Vector<complex<double>> expected(2);
    expected[0] = complex<double>(1, -2);
    expected[1] = complex<double>(-1.5, -26.7);
    Vector<complex<double>> result;
    testcode(result = z.conj());
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // x.conj()  -- does not exist
    // using namespace std;
    // printStart(++testnum);
    // Vector<double> x(2);
    // x[0] = 3.14;
    // x[1] = -45;
    // Vector<ComplexDouble> expected({ComplexDouble(3.14,0), ComplexDouble(-45,0) });
    // expected[0] = 3.14;
    // expected[1] = -45;
    // Vector<ComplexDouble> result;
    // testcode( result = x.conj() );
    // bool pass = alltrue(result==expected);
    // printEnd(pass,result,expected);
    // allpass = allpass && pass;
    // failnum += (!pass);
  }




  // ----------------- transpose-----------------------------

  {
    // transpose(z)
    using namespace std;
    printStart(++testnum);
    Vector<complex<double>> z(2);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    Vector<complex<double>> expected(2);
    expected[0] = complex<double>(1, 2);
    expected[1] = complex<double>(-1.5, 26.7);
    Vector<complex<double>> result;
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
    Vector<double> x(2);
    x[0] = 3.14;
    x[1] = -45;
    Vector<double> expected(2);
    expected[0] = 3.14;
    expected[1] = -45;
    Vector<double> result;
    testcode(result = transpose(x));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  //-------------------adjoint ---------------------
  {
    // adjoint(z)
    using namespace std;
    printStart(++testnum);
    Vector<complex<double>> z(2);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    Vector<complex<double>> expected(2);
    expected[0] = complex<double>(1, -2);
    expected[1] = complex<double>(-1.5, -26.7);
    Vector<complex<double>> result;
    testcode(result = adjoint(z));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  printSummary(__FILE__, testnum, failnum);
  return failnum;
}
