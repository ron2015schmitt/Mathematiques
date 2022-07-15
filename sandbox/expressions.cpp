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
// #include "fileio.h"
// #include "util.h"
// #include "debug.h"

#include "type-defs.h"

#include "math_real.h"
#include "math_cplx.h"
#include "math_imag.h"
#include "math_quaternion.h"

#include "indices.h"
// #include "slices.h"

#include "expression-r.h"
#include "expression-rw.h"

#include "vector.h"
#include "dimensions.h"
#include "multi-array-fixed.h"
#include "multi-array-dynamic.h"
// #include "scalar.h"
// #include "matrix.h"
// #include "multi-array3.h"
// #include "multi-array4.h"

// #include "vector-constant.h"
// #include "vector-sparse.h"

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
// #include "matrix_sparse.h"
// #include "matrix_symmetric.h"
// #include "matrix_toeplitz.h"
// #include "matrix_uppertriangle.h"
// #include "matrix_vandermonde.h"
// #include "matrix_zero.h"
// #include "matrix-constant.h"
// #include "matrix-repeat-vec.h"
// #include "matrix-outer-product.h"

// #include "multi-array3-constant.h"
// #include "multi-array3-repeat-vec.h"
// #include "multi-array3-outer-product.h"

// #include "multi-array4-constant.h"
// #include "multi-array4-repeat-vec.h"
// #include "multi-array5-outer-product.h"

// #include "multi-array-constant.h"
// #include "multi-array-repeat-vec.h"
// #include "multi-array-outer-product.h"


#include "expressions-r.h"
#include "expressions-rw.h"

#include "fun_unary_AUTO.h"
#include "fun_binary_AUTO.h"
#include "fun_ternary_AUTO.h"
#include "functions_misc.h"
#include "functions_structure.h"
#include "functions_products.h"
#include "functions_user.h"
// #include "grids.h"

// #include "coda.h"



template <typename Element, size_t rank, size_t... dims > requires (rank < 100)
class Test;


template <typename Element, size_t rank, size_t... dims > requires (rank < 100)
class Test {
public:
  Test() {
    using namespace mathq;
    using namespace display;
    OUTPUT("\nInside main Test constructor");
    TRDISP(rank);
  }
};

template <typename Element, size_t rank> requires (rank < 100)
class Test<Element, rank> {
public:
  Test() {
    using namespace mathq;
    using namespace display;
    OUTPUT("\nInside specialization Test constructor");
    TRDISP(rank);
  }
};



template <typename Element, size_t rank, size_t... dims > requires (!mathq::check_dynamic<rank,dims...>())
class Test2 {
public:
  Test2() {
    using namespace mathq;
    using namespace display;
    OUTPUT("\nInside main Test2 constructor");
    TRDISP(rank);
  }
};




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


  const size_t N = 20;
  Vector<double> k = range<double>(0, N-1);
  Vector<double> An = 1/k;
  An[0] = 0.;
  Vector<double> Bn = Vector<double>(N, 0.);
  const double pi = 3.14159265358979323846;
  Vector<double> t = linspace<double>(0, 2*pi, 51);
  const double T = 2*pi;
  const double omega = 2*pi/T;
  TRDISP(ifourier(An, Bn, t, An.size(), omega));

  TRDISP(k);
  TRDISP(transpose(k));

  TRDISP(join(k, k));

  TRDISP(rep(k, 3));


  CR();
  ECHO_CODE(Vector<double> v1a);
  TRDISP(v1a.classname());  // Vector

  CR();
  ECHO_CODE(Vector<double, 0> v1b);
  TRDISP(v1b.classname());  // Vector

  CR();
  ECHO_CODE(Vector<double, 5> v1c);
  TRDISP(v1c.classname());  // Vector

  CR();
  CR();
  OUTPUT("The following MultiArrays should use the Vector specialization");
  CR();
  ECHO_CODE(MultiArray<double, 1, dynamic> x1a);
  TRDISP(x1a.classname());  // Vector

  CR();
  ECHO_CODE(MultiArray<double, 1, 5> x1b);
  TRDISP(x1b.classname());  // Vector


  CR();
  CR();
  OUTPUT("Dynamic MultiArray");

  ECHO_CODE(MultiArray<double, 2, dynamic> x2);
  TRDISP(x2.classname());
  TRDISP(x2.is_dynamic_value);
  TRDISP(x2.compile_time_size);
  TRDISP(x2.dims_array());
  TRDISP(x2.rank());
  TRDISP(x2.depth());
  TRDISP(x2.dims());

  // TRDISP(x2.size());
  // TRDISP(x2.data_);
  // TRDISP(sizeof(x2.data_)/sizeof(double));
  // TRDISP(sizeof(x2)/sizeof(double));

  // ECHO_CODE(x2.resize(6));
  // TRDISP(x2.size());
  // TRDISP(x2.data_);
  // TRDISP(sizeof(x2.data_)/sizeof(double));
  // TRDISP(sizeof(x2)/sizeof(double));

  CR();
  CR();
  OUTPUT("Static MultiArray");

  CR();
  ECHO_CODE(MultiArray<double, 2, 3, 2> x3);
  TRDISP(x3.classname());
  TRDISP(x3.is_dynamic_value);
  TRDISP(x3.compile_time_size);
  TRDISP(x3.static_dims_array);
  TRDISP(x3.size());
  TRDISP(x3.rank());
  TRDISP(x3.depth());
  TRDISP(x3.dims_array());
  // TRDISP(x3.dims());
  TRDISP(x3.data_);
  TRDISP(sizeof(x3.data_)/sizeof(double));
  TRDISP(sizeof(x3)/sizeof(double));

  // CR();
  // ECHO_CODE(MultiArray<double,2> x2(1,2));
  // TRDISP(x1);

  // Test<double,1> test1;
  // Test<double,1,2,3> test2;
  // Test<double,1,0> test3;

  // Test2<double,1, 2> foo1;
  // Test2<double,3, 2,4,12> foo2;
  // Test2<double,3, 0,4,12> foo3;


  return 0;
}
