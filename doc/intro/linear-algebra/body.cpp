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

  CR();
  OUTPUT("| function | operator form | operation | standard notation | rules |");
  OUTPUT("| :---: | :---: | :---: | :---: | :---: | ");
  OUT("| `dot(v, w)` ");
  OUT("| `v \\| w` ");
  OUT("| inner product ");
  OUT("| $\\mathbf{v} \\cdot \\mathbf{w} = \\displaystyle\\sum_{i=1}^{N} v_i w_i$ ");
  OUT("| both vectors must be of same length | ");
  CR();

  OUT("| `tensor_product(v,w)` ");
  OUT("| `v & w` ");
  OUT("| outer/tensor product ");
  OUT("| $\\mathbf{v} \\mathbf{w} = \\left[ v_i w_j \\right]$ ");
  OUT("| none | ");
  CR();


  OUT("| `cross(v,w)` ");
  OUT("| `v ^ w` ");
  OUT("| cross product ");
  OUT("| $\\mathbf{v} \\times \\mathbf{w} = \\left(  v_2 w_3 - v_3 w_2, \\enspace v_3 w_1 - v_1 w_3, \\enspace v_1 w_2 - v_2 w_1 \\right)$ ");
  OUT("| $N = 3$ | ");
  CR();

  OUT("| `conj(v)` ");
  OUT("| `~v` ");
  OUT("| complex conjugate ");
  OUT("| $\\mathbf{v}^*$ ");
  OUT("| none | ");
  CR();

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

  GMD_VSPACE();
  GMD_HEADER3("Matrix");

  CR();
  OUTPUT("| function | operator form | operation | standard notation | rules |");
  OUTPUT("| :---: | :---: | :---: | :---: | :---: | ");
  OUT("| `dot(A, B)` ");
  OUT("| `A \\| B` ");
  OUT("| inner product ");
  OUT("| $\\mathbf{A} \\cdot \\mathbf{B} = \\displaystyle\\sum_{j=1}^{M} A_{ij} B_{jk}$ ");
  OUT("| $\\left. \\begin{array}{c} \\mathbf{A} = L \\!\\!\\times\\!\\! M \\,\\text{matrix} \\\\ \\mathbf{B} = M \\!\\!\\times\\!\\! N \\,\\text{matrix} \\end{array}  \\right.$ | ");
  CR();

  OUT("| `tensor_product(A,B)` ");
  OUT("| `A & B` ");
  OUT("| outer/tensor product ");
  OUT("| $\\mathbf{A} \\mathbf{B} = \\left[ A_{ij} B_{kl} \\right]$ ");
  OUT("| none | ");
  CR();

  OUT("| `conj(A)` ");
  OUT("|  ");
  OUT("| conjugate ");
  OUT("| $ \\left\\\\{ \\begin{array}{cc} \\mathbf{A} & \\mathbf{A}  \\text{real} \\\\\\\\ \\mathbf{A}^{*}  & \\mathbf{A} \\;  \\text{complex}  \\end{array} \\right. $ ");
  OUT("| none | ");
  CR();

  OUT("| `transpose(A)` ");
  OUT("|  ");
  OUT("| transpose ");
  OUT("| $ \\left\\{ \\begin{array}{cc} \\mathbf{A}^{T} & \\mathbf{A} \\; \\text{real} \\\\ \\mathbf{A}^{T}  & \\mathbf{A} \\;  \\text{complex}  \\end{array} \\right. $ ");
  OUT("| none | ");
  CR();

  OUT("| `adjoint(A)` ");
  OUT("| `~A` ");
  OUT("| adjoint ");
  OUT("| $ \\left\\{ \\begin{array}{cc} \\mathbf{A}^{T} & \\mathbf{A} \\; \\text{real} \\\\ \\mathbf{A}^{\\dagger} = \\mathbf{A}^{T*}  & \\mathbf{A} \\;  \\text{complex}  \\end{array} \\right. $ ");
  OUT("| none | ");
  CR();

  CR();


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
  OUTPUT("| function | operator form | operation | standard notation | rules |");
  OUTPUT("| :---: | :---: | :---: | :---: | :---: | ");
  OUT("| `dot(v, A)` ");
  OUT("| `v \\| A` ");
  OUT("| inner product ");
  OUT("| $\\mathbf{v} \\cdot \\mathbf{A} = \\displaystyle\\sum_{i=1}^{M} v_{i} A_{ij}$ ");
  OUT("| $\\left. \\begin{array}{c} \\mathbf{v} = \\text{length}\\, M \\,\\text{vector} \\\\ \\mathbf{A} = M \\!\\!\\times\\!\\! N \\,\\text{matrix} \\end{array}  \\right.$ | ");
  CR();

  OUT("| `dot(A, v)`");
  OUT("| `A \\| v`");
  OUT("| inner product ");
  OUT("| $\\mathbf{A} \\cdot \\mathbf{v} = \\displaystyle\\sum_{j=1}^{N}  A_{ij} v_{j}$ ");
  OUT("| $\\left. \\begin{array}{c} \\mathbf{A} = M \\!\\!\\times\\!\\! N \\,\\text{matrix} \\\\ \\mathbf{v} = \\text{length}\\, N \\,\\text{vector} \\end{array}  \\right.$ | ");
  CR();

  OUT("| `tensor_product(v, A)` ");
  OUT("| `v & A` ");
  OUT("| outer/tensor product ");
  OUT("| $\\mathbf{v} \\mathbf{A} = \\left[ v_{i} A_{jk} \\right]$ ");
  OUT("| none | ");
  CR();

  OUT("| `tensor_product(A, v)` ");
  OUT("| `A & v` ");
  OUT("| outer/tensor product ");
  OUT("| $\\mathbf{A} \\mathbf{v}  = \\left[ A_{jk} v_{l} \\right]$ ");
  OUT("| none | ");
  CR();

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
