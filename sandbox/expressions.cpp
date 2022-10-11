#include "mathq.h"



template <typename Element, size_t rank, size_t... dims > requires (rank < 100)
  class Test;


template <typename Element, size_t rank, size_t... dims > requires (rank < 100)
  class Test {
  public:
    Test() {
      using namespace mathq;
      using namespace display;
      OUTPUT("\nInside main Test constructor");
      ETV(rank);
    }
};

template <typename Element, size_t rank> requires (rank < 100)
  class Test<Element, rank> {
  public:
    Test() {
      using namespace mathq;
      using namespace display;
      OUTPUT("\nInside specialization Test constructor");
      ETV(rank);
    }
};



template <typename Element, size_t rank, size_t... dims > requires (!mathq::check_dynamic<rank, dims...>())
class Test2 {
public:
  Test2() {
    using namespace mathq;
    using namespace display;
    OUTPUT("\nInside main Test2 constructor");
    ETV(rank);
  }
};




int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  Test<double, 1> test1;
  Test<double, 1, 2, 3> test2;
  Test<double, 1, 0> test3;

  Test2<double, 1, 2> foo1;
  Test2<double, 3, 2, 4, 12> foo2;
  // Test2<double,3, 0,4,12> foo3;  // FAILS check_dynamic

  ETV(std::array<size_t, 0>{});
  ETV(NumberTrait<MultiArray<double, 2>>::depth());
  ETV(std::valarray<size_t>{});
  ETV(NumberTrait<double>::sum_of_ranks());
  ETV(NumberTrait<double>::get_rank_array());
  ETV(NumberTrait<MultiArray<double, 2>>::sum_of_ranks());
  ETV(NumberTrait<MultiArray<double, 2>>::get_rank_array());
  ETV(NumberTrait<MultiArray<MultiArray<double, 3, 1, 2, 3>, 4, 3, 2, 1, 1>>::sum_of_ranks());
  ETV(NumberTrait<MultiArray<MultiArray<double, 3, 1, 2, 3>, 4, 3, 2, 1, 1>>::get_rank_array());


  CR();
  ECHO(Vector<double> v2{ 3.1, 22.5, 100 });
  ETV(v2);

  CR();
  ECHO(Vector<double, 3> v3{ 42.1, -2.5, 6.8 });
  ETV(v3);

  ETV(-v3);
  ETV(exp(v3));
  ETV(v2+v3);
  ETV(std::sph_legendre(3, 0, 1.2345));
  ETV(sph_legendre(2, 1, v3));

  Vector<double> J0Coeffs = Vector<double>({ 1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0. });
  Vector<double> r = linspace<double>(0, 10, 101);
  ETV(taylor(J0Coeffs, r, 19));


  const size_t N = 20;
  Vector<double> k = range<double>(0, N-1);
  Vector<double> An = 1/k;
  An[0] = 0.;
  Vector<double> Bn = Vector<double>(N, 0.);
  const double pi = 3.14159265358979323846;
  Vector<double> t = linspace<double>(0, 2*pi, 51);
  const double T = 2*pi;
  const double omega = 2*pi/T;
  ETV(ifourier(An, Bn, t, An.size(), omega));

  ETV(k);
  ETV(transpose(k));

  ETV(join(k, k));

  ETV(rep(k, 3));


  CR();
  ECHO(Vector<double> v1a);
  ETV(v1a.classname());  // Vector

  CR();
  ECHO(Vector<double> v1b);
  ETV(v1b.classname());  // Vector

  CR();
  ECHO(Vector<double, 5> v1c);
  ETV(v1c.classname());  // Vector

  CR();
  CR();
  OUTPUT("The following MultiArrays should use the Vector specialization");
  CR();
  ECHO(MultiArray<double, 1> x1a);
  ETV(x1a.classname());  // Vector

  CR();
  ECHO(MultiArray<double, 1, 5> x1b);
  ETV(x1b.classname());  // Vector


  CR();
  CR();
  OUTPUT("Dynamic MultiArray");

  ECHO(MultiArray<double, 2> x2);
  ETV(x2.classname());
  ETV(x2.is_dynamic_value);
  ETV(x2.compile_time_size);
  ETV(x2.static_dims_array);
  ETV(std::get<0>(x2.static_dims_array));
  // ETV(x2.dims_array());
  ETV(x2.rank());
  ETV(x2.depth());
  ETV(x2.dims());
  ETV(x2.size());
  ETV(sizeof(x2)/sizeof(double));
  ETV(NumberTrait<decltype(x2)>::sum_of_ranks());


  ETV(x2.data_);
  ETV(sizeof(x2.data_)/sizeof(double));

  // ECHO(x2.resize(6));
  ETV(x2.size());
  ETV(x2.data_);
  ETV(sizeof(x2.data_)/sizeof(double));
  ETV(sizeof(x2)/sizeof(double));

  CR();
  CR();
  OUTPUT("Static MultiArray");

  CR();
  ECHO(MultiArray<double, 2, 3, 2> x3{ 10.0, 10.1, 11.0, 11.1, 12.0, 12.1 });
  ETV(x3.classname());
  ETV(x3.is_dynamic_value);
  ETV(x3.compile_time_size);
  ETV(x3.static_dims_array);
  ETV(std::get<0>(x3.static_dims_array));
  ETV(x3.size());
  ETV(x3.rank());
  ETV(x3.depth());
  ETV(x3.dims_array());
  ETV(x3.dims());
  ETV(x3.recursive_dims());
  ETV(NumberTrait<decltype(x3)>::sum_of_ranks());
  ETV(x3.data_);
  ETV(sizeof(x3.data_)/sizeof(double));
  ETV(sizeof(x3)/sizeof(double));
  ETV(x3);
  ETV(x3[2]);
  ETV(x3.indices(2));
  ETV(x3.index({ 1,0 }));
  ETV(x3.index(Indices({ 1,0 })));
  ETV(x3.index(1, 0));
  ETV(x3[Indices({ 1,0 })]);
  ETV(x3[{1, 0}]);
  ETV(x3(1, 0));
  // flat list
  ECHO(x3 = { 100.0, 100.1, 100.2, 100.3, 100.4, 100.5 });
  ETV(x3);
  // nested list (indices)
  ECHO(x3 = { {-9900, -9901}, {-9910, -9911}, {-9920, -9921} });
  ETV(x3);



  CR();
  ECHO(Vector<double> x4{ 1 , 3.5, 200, -1, 50, 2, -3 });
  ETV(NumberTrait<decltype(x4)>::sum_of_ranks());
  ETV(x4);
  ETV(x4.sort());
  ETV(x4);


  // back to MultiArrays 

  CR();
  ECHO(MultiArray<double, 2, 3, 4> A1(3.14));
  ETV(A1);
  ETV(A1.dims());
  ETV(sizeof(A1)/sizeof(double));
  ETV(sizeof(A1.data_)/sizeof(double));
  // ETV(A1.dynamic_dims_array);
  ETV(A1.asMultiArrayData());

  CR();
  ECHO(MultiArray<double, 1, 10> A2);
  ETV(A2.dims());
  // ETV(A2.data_);
  ETV(sizeof(A2)/sizeof(double));
  ETV(sizeof(A2.data_)/sizeof(double));
  // ETV(A2.dynamic_dims_array);

  CR();
  ECHO(MultiArray<double, 2> A3);
  ETV(A3.dims());
  // ETV(A3.data_);
  // ETV(A3.dynamic_dims_array);
  ETV(sizeof(A3)/sizeof(double));
  ETV(sizeof(A3.data_)/sizeof(double));
  // ETV(sizeof(A3.dynamic_dims_array)/sizeof(size_t));
  ETV(A3.is_dynamic_value);
  ETV(A3.resize(2, 3));
  ETV(A3.resize(Dimensions({ 4,1 })));

  CR();
  ECHO(MultiArray<MultiArray<double, 3, 1, 2, 3>, 4, 3, 2, 1, 1> A4(42.42));
  ETV(A4.data_);
  ETV(A4.rank());
  ETV(A4.size());
  ETV(A4.dims());
  ETV(A4.recursive_dims());


  {
    CR();
    ECHO(Scalar<double> x1);
    ETV(x1);
    x1 = 0;
    ETV(x1);

    CR();
    ECHO(Vector<double, 3> x2);
    ETV(x2);
    x2 = 0;
    ETV(x2);

    CR();
    ECHO(Matrix<double, 2, 2> x3);
    ETV(x3);
    x3 = 0;
    ETV(x3);

    CR();
    ECHO(MultiArray<double, 3, 2, 1, 2> x4);
    ETV(x4);
    x4 = 0;
    ETV(x4);
  }

  return 0;
}
