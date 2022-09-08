<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.114-c++20</h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
1. [License](../../license/README.md)<br>
2. [About](../../about/README.md)<br>
3. [Status, Planned Work & Release Notes](../../status-release/README.md)<br>
4. _Introduction with Examples_ <br>
5. [Installation](../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../first-project/README.md)<br>
7. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
8. [Benchmarks](../../benchmarks/README.md)<br>
9. [Tests](../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [4. Introduction with Examples](../README.md)<br>
4.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
4.2. [Number Systems](../numbers/README.md)<br>
4.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
4.4. _Nested MultiArrays_ <br>
4.5. [Mathematical functions](../math-functions/README.md)<br>
4.6. [Linear Algebra](../linear-algebra/README.md)<br>
4.7. [Calculus and Vector Calculus](../vector-calculus/README.md)<br>
4.8. [Tensors](../tensors/README.md)<br>
4.9. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 4.4. Nested MultiArrays



Mathématiques supports vectors, matrices and arbitrary rank multi-arrays.   These containers can be nested any number of levels.

<br>

## Vectors
Vectors can be fixed length, with length determined at compile-time, or dynamic length.
### Fixed-length Vectors
```C++
Vector<double, 3> v{ 1,2,3 };

☀ v ➜ Vector<double,N0=3> {1, 2, 3};
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
### Element access
```C++
Vector<double, 3> v{ 1,2,3 };

☀ v[0] ➜ double 1;
☀ v[1] ➜ double 2;
☀ v[2] ➜ double 3;
v[0] = 200;
☀ v ➜ Vector<double,N0=3> {200, 2, 3};
v[2] = v[1] = v[0];
☀ v ➜ Vector<double,N0=3> {200, 200, 200};
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
```
### Element access
```C++
Vector<double, 3> v{ 1,2,3 };

☀ v[0] ➜ double 1;
☀ v[1] ➜ double 2;
☀ v[2] ➜ double 3;
v[0] = 200;
☀ v ➜ Vector<double,N0=3> {200, 2, 3};
v[2] = v[1] = v[0];
☀ v ➜ Vector<double,N0=3> {200, 200, 200};
```

<br>

## MultiArrays
MultiArrays can be created of arbitrary rank, `MultiArray<double,[rank]]>`, where `[rank]` is a whole number.
In fact a `Vector` is simply an alias for a `MultiArray` of rank 1. 
A `Matrix` is simply an alias for a `MultiArray` of rank 2. 

<br>



| ⇦ <br />[Vectors, Matrices, and MultiArrays](../multiarrays/README.md)  | [Introduction with Examples](../README.md)<br />Nested MultiArrays<br /><img width=1000/> | ⇨ <br />[Mathematical functions](../math-functions/README.md)   |
| ------------ | :-------------------------------: | ------------ |

