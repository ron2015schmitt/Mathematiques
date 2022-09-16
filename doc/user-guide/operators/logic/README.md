[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.162-c++20</h1>](../../../../README.md)

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
9.4.3. _Logic_ <br>
9.4.4. [Relational](../relational/README.md)<br>


</details>



# 9.4.3. Logic

_This document was generated from the C++ file_ `logic/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 


<br>

## Logic Operators
For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).


| operator | operation | 
| :---: | :---: | 
| `!` | logical NOT | 
| `\|\|` | logical OR | 
| `&&` | logical AND | 

**CAVEAT**: C++ also has binary bit-wise operators `&` and `|`.  Mistyping the above operators can cause painful bugs. 


Examples:

```C++
☀ true ➜ bool true;
☀ false ➜ bool false;
☀ !true ➜ bool false;
☀ !false ➜ bool true;
☀ true && true ➜ bool true;
☀ true && false ➜ bool false;
☀ true || false ➜ bool true;
```
* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`

```C++
☀ !true ➜ bool false;
☀ !8 ➜ bool false;
☀ !!8.293 ➜ bool true;
☀ true && 3 ➜ bool true;
☀ true && 0 ➜ bool false;
```

<br>



| ⇦ <br />[Integer Division](../integer-division/README.md)  | [Operators](../README.md)<br />Logic<br /><img width=1000/> | ⇨ <br />[Relational](../relational/README.md)   |
| ------------ | :-------------------------------: | ------------ |

