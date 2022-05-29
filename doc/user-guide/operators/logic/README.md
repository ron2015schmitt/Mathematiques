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
4.2. [Integer Division](../integer-division/README.md)<br>
4.3. _Logic_ <br>
4.4. [Relational](../relational/README.md)<br>


</details>



# 4.3. Logic

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
☀ true ➜ bool 1;
☀ false ➜ bool 0;
☀ !true ➜ bool 0;
☀ !false ➜ bool 1;
☀ true && true ➜ bool 1;
☀ true && false ➜ bool 0;
☀ true || false ➜ bool 1;
```
* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`

```C++
☀ !true ➜ bool 0;
☀ !8 ➜ bool 0;
☀ !!8.293 ➜ bool 1;
☀ true && 3 ➜ bool 1;
☀ true && 0 ➜ bool 0;
```

<br>



| ⇦ <br />[Integer Division](../integer-division/README.md)  | [Operators](../README.md)<br />Logic<br /><img width=1000/> | ⇨ <br />[Relational](../relational/README.md)   |
| ------------ | :-------------------------------: | ------------ |

