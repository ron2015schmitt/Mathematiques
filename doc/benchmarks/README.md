[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.032</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Why?](../why/README.md)<br>
Chapter 4. [Objectives](../objectives/README.md)<br>
Chapter 5. [Versioning](../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../development-schedule/README.md)<br>
Chapter 8. [Introduction with Examples](../intro/README.md)<br>
Chapter 9. [Installation](../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 11. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 12. _Benchmarks_ <br>
Chapter 13. [Tests](../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# Chapter 12. Benchmarks

_This document was generated from the C++ file_ `benchmarks/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 


## Memory Usage

The multiarrays provided by Mathématiques are a C++ template class that wraps either a `std::array` (for compile-time fixed-size multiarrays) or a `std::valarray` (for dynamic-size multiarrays)
```C++
Vector<double, 100> v;
☀ sizeof(v)/sizeof(double) ➜ 100;
```
```C++
Matrix<double, 10, 10> A;
☀ sizeof(A)/sizeof(double) ➜ 100;
```
```C++
Vector<std::complex<double>, 100> v;
☀ sizeof(v)/sizeof(double) ➜ 200;
```
```C++
Vector<Vector<double, 3>, 100> v;
☀ sizeof(v)/sizeof(double) ➜ 300;
```

<br>

## Run-Time Performance
The following tests are run during each build. The Mathématiques code is usually faster than hand-coded C.  The tests are repeated `Nloop` times and then the results are averaged.
### Test 1. Function of a Vector

$f(x) = 1 + 10 x + e^{i  [   2 \pi   +   \pi sin(  2 \pi x + \pi / 6  )   ] }$

```C++
using namespace std::numbers;
size_t Nloop = 30;
constexpr size_t N = 10000;
```
#### Results 1A. Hand-Coded C
```C++
const std::complex<double> i(0, 1);
std::valarray<double> x(N);
std::valarray<std::complex<double>> f(N);

for (size_t k = 0; k < N; k++) {
  x[k] = double(k) / double(N - 1);
}
for (size_t k = 0; k < N; k++) {
  f[k] = 1 + 10 * x[k] + exp(i * (2 * pi + pi * sin(2 * pi * x[k] + pi / 6)));
}
```
☀ elapsed_time ➜ 263 μsec;


#### Results 1B. Mathématiques C
```C++
const Imaginary<double> i{ 1 };
Vector<double> x(N);
Vector<std::complex<double>> f(N);

x = linspace<double>(0, 1, N);
f = 1 + 10 * x + exp(i * (2 * pi + pi * sin(2 * pi * x + pi / 6)));
```
☀ elapsed_time ➜ 241 μsec;


<br>

### Test 2. Matrix Multiply

$\mathbf{y} = \mathbf{A} \cdot \mathbf{x}$
```C++
using namespace std::numbers;
size_t Nloop = 30;
constexpr size_t N = 500;
```
#### Results 2A. Hand-Coded C
```C++
std::valarray<double> x(N);
std::valarray<double> y(N);
std::valarray<double> A(N* N);

for (size_t k = 0; k < N; k++) {
  x[k] = double(k) / double(N - 1);
}
for (size_t k = 0; k < N*N; k++) {
  A[k] = sin(double(k)*pi/double(N*N));
}
size_t step = 0;
for (size_t r = 0; r < N; r++) {
  y[r] = 0;
  for (size_t c = 0; c < N; c++) {
    y[r] += A[step++] * x[c];
  }
}
```
☀ elapsed_time ➜ 1339 μsec;


#### Results 2B. Mathématiques C
```C++
Vector<double> x(N);
Vector<double> y(N);
Matrix<double> A(N, N);

x = linspace<double>(0, 1, N);
for (size_t k = 0; k < N*N; k++) {
  A[k] = sin(double(k)*pi/double(N*N));
}
y = A | x;
```
☀ elapsed_time ➜ 1330 μsec;




| ⇦ <br />[Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)  | [Documentation](../README.md)<br />Benchmarks<br /><img width=1000/> | ⇨ <br />[Tests](../test/README.md)   |
| ------------ | :-------------------------------: | ------------ |

