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
7.2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../../scalars/README.md)<br>
7.3. [Container Types (Vector, Matrix & Tensor)](../../containers/README.md)<br>
7.4. _Operators_ <br>
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

<summary>Operators</summary>

# [7.4. Operators](../README.md)<br>

7.4.1. _Arithmetic_ <br>
7.4.2. [Integer Division](../integer-division/README.md)<br>
7.4.3. [Logic](../logic/README.md)<br>
7.4.4. [Relational](../relational/README.md)<br>


</details>



# 7.4.1. Arithmetic

_This document was generated from the C++ file_ `arithmetic/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 

## Arithmetic Operators
The operators `+, -, *, /` are the addition, subtraction, multiplication, and division operators respectively.

For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).


| operator | operation | types | 
| :---: | :---: | :---: | 
| `+` | addition | 𝕤, 𝕌 | 
| `-` | subtraction | 𝕤, 𝕌 | 
| `*` | multiplication | 𝕤, 𝕌 | 
| `/` | division | 𝕤, 𝕌 | 

For container types, the following rules apply for `x op y`:

* For two (zero-depth) containers of the same `rank` and `dimensions`, `x op y` yields the element-wise operation a container of the same `rank` and `dimensions

* All other cases are invalid and will produce unpredictable results or a run-time error. Debug modes will send useful error messages to the stderr.


<br>

## Exponentiation and the `pow` function
C++ does not have an exponentiation operator.  Instead it provides the [`std::pow`](https://en.cppreference.com/w/cpp/numeric/math/div) function
```C++
☀ pow(2, 8) ➜ double 256;
☀ pow(25, 1 / 2) ➜ double 1;
```

<br>

## Examples using addition
#### Reals

```C++
☀ 1 + 2 ➜ int 3;
☀ 7.5 + 2 ➜ double 9.5;
☀ 7.5 - 0.5 ➜ double 7;
```

#### Complex, Imaginary and Mixed

```C++
☀ complex<double>(1.5, 0) + complex<double>(0.5, 4) ➜ std::complex<double> (2,4);
```

#### Imaginary

```C++
☀ complex<double>(1.5, 0) + complex<double>(0.5, 4) ➜ std::complex<double> (2,4);
☀ Imaginary<double>(1) + Imaginary<double>(33.12) ➜ Imaginary<double> 34.12i;
☀ -10 + Imaginary<double>(5.25) ➜ std::complex<double> (-10,5.25);
☀ 100 + complex<double>(1.5, 2) + Imaginary<double>(5.25) ➜ std::complex<double> (101.5,7.25);
```

```C++
☀ complex(1.0, 1.0) + complex(2.0, 4.0) ➜ (3,5);
☀ complex(1.0, 1.0) - complex(2.0, 4.0) ➜ (-1,-3);
☀ complex(1.0, 1.0) * complex(2.0, 4.0) ➜ (-2,6);
☀ complex(1.0, 1.0) / complex(2.0, 4.0) ➜ (0.3,-0.1);
```

<br>

### Exponentiation and the ```pow``` function
C++ does not have an exponentiation operator.  Instead it provides the [```std::pow```](https://en.cppreference.com/w/cpp/numeric/complex/div) function
```C++
☀ pow(complex(1.0, 1.0), complex(2.0, 4.0)) ➜ (-0.084961,0.0158558);
```

<br>

### Relational Operators
Complex numbers are not an ordered set.  Therefore, there is no concept of greater than or less than.

For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).


| operator | operation | 
| :---: | :---: | 
| `==` | equal to | 
| `!=` | not equal to | 

Examples:

```C++

☀ complex(1.0, 1.0) == complex(1.0, 1.0) ➜ 1;
☀ complex(1.0, 1.0) != complex(1.0, 1.0) ➜ 0;

☀ complex(1.0, 1.0) == complex(2.0, 4.0) ➜ 0;
☀ complex(1.0, 1.0) != complex(2.0, 4.0) ➜ 1;
```
#### Mixed Type

```C++
☀ complex<double>(1.5, 0) + complex<double>(0.5, 4) ➜ std::complex<double> (2,4);
☀ Imaginary<double>(1) + Imaginary<double>(33.12) ➜ Imaginary<double> 34.12i;
☀ -10 + Imaginary<double>(5.25) ➜ std::complex<double> (-10,5.25);
☀ 100 + complex<double>(1.5, 2) + Imaginary<double>(5.25) ➜ std::complex<double> (101.5,7.25);
```

#### Containers

```C++
```

#### Nested Containers

```C++
```

#### Mixed Rank Math

```C++
```

#### Mixed Depth Math

```C++
```



| ⇦ <br />  | [Operators](../README.md)<br />Arithmetic<br /><img width=1000/> | ⇨ <br />[Integer Division](../integer-division/README.md)   |
| ------------ | :-------------------------------: | ------------ |

