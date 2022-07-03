#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <fstream>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stdarg.h>
#include <string>
#include <type_traits> 
#include <typeinfo>
#include <valarray>
#include <vector>


#include "version_mathq.h"  // auto generated

#include "declarations.h"
#include "type-traits.h"
#include "display.h"

#include "type-defs.h"

#include "math_real.h"
#include "math_cplx.h"
#include "math_imag.h"
#include "math_quaternion.h"

#include "indices.h"
#include "dimensions.h"
#include "slices.h"
#include "util.h"
#include "debug.h"

// #include "multi-array-expressions.h"

// #include "multi-array.h"
// #include "multi-array-constant.h"
// #include "multi-array-repeat-vec.h"
// #include "multi-array-outer-product.h"

// #include "scalar.h"
// #include "vector.h"
// #include "vector-constant.h"

// #include "matrix.h"
// #include "matrix_constdiag.h"
// #include "matrix_diagonal.h"
// #include "matrix_exchange.h"
// #include "matrix_hermitian.h"
// #include "matrix_identity.h"
// #include "matrix_lowertriangle.h"
// #include "matrix_revdiag.h"
// #include "matrix_repcol.h"
// #include "matrix_reprow.h"
// #include "matrix_rep.h"
// #include "matrix_skewhermitian.h"
// #include "matrix_skewsymmetric.h"
// #include "matrix_symmetric.h"
// #include "matrix_toeplitz.h"
// #include "matrix_uppertriangle.h"
// #include "matrix_vandermonde.h"
// #include "matrix_zero.h"
// #include "matrix-constant.h"
// #include "matrix-repeat-vec.h"
// #include "matrix-outer-product.h"

// #include "multi-array3.h"
// #include "multi-array4.h"

// #include "expressionsR.h"
// #include "expressionsRW.h"

// #include "fun_unary_AUTO.h"
// #include "fun_binary_AUTO.h"
// #include "fun_ternary_AUTO.h"
// #include "functions_misc.h"
// #include "functions_structure.h"
// #include "functions_products.h"
// #include "functions_user.h"

// #include "fileio.h"
// #include "coda.h"

int main(int argc, char* argv[]) {
  // using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  std::cout << std::endl;
  std::cout << "running: " <<myname << std::endl;
  std::cout << std::endl;


  CR();
  TRDISP(roundzero(float(0.001)));
  TRDISP(float(3e-7));
  TRDISP(roundzero(float(3e-7)));

  CR();
  TRDISP(roundzero(double(0.001)));
  TRDISP(double(1e-16));
  TRDISP(roundzero(double(1e-16)));

  CR();
  TRDISP(roundzero(quad(0.001)));
  TRDISP(quad(1e-30));
  TRDISP(roundzero(quad(1e-30)));

  CR();
  TRDISP(zero<int>());
  TRDISP(zero<double>());
  TRDISP(zero<quad>());

  CR();
  TRDISP(one<int>());
  TRDISP(one<double>());
  TRDISP(one<quad>());

  int ii = 42;
  double dub = 3.14;
  int nii = -13;
  double ndub = -2.73;

  CR();
  TRDISP(mathq::conj(ii));
  TRDISP(mathq::conj(dub));


  CR();
  TRDISP(mathq::real(ii));
  TRDISP(mathq::real(dub));

  CR();
  TRDISP(mathq::imag(ii));
  TRDISP(mathq::imag(dub));

  CR();
  TRDISP(mathq::sqr(ii));
  TRDISP(mathq::sqr(dub));

  CR();
  TRDISP(mathq::cube(ii));
  TRDISP(mathq::cube(dub));

  CR();
  TRDISP(mathq::logN(ii, 5));
  TRDISP(mathq::logN(dub, 5));

  CR();
  TRDISP(mathq::normsqr(ii));
  TRDISP(mathq::normsqr(dub));
  TRDISP(mathq::normsqr(nii));
  TRDISP(mathq::normsqr(ndub));

  CR();
  TRDISP(mathq::sgn(ii));
  TRDISP(mathq::sgn(dub));
  TRDISP(mathq::sgn(nii));
  TRDISP(mathq::sgn(ndub));

  CR();
  TRDISP(mathq::approx(ii, ii+1));
  TRDISP(mathq::approx(dub, dub+1e-16));
  TRDISP(mathq::approx(dub, dub+5e-16));


  return 0;
}
