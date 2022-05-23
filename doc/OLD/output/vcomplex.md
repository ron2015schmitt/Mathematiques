
[Table of Contents](README.md)


# Complex-valued Vectors in Mathématiques
_This document was automatically generated from file_ **`vcomplex.cpp`** (Mathématiques-v3.2-r1).

### Representing the unit imaginary _i_
* In C++, there is no definition for pure imaginary numbers.
* This is in contrast to Fortran.
* The unit imaginary is thus `complex<D>(0,1`


**EXAMPLE 1**: The unit imaginary _i_ in C++14

* In C++14, the unit imaginary is defined by the product operator `operator""i`
```C++
using namespace std;
using namespace literals;
using namespace complex_literals;
complex<double> z1 = 1i;
complex<double> z2 = 1+1i;
complex<double> z3 = -5i;
complex<double> z4 = 5;
```
**Some expressions with results**
```C++
  z1 = (0,1); 
  z2 = (1,1); 
  ~z2 = (1,-1); 
  z3 = (-0,-5); 
  z4 = (5,0); 
```



**EXAMPLE 2**: The unit imaginary _i_ (works in any version)

In earlier versions of C++, the unit imaginary can be defined by
```C++
using namespace std;
const complex<double> i = complex<double>(0,1);
complex<double> z1 = 1.*i;
complex<double> z2 = 1. + 1.*i;
complex<double> z3 = -5.*i;
complex<double> z4 = 5;
```

**Some expressions with results**
```C++
  z1 = (0,1); 
  z2 = (1,1); 
  z3 = (-0,-5); 
  z4 = (5,0); 
```

### Declaring a complex-valued `Vector`


**EXAMPLE 3**: Complex  `Vector` 
```C++
using namespace std;
Vector<complex<double> > v(4);
using namespace literals;
using namespace complex_literals;
v = { 1+1i, 1, 1i, 1-1i }; // C++11 list and C++14 literal `i` for unit imaginary 
```

**Some expressions with results**
```C++
  v = {(1,1), (1,0), (0,1), (1,-1)}; 
```

### Arithmetic with complex-valued `Vector`'s


**EXAMPLE 4**: Complex `Vector` arithmetic
```C++
using namespace std;
Vector<complex<double> > v1(4);
Vector<complex<double> > v2(4);
using namespace literals;
using namespace complex_literals;
v1 = { -1i, 0, 1-1i, 1+1i }; // C++11 list and C++14 literal `i` for unit imaginary 
v2 = { 1+1i, 1, 1i, -1i }; // C++11 list and C++14 literal `i` for unit imaginary 
```

**Some expressions with results**
```C++
  v1+v2 = Vector<std::complex<double>> {(1,0), (1,0), (1,0), (1,0)}; 
  v1-v2 = Vector<std::complex<double>> {(-1,-2), (-1,0), (1,-2), (1,2)}; 
  v1*v2 = Vector<std::complex<double>> {(1,-1), (0,0), (1,1), (1,-1)}; 
  v1/v2 = Vector<std::complex<double>> {(-0.5,-0.5), (0,0), (-1,-1), (-1,1)}; 
```

### Mixed arithmetic with complex and real vectors and scalars `Vector`'s


**EXAMPLE 5**: Mixed real and complex arithmetic 
```C++
using namespace std;
Vector<double > vr(4);
Vector<complex<double> > vc(4);
using namespace literals;
using namespace complex_literals;
vr = { 1, 2, 3, 4 }; // C++11 list 
vc = { 1+1i, 1, 1i, -1i }; // C++11 list and C++14 literal `i` for unit imaginary 
```

**Some expressions with results**
```C++
  vr+vc = Vector<std::complex<double>> {(2,1), (3,0), (3,1), (4,-1)}; 
  vr-vc = Vector<std::complex<double>> {(0,-1), (1,-0), (3,-1), (4,1)}; 
  vr*vc = Vector<std::complex<double>> {(1,1), (2,0), (0,3), (-0,-4)}; 
  vr/vc = Vector<std::complex<double>> {(0.5,-0.5), (2,0), (0,-3), (-0,4)}; 
  2.*vr + vc/2. + 1 = Vector<std::complex<double>> {(3.5,0.5), (5.5,0), (7,0.5), (9,-0.5)}; 
  complex<double>(0,1)*vr + complex<double>(5,2)*vc = Vector<std::complex<double>> {(3,8), (5,4), (-2,8), (2,-1)}; 
```

### real and imag parts of `Vector`'s


**EXAMPLE 6**: get the real and imaginary part of a complex vector
```C++
using namespace std;
Vector<complex<double> > v(4);
v = {1+1.i, 1., 1.i, 2-5.i}; // C++11 list and C++14 imag
```

**Some expressions with results**: real and imaginary parts
```C++
  v = {(1,1), (1,0), (0,1), (2,-5)}; 
  real(v) = Vector<double> {1, 1, 0, 2}; 
  imag(v) = Vector<double> {1, 0, 1, -5}; 
```


### creating complex Vectors from real vectors and scalars


**EXAMPLE 7**: create a complex vector from two real vectors
```C++
using namespace std;
Vector<complex<double> > vc(4);
Vector<double> vr( range<double>(1,4) );
Vector<double> vi( range<double>(-1,-4) );
vc = Complex(vr, vi);
```

**Some expressions with results**: create a complex vector from two real vectors
```C++
  vr = {1, 2, 3, 4}; 
  vi = {-1, -2, -3, -4}; 
  vc = {(1,-1), (2,-2), (3,-3), (4,-4)}; 
  real(vc) = Vector<double> {1, 2, 3, 4}; 
  imag(vc) = Vector<double> {-1, -2, -3, -4}; 
```




