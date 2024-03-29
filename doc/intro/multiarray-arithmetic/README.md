<h1 style='border: 2px solid; text-align: center'><a href='../../../README.md'>Mathématiques 0.42.6</a></h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Versioning](../versioning/README.md)<br>
Chapter 4. [Status & Release Notes](../status-release/README.md)<br>
Chapter 5. [Upcoming Development](../development-schedule/README.md)<br>
Chapter 6. _Introduction with Examples_ <br>
Chapter 7. [Installation](../installation/README.md)<br>
Chapter 8. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 9. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 10. [Benchmarks](../benchmarks/README.md)<br>
Chapter 11. [Tests](../test/README.md)<br>
Chapter 12. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [6. Introduction with Examples](../README.md)<br>
6.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
6.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
6.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
6.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
6.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
6.6. _MultiArray Arithmetic and Operators_ <br>
6.7. [Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)<br>
6.8. [Linear Algebra](../linear-algebra/README.md)<br>
6.9. [Indexing, Masks, Slicing, Sorting, etc.](../sort-mask-slice/README.md)<br>
6.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
6.11. [Numerical / Discretized Mathematical Function Objects](../numerical-functions/README.md)<br>
6.12. [Functions of Complex Variables](../complex-calculus/README.md)<br>
6.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
6.14. [Tensors](../tensors/README.md)<br>
6.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.6. MultiArray Arithmetic and Operators



Mathématiques supports arithmetic, relational, and logic operators for MultiArrays.
All operators perform operations in an element-wise manner.
The section demonstrates operators on two containers of the same `rank`, `dimensions`, and `depth`.

## Arithmetic Operators
The operators `+, -, *, /` are the addition, subtraction, multiplication, and division operators respectively.


| operator | operation |
| :---: | :---: | 
| `+` | addition | 
| `-` | subtraction | 
| `*` | multiplication | 
| `/` | division | 


Examples:

```C++
☀ (Vector<double>{1, 2, 3} + Vector<double>{1, -2, 10}) ➜ Vector<double> {2, 0, 13};

☀ (Matrix<double>{ {11, 22}, { 33, 44 }} - Matrix<double>{ {1, 2}, { 3, 4 }}) ➜ Matrix<double> 
{
  {10, 20},
  {30, 40}
};

☀ (MultiArray<double, 3>{ { {1, 2}, { 3, 4 }}, { {5, 6}, { 7, 8 } }} *MultiArray<double, 3>{ { {10, 10}, { 100, 100 }}, { {1000, 1000}, { 10000, 10000 } }}) ➜ MultiArray<double, rank=3> 
{
  {
    {10, 20},
    {300, 400}
  },
  {
    {5000, 6000},
    {70000, 80000}
  }
};

☀ (Vector<double>{24, 24, 24} / Vector<double>{2, 3, 4}) ➜ Vector<double> {12, 8, 6};

```
Operators also work on nested multiarrays, ie multiarrays with depth greater then 1.

Examples:

```C++
Vector<Matrix<double>> v{ {{1, 2}, {3, 4}}, {{11, 12}, {13, 14}} };

☀ (v*v + 10*v)/(2*v-v) ➜ Vector<Matrix<double>> {
{
  {11, 12},
  {13, 14}
}, 
{
  {21, 22},
  {23, 24}
}};

```

<br>

## Relational Operators

| operator | operation | 
| :---: | :---: | 
| `==` | equal to | 
| `!=` | not equal to | 
| `<` | less than | 
| `<=` | less than or equal to | 
| `>` | greater than | 
| `>=` | greater than or equal to | 


Examples:

```C++
☀ (Vector<double>{1, 2, 3} == Vector<double>{1, -1, 3}) ➜ Vector<bool> {true, false, true};
☀ (Vector<double>{1, 2, 3} < Vector<double>{1, 10, 0}) ➜ Vector<bool> {false, true, false};
```

<br>

## Logic Operators

| operator | operation | 
| :---: | :---: | 
| `!` | logical NOT | 
| `\|\|` | logical OR | 
| `&&` | logical AND | 


Examples:

```C++
Vector<double> v1{ 1, 2, 3 };
Vector<double> v2{ 11, 22, 33 };
☀ !(v1 < v2) ➜ Vector<bool> {false, false, false};

Vector<double> v{ 5, 7, 1 };
☀ (v1 < v) && (v < v2) ➜ Vector<bool> {true, true, false};
```

<br>

## Logical MutliArray functions: `alltrue`, `anytrue`, `numtrue`, and `findtrue`

* The function `alltrue(v)` returns a `bool`: true if every element of `v` is true, otherwise it returns false

* The function `anytrue(v)` returns a `bool`: true if any element of `v` is true, otherwise it returns false

* The function `numtrue(v)` returns a `size_t` equal to the number of elements of `v` that are true. 

* The function `findtrue(v)` returns a `Vector<size_t>` which contains the indices of the true elements of `v`. 


The functions `alltrue`, `anytrue`, `numtrue`, and `findtrue`
```C++
Vector<double> v{ 0,1,2,3 };

☀ v ➜ Vector<double> {0, 1, 2, 3};
☀ (v > 2) ➜ Vector<bool> {false, false, false, true};
☀ alltrue(v > 2) ➜ bool false;
☀ alltrue(v > 0) ➜ bool false;
☀ anytrue(v > 2) ➜ bool true;
☀ numtrue(v > 2) ➜ unsigned long 1;
☀ numtrue(v > 0) ➜ unsigned long 3;
☀ findtrue(v > 2) ➜ Vector<unsigned long> {3};
☀ findtrue(v > 0) ➜ Vector<unsigned long> {1, 2, 3};
```


<br>



| ⇦ <br />[Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)  | [Introduction with Examples](../README.md)<br />MultiArray Arithmetic and Operators<br /><img width=1000/> | ⇨ <br />[Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)   |
| ------------ | :-------------------------------: | ------------ |

