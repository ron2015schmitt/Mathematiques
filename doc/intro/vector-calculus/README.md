[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.155-c++20</h1>](../../../README.md)

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
6.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
6.7. [Linear Algebra](../linear-algebra/README.md)<br>
6.8. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
6.9. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
6.10. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
6.11. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
6.12. _Vector Calculus and Curvilinear Coordinates_ <br>
6.13. [Tensors](../tensors/README.md)<br>
6.14. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.12. Vector Calculus and Curvilinear Coordinates



## Pretty Printing
Mathématiques supports the follow number systems:
```C++
bool q = (5 > 3);
☀ q ➜ bool true;
☀ !q ➜ bool false;

☀ true || false ➜ bool true;
☀ true && false ➜ bool false;

☀ true + 9 ➜ int 10;
```

<br>

## Debugging Modes
Mathématiques supports mixed math and automatically promotes numbers as needed
```C++
unsigned int n = 23;
☀ n ➜ unsigned int 23;
☀ n + 102 - 2*4 ➜ unsigned int 117;
☀ n - 24 ➜ unsigned int 4294967295;
☀ n/2 ➜ unsigned int 11;
☀ n % 2 ➜ unsigned int 1;
```

<br>



| ⇦ <br />[Calculus on Complex Number Domains](../complex-calculus/README.md)  | [Introduction with Examples](../README.md)<br />Vector Calculus and Curvilinear Coordinates<br /><img width=1000/> | ⇨ <br />[Tensors](../tensors/README.md)   |
| ------------ | :-------------------------------: | ------------ |

