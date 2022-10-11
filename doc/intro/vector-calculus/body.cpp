#include "mathq.h"


std::string load(std::string fname) {
  std::ifstream in(fname.data(), std::ios::in);
  if (!in) {
    std::cerr << "CANNOT OPEN FILE\n";
    return std::string("");
  }

  std::stringstream buffer;
  buffer << in.rdbuf();
  in.close();

  // std::cerr << buffer.str();
  return buffer.str();
}


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();

  OUTPUT("Mathématiques provides classes and extensive functionality for curvilinear coordinate systems as well as scalar, vector, and rank >=2 functions using these coordinates.");

  GMD_VSPACE();
  GMD_HEADER2("Curvilinear Coordinates");

  OUTPUT("Currently Cartesian and polar coordinates are supported.");
  OUTPUT("To save memory, the coordinate grids are stored in a special type of multiarray that only contains a vector, which is then repeated.");
  OUTPUT("In 3D+Time, this reduces the storage from $N^4$ to $N$. For 1000 points this is a reduction from $10^{12}$ data points to $1000$ data points for each coordinate.");

  CR();
  GMD_HEADER3("Cartesian Coordinates");
  {
    GMD_CODE_START("C++");
    CartesianCoords<double, 2> coords({
        Interval<double>::interval(-2,2,5),  // x domain
        Interval<double>::interval(2,3,3)
      });
    OUTPUT(R"TEXT(CartesianCoords<double, 2> coords({
  Interval<double>::interval(-2,2,5),  // x domain
  Interval<double>::interval(2,3,3)    // y domain
}))TEXT");
    ETV(coords.x());
    ETV(coords.y());
    GMD_CODE_END();
  }
  CR();

  CR();
  GMD_HEADER3("Polar Coordinates");
  {
    GMD_CODE_START("C++");
    ECHO(using namespace std::numbers);
    PolarCoords<double> coords({
    Interval<double>::interval(0,1,5),
    Interval<double>::c_interval_o(0,2*pi,4)
      });
    OUTPUT(R"TEXT(PolarCoords<double> coords({
  Interval<double>::interval(0,1,5),  // r domain
  Interval<double>::c_interval_o(0,2*pi,4)    // phi domain
}))TEXT");

    ETV(coords.r());
    ETV(coords.phi());
    GMD_CODE_END();
  }
  CR();

  OUTPUT("NOTE: The above syntax `Interval<double>::c_interval_o` specifies the interval $[0,2\\pi)$, so that the point $\\phi = 2 \\pi$ is not included (since it is the same point in space as $\\phi = 0$).");

  GMD_VSPACE();
  GMD_HEADER2("Vector fields");

  OUTPUT("Now that we have coordinate systems, we can create vector fields using the `CurvilinearField` class. ");

  CR();
  OUTPUT("$$\\vec{v}(x,y) \\hspace1ex = -3x \\hspace0.5ex \\hat{x} + 2y \\hspace0.5ex \\hat{y} $$");
  CR();

  CR();
  {
    GMD_CODE_START("C++");
    ECHO(CartesianCoords<double, 2, false> coords({
    Interval<double>::interval(-2,2,5),
    Interval<double>::interval(2,3,3),
      }));
    CR();
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    CR();
    ECHO(CurvilinearField<double, 1, decltype(coords)> v(coords));
    ECHO(v = expr{ -3*x,  2*y });
    ETV(v);
    GMD_CODE_END();
  }
  CR();


  GMD_VSPACE();
  GMD_HEADER2("Fields of any rank");

  OUTPUT("In fact, the `CurvilinearField` class supports fields of any rank: scalar=0, vector=1, matrix=2, etc. ");

  CR();
  {
    CR();
    OUTPUT("Define 2D Cartesian Coordinates");
    CR();
    GMD_CODE_START("C++");
    ECHO(CartesianCoords<double, 2, false> coords({
    Interval<double>::interval(-2,2,5),
    Interval<double>::interval(2,3,3),
      }));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    GMD_CODE_END();
    CR();

    GMD_VSPACE();
    OUTPUT("Scalar field: $$f(x,y) \\hspace1ex = 2 x^2 + y^2 $$");
    CR();
    GMD_CODE_START("C++");
    ECHO(CurvilinearField<double, 0, decltype(coords)> scalar_field(coords));
    ECHO(scalar_field = 2*pow(x, 2) + pow(y, 2));
    ETV(scalar_field);
    GMD_CODE_END();
    CR();

    GMD_VSPACE();
    OUTPUT("Vector field: $$\\vec{v}(x,y) \\hspace1ex = -3x \\hspace0.5ex \\hat{x} + 2y \\hspace0.5ex \\hat{y} $$");
    CR();
    GMD_CODE_START("C++");
    ECHO(CurvilinearField<double, 1, decltype(coords)> vector_field(coords));
    ECHO(vector_field = expr{ -3*x,  2*y });
    ETV(vector_field);
    GMD_CODE_END();
    CR();

    GMD_VSPACE();
    OUTPUT("\"Matrix\" (rank 2 tensor) field: $$\\stackrel{\\leftrightarrow}{T}(x,y) \\hspace1ex = \\vec{v} \\vec{v} $$");
    CR();
    GMD_CODE_START("C++");
    ECHO(CurvilinearField<double, 2, decltype(coords)> tensor_field(coords));
    ECHO(tensor_field = vector_field & vector_field);
    ETV(tensor_field);
    GMD_CODE_END();
  }
  CR();


  OUTPUT("Note: the class `NumericalFunction` from the previous section is actually just a type alias for `CurvilinearField<double, 0>`");


  GMD_VSPACE();
  GMD_HEADER2("Grad, Div, Curl");

  OUTPUT(load("vector-calculus/grad-div-curl.md"));


  GMD_VSPACE();
  GMD_HEADER2("Maxwell's Equations");

  CR();
  OUTPUT("The code below calculates, in 3D, the time-dependent, complex-valued potentials");
  CR();
  OUTPUT("$$\\Phi(\\vec{x},t) \\hspace1ex \\dot{=} \\hspace1ex A_0 \\frac{c^2 k_y}{\\omega} \\hspace0.5ex e^{i(k_y y - \\omega t)}$$");
  CR();
  OUTPUT("$$\\vec{A}(\\vec{x},t) \\hspace1ex \\dot{=} \\hspace1ex A_0 \\hspace0.5ex e^{i(k_z z - \\omega t)} \\hspace0.5ex \\hat{x} \\hspace1ex + \\hspace1ex A_0 \\hspace0.5ex e^{i(k_y y - \\omega t)} \\hspace0.5ex \\hat{y}$$");
  CR();
  OUTPUT("Then from these potentials, it calculates the electric and magnetic fields using");
  CR();
  OUTPUT("$$\\vec{E}(\\vec{x},t) \\hspace1ex = - \\vec{\\nabla}\\Phi - \\frac{\\partial \\vec{A}}{\\partial t} $$");
  CR();
  OUTPUT("$$\\vec{B}(\\vec{x},t) \\hspace1ex = \\vec{\\nabla} \\times  \\vec{A}$$");
  CR();
  {
    GMD_VSPACE();
    OUTPUT("Constant definitions");
    GMD_CODE_START("C++");
    ECHO(using namespace std::numbers);
    ECHO(using namespace mathq::unit_imaginary);
    ECHO(const size_t Npts = 10);
    ECHO(const double A0 = 1);
    ECHO(const double omega = 2);
    ECHO(const double c = 299792458);
    ECHO(const double kx = 0);
    ECHO(const double ky = 2);
    ECHO(const double kz = 1);
    ECHO(const Vector<double, 3> k{ kx, ky, kz });
    ECHO(const double Phi0 = A0 * pow(c, 2) * ky / omega);
    GMD_CODE_END();
    CR();

    GMD_VSPACE();
    OUTPUT("3D+Time Cartesian Coordinates");
    GMD_CODE_START("C++");
    CartesianCoords<double, 3, true> coords({
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(0,1,Npts),
      });
    OUTPUT(R"TEXT(CartesianCoords<double, 3, true> coords({
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(0,1,Npts),
}) )TEXT");
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(auto& z = coords.z());
    ECHO(auto& t = coords.t());
    GMD_CODE_END();
    CR();

    GMD_VSPACE();
    OUTPUT("Type Definitons for convenience");
    GMD_CODE_START("C++");
    ECHO(using MyScalarField = CurvilinearField<std::complex<double>, 0, decltype(coords)>);
    ECHO(using MyVectorField = CurvilinearField<std::complex<double>, 1, decltype(coords)>);
    GMD_CODE_END();
    CR();

    GMD_VSPACE();
    OUTPUT("Potentials");
    GMD_CODE_START("C++");
    ECHO(MyScalarField Phi(coords));
    ECHO(Phi = Phi0 * exp(i*(ky*y - omega*t)));

    CR();
    ECHO(MyVectorField A(coords));
    ECHO(A = expr{ A0 * exp(i*(kz*z - omega*t)), A0 * exp(i*(ky*y - omega*t)), 0 });
    GMD_CODE_END();
    CR();

    GMD_VSPACE();
    OUTPUT("E and B fields");
    GMD_CODE_START("C++");
    ECHO(MyVectorField B(coords));
    ECHO(B = curl(A));
    CR();

    ECHO(MyVectorField E(coords));
    ECHO(E = -grad(Phi) - pd(A, A.time));
    GMD_CODE_END();
    CR();



    GMD_VSPACE();
    OUTPUT("Verify the Lorenz Gauge Condition, $\\frac{1}{c^2} \\frac{\\partial \\Phi}{\\partial t} + \\vec{\\nabla} \\cdot \\vec{A} = 0$, to 0.2\% accuracy at every point!");
    GMD_CODE_START("C++");
    // ECHO(auto result0 = i*k|A);
    ECHO(MyScalarField result1(coords));
    ECHO(result1 = div(A));
    CR();

    ECHO(MyScalarField result2);
    ECHO(result2 = -1./(c*c) * pd(Phi, Phi.time));
    CR();
    ETV(alltrue(approx(result1(), result2(), 0.002)));

    // ETV(approx(result1(0, 0, 0, 2), result2(0, 0, 0, 2), 0.1));

    // MultiArray<complex<double>, 4, 5, 5, 5, 5> delta = result1 - result2;
    // MultiArray<double, 4, 5, 5, 5, 5> err = abs(result1-result2);
    // MultiArray<bool, 4, 5, 5, 5, 5> match = approx(result1, result2, 0.1);
    // ETV(result1(0, 0, 0, 2));
    // ETV(result2()(0, 0, 0, 2));
    // ETV(result3()(0, 0, 0, 2));
    // ETV(delta(0, 0, 0, 2));
    // ETV(err(0, 0, 0, 2));
    // ETV(match(0, 0, 0, 2));
    // ETV(numtrue(approx(result1, result2(), 0.015)));

    // ECHO(Nabla nabla(5));
    // ECHO(B = nabla ^ A);
    // ECHO(B = curl(A, nabla));
    // CR();

    GMD_CODE_END();
    CR();
  }
  CR();


  GMD_VSPACE();
  GMD_HEADER2("Derivative parameters");

  OUTPUT("The default [stencil size](https://en.wikipedia.org/wiki/Stencil_(numerical_analysis)) for the derivative on uniform grids is set to 7 points for high accuracy.  Stencil size of 2, 3, 5, and 7 points are supported for uniform grids.    ");
  CR();
  OUTPUT("For non-uniform grids, a stencil size of 3 points is currently supported.");
  CR();

  OUTPUT("The stencil size is set via the Nabla operator as shown in the example below.");

  CR();
  GMD_CODE_START("C++");
  OUTPUT("Nabla nabla(3);  // 3pt stencil instead of default 7 pt");
  Nabla nabla(3);
  ETV(nabla);
  CR();
  OUTPUT("B = curl(A, nabla);  // 1. curl using function");
  OUTPUT("B = nabla ^ A; // 2. curl using Nabla operator");
  GMD_CODE_END();
  CR();

  GMD_VSPACE();
  GMD_HEADER2("Integration");
  OUTPUT("Numerical integration is in development.");

  GMD_HEADER3("Definite integral example");

  {
    CR();
    GMD_CODE_START("C++");
    ECHO(const size_t N = 100000);
    ECHO(const double a = 0);
    ECHO(const double b = 1);
    ECHO(Vector<double> x(linspace_ab<double>(a, b, N)));
    ECHO(Vector<double> f);
    ECHO(f = -log(log(1/x)));
    ETV(integrate_a2b(f, a, b, 0));
    GMD_CODE_END();
    CR();
  }


  GMD_HEADER3("Semi-Definite Integral example");
  {
    CR();
    GMD_CODE_START("C++");
    ECHO(using namespace std::numbers);
    ECHO(const size_t N = 21);
    ECHO(const double a = 0);
    ECHO(const double b = 4);
    ECHO(Vector<double> x(linspace<double>(a, b, N)));
    ECHO(Vector<double> gaussian);
    ECHO(gaussian = 2/sqrt(pi)*exp(-sqr(x)));
    ECHO(Vector<double> erf);
    ETV(erf = integrate_a2x(gaussian, a, b));
    GMD_CODE_END();
    CR();
  }

  GMD_VSPACE();
  return 0;
}
