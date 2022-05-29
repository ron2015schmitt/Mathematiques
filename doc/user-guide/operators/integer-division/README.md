<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.40.9-c++17</h1>

<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [Usage Guide: Syntax, Data Types, Functions, etc](../../README.md)<br>
1. [Usage Guide Notation](../../notation/README.md)<br>
2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../../scalars/README.md)<br>
3. [Container Types (Vector, Matrix & MultiArray)](../../multiarrays/README.md)<br>
4. _Operators_ <br>
5. [Functions](../../functions/README.md)<br>
6. [Linear Algebra](../../linear-algebra/README.md)<br>
7. [Indexing, Masks, and Sorting](../../indexing-sorting/README.md)<br>
8. [Ranges and Grids](../../ranges-grids/README.md)<br>
9. [Calculus](../../calculus/README.md)<br>
10. [Vector Calculus](../../vector-calculus/README.md)<br>
11. [MultiArray Calculus](../../tensor-calculus/README.md)<br>
12. [Display of Results](../../display/README.md)<br>
13. [FILE I/O](../../file-io/README.md)<br>
14. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Operators</summary>

# [4. Operators](../README.md)<br>
4.1. [Arithmetic](../arithmetic/README.md)<br>
4.2. _Integer Division_ <br>
4.3. [Logic](../logic/README.md)<br>
4.4. [Relational](../relational/README.md)<br>


</details>



# 4.2. Integer Division

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

