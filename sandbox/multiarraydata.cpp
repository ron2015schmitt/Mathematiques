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


  CR();
  ECHO(typename MakeInitializer<double, 0>::Type init0{ 3 });
  ETV(init0);
  ECHO(typename MakeInitializer<double, 1>::Type init1{ 3,2,1 });
  ETV(init1);
  ECHO(typename MakeInitializer<double, 2>::Type init2{ {1}, {1,2}, {1,2,3} });
  ETV(init2);




  // MultiArray*Data* tests
  CR();
  OUTPUT("rank = 0, fixed size (no dynamic size)");
  ECHO(MultiArrayData<double, 0> testdata0);
  testdata0.data_ = { 0 };
  ETV(testdata0);
  ETV(testdata0.classname());
  ETV(sizeof(testdata0)/sizeof(double));
  ETV(sizeof(testdata0.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 1, fixed size");
  ECHO(MultiArrayData<double, 1, 10> testdata1);
  testdata1.data_ = array_of_one_value<double, 10, 0.>();
  ETV(testdata1);
  ETV(testdata1.classname());
  ETV(sizeof(testdata1)/sizeof(double));
  ETV(sizeof(testdata1.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 2, fixed size");
  ECHO(MultiArrayData<double, 2, 3, 4> testdata2);
  testdata2.data_ = array_of_one_value<double, 12, 0.>();
  ETV(testdata2);
  ETV(testdata2.classname());
  ETV(sizeof(testdata2)/sizeof(double));
  ETV(sizeof(testdata2.data_)/sizeof(double));

  CR();
  OUTPUT("MultiArray: rank = 2, fixed size => should Matrix");
  ECHO(MultiArray<double, 2, 3, 4> x2);
  x2 = 0.;
  ETV(x2);
  ETV(x2.asMultiArrayData());


  CR();
  OUTPUT("rank = 3, fixed size");
  ECHO(MultiArrayData<double, 3, 3, 4, 2> testdata3);
  testdata3.data_ = array_of_one_value<double, 24, 0.>();
  ETV(testdata3);
  ETV(testdata3.classname());
  ETV(sizeof(testdata3)/sizeof(double));
  ETV(sizeof(testdata3.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 4, fixed size");
  ECHO(MultiArrayData<double, 4, 2, 3, 4, 2> testdata4);
  testdata4.data_ = array_of_one_value<double, 48, 0.>();
  ETV(testdata4);
  ETV(testdata4.classname());
  ETV(sizeof(testdata4)/sizeof(double));
  ETV(sizeof(testdata4.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 5, fixed size");
  ECHO(MultiArrayData<double, 5, 3, 4, 4, 3, 2> testdata5);
  testdata5.data_ = array_of_one_value<double, 288, 0.>();
  ETV(testdata5);
  ETV(testdata5.classname());
  ETV(sizeof(testdata5)/sizeof(double));
  ETV(sizeof(testdata5.data_)/sizeof(double));



  CR();
  OUTPUT("rank = 1, dynamic size");
  ECHO(MultiArrayData<double, 1> testdata1d);
  ETV(testdata1d);
  ETV(testdata1d.classname());
  ETV(sizeof(testdata1d)/sizeof(double));
  ETV(sizeof(testdata1d.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 2, dynamic size");
  ECHO(MultiArrayData<double, 2> testdata2d);
  ETV(testdata2d);
  ETV(testdata2d.classname());
  ETV(sizeof(testdata2d)/sizeof(double));
  ETV(sizeof(testdata2d.data_)/sizeof(double));

  CR();
  OUTPUT("MultiArray: rank = 2, dynamic size => should be Matrix");
  ECHO(MultiArray<double, 2> xd2);
  xd2 = 0.;
  ETV(xd2);
  ETV(xd2.asMultiArrayData());

  CR();
  OUTPUT("rank = 3, dynamic size");
  ECHO(MultiArrayData<double, 3> testdata3d);
  ETV(testdata3d);
  ETV(testdata3d.classname());
  ETV(sizeof(testdata3d)/sizeof(double));
  ETV(sizeof(testdata3d.data_)/sizeof(double));
  ETV(sizeof(testdata3d.dynamic_dims_array)/sizeof(size_t));

  CR();
  OUTPUT("rank = 4, dynamic size");
  ECHO(MultiArrayData<double, 4> testdata4d);
  ETV(testdata4d);
  ETV(testdata4d.classname());
  ETV(sizeof(testdata4d)/sizeof(double));
  ETV(sizeof(testdata4d.data_)/sizeof(double));
  ETV(sizeof(testdata4d.dynamic_dims_array)/sizeof(size_t));


  CR();
  OUTPUT("rank = 5, dynamic size");
  ECHO(MultiArrayData<double, 5> testdata5d);
  ETV(testdata5d);
  ETV(testdata5d.classname());
  ETV(sizeof(testdata5d)/sizeof(double));
  ETV(sizeof(testdata5d.data_)/sizeof(double));
  ETV(sizeof(testdata5d.dynamic_dims_array)/sizeof(size_t));



  return 0;
}
