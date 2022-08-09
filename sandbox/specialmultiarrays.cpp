
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
  Style violet = CREATESTYLE(BOLD + VIOLET1);


  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;
  print_mathq_info();

  CR();
  CR();
  CR();
  MOUT << violet.apply("Constant") << std::endl;

  CR();
  MOUT << blue.apply("MultiArray_Constant: fixed-size") << std::endl;
  CR();
  {
    ECHO_CODE( MultiArray_Constant<double,3, 3,2,1> a(3.14));
    TRDISP(a);
    TRDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TRDISP(a);
    ECHO_CODE( MultiArray<double,3, 3,2,1> b = a );
    TRDISP(b);
    ECHO_CODE( a = 10 + b );
    TRDISP(a);
  }

  CR();
  MOUT << blue.apply("MultiArray_Constant: dynamic-size") << std::endl;
  CR();
  {
    ECHO_CODE( MultiArray_Constant<double,3> a(Dimensions({3,2,1}), 6.78) );
    TRDISP(a);
    TRDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TRDISP(a(1,1,0));
  }

  CR();
  MOUT << blue.apply("Matrix_Constant: fixed-size") << std::endl;
  CR();
  {
    ECHO_CODE( Matrix_Constant<double, 2,3> a(3.14) );
    TRDISP(a);
    TRDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TRDISP(a(1,2));
    ECHO_CODE( Matrix<double,2,3> b );
    ECHO_CODE( b = a );
    TRDISP(b);
    ECHO_CODE( a = 10 + b );
    TRDISP(a);
  }

  CR();
  MOUT << blue.apply("Matrix_Constant: dynamic-size") << std::endl;
  CR();
  {
    ECHO_CODE( Matrix_Constant<double> a(Dimensions({2,3}), 6.78) );
    TRDISP(a);
    TRDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TRDISP(a);
  }


  CR();
  MOUT << blue.apply("Vector_Constant: fixed-size") << std::endl;
  CR();
  {
    ECHO_CODE( Vector_Constant<double, 4> a(3.14) );
    TRDISP(a);
    TRDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TRDISP(a);
    ECHO_CODE( Vector<double,4> b = a );
    TRDISP(b);
    ECHO_CODE( a = 10 + b );
    TRDISP(a);
  }

  CR();
  MOUT << blue.apply("Vector_Constant: dynamic-size") << std::endl;
  CR();
  {
    ECHO_CODE( Vector_Constant<double> a(Dimensions({5}), 6.78) );
    TRDISP(a);
    TRDISP(sizeof(a)/sizeof(double));
    a = 42.42;
    TRDISP(a(3));
  }




  CR();
  CR();
  CR();
  MOUT << violet.apply("RepeatVector") << std::endl;

  CR();
  MOUT << blue.apply("MultiArray_RepeatVector: fixed-size") << std::endl;
  CR();
  {
    ECHO_CODE( MultiArray_RepeatVector<double,3, 2,3,4> a(1, 3.14) );
    TRDISP(a);
    TRDISP(sizeof(a)/sizeof(double));
    a = { 1.1, 2.2, 3.3 };
    TRDISP(a);
    ECHO_CODE( MultiArray<double,3> b = a );
    // b(1,2,3) = -999; // error injection
    TRDISP(b);
    ECHO_CODE( a = 10 + b );
    TRDISP(a);
  }

  CR();
  MOUT << blue.apply("MultiArray_RepeatVector: dynamic-size") << std::endl;
  CR();
  {
    ECHO_CODE( MultiArray_RepeatVector<double,3> a(1, Dimensions({2,3,4}), 6.78) );
    TRDISP(a);
    TRDISP(sizeof(a)/sizeof(double));
    a = { 1.1, 2.2, 3.3 };
    TRDISP(a);
  }



  // CR();
  // MOUT << blue.apply("Matrix_RepeatVector: fixed-size") << std::endl;
  // CR();
  // {
  //   ECHO_CODE( Matrix_RepeatVector<double, 0, 3,3> a );
  //   a = 0;
  //   TRDISP(a);
  //   TRDISP(sizeof(a)/sizeof(double));
  //   TRDISP(a.vector);
  //   TRDISP(a.dims());
  //   std::array<double,3> x{1.1,2.2,3.3};
  //   TRDISP(x);
  //   ECHO_CODE( a = x );
  //   TRDISP(a);
  //   ECHO_CODE( a = {-1.1,-2.2,-3.3} );
  //   TRDISP(a);
  //   ECHO_CODE( Matrix<double> b = -a );
  //   // b(1,2) = -999; // error injection
  //   TRDISP(b);
  //   ECHO_CODE( a = 10 + b );
  //   TRDISP(a);

  // }

  // CR();
  // MOUT << blue.apply("Matrix_RepeatVector: dynamic-size") << std::endl;
  // CR();
  // {
  //   ECHO_CODE( Matrix_RepeatVector<double,1> a(Dimensions({3,3}), 6.78) );
  //   TRDISP(a);
  //   TRDISP(sizeof(a)/sizeof(double));
  //   a = { 1.1, 2.2, 3.3 };
  //   TRDISP(a);
  // }



  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();
  return 0;
}
