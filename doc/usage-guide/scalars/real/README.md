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

7.2.1. _Reals_ <br>
7.2.2. [Complex numbers](../complex/README.md)<br>
7.2.3. [Imaginary numbers](../imaginary/README.md)<br>
7.2.4. [Quaternions](../quaternion/README.md)<br>


</details>



# 7.2.1. Reals

_This document was generated from the C++ file_ `real/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 

C++ supports a wide variety of real numbers [integer and floating point types](https://en.cppreference.com/w/cpp/language/types).

## Integers

### Signed Integers
C++ supports several different signed integer types.  **The size of each depends on the CPU and compiler**.  For a 64-bit CPU running Linux, they have the following number of bits:
The symbol [`CHAR_BIT`](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [`sizeof()`](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.

The maximum and minimum for each type are given below.
| Type | Size<sup>1,2</sup> | Min<sup>1,3</sup> | Max<sup>1,4</sup> |
| :--- | :---: | :---: | :---: | 
| `char` | 8 bits | -128 | 127 | 
| `short` | 16 bits | -32768 | 32767 | 
| `int` | 32 bits | -2147483648 | 2147483647 | 
| `long` | 64 bits | -9223372036854775808 | 9223372036854775807 | 
| `long long` | 64 bits | -9223372036854775808 | 9223372036854775807 | 
1. Sizes and limits given for a 64-bit CPU running Linux
2. The C++ constant [`CHAR_BIT`](https://en.cppreference.com/w/cpp/types/numeric_limits) and C++ function[`std::sizeof`](https://en.cppreference.com/w/cpp/types/numeric_limits) were used to compute size in bits, eg. `CHAR_BIT*sizeof(int)`.
3. The C++ function [`std::numeric_limits<type>::min()`](https://en.cppreference.com/w/cpp/types/numeric_limits) was used to compute the minimum.
4. The C++ function [`std::numeric_limits<type>::max()`](https://en.cppreference.com/w/cpp/types/numeric_limits) was used to compute the maximum.


<br>

### Unsigned Integers
C++ also supports several different unsigned integer types.  **The size of each depends on the CPU and compiler**.  For a 64-bit CPU running Linux, they have the following number of bits:
| Type | Size<sup>1,2</sup> | Min<sup>1,3</sup> | Max<sup>1,4</sup> |
| :--- | :---: | :---: | :---: | 
| `bool` | 8 bits | 0 | 1 | 
| `unsigned char` | 8 bits | 0 | 255 | 
| `unsigned short` | 16 bits | 0 | 65535 | 
| `unsigned int` | 32 bits | 0 | 4294967295 | 
| `unsigned long` | 64 bits | 0 | 18446744073709551615 | 
| `unsigned long long` | 64 bits | 0 | 18446744073709551615 | 
| `size_t` | 64 bits | 0 | 18446744073709551615 | 
1. Sizes and limits given for a 64-bit CPU running Linux
2. The C++ constant [`CHAR_BIT`](https://en.cppreference.com/w/cpp/types/numeric_limits) and C++ function[`std::sizeof`](https://en.cppreference.com/w/cpp/types/numeric_limits) were used to compute size in bits, eg. `CHAR_BIT*sizeof(int)`.
3. The C++ function [`std::numeric_limits<type>::min()`](https://en.cppreference.com/w/cpp/types/numeric_limits) was used to compute the minimum.
4. The C++ function [`std::numeric_limits<type>::max()`](https://en.cppreference.com/w/cpp/types/numeric_limits) was used to compute the maximum.

<br>

### Boolean
The boolean type, [`bool`](https://en.cppreference.com/w/c/types/boolean), was introduced in C99.  A `bool` can take only two values, 0 or 1.
Two associated constants are defined: `true` and `false`.


```C++
☀ CHAR_BIT*sizeof(bool) ➜ 8 bits;

