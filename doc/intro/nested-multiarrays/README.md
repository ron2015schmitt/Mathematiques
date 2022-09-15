[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.152-c++20</h1>](../../../README.md)

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
6.4. _Nested MultiArrays_ <br>
6.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
6.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
6.7. [Linear Algebra](../linear-algebra/README.md)<br>
6.8. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
6.9. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
6.10. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
6.11. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
6.12. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
6.13. [Tensors](../tensors/README.md)<br>
6.14. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.4. Nested MultiArrays



MultiArrays can contain any number type, eg `int`, `double`, `complex<float>`, `Quaternion<extended>`.
Additionally, the elements of a `MultiArray` can be another type of `MultiArray`.
These containers can be nested any number of levels.
### Vector of Matrices
A Vector of Matrices is useful for storing the values of a vector field on a grid of points
```C++
Vector<Matrix<double, 2, 2>, 3> E;
☀ E ➜ Vector<Matrix<double, 2⨯2>,3> {
{
  {1, 2},
  {3, 4}
}, 
{
  {-1, -2},
  {-3, -4}
}, 
{
  {11, 12},
  {13, 14}
}};

☀ E[0] ➜ Matrix<double, 2⨯2> 
{
  {1, 2},
  {3, 4}
};

☀ E[0](0, 1) ➜ double 2;
```
### Matrix of Vectors
A Matrix of Vectors can also be used for storing the values of a vector field on a grid of points
```C++
Matrix<Vector<double, 3>, 2, 2> E;
☀ E ➜ Matrix<Vector<double,3>, 2⨯2> 
{
  {{1, -1, 11}, {4, -4, 14}},
  {{3, -3, 13}, {12, 13, 14}}
};

☀ E(0, 0) ➜ Vector<double,3> {1, -1, 11};

☀ E(0, 1)[1] ➜ double -4;
```
### Eversion - turning a structure inside out
A `Vector` of Matrices can be converted to a `Matrix` of `Vector`s and vice verse
```C++
Vector<Matrix<double, 2, 2>, 3> E{ { {1, 2}, {3, 4} }, { {-1, -2}, {-3, -4} }, { {11, 12}, {13, 14} } };
☀ E ➜ Vector<Matrix<double, 2⨯2>,3> {
{
  {1, 2},
  {3, 4}
}, 
{
  {-1, -2},
  {-3, -4}
}, 
{
  {11, 12},
  {13, 14}
}};

☀ evert(E) ➜ Matrix<Vector<double,3>, 2⨯2> 
{
  {{1, -1, 11}, {2, -2, 12}},
  {{3, -3, 13}, {4, -4, 14}}
};

☀ evert(evert(E)) ➜ Vector<Matrix<double, 2⨯2>,3> {
{
  {1, 2},
  {3, 4}
}, 
{
  {-1, -2},
  {-3, -4}
}, 
{
  {11, 12},
  {13, 14}
}};
```

<br>



| ⇦ <br />[Vectors, Matrices, and MultiArrays](../multiarrays/README.md)  | [Introduction with Examples](../README.md)<br />Nested MultiArrays<br /><img width=1000/> | ⇨ <br />[Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)   |
| ------------ | :-------------------------------: | ------------ |

