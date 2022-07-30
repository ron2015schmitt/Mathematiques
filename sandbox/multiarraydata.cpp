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
  ECHO_CODE(typename MakeInitializer<double,0>::Type init0{3});
  TRDISP(init0);
  ECHO_CODE(typename MakeInitializer<double,1>::Type init1{3,2,1});
  TRDISP(init1);
  ECHO_CODE(typename MakeInitializer<double,2>::Type init2{{1}, {1,2}, {1,2,3}});
  TRDISP(init2);

  // MultiArray*Data* tests

  CR();
  OUTPUT("rank = 1, fixed size");
  ECHO_CODE(MultiArrayData<double,1, 10> testdata1);
  TRDISP(testdata1);
  TRDISP(testdata1.classname());
  TRDISP(sizeof(testdata1)/sizeof(double));
  TRDISP(sizeof(testdata1.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 2, fixed size");
  ECHO_CODE(MultiArrayData<double,2, 3,4> testdata2);
  TRDISP(testdata2);
  TRDISP(testdata2.classname());
  TRDISP(sizeof(testdata2)/sizeof(double));
  TRDISP(sizeof(testdata2.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 3, fixed size");
  ECHO_CODE(MultiArrayData<double,3, 3,4,2> testdata3);
  TRDISP(testdata3);
  TRDISP(testdata3.classname());
  TRDISP(sizeof(testdata3)/sizeof(double));
  TRDISP(sizeof(testdata3.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 4, fixed size");
  ECHO_CODE(MultiArrayData<double,4, 2,3,4,2> testdata4);
  TRDISP(testdata4);
  TRDISP(testdata4.classname());
  TRDISP(sizeof(testdata4)/sizeof(double));
  TRDISP(sizeof(testdata4.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 5, fixed size");
  ECHO_CODE(MultiArrayData<double,5, 3,4,4,3,2> testdata5);
  TRDISP(testdata5);
  TRDISP(testdata5.classname());
  TRDISP(sizeof(testdata5)/sizeof(double));
  TRDISP(sizeof(testdata5.data_)/sizeof(double));







  CR();
  OUTPUT("rank = 1, dynamic size");
  ECHO_CODE(MultiArrayData<double,1> testdata1d);
  TRDISP(testdata1d);
  TRDISP(testdata1d.classname());
  TRDISP(sizeof(testdata1d)/sizeof(double));
  TRDISP(sizeof(testdata1d.data_)/sizeof(double));

  CR();
  OUTPUT("rank = 2, dynamic size");
  ECHO_CODE(MultiArrayData<double,2> testdata2d);
  TRDISP(testdata2d);
  TRDISP(testdata2d.classname());
  TRDISP(sizeof(testdata2d)/sizeof(double));
  TRDISP(sizeof(testdata2d.data_)/sizeof(double));
  TRDISP(sizeof(testdata2d.dynamic_dims_array)/sizeof(size_t));

  CR();
  OUTPUT("rank = 3, dynamic size");
  ECHO_CODE(MultiArrayData<double,3> testdata3d);
  TRDISP(testdata3d);
  TRDISP(testdata3d.classname());
  TRDISP(sizeof(testdata3d)/sizeof(double));
  TRDISP(sizeof(testdata3d.data_)/sizeof(double));
  TRDISP(sizeof(testdata3d.dynamic_dims_array)/sizeof(size_t));

  CR();
  OUTPUT("rank = 4, dynamic size");
  ECHO_CODE(MultiArrayData<double,4> testdata4d);
  TRDISP(testdata4d);
  TRDISP(testdata4d.classname());
  TRDISP(sizeof(testdata4d)/sizeof(double));
  TRDISP(sizeof(testdata4d.data_)/sizeof(double));
  TRDISP(sizeof(testdata4d.dynamic_dims_array)/sizeof(size_t));


  CR();
  OUTPUT("rank = 5, dynamic size");
  ECHO_CODE(MultiArrayData<double,5> testdata5d);
  TRDISP(testdata5d);
  TRDISP(testdata5d.classname());
  TRDISP(sizeof(testdata5d)/sizeof(double));
  TRDISP(sizeof(testdata5d.data_)/sizeof(double));
  TRDISP(sizeof(testdata5d.dynamic_dims_array)/sizeof(size_t));



  return 0;
}
