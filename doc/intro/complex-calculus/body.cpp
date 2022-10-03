#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  OUTPUT("Mathématiques provides classes and extensive functionality for single- and multi-variate numerical functions, ie formal mathematical functions over a discretized domain.");


  // template <typename GridElement, size_t Ndims, bool TimeCoord, typename TargetElement = GridElement>
  // using NumericalFunction = CurvilinearField<TargetElement, 0, CartesianCoords<GridElement, Ndims, TimeCoord>>;  {

  GMD_HEADER2("Introduction");

  OUTPUT("The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. ");
  OUTPUT("With this defintion, we can create a function, e.g. $f(x) = 1 + x + \\frac{x^2}{2} + \\frac{x^3}{6} + \\frac{x^4}{24}$ ");

  {
    GMD_CODE_START("C++");
    ECHO(NumericalFunction<double> f);

    CR();
    ECHO(auto x = f.coordinates[0]);
    EV(x);
    CR();
    ECHO(f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24);
    EV(f);
    CR();
    GMD_CODE_END();
    CR();

    OUTPUT("To access the data as a Vector, use paretheses, `f()`.  The `NumericalFunction` type is actually a rank 0 (ie. scalar) `CurvilinearField`, which will be discussed in a later section.");

    CR();
    GMD_CODE_START("C++");
    ETV(f());
    ETV(f()[0]);
    ETV(f()[{1, 3}]);
    GMD_CODE_END();
    CR();


    OUTPUT("We can easily create a second function, e.g. $g(x) = x + 2 f(x) - 4 \\frac{df}{dx}$ ");

    CR();
    GMD_CODE_START("C++");
    ECHO(NumericalFunction<double> g);
    CR();
    ECHO(g = x + 2*f - 4*d(f));
    EV(g);
    GMD_CODE_END();
    CR();
  }



  {
    OUTPUT("CurvilinearField - Complex 1D");
    ComplexRectangle<double> rect(
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 5)
    );
    ETV(rect);
    ETV(rect.dims());
    ETV(rect.grid_complex());
    ETV(rect.grid_real());
    ETV(rect.grid_imag());


    ComplexCoords<double, false> coords(rect);
    ETV(coords);
    ETV(coords.grid_dims());
    ETV(IsComplexCoords<decltype(coords)>);
    ETV(coords.x());
    ETV(coords.y());
    ETV(coords.z());

    ECHO(ComplexMathFunction<std::complex<double>, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(auto& z = coords.z());
    ECHO(field0() = -3*x + 5*Imaginary<double>(1)*x);
    ETV(field0);
    ETV(real(field0));
    ETV(imag(field0));
    ETV(pd(field0, 0));
    ETV(IsMultiArray<decltype(field0)>);
    ETV(IsMultiArray<decltype(field0())>);
    ETV(IsComplex<typename NumberTrait<decltype(field0)>::Type>::value);
    ETV(dz(field0));
    ECHO(field0() = -3*x + 5*Imaginary<double>(1)*y);
    ETV(dz_star(field0));
  }


  {
    OUTPUT("CurvilinearField - Complex 1D with time");
    ComplexRectangle<double> rect(
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 3)
    );

    ComplexCoords<double, true> coords(rect, Interval<double>::interval(0, 1, 2));
    ETV(coords.z());
    ETV(coords.t());

    // ETV(coords);
    // ETV(coords.grid_dims());
    // ETV(coords[0]);
    // ETV(coords[1]);

    ECHO(ComplexMathFunction<std::complex<double>, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& z = coords.z());
    ECHO(auto& t = coords.t());
    ECHO(field0() = exp(2*z) + 5*t);
    ETV(field0);
    ETV(pd(field0, 2));

    // ETV(x);

    // ETV(IsGridlike<decltype(x)>);
    // ETV(IsMultiArray<decltype(x)>);
    // ETV(IsWritableExpressionOrArray<decltype(x)>);
    // ETV(x.isNotExpression);
  }

  GMD_VSPACE();
  return 0;
}
