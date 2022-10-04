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
  OUTPUT("$$ f(z) = e^{10*z} $$");
  OUTPUT("$$ \\frac{df}{dz} $$");
  OUTPUT("$$ \\frac{df}{dz^*} $$");


  {
    GMD_CODE_START("C++");
    CR();
    ECHO(ComplexCoords<double, false> coords({
      Interval<double>::interval(-2, 2, 5),
      Interval<double>::interval(-2, 2, 5)
      }));
    ECHO(ComplexMathFunction<std::complex<double>, decltype(coords)> f(coords));

    ECHO(auto& z = coords.z());
    ETV(z);
    CR();

    ECHO(f() = exp(10*z));
    ETV(f);
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
  OUTPUT("$$ f(z) = \\frac{z + 1}{z - 1} $$");
  OUTPUT("$$ \\frac{df}{dz} $$");
  OUTPUT("$$ \\frac{df}{dz^*} $$");

  {
    GMD_CODE_START("C++");
    CR();
    ECHO(ComplexMathFunction<std::complex<double>, ComplexCoords<double, false>> f({
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 5)
      }));

    // ECHO(auto& cc = f.coords());
    ECHO(auto& z = f.coords().z());
    ECHO(f() = (z + 1)/(z - 1));
    ETV(f);
    ETV(dz(f));
    ETV(dz_star(f));
    GMD_CODE_END();
  }

  CR();
  CR();

  GMD_VSPACE();
  return 0;
}
