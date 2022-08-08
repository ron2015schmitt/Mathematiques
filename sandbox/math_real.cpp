#include "mathq.h"


int main(int argc, char* argv[]) {
  // using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  std::cout << std::endl;
  std::cout << "running: " <<myname << std::endl;
  std::cout << std::endl;


  CR();
  TRDISP(roundzero(float(0.001)));
  TRDISP(float(3e-7));
  TRDISP(roundzero(float(3e-7)));

  CR();
  TRDISP(roundzero(double(0.001)));
  TRDISP(double(1e-16));
  TRDISP(roundzero(double(1e-16)));

  CR();
  TRDISP(roundzero(quad(0.001)));
  TRDISP(quad(1e-30));
  TRDISP(roundzero(quad(1e-30)));

  CR();
  TRDISP(zero<int>());
  TRDISP(zero<double>());
  TRDISP(zero<quad>());

  CR();
  TRDISP(one<int>());
  TRDISP(one<double>());
  TRDISP(one<quad>());

  int ii = 42;
  double dub = 3.14;
  int nii = -13;
  double ndub = -2.73;

  CR();
  TRDISP(mathq::conj(ii));
  TRDISP(mathq::conj(dub));


  CR();
  TRDISP(mathq::real(ii));
  TRDISP(mathq::real(dub));

  CR();
  TRDISP(mathq::imag(ii));
  TRDISP(mathq::imag(dub));

  CR();
  TRDISP(mathq::sqr(ii));
  TRDISP(mathq::sqr(dub));

  CR();
  TRDISP(mathq::cube(ii));
  TRDISP(mathq::cube(dub));

  CR();
  TRDISP(mathq::logN(ii, 5));
  TRDISP(mathq::logN(dub, 5));

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
  TRDISP(mathq::approx(ii, ii+1));
  TRDISP(mathq::approx(dub, dub+1e-16));
  TRDISP(mathq::approx(dub, dub+5e-16));


  return 0;
}
