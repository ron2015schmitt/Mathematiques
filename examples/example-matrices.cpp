#include <iostream>
#include <fstream>
#include <string>

#include "mathq.h"

void printoptsfile() {
  std::ifstream myfile;
  myfile.open("example.g++_copts");
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

  Vector<double> v1({ 2, -1 });
  Vector<double> v2;
  v2 = 10 * sin(pi / 2 * v1) + 5;

  DISP(v1);
  DISP(v2);
  DISP(v1 + v2);

  // FormatDataVector::max_elements_per_line = 10;
  // FormatDataVector::string_opening = "[\n  ";
  // FormatDataVector::string_delimeter = "\n  ";
  // FormatDataVector::string_endofline = "";
  // FormatDataVector::string_closing = "\n]";

  FormatDataMatrix::max_elements_per_line = 10;
  FormatDataMatrix::string_opening = "[\n";
  FormatDataMatrix::string_delimeter = ", ";
  FormatDataMatrix::string_row_opening = "    ";
  FormatDataMatrix::string_row_closing = "\n";
  FormatDataMatrix::string_lastrow_closing = "";
  FormatDataMatrix::string_endofline = "\n";
  FormatDataMatrix::string_closing = "\n]";

  Matrix<double> m1(2, 2);
  m1 = { 10, 20, 30, 40 };
  Matrix<double> m2(2, 2);
  m2 = { -1, -2, -3, -4 };

  Matrix<double> m3({ {1, 2}, {3, 4}, {5, 6} });
  // m3 = {{1, 2}, {3, 4}, {5, 6}};
  // dot product
  DISP(v1 | v2);

  DISP(v1);
  DISP(m3);
  DISP((m3 | v1));

  DISP(m1);
  DISP(m2);
  DISP(m1 + m2);

  DISP(m1 | v1);
  DISP(v1 | m1);

  DISP(m1 | m2);

  DISP(m3 | m1);
  DISP(m2 | m3.transpose());

  Vector<double> v({ 2, -1 });
  Vector<double> u({ 1, -2, 4 });
  Matrix<double> A({ {1, 2}, {3, 4}, {5, 6} });

  DISP(v);
  DISP(A);
  DISP(A | v);

  DISP(u);
  DISP(v);
  DISP(A);
  DISP(u | A | v);
  DISP(u | (2 * A - 1) | (10 * sin(pi / 2 * v) + 5));

  CR();
  MOUT << "done: " << CREATESTYLE(BOLD).apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
