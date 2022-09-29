#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;




  OUTPUT("Mathématiques");
  GMD_VSPACE();
  GMD_HEADER2("Examples");

  OUTPUT("Contraction of of simple (non-field) 3D vectors");

  GMD_HEADER3("Rank 1: Vectors and Covectors");
  {
    GMD_CODE_START("C++");
    ECHO(using namespace mathq::TensorIndex);
    ECHO(Vector<double, 3>::Tensor<COVARIANT> covec);
    ECHO(covec = { 1,2,3 });
    ETV(covec);
    CR();

    ECHO(Vector<double, 3>::Tensor<CONTRAVARIANT> vec);
    ECHO(vec = { 3,2,1 });
    ETV(vec);
    CR();

    ETV(covec(vec));
    ETV(vec(covec));
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER3("Rank 2 Tensors and the metric tensor");
  {
    GMD_CODE_START("C++");
    ECHO(using namespace mathq::TensorIndex);
    ECHO(using namespace std::numbers);

    ECHO(double r = 5);
    ECHO(double theta = pi/2);
    ECHO(Matrix<double, 3, 3>::Tensor<L, L> g{ {1, 0, 0}, {0, pow(r,2), 0}, {0, 0 , pow(r*sin(theta),2)} });
    ETV(g);
    CR();

    ECHO(Matrix<double, 3, 3>::Tensor<H, H> ginv{ {1, 0, 0}, {0, pow(r,-2), 0}, {0, 0 , pow(r*sin(theta),-2)} });
    ETV(ginv);
    CR();

    // ETV(covec(vec));
    // ETV(vec(covec));
    GMD_CODE_END();
  }

  return 0;
}
