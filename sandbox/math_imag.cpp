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
    ECHO(Imaginary<float> x1{ 0.001 });
    ETV(roundzero(x1));
    ECHO(Imaginary<float> x2{ 3e-7 });
    ETV(x2);
    ETV(roundzero(x2));
  }

  {
    CR();
    ECHO(Imaginary<double> x1{ 0.001 });
    ETV(roundzero(x1));
    ECHO(Imaginary<double> x2{ 1e-16 });
    ETV(x2);
    ETV(roundzero(x2));
  }


  {
    CR();
    ECHO(Imaginary<quad> x1{ 0.001 });
    ETV(roundzero(x1));
    ECHO(Imaginary<quad> x2{ 1e-30 });
    ETV(x2);
    ETV(roundzero(x2));
  }


  CR();
  ETV(zero<Imaginary<int>>());
  ETV(zero<Imaginary<double>>());
  ETV(zero<Imaginary<quad>>());

  CR();
  ETV(one<Imaginary<int>>());
  ETV(one<Imaginary<double>>());
  ETV(one<Imaginary<quad>>());

  CR();
  ECHO(Imaginary<int> ii{ 42 });
  ECHO(Imaginary<double> dub{ 3.14 });
  ECHO(Imaginary<int> nii{ -13 });
  ECHO(Imaginary<double> ndub{ -2.73 });

  CR();
  ETV(mathq::real(ii));
  ETV(mathq::real(dub));

  CR();
  ETV(mathq::imag(ii));
  ETV(mathq::imag(dub));

  CR();
  ETV(mathq::conj(ii));
  ETV(mathq::conj(dub));

  CR();
  ETV(mathq::sqr(ii));
  ETV(mathq::sqr(dub));

  CR();
  ETV(mathq::cube(ii));
  ETV(mathq::cube(dub));

  // CR();
  // ETV(mathq::logN(ii, 5));
  // ETV(mathq::logN(dub, 5));

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
  ETV(mathq::approx(ii, ii + Imaginary<int>(1)));
  ETV(mathq::approx(dub, dub + Imaginary<double>(1e-16)));
  ETV(mathq::approx(dub, dub + Imaginary<double>(5e-16)));

  return 0;
}
