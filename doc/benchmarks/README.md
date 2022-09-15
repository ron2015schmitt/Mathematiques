[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.152-c++20</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Objectives](../objectives/README.md)<br>
Chapter 4. [Status & Release Notes](../status-release/README.md)<br>
Chapter 5. [Upcoming Development](../development-schedule/README.md)<br>
Chapter 6. [Introduction with Examples](../intro/README.md)<br>
Chapter 7. [Installation](../installation/README.md)<br>
Chapter 8. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 9. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 10. _Benchmarks_ <br>
Chapter 11. [Tests](../test/README.md)<br>
Chapter 12. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# Chapter 10. Benchmarks

_This document was generated from the C++ file_ `benchmarks/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 



## Memory Usage

### Vectors
| Type | Size<sup>1,2</sup> | Min<sup>1,3</sup> | Max<sup>1,4</sup> |
| :--- | :---: | :---: | :---: | 
| `char` | 8 bits | -128 | 127 | 
| `short` | 16 bits | -32768 | 32767 | 
| `int` | 32 bits | -2147483648 | 2147483647 | 
| `long` | 64 bits | -9223372036854775808 | 9223372036854775807 | 
| `long long` | 64 bits | -9223372036854775808 | 9223372036854775807 | 

<br>

## Speed
### Complicated Mathematical function of a Vector

$f(x) = 10 x + e^{i  [   2 \pi   +   \pi sin(  2 \pi x + \pi / 6  )   ] }$

**Hand-coded C**
```C++

 using namespace std::numbers;
 const std::complex<double> i(0, 1);
 constexpr size_t N = 500000;
 std::valarray<double> x(N);
 std::valarray<std::complex<double>> f(N);
 Timer timer;
 
 timer.start_timer_silent();
 for (size_t k = 0; k < N; k++) { 
   x[k] = double(k) / double(N - 1);
 }
 for (size_t k = 0; k < N; k++) { 
   f[k] = 10 * x[k] + exp(i * (2 * pi + pi * sin(2 * pi * x[k] + pi / 6)));
 }
 double elapsed = timer.stop_timer();


☀ elapsed ➜ 0.013355 sec;
```

**Mathématiques**
```C++

 using namespace std::numbers;
 const Imaginary<double> i{ 1 };
 constexpr size_t N = 500000;
 Vector<double> x(N);
 Vector<std::complex<double>> f(N);
 Timer timer;
 
 timer.start_timer_silent();
 x = linspace<double>(0, 1, N);
 f = 10 * x + exp(i * (2 * pi + pi * sin(2 * pi * x + pi / 6)));
 double elapsed = timer.stop_timer();


☀ elapsed ➜ 0.011987 sec;
```

<br>

### Matrix Multiply

$\mathbf{y} = \mathbf{A} \cdot \mathbf{x}$

**Hand-coded C**
```C++

 using namespace std::numbers;
 const std::complex<double> i(0, 1);
 constexpr size_t N = 1000;
 std::valarray<double> x(N);
 std::valarray<double> y(N);
 std::valarray<double> A(N*N);
 Timer timer;
 
 timer.start_timer_silent();
 for (size_t k = 0; k < N; k++) { 
   x[k] = double(k) / double(N - 1);
 };
 for (size_t k = 0; k < N*N; k++) { 
   A[k] = sin(double(k)*pi/double(N*N));
 };
 size_t step = 0;
 for (size_t r = 0; r < N; r++) { 
   y[r] = 0;
   for (size_t c = 0; c < N; c++) { 
     y[r] += A[step++] * x[c];
    }
 }
 double elapsed = timer.stop_timer();


☀ elapsed ➜ 0.007691 sec;
```

**Mathématiques**
```C++

 using namespace std::numbers;
 const Imaginary<double> i{ 1 };
 constexpr size_t N = 1000;
 Vector<double> x(N);
 Vector<double> y(N);
 Matrix<double> A(N, N);
 Timer timer;
 
 timer.start_timer_silent();
 x = linspace<double>(0, 1, N);
 for (size_t k = 0; k < N*N; k++) { 
   A[k] = sin(double(k)*pi/double(N*N));
 }
 y = A | x;
 double elapsed = timer.stop_timer();


☀ elapsed ➜ 0.005544 sec;
```



| ⇦ <br />[Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)  | [Documentation](../README.md)<br />Benchmarks<br /><img width=1000/> | ⇨ <br />[Tests](../test/README.md)   |
| ------------ | :-------------------------------: | ------------ |

