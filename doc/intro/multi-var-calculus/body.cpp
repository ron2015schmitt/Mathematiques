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

  OUTPUT("Mathématiques provides classes and extensive functionality for single- and multi-variate numerical functions.");


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
    CR();
    ECHO(f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24);
    ETV(f);
    CR();
    GMD_CODE_END();


    OUTPUT("We can easily create a second function, e.g. $g(x) = x + 2 f(x) - 4 \\frac{df}{dx}$ ");

    GMD_CODE_START("C++");
    ECHO(NumericalFunction<double> g);
    CR();
    ECHO(g = x + 2*f - 4*d(f));
    // ECHO(g = d(f));
    // ECHO(g = sqrt(f));
    // ECHO(g = sqrt(d(f)));
    // ECHO(g = d(sqrt(f)));
    ETV(g);
    CR();
    GMD_CODE_END();
  }



  GMD_VSPACE();
  GMD_HEADER2("Specifying the function domain");

  OUTPUT("The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. ");
  OUTPUT("With this defintion, we can create a function, e.g. $f(x) = 1 + x + \\frac{x^2}{2} + \\frac{x^3}{6} + \\frac{x^4}{24}$ ");


  GMD_VSPACE();
  GMD_HEADER2("Specifying the function target set");

  OUTPUT("The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. ");
  OUTPUT("With this defintion, we can create a function, e.g. $f(x) = 1 + x + \\frac{x^2}{2} + \\frac{x^3}{6} + \\frac{x^4}{24}$ ");


  GMD_VSPACE();
  GMD_HEADER2("Specifying the function boundary conditions");

  OUTPUT("The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. ");
  OUTPUT("With this defintion, we can create a function, e.g. $f(x) = 1 + x + \\frac{x^2}{2} + \\frac{x^3}{6} + \\frac{x^4}{24}$ ");



  GMD_VSPACE();
  GMD_HEADER2("Multivariate functions");

  OUTPUT("The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. ");
  OUTPUT("With this defintion, we can create a function, e.g. $f(x) = 1 + x + \\frac{x^2}{2} + \\frac{x^3}{6} + \\frac{x^4}{24}$ ");


  {
    GMD_CODE_START("C++");
    NumericalFunction<double, 2> H({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-10,10,5)
      });

    OUTPUT(
      R"TEXT(NumericalFunction<double, 2> H({
  Interval<double>::interval(-1, 1, 5),
  Interval<double>::interval(-10, 10, 5)
}))TEXT");
    CR();
    ETV(H);
    ECHO(auto x = H.coordinates[0]);
    ECHO(auto p = H.coordinates[1]);
    ECHO(double m = 2);
    ECHO(double k = 25);
    CR();
    ETV(x);
    ETV(p);
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
    ETV(H);
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER2("Time-varying functions");

  OUTPUT("The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. ");
  OUTPUT("With this defintion, we can create a function, e.g. $f(x) = 1 + x + \\frac{x^2}{2} + \\frac{x^3}{6} + \\frac{x^4}{24}$ ");




  GMD_VSPACE();
  GMD_HEADER2("Other functionality");

  OUTPUT("Integrals");
  OUTPUT("Support for units via [user-defined literals](https://en.cppreference.com/w/cpp/language/user_literal)");


  // OUTPUT("Calculus");

  // GMD_HEADER2("Integration");
  // GMD_HEADER3("Definite integrals");

  // OUTPUT("Integrating over an interval (a,b) yields a single number--the area under the curve.");
  // CR();
  // OUTPUT("![Definite Integral](DefiniteIntegral.png)");


  // {
  //   CR();
  //   CR();
  //   OUTPUT("Definite integrals");
  //   GMD_CODE_START("C++");
  //   ECHO(const size_t N = 100000);
  //   ECHO(const double a = 0);
  //   ECHO(const double b = 1);
  //   ECHO(Vector<double> x(linspace_ab<double>(a, b, N)));
  //   ECHO(Vector<double> f);
  //   ECHO(f = -log(log(1/x)));
  //   GMD_CODE_END();
  //   CR();


  //   OUTPUT("Integrating f(x), as given above, yields the [Euler–Mascheroni](http://mathworld.wolfram.com/Euler-MascheroniConstant.html) constant whose exact value is `0.577215664901532...`.  The function _f_(_x_) is singular at both x=0 and x=1.  Thus we omitted these points. As the results show, many points are needed to achieve even a few digits of accuracy, due to the singularities. ");
  //   CR();
  //   OUTPUT(" ![Euler–Mascheron Integral](EulerMascheroniConstant.png)");
  //   CR();
  //   resultstart3("");
  //   resultmulti(N);
  //   resultmulti(a);
  //   resultmulti(b);
  //   resultmulti(integrate_a2b(f, a, b, 0));
  //   resultmulti(integrate_a2b(f, a, b, 1));
  //   resultmulti(integrate_a2b(f, a, b, 2));
  //   resultend();
  // }


  // GMD_HEADER3("Semi-Definite Integrals");
  // OUTPUT("A semi-definite integral is created by replacing one of the end points with _x_.");
  // CR();
  // OUTPUT("* For the integral\n");
  // OUTPUT("![Semi-Definite Integral a2x](SemiDefinite_a2x.png)\n");
  // OUTPUT("use the method `f.integrate_a2x(a, b)` or the function `integrate_a2x(f, a, b)`.");
  // CR();
  // CR();
  // OUTPUT("* For the integral\n");
  // OUTPUT("![Semi-Definite Integral x2b](SemiDefinite_x2b.png)\n");
  // OUTPUT("use the method `f.integrate_x2b(a, b)` or the function `integrate_x2b(f, a, b)`.");
  // CR();
  // CR();
  // OUTPUT("Where [`a`,`b`] defines the interval being used\n");

  // CR();
  // CR();
  // OUTPUT("A semi-definite integral yields a function as its output.");

  // OUTPUT("Integration requires a cumulative sum.  Thus the caculation can not be accomplished via element-wise operations.  For this reasons these functions can be performed: ");
  // OUTPUT("  * on a Vector in place using `f.integrate_a2x(a, b)`, mimizing both memory usage and computation time.");
  // OUTPUT("  * on a Vector or expression using the function `integrate_a2x(f, a, b)`,  in which case a `new Vector` is created inside the function and returned. ");

  // OUTPUT("All of the remaining functions discussed in this page can be called in either manner.");


  // {
  //   CR();
  //   CR();
  //   OUTPUT(" The error function integral");
  //   OUTPUT("The [error function](http://mathworld.wolfram.com/Erf.html) is the following semi-definite integral of a Gaussian function (with zero mean and variance of 1/2).");
  //   CR();
  //   OUTPUT("![ErrorFunction](ErrorFunction.png)");
  //   GMD_CODE_START("C++");
  //   ECHO(const size_t N = 101);
  //   ECHO(const double a = 0);
  //   ECHO(const double b = 4);
  //   ECHO(const double pi = M_PI);
  //   ECHO(Vector<double> x(linspace<double>(a, b, N)));
  //   ECHO(Vector<double> gauss);
  //   ECHO(gauss = 2/sqrt(pi)*exp(-sqr(x)));
  //   ECHO(Vector<double> erf = gauss);
  //   ECHO(erf.integrate_a2x(a, b));
  //   ECHO(set_mathematica_var_format());
  //   GMD_CODE_END();
  //   CR();

  //   OUTPUT("The results _x_ and _erf_(_x_) are:");
  //   CR();
  //   GMD_CODE_START("Mathematica");
  //   DISP(x);
  //   DISP(erf);
  //   GMD_CODE_END();

  //   OUTPUT("Cut and paste the above data for `x` and `erf` into Mathematica as well as the following commands");
  //   CR();
  //   GMD_CODE_START("Mathematica");
  //   OUTPUT("p1=ListPlot[Partition[Riffle[x,erf],2],PlotStyle->Red];");
  //   OUTPUT("p2=Plot[Erf[0,x],{x,0,4}];");
  //   OUTPUT("Show[p1,p2]");
  //   GMD_CODE_END();

  //   OUTPUT("This yields the following plot comparing the results above [red dots] to the exact function [solid blue].");

  //   OUTPUT("![ErrorFunctionPlot](ErrorFunctionPlot.png)");


  // }


  // GMD_HEADER3("Semi-Definite Integrals: optional parameters");


  // OUTPUT("The optional `order` parameter specifies the integration method order: \n");
  // OUTPUT("* 0 for rectangular integration\n");
  // OUTPUT("* 1 for trapezoidal integration (DEFAULT).\n");

  // OUTPUT("Usage: \n");
  // OUTPUT("* `f.integrate_x2b(a, b, order)`");
  // OUTPUT("* `integrate_x2b(f, a, b, order)`");

  // GMD_HEADER2("Differentiation");
  // OUTPUT("* Differentiation requires points around it.   The derivative can be performed :");
  // OUTPUT("  * on a Vector in place using `f.deriv(a, b)`, mimizing both memory usage and computation time.");
  // OUTPUT("  * on a Vector or expression using the function `deriv(f, a, b)`,  in which case a `new Vector` is created inside the function and returned. ");


  // {
  //   CR();
  //   CR();
  //   OUTPUT("Derivative of the function _f_(_x_) = 5 _x_");
  //   CR();
  //   CR();
  //   OUTPUT("The derivative of the function _f_(_x_) = is the constant 5");
  //   GMD_CODE_START("C++");
  //   ECHO(set_default_format());
  //   ECHO(const double pi = M_PI);
  //   ECHO(const size_t N = 11);
  //   ECHO(const double a = 0);
  //   ECHO(const double b = 1);
  //   ECHO(Vector<double> x(linspace<double>(a, b, N)));
  //   GMD_CODE_END();
  //   CR();

  //   resultstart3("");
  //   resultmulti(x);
  //   resultmulti(deriv(5*x, a, b));

  //   // resultmulti(deriv(5*x,a,b,1,2));
  //   // resultmulti(deriv(5*x,a,b,1,3));
  //   // resultmulti(deriv(5*x,a,b,1,5));
  //   // resultmulti(deriv(5*x,a,b,1,7));

  //   // resultmulti(deriv(x*x,a,b,1,2));
  //   // resultmulti(deriv(x*x,a,b,1,3));
  //   // resultmulti(deriv(x*x,a,b,1,5));
  //   // resultmulti(deriv(x*x,a,b,1,7));

  //   resultend();
  // }


  // GMD_HEADER3("Differentiation: optional parameters");
  // OUTPUT("* The differentiation method/function has 3 optional parameters:");
  // OUTPUT("  * `f.deriv(a, b, n, Dpts, periodic)` or `deriv(f, a, b, n, Dpts, periodic)`");
  // OUTPUT("* The optional parameters are:");
  // OUTPUT("  * `n` [DEFAULT=`1`] is the number of derivatives to compute: ");
  // OUTPUT("  * `Dpts` [DEFAULT=`7`] is the number of points to use in the calculation: 2,3,5, or 7.  More points yield better accuracy. ");
  // OUTPUT("  * `periodic` [DEFAULT=`false`]. When set to `true` the derivative at the end points will be of higher accuracy for periodic function.");

  // GMD_HEADER3("Differentiation: taking multiple derivatives in one call");

  // {
  //   CR();
  //   CR();
  //   OUTPUT("The fourth derivative of sin _x_");
  //   CR();
  //   CR();
  //   OUTPUT("Here we take the 4th derivative of sin _x_ using `Dpts`=2,3,5, and 7 points. The result for all should be sin _x_:");
  //   CR();
  //   CR();
  //   OUTPUT("![4th derivative of sin(x)](fourthDerivativeOfSin.png)");
  //   CR();
  //   CR();
  //   OUTPUT("We also set `periodic=true` since sin _x_ is periodic over [0,2pi)");
  //   GMD_CODE_START("C++");
  //   ECHO(set_mathematica_var_format());
  //   ECHO(const double pi = M_PI);
  //   ECHO(const size_t N = 25);
  //   ECHO(Vector<double> x(linspace_b<double>(0, 2*pi, N)));
  //   ECHO(const double a = min(x));
  //   ECHO(const double b = max(x));
  //   ECHO(Vector<double> f = sin(x));
  //   ECHO(Vector<double> f2 = deriv(f, a, b, 4, 2, true));
  //   ECHO(Vector<double> f3 = deriv(f, a, b, 4, 3, true));
  //   ECHO(Vector<double> f5 = deriv(f, a, b, 4, 5, true));
  //   ECHO(Vector<double> f7 = deriv(f, a, b, 4, 7, true));
  //   GMD_CODE_END();
  //   CR();

  //   GMD_CODE_START("Mathematica");
  //   DISP(x);
  //   DISP(f2);
  //   DISP(f3);
  //   DISP(f5);
  //   DISP(f7);
  //   GMD_CODE_END();

  //   OUTPUT("Cut and paste the above data for `x`, `f2`, `f3`,...  into Mathematica as well as the following commands");
  //   CR();
  //   GMD_CODE_START("Mathematica");
  //   OUTPUT("p2 = ListPlot[Partition[Riffle[x, f2], 2], PlotStyle -> {Red, PointSize[0.01], Opacity[0.9]},PlotLegends -> {\"Dpts=2\"}];");
  //   OUTPUT("p3 = ListPlot[Partition[Riffle[x, f3], 2], PlotStyle -> {Orange, PointSize[0.01], Opacity[0.75]}, PlotLegends -> {\"Dpts=3\"}];");
  //   OUTPUT("p5 = ListPlot[Partition[Riffle[x, f5], 2], PlotStyle -> {Green, PointSize[0.01], Opacity[0.5]}, PlotLegends -> {\"Dpts=5\"}];");
  //   OUTPUT("p7 = ListPlot[Partition[Riffle[x, f7], 2],PlotStyle -> {Black, PointSize[0.005], Opacity[0.9]}, PlotLegends -> {\"Dpts=7\"}];");
  //   OUTPUT("p = Plot[Sin[x], {x, 0, 2*Pi}, PlotLegends -> {\"sin(x)\"}];");
  //   OUTPUT("Show[p, p2, p3, p5, p7]");
  //   GMD_CODE_END();

  //   OUTPUT("This yields the following plot comparing the results above [dots] to the exact function [solid blue].");

  //   OUTPUT("![The Fourth Derivative of Sin(x)](FourthDerivativeSinPlot.png)");

  //   OUTPUT("From these results we observe:");
  //   OUTPUT("* the 2 point derivative has a bias that shifts the data to the right by 1/2 a grid point for each derivative taken.");
  //   OUTPUT("* the 3 point derivative is approximately correct: rms error = 2.9%");
  //   OUTPUT("* the 5 point derivative is very accurate:         rms error = 0.04%");
  //   OUTPUT("* the 7 point derivative is even more accurate:    rms error = 5ppm");
  //   CR();
  //   CR();
  //   OUTPUT("The root mean square (rms) errors were calculated in Mathematica using the following commands.");

  //   GMD_CODE_START("Mathematica");
  //   OUTPUT("RootMeanSquare[f2 - Sin[x]]*100");
  //   OUTPUT("RootMeanSquare[f3 - Sin[x]]*100");
  //   OUTPUT("RootMeanSquare[f5 - Sin[x]]*100");
  //   OUTPUT("RootMeanSquare[f7 - Sin[x]]*10^6");
  //   GMD_CODE_END();


  // }





  // GMD_HEADER2("Various functions related to integration and differentiation");
  // OUTPUT("All of these functions can be called _either_ as a method, eg `v.cumsum()` or a function `cumsum(v)`.");

  // {
  //   CR();
  //   CR();
  //   OUTPUT("Various functions: `cumsum`, `cumprod`, `cumtrapz`, `diff`, etc");
  //   GMD_CODE_START("C++");
  //   ECHO(set_default_format());
  //   ECHO(Vector<double> v1(5));
  //   GMD_CODE_END();
  //   CR();


  //   resultstart2("");
  //   resultmulti(v1 = { 1,4,9,16,25 });
  //   resultmulti(v1.cumsum());
  //   resultmulti(v1 = { 1,4,9,16,25 });
  //   resultmulti(v1.cumtrapz());
  //   resultmulti(v1 = { 1,2,3,4,5 });
  //   resultmulti(v1.cumprod());
  //   resultmulti(v1 = { 1,4,9,16,25 });
  //   resultmulti(v1.diff());
  //   resultmulti(v1 = { 1,4,9,16,25 });
  //   resultmulti(v1.diff(true));
  //   resultmulti(v1 = { 25,16,9,4,1 });
  //   resultmulti(v1.cumsum_rev());
  //   resultmulti(v1 = { 25,16,9,4,1 });
  //   resultmulti(v1.cumtrapz_rev());
  //   resultmulti(v1 = { 5,4,3,2,1 });
  //   resultmulti(v1.cumprod_rev());
  //   resultmulti(v1 = { 1,4,9,16,25 });
  //   resultmulti(v1.diff_rev());
  //   resultmulti(v1 = { 1,4,9,16,25 });
  //   resultmulti(v1.diff_rev(true));
  //   resultend();
  // }

  // OUTPUT("The suffix `_rev` denote that the function starts at the highest element instead of the lowest element. Passing `true` to diff signifies that the function is periodic over the interval [a,b]. ");

  GMD_VSPACE();
  return 0;
}
