#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  OUTPUT("Mathématiques supports arithmetic, relational, and logic operators for MultiArrays.");
  OUTPUT("All operators perform operations in an element-wise manner.");
  OUTPUT("The section demonstrates operators on two containers of the same `rank`, `dimensions`, and `depth`.\n");

  GMD_HEADER2("Arithmetic Operators");
  OUTPUT("The operators `+, -, *, /` are the addition, subtraction, multiplication, and division operators respectively.\n");

  {
    CR();
    OUTPUT("| operator | operation |");
    OUTPUT("| :---: | :---: | ");
    OUTPUT("| `+` | addition | ");
    OUTPUT("| `-` | subtraction | ");
    OUTPUT("| `*` | multiplication | ");
    OUTPUT("| `/` | division | ");
    CR();
  }

  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ETV((Vector<double>{1, 2, 3} + Vector<double>{1, -2, 10}));
    CR();
    ETV((Matrix<double>{ {11, 22}, { 33, 44 }} - Matrix<double>{ {1, 2}, { 3, 4 }}));
    CR();
    ETV((MultiArray<double, 3>{ { {1, 2}, { 3, 4 }}, { {5, 6}, { 7, 8 } }} *MultiArray<double, 3>{ { {10, 10}, { 100, 100 }}, { {1000, 1000}, { 10000, 10000 } }}));
    CR();
    ETV((Vector<double>{24, 24, 24} / Vector<double>{2, 3, 4}));
    CR();
    GMD_CODE_END();
  }

  OUTPUT("Operators also work on nested multiarrays, ie multiarrays with depth greater then 1.");
  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO(Vector<Matrix<double>> v{ {{1, 2}, {3, 4}}, {{11, 12}, {13, 14}} });
    CR();
    ETV((v*v + 10*v)/(2*v-v));
    CR();
    GMD_CODE_END();
  }

  GMD_VSPACE();
  GMD_HEADER2("Relational Operators");

  CR();
  OUTPUT("| operator | operation | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `==` | equal to | ");
  OUTPUT("| `!=` | not equal to | ");
  OUTPUT("| `<` | less than | ");
  OUTPUT("| `<=` | less than or equal to | ");
  OUTPUT("| `>` | greater than | ");
  OUTPUT("| `>=` | greater than or equal to | ");
  // OUTPUT("| `<=>` | three-way comparison | ");
  CR();

  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ETV((Vector<double>{1, 2, 3} == Vector<double>{1, -1, 3}));
    ETV((Vector<double>{1, 2, 3} < Vector<double>{1, 10, 0}));
    GMD_CODE_END();
  }

  GMD_VSPACE();
  GMD_HEADER2("Logic Operators");

  CR();
  OUTPUT("| operator | operation | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `!` | logical NOT | ");
  OUTPUT("| `\\|\\|` | logical OR | ");
  OUTPUT("| `&&` | logical AND | ");
  CR();

  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v1{ 1, 2, 3 });
    ECHO(Vector<double> v2{ 11, 22, 33 });
    ETV(!(v1 < v2));
    CR();
    ECHO(Vector<double> v{ 5, 7, 1 });
    ETV((v1 < v) && (v < v2));
    GMD_CODE_END();
  }

  GMD_VSPACE();
  return 0;
}
