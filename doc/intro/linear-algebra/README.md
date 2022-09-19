[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.005</h1>](../../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Why?](../../why/README.md)<br>
Chapter 4. [Objectives](../../objectives/README.md)<br>
Chapter 5. [Versioning](../../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../../development-schedule/README.md)<br>
Chapter 8. _Introduction with Examples_ <br>
Chapter 9. [Installation](../../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 11. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 12. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 13. [Tests](../../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [8. Introduction with Examples](../README.md)<br>
8.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
8.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
8.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
8.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
8.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
8.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
8.7. [Mixed Depth Arithmetic](../arithmetic-mixed-rank/README.md)<br>
8.8. [Nested Arithmetic](../arithmetic-mixed-depth/README.md)<br>
8.9. _Linear Algebra_ <br>
8.10. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
8.11. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
8.12. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
8.13. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
8.14. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
8.15. [Tensors](../tensors/README.md)<br>
8.16. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.9. Linear Algebra



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



| ⇦ <br />[Nested Arithmetic](../arithmetic-mixed-depth/README.md)  | [Introduction with Examples](../README.md)<br />Linear Algebra<br /><img width=1000/> | ⇨ <br />[Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)   |
| ------------ | :-------------------------------: | ------------ |

