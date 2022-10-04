#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;



  GMD_HEADER2("Background");

  OUTPUT("Mathématiques supports tensors and generalized coordinates. ");
  OUTPUT("Let $\\vec{x}=(x_1,x_2,x_3)$ be Cartesian coordinates for 3D (flat) space.  ");
  OUTPUT("and let $(q_1,q_2,q_3)$ be a set of generalized coordinates.  ");
  OUTPUT("Then the *basis* is given by the vectors.");
  CR();
  OUTPUT("$$ \\vec{e}_1 \\doteq \\frac{\\partial \\vec{x}}{\\partial q^1} , \\enspace \\vec{e}_2 \\doteq \\frac{\\partial \\vec{x}}{\\partial q^2} , \\enspace \\vec{e}_3 \\doteq \\frac{\\partial \\vec{x}}{\\partial q^3} $$");
  CR();
  OUTPUT("And the *reciprocal basis* is given by the vectors.");
  CR();
  OUTPUT("$$ \\vec{e}^1 \\doteq \\vec{\\nabla} q^1 , \\enspace \\vec{e}^2 \\doteq \\vec{\\nabla} q^2 , \\enspace \\vec{e}^3 \\doteq \\vec{\\nabla} q^3 $$");
  CR();
  OUTPUT("The vectors of the basis and reciprocal basis are mutually orthonormal");
  CR();
  OUTPUT("$$ \\vec{e} \\lower 2pt {i} \\cdot \\vec{e}^j = \\delta \\lower 2pt {ij}$$");
  CR();
  OUTPUT("where $\\delta_{ij}$ is the [Kroencker delta](https://en.wikipedia.org/wiki/Kronecker_delta) ");

  GMD_VSPACE();
  GMD_HEADER2("Rank 1: Contravariant and Covariant Vectors");
  GMD_HEADER3("Contravariant Vectors");
  OUTPUT("A vector written in terms of the basis");
  CR();
  OUTPUT("$$ \\vec{A} = \\sum_{i=1}^{3}  A^i \\vec{e}_i $$");
  CR();
  OUTPUT("is referred to as contravariant form.  Note that the indices are superscripted or 'high'.");
  OUTPUT("In Mathématiques a contravariant vector can be declared as follows");

  {
    GMD_CODE_START("C++");
    using namespace mathq::TensorIndex;
    ECHO(Vector<double, 3>::Tensor<CONTRAVARIANT> A);
    GMD_CODE_END();
  }

  OUTPUT("or");
  {
    GMD_CODE_START("C++");
    using namespace mathq::TensorIndex::LH;
    ECHO(Vector<double, 3>::Tensor<H> A);
    GMD_CODE_END();
  }


  GMD_HEADER3("Covariant Vectors");
  OUTPUT("A vector written in terms of the reciprocal basis");
  CR();
  OUTPUT("$$ \\vec{A} = \\sum_{i=1}^{3}  A_i \\vec{e}^i $$");
  CR();
  OUTPUT("is referred to as covariant form.  Note that the indices are subscripted or 'low'.");
  OUTPUT("In Mathématiques a covariant vector can be declared as follows");

  {
    GMD_CODE_START("C++");
    using namespace mathq::TensorIndex;
    ECHO(Vector<double, 3>::Tensor<COVARIANT> A);
    GMD_CODE_END();
  }

  OUTPUT("or");
  {
    GMD_CODE_START("C++");
    using namespace mathq::TensorIndex::LH;
    ECHO(Vector<double, 3>::Tensor<L> A);
    GMD_CODE_END();
  }




  GMD_HEADER2("Inner product of rank 1 tensors");

  OUTPUT("From the mutual othonormality of the bases, the inner product of two vectors can be written");
  CR();
  OUTPUT("$$ \\vec{A} \\cdot \\vec{B} = A_i B^i$$");
  CR();
  OUTPUT("where we have used the [Einstein summation convention](https://en.wikipedia.org/wiki/Einstein_notation).");
  OUTPUT("Mathématiques uses modern tensor notation, and we write the inner product as either $A(B)$ or $B(A)$.");
  {
    GMD_CODE_START("C++");
    ECHO(using namespace mathq::TensorIndex::LH);
    ECHO(Vector<double, 3>::Tensor<L> A{ 1,2,3 });
    ETV(A);
    CR();

    ECHO(Vector<double, 3>::Tensor<H> B{ 1,25,25 });
    ETV(B);
    CR();

    ETV(A(B));
    ETV(B(A));
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER3("Rank 2 Tensors and the metric tensor");

  OUTPUT("A rank 2 tensor has the same number of elements as a matrix, but now there are four forms: $A_{ij}$, ${A_i}^{j}$, ${A^i}_{j}$, and $A^{ij}$");
  OUTPUT("The most important rank 2 tensor is the [metric tensor](https://en.wikipedia.org/wiki/Metric_tensor), $g_{ij}$, which determined by the generalized coordinates used.");
  OUTPUT("The metric tensor allows the conversion of a contravariant vector into a covariant vector.");
  CR();
  OUTPUT("$$ g(V,\\cdot) =  g_{ij} V^i  = V_j$$");
  CR();
  OUTPUT("It also then allows us to take the inner product of two contravariant vectors");
  CR();
  OUTPUT("$$ g(V,W) =  g_{ij} V^i W^j  = V_i W^i$$");
  CR();
  OUTPUT("The code for these operations are given below");
  {
    GMD_CODE_START("C++");
    ECHO(using namespace mathq::TensorIndex::LH);
    ECHO(using namespace std::numbers);

    ECHO(double r = 5);
    ECHO(double theta = pi/2);
    ECHO(Matrix<double, 3, 3>::Tensor<L, L> g{ {1, 0, 0}, {0, pow(r,2), 0}, {0, 0 , pow(r*sin(theta),2)} });
    CR();
    ETV(g);
    CR();

    ECHO(Vector<double, 3>::Tensor<H> V{ 1,2,3 });
    ECHO(Vector<double, 3>::Tensor<H> W{ 1,1,1 });
    ECHO(const NullType o);
    CR();
    ETV(g(V, o));
    ETV(g(V, W));
    ETV(g(o, W));

    CR();
    ETV(g(V, V));
    ETV(g(V, o)(V));
    GMD_CODE_END();
  }

  // ECHO(Matrix<double, 3, 3>::Tensor<H, H> ginv{ {1, 0, 0}, {0, pow(r,-2), 0}, {0, 0 , pow(r*sin(theta),-2)} });
  // ETV(ginv);
  // CR();


  GMD_VSPACE();
  GMD_HEADER2("Tensor Fields and Calculus");
  OUTPUT("* full support for generalized coordinates (`TensorCoords`) and tensor fields (`TensorField`) is under way.\n");
  OUTPUT("* method to pretty-print tensors, eg\n");
  OUTPUT("  * contravariant: 2.35 ∇r + 3.43 ∇θ\n");
  OUTPUT("  * covariant:  5.0 ∂**x**/∂r + 4.32 ∂**x**/∂θ\n");
  OUTPUT("* Support for tensors in Riemannian geometry, differential forms etc\n");



  return 0;
}