**EXAMPLE 8**: create a complex vector from a real vector and a scalar
```C++
using namespace std;
Vector<double> v( range<double>(1,4) );
```

**Some expressions with results**: create a complex vector from a real vector and a scalar
```C++
  Complex(v, 0.) = Vector<std::complex<double>> {(1,0), (2,0), (3,0), (4,0)}; 
  Complex(v, 1.) = Vector<std::complex<double>> {(1,1), (2,1), (3,1), (4,1)}; 
  Complex(0., v) = Vector<std::complex<double>> {(0,1), (0,2), (0,3), (0,4)}; 
  Complex(1., v) = Vector<std::complex<double>> {(1,1), (1,2), (1,3), (1,4)}; 
```


### Complex Conjugation
Complex cojugation can be performed via the function `conj` or via the operator `~`


**EXAMPLE 9**: compute the complex conjugate of a vector
```C++
using namespace std;
Vector<complex<double> > vc(3);
Vector<double> vr( range<double>(1,3) );
Vector<double> vi( range<double>(-1,1) );
vc = Complex(vr, vi);
```

**Some expressions with results**: compute the complex conjugate of a vector
```C++
  vr = {1, 2, 3}; 
  vi = {-1, 0, 1}; 
  vc = {(1,-1), (2,0), (3,1)}; 
  conj(vc) = Vector<std::complex<double>> {(1,1), (2,-0), (3,-1)}; 
  ~vc = Vector<std::complex<double>> {(1,1), (2,-0), (3,-1)}; 
```


* Functions defined for complex vectors  


**EXAMPLE10**: functions of complex vectors
```C++
const double pi = 3.14159265358979323846;
using namespace std;
Vector<complex<double> > v(3);
Vector<double> vr( range<double>(1,3) );
Vector<double> vi( range<double>(-1,1) );
v = Complex(vr, vi);
```

**Some expressions with results**: functions of complex vectors
```C++
  v = {(1,-1), (2,0), (3,1)}; 
  abs(v)* ( cos(arg(v)) + Complex(0., sin(arg(v))) ) = Vector<std::complex<double>> {(1,-1), (2,0), (3,1)}; 
  abs(v) = Vector<double> {1.41421, 2, 3.16228}; 
  pow(2., v) = Vector<std::complex<double>> {(1.53848,-1.27792), (4,0), (6.15391,5.11169)}; 
  pow(v, 2.) = Vector<std::complex<double>> {(1.22465e-16,-2), (4,0), (8,6)}; 
  pow(v,v) = Vector<std::complex<double>> {(0.273957,-0.583701), (4,0), (-11.8982,19.5929)}; 
  exp(v) = Vector<std::complex<double>> {(1.46869,-2.28736), (7.38906,0), (10.8523,16.9014)}; 
  round(exp(v)) = Vector<std::complex<double>> {(1,-2), (7,0), (11,17)}; 
  roundzero(v+1e-16) = Vector<std::complex<double>> {(1,-1), (2,0), (3,1)}; 
  log(v) = Vector<std::complex<double>> {(0.346574,-0.785398), (0.693147,0), (1.15129,0.321751)}; 
  log10(v) = Vector<std::complex<double>> {(0.150515,-0.341094), (0.30103,0), (0.5,0.139734)}; 
  sqr(v) = Vector<std::complex<double>> {(0,-2), (4,0), (8,6)}; 
  cube(v) = Vector<std::complex<double>> {(-2,-2), (8,0), (18,26)}; 
  sqrt(v) = Vector<std::complex<double>> {(1.09868,-0.45509), (1.41421,0), (1.75532,0.284849)}; 
  sin(v) = Vector<std::complex<double>> {(1.29846,-0.634964), (0.909297,-0), (0.21776,-1.16344)}; 
  cos(v) = Vector<std::complex<double>> {(0.83373,0.988898), (-0.416147,-0), (-1.52764,-0.165844)}; 
  tan(v) = Vector<std::complex<double>> {(0.271753,-1.08392), (-2.18504,0), (-0.0591685,0.768018)}; 
  sinh(v) = Vector<std::complex<double>> {(0.634964,-1.29846), (3.62686,0), (5.41268,8.47165)}; 
  cosh(v) = Vector<std::complex<double>> {(0.83373,-0.988898), (3.7622,0), (5.43958,8.42975)}; 
  tanh(v) = Vector<std::complex<double>> {(1.08392,-0.271753), (0.964028,0), (1.00205,0.00451714)}; 
  asin(v) = Vector<std::complex<double>> {(0.666239,-1.06128), (1.5708,1.31696), (1.2331,1.8242)}; 
  acos(v) = Vector<std::complex<double>> {(0.904557,1.06128), (0,-1.31696), (0.337701,-1.8242)}; 
  atan(v) = Vector<std::complex<double>> {(1.01722,-0.402359), (1.10715,0), (1.2768,0.0919312)}; 
  atan2(vr, vi) = Vector<double> {2.35619, 1.5708, 1.24905}; 
```


**Results**Aritmetic with scalars
```C++
  v + 0.1 = Vector<std::complex<double>> {(1.1,-1), (2.1,0), (3.1,1)}; 
  0.1 + v = Vector<std::complex<double>> {(1.1,-1), (2.1,0), (3.1,1)}; 
  v - 0.1 = Vector<std::complex<double>> {(0.9,-1), (1.9,0), (2.9,1)}; 
  0.1 - v = Vector<std::complex<double>> {(-0.9,1), (-1.9,-0), (-2.9,-1)}; 
```



[Table of Contents](README.md)
