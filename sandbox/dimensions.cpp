
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
// #include "math_real.h"
// #include "math_cplx.h"
// #include "math_imag.h"
// #include "math_quaternion.h"
// #include "display.h"
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


  CR();
  ECHO_CODE(FixedDims<1, 4, 2> dims);
  TRDISP(dims.is_dynamic());
  TRDISP(dims.rank());
  TRDISP(dims.data);
  TRDISP(dims.data[1]);
  TRDISP(dims.datasize());
  TRDISP(dims);

  // dims.data[1] = 42;  // should cause compile error
  // dims[1] = 42;  // should cause compile error



  CR();
  ECHO_CODE(DynamicDims<1> dims2);
  TRDISP(dims2.is_dynamic());
  TRDISP(dims2.rank());
  TRDISP(dims2.datasize());
  TRDISP(dims2);

  ECHO_CODE(dims2.data[0] = 42);
  TRDISP(dims2);
  ECHO_CODE(dims2[0] = 101);
  TRDISP(dims2);
  ECHO_CODE(std::array<size_t, 1> a = std::array<size_t, 1>{56});
  TRDISP(a);
  ECHO_CODE(dims2.data = a);
  TRDISP(dims2.datasize());
  TRDISP(dims2);


  CR();
  ECHO_CODE(DynamicDims<2> dims3);
  TRDISP(dims3.is_dynamic());
  TRDISP(dims3.rank());
  TRDISP(dims3.datasize());
  TRDISP(dims3);

  CR();
  ECHO_CODE(DynamicDims<3> dims4);
  TRDISP(dims4.is_dynamic());
  TRDISP(dims4.rank());
  TRDISP(dims4.datasize());
  TRDISP(dims4);


  CR();
  ECHO_CODE(DynamicDims<2> dims5);
  TRDISP(dims5.is_dynamic());
  TRDISP(dims5.rank());
  TRDISP(dims5.datasize());
  TRDISP(dims5);

  CR();
  ECHO_CODE(DynamicDims<2> dims6(5, 2));
  TRDISP(dims6.is_dynamic());
  TRDISP(dims6.rank());
  TRDISP(dims6.datasize());
  TRDISP(dims6);

  CR();
  ECHO_CODE(DynamicDims<1> dims7(42));
  TRDISP(dims7.is_dynamic());
  TRDISP(dims7.rank());
  TRDISP(dims7.datasize());
  TRDISP(dims7);



  CR();
  ECHO_CODE(DynamicDims<2> dims8(42, 13));
  TRDISP(dims8.is_dynamic());
  TRDISP(dims8.rank());
  TRDISP(dims8.datasize());
  TRDISP(dims8);


  CR();
  ECHO_CODE(DynamicDims<3> dims9({ 12, 5, 81 }));
  TRDISP(dims9.is_dynamic());
  TRDISP(dims9.rank());
  TRDISP(dims9.datasize());
  TRDISP(dims9);

  CR();
  ECHO_CODE(NestedDims<decltype(dims9)> ndims1(dims9));
  TRDISP(ndims1);
  TRDISP(ndims1.rank());
  TRDISP(ndims1.depth());

  CR();
  ECHO_CODE(NestedDims<decltype(dims), decltype(ndims1)> ndims2(dims, ndims1));
  TRDISP(ndims2);
  TRDISP(ndims2.rank());
  TRDISP(ndims2.depth());

  return 0;
}