☀ false ➜ bool 0;
☀ true ➜ bool 1;
```

<br>

### Indexing Types
The type [`size_t`](https://en.cppreference.com/w/c/types/size_t) is an _unsigned_ integer type
that is the optimal type for array indexing and loop counting. 
It's size depends on implementation.  The 64-bit Ubuntu 20.04 size is shown below:


```C++
☀ CHAR_BIT*sizeof(size_t) ➜ 64 bits;
```


<br>

### Fixed width integer types
C++11 introduced new types, called [fixed interger types](https://en.cppreference.com/w/cpp/types/integer), that allow you to directly specify the number of bits:

| Type | Size<sup>1</sup> | Min<sup>2</sup> | Max<sup>3</sup> |
| :--- | :---: | :---: | :---: | 
| `int8_t` | 8 bits | -128 | 127 | 
| `int16_t` | 16 bits | -32768 | 32767 | 
| `int32_t` | 32 bits | -2147483648 | 2147483647 | 
| `int64_t` | 64 bits | -9223372036854775808 | 9223372036854775807 | 


<br>


| Type | Size<sup>1</sup> | Min<sup>2</sup> | Max<sup>3</sup> |
| :--- | :---: | :---: | :---: | 
| `uint8_t` | 8 bits | 0 | 255 | 
| `uint16_t` | 16 bits | 0 | 65535 | 
| `uint32_t` | 32 bits | 0 | 4294967295 | 
| `uint64_t` | 64 bits | 0 | 18446744073709551615 | 

1. The C++ constant [`CHAR_BIT`](https://en.cppreference.com/w/cpp/types/numeric_limits) and C++ function[`std::sizeof`](https://en.cppreference.com/w/cpp/types/numeric_limits) were used to compute size in bits, eg. `CHAR_BIT*sizeof(uint)`.
2. The C++ function [`std::numeric_limits<type>::min()`](https://en.cppreference.com/w/cpp/types/numeric_limits) was used to compute the minimum.
3. The C++ function [`std::numeric_limits<type>::max()`](https://en.cppreference.com/w/cpp/types/numeric_limits) was used to compute the maximum.

<br>

## Floating Point Numbers
C++ generally supports three types of floating point number.  These types aare the same for all CPUs and operating systems.
The three types are compared below.
| type | name | bits | standard |  `digits10` |  `max_digits10` | `epsilon()` | `min()` | `lowest()` | `max()` | 
| :--- | :---: | :---: | :---:  | :---:  | :---:  | :---:  | :---:  | :---: | :---: |
| float | Single Precision | 32 | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |6 | 9 | 1.19209e-07 | 1.17549e-38 | -3.40282e+38 | 3.40282e+38 | 
| double | Double Precision | 64 | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |15 | 17 | 2.22045e-16 | 2.22507e-308 | -1.79769e+308 | 1.79769e+308 | 
| long double | Quad Precision | 128 | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |18 | 21 | 1.0842e-19 | 3.3621e-4932 | -1.18973e+4932 | 1.18973e+4932 | 

The functions `epsilon()`, `min()`, `lowest()`, and  `max()`, as well as the static values `digits10` and `max_digits10` are found in [`limits`](https://en.cppreference.com/w/cpp/types/numeric_limits)
The static value `max_digits10` was used as the precision for printing the above values.

## Methods
All real number types are primitives not objects and thus do not have methods.
## Operators & Functions

C++ supports many functions and Mathématiques provides several more.  These are listed in detail in the sections on opetators and functions.  C++ supports mixed type arithmetic between all the real types.
Below are a few examples.



```C++
double pi = 3.14159265358979311599796346854;
☀ pi  ➜  double 3.1415926535897931159980;
☀ pi/2+100-0.5*pi ➜ double 100;
☀ 2*sin(pi/4) - 1 ➜ double 0.414214;
☀ 3/pi*asin(0.86602540378) ➜ double 1;
☀ exp(2) ➜ double 7.38906;
☀ log(10) ➜ double 2.30259;
☀ log10(10) ➜ double 1;
☀ pow(2, 10) ➜ double 1024;
☀ pow(2, 2.5-2) ➜ double 1.41421;
```
## Containers of Imaginary numbers

Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>` can have imaginary numbers as their underlying type.
Below are examples of container math with imaginary numbers.  Mixed math is allowed.


```C++
auto v = Vector<double>() = { 0, 1, 2, 3, 4 };
☀ v ➜ Vector<double> {0, 1, 2, 3, 4};
☀ pi*v/4 ➜ TER_Binary Vector<double> {0, 0.785398, 1.5708, 2.35619, 3.14159};
☀ 10*sin(pi*v/4) ➜ TER_Binary Vector<double> {0, 7.07107, 10, 7.07107, 1.22465e-15};
☀ 10*sin(pi*v/4) + 100*v + 1 + v*v ➜ TER_Binary Vector<double> {1, 109.071, 215, 317.071, 417};
```


| ⇦ <br />  | [Scalar Types (Real, Imaginary, Complex & Quaternion)](../README.md)<br />Reals<br /><img width=1000/> | ⇨ <br />[Complex numbers](../complex/README.md)   |
| ------------ | :-------------------------------: | ------------ |

