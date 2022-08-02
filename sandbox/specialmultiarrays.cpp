
#define MATHQ_DEBUG 0
#include "mathq.h"


int main(int argc, char *argv[]) {

  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace mathq;
  using namespace display;
  using namespace std;

  Style bold = CREATESTYLE(BOLD);
  Style blue = CREATESTYLE(BOLD + BLUE2);


  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;
  print_mathq_info();

  CR();
  MOUT << blue.apply("MultiArray_Constant") << std::endl;
  CR();

  CR();
  MOUT << blue.apply("MultiArray_Constant: fixed-size") << std::endl;
  CR();
  {
    ECHO_CODE( MultiArray_Constant<double,3, 2,3,4> a(3.14));
    TLDISP(a);
    TLDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TLDISP(a(1,1,1));
  }

  CR();
  MOUT << blue.apply("MultiArray_Constant: dynamic-size") << std::endl;
  CR();
  {
    ECHO_CODE( MultiArray_Constant<double,3> a(Dimensions({3,2,1}), 6.78) );
    TLDISP(a);
    TLDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TLDISP(a(1,1,0));
  }

  CR();
  MOUT << blue.apply("Matrix_Constant: fixed-size") << std::endl;
  CR();
  {
    ECHO_CODE( Matrix_Constant<double, 2,3> a(3.14) );
    TLDISP(a);
    TLDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TLDISP(a(1,2));
  }

  CR();
  MOUT << blue.apply("Matrix_Constant: dynamic-size") << std::endl;
  CR();
  {
    ECHO_CODE( Matrix_Constant<double> a(Dimensions({2,3}), 6.78) );
    TLDISP(a);
    TLDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TLDISP(a(1,2));
  }


  CR();
  MOUT << blue.apply("Vector_Constant: fixed-size") << std::endl;
  CR();
  {
    ECHO_CODE( Vector_Constant<double, 4> a(3.14) );
    TLDISP(a);
    TLDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TLDISP(a(2));
  }

  CR();
  MOUT << blue.apply("Vector_Constant: dynamic-size") << std::endl;
  CR();
  {
    ECHO_CODE( Vector_Constant<double> a(Dimensions({5}), 6.78) );
    TLDISP(a);
    TLDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TLDISP(a(3));
  }




  // CR();
  // MOUT << blue.apply("MultiArray_RepeatVector") << std::endl;
  // CR();

  // CR();
  // MOUT << blue.apply("MultiArray_RepeatVector: fixed-size") << std::endl;
  // CR();
  // {
  //   ECHO_CODE( MultiArray_RepeatVector<double,3, 1, 2,3,4> a(3.14) );
  //   TLDISP(a);
  //   TLDISP(sizeof(a)/sizeof(double));
  //   a = { 1.1, 2.2, 3.3 };
  //   TLDISP(a);
  // }

  // CR();
  // MOUT << blue.apply("MultiArray_RepeatVector: dynamic-size") << std::endl;
  // CR();
  // {
  //   ECHO_CODE( MultiArray_RepeatVector<double,3,1> a(Dimensions({2,3,4}), 6.78) );
  //   TLDISP(a);
  //   TLDISP(sizeof(a)/sizeof(double));
  //   a = { 1.1, 2.2, 3.3 };
  //   TLDISP(a);
  // }

  // CR();
  // MOUT << blue.apply("Matrix_RepeatVector: fixed-size") << std::endl;
  // CR();
  // {
  //   ECHO_CODE( Matrix_RepeatVector<double, 0, 3,3> a(3.14) );
  //   TLDISP(a);
  //   TLDISP(sizeof(a)/sizeof(double));
  //   a = { 1.1, 2.2, 3.3 };
  //   TLDISP(a);
  // }

  // CR();
  // MOUT << blue.apply("Matrix_RepeatVector: dynamic-size") << std::endl;
  // CR();
  // {
  //   ECHO_CODE( Matrix_RepeatVector<double,1> a(Dimensions({3,3}), 6.78) );
  //   TLDISP(a);
  //   TLDISP(sizeof(a)/sizeof(double));
  //   a = { 1.1, 2.2, 3.3 };
  //   TLDISP(a);
  // }



  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();
  return 0;
}
