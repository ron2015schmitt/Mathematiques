<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.40.10-c++17</h1>

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
4.2. [Integer Division](../integer-division/README.md)<br>
4.3. [Logic](../logic/README.md)<br>
4.4. _Relational_ <br>


</details>



# 4.4. Relational

_This document was generated from the C++ file_ `relational/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 


<br>

## Relational Operators
For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).


| operator | operation | 
| :---: | :---: | 
| `==` | equal to | 
| `!=` | not equal to | 
| `<` | less than | 
| `<=` | less than or equal to | 
| `>` | greater than | 
| `>=` | greater than or equal to | 

**CAVEAT**: C++ allows assigment `=` inside `if` statements (eg, `if (a = true) return;`).  Mistyping the equals operator `==` can cause painful bugs. 


Examples:

```C++
☀ (2 == 2) ➜ bool 1;
☀ (1 / 2 == 0.5) ➜ bool 0;
☀ (1. / 2 == 0.5) ➜ bool 1;
☀ (-2 < 34.2) ➜ bool 1;
☀ (2 > 0) ➜ bool 1;
```


| ⇦ <br />[Logic](../logic/README.md)  | [Operators](../README.md)<br />Relational<br /><img width=1000/> | ⇨ <br />   |
| ------------ | :-------------------------------: | ------------ |

