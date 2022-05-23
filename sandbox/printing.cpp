#include <vector>

#define MATHQ_DEBUG 0
#include "mathq.h"


int main(int argc, char *argv[]) {
  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace mathq;
  using namespace display;

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << CREATESTYLE(BOLD).apply(myname) << std::endl;


  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();


  int n = 45;
  unsigned int m = 256;
  double x = 3.14;
  double vals[] = {1.1, 2.2, 3.3};
  bool done = true;
  Vector<double> v = range<double>(1, 10);
  Matrix<double> A(2, 2, {1, 2, 3, 4});
  char str[] = "hello";
  std::string s = "world";
  ComplexDouble z(1, -1);


  CR();
  CR();
  DISP(n);
  DISP(m);
  DISP(x);
  DISP(vals);
  DISP(done);
  DISP(v);
  DISP(A);
  DISP(str);
  DISP(s);
  DISP(z);

  CR();
  CR();
  TLDISP(n);
  TLDISP(m);
  TLDISP(x);
  TLDISP(vals);
  TLDISP(done);
  TLDISP(v);
  TLDISP(A);
  TLDISP(str);
  TLDISP(s);
  TLDISP(z);

  CR();
  CR();
  MDISP(n, m, x, vals, done, str, s, z);

  CR();
  CR();
  DISPVAL(n);
  DISPVAL(m);
  DISPVAL(A);

  CR();
  CR();
  DISP(n + 3);
  DISP(10 * x - 1);
  DISP(!done);
  DISP(round(10 * sin(pi / 10 * v) + 10));
  DISP(s + " tour");
  MOUT << std::endl;

  MOUT << CREATESTYLE(GRAY1) << "  ";
  MOUT << CREATESTYLE(GRAY2) << "  ";
  MOUT << CREATESTYLE(WHITE + BLACKBACK) << "  ";
  MOUT << std::endl;

  MOUT << CREATESTYLE(RED) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(ORANGE) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(YELLOW) << "  ";
  MOUT << CREATESTYLE(YELLOWBRIGHT) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(GREEN) << "  ";
  MOUT << CREATESTYLE(GREENBRIGHT) << "  ";
  MOUT << CREATESTYLE(GREEN1) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(CYAN) << "  ";
  MOUT << CREATESTYLE(BLUE) << "  ";
  MOUT << CREATESTYLE(BLUEBRIGHT) << "  ";
  MOUT << CREATESTYLE(BLUE1) << "  ";
  MOUT << CREATESTYLE(BLUE2) << "  ";
  MOUT << CREATESTYLE(BLUE3) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(MAGENTA) << "  ";
  MOUT << CREATESTYLE(MAGENTA1) << "  ";
  MOUT << CREATESTYLE(VIOLET1) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(BOLD) << "  ";
  MOUT << CREATESTYLE(UNDERLINE) << "  ";
  MOUT << CREATESTYLE(CROSSEDOUT) << "  ";
  MOUT << CREATESTYLE(OVERLINE) << "  ";
  MOUT << CREATESTYLE(SLOWBLINK) << "  ";
  MOUT << std::endl;

  MOUT << CREATESTYLE(REDBACK) << "  ";
  MOUT << CREATESTYLE(ORANGEBACK) << "  ";
  MOUT << CREATESTYLE(YELLOWBACK) << "  ";
  MOUT << CREATESTYLE(GREENBACK) << "  ";
  MOUT << std::endl;
  MOUT << std::endl;
  MOUT << std::endl;

  MOUT << CREATESTYLE(BOLD + UNDERLINE + VIOLET1) << "  ";
  MOUT << std::endl;
  MOUT << std::endl;
  MOUT << std::endl;
  MOUT << std::endl;

  {
    Style mystyle = CREATESTYLE(BOLD + RED);
    MOUT << mystyle.apply("with style") + " without style " << std::endl;
  }
  MOUT << std::endl;
  MOUT << std::endl;
  MOUT << std::endl;

  {
    int nf = 27;  // color for foreground
    int nb = 227; // color for background
    Style mystyle(nf, nb);
    MOUT << mystyle.apply("Hello World") << std::endl;

    MOUT << std::endl;
    MOUT << std::endl;
    MOUT << std::endl;


    Style bold(BOLD);
    Style mybold = bold + mystyle;
    MOUT << mybold.apply("Hello World") << std::endl;

    Style black(BLACK);
    MOUT << "XXX" << black.apply("XXX") << "XXX" << std::endl;
  }


  CR();
  MOUT << "done: " << CREATESTYLE(BOLD).apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();


  return 0;
}
