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


  {
    CR();
    Vector<Matrix<double, 2, 2>, 3> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(1)(0, 1));
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.deepdims());

    decltype(v) x(0.0);
    x = 0.;
    TLDISP(x);

    typename decltype(v)::EType e;
    e = 0.;
    TLDISP(e);

    typename decltype(v)::DType d = 0.;
    TLDISP(d);

    typename decltype(v)::XType v2;
    TLDISP(v2);

    TLDISP(decltype(v)::Mvalue);
    TLDISP(decltype(v)::Rvalue);
  }





  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
