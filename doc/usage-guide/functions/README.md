<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.78-c++17</h1>

<details>

<summary>User Manual</summary>

# [User Manual](../../README.md)<br>
1. [About](../../about/README.md)<br>
2. [License](../../license/README.md)<br>
3. [Status, Planned Work & Release Notes](../../status-release/README.md)<br>
4. [Description and Example Usage](../../description-examples/README.md)<br>
5. [Installation](../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../first-project/README.md)<br>
7. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
8. [Benchmarks](../../benchmarks/README.md)<br>
9. [Tests](../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [7. Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br>
7.1. [Usage Guide Notation](../notation/README.md)<br>
7.2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../scalars/README.md)<br>
7.3. [Container Types (Vector, Matrix & Tensor)](../containers/README.md)<br>
7.4. [Operators](../operators/README.md)<br>
7.5. _Functions_ <br>
7.6. [Linear Algebra](../linear-algebra/README.md)<br>
7.7. [Indexing, Masks, and Sorting](../indexing-sorting/README.md)<br>
7.8. [Ranges and Grids](../ranges-grids/README.md)<br>
7.9. [Calculus](../calculus/README.md)<br>
7.10. [Vector Calculus](../vector-calculus/README.md)<br>
7.11. [Tensor Calculus](../tensor-calculus/README.md)<br>
7.12. [Display of Results](../display/README.md)<br>
7.13. [FILE I/O](../file-io/README.md)<br>
7.14. [Debug Modes](../debug/README.md)<br>


</details>



# 7.5. Functions

_This document was generated from the C++ file_ `functions/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 

C++ supports a wide variety of mathematical functions.

Mathématiques supplements C++ functionality with several more functions.

Mathématiques extends many of these functions to complex numbers, imaginary numbers, and quaterions, as well as extending to vectors, matrices, and tensors in a element-wise fashion.

The following are basic mathematical functions for manipulating numbers.

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `abs(x)` | `std` | `<cmath>` | [absolute value](https://en.cppreference.com/w/cpp/numeric/math/abs) | 
| `abs(u)` | `mathq` | `"mathq.h"` | **mathq** abs  | 
| `ceil(x)` | `std` | `<cmath>` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/math/ceil) | 
| `ceil(u)` | `mathq` | `"mathq.h"` | **mathq** ceiling | 
| `floor(x)` | `std` | `<cmath>` | [floor function](https://en.cppreference.com/w/cpp/numeric/math/floor) | 
| `floor(u)` | `mathq` | `"mathq.h"` | **mathq** floor | 
| `one(u)` | `mathq` | `"mathq.h"` | return a one with the same type as x | 
| `trunc(x)` | `std` | `<cmath>` | [truncate function](https://en.cppreference.com/w/cpp/numeric/math/trunc) | 
| `trunc(u)` | `mathq` | `"mathq.h"` | **mathq** truncate | 
| `round(x)` | `std` | `<cmath>` | [round function](https://en.cppreference.com/w/cpp/numeric/math/round) | 
| `round(u)` | `mathq` | `"mathq.h"` | **mathq** round function | 
| `roundzero(u, tolerance = Functions<X>::tolerance)` | `mathq` | `"mathq.h"` | round numbers with magnitude less than `tolerance` to 0. The default values are shown below. | 
| `sgn(u)` | `mathq` | `"mathq.h"` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | 
| `zero(u)` | `mathq` | `"mathq.h"` | return a zero with the same type as x | 


Notes:
The default `zero_tolerance` values are global variables and can be changed by the user code.
The default values were chosen so that the typical numerical error encountered with trig functions will produce exactly zero when appropriate.

```C++
☀ Functions<float>::tolerance ➜ 3.5e-07;
☀ Functions<double>::tolerance ➜ 1.5e-16;
☀ Functions<long double>::tolerance ➜ 1.5e-30;
```



<br>


The following functions / operators are provided for using real number types with imaginary and complex types.

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `real(x)` | `mathq` | `"mathq.h"` | returns x | 
| `imag(x)` | `mathq` | `"mathq.h"` | returns `zero(x)` | 
| `conj(x)` | `mathq` | `"mathq.h"` | returns x | 
| `~x` | `mathq` | `"mathq.h"` | returns x | 


*Trig Functions*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `sin(x)` | [sine](https://en.cppreference.com/w/cpp/numeric/math/sin) | 
| `cos(x)` | [cosine](https://en.cppreference.com/w/cpp/numeric/math/cos) | 
| `tan(x)` | [tangent](https://en.cppreference.com/w/cpp/numeric/math/tan) | 


*Inverse Trig Functions*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `asin(x)` | [arc sine](https://en.cppreference.com/w/cpp/numeric/math/asin) | 
| `acos(x)` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acos) | 
| `atan(x)` | [arc tangent: all results are mapped into -𝜋/2 <= 𝜃 <= +𝜋/2](https://en.cppreference.com/w/cpp/numeric/math/atan) | 
| `atan2(b, a)` | [arc tangent of b/a with full quadrant angles, 0 <= 𝜃 < +2𝜋](https://en.cppreference.com/w/cpp/numeric/math/atan2) | 


*Hyperbolic Trig Functions*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `sinh(x)` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/math/sinh) | 
| `cosh(x)` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/math/cosh) | 
| `tanh(x)` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/math/tanh) | 


*Inverse Hyperbolic Trig Functions*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `asinh(x)` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/math/asinh) | 
| `acosh(x)` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acosh) | 
| `atanh(x)` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/math/atanh) | 


*Exponentiation*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/math/pow) | 
| `sqrt(x)` | [Square Root](https://en.cppreference.com/w/cpp/numeric/math/sqrt) | 
| `cqrt(x)` | [Cube Root](https://en.cppreference.com/w/cpp/numeric/math/cqrt) | 


*Exponentials*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `exp(x)` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp) | 
| `exp2(x)` | [2<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp2) | 
| `expm1(x)` | [e<sup>x</sup> - 1](https://en.cppreference.com/w/cpp/numeric/math/expm1) | 


*Logarithms*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `log(x)` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log) | 
| `log10(x)` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log10) | 
| `log2(x)` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log2) | 
| `log1p(x)` | [ln(x + 1)](https://en.cppreference.com/w/cpp/numeric/math/log1p) | 
| `logb(x)` | [extracts exponent of the number and returns a floating point type](https://en.cppreference.com/w/cpp/numeric/math/logb) | 
| `ilogb(x)` | [extracts exponent of the number and returns an integral type](https://en.cppreference.com/w/cpp/numeric/math/ilogb) | 


*Other Functions*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `erf(x)` | [error function, erf(x)](https://en.cppreference.com/w/cpp/numeric/math/erf) | 
| `erfc(x)` | [complimentary error function, erfc(x)](https://en.cppreference.com/w/cpp/numeric/math/erfc) | 
| `tgamma(x)` | [Gamma Function, Γ(x)](https://en.cppreference.com/w/cpp/numeric/math/tgamma) | 
| `lgamma(x)` | [Natural Logarithm of the Gamma Function, ln(Γ(x))](https://en.cppreference.com/w/cpp/numeric/math/lgamma) | 



<br>

### Mathematical functions from the C++ [``std::complex`` header](https://en.cppreference.com/w/cpp/numeric/complex)

COMPLEX FUNCTIONS

| function | name | 
| :---: | :---: | 
| `abs` | [absolute value](https://en.cppreference.com/w/cpp/numeric/complex/abs) | 
| `ceil` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/complex/ceil) | 
| `floor` | [floor function](https://en.cppreference.com/w/cpp/numeric/complex/floor) | 
| `trunc` | [truncate function](https://en.cppreference.com/w/cpp/numeric/complex/trunc) | 
| `round` | [round function](https://en.cppreference.com/w/cpp/numeric/complex/round) | 


*Trig Functions*

| function | name | 
| :---: | :---: | 
| `sin` | [sine](https://en.cppreference.com/w/cpp/numeric/complex/sin) | 
| `cos` | [cosine](https://en.cppreference.com/w/cpp/numeric/complex/cos) | 
| `tan` | [tangent](https://en.cppreference.com/w/cpp/numeric/complex/tan) | 


*Inverse Trig Functions*

| function | name | 
| :---: | :---: | 
| `asin` | [arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asin) | 
| `acos` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acos) | 
| `atan` | [arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atan) | 


*Hyperbolic Trig Functions*

| function | name | 
| :---: | :---: | 
| `sinh` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/complex/sinh) | 
| `cosh` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/complex/cosh) | 
| `tanh` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/complex/tanh) | 


*Inverse Hyperbolic Trig Functions*

| function | name | 
| :---: | :---: | 
| `asinh` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asinh) | 
| `acosh` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acosh) | 
| `atanh` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atanh) | 


*Exponentiation*

| function | name | 
| :---: | :---: | 
| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/complex/pow) | 
| `sqrt` | [Square Root](https://en.cppreference.com/w/cpp/numeric/complex/sqrt) | 


*Exponentials*

| function | name | 
| :---: | :---: | 
| `exp` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/complex/exp) | 


*Logarithms*

| function | name | 
| :---: | :---: | 
| `log` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log) | 
| `log10` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log10) | 
| `log2` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log2) | 


#### C++ ``std`` library special functions
The following [special mathematical functions](https://en.cppreference.com/w/cpp/numeric/special_functions) implemented in the C++ `std` library

*Bessel Functions*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `cyl_bessel_j(𝜈, x)` | _J_<sub>𝜈</sub>(_x_) | [Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_j) | 
| `cyl_neumann(𝜈, x)` | _Y_<sub>𝜈</sub>(_x_) | [Bessel (aka Neumann or Weber) function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_neumann) | 
| `cyl_bessel_i(𝜈, x)` | _I_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_i) | 
| `cyl_bessel_k(𝜈, x)` | _K_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_k) | 


*Spherical Bessel Functions*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `sph_bessel(n, x)` | _j_<sub>n</sub>(_x_) | [Spherical Bessel function of the 1st kind of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_bessel) | 
| `sph_neumann(n, x)` | _y_<sub>n</sub>(_x_) | [Spherical Bessel (aka Neumann or Weber) function of the 2nd kind of degree n, aka Spherical Neumann function](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_neumann) | 


*Orthogonal Polynomials*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `hermite(n, x)` | _H_<sub>n</sub>(_x_) | [Hermite polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/hermite) | 
| `laguerre(n, x)` | _L_<sub>n</sub>(_x_) | [Laguerre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/laguerre) | 
| `legendre(n, x)` | _P_<sub>n</sub>(_x_) | [Legendre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/legendre) | 
| `assoc_laguerre(n, m, x)` | _L_<sub>n,m</sub>(_x_) | [Associated Laguerre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_laguerre) | 
| `assoc_legendre(n, m, x)` | _P_<sub>n,m</sub>(_x_) | [Associated Legendre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_legendre) | 


*Other Special Functions*

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `beta(x, y)` |  B(_x_,_y_) | [Euler beta function (Euler Integral of the 1st kind)](https://en.cppreference.com/w/cpp/numeric/special_functions/beta) | 
| `comp_ellint_1(k)` |  _K_(_k_) |  [Complete elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_1) | 
| `comp_ellint_2(k)` |  _E_(_k_) |  [Complete elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_2) | 
| `comp_ellint_3(n, k)` |  _Π_(_n_,_k_) |  [Complete elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_3) | 
| `ellint_1(k, φ)` |  _F_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_1) | 
| `ellint_2(k, φ)` |  _E_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_2) | 
| `ellint_3(k, n, φ)` |  _Π_(_n_; _φ_, _k_) |  [(Incomplete) elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_3) | 
| `expint(x)` |  Ei(_x_) |  [Exponential Integral](https://en.cppreference.com/w/cpp/numeric/special_functions/expint) | 
| `riemann_zeta(x)` |  ζ(_x_) | [Riemann Zeta Function](https://en.cppreference.com/w/cpp/numeric/special_functions/riemann_zeta) | 
| `sph_legendre(l, m, θ)` | _Y_<sub>_l_</sub><sup>_m_</sup></sub>(_θ_, _φ_=0) | [Spherical Associated Legendre function<sup>†</sup> of degree _l_, order _m_](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_legendre) | 


† This is equal to a [Spherical Harmonic](https://en.wikipedia.org/wiki/Spherical_harmonics) with _φ_=0, as the notation implies.
### Mathematical functions from the Mathématiques library, namespace `mathq`
The following are mathematical functions implemented in the Mathématiques library, namespace `mathq`

| <div style='width:225px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `sqr(x)` | x<sup>2</sup> | 
| `cube(x)` | x<sup>3</sup> | 



<br>

## More on types
### Type information
#### typeid(x)
The function [`std::typeid`](https://en.cppreference.com/w/cpp/language/typeid) returns an object of type [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) (defined in the header `<typeinfo>`). 
This gives the type for any varable. However, the names are garbled compiler strings that are not pretty. 

Examples:

```C++
int n = 3;
☀ typeid(n).name() ➜ i;
string s = "hello";
☀ typeid(s).name() ➜ NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;
```

<br>

#### getTypeName(x)
The function `mathq::display::getTypeName` returns a string that gives the actual human-readable type name. It works for most [fundamental types](https://en.cppreference.com/w/cpp/language/types) and all classes defined in 
Examples:

```C++
int n = 3;
☀ getTypeName(n) ➜ int;
string s = "hello";
☀ getTypeName(s) ➜ std::string;
```

<br>

### Mixed-typed math and auto-promotion

C++ automatically converts number types depending on context.
This is referred to as [implicit conversion](https://en.cppreference.com/w/c/language/conversion).
For example, when adding an integer and a floating point number, the integer is first converted to a floating point type before the addition takes place.
As another example, when adding two integers (or floating point types) of different sizes, the smaller size is first converted to the larger size. This porces is referred to as _promotion_.
Examples:

```C++
short n1 = 3;
int n2 = 100;
☀ n1 * n2 ➜ int 300;

float x1 = 3;
double x2 = 0.1415;
☀ x1 + x2 ➜ double 3.1415;

int8_t y1 = 25;
double y2 = 0.25;
☀ y1 / y2 + y2 ➜ double 100.25;
```

<br>

### Type Conversion
There are various ways to cast one type to another in C++.  
Here we demonstrate [explicit conversion](https://en.cppreference.com/w/cpp/language/explicit_cast), which has two forms for the syntax: `(type) expression` or  `type(expression)` 


Converting a floating point type to an integer:

```C++
int n1 = (int)3.14;
☀ n1 ➜ int 3;
int n2 = int(3.14);
☀ n2 ➜ int 3;
```
Forcing floating point division by converting the numerator to a `float`

```C++
double x = (21 + 1) / 7;
☀ x ➜ double 3;
double y = float(21 + 1) / 7;
☀ y ➜ double 3.14286;
```


| ⇦ <br />[Operators](../operators/README.md)  | [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br />Functions<br /><img width=1000/> | ⇨ <br />[Linear Algebra](../linear-algebra/README.md)   |
| ------------ | :-------------------------------: | ------------ |

