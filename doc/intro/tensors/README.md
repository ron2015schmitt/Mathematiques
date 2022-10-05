[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.038</h1>](../../../README.md)

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
8.11. [Numerical / Discretized Mathematical Function Objects](../numerical-functions/README.md)<br>
8.12. [Functions of Complex Variables](../complex-calculus/README.md)<br>
8.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
8.14. _Tensors_ <br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.14. Tensors

## Background
Mathématiques supports tensors and generalized coordinates. 
Let $\vec{x}=(x_1,x_2,x_3)$ be Cartesian coordinates for 3D (flat) space.  
and let $(q_1,q_2,q_3)$ be a set of generalized coordinates.  
Then the *basis* is given by the vectors.

$$ \vec{e}_1 \doteq \frac{\partial \vec{x}}{\partial q^1} , \enspace \vec{e}_2 \doteq \frac{\partial \vec{x}}{\partial q^2} , \enspace \vec{e}_3 \doteq \frac{\partial \vec{x}}{\partial q^3} $$

And the *reciprocal basis* is given by the vectors.

$$ \vec{e}^1 \doteq \vec{\nabla} q^1 , \enspace \vec{e}^2 \doteq \vec{\nabla} q^2 , \enspace \vec{e}^3 \doteq \vec{\nabla} q^3 $$

The vectors of the basis and reciprocal basis are mutually orthonormal

$$ \vec{e} \lower 2pt {i} \cdot \vec{e}^j = \delta \lower 2pt {ij}$$

where $\delta_{ij}$ is the [Kroencker delta](https://en.wikipedia.org/wiki/Kronecker_delta) 

<br>

## Rank 1: Contravariant and Covariant Vectors
### Contravariant Vectors
A vector written in terms of the basis

$$ \vec{A} = \sum_{i=1}^{3}  A^i \vec{e}_i $$

is referred to as contravariant form.  Note that the indices are superscripted or 'high'.
In Mathématiques a contravariant vector can be declared as follows
```C++
Vector<double, 3>::Tensor<CONTRAVARIANT> A;
```
or
```C++
Vector<double, 3>::Tensor<H> A;
```
### Covariant Vectors
A vector written in terms of the reciprocal basis

$$ \vec{A} = \sum_{i=1}^{3}  A_i \vec{e}^i $$

is referred to as covariant form.  Note that the indices are subscripted or 'low'.
In Mathématiques a covariant vector can be declared as follows
```C++
Vector<double, 3>::Tensor<COVARIANT> A;
```
or
```C++
Vector<double, 3>::Tensor<L> A;
```
## Inner product of rank 1 tensors
From the mutual othonormality of the bases, the inner product of two vectors can be written

$$ \vec{A} \cdot \vec{B} = A_i B^i$$

where we have used the [Einstein summation convention](https://en.wikipedia.org/wiki/Einstein_notation).
Mathématiques uses modern tensor notation, and we write the inner product as either $A(B)$ or $B(A)$.
```C++
using namespace mathq::TensorIndex::LH;
Vector<double, 3>::Tensor<L> A{ 1,2,3 };
☀ A ➜ Vector<double,3>::Tensor<L> {1, 2, 3};

Vector<double, 3>::Tensor<H> B{ 1,25,25 };
☀ B ➜ Vector<double,3>::Tensor<H> {1, 25, 25};

☀ A(B) ➜ double 126;
☀ B(A) ➜ double 126;
```

<br>

### Rank 2 Tensors and the metric tensor
A rank 2 tensor has the same number of elements as a matrix, but now there are four forms: $A_{ij}$, ${A_i}^{j}$, ${A^i}\_{j}$, and $A^{ij}$
The most important rank 2 tensor is the [metric tensor](https://en.wikipedia.org/wiki/Metric_tensor), $g_{ij}$, which determined by the generalized coordinates used.
The metric tensor allows the conversion of a contravariant vector into a covariant vector.

$$ g(V,\cdot) =  g_{ij} V^i  = V_j$$

It also then allows us to take the inner product of two contravariant vectors

$$ g(V,W) =  g_{ij} V^i W^j  = V_j W^j$$

The code for these operations are given below
```C++
using namespace mathq::TensorIndex::LH;
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

Vector<double, 3>::Tensor<H> V{ 1,2,3 };
Vector<double, 3>::Tensor<H> W{ 1,1,1 };
const NullType o;

☀ g(V, o) ➜ Vector<double,3>::Tensor<L> {1, 50, 75};
☀ g(V, W) ➜ double 126;
☀ g(o, W) ➜ Vector<double,3>::Tensor<L> {1, 25, 25};

☀ g(V, V) ➜ double 326;
☀ g(V, o)(V) ➜ double 326;
```

<br>

## Tensor Fields and Calculus
* full support for generalized coordinates (`TensorCoords`) and tensor fields (`TensorField`) is under way.

* method to pretty-print tensors, eg

  * contravariant: 2.35 ∇r + 3.43 ∇θ

  * covariant:  5.0 ∂**x**/∂r + 4.32 ∂**x**/∂θ

* Support for tensors in Riemannian geometry, differential forms etc



| ⇦ <br />[Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)  | [Introduction with Examples](../README.md)<br />Tensors<br /><img width=1000/> | ⇨ <br />[Series and transforms](../series-transforms/README.md)   |
| ------------ | :-------------------------------: | ------------ |

