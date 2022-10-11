<h1 style='border: 2px solid; text-align: center'><a href='../README.md'>Mathématiques 0.42.3</a></h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Versioning](../../versioning/README.md)<br>
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
6.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
6.5. _Special Vectors, Matrices, and MultiArrays_ <br>
6.6. [MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)<br>
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



# 6.5. Special Vectors, Matrices, and MultiArrays




<br>

## Constant MultiArrays
These multiarrays have the same value for each element, and only take the memory profile a single element (plus dimensions integers for dynamic multiarrays).

<details><summary>Constant MultiArray Examples</summary><blockquote>


### Vector_Constant

```C++
Vector_Constant<double, 5> v{ 3.14 };

☀ v ➜ Vector_Constant<double,N0=5> {3.14, 3.14, 3.14, 3.14, 3.14};

☀ sizeof(v)/sizeof(double) ➜ unsigned long 1;
```

### Dynamic-length Vector_Constant

```C++
Vector_Constant<double> v{ 5, 3.14 };

☀ v ➜ Vector_Constant<double> {3.14, 3.14, 3.14, 3.14, 3.14};

☀ sizeof(v)/sizeof(double) ➜ unsigned long 2;
```

### Matrix_Constant

```C++
Matrix_Constant<double, 2, 3> A{ 3.14 };

☀ A ➜ Matrix_Constant<double, 2⨯3> 
{
  {3.14, 3.14, 3.14},
  {3.14, 3.14, 3.14}
};

☀ sizeof(A)/sizeof(double) ➜ unsigned long 1;
```

### Dynamic-length Matrix_Constant

```C++
Matrix_Constant<double> A(Dimensions{ 2, 3 }, 3.14);

☀ A ➜ Matrix_Constant<double> 
{
  {3.14, 3.14, 3.14},
  {3.14, 3.14, 3.14}
};

☀ sizeof(A)/sizeof(double) ➜ unsigned long 3;
```

### MultiArray_Constant

```C++
MultiArray_Constant<double, 3, 1, 2, 3> A{ 3.14 };

☀ A ➜ MultiArray_Constant<double, rank=3, 1⨯2⨯3> 
{
  {
    {3.14, 3.14, 3.14},
    {3.14, 3.14, 3.14}
  }
};

☀ sizeof(A)/sizeof(double) ➜ unsigned long 1;
```

### Dynamic-length MultiArray_Constant

```C++
MultiArray_Constant<double, 3> A(Dimensions{ 1, 2, 3 }, 3.14);

☀ A ➜ MultiArray_Constant<double, rank=3> 
{
  {
    {3.14, 3.14, 3.14},
    {3.14, 3.14, 3.14}
  }
};

☀ sizeof(A)/sizeof(double) ➜ unsigned long 4;
```


</blockquote></details>


<br>

## Repeated Vector MultiArrays
These multiarrays vary along only one indices, which implies that they can be specified by a single vector.  For `rank=2`, this results in either a repeated-column matrix (`index=0`) or a repeated-row matrix (`index=1`) .

<details><summary>Repeated Vector MultiArray Examples</summary><blockquote>


### Matrix_RepeatVector

#### Repeated Column Matrix
Set the varying index to zero.

```C++
Matrix_RepeatVector<double, 2, 3 > A(0, { 1.1, 2.2 });

☀ A ➜ MultiArray_RepeatVector<double, rank=2, 2⨯3> 
{
  {1.1, 1.1, 1.1},
  {2.2, 2.2, 2.2}
};

☀ sizeof(A)/sizeof(double) ➜ unsigned long 3;
```


#### Repeated Row Matrix
Set the varying index to one.

```C++
Matrix_RepeatVector<double, 2, 3 > A(1, { 1.1, 2.2, 3.3 });

☀ A ➜ MultiArray_RepeatVector<double, rank=2, 2⨯3> 
{
  {1.1, 2.2, 3.3},
  {1.1, 2.2, 3.3}
};

☀ sizeof(A)/sizeof(double) ➜ unsigned long 3;
```


</blockquote></details>


<br>

## Special MultiArrays In Development
🚧 in progress...

<br>

* Block Matrix
* Zero Matrix, **`0`**, useful for block matrices
* Identity Matrix, **`I`**
* Exchange Matrix, **`J`**


<br>

* Diagonal Matrix
* Cross-Diagonal Matrix


<br>

* Upper-Triangle Matrix
* Lower-Triangle Matrix
* Symmetric Matrix
* Skew Symmetric Matrix
* Hermitian Matrix
* Skew Hermitian Matrix
* Toeplitz Matrix
* Vandermonde Matrix


<br>

* Sparse MultiArray
* Levi-Cevita Symbol MultiArray
* Pauli matrices and Gamma matrices


<br>



| ⇦ <br />[Nested MultiArrays](../nested-multiarrays/README.md)  | [Introduction with Examples](../README.md)<br />Special Vectors, Matrices, and MultiArrays<br /><img width=1000/> | ⇨ <br />[MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)   |
| ------------ | :-------------------------------: | ------------ |

