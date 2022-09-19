[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.006</h1>](../../../README.md)

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
Chapter 8. [Introduction with Examples](../../intro/README.md)<br>
Chapter 9. [Installation](../../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 11. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
Chapter 12. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 13. [Tests](../../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [11. Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br>

11.1. _Usage Guide Notation_ <br>
11.2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../numbers/README.md)<br>
11.3. [Container Types (Vector, Matrix & MultiArray)](../multiarrays/README.md)<br>
11.4. [Operators](../operators/README.md)<br>
11.5. [Functions](../functions/README.md)<br>
11.6. [Linear Algebra](../linear-algebra/README.md)<br>
11.7. [Indexing, Masks, and Sorting](../indexing-sorting/README.md)<br>
11.8. [Ranges and Grids](../ranges-grids/README.md)<br>
11.9. [Calculus](../calculus/README.md)<br>
11.10. [Vector Calculus](../vector-calculus/README.md)<br>
11.11. [MultiArray Calculus](../tensor-calculus/README.md)<br>
11.12. [Display of Results](../display/README.md)<br>
11.13. [FILE I/O](../file-io/README.md)<br>
11.14. [Debug Modes](../debug/README.md)<br>


</details>



# 11.1. Usage Guide Notation

_This document was generated from the C++ file_ `notation/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 
<br>

## Code and results
In this documentation, code is shown inline as `int x` and in code blocks:


```C++
double pi = 3.14;
double r = 2.5;
double area = pi * pow(r, 2);
```
Results are also shown in code blocks but with each line preceded by the symbol `☀ `


```C++
☀ pi ➜ double 3.14;
☀ r ➜ double 2.5;
☀ area ➜ double 19.625;
```
This is also how the results are output in a linux terminal, albeit with slightly different coloring.  A screen shot of the same results are shown below

![linux-terminal-example-output](linux-terminal-example-output.png)


The code used to display these results is:



```C++
ETV(pi);
ETV(r);
ETV(area);
```
This topic is covered in detail in the Display section of this guide.

Often we will display code and results together, with the symbol `☀ ` distinguishing results from code:

```C++
double x = 1.52;
☀ x ➜ double 1.52;
```
## Numbers and containers
The following notation shorthand is used in the User Guide (but certainly not in C++ code!).

### Scalars

| symbol | C++ types |
| :---: | :---: | 
| ℤ | any C++ real signed integral type: `bool`, `int`, `long`, etc | 
| ℕ | any C++ real unsigned integral type: `unsigned int`, `unsigned long`, etc | 
| ℝ | any C++ real floating-point type: `float`, `double`, `long double`) | 
| ℂ | any `std::complex<ℝ>` | 
| 𝕁 | any `Imaginary<ℝ>` | 
| ℍ | any `Quaternion<ℝ>` | 
| 𝕂 | any ℝ, ℂ, 𝕁, ℍ | 
| 𝕤 | any ℤ, 𝕂 | 

Lower case 𝕤 was chosen because 𝕊 is commonly used in mathematics for the spherical groups


<br>

### Containers

| symbol | C++ types |
| :---: | :---: | 
| 𝕍 | any `Vector<T>` for any scalar or container type or type symbol T | 
| 𝕄 | any `Matrix<T>` for any scalar or container type or type symbol T | 
| 𝕥 | any `MultiArray<T>` for any scalar or container type or type symbol T | 
| 𝕌 | any 𝕍, 𝕄, 𝕥 | 

Lower case 𝕥 was chosen because 𝕋 is commonly used in mathematics for the torus groups



<br>



| ⇦ <br />  | [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br />Usage Guide Notation<br /><img width=1000/> | ⇨ <br />[Scalar Types (Real, Imaginary, Complex & Quaternion)](../numbers/README.md)   |
| ------------ | :-------------------------------: | ------------ |

