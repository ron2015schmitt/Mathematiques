
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
#include "math_real.h"
#include "math_cplx.h"
#include "math_imag.h"
#include "math_quaternion.h"
#include "display.h"
// #include "slices.h"
// #include "util.h"

// #include "multiarrays.h"
// #include "debug.h"
// #include "scalar.h"
// #include "vector.h"

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

// #include "multi-array.h"

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
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  cout << "IsMultiArrayOrExpression" << std::endl;
  cout << "double: " << IsMultiArrayOrExpression<double>::value << "\n";
  cout << "Vector: " << IsMultiArrayOrExpression<Vector<double>>::value << "\n";
  cout << "MArrayExpR: " << IsMultiArrayOrExpression<MArrayExpR<Vector<double>, double, double, 1, 1, NullDims>>::value << "\n";
  cout << "MArrayExpRW: " << IsMultiArrayOrExpression<MArrayExpRW<Vector<double>, double, double, 1, 1, NullDims>>::value << "\n";
  cout << std::endl;

  cout << "IsMultiArray" << std::endl;
  cout << "double: " << IsMultiArray<double>::value << "\n";
  cout << "Vector: " << IsMultiArray<Vector<double>>::value << "\n";
  cout << "MArrayExpR: " << IsMultiArray<MArrayExpR<Vector<double>, double, double, 1, 1, NullDims>>::value << "\n";
  cout << std::endl;

  cout << "IsMultiArrayExp" << std::endl;
  cout << "double: " << IsMultiArrayExp<double>::value << "\n";
  cout << "Vector: " << IsMultiArrayExp<Vector<double>>::value << "\n";
  cout << "MArrayExpR: " << IsMultiArrayExp<MArrayExpR<Vector<double>, double, double, 1, 1, NullDims>>::value << "\n";
  cout << "MArrayExpRW: " << IsMultiArrayExp<MArrayExpRW<Vector<double>, double, double, 1, 1, NullDims>>::value << "\n";
  cout << std::endl;

  cout << "IsMultiArrayExpRW" << std::endl;
  cout << "double: " << IsMultiArrayExpRW<double>::value << "\n";
  cout << "Vector: " << IsMultiArrayExpRW<Vector<double>>::value << "\n";
  cout << "MArrayExpR: " << IsMultiArrayExpRW<MArrayExpR<Vector<double>, double, double, 1, 1, NullDims>>::value << "\n";
  cout << "MArrayExpRW: " << IsMultiArrayExpRW<MArrayExpRW<Vector<double>, double, double, 1, 1, NullDims>>::value << "\n";
  cout << std::endl;


  cout << "NumberTrait" << std::endl;
  // TRDISP(NumberTrait<NullType>::Type());    // causes compile error
  TRDISP(NumberTrait<int>::Type());
  TRDISP(NumberTrait<double>::Type());
  TRDISP(NumberTrait<std::complex<double>>::Type());
  // TRDISP(NumberTrait<std::complex<Vector<bool>>>::Type());
  typename NumberTrait<Vector<double>>::Type x;
  TRDISP(NumberTrait<Vector<double,1>,double>::Type());
  TRDISP(NumberTrait<Vector<std::complex<double>>>::Type());
  TRDISP(NumberTrait<MArrayExpR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1, NullDims>>::Type());
  TRDISP(NumberTrait<MArrayExpRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1, NullDims>>::Type());
  cout << std::endl;

  cout << "NumberTrait" << std::endl;
  // TRDISP(NumberTrait<NullType>::depth());    // causes compile error
  DISP(NumberTrait<int>::depth());
  DISP(NumberTrait<double>::depth());
  DISP(NumberTrait<std::complex<double>>::depth());
  // DISP(NumberTrait<std::complex<Vector<bool>>>::depth());
  DISP(NumberTrait<Vector<double>>::depth());
  DISP(NumberTrait<Vector<std::complex<double>>>::depth());
  DISP(NumberTrait<MArrayExpR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1, NullDims>>::depth());
  DISP(NumberTrait<MArrayExpRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1, NullDims>>::depth());
  cout << std::endl;


  cout << "SimpleNumberTrait" << std::endl;
  // TRDISP(SimpleNumberTrait<NullType>::Type());    // causes compile error
  TRDISP(SimpleNumberTrait<int>::Type());
  TRDISP(SimpleNumberTrait<double>::Type());
  TRDISP(SimpleNumberTrait<std::complex<double>>::Type());
  TRDISP(SimpleNumberTrait<std::complex<Vector<bool>>>::Type());
  TRDISP(SimpleNumberTrait<Vector<double>>::Type());
  TRDISP(SimpleNumberTrait<Vector<std::complex<double>>>::Type());
  TRDISP(SimpleNumberTrait<MArrayExpR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1, NullDims>>::Type());
  TRDISP(SimpleNumberTrait<MArrayExpRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1, NullDims>>::Type());
  cout << std::endl;

  cout << "SimpleNumberTrait" << std::endl;
  // TRDISP(SimpleNumberTrait<NullType>::depth());    // causes compile error
  DISP(SimpleNumberTrait<int>::depth());
  DISP(SimpleNumberTrait<double>::depth());
  DISP(SimpleNumberTrait<std::complex<double>>::depth());
  DISP(SimpleNumberTrait<std::complex<Vector<bool>>>::depth());
  DISP(SimpleNumberTrait<Vector<double>>::depth());
  DISP(SimpleNumberTrait<Vector<std::complex<double>>>::depth());
  DISP(SimpleNumberTrait<MArrayExpR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1, NullDims>>::depth());
  DISP(SimpleNumberTrait<MArrayExpRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1, NullDims>>::depth());
  cout << std::endl;


  return 0;
}
