#include <vector>
#include <string>

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

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;


  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();


  {
    CR();
    TLDISP(i);
    Imaginary<double> x(2);
    Imaginary<int> y(3);
    std::complex<float> z(1, 1);

    TLDISP(x);
    TLDISP(y);
    TLDISP(numbercast<Imaginary<float>>(y));

    TLDISP(+x);
    TLDISP(-x);



    TLDISP(x + 3 * i);
    TLDISP(x - 3 * i);
    TLDISP(i * i);
    TLDISP(x * i);
    TLDISP(x / i);

    TLDISP(4 * i + x);
    TLDISP(4 * i - x);
    TLDISP(i * x);
    TLDISP(i / x);

    TLDISP(x + 3);
    TLDISP(x - 3);
    TLDISP(x * 4);
    TLDISP(x / 2);

    TLDISP(3 + x);
    TLDISP(3 - x);
    TLDISP(4 * x);
    TLDISP(2 / x);


    TLDISP(x + z);
    TLDISP(x - z);
    TLDISP(x * z);
    TLDISP(x / z);

    TLDISP(z + x);
    TLDISP(z - x);
    TLDISP(z * x);
    TLDISP(z / x);



    TLDISP(x += i);
    TLDISP(x -= 2 * i);
    TLDISP(x *= 4);
    TLDISP(x /= 4);

    TLDISP(x += 5 * i);

    TLDISP(x + y);
    TLDISP(x - y);
    TLDISP(x * y);
    TLDISP(x / y);


    TLDISP(Complex(x));

    TLDISP(real(x));
    TLDISP(imag(x));
    TLDISP(arg(x));

    TLDISP(abs(x));
    TLDISP(normsqr(x));
    TLDISP(conj(x));
    TLDISP(~x);
    TLDISP(polar(x));

    TLDISP(exp(x));

    TLDISP(log(x));
    TLDISP(log10(x));
    TLDISP(log2(x));

    TLDISP(x);
    TLDISP(y);
    TLDISP(pow(x, y));
    TLDISP(pow(x, 2));
    TLDISP(pow(2, x));
    TLDISP(pow(x, z));
    TLDISP(pow(z, x));

    TLDISP(sqrt(x));
    TLDISP(sqr(x));
    TLDISP(cube(x));

    Imaginary<double> w(1.9);
    TLDISP(w);
    TLDISP(round(w));
    TLDISP(sgn(-w));
    TLDISP(floor(w));
    TLDISP(ceil(w));

    w = 0.009 * i;
    TLDISP(w);
    TLDISP(roundzero(w, 0.01));
    TLDISP(roundzero(w, 0.001));
    TLDISP(approx(i, 1.009 * i, 0.01));
    TLDISP(approx(i, 1.009 * i, 0.001));


    TLDISP(sin(x));
    TLDISP(cos(x));
    TLDISP(tan(x));

    TLDISP(sinh(x));
    TLDISP(cosh(x));
    TLDISP(tanh(x));


    TLDISP(asin(x));
    TLDISP(acos(x));
    TLDISP(atan(x));

    w = 0.9 * i;
    TLDISP(w);
    TLDISP(atan(w));



    TLDISP(asinh(w));
    TLDISP(acosh(w));
    TLDISP(atanh(w));
  }


  //------------------------------------------------------

  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();
  return 0;
}
