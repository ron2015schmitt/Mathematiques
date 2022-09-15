[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.152-c++20</h1>](../../../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../../../README.md)<br>
Chapter 1. [License](../../../license/README.md)<br>
Chapter 2. [About](../../../about/README.md)<br>
Chapter 3. [Objectives](../../../objectives/README.md)<br>
Chapter 4. [Status & Release Notes](../../../status-release/README.md)<br>
Chapter 5. [Upcoming Development](../../../development-schedule/README.md)<br>
Chapter 6. [Introduction with Examples](../../../intro/README.md)<br>
Chapter 7. [Installation](../../../installation/README.md)<br>
Chapter 8. [Your First Mathématiques Project](../../../first-project/README.md)<br>
Chapter 9. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
Chapter 10. [Benchmarks](../../../benchmarks/README.md)<br>
Chapter 11. [Tests](../../../test/README.md)<br>
Chapter 12. [Developer Guide: Modifying and Extending Mathématiques](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [9. Usage Guide: Syntax, Data Types, Functions, etc](../../README.md)<br>
9.1. [Usage Guide Notation](../../notation/README.md)<br>
9.2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../../numbers/README.md)<br>
9.3. [Container Types (Vector, Matrix & MultiArray)](../../multiarrays/README.md)<br>
9.4. _Operators_ <br>
9.5. [Functions](../../functions/README.md)<br>
9.6. [Linear Algebra](../../linear-algebra/README.md)<br>
9.7. [Indexing, Masks, and Sorting](../../indexing-sorting/README.md)<br>
9.8. [Ranges and Grids](../../ranges-grids/README.md)<br>
9.9. [Calculus](../../calculus/README.md)<br>
9.10. [Vector Calculus](../../vector-calculus/README.md)<br>
9.11. [MultiArray Calculus](../../tensor-calculus/README.md)<br>
9.12. [Display of Results](../../display/README.md)<br>
9.13. [FILE I/O](../../file-io/README.md)<br>
9.14. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Operators</summary>

# [9.4. Operators](../README.md)<br>
9.4.1. [Arithmetic](../arithmetic/README.md)<br>
9.4.2. [Integer Division](../integer-division/README.md)<br>
9.4.3. [Logic](../logic/README.md)<br>
9.4.4. _Relational_ <br>


</details>



# 9.4.4. Relational

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
☀ (2 == 2) ➜ bool true;
☀ (1 / 2 == 0.5) ➜ bool false;
☀ (1. / 2 == 0.5) ➜ bool true;
☀ (-2 < 34.2) ➜ bool true;
☀ (2 > 0) ➜ bool true;
```


| ⇦ <br />[Logic](../logic/README.md)  | [Operators](../README.md)<br />Relational<br /><img width=1000/> | ⇨ <br />   |
| ------------ | :-------------------------------: | ------------ |

