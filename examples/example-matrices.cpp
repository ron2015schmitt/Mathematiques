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

  CR();
  Vector<double> u = { 2, -1 };
  DISP(u);
  Vector<double> v = { 5, -5 };
  DISP(v);
  Matrix<double> A = { {1, 2}, {3, 4}, {5, 6} };
  DISP(A);
  Vector<double> w = { 2, 1, -2 };
  DISP(w);
  Matrix<double, 2, 2> B = { {10, 20}, {30, 40} };
  DISP(B);
  // when the size is specified, you can also initialize using a flat list
  Matrix<double, 2, 2> C = { -1, -2, -3, -4 };
  DISP(C);

  CR();
  DISP(u + v);
  DISP(u | v);


  CR();
  DISP((A | u));
  DISP((w | A));

  CR();
  DISP(B + C);
  DISP(B | C);
  DISP(A | B);
  DISP(C | A.transpose());

  DISP(u | (B+C) | v);
  DISP(u | (2 * A - 1) | (10 * sin(pi / 2 * v) + 5));


  CR();
  MOUT << "done: " << CREATESTYLE(BOLD).apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
