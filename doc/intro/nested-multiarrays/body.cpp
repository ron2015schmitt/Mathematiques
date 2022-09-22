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

  OUTPUT("MultiArrays can contain any number type, eg `int`, `double`, `complex<float>`, `Quaternion<extended>`.");
  OUTPUT("Additionally, the elements of a `MultiArray` can be another type of `MultiArray`.");
  OUTPUT("These containers can be nested any number of levels.");
  OUTPUT("Nesting of multiarrays also allows for the creation of *block matrices*.");



  GMD_HEADER3("Vector of Matrices");

  OUTPUT("A Vector of Matrices is useful for storing the values of a vector field on a grid of points");

  {
    GMD_CODE_START("C++");
    ECHO(Vector<Matrix<double, 2, 2>, 3> E);
    E[0] = { {1, 2}, {3, 4} };
    E[1] = { {-1, -2}, {-3, -4} };
    E[2] = { {11, 12}, {13, 14} };
    ETV(E);
    CR();
    ETV(E[0]);
    CR();
    ETV(E[0](0, 1));
    GMD_CODE_END();
  }

  GMD_HEADER3("Matrix of Vectors");

  OUTPUT("A Matrix of Vectors can also be used for storing the values of a vector field on a grid of points");

  {
    GMD_CODE_START("C++");
    ECHO(Matrix<Vector<double, 3>, 2, 2> E);
    E(0, 0) = { {1, -1, 11} };
    E(0, 1) = { {2, -2, 12} };
    E(1, 0) = { {3, -3, 13} };
    E(0, 1) = { {4, -4, 14} };
    ETV(E);
    CR();
    ETV(E(0, 0));
    CR();
    ETV(E(0, 1)[1]);
    GMD_CODE_END();
  }

  GMD_HEADER3("Eversion - turning a structure inside out");

  OUTPUT("A `Vector` of Matrices can be converted to a `Matrix` of `Vector`s and vice verse");
  {
    GMD_CODE_START("C++");
    ECHO(Vector<Matrix<double, 2, 2>, 3> E{
      { {1, 2}, {3, 4} },
      { {-1, -2}, {-3, -4} },
      { {11, 12}, {13, 14} }
      });
    ETV(E);
    CR();
    ETV(evert(E));
    CR();
    ETV(evert(evert(E)));
    GMD_CODE_END();
  }


  GMD_VSPACE();
  return 0;
}
