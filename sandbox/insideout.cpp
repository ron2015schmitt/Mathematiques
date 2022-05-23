#include <fstream>


#define MATHQ_DEBUG 0
#include "mathq.h"


int main(int argc, char *argv[]) {

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  using namespace display;
  using namespace mathq::unit_imaginary;

  Style bold = CREATESTYLE(BOLD);
  Style blue = CREATESTYLE(BOLD + BLUE2);

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;


  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();





  CR();
  MOUT << StyledString::get(HORLINE);
  CR();
  //------------------------------------------------------

  CR();
  CR();
  MOUT << bold.apply("Scalar") << endl;
  {
    CR();
    InversionType<Scalar<double>, Null>::Type s{4};
    TLDISP(s);
    InversionType<Vector<double>, Null>::Type v{1, 2, 3, 4};
    TLDISP(v);
    InversionType<Scalar<Vector<double>>, Null>::Type vs{{1}, {2}, {3}, {4}};
    TLDISP(vs);
    Scalar<Vector<double>> sv{{1, 2, 3, 4}};
    TLDISP(sv);
    InversionType<decltype(sv), Null>::Type vs2;
    TLDISP(vs2);
  }





  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
