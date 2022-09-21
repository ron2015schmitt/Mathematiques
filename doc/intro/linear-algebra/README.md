[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.009</h1>](../../../README.md)

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
8.7. [Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)<br>
8.8. _Linear Algebra_ <br>
8.9. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
8.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
8.11. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
8.12. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
8.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
8.14. [Tensors](../tensors/README.md)<br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.8. Linear Algebra




<br>

## Inner Product, Outer Product, Transpose
### `Vector`
Keep in mind that in Mathématiques, a `Vector<double>` (aka `MultiArray<double,1>`) is neither a column nor a row vector. Instead vectors `Vector<double>` are denoted as vectors are denoted in physics*.
Of course, if you really want row and column vectors, use `Matrix<double,N,1>` and `Matrix<double,N,1>` respectively, although this is not necessary. (Refer to the linear algebra notation section below.

| function | operator form | operation | standard notation | rules |
| :---: | :---: | :---: | :---: | :---: | 
| `dot(v, w)` | `v \| w` | inner product | $\mathbf{v} \cdot \mathbf{w} = \displaystyle\sum_{i=1}^{N} v_i w_i$ | both vectors must be of same length | 
| `tensor_product(v,w)` | `v & w` | outer/tensor product | $\mathbf{v} \mathbf{w} = \left[ v_i w_j \right]$ | none | 
| `cross(v,w)` | `v ^ w` | cross product | $\mathbf{v} \times \mathbf{w} = \left(  v_2 w_3 - v_3 w_2, \enspace v_3 w_1 - v_1 w_3, \enspace v_1 w_2 - v_2 w_1 \right)$ | $N = 3$ | 
| `conj(v)` | `~v` | complex conjugate | $\mathbf{v}^*$ | none | 

Examples:

```C++
Vector<double> v{ 1, 2, 3 };
Vector<double> w{ 2, 4, -3 };
☀ v | w ➜ double 1;
☀ v & w ➜ Matrix<double> 
{
  {2, 4, -3},
  {4, 8, -6},
  {6, 12, -9}
};
```

<br>

### Matrix

| function | operator form | operation | standard notation | rules |
| :---: | :---: | :---: | :---: | :---: | 
| `dot(A, B)` | `A \| B` | inner product | $\mathbf{A} \cdot \mathbf{B} = \displaystyle\sum_{j=1}^{M} A_{ij} B_{jk}$ | $\left. \begin{array}{c} \mathbf{A} = L \!\!\times\!\! M \,\text{matrix} \\ \mathbf{B} = M \!\!\times\!\! N \,\text{matrix} \end{array}  \right.$ | 
| `tensor_product(A,B)` | `A & B` | outer/tensor product | $\mathbf{A} \mathbf{B} = \left[ A_{ij} B_{kl} \right]$ | none | 
| `conj(A)` |  | conjugate | $ \left\\{ \begin{array}{cc} \mathbf{A} & \mathbf{A}  \text{real} \\\\ \mathbf{A}^{*}  & \mathbf{A} \;  \text{complex}  \end{array} \right. $ | none | 
| `transpose(A)` |  | transpose | $ \left\{ \begin{array}{cc} \mathbf{A}^{T} & \mathbf{A} \; \text{real} \\ \mathbf{A}^{T}  & \mathbf{A} \;  \text{complex}  \end{array} \right. $ | none | 
| `adjoint(A)` | `~A` | adjoint | $ \left\{ \begin{array}{cc} \mathbf{A}^{T} & \mathbf{A} \; \text{real} \\ \mathbf{A}^{\dagger} = \mathbf{A}^{T*}  & \mathbf{A} \;  \text{complex}  \end{array} \right. $ | none | 


Examples:

```C++
Matrix<double> A{ {1, 2}, {3, 4} };
Matrix<double> B{ {11, 22}, {33, 44} };
☀ A | B ➜ Matrix<double> 
{
  {77, 110},
  {165, 242}
};
☀ A & B ➜ MultiArray<double, rank=4> 
{
  {
    {
      {11, 22},
      {33, 44}
    },
    {
      {22, 44},
      {66, 88}
    }
  },
  {
    {
      {33, 66},
      {99, 132}
    },
    {
      {44, 88},
      {132, 176}
    }
  }
};

☀ conj(A) ➜ Matrix<double> 
{
  {1, 2},
  {3, 4}
};
☀ transpose(A) ➜ Matrix<double> 
{
  {1, 3},
  {2, 4}
};
☀ ~A ➜ Matrix<double> 
{
  {1, 3},
  {2, 4}
};

Matrix<std::complex<double>> D{ { 1 + 10i, 2 + 20i }, { 3 + 30i, 4 + 40i } };
☀ D ➜ Matrix<std::complex<double>> 
{
  {(1,10), (2,20)},
  {(3,30), (4,40)}
};
☀ conj(D) ➜ Matrix<std::complex<double>> 
{
  {(1,-10), (2,-20)},
  {(3,-30), (4,-40)}
};
☀ transpose(D) ➜ Matrix<std::complex<double>> 
{
  {(1,10), (3,30)},
  {(2,20), (4,40)}
};
☀ ~D ➜ Matrix<std::complex<double>> 
{
  {(1,-10), (3,-30)},
  {(2,-20), (4,-40)}
};
```

<br>

### Matrix and Vector

| function | operator form | operation | standard notation | rules |
| :---: | :---: | :---: | :---: | :---: | 
| `dot(v, A)` | `v \| A` | inner product | $\mathbf{v} \cdot \mathbf{A} = \displaystyle\sum_{i=1}^{M} v_{i} A_{ij}$ | $\left. \begin{array}{c} \mathbf{v} = \text{length}\, M \,\text{vector} \\ \mathbf{A} = M \!\!\times\!\! N \,\text{matrix} \end{array}  \right.$ | 
| `dot(A, v)`| `A \| v`| inner product | $\mathbf{A} \cdot \mathbf{v} = \displaystyle\sum_{j=1}^{N}  A_{ij} v_{j}$ | $\left. \begin{array}{c} \mathbf{A} = M \!\!\times\!\! N \,\text{matrix} \\ \mathbf{v} = \text{length}\, N \,\text{vector} \end{array}  \right.$ | 
| `tensor_product(v, A)` | `v & A` | outer/tensor product | $\mathbf{v} \mathbf{A} = \left[ v_{i} A_{jk} \right]$ | none | 
| `tensor_product(A, v)` | `A & v` | outer/tensor product | $\mathbf{A} \mathbf{v}  = \left[ A_{jk} v_{l} \right]$ | none | 


Examples:

```C++
Vector<double> v{ 1, 2 };
Matrix<double> A{ {1, 2}, {3, 4} };

☀ v | A ➜ Vector<double> {7, 10};
☀ A | v ➜ Vector<double> {5, 11};

☀ v & A ➜ MultiArray<double, rank=3> 
{
  {
    {1, 2},
    {3, 4}
  },
  {
    {2, 4},
    {6, 8}
  }
};
☀ A & v ➜ MultiArray<double, rank=3> 
{
  {
    {1, 2},
    {2, 4}
  },
  {
    {3, 6},
    {4, 8}
  }
};

```

<br>

### General MultiArrays

The above functions are extended to general MultiArrays of any rank.  The transpose is defined by reverse all the indices. 


| ⇦ <br />[Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)  | [Introduction with Examples](../README.md)<br />Linear Algebra<br /><img width=1000/> | ⇨ <br />[Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)   |
| ------------ | :-------------------------------: | ------------ |

