<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.78-c++17</h1>

<details>

<summary>User Manual</summary>

# [User Manual](../../../README.md)<br>
1. [About](../../../about/README.md)<br>
2. [License](../../../license/README.md)<br>
3. [Status, Planned Work & Release Notes](../../../status-release/README.md)<br>
4. [Description and Example Usage](../../../description-examples/README.md)<br>
5. [Installation](../../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../../first-project/README.md)<br>
7. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
8. [Benchmarks](../../../benchmarks/README.md)<br>
9. [Tests](../../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [7. Usage Guide: Syntax, Data Types, Functions, etc](../../README.md)<br>
7.1. [Usage Guide Notation](../../notation/README.md)<br>
7.2. _Scalar Types (Real, Imaginary, Complex & Quaternion)_ <br>
7.3. [Container Types (Vector, Matrix & Tensor)](../../containers/README.md)<br>
7.4. [Operators](../../operators/README.md)<br>
7.5. [Functions](../../functions/README.md)<br>
7.6. [Linear Algebra](../../linear-algebra/README.md)<br>
7.7. [Indexing, Masks, and Sorting](../../indexing-sorting/README.md)<br>
7.8. [Ranges and Grids](../../ranges-grids/README.md)<br>
7.9. [Calculus](../../calculus/README.md)<br>
7.10. [Vector Calculus](../../vector-calculus/README.md)<br>
7.11. [Tensor Calculus](../../tensor-calculus/README.md)<br>
7.12. [Display of Results](../../display/README.md)<br>
7.13. [FILE I/O](../../file-io/README.md)<br>
7.14. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Scalar Types (Real, Imaginary, Complex & Quaternion)</summary>

# [7.2. Scalar Types (Real, Imaginary, Complex & Quaternion)](../README.md)<br>
7.2.1. [Reals](../real/README.md)<br>
7.2.2. [Complex numbers](../complex/README.md)<br>
7.2.3. _Imaginary numbers_ <br>
7.2.4. [Quaternions](../quaternion/README.md)<br>


</details>



# 7.2.3. Imaginary numbers



## Introduction
The [imaginary numbers](https://mathworld.wolfram.com/Imaginary.html) are a non-communative [division algebra](https://en.wikipedia.org/wiki/Division_algebra).



<br>

## Size of imaginary numbers
The size of a imaginary numbers is the same size of the underlying arithmetic type:


```C++
☀ CHAR_BIT ➜ 8 bits;

☀ CHAR_BIT*sizeof(int) ➜ 32 bits;
☀ CHAR_BIT*sizeof(Imaginary<int>) ➜ 32 bits;

☀ CHAR_BIT*sizeof(double) ➜ 64 bits;
☀ CHAR_BIT*sizeof(Imaginary<double>) ➜ 64 bits;

☀ CHAR_BIT*sizeof(long double) ➜ 128 bits;
☀ CHAR_BIT*sizeof(Imaginary<long double>) ➜ 128 bits;

```
## Declaration and initialization
Declaring quaternion variables in Mathématiques


```C++
using namespace mathq;
using namespace mathq::unit_imaginary;

Imaginary<double> q1 = Imaginary<double>(2.5);
auto q2 = Imaginary<double>() = 2*i;
auto q = Imaginary<double>() = -i/0.25;

☀ q1 ➜ Imaginary<double> 2.5i;
☀ q2 ➜ Imaginary<double> 2i;
☀ q ➜ Imaginary<double> -4i;
```
In the above expressions we used the constant `i` which is defined as follows:

```C++
☀ mathq::unit_imaginary::i ➜ Imaginary<double> i;
```
Unlike the standard C++ `i`, which is an operator, the Mathématiques `i`, `j`, and `k` are constants
## Arithmetic
The 4 fundamental arithmetic operators can be used with imaginary numbers.
Mathématiques supports the four arithmetic operators for imaginary numbers:

```C++
☀ q1+q2 ➜ Imaginary<double> 4.5i;
☀ q1-q2 ➜ Imaginary<double> 0.5i;
☀ q1*q2 ➜ double -5;
☀ q2/q1 ➜ double 0.8;
```
## Methods
Assume `q`  is of type `Imaginary<D>` with 

| syntax | modifies q? | description | 
| :---: | :---: | :---: | 
| `Imaginary<D> invert()` | yes | q := 1/q, returns `q` | 
| `Imaginary<D> negate()` | yes | q := -q, returns `q` | 
| `Imaginary<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | 
| `D real()` | no | returns the real part of `q`, ie zero | 
| `D imag()` | no | returns the i-component part of `q` | 
| `D value()` | no | returns the i-component part of `q` | 
| `D abs()` | no | returns \|_q_\|, the magnitude of `q` | 
| `D normsqr()` | no | returns the magnitude-squared of `q` | 
A few examples are shown below.

```C++
☀ q1 ➜ Imaginary<double> 2.5i;
☀ q1.real() ➜ double 0;
☀ q1.imag() ➜ double 2.5;
☀ q1.value() ➜ double 2.5;
☀ q1.abs() ➜ double 2.5;
☀ q1.normsqr() ➜ double 6.25;
```
## Operators & Functions

C++ supports many functions and Mathématiques provides several more.  These are listed in detail in the sections on opetators and functions.  C++ supports mixed type arithmetic between all the real types.
Below are a few examples.



```C++
double pi = 3.14159265358979311599796346854;
☀ 2*i*i ➜ double -2;
☀ 20*i*i/(4*i) ➜ Imaginary<double> 5i;
☀ 2*i*i + 3 ➜ double 1;
☀ i/i + i/5 +4*i + 4 ➜ std::complex<double> (5,4.2);
☀ 1 + i ➜ std::complex<double> (1,1);
☀ 20 + i/0.25 ➜ std::complex<double> (20,4);
☀ 10*exp(i*pi/4) ➜ std::complex<double> (7.07107,7.07107);
☀ 10*cos(pi/4) + 10*i*sin(pi/4) ➜ std::complex<double> (7.07107,7.07107);
☀ exp(1+i*pi/4)/2.71828 ➜ std::complex<double> (0.707107,0.707107);

☀ q ➜ Imaginary<double> -4i;
☀ pow(q, 7) ➜ std::complex<double> (-7.02261e-12,16384);
```
## Containers of Imaginary numbers

Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>` can have imaginary numbers as their underlying type.
Below are examples of container math with imaginary numbers.  Mixed math is allowed.


```C++
auto v = Vector<Imaginary<double>>({ i, i, -i, i });
```
```C++
☀ q ➜ Imaginary<double> -4i;

☀ v ➜ Vector<Imaginary<double>> {i, i, -1i, i};

☀ v + q ➜ TER_Binary Vector<Imaginary<double>> {-3i, -3i, -5i, -3i};

☀ exp(v) ➜ TER_Unary Vector<std::complex<double>> {(0.540302,0.841471), (0.540302,0.841471), (0.540302,-0.841471), (0.540302,0.841471)};

☀ exp(v) + v ➜ TER_Binary Vector<std::complex<double>> {(0.540302,1.84147), (0.540302,1.84147), (0.540302,-1.84147), (0.540302,1.84147)};
☀ exp(v) + 1 ➜ TER_Binary Vector<std::complex<double>> {(1.5403,0.841471), (1.5403,0.841471), (1.5403,-0.841471), (1.5403,0.841471)};
☀ exp(v) + 2.3 ➜ TER_Binary Vector<std::complex<double>> {(2.8403,0.841471), (2.8403,0.841471), (2.8403,-0.841471), (2.8403,0.841471)};
☀ exp(v) + complex(1, 2) ➜ TER_Binary Vector<std::complex<double>> {(1.5403,2.84147), (1.5403,2.84147), (1.5403,1.15853), (1.5403,2.84147)};
☀ 2*exp(v) + Imaginary<double>(2) ➜ TER_Binary Vector<std::complex<double>> {(1.0806,3.68294), (1.0806,3.68294), (1.0806,0.317058), (1.0806,3.68294)};
```


| ⇦ <br />[Complex numbers](../complex/README.md)  | [Scalar Types (Real, Imaginary, Complex & Quaternion)](../README.md)<br />Imaginary numbers<br /><img width=1000/> | ⇨ <br />[Quaternions](../quaternion/README.md)   |
| ------------ | :-------------------------------: | ------------ |

