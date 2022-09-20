[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.007</h1>](../../../README.md)

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

## Products: Inner, Outer, and Wedge
### `Vector`
Keep in mind that in Mathématiques, a `Vector<double>` (aka `MultiArray<double,1>`) is neither a column nor a row vector. Instead vectors `Vector<double>` are denoted as vectors are denoted in physics*.
Of course, if you really want row and column vectors, use `Matrix<double,N,1>` and `Matrix<double,N,1>` respectively, although this is not necessary. (Refer to the linear algebra notation section below.

| operator | operation | standard notation | rules |
| :---: | :---: | :---: | :---: | 
| `v \| w` | inner product | $\braket{\mathbf{v},\mathbf{w}} = \left\{ \begin{array}{cc} \mathbf{v} \cdot \mathbf{w}, & \in \mathbb{R}^N  \\ \mathbf{v}^* \cdot \mathbf{w}, & \in \mathbb{C}^N, \mathbb{Q}^N \end{array} \right.$ | both vectors must be of same length | 
| `v & w` | outer/tensor product | $\mathbf{v} \mathbf{w} = \left\{ \begin{array}{cc} \mathbf{v} \mathbf{w}, & \in \mathbb{R}^N  \\ \mathbf{v}^*  \mathbf{w}, & \in \mathbb{C}^N, \mathbb{Q}^N \end{array} \right.$ | none | 
| `v ^ w` | wedge product<sup>🚧</sup> | $\mathbf{v} \wedge \mathbf{w} = \left[ \mathbf{v} \mathbf{w} \right] = \mathbf{v} \mathbf{w} - \mathbf{w} \mathbf{v}$ | none | 

<sup>🚧</sup> wedge product is in progress. It requires completion of anti-symmetric (and anti-hermitian for complex numbers) matrices because the output will be of this type.

Examples:

```C++
Vector<double> A{ 1, 2, 3 };
Vector<double> B{ 2, 4, -3 };
☀ A|B ➜ double 1;
☀ A&B ➜ Matrix<double> 
{
  {2, 4, -3},
  {4, 8, -6},
  {6, 12, -9}
};
```
### Matrices

| operator | operation | standard notation | rules |
| :---: | :---: | :---: | :---: | 
| `A \| B` | inner product | $\braket{\mathbf{A},\mathbf{B}}$ = $\left\{ \begin{array}{cc} \mathbf{A} \cdot \mathbf{B}, & \in \mathbb{R}^N  \\ \mathbf{A}^* \cdot \mathbf{B}, & \in \mathbb{C}^N, \mathbb{Q}^N \end{array} \right.$ | both vectors must be of same length |
| `A & B` | outer product (tensor product) | $\mathbf{A} \mathbf{B}$ | none | 
| `A ^ B` | wedge product<sup>🚧</sup> | $\mathbf{A} \wedge \mathbf{B} = \left[ \mathbf{A} \mathbf{B} \right] = \mathbf{A} \mathbf{B} - \mathbf{B} \mathbf{A}$ | none | 

<sup>🚧</sup> wedge product is in progress. It requires completion of anti-symmetric (and anti-hermitian for complex numbers) matrices because the output will be of this type.

Examples:

```C++
Matrix<double> A{ {1, 2}, {3, 4} };
Matrix<double> B{ {11, 22}, {33, 44} };
☀ A|B ➜ Matrix<double> 
{
  {77, 110},
  {165, 242}
};
☀ A&B ➜ MultiArray<double, rank=4> 
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
```


| ⇦ <br />[Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)  | [Introduction with Examples](../README.md)<br />Linear Algebra<br /><img width=1000/> | ⇨ <br />[Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)   |
| ------------ | :-------------------------------: | ------------ |

