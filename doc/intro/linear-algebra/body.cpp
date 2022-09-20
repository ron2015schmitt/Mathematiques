#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  GMD_VSPACE();
  GMD_HEADER2("Products: Inner, Outer, and Wedge");
  GMD_HEADER3("`Vector`");

  OUTPUT("Keep in mind that in Mathématiques, a `Vector<double>` (aka `MultiArray<double,1>`) is neither a column nor a row vector. Instead vectors `Vector<double>` are denoted as vectors are denoted in physics*.");
  OUTPUT("Of course, if you really want row and column vectors, use `Matrix<double,N,1>` and `Matrix<double,N,1>` respectively, although this is not necessary. (Refer to the linear algebra notation section below.");

  CR();
  OUTPUT("| operator | operation | standard notation | rules |");
  OUTPUT("| :---: | :---: | :---: | :---: | ");

  OUT("| `v \\| w` ");
  OUT("| inner product ");
  OUT("| $\\braket{\\mathbf{v},\\mathbf{w}} = \\left\\{ \\begin{array}{cc} \\mathbf{v} \\cdot \\mathbf{w}, & \\in \\mathbb{R}^N  \\\\ \\mathbf{v}^* \\cdot \\mathbf{w}, & \\in \\mathbb{C}^N, \\mathbb{Q}^N \\end{array} \\right.$ ");
  OUT("| both vectors must be of same length | ");
  CR();

  OUT("| `v & w` ");
  OUT("| outer/tensor product ");
  OUT("| $\\mathbf{v} \\mathbf{w} = \\left\\{ \\begin{array}{cc} \\mathbf{v} \\mathbf{w}, & \\in \\mathbb{R}^N  \\\\ \\mathbf{v}^*  \\mathbf{w}, & \\in \\mathbb{C}^N, \\mathbb{Q}^N \\end{array} \\right.$ ");
  OUT("| none | ");
  CR();

  // OUTPUT("| `v & w` |  | $\\mathbf{v} \\mathbf{w}$ | none | ");
  OUTPUT("| `v ^ w` | wedge product<sup>🚧</sup> | $\\mathbf{v} \\wedge \\mathbf{w} = \\left[ \\mathbf{v} \\mathbf{w} \\right] = \\mathbf{v} \\mathbf{w} - \\mathbf{w} \\mathbf{v}$ | none | ");
  CR();
  OUTPUT("<sup>🚧</sup> wedge product is in progress. It requires completion of anti-symmetric (and anti-hermitian for complex numbers) matrices because the output will be of this type.");

  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO(Vector<double> A{ 1, 2, 3 });
    ECHO(Vector<double> B{ 2, 4, -3 });
    ETV(A|B);
    ETV(A&B);
    GMD_CODE_END();
  }

  GMD_HEADER3("Matrices");

  CR();
  OUTPUT("| operator | operation | standard notation | rules |");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `A \\| B` | inner product | $\\braket{\\mathbf{A},\\mathbf{B}}$ = $\\left\\{ \\begin{array}{cc} \\mathbf{A} \\cdot \\mathbf{B}, & \\in \\mathbb{R}^N  \\\\ \\mathbf{A}^* \\cdot \\mathbf{B}, & \\in \\mathbb{C}^N, \\mathbb{Q}^N \\end{array} \\right.$ | both vectors must be of same length |");
  OUTPUT("| `A & B` | outer product (tensor product) | $\\mathbf{A} \\mathbf{B}$ | none | ");
  OUTPUT("| `A ^ B` | wedge product<sup>🚧</sup> | $\\mathbf{A} \\wedge \\mathbf{B} = \\left[ \\mathbf{A} \\mathbf{B} \\right] = \\mathbf{A} \\mathbf{B} - \\mathbf{B} \\mathbf{A}$ | none | ");
  CR();
  OUTPUT("<sup>🚧</sup> wedge product is in progress. It requires completion of anti-symmetric (and anti-hermitian for complex numbers) matrices because the output will be of this type.");

  {
    CR();
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO(Matrix<double> A{ {1, 2}, {3, 4} });
    ECHO(Matrix<double> B{ {11, 22}, {33, 44} });
    ETV(A|B);
    ETV(A&B);
    GMD_CODE_END();
  }


  return 0;
}
