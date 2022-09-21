#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  GMD_VSPACE();
  GMD_HEADER2("Inner Product, Outer Product, Transpose");
  GMD_HEADER3("`Vector`");

  OUTPUT("Keep in mind that in Mathématiques, a `Vector<double>` (aka `MultiArray<double,1>`) is neither a column nor a row vector. Instead vectors `Vector<double>` are denoted as vectors are denoted in physics*.");
  OUTPUT("Of course, if you really want row and column vectors, use `Matrix<double,N,1>` and `Matrix<double,N,1>` respectively, although this is not necessary. (Refer to the linear algebra notation section below.");


  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v{ 1, 2, 3 });
    ECHO(Vector<double> w{ 2, 4, -3 });
    ETV(v | w);
    ETV(v & w);
    GMD_CODE_END();
  }




  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO(Matrix<double> A{ {1, 2}, {3, 4} });
    ECHO(Matrix<double> B{ {11, 22}, {33, 44} });
    ETV(A | B);
    ETV(A & B);
    CR();
    ETV(conj(A));
    ETV(transpose(A));
    ETV(~A);
    CR();
    ECHO(Matrix<std::complex<double>> D{ { 1 + 10i, 2 + 20i }, { 3 + 30i, 4 + 40i } });
    ETV(D);
    ETV(conj(D));
    ETV(transpose(D));
    ETV(~D);
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER3("Matrix and Vector");

  CR();


  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v{ 1, 2 });
    ECHO(Matrix<double> A{ {1, 2}, {3, 4} });
    CR();
    ETV(v | A);
    ETV(A | v);
    CR();
    ETV(v & A);
    ETV(A & v);
    CR();
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER3("General MultiArrays");

  CR();
  OUTPUT("The above functions are extended to general MultiArrays of any rank.  The transpose is defined by reverse all the indices. ");


  return 0;
}
