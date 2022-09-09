<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.123-c++20</h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../../README.md)<br>
1. [License](../../../license/README.md)<br>
2. [About](../../../about/README.md)<br>
3. [Status, Planned Work & Release Notes](../../../status-release/README.md)<br>
11. [Introduction with Examples](../../../intro/README.md)<br>
5. [Installation](../../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../../first-project/README.md)<br>
12. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
8. [Benchmarks](../../../benchmarks/README.md)<br>
9. [Tests](../../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../../developer-guide/README.md)<br>
11. [Introduction with Examples](../../../intro/README.md)<br>
12. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [12. Usage Guide: Syntax, Data Types, Functions, etc](../../README.md)<br>
12.1. [Usage Guide Notation](../../notation/README.md)<br>
12.16. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../../numbers/README.md)<br>
12.15. [Container Types (Vector, Matrix & MultiArray)](../../multiarrays/README.md)<br>
12.17. _Operators_ <br>
12.5. [Functions](../../functions/README.md)<br>
12.6. [Linear Algebra](../../linear-algebra/README.md)<br>
12.7. [Indexing, Masks, and Sorting](../../indexing-sorting/README.md)<br>
12.8. [Ranges and Grids](../../ranges-grids/README.md)<br>
12.9. [Calculus](../../calculus/README.md)<br>
12.10. [Vector Calculus](../../vector-calculus/README.md)<br>
12.11. [MultiArray Calculus](../../tensor-calculus/README.md)<br>
12.12. [Display of Results](../../display/README.md)<br>
12.13. [FILE I/O](../../file-io/README.md)<br>
12.14. [Debug Modes](../../debug/README.md)<br>
12.15. [Container Types (Vector, Matrix & MultiArray)](../../multiarrays/README.md)<br>
12.16. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../../numbers/README.md)<br>
12.17. _Operators_ <br>


</details>



<details>

<summary>Operators</summary>

# [12.17. Operators](../README.md)<br>
12.17.1. [Arithmetic](../arithmetic/README.md)<br>
12.17.2. _Integer Division_ <br>
12.17.3. [Logic](../logic/README.md)<br>
12.17.4. [Relational](../relational/README.md)<br>


</details>



# 12.17.2. Integer Division

_This document was generated from the C++ file_ `integer-division/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 

C++ also provides support for integer division witjh remainder.

If both numerator and denominator are integers, the division operator gives the integer division result.

For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).


| operator | operation | types | 
| :---: | :---: | :---: | 
| `/` | integer division | 𝕤, 𝕌 | 
| `%` | modulus | ℤ | 


<br>

### Examples: integer division
```C++
☀ 7 / 2 ➜ int 3;
```
* The modulus operator `a % b`, gives the remainder after integer divison of `a` by `b`.

```C++
☀ 7 % 2 ➜ int 1;
```
* The function [`std::div`](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.

```C++
div_t result = div(7, 2);
```
With result:

```C++
☀ result.quot ➜ int 3;
☀ result.rem ➜ int 1;
```


| ⇦ <br />[Arithmetic](../arithmetic/README.md)  | [Operators](../README.md)<br />Integer Division<br /><img width=1000/> | ⇨ <br />[Logic](../logic/README.md)   |
| ------------ | :-------------------------------: | ------------ |

