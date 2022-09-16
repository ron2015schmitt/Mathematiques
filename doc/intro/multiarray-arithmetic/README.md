[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.163-c++20</h1>](../../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Objectives](../../objectives/README.md)<br>
Chapter 4. [Status & Release Notes](../../status-release/README.md)<br>
Chapter 5. [Upcoming Development](../../development-schedule/README.md)<br>
Chapter 6. _Introduction with Examples_ <br>
Chapter 7. [Installation](../../installation/README.md)<br>
Chapter 8. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 9. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 10. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 11. [Tests](../../test/README.md)<br>
Chapter 12. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [6. Introduction with Examples](../README.md)<br>
6.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
6.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
6.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
6.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
6.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
6.6. _MultiArray Arithmetic_ <br>
6.7. [Linear Algebra](../linear-algebra/README.md)<br>
6.8. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
6.9. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
6.10. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
6.11. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
6.12. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
6.13. [Tensors](../tensors/README.md)<br>
6.14. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.6. MultiArray Arithmetic



Mathématiques supports arithmetic, relational, and logic operators for MultiArrays
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

<br>

## Logic Operators
For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).


| operator | operation | 
| :---: | :---: | 
| `!` | logical NOT | 
| `\|\|` | logical OR | 
| `&&` | logical AND | 

**CAVEAT**: C++ also has binary bit-wise operators `&` and `|`.  Mistyping the above operators can cause painful bugs. 

#### Containers

```C++
```

#### Nested Containers

```C++
```

#### Mixed Rank Math

```C++
```

#### Mixed depth Math

```C++
```


<br>



| ⇦ <br />[Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)  | [Introduction with Examples](../README.md)<br />MultiArray Arithmetic<br /><img width=1000/> | ⇨ <br />[Linear Algebra](../linear-algebra/README.md)   |
| ------------ | :-------------------------------: | ------------ |

