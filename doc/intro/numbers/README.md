[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.131-c++20</h1>](../../../README.md)

<details>

<summary>Documentation</summary>

# [Chapter  Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Status, Planned Work & Release Notes](../../status-release/README.md)<br>
Chapter 4. _Introduction with Examples_ <br>
Chapter 5. [Installation](../../installation/README.md)<br>
Chapter 6. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 7. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 8. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 9. [Tests](../../test/README.md)<br>
Chapter 10. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [4. Introduction with Examples](../README.md)<br>
4.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
4.2. _Number Systems_ <br>
4.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
4.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
4.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
4.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
4.7. [Linear Algebra](../linear-algebra/README.md)<br>
4.8. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
4.9. [Mathematical functions](../math-functions/README.md)<br>
4.10. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
4.11. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
4.12. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
4.13. [Tensors](../tensors/README.md)<br>
4.14. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 4.2. Number Systems



## Number Systems Currently Supported
Mathématiques supports the follow number systems:
* Boolean numbers
* signed and unsigned integers
* real numbers, as approximated by floating point values
* pure imaginary numbers, which saves memory for imaginary matrices
* complex numbers
* quaternions
## Examples
Mathématiques supports mixed math and automatically promotes numbers as needed
### Boolean
```C++
bool q = (5 > 3);
☀ q ➜ bool true;
☀ !q ➜ bool false;

☀ true || false ➜ bool true;
☀ true && false ➜ bool false;

☀ true + 9 ➜ int 10;
```

<br>

### Unsigned integers
```C++
unsigned int n = 23;
☀ n ➜ unsigned int 23;
☀ n + 102 - 2*4 ➜ unsigned int 117;
☀ n - 24 ➜ unsigned int 4294967295;
☀ n/2 ➜ unsigned int 11;
☀ n % 2 ➜ unsigned int 1;
```

<br>

### Signed integers
```C++
int n = 23;
☀ n ➜ int 23;
☀ n + 102 - 2*4 ➜ int 117;
☀ n - 24 ➜ int -1;
☀ n/2 ➜ int 11;

☀ 2 + 4/2 ➜ int 4;
☀ 2 + 0.5 ➜ double 2.5;
```

<br>

### Floating point (reals)
```C++
double x = 23;
☀ x ➜ double 23;
☀ 4.5*x + 35/(2+3) ➜ double 110.5;

☀ 25. ➜ double 25;
☀ 2. + 4/2 ➜ double 4;
```

<br>

### Imaginary
```C++
Imaginary<double> y{ 4 };
☀ y ➜ Imaginary<double> 4i;

double x{ 3 };
☀ x ➜ double 3;
☀ x + y ➜ std::complex<double> (3,4);

using namespace mathq::unit_imaginary;
☀ 3 + 4*i ➜ std::complex<double> (3,4);
```

<br>

### Complex
```C++
using std::complex;
complex<double> z(10, -20);
☀ z ➜ std::complex<double> (10,-20);
☀ abs(z) ➜ double 22.3607;

☀ z/complex(1, 2) ➜ std::complex<double> (-6,-8);

using namespace mathq::unit_imaginary;
☀ z/(1 + i*2) ➜ std::complex<double> (-6,-8);
```

<br>

### Quaternion
```C++
auto q1 = Quaternion<double>(1, 2, -1, -3);
auto q2 = Quaternion<double>(4, 3, -2, -5);
☀ q1 ➜ Quaternion<double> 1 + 2*i + -j + -3*k;
☀ q2 ➜ Quaternion<double> 4 + 3*i + -2*j + -5*k;
☀ q1+q2 ➜ Quaternion<double> 5 + 5*i + -3*j + -8*k;
☀ q1-q2 ➜ Quaternion<double> -3 + -i + j + 2*k;
☀ q1*q2 ➜ Quaternion<double> -19 + 10*i + -5*j + -18*k;
☀ q2/q1 ➜ Quaternion<double> 1.8 + -0.4*i + 0.2*j + 0.4*k;

using namespace mathq::unit_imaginary;
using namespace mathq::unit_quaternion;
auto q = Quaternion<double>() = 16 + 2*i + 3*j + 13*k;
auto p = Quaternion<double>() = 0.53767 + 0.86217*i - 0.43359*j + 2.7694*k;
☀ q ➜ Quaternion<double> 16 + 2*i + 3*j + 13*k;
☀ p ➜ Quaternion<double> 0.53767 + 0.86217*i + -0.43359*j + 2.7694*k;

double x{ 3 };
☀ x ➜ double 3;
Imaginary<double> y{ 4 };
☀ y ➜ Imaginary<double> 4i;
std::complex<double> z(1, 2);
☀ x + y + z + 5*j ➜ Quaternion<double> 4 + 6*i + 5*j;
```

<br>



| ⇦ <br />[Pretty Printing and Debugging](../print-debug/README.md)  | [Introduction with Examples](../README.md)<br />Number Systems<br /><img width=1000/> | ⇨ <br />[Vectors, Matrices, and MultiArrays](../multiarrays/README.md)   |
| ------------ | :-------------------------------: | ------------ |

