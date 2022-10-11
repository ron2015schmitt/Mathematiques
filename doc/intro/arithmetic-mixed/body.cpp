#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  OUTPUT("Mathématiques also supports operators between objects (multi-arrays and numbers) of different rank and depth, when such operations make sense.");

  GMD_VSPACE();
  GMD_HEADER2("Rank, Depth, and Dimensions");

  OUTPUT("Notice that Number types (eg `bool`, `int`, `double`, `std::complex`, etc) have both zero rank and zero depth, whereas the `Scalar` multiarray has rank zero but depth one. `Scalar` multiarrays are needed to serve as the base class for scalar NumericalFunctions. ");

  GMD_HEADER3("Function `rank`");
  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ETV(mathq::rank(2));
    CR();
    ETV(mathq::rank(Scalar<double>{42}));
    ETV(mathq::rank(Vector<double>{1, 2}));
    ETV(mathq::rank(Matrix<double>{ {1, 2}, { 3,4 }}));
    ETV(mathq::rank(MultiArray<double, 3>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }));
    CR();
    ETV(mathq::rank(Vector<Matrix<double>>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }));
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER3("Function `depth`");
  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ETV(mathq::depth(2));
    CR();
    ETV(mathq::depth(Scalar<double>{42}));
    ETV(mathq::depth(Vector<double>{1, 2}));
    ETV(mathq::depth(Matrix<double>{ {1, 2}, { 3,4 }}));
    ETV(mathq::depth(MultiArray<double, 3>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }));
    CR();
    ETV(mathq::depth(Vector<Matrix<double>>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }));
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER3("Function `dimensions`");
  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ETV(mathq::dimensions(2));
    CR();
    ETV(mathq::dimensions(Scalar<double>{42}));
    ETV(mathq::dimensions(Vector<double>{1, 2}));
    ETV(mathq::dimensions(Matrix<double>{ {1, 2}, { 3,4 }}));
    ETV(mathq::dimensions(MultiArray<double, 3>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }));
    CR();
    ETV(mathq::dimensions(Vector<Matrix<double>>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }));
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER2("Number/`Scalar` `op` `MultiArray`");

  OUTPUT("As in matlab, a MultiArray can be paired with a Number or `Scalar` with any operator.");

  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ETV(Vector<double>{1, 2}+10);
    CR();
    ETV(2*Scalar<double>{42});
    ETV(Vector<double>{1, 2} == 1);
    ETV(Matrix<double>{ {1, 2}, { 3,4 }} - 1);
    ETV(MultiArray<double, 3>{ { {7, 14}, { 21, 28 }}, { {35, 42}, {49, 56} } } / 7);
    CR();
    ETV(Vector<Matrix<double>>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } } > 5);
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER2("`MultiArray`s of different depth");

  OUTPUT("`MultiArray`s of different depths can be paired, where it makes sense.");
  OUTPUT("For example, a 2x2 matrix can be added to a vector of 2x2 matrices.");
  OUTPUT("Another example is adding a vector of length 2 to a vector of matrices that is also of length 2. Both cases are shown below.  ");

  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO(Matrix<double> A{ {100, 200}, { 300,400 } });
    ECHO(Vector<Matrix<double>> v{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } });
    CR();
    ETV(A+v);
    CR();
    ECHO(Vector<double> w{ -1, 2 });
    ETV(v*w);
    GMD_CODE_END();
  }



  GMD_VSPACE();
  return 0;
}
