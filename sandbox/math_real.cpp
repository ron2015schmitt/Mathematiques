#include "mathq.h"


int main(int argc, char* argv[]) {
  // using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  std::cout << std::endl;
  std::cout << "running: " <<myname << std::endl;
  std::cout << std::endl;


  CR();
  ETV(roundzero(float(0.001)));
  ETV(float(3e-7));
  ETV(roundzero(float(3e-7)));

  CR();
  ETV(roundzero(double(0.001)));
  ETV(double(1e-16));
  ETV(roundzero(double(1e-16)));

  CR();
  ETV(roundzero(quad(0.001)));
  ETV(quad(1e-30));
  ETV(roundzero(quad(1e-30)));

  CR();
  ETV(zero<int>());
  ETV(zero<double>());
  ETV(zero<quad>());

  CR();
  ETV(one<int>());
  ETV(one<double>());
  ETV(one<quad>());

  int ii = 42;
  double dub = 3.14;
  int nii = -13;
  double ndub = -2.73;

  CR();
  ETV(mathq::conj(ii));
  ETV(mathq::conj(dub));


  CR();
  ETV(mathq::real(ii));
  ETV(mathq::real(dub));

  CR();
  ETV(mathq::imag(ii));
  ETV(mathq::imag(dub));

  CR();
  ETV(mathq::sqr(ii));
  ETV(mathq::sqr(dub));

  CR();
  ETV(mathq::cube(ii));
  ETV(mathq::cube(dub));

  CR();
  ETV(mathq::logN(ii, 5));
  ETV(mathq::logN(dub, 5));

  CR();
  ETV(mathq::normsqr(ii));
  ETV(mathq::normsqr(dub));
  ETV(mathq::normsqr(nii));
  ETV(mathq::normsqr(ndub));

  CR();
  ETV(mathq::sgn(ii));
  ETV(mathq::sgn(dub));
  ETV(mathq::sgn(nii));
  ETV(mathq::sgn(ndub));

  CR();
  ETV(mathq::approx(ii, ii+1));
  ETV(mathq::approx(dub, dub+1e-16));
  ETV(mathq::approx(dub, dub+5e-16));


  return 0;
}
