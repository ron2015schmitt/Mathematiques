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
6.6. [MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)<br>
6.7. _Mixed-Rank & Mixed-Depth Arithmetic_ <br>
6.8. [Linear Algebra](../linear-algebra/README.md)<br>
6.9. [Indexing, Masks, Slicing, Sorting, etc.](../sort-mask-slice/README.md)<br>
6.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
6.11. [Numerical / Discretized Mathematical Function Objects](../numerical-functions/README.md)<br>
6.12. [Functions of Complex Variables](../complex-calculus/README.md)<br>
6.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
6.14. [Tensors](../tensors/README.md)<br>
6.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.7. Mixed-Rank & Mixed-Depth Arithmetic



Mathématiques also supports operators between objects (multi-arrays and numbers) of different rank and depth, when such operations make sense.

<br>

## Rank, Depth, and Dimensions
Notice that Number types (eg `bool`, `int`, `double`, `std::complex`, etc) have both zero rank and zero depth, whereas the `Scalar` multiarray has rank zero but depth one. `Scalar` multiarrays are needed to serve as the base class for scalar NumericalFunctions. 
### Function `rank`

Examples:

```C++
☀ mathq::rank(2) ➜ unsigned long 0;

☀ mathq::rank(Scalar<double>{42}) ➜ unsigned long 0;
☀ mathq::rank(Vector<double>{1, 2}) ➜ unsigned long 1;
☀ mathq::rank(Matrix<double>{ {1, 2}, { 3,4 }}) ➜ unsigned long 2;
☀ mathq::rank(MultiArray<double, 3>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }) ➜ unsigned long 3;

☀ mathq::rank(Vector<Matrix<double>>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }) ➜ unsigned long 1;
```

<br>

### Function `depth`

Examples:

```C++
☀ mathq::depth(2) ➜ unsigned long 0;

☀ mathq::depth(Scalar<double>{42}) ➜ unsigned long 1;
☀ mathq::depth(Vector<double>{1, 2}) ➜ unsigned long 1;
☀ mathq::depth(Matrix<double>{ {1, 2}, { 3,4 }}) ➜ unsigned long 1;
☀ mathq::depth(MultiArray<double, 3>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }) ➜ unsigned long 1;

☀ mathq::depth(Vector<Matrix<double>>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }) ➜ unsigned long 2;
```

<br>

### Function `dimensions`

Examples:

```C++
☀ mathq::dimensions(2) ➜ RecursiveDimensions {};

☀ mathq::dimensions(Scalar<double>{42}) ➜ RecursiveDimensions {{}};
☀ mathq::dimensions(Vector<double>{1, 2}) ➜ RecursiveDimensions {2};
☀ mathq::dimensions(Matrix<double>{ {1, 2}, { 3,4 }}) ➜ RecursiveDimensions {2⨯2};
☀ mathq::dimensions(MultiArray<double, 3>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }) ➜ RecursiveDimensions {2⨯2⨯2};

☀ mathq::dimensions(Vector<Matrix<double>>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } }) ➜ RecursiveDimensions {2, 2⨯2};
```

<br>

## Number/`Scalar` `op` `MultiArray`
As in matlab, a MultiArray can be paired with a Number or `Scalar` with any operator.

Examples:

```C++
☀ Vector<double>{1, 2}+10 ➜ Vector<double> {11, 12};

☀ 2*Scalar<double>{42} ➜ Scalar<double> 84;
☀ Vector<double>{1, 2} == 1 ➜ Vector<bool> {true, false};
☀ Matrix<double>{ {1, 2}, { 3,4 }} - 1 ➜ Matrix<double> 
{
  {0, 1},
  {2, 3}
};
☀ MultiArray<double, 3>{ { {7, 14}, { 21, 28 }}, { {35, 42}, {49, 56} } } / 7 ➜ MultiArray<double, rank=3> 
{
  {
    {1, 2},
    {3, 4}
  },
  {
    {5, 6},
    {7, 8}
  }
};

☀ Vector<Matrix<double>>{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } } > 5 ➜ Vector<Matrix<bool>> {
{
  {false, false},
  {false, false}
}, 
{
  {true, true},
  {true, true}
}};
```

<br>

## `MultiArray`s of different depth
`MultiArray`s of different depths can be paired, where it makes sense.
For example, a 2x2 matrix can be added to a vector of 2x2 matrices.
Another example is adding a vector of length 2 to a vector of matrices that is also of length 2. Both cases are shown below.  

Examples:

```C++
Matrix<double> A{ {100, 200}, { 300,400 } };
Vector<Matrix<double>> v{ { {1, 2}, { 3, 4 }}, { {11, 12}, {13, 14} } };

☀ A+v ➜ Vector<Matrix<double>> {
{
  {101, 202},
  {303, 404}
}, 
{
  {111, 212},
  {313, 414}
}};

Vector<double> w{ -1, 2 };
☀ v*w ➜ Vector<Matrix<double>> {
{
  {-1, -2},
  {-3, -4}
}, 
{
  {22, 24},
  {26, 28}
}};
```

<br>



| ⇦ <br />[MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)  | [Introduction with Examples](../README.md)<br />Mixed-Rank & Mixed-Depth Arithmetic<br /><img width=1000/> | ⇨ <br />[Linear Algebra](../linear-algebra/README.md)   |
| ------------ | :-------------------------------: | ------------ |

