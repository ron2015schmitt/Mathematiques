<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.122-c++20</h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
1. [License](../../license/README.md)<br>
2. [About](../../about/README.md)<br>
3. [Status, Planned Work & Release Notes](../../status-release/README.md)<br>
11. _Introduction with Examples_ <br>
5. [Installation](../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../first-project/README.md)<br>
12. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
8. [Benchmarks](../../benchmarks/README.md)<br>
9. [Tests](../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>
11. _Introduction with Examples_ <br>
12. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [11. Introduction with Examples](../README.md)<br>
11.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
11.2. [Number Systems](../numbers/README.md)<br>
11.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
11.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
11.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
11.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
11.7. [Linear Algebra](../linear-algebra/README.md)<br>
11.8. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
11.9. [Mathematical functions](../math-functions/README.md)<br>
11.10. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
11.11. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
11.12. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
11.13. _Tensors_ <br>
11.14. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 11.13. Tensors



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



| ⇦ <br />[Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)  | [Introduction with Examples](../README.md)<br />Tensors<br /><img width=1000/> | ⇨ <br />[Series and transforms](../series-transforms/README.md)   |
| ------------ | :-------------------------------: | ------------ |

