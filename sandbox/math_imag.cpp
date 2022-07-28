#include "mathq.h"


int main(int argc, char* argv[]) {
  // using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  std::cout << std::endl;
  std::cout << "running: " <<myname << std::endl;
  std::cout << std::endl;


  {
    CR();
    ECHO_CODE(Imaginary<float> x1{ 0.001 });
    TRDISP(roundzero(x1));
    ECHO_CODE(Imaginary<float> x2{ 3e-7 });
    TRDISP(x2);
    TRDISP(roundzero(x2));
  }

  {
    CR();
    ECHO_CODE(Imaginary<double> x1{ 0.001 });
    TRDISP(roundzero(x1));
    ECHO_CODE(Imaginary<double> x2{ 1e-16 });
    TRDISP(x2);
    TRDISP(roundzero(x2));
  }


  {
    CR();
    ECHO_CODE(Imaginary<quad> x1{ 0.001 });
    TRDISP(roundzero(x1));
    ECHO_CODE(Imaginary<quad> x2{ 1e-30 });
    TRDISP(x2);
    TRDISP(roundzero(x2));
  }


  CR();
  TRDISP(zero<Imaginary<int>>());
  TRDISP(zero<Imaginary<double>>());
  TRDISP(zero<Imaginary<quad>>());

  CR();
  TRDISP(one<Imaginary<int>>());
  TRDISP(one<Imaginary<double>>());
  TRDISP(one<Imaginary<quad>>());

  CR();
  ECHO_CODE(Imaginary<int> ii{ 42 });
  ECHO_CODE(Imaginary<double> dub{ 3.14 });
  ECHO_CODE(Imaginary<int> nii{ -13 });
  ECHO_CODE(Imaginary<double> ndub{ -2.73 });

  CR();
  TRDISP(mathq::real(ii));
  TRDISP(mathq::real(dub));

  CR();
  TRDISP(mathq::imag(ii));
  TRDISP(mathq::imag(dub));

  CR();
  TRDISP(mathq::conj(ii));
  TRDISP(mathq::conj(dub));

  CR();
  TRDISP(mathq::sqr(ii));
  TRDISP(mathq::sqr(dub));

  CR();
  TRDISP(mathq::cube(ii));
  TRDISP(mathq::cube(dub));

  // CR();
  // TRDISP(mathq::logN(ii, 5));
  // TRDISP(mathq::logN(dub, 5));

  CR();
  TRDISP(mathq::normsqr(ii));
  TRDISP(mathq::normsqr(dub));
  TRDISP(mathq::normsqr(nii));
  TRDISP(mathq::normsqr(ndub));

  CR();
  TRDISP(mathq::sgn(ii));
  TRDISP(mathq::sgn(dub));
  TRDISP(mathq::sgn(nii));
  TRDISP(mathq::sgn(ndub));

  CR();
  TRDISP(mathq::approx(ii, ii + Imaginary<int>(1)));
  TRDISP(mathq::approx(dub, dub + Imaginary<double>(1e-16)));
  TRDISP(mathq::approx(dub, dub + Imaginary<double>(5e-16)));

  return 0;
}
