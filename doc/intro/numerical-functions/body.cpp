#include "mathq.h"

int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();


  OUTPUT("Mathématiques provides classes and extensive functionality for single- and multi-variate numerical functions, ie formal mathematical functions over a discretized domain.");

  GMD_VSPACE();
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



  GMD_VSPACE();
  GMD_VSPACE();
  GMD_HEADER2("Specifying the function domain");

  OUTPUT("As mentioned above, the default syntax uses the interval $[0,1]$ for the domain. ");
  OUTPUT("Other domains can be explicitly given as shown below.");


  CR();
  GMD_HEADER3("Linear equispaced interval");
  {
    GMD_CODE_START("C++");
    ECHO(NumericalFunction<double> f({ Interval<double>::interval(-2, 2, 5) }));

    CR();
    ECHO(auto x = f.coordinates[0]);
    EV(x);
    CR();
    ECHO(f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24);
    EV(f);
    CR();
    GMD_CODE_END();
    CR();
  }
  CR();

  CR();
  GMD_HEADER3("Log-spaced interval");
  {
    GMD_CODE_START("C++");
    ECHO(NumericalFunction<double> f({ PointSequence<double>::log10(1, 10, 11) }));

    CR();
    ECHO(auto x = f.coordinates[0]);
    EV(x);
    CR();
    ECHO(f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24);
    EV(f);
    CR();
    GMD_CODE_END();
    CR();
  }
  CR();

  CR();
  GMD_HEADER3("Arbitrary sequence of points");
  {
    GMD_CODE_START("C++");
    ECHO(NumericalFunction<double> f({ PointSequence<double>({1,10}) }));

    CR();
    ECHO(auto x = f.coordinates[0]);
    EV(x);
    CR();
    ECHO(f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24);
    EV(f);
    CR();
    GMD_CODE_END();
    CR();
  }
  CR();



  GMD_VSPACE();
  GMD_VSPACE();
  GMD_HEADER2("Multivariate functions");

  OUTPUT("Using the syntax `NumericalFunction<NumberType, N>` can create a function of `N` variables., e.g. \n$$H(x,p) = \\frac{p^2}{2 m} + \\frac{1}{2} k x^2 $$ ");


  {
    GMD_CODE_START("C++");
    NumericalFunction<double, 2> H({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-10,10,5)
      });
    // Written explciitly in text below so that it is formatted nicely.
    OUTPUT(
      R"TEXT(NumericalFunction<double, 2> H({
  Interval<double>::interval(-1, 1, 5),
  Interval<double>::interval(-10, 10, 5)
}))TEXT");
    CR();
    ECHO(auto x = H.coordinates[0]);
    ECHO(auto p = H.coordinates[1]);
    ECHO(double m = 2);
    ECHO(double k = 25);
    CR();
    EV(x);
    EV(p);
    CR();

    // ECHO(H = x);
    // ETV(H);
    // CR();
    // ECHO(H = 0.5*k*pow(x, 2));
    // ETV(H);
    // CR();
    // ECHO(H = 1/(2*m)*pow(p, 2));
    // ETV(H);
    // CR();
    ECHO(H = 1/(2*m) * pow(p, 2) + 0.5*k * pow(x, 2));
    EV(H);
    ETV(H()(1, 2));
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_VSPACE();
  GMD_HEADER2("Time-varying functions");

  OUTPUT("The syntax `NumericalFunction<NumberType, N, true>` can be used to include time as an independent variable.");
  OUTPUT("As an example, consider \n$$H(x,p,t) = \\frac{p^2}{2 m} + (1 + \\frac{1}{2} \\cos t)^2 x^2 $$ ");


  {
    GMD_CODE_START("C++");
    NumericalFunction<double, 2, true> H({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-10,10,5),
        Interval<double>::interval(0,10,5)
      });
    // Written explciitly in text below so that it is formatted nicely.
    OUTPUT(
      R"TEXT(NumericalFunction<double, 2, true> H({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-10,10,5),
        Interval<double>::interval(0,10,5)
      }); )TEXT");
    CR();
    ECHO(auto x = H.coordinates[0]);
    ECHO(auto p = H.coordinates[1]);
    ECHO(auto t = H.coordinates[2]);
    ECHO(double m = 2);
    CR();
    // EV(x);
    // EV(p);
    // CR();

    // ECHO(H = x);
    // ETV(H);
    // CR();
    // ECHO(H = 0.5*k*pow(x, 2));
    // ETV(H);
    // CR();
    // ECHO(H = 1/(2*m)*pow(p, 2));
    // ETV(H);
    // CR();
    ECHO(H = 1/(2*m) * pow(p, 2) +  pow(1 + 0.5*cos(t)*x, 2));
    EV(H);
    ETV(H()(1, 2, 0));
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_VSPACE();
  GMD_HEADER2("Specifying the function target set");

  OUTPUT("In all of the previous examples we used real-valued functions. That is, the function values come from the set of real numbers, $\\mathbb{R}$. ");
  OUTPUT("The set that a function's values come from is called the *target set* or *codomain*.");

  OUTPUT("The modern definition of a [function](https://en.wikipedia.org/wiki/Function_(mathematics)) is a mapping from a [domain set](https://en.wikipedia.org/wiki/Domain_of_a_function) to a [target/codomain set](https://en.wikipedia.org/wiki/Codomain).");
  OUTPUT("This definition is written symbolically as");
  CR();
  OUTPUT("$$ f\\colon \\text{Domain}\\rightarrow\\text{Target} $$");
  CR();
  OUTPUT("The syntax\n");
  GMD_CODE_START("C++");
  OUTPUT("NumericalFunction<Domain, N, is_time_varying, Target> f;");
  GMD_CODE_END();
  OUTPUT("can be used to represent a function with a different target number type.");
  OUTPUT("For example, we can define complex-valued functions and quaternion-valued functions, as shown below");
  CR();

  CR();
  GMD_HEADER3("Complex-valued functions");
  OUTPUT("As an example consider the complex-valued function:");
  CR();
  OUTPUT("$$ f\\colon [0,1]\\rightarrow\\mathbb{C}$$");
  OUTPUT("$$f(x) = e^{i \\pi x} $$");
  CR();

  {
    GMD_CODE_START("C++");
    ECHO(using namespace mathq::unit_imaginary);
    ECHO(using namespace std::numbers);
    ECHO(NumericalFunction<double, 1, false, std::complex<double>> f);

    CR();
    ECHO(auto x = f.coordinates[0]);
    CR();
    ECHO(f = roundzero(exp(i*pi*x)));
    EV(f);
    CR();
    GMD_CODE_END();
  }
  CR();

  CR();
  GMD_HEADER3("Quaternion-valued functions");
  OUTPUT("As an example consider the quaternion-valued function over 2D:");
  CR();
  OUTPUT("$$ f\\colon [0,1] \\times [0,1]\\rightarrow\\mathbb{H}$$");
  OUTPUT("$$ f(x,y) = e^{i \\frac{\\pi}{2} + j \\pi x + k \\pi y} $$");
  CR();

  {
    GMD_CODE_START("C++");
    ECHO(using namespace mathq::unit_imaginary);
    ECHO(using namespace mathq::unit_quaternion);
    ECHO(using namespace std::numbers);
    ECHO(NumericalFunction<double, 2, false, Quaternion<double>> f);

    CR();
    ECHO(auto x = f.coordinates[0]);
    ECHO(auto y = f.coordinates[1]);
    CR();
    ECHO(f = roundzero(exp(i*pi/2 + j*pi*x + k*pi*y)));
    EV(f);
    CR();
    GMD_CODE_END();
  }
  CR();




  GMD_VSPACE();
  GMD_VSPACE();
  GMD_HEADER2("Other functionality");
  CR();
  OUTPUT("🚧 Further functionality is in development.");
  OUTPUT("* function boundary conditions: constant, periodic, etc");
  OUTPUT("* function causality (needed for differentiation): non-causal (centered derivative stencil), causal (backward derivative stencil), anti-causal (forward derivative stencil)");
  OUTPUT("* Time-varying function object that is a time-series, $f_t(x) = f(x;t)$");
  OUTPUT("* integration");
  OUTPUT("* non-uniform 2D and 3D grids and multi-grid");
  OUTPUT("* 2D and 3D meshes for [Finite Element Method](https://en.wikipedia.org/wiki/Finite_element_method) (triangulation)");
  OUTPUT("* Support for units via [user-defined literals](https://en.cppreference.com/w/cpp/language/user_literal)");

  CR();

  GMD_VSPACE();
  return 0;
}
