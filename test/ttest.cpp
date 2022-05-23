
#define MATHQ_DEBUG 0
#include "mathq.h"
#include "test.h"

int main() {

  using namespace mathq;
  using namespace display;

  print_mathq_info();
  MOUT << CREATESTYLE(BOLD + MAGENTA1).apply(__FILE__) << " - tensor tests" << std::endl;
  CR();
  CR();

  bool allpass = true;
  int testnum = 0;
  int failnum = 0;
  double tol = 5e-16;

  // TODO: add a test for every function and functionality
  //       check math with matlab or mathematica

  {
    // tensor + tensor

    printStart(++testnum);
    Dimensions dims(2, 3, 4);
    Tensor<int> t1(dims);
    int c = 0;
    for (index_type i = 0; i < t1.dims()[0]; i++) {
      for (index_type j = 0; j < t1.dims()[1]; j++) {
        for (index_type k = 0; k < t1.dims()[2]; k++) {
          t1(i, j, k) = 100 + c++;
        }
      }
    }
    Tensor<int> t2(dims);
    c = 0;
    for (index_type i = 0; i < t2.dims()[0]; i++) {
      for (index_type j = 0; j < t2.dims()[1]; j++) {
        for (index_type k = 0; k < t2.dims()[2]; k++) {
          t2(i, j, k) = -100 + 9 * c++;
        }
      }
    }
    TLDISP(t2);
    int A[24] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230 };
    Tensor<int> expected(dims);
    expected = A;
    Tensor<int> result(dims);
    testcode(result = t1 + t2);
    bool pass = equal(result, expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  //-------------------conjugate----------------------------

  {
    // conj(z)
    using namespace std;
    printStart(++testnum);
    Dimensions dims(2, 3);

    Tensor<complex<double>> z(dims);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    z[2] = complex<double>(5, -8);
    z[3] = complex<double>(4, -5.6);
    z[4] = complex<double>(-1, 2.122);
    z[5] = complex<double>(-1.5, -88);
    Tensor<complex<double>> expected(dims);
    expected[0] = complex<double>(1, -2);
    expected[1] = complex<double>(-1.5, -26.7);
    expected[2] = complex<double>(5, 8);
    expected[3] = complex<double>(4, 5.6);
    expected[4] = complex<double>(-1, -2.122);
    expected[5] = complex<double>(-1.5, 88);
    Tensor<complex<double>> result;
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
    Dimensions dims(2, 3);

    Tensor<complex<double>> z(dims);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    z[2] = complex<double>(5, -8);
    z[3] = complex<double>(4, -5.6);
    z[4] = complex<double>(-1, 2.122);
    z[5] = complex<double>(-1.5, -88);
    Tensor<complex<double>> expected(dims);
    expected[0] = complex<double>(1, -2);
    expected[1] = complex<double>(-1.5, -26.7);
    expected[2] = complex<double>(5, 8);
    expected[3] = complex<double>(4, 5.6);
    expected[4] = complex<double>(-1, -2.122);
    expected[5] = complex<double>(-1.5, 88);
    Tensor<complex<double>> result;
    testcode(result = z.conj());
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // x.conj() -- does not exist

  //-------------------transpose----------------------------

  {
    // transpose(x)
    using namespace std;
    printStart(++testnum);
    Dimensions dims(2, 2, 2);
    Tensor<double> x(dims);
    x[0] = 0;
    x[1] = 1;
    x[2] = 2;
    x[3] = 3;
    x[4] = 4;
    x[5] = 5;
    x[6] = 6;
    x[7] = 7;
    Tensor<double> expected(dims);
    expected[0] = 0;
    expected[1] = 4;
    expected[2] = 2;
    expected[3] = 6;
    expected[4] = 1;
    expected[5] = 5;
    expected[6] = 3;
    expected[7] = 7;
    Tensor<double> result;
    testcode(result = transpose(x));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // transpose(z)
    using namespace std;
    printStart(++testnum);
    Dimensions dims(2, 2, 2);

    Tensor<complex<double>> z(dims);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    z[2] = complex<double>(5, -8);
    z[3] = complex<double>(4, -5.6);
    z[4] = complex<double>(-1, 2.122);
    z[5] = complex<double>(-1.5, -88);
    z[6] = complex<double>(4.3, 1.1);
    z[7] = complex<double>(2.2, -7);
    Tensor<complex<double>> expected(dims);
    expected[0] = complex<double>(1, 2);
    expected[1] = complex<double>(-1, 2.122);
    expected[2] = complex<double>(5, -8);
    expected[3] = complex<double>(4.3, 1.1);
    expected[4] = complex<double>(-1.5, 26.7);
    expected[5] = complex<double>(-1.5, -88);
    expected[6] = complex<double>(4, -5.6);
    expected[7] = complex<double>(2.2, -7);
    Tensor<complex<double>> result;
    testcode(result = transpose(z));
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // adjoint(z)
    using namespace std;
    printStart(++testnum);
    Dimensions dims(2, 2, 2);

    Tensor<complex<double>> z(dims);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    z[2] = complex<double>(5, -8);
    z[3] = complex<double>(4, -5.6);
    z[4] = complex<double>(-1, 2.122);
    z[5] = complex<double>(-1.5, -88);
    z[6] = complex<double>(4.3, 1.1);
    z[7] = complex<double>(2.2, -7);
    Tensor<complex<double>> expected(dims);
    expected[0] = complex<double>(1, -2);
    expected[1] = complex<double>(-1, -2.122);
    expected[2] = complex<double>(5, 8);
    expected[3] = complex<double>(4.3, -1.1);
    expected[4] = complex<double>(-1.5, -26.7);
    expected[5] = complex<double>(-1.5, 88);
    expected[6] = complex<double>(4, 5.6);
    expected[7] = complex<double>(2.2, 7);
    Tensor<complex<double>> result;
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
    Dimensions dims(2, 2, 2);

    Tensor<complex<double>> z(dims);
    z[0] = complex<double>(1, 2);
    z[1] = complex<double>(-1.5, 26.7);
    z[2] = complex<double>(5, -8);
    z[3] = complex<double>(4, -5.6);
    z[4] = complex<double>(-1, 2.122);
    z[5] = complex<double>(-1.5, -88);
    z[6] = complex<double>(4.3, 1.1);
    z[7] = complex<double>(2.2, -7);
    Tensor<complex<double>> expected(dims);
    expected[0] = complex<double>(1, -2);
    expected[1] = complex<double>(-1, -2.122);
    expected[2] = complex<double>(5, 8);
    expected[3] = complex<double>(4.3, -1.1);
    expected[4] = complex<double>(-1.5, -26.7);
    expected[5] = complex<double>(-1.5, 88);
    expected[6] = complex<double>(4, 5.6);
    expected[7] = complex<double>(2.2, 7);
    Tensor<complex<double>> result;
    testcode(result = ~z);
    bool pass = alltrue(result == expected);
    printEnd(pass, result, expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  printSummary(__FILE__, testnum, failnum);
  return failnum;
}
