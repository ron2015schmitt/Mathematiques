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
7.2.3. [Imaginary numbers](../imaginary/README.md)<br>
7.2.4. _Quaternions_ <br>


</details>



# 7.2.4. Quaternions



## Introduction
The [quaternions](https://mathworld.wolfram.com/Quaternion.html) are a non-communative [division algebra](https://en.wikipedia.org/wiki/Division_algebra).
The quaternions are the third algebra in the sequence of [Cayley–Dickson algebras](https://en.wikipedia.org/wiki/Cayley%E2%80%93Dickson_construction), with the first two algebras being the reals and the complex numbers. 
They were [invented by Hamilton in 1843](https://en.wikipedia.org/wiki/Quaternion), as a generalization of complex numbers.  

A quaternion can be written in terms of a real number, imaginary number, and two other numbers:

q = a + b **i** + c **j** + d **k**

Multiplication of the basis elements is defined as follows.  Note that multiplication is not commutative 

| × | 1 | **i** | **j** | **k** | 
| :---: | :---: | :---: | :---: | :---: |
| 1 |1 | i | j | k | 
| **i** |i | -1 | k | -j | 
| **j** |j | -k | -1 | i | 
| **k** |k | j | -i | -1 | 

The above table is referred to as the [Cayley Table](https://en.wikipedia.org/wiki/Cayley_table) for Quaternions.  Each entry is the product of the row label times the col label.



<br>

## Size of quaternionss
The size of a quaternions is simply _four times_ the size of the underlying arithmetic type:


```C++
☀ CHAR_BIT ➜ 8 bits;

☀ CHAR_BIT*sizeof(int) ➜ 32 bits;
☀ CHAR_BIT*sizeof(Quaternion<int>) ➜ 128 bits;

☀ CHAR_BIT*sizeof(double) ➜ 64 bits;
☀ CHAR_BIT*sizeof(Quaternion<double>) ➜ 256 bits;

☀ CHAR_BIT*sizeof(long double) ➜ 128 bits;
☀ CHAR_BIT*sizeof(Quaternion<long double>) ➜ 512 bits;

```
## Declaration and initialization
Declaring quaternion variables in Mathématiques


```C++
using namespace mathq;
using namespace mathq::unit_imaginary;
using namespace mathq::unit_quaternion;

auto q1 = Quaternion<double>(1, 2, -1, -3);
auto q2 = Quaternion<double>(4, 3, -2, -5);
auto q = Quaternion<double>() = 16 + 2*i + 3*j + 13*k;
auto p = Quaternion<double>() = 0.53767 + 0.86217*i - 0.43359*j + 2.7694*k;
```
In the above expressions we used the constants `i`, `j`, and `k`, which are defined as follows:

```C++
☀ mathq::unit_imaginary::i ➜ Imaginary<double> i;
☀ mathq::unit_quaternion::j ➜ Quaternion<double> j;
☀ mathq::unit_quaternion::k ➜ Quaternion<double> k;
```
Unlike the standard C++ `i`, which is an operator, the Mathématiques `i`, `j`, and `k` are constants
## Arithmetic Operators
The 4 fundamental arithmetic operators can be used with quaternions.
Mathématiques supports the four arithmetic operators for quaternions:

```C++
☀ q1+q2 ➜ Quaternion<double> 5 + 5*i + -3*j + -8*k;
☀ q1-q2 ➜ Quaternion<double> -3 + -i + j + 2*k;
☀ q1*q2 ➜ Quaternion<double> -19 + 10*i + -5*j + -18*k;
☀ q2/q1 ➜ Quaternion<double> 1.8 + -0.4*i + 0.2*j + 0.4*k;
```
## Methods
Assume `q`  is of type `Quaternion<D>` with 

> _q_ = _a_ + _b_ **i** + _c_ **j** + _d_ **k** 

The scalar+vector form of q is 

>  _q_ = _a_ + **v**. 

The polar form of q is: 

> _q_ = ||_q_|| ( cos _φ_ + **n̂** sin _φ_ ). 

where  

> _φ_ ≐  cos<sup-1></sup>( _a_/||_q_|| ). 

and  

> **n̂** ≐ **v**/||**v**||

Note that for complex numbers **n̂** = +i or -i.  

| syntax | modifies q? | description | 
| :---: | :---: | :---: | 
| `Quaternion<D> invert()` | yes | q := 1/q, returns `q` | 
| `Quaternion<D> negate()` | yes | q := -q, returns `q` | 
| `Quaternion<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | 
| `D real()` | no | returns the real part of `q` | 
| `D imag()` | no | returns the i-component part of `q` | 
| `D jmag()` | no | returns the j-component part of `q` | 
| `D kmag()` | no | returns the k-component of `q` | 
| `D abs()` | no | returns \|\|_q_\|\|, the magnitude of `q` | 
| `D normsqr()` | no | returns the magnitude-squared of `q` | 
| `D scalar()` | no | same as real() | 
| `Quaternion<D> normalized()` | no | returns _q_/\|\|_q_\|\| | 
| `Vector<D,3> vector()` | no | returns **v**, the vector part of `q` | 
| `Vector<D,3> unitvector()` | no | returns **n̂**, the vector part of `q` normalized to 1 | 
| `D vabs()` | no | returns, _v_=\|\|**v**\|\| the magnitude of `q.vector()` | 
| `D vnormsqr()` | no | returns \|\|**v**\|\|<sup>2</sup> | 
| `D angle()` | no | returns φ as defined above | 
| `std::tuple<D, D, Vector<D, 3>> polar()` | no | returns { \|\|_q_\|\|, φ, **n̂** } as a tuple | 
| `Matrix<std::complex<D>, 2, 2> matrix2by2()` | no | returns **Q**, the 2x2 matrix form<sup>1</sup> of _q_ | 

1. **Q** = [  _a_ + **i** _b_,  _c_ + **i** _d_; 
             -_c_ + **i** _d_,  _a_ - **i** _b_  ]

A few examples are shown below.

```C++
☀ q1 ➜ Quaternion<double> 1 + 2*i + -j + -3*k;
☀ q1.real() ➜ double 1;
☀ q1.imag() ➜ double 2;
☀ q1.jmag() ➜ double -1;
☀ q1.kmag() ➜ double -3;
☀ q1.abs() ➜ double 3.87298;
☀ q1.scalar() ➜ double 1;
☀ q1.vector() ➜ Vector<double,NE=3> {2, -1, -3};
☀ q1.vabs() ➜ double 3.74166;
☀ q1.unitvector() ➜ Vector<double,NE=3> {0.534522, -0.267261, -0.801784};
☀ q1.angle() ➜ double 1.30964;
☀ q1.polar() ➜ std::tuple<double,double,Vector<double,NE=3>> {3.87298,1.30964,{0.534522, -0.267261, -0.801784}};
☀ q1.matrix2by2() ➜ Matrix<std::complex<double>,NR=2,NC=2> { {(1,2), (-1,-3)}, {(1,-3), (1,-2)} };
```
typename = std::tuple<double,double,Vector<double,NE=3>>
## Functions

Mathématiques supports several quaternion functions.  These are listed in detail in the section on functions.
Below are a few examples.



```C++
☀ q ➜ Quaternion<double> 16 + 2*i + 3*j + 13*k;
☀ exp(q) ➜ Quaternion<double> 5.35246e+06 + 1.05157e+06*i + 1.57736e+06*j + 6.83522e+06*k;
☀ log(q) ➜ Quaternion<double> 3.04111 + 0.103851*i + 0.155777*j + 0.675034*k;
☀ pow(q, 2) ➜ Quaternion<double> 74 + 64*i + 96*j + 416*k;
☀ pow(q, 0.5) ➜ Quaternion<double> 4.297 + 0.23272*i + 0.349081*j + 1.51268*k;
☀ inv(q) ➜ Quaternion<double> 0.0365297 + -0.00456621*i + -0.00684932*j + -0.0296804*k;
☀ conj(q) ➜ Quaternion<double> 16 + -2*i + -3*j + -13*k;
```
## Containers of Quaternions

Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>` can have quaternions as their underlying type.
Below are examples of container math with quaternions.  Mixed math is allowed.


```C++
auto v = Vector<Quaternion<double>>({ 16 + 2*i + 3*j + 13*k, 5 + 11*i + 10*j + 8*k, 9 + 7*i + 6*j + 12*k, 4 + 14*i + 15*j + 1*k });
```
```C++
☀ q ➜ Quaternion<double> 16 + 2*i + 3*j + 13*k;

☀ v ➜ Vector<Quaternion<double>> {
16 + 2*i + 3*j + 13*k, 
5 + 11*i + 10*j + 8*k, 
9 + 7*i + 6*j + 12*k, 
4 + 14*i + 15*j + k};

☀ v + q ➜ TER_Binary Vector<Quaternion<double>> {
32 + 4*i + 6*j + 26*k, 
21 + 13*i + 13*j + 21*k, 
25 + 9*i + 9*j + 25*k, 
20 + 16*i + 18*j + 14*k};

☀ exp(v) ➜ TER_Unary Vector<Quaternion<double>> {
5.35246e+06 + 1.05157e+06*i + 1.57736e+06*j + 6.83522e+06*k, 
-57.3593 + -89.1893*i + -81.0812*j + -64.865*k, 
-6799.09 + 2039.12*i + 1747.82*j + 3495.64*k, 
-6.65998 + 36.9313*i + 39.5692*j + 2.63795*k};

```


| ⇦ <br />[Imaginary numbers](../imaginary/README.md)  | [Scalar Types (Real, Imaginary, Complex & Quaternion)](../README.md)<br />Quaternions<br /><img width=1000/> | ⇨ <br />   |
| ------------ | :-------------------------------: | ------------ |

