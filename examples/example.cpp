
#include <iostream>
#include <fstream>
#include <string>

#include "mathq.h"

void printoptsfile() {
  std::ifstream myfile;
  myfile.open("example.compiler");
  std::string myline;
  if (myfile.is_open()) {
    while (myfile) {
      std::getline(myfile, myline);
      std::cout << myline << '\n';
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
}

int main(int argc, char* argv[]) {
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
  printoptsfile();

  Vector<double> v1(linspace<double>(-1, 1, 21));
  Vector<double> v2;
  v2 = 10 * sin(pi / 2 * v1) + 10;

  EV(v1);
  EV(v2);
  EV(v1 + v2);

  // dot product
  EV(v1 | v2);

  const double N = double(v2.size());
  // mean
  double mu2 = sum(v2) / N;

  // std deviation
  double sigma2 = norm(v2 - mu2) / sqrt(N - 1);

  MDISP(mu2, sigma2);

  CR();
  MOUT << "done: " << CREATESTYLE(BOLD).apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
