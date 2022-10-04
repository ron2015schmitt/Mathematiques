[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.033</h1>](../../../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../../../README.md)<br>
Chapter 1. [License](../../../license/README.md)<br>
Chapter 2. [About](../../../about/README.md)<br>
Chapter 3. [Why?](../../../why/README.md)<br>
Chapter 4. [Objectives](../../../objectives/README.md)<br>
Chapter 5. [Versioning](../../../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../../../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../../../development-schedule/README.md)<br>
Chapter 8. [Introduction with Examples](../../../intro/README.md)<br>
Chapter 9. [Installation](../../../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../../../first-project/README.md)<br>
Chapter 11. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
Chapter 12. [Benchmarks](../../../benchmarks/README.md)<br>
Chapter 13. [Tests](../../../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [11. Usage Guide: Syntax, Data Types, Functions, etc](../../README.md)<br>
11.1. [Usage Guide Notation](../../notation/README.md)<br>
11.2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../../numbers/README.md)<br>
11.3. [Container Types (Vector, Matrix & MultiArray)](../../multiarrays/README.md)<br>
11.4. _Operators_ <br>
11.5. [Functions](../../functions/README.md)<br>
11.6. [Linear Algebra](../../linear-algebra/README.md)<br>
11.7. [Indexing, Masks, and Sorting](../../indexing-sorting/README.md)<br>
11.8. [Ranges and Grids](../../ranges-grids/README.md)<br>
11.9. [Calculus](../../calculus/README.md)<br>
11.10. [Vector Calculus](../../vector-calculus/README.md)<br>
11.11. [MultiArray Calculus](../../tensor-calculus/README.md)<br>
11.12. [Display of Results](../../display/README.md)<br>
11.13. [FILE I/O](../../file-io/README.md)<br>
11.14. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Operators</summary>

# [11.4. Operators](../README.md)<br>
11.4.1. [Arithmetic](../arithmetic/README.md)<br>
11.4.2. [Integer Division](../integer-division/README.md)<br>
11.4.3. [Logic](../logic/README.md)<br>
11.4.4. _Relational_ <br>


</details>



# 11.4.4. Relational

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

