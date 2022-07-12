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

// #include "indices.h"
// #include "slices.h"
// #include "util.h"
// #include "debug.h"

#include "expression-r.h"
#include "expression-rw.h"
#include "vector.h"
#include "dimensions.h"


// #include "multi-array.h"
// #include "multi-array-constant.h"
// #include "multi-array-repeat-vec.h"
// #include "multi-array-outer-product.h"

// #include "scalar.h"
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

#include "expressions-r.h"
// #include "expressions-rw.h"

#include "fun_unary_AUTO.h"
#include "fun_binary_AUTO.h"
#include "fun_ternary_AUTO.h"
#include "functions_misc.h"
// #include "grids.h"
// #include "functions_structure.h"
// #include "functions_products.h"
// #include "functions_user.h"

// #include "fileio.h"
// #include "coda.h"



int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;


  CR();
  ECHO_CODE(Vector<double> v2{ 3.1, 22.5, 100 });
  TRDISP(v2);

  CR();
  ECHO_CODE(Vector<double, 3> v3{ 42.1, -2.5, 6.8 });
  TRDISP(v3);

  TRDISP(-v3);
  TRDISP(exp(v3));
  TRDISP(v2+v3);
  TRDISP(std::sph_legendre(3, 0, 1.2345));
  TRDISP(sph_legendre(2, 1, v3));

  Vector<double> J0Coeffs = Vector<double>({ 1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0. });
  Vector<double> r = linspace<double>(0, 10, 101);
  TRDISP(taylor(J0Coeffs, r, 19));

  return 0;
}
