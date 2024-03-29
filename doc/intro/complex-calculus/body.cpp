#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  OUTPUT("Mathématiques supports complex domains, ie functions of a complex variable.");


  // template <typename GridElement, size_t Ndims, bool TimeCoord, typename TargetElement = GridElement>
  // using NumericalFunction = CurvilinearField<TargetElement, 0, CartesianCoords<GridElement, Ndims, TimeCoord>>;  {

  CR();

  GMD_HEADER3("Example 1");
  OUTPUT("As an example consider the function:");
  CR();
  OUTPUT("$$ f\\colon [-2,2] \\times i[-2,2] \\rightarrow\\mathbb{C}$$");
  CR();
  OUTPUT("$$ f(z) = e^{10 z} $$");
  CR();
  OUTPUT("$$ \\frac{df}{dz} $$");
  CR();
  OUTPUT("$$ \\frac{df}{dz^*} $$");
  CR();

  OUTPUT("Code");
  CR();

  {
    GMD_CODE_START("C++");
    ECHO(ComplexCoords<double, false> coords({
      Interval<double>::interval(-2, 2, 5),
      Interval<double>::interval(-2, 2, 5)
      }));
    ECHO(ComplexMathFunction<std::complex<double>, decltype(coords)> f(coords));

    CR();
    ECHO(auto& z = coords.z());
    ECHO(f = exp(10*z));
    GMD_CODE_END();

    CR();
    OUTPUT("Results");
    CR();

    GMD_CODE_START("C++");
    ETV(z);
    CR();
    ETV(f);
    CR();
    ETV(dz(f));
    ETV(dz_star(f));
    CR();
    GMD_CODE_END();
  }

  GMD_VSPACE();
  GMD_HEADER3("Example 2");
  OUTPUT("Consider the function:");
  CR();
  OUTPUT("$$ f\\colon [-2,2] \\times i[-2,2] \\rightarrow\\mathbb{C}$$");
  CR();
  OUTPUT("$$ f(z) = \\frac{z + 1}{z - 1} $$");
  CR();
  OUTPUT("$$ \\frac{df}{dz} $$");
  CR();
  OUTPUT("$$ \\frac{df}{dz^*} $$");
  CR();
  OUTPUT("Code");
  CR();

  {
    GMD_CODE_START("C++");
    CR();
    ECHO(ComplexMathFunction<std::complex<double>, ComplexCoords<double, false>> f({
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 5)
      }));
    ECHO(auto& z = f.coords().z());
    ECHO(f = (z + 1)/(z - 1));
    GMD_CODE_END();
    CR();
    OUTPUT("Results");
    CR();
    GMD_CODE_START("C++");
    ETV(f);
    ETV(dz(f));
    ETV(dz_star(f));
    GMD_CODE_END();
    CR();
  }

  CR();
  CR();

  GMD_VSPACE();
  return 0;
}
