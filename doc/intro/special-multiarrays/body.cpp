#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  // using namespace mathq::unit_quaternion;
  // using namespace mathq::unit_imaginary;
  // using std::sqrt;

  OUTPUT("Mathématiques ");


  GMD_VSPACE();
  GMD_HEADER2("Constant MultiArrays");

  OUTPUT("These multiarrays have the same value for each element, and only take the memory profile a single element (plus dimensions integers for dynamic multiarrays).");

  GMD_HIDDEN_START("Constant MultiArray Examples");

  CR();
  GMD_HEADER3("Vector_Constant");
  CR();
  {
    GMD_CODE_START("C++");
    ECHO(Vector_Constant<double, 5> v{ 3.14 });
    CR();
    ETV(v);
    CR();
    ETV(sizeof(v)/sizeof(double));
    GMD_CODE_END();
  }

  CR();
  GMD_HEADER3("Dynamic-length Vector_Constant");
  CR();
  {
    GMD_CODE_START("C++");
    ECHO(Vector_Constant<double> v{ 5, 3.14 });
    CR();
    ETV(v);
    CR();
    ETV(sizeof(v)/sizeof(double));
    GMD_CODE_END();
  }


  CR();
  GMD_HEADER3("Matrix_Constant");\
    CR();
  {
    GMD_CODE_START("C++");
    ECHO(Matrix_Constant<double, 2, 3> A{ 3.14 });
    CR();
    ETV(A);
    CR();
    ETV(sizeof(A)/sizeof(double));
    GMD_CODE_END();
  }

  CR();
  GMD_HEADER3("Dynamic-length Matrix_Constant");
  CR();
  {
    GMD_CODE_START("C++");
    ECHO(Matrix_Constant<double> A(Dimensions{ 2, 3 }, 3.14));
    CR();
    ETV(A);
    CR();
    ETV(sizeof(A)/sizeof(double));
    GMD_CODE_END();
  }

  CR();
  GMD_HEADER3("MultiArray_Constant");\
    CR();
  {
    GMD_CODE_START("C++");
    ECHO(MultiArray_Constant<double, 3, 1, 2, 3> A{ 3.14 });
    CR();
    ETV(A);
    CR();
    ETV(sizeof(A)/sizeof(double));
    GMD_CODE_END();
  }

  CR();
  GMD_HEADER3("Dynamic-length MultiArray_Constant");
  CR();
  {
    GMD_CODE_START("C++");
    ECHO(MultiArray_Constant<double, 3> A(Dimensions{ 1, 2, 3 }, 3.14));
    CR();
    ETV(A);
    CR();
    ETV(sizeof(A)/sizeof(double));
    GMD_CODE_END();
  }
  CR();

  GMD_HIDDEN_END();





  GMD_VSPACE();
  GMD_HEADER2("Repeated Vector MultiArrays");

  OUTPUT("These multiarrays vary along only one indices, which implies that they can be specified by a single vector.  For `rank=2`, this results in either a repeated-column matrix (`index=0`) or a repeated-row matrix (`index=1`) .");

  GMD_HIDDEN_START("Repeated Vector MultiArray Examples");


  CR();
  GMD_HEADER3("Matrix_RepeatVector");

  CR();
  GMD_HEADER4("Repeated Column Matrix");
  OUTPUT("Set the varying index to zero.");
  CR();
  {
    GMD_CODE_START("C++");
    ECHO(Matrix_RepeatVector<double, 2, 3 > A(0, { 1.1, 2.2 }));
    CR();
    ETV(A);
    CR();
    ETV(sizeof(A)/sizeof(double));
    GMD_CODE_END();
  }
  CR();

  CR();
  GMD_HEADER4("Repeated Row Matrix");
  OUTPUT("Set the varying index to one.");
  CR();
  {
    GMD_CODE_START("C++");
    ECHO(Matrix_RepeatVector<double, 2, 3 > A(1, { 1.1, 2.2, 3.3 }));
    CR();
    ETV(A);
    CR();
    ETV(sizeof(A)/sizeof(double));
    GMD_CODE_END();
  }
  CR();

  GMD_HIDDEN_END();


  GMD_VSPACE();
  GMD_HEADER2("Special MultiArrays In Development");

  OUTPUT("🚧 in progress...");

  GMD_VSPACE();
  OUTPUT("* Block Matrix");
  OUTPUT("* Zero Matrix, **`0`**, useful for block matrices");
  OUTPUT("* Identity Matrix, **`I`**");
  OUTPUT("* Exchange Matrix, **`J`**");
  CR();

  GMD_VSPACE();
  OUTPUT("* Diagonal Matrix");
  OUTPUT("* Cross-Diagonal Matrix");
  CR();

  GMD_VSPACE();
  OUTPUT("* Upper-Triangle Matrix");
  OUTPUT("* Lower-Triangle Matrix");
  OUTPUT("* Symmetric Matrix");
  OUTPUT("* Skew Symmetric Matrix");
  OUTPUT("* Hermitian Matrix");
  OUTPUT("* Skew Hermitian Matrix");
  OUTPUT("* Toeplitz Matrix");
  OUTPUT("* Vandermonde Matrix");
  CR();

  GMD_VSPACE();
  OUTPUT("* Sparse MultiArray");
  OUTPUT("* Levi-Cevita Symbol MultiArray");
  OUTPUT("* Pauli matrices and Gamma matrices");
  CR();



  GMD_VSPACE();
  return 0;
}
