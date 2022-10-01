[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.021</h1>](../../../README.md)

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
8.6. [MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)<br>
8.7. [Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)<br>
8.8. [Linear Algebra](../linear-algebra/README.md)<br>
8.9. [Indexing, Masks, Slicing, Sorting, etc.](../sort-mask-slice/README.md)<br>
8.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
8.11. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
8.12. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
8.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
8.14. _Tensors_ <br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.14. Tensors

Mathématiques

<br>

## Examples
Contraction of of simple (non-field) 3D vectors
### Rank 1: Vectors and Covectors
```C++
using namespace mathq::TensorIndex;
Vector<double, 3>::Tensor<COVARIANT> covec;
covec = { 1,2,3 };
☀ covec ➜ Vector<double,3>::Tensor<L> {1, 2, 3};

Vector<double, 3>::Tensor<CONTRAVARIANT> vec;
vec = { 3,2,1 };
☀ vec ➜ Vector<double,3>::Tensor<H> {3, 2, 1};

☀ covec(vec) ➜ double 10;
☀ vec(covec) ➜ double 10;
```

<br>

### Rank 2 Tensors and the metric tensor
```C++
using namespace mathq::TensorIndex;
using namespace std::numbers;
double r = 5;
double theta = pi/2;
Matrix<double, 3, 3>::Tensor<L, L> g{ {1, 0, 0}, {0, pow(r,2), 0}, {0, 0 , pow(r*sin(theta),2)} };
☀ g ➜ Matrix<double, 3⨯3>::Tensor<L, L> 
{
  {1, 0, 0},
  {0, 25, 0},
  {0, 0, 25}
};

Matrix<double, 3, 3>::Tensor<H, H> ginv{ {1, 0, 0}, {0, pow(r,-2), 0}, {0, 0 , pow(r*sin(theta),-2)} };
☀ ginv ➜ Matrix<double, 3⨯3>::Tensor<H, H> 
{
  {1, 0, 0},
  {0, 0.04, 0},
  {0, 0, 0.04}
};

Vector<double, 3>::Tensor<CONTRAVARIANT> A{ 1,2,3 };
Vector<double, 3>::Tensor<CONTRAVARIANT> B{ 1,1,1 };
☀ g(A, B) ➜ double 126;
☀ g(A, NullType{}) ➜ Vector<double,3>::Tensor<L> {1, 50, 75};
☀ g(NullType{}, A) ➜ Vector<double,3>::Tensor<L> {1, 50, 75};
```


| ⇦ <br />[Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)  | [Introduction with Examples](../README.md)<br />Tensors<br /><img width=1000/> | ⇨ <br />[Series and transforms](../series-transforms/README.md)   |
| ------------ | :-------------------------------: | ------------ |

