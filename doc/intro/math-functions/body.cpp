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

  OUTPUT("C++ supports a wide variety of mathematical functions including trig functions, exponentials and logarithms, as well as Bessel functions, Legendre polynomials, the Gamma function and many more.");
  CR();
  OUTPUT("Mathématiques supplements C++ functionality with several more functions.");

  CR();
  OUTPUT("Mathématiques extends these functions to vectors, matrices, and multiarrays in a element-wise fashion.");
  OUTPUT("Mathématiques also extends many of these functions to complex numbers, imaginary numbers, and quaterions.");


  CR();
  OUTPUT("The following are basic mathematical functions for manipulating numbers.");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `abs(x)` | `std` | `<cmath>` | [absolute value](https://en.cppreference.com/w/cpp/numeric/math/abs) | ");
  OUTPUT("| `abs(u)` | `mathq` | `\"mathq.h\"` | **mathq** abs  | ");
  OUTPUT("| `ceil(x)` | `std` | `<cmath>` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/math/ceil) | ");
  OUTPUT("| `ceil(u)` | `mathq` | `\"mathq.h\"` | **mathq** ceiling | ");
  OUTPUT("| `floor(x)` | `std` | `<cmath>` | [floor function](https://en.cppreference.com/w/cpp/numeric/math/floor) | ");
  OUTPUT("| `floor(u)` | `mathq` | `\"mathq.h\"` | **mathq** floor | ");
  OUTPUT("| `one(u)` | `mathq` | `\"mathq.h\"` | return a one with the same type as x | ");
  OUTPUT("| `trunc(x)` | `std` | `<cmath>` | [truncate function](https://en.cppreference.com/w/cpp/numeric/math/trunc) | ");
  OUTPUT("| `trunc(u)` | `mathq` | `\"mathq.h\"` | **mathq** truncate | ");
  OUTPUT("| `round(x)` | `std` | `<cmath>` | [round function](https://en.cppreference.com/w/cpp/numeric/math/round) | ");
  OUTPUT("| `round(u)` | `mathq` | `\"mathq.h\"` | **mathq** round function | ");
  OUTPUT("| `roundzero(u, tolerance = Functions<X>::tolerance)` | `mathq` | `\"mathq.h\"` | round numbers with magnitude less than `tolerance` to 0. The default values are shown below. | ");
  OUTPUT("| `sgn(u)` | `mathq` | `\"mathq.h\"` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | ");
  OUTPUT("| `zero(u)` | `mathq` | `\"mathq.h\"` | return a zero with the same type as x | ");
  CR();
  CR();

  OUTPUT("Notes:");
  OUTPUT("The default `zero_tolerance` values are global variables and can be changed by the user code.");
  OUTPUT("The default values were chosen so that the typical numerical error encountered with trig functions will produce exactly zero when appropriate.");
  CR();
  GMD_CODE_START("C++");
  DISP(Functions<float>::tolerance);
  DISP(Functions<double>::tolerance);
  DISP(Functions<long double>::tolerance);
  GMD_CODE_END();
  CR();

  CR();
  GMD_VSPACE();

  CR();
  OUTPUT("The following functions / operators are provided for using real number types with imaginary and complex types.");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `real(x)` | `mathq` | `\"mathq.h\"` | returns x | ");
  OUTPUT("| `imag(x)` | `mathq` | `\"mathq.h\"` | returns `zero(x)` | ");
  OUTPUT("| `conj(x)` | `mathq` | `\"mathq.h\"` | returns x | ");
  OUTPUT("| `~x` | `mathq` | `\"mathq.h\"` | returns x | ");
  CR();
  CR();

  OUTPUT("*Trig Functions*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `sin(x)` | [sine](https://en.cppreference.com/w/cpp/numeric/math/sin) | ");
  OUTPUT("| `cos(x)` | [cosine](https://en.cppreference.com/w/cpp/numeric/math/cos) | ");
  OUTPUT("| `tan(x)` | [tangent](https://en.cppreference.com/w/cpp/numeric/math/tan) | ");
  CR();
  CR();

  OUTPUT("*Inverse Trig Functions*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `asin(x)` | [arc sine](https://en.cppreference.com/w/cpp/numeric/math/asin) | ");
  OUTPUT("| `acos(x)` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acos) | ");
  OUTPUT("| `atan(x)` | [arc tangent: all results are mapped into -𝜋/2 <= 𝜃 <= +𝜋/2](https://en.cppreference.com/w/cpp/numeric/math/atan) | ");
  OUTPUT("| `atan2(b, a)` | [arc tangent of b/a with full quadrant angles, 0 <= 𝜃 < +2𝜋](https://en.cppreference.com/w/cpp/numeric/math/atan2) | ");
  CR();
  CR();

  OUTPUT("*Hyperbolic Trig Functions*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `sinh(x)` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/math/sinh) | ");
  OUTPUT("| `cosh(x)` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/math/cosh) | ");
  OUTPUT("| `tanh(x)` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/math/tanh) | ");
  CR();
  CR();

  OUTPUT("*Inverse Hyperbolic Trig Functions*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `asinh(x)` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/math/asinh) | ");
  OUTPUT("| `acosh(x)` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acosh) | ");
  OUTPUT("| `atanh(x)` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/math/atanh) | ");

  CR();
  CR();

  OUTPUT("*Exponentiation*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/math/pow) | ");
  OUTPUT("| `sqrt(x)` | [Square Root](https://en.cppreference.com/w/cpp/numeric/math/sqrt) | ");
  OUTPUT("| `cqrt(x)` | [Cube Root](https://en.cppreference.com/w/cpp/numeric/math/cqrt) | ");

  CR();
  CR();

  OUTPUT("*Exponentials*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `exp(x)` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp) | ");
  OUTPUT("| `exp2(x)` | [2<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp2) | ");
  OUTPUT("| `expm1(x)` | [e<sup>x</sup> - 1](https://en.cppreference.com/w/cpp/numeric/math/expm1) | ");
  CR();
  CR();

  OUTPUT("*Logarithms*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `log(x)` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log) | ");
  OUTPUT("| `log10(x)` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log10) | ");
  OUTPUT("| `log2(x)` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log2) | ");
  OUTPUT("| `log1p(x)` | [ln(x + 1)](https://en.cppreference.com/w/cpp/numeric/math/log1p) | ");
  OUTPUT("| `logb(x)` | [extracts exponent of the number and returns a floating point type](https://en.cppreference.com/w/cpp/numeric/math/logb) | ");
  OUTPUT("| `ilogb(x)` | [extracts exponent of the number and returns an integral type](https://en.cppreference.com/w/cpp/numeric/math/ilogb) | ");

  CR();
  CR();

  OUTPUT("*Other Functions*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `erf(x)` | [error function, erf(x)](https://en.cppreference.com/w/cpp/numeric/math/erf) | ");
  OUTPUT("| `erfc(x)` | [complimentary error function, erfc(x)](https://en.cppreference.com/w/cpp/numeric/math/erfc) | ");
  OUTPUT("| `tgamma(x)` | [Gamma Function, Γ(x)](https://en.cppreference.com/w/cpp/numeric/math/tgamma) | ");
  OUTPUT("| `lgamma(x)` | [Natural Logarithm of the Gamma Function, ln(Γ(x))](https://en.cppreference.com/w/cpp/numeric/math/lgamma) | ");
  CR();
  CR();


  OUTPUT("\n<br>\n");
  GMD_HEADER3("Mathematical functions from the C++ [``std::complex`` header](https://en.cppreference.com/w/cpp/numeric/complex)");


  CR();
  OUTPUT("COMPLEX FUNCTIONS");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `abs` | [absolute value](https://en.cppreference.com/w/cpp/numeric/complex/abs) | ");
  OUTPUT("| `ceil` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/complex/ceil) | ");
  OUTPUT("| `floor` | [floor function](https://en.cppreference.com/w/cpp/numeric/complex/floor) | ");
  OUTPUT("| `trunc` | [truncate function](https://en.cppreference.com/w/cpp/numeric/complex/trunc) | ");
  OUTPUT("| `round` | [round function](https://en.cppreference.com/w/cpp/numeric/complex/round) | ");
  CR();
  CR();

  OUTPUT("*Trig Functions*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `sin` | [sine](https://en.cppreference.com/w/cpp/numeric/complex/sin) | ");
  OUTPUT("| `cos` | [cosine](https://en.cppreference.com/w/cpp/numeric/complex/cos) | ");
  OUTPUT("| `tan` | [tangent](https://en.cppreference.com/w/cpp/numeric/complex/tan) | ");
  CR();
  CR();

  OUTPUT("*Inverse Trig Functions*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `asin` | [arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asin) | ");
  OUTPUT("| `acos` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acos) | ");
  OUTPUT("| `atan` | [arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atan) | ");
  CR();
  CR();

  OUTPUT("*Hyperbolic Trig Functions*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `sinh` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/complex/sinh) | ");
  OUTPUT("| `cosh` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/complex/cosh) | ");
  OUTPUT("| `tanh` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/complex/tanh) | ");
  CR();
  CR();

  OUTPUT("*Inverse Hyperbolic Trig Functions*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `asinh` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asinh) | ");
  OUTPUT("| `acosh` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acosh) | ");
  OUTPUT("| `atanh` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atanh) | ");

  CR();
  CR();

  OUTPUT("*Exponentiation*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/complex/pow) | ");
  OUTPUT("| `sqrt` | [Square Root](https://en.cppreference.com/w/cpp/numeric/complex/sqrt) | ");

  CR();
  CR();

  OUTPUT("*Exponentials*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `exp` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/complex/exp) | ");
  CR();
  CR();

  OUTPUT("*Logarithms*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `log` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log) | ");
  OUTPUT("| `log10` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log10) | ");
  OUTPUT("| `log2` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log2) | ");

  CR();
  CR();


  GMD_HEADER4("C++ ``std`` library special functions");

  OUTPUT("The following [special mathematical functions](https://en.cppreference.com/w/cpp/numeric/special_functions) implemented in the C++ `std` library");
  CR();

  OUTPUT("*Bessel Functions*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `cyl_bessel_j(𝜈, x)` | _J_<sub>𝜈</sub>(_x_) | [Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_j) | ");
  OUTPUT("| `cyl_neumann(𝜈, x)` | _Y_<sub>𝜈</sub>(_x_) | [Bessel (aka Neumann or Weber) function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_neumann) | ");
  OUTPUT("| `cyl_bessel_i(𝜈, x)` | _I_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_i) | ");
  OUTPUT("| `cyl_bessel_k(𝜈, x)` | _K_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_k) | ");

  CR();
  CR();
  OUTPUT("*Spherical Bessel Functions*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `sph_bessel(n, x)` | _j_<sub>n</sub>(_x_) | [Spherical Bessel function of the 1st kind of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_bessel) | ");
  OUTPUT("| `sph_neumann(n, x)` | _y_<sub>n</sub>(_x_) | [Spherical Bessel (aka Neumann or Weber) function of the 2nd kind of degree n, aka Spherical Neumann function](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_neumann) | ");
  CR();
  CR();

  OUTPUT("*Orthogonal Polynomials*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `hermite(n, x)` | _H_<sub>n</sub>(_x_) | [Hermite polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/hermite) | ");
  OUTPUT("| `laguerre(n, x)` | _L_<sub>n</sub>(_x_) | [Laguerre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/laguerre) | ");
  OUTPUT("| `legendre(n, x)` | _P_<sub>n</sub>(_x_) | [Legendre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/legendre) | ");
  OUTPUT("| `assoc_laguerre(n, m, x)` | _L_<sub>n,m</sub>(_x_) | [Associated Laguerre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_laguerre) | ");
  OUTPUT("| `assoc_legendre(n, m, x)` | _P_<sub>n,m</sub>(_x_) | [Associated Legendre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_legendre) | ");
  CR();
  CR();

  OUTPUT("*Other Special Functions*");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `beta(x, y)` |  B(_x_,_y_) | [Euler beta function (Euler Integral of the 1st kind)](https://en.cppreference.com/w/cpp/numeric/special_functions/beta) | ");
  OUTPUT("| `comp_ellint_1(k)` |  _K_(_k_) |  [Complete elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_1) | ");
  OUTPUT("| `comp_ellint_2(k)` |  _E_(_k_) |  [Complete elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_2) | ");
  OUTPUT("| `comp_ellint_3(n, k)` |  _Π_(_n_,_k_) |  [Complete elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_3) | ");
  OUTPUT("| `ellint_1(k, φ)` |  _F_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_1) | ");
  OUTPUT("| `ellint_2(k, φ)` |  _E_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_2) | ");
  OUTPUT("| `ellint_3(k, n, φ)` |  _Π_(_n_; _φ_, _k_) |  [(Incomplete) elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_3) | ");
  OUTPUT("| `expint(x)` |  Ei(_x_) |  [Exponential Integral](https://en.cppreference.com/w/cpp/numeric/special_functions/expint) | ");
  OUTPUT("| `riemann_zeta(x)` |  ζ(_x_) | [Riemann Zeta Function](https://en.cppreference.com/w/cpp/numeric/special_functions/riemann_zeta) | ");
  OUTPUT("| `sph_legendre(l, m, θ)` | _Y_<sub>_l_</sub><sup>_m_</sup></sub>(_θ_, _φ_=0) | [Spherical Associated Legendre function<sup>†</sup> of degree _l_, order _m_](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_legendre) | ");
  CR();
  CR();
  OUTPUT("† This is equal to a [Spherical Harmonic](https://en.wikipedia.org/wiki/Spherical_harmonics) with _φ_=0, as the notation implies.");

  GMD_HEADER3("Mathematical functions from the Mathématiques library, namespace `mathq`");

  OUTPUT("The following are mathematical functions implemented in the Mathématiques library, namespace `mathq`");
  CR();
  OUTPUT("| <div style='width:225px'>function</div> | namespace | header | name | ");
  OUTPUT("| :---: | :---: | :---: | :---: | ");
  OUTPUT("| `sqr(x)` | x<sup>2</sup> | ");
  OUTPUT("| `cube(x)` | x<sup>3</sup> | ");
  CR();

  GMD_VSPACE();
  GMD_HEADER2("Exponentiation and the `pow` function");
  OUTPUT("C++ does not have an exponentiation operator.  Instead it provides the [`std::pow`](https://en.cppreference.com/w/cpp/numeric/math/div) function");
  GMD_CODE_START("C++");
  ETV(pow(2, 8));
  ETV(pow(25, 1 / 2));
  GMD_CODE_END();


  GMD_VSPACE();
  GMD_HEADER2("Exponentiation and the `pow` function");
  OUTPUT("C++ does not have an exponentiation operator.  Instead it provides the [`std::pow`](https://en.cppreference.com/w/cpp/numeric/math/div) function");
  GMD_CODE_START("C++");
  ETV(pow(2, 8));
  ETV(pow(25, 1 / 2));
  GMD_CODE_END();



  return 0;
}
