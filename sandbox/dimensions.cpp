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

#include "vector.h"
#include "dimensions.h"


// #include "indices.h"
// #include "slices.h"
// #include "util.h"
// #include "debug.h"

// #include "multi-array-expressions.h"

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
  ECHO_CODE(Vector<double, 3> v1);
  TRDISP(v1.size());
  TRDISP(v1.is_dynamic_value);
  // TRDISP(v1.data_);
  TRDISP(v1.static_dims_array);
  TRDISP(v1);
  v1[0] = 2.2;
  TRDISP(v1);
  v1 = { 2.2, 4.4, -100.1 };
  TRDISP(v1);
  TRDISP(v1.dims());
  TRDISP(sizeof(v1)/sizeof(double));


  CR();
  ECHO_CODE(Vector<double> v2{ 3.1, 22.5, 100 });
  TRDISP(v2.size());
  TRDISP(v2.dims());
  TRDISP(v2.is_dynamic_value);
  // TRDISP(v2.data_);
  TRDISP(v2.static_dims_array);
  TRDISP(v2.resize(4));

  CR();
  ECHO_CODE(Vector<double, 3> v3{ 42.1, -2.5, 6.8 });
  TRDISP(v3.size());
  TRDISP(v3.is_dynamic_value);
  // TRDISP(v3.data_);
  TRDISP(v3.static_dims_array);
  TRDISP(v3.dims());

  CR();
  ECHO_CODE(Vector<double> v4);
  TRDISP(v4.size());
  TRDISP(v4.is_dynamic_value);
  // TRDISP(v4.data_);
  TRDISP(v4.static_dims_array);
  TRDISP(v4.dims());


  CR();
  ECHO_CODE(Dimensions<> dims);
  TRDISP(dims.is_dynamic_value);
  TRDISP(dims.rank_value);
  TRDISP(dims.static_dims_array);
  TRDISP(dims.size());
  TRDISP(dims);
  TRDISP(dims.resize(2));
  ECHO_CODE(dims[0] = 14);
  ECHO_CODE(dims[1] = 42);
  TRDISP(dims);



  CR();
  ECHO_CODE(Dimensions<> dims2);
  dims2 = { 3,2,1 };
  TRDISP(dims2);


  CR();
  ECHO_CODE(Dimensions<> dims3{ 33, 46, 77, 81 });
  TRDISP(dims3.is_dynamic_value);
  TRDISP(dims3.rank_value);
  TRDISP(dims3.static_dims_array);
  TRDISP(dims3.size());
  TRDISP(dims3);
  dims3 = { 13, 42, 56, 99 };
  TRDISP(dims3);


  CR();
  ECHO_CODE(Dimensions<> dims4 = *(new Dimensions<0>(5)));
  TRDISP(dims4);

  CR();
  ECHO_CODE(Dimensions<4> dims5{ 33, 46, 77, 81 });
  TRDISP(dims5.is_dynamic_value);
  TRDISP(dims5.rank_value);
  TRDISP(dims5.static_dims_array);
  TRDISP(dims5.size());
  TRDISP(dims5);
  dims5 = { 13, 42, 56, 99 };
  TRDISP(dims5);

  CR();
  TRDISP(sizeof(RecursiveDimensions<0>)/sizeof(size_t));
  TRDISP(sizeof(RecursiveDimensions<1>)/sizeof(size_t));
  TRDISP(sizeof(RecursiveDimensions<2>)/sizeof(size_t));
  TRDISP(sizeof(RecursiveDimensions<10>)/sizeof(size_t));


  CR();
  ECHO_CODE(RecursiveDimensions<2> ndims1);
  TRDISP(ndims1.size());
  TRDISP(ndims1);
  ndims1[0] = dims;
  ndims1[1] = dims3;
  TRDISP(ndims1);

  // ECHO_CODE(RecursiveDimensions<2> ndims2(5));  // shoudl cause compiler error

  CR();
  ECHO_CODE(RecursiveDimensions<0> ndims2(2));
  TRDISP(ndims2.size());
  TRDISP(ndims2);
  ndims2 = { dims, dims3 };
  TRDISP(ndims2);

  CR();
  ECHO_CODE(RecursiveDimensions<> ndims3{ dims, dims3 });
  TRDISP(ndims3);

  CR();
  TRDISP(v1);
  TRDISP(v1.size());
  TRDISP(v1.element_size());
  TRDISP(v1.total_size());
  TRDISP(v1.dims());
  TRDISP(v1.depth());
  TRDISP(v1.recursive_dims());
  TRDISP(v1.element_dims());


  CR();
  ECHO_CODE(Vector<Vector<double, 2>, dynamic> u2);
  TRDISP(u2);
  TRDISP(u2.size());
  TRDISP(u2.element_size());
  TRDISP(u2.total_size());
  TRDISP(u2.dims());
  TRDISP(u2.depth());
  TRDISP(u2.recursive_dims());
  TRDISP(u2.element_dims());


  CR();
  ECHO_CODE(Vector<Vector<double, 2>, 3> u);
  TRDISP(u.size());
  TRDISP(u.element_size());
  TRDISP(u.dims());
  u[0] = { 1,2 };
  u[1] = { 3,4 };
  u[2] = { 5,6 };
  TRDISP(u);
  TRDISP(u.recursive_dims());
  u = { {11,12}, {13,14}, {15,16}};
  TRDISP(u);
  TRDISP(u);
  TRDISP(u.size());
  TRDISP(u.element_size());
  TRDISP(u.el_total_size());
  TRDISP(u.total_size());
  TRDISP(u.dims());
  TRDISP(u.depth());
  TRDISP(u.recursive_dims());
  TRDISP(u.element_dims());

  // CR();
  // ECHO_CODE(Dimensions<2> dims5);
  // TRDISP(dims5.is_dynamic_value);
  // TRDISP(dims5.rank());
  // TRDISP(dims5.size());
  // TRDISP(dims5);

  // CR();
  // ECHO_CODE(Dimensions<2> dims6(5, 2));
  // TRDISP(dims6.is_dynamic_value);
  // TRDISP(dims6.rank());
  // TRDISP(dims6.size());
  // TRDISP(dims6);

  // CR();
  // ECHO_CODE(Dimensions<1> dims7(42));
  // TRDISP(dims7.is_dynamic_value);
  // TRDISP(dims7.rank());
  // TRDISP(dims7.size());
  // TRDISP(dims7);



  // CR();
  // ECHO_CODE(Dimensions<2> dims8(42, 13));
  // TRDISP(dims8.is_dynamic_value);
  // TRDISP(dims8.rank());
  // TRDISP(dims8.size());
  // TRDISP(dims8);


  // CR();
  // ECHO_CODE(Dimensions<3> dims9({ 12, 5, 81 }));
  // TRDISP(dims9.is_dynamic_value);
  // TRDISP(dims9.rank());
  // TRDISP(dims9.size());
  // TRDISP(dims9);

  // CR();
  // ECHO_CODE(RecursiveDimensions<decltype(dims9)> ndims1(dims9));
  // TRDISP(ndims1);
  // TRDISP(ndims1.rank());
  // TRDISP(ndims1.depth());

  // CR();
  // ECHO_CODE(RecursiveDimensions<decltype(dims), decltype(ndims1)> ndims2(dims, ndims1));
  // TRDISP(ndims2);
  // TRDISP(ndims2.rank());
  // TRDISP(ndims2.depth());

  return 0;
}
