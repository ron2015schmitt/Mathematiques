[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.141-c++20</h1>](../../../README.md)

<details>

<summary>Documentation</summary>

# [Chapter  Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Status, Planned Work & Release Notes](../../status-release/README.md)<br>
Chapter 4. _Introduction with Examples_ <br>
Chapter 5. [Installation](../../installation/README.md)<br>
Chapter 6. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 7. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 8. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 9. [Tests](../../test/README.md)<br>
Chapter 10. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [4. Introduction with Examples](../README.md)<br>
4.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
4.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
4.3. _Vectors, Matrices, and MultiArrays_ <br>
4.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
4.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
4.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
4.7. [Linear Algebra](../linear-algebra/README.md)<br>
4.8. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
4.9. [Mathematical functions](../math-functions/README.md)<br>
4.10. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
4.11. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
4.12. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
4.13. [Tensors](../tensors/README.md)<br>
4.14. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 4.3. Vectors, Matrices, and MultiArrays



Mathématiques supports vectors, matrices and arbitrary rank multi-arrays.

<br>

## Vectors
Vectors can be fixed length, with length determined at compile-time, or dynamic length.  Fixed-length vectors allow for better optimzation by the compiler.
### Fixed-length Vectors
```C++
Vector<double, 3> v{ 1,2,3 };

☀ v ➜ Vector<double,3> {1, 2, 3};
```
### Dynamic-length Vectors
```C++
Vector<double> v{ 1,2,3,4,5 };

☀ v ➜ Vector<double> {1, 2, 3, 4, 5};
v = 100*v;
☀ v ➜ Vector<double> {100, 200, 300, 400, 500};
v.resize(10);
☀ v ➜ Vector<double> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
v = linspace<double>(0, 1, 10);
☀ v ➜ Vector<double> {0, 0.111111, 0.222222, 0.333333, 0.444444, 0.555556, 0.666667, 0.777778, 0.888889, 1};
```
### Vector Element access
```C++
Vector<double, 3> v{ 1,2,3 };

☀ v[0] ➜ double 1;
☀ v[1] ➜ double 2;
☀ v[2] ➜ double 3;
v[0] = 200;
☀ v ➜ Vector<double,3> {200, 2, 3};
v[2] = v[1] = v[0];
☀ v ➜ Vector<double,3> {200, 200, 200};
```

<br>

## Matrices
Matrices can be fixed dimensions, with dimensions determined at compile-time, or dynamic dimensions.
### Fixed-dimensions Matrices
```C++
Matrix<double, 2, 2> A{ {1,2}, {3,4} };

☀ A ➜ Matrix<double, 2⨯2> 
{
  {1, 2},
  {3, 4}
};
```
### Dynamic-dimensions Matrices
```C++
Matrix<double> A{ {1,2}, {3,4}, {5,6} };
☀ A ➜ Matrix<double> 
{
  {1, 2},
  {3, 4},
  {5, 6}
};

A.resize(1, 2);
☀ A ➜ Matrix<double> 
{
  {0, 0}
};
```
### Matrix Element access
Elements can be accessed via row and column indices:
```C++
Matrix<double> A{ {1,2}, {3,4}, {5,6} };
☀ A ➜ Matrix<double> 
{
  {1, 2},
  {3, 4},
  {5, 6}
};

☀ A(0, 0) ➜ double 1;
☀ A(2, 1) ➜ double 6;
```
Elements can also be accessed via a single row-major index:
```C++
Matrix<double> A{ {1,2}, {3,4}, {5,6} };
☀ A ➜ Matrix<double> 
{
  {1, 2},
  {3, 4},
  {5, 6}
};

☀ A[0] ➜ double 1;
☀ A[1] ➜ double 2;
☀ A[2] ➜ double 3;
```

<br>

## General MultiArrays
MultiArrays can be created of arbitrary rank via the syntax `MultiArray<double,[rank]]>`, where `[rank]` is a whole number.
In fact a `Vector` is simply an alias for a `MultiArray` of rank 1. 
A `Matrix` is simply an alias for a `MultiArray` of rank 2.  
It should be noted, however, that `Vector` and `Matrix` have optimized implementations.
Multiarrays are sometimes referred to as tensors.  To be accurate, multiarrays are Cartesian algebraic tensors.  Tensor fields are also supported by Mathématiques, but described later in this introduction.
### Fixed-dimensions MultiArrays
```C++
MultiArray<double, 3, 2, 2, 2> M{ { {1,2}, {3,4} }, { {5,6}, {7,8} } };

☀ M ➜ MultiArray<double, rank=3, 2⨯2⨯2> 
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
```
### Dynamic-dimensions MultiArrays
```C++
MultiArray<double, 3> M{ { {1,2}, {3,4} }, { {5,6}, {7,8} } };

☀ M ➜ MultiArray<double, rank=3> 
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
```
### MultiArray Element access
Elements can be accessed via multiple indices:
```C++
MultiArray<double, 3> M{ { {1,2}, {3,4} }, { {5,6}, {7,8} } };

☀ M ➜ MultiArray<double, rank=3> 
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

☀ M(0, 0, 0) ➜ double 1;
☀ M(1, 1, 1) ➜ double 8;
```
Elements can also be accessed via a single row-major index:
```C++
MultiArray<double, 3> M{ { {1,2}, {3,4} }, { {5,6}, {7,8} } };

☀ M ➜ MultiArray<double, rank=3> 
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

☀ M[0] ➜ double 1;
☀ M[1] ➜ double 2;
☀ M[2] ➜ double 3;
```

<br>



| ⇦ <br />[Number Systems and Arithmetic](../numbers/README.md)  | [Introduction with Examples](../README.md)<br />Vectors, Matrices, and MultiArrays<br /><img width=1000/> | ⇨ <br />[Nested MultiArrays](../nested-multiarrays/README.md)   |
| ------------ | :-------------------------------: | ------------ |

