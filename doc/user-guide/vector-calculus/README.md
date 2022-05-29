<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.40.10-c++17</h1>

<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br>
1. [Usage Guide Notation](../notation/README.md)<br>
2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../scalars/README.md)<br>
3. [Container Types (Vector, Matrix & MultiArray)](../multiarrays/README.md)<br>
4. [Operators](../operators/README.md)<br>
5. [Functions](../functions/README.md)<br>
6. [Linear Algebra](../linear-algebra/README.md)<br>
7. [Indexing, Masks, and Sorting](../indexing-sorting/README.md)<br>
8. [Ranges and Grids](../ranges-grids/README.md)<br>
9. [Calculus](../calculus/README.md)<br>
10. _Vector Calculus_ <br>
11. [MultiArray Calculus](../tensor-calculus/README.md)<br>
12. [Display of Results](../display/README.md)<br>
13. [FILE I/O](../file-io/README.md)<br>
14. [Debug Modes](../debug/README.md)<br>


</details>



# 10. Vector Calculus



## Introduction



<br>

### Grids, Functions, and Vector Calculus


```C++

☀ d1 ➜ mathq::Nabla (Ndims=1, Nwindow=7, periodic=0);
☀ u ➜ mathq::TargetSet<std::complex<double>> (Ndims=1, rank=0);
Coordinate<double> x_coord("x");
☀ x_coord ➜ mathq::Coordinate<double> (name="x");
Interval<double> x_interval("x", -1, 1, 5);
☀ x_interval ➜ mathq::Interval<double> (name="x", a=-1, b=1, N=5, gridState=deflated);
```


| ⇦ <br />[Calculus](../calculus/README.md)  | [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br />Vector Calculus<br /><img width=1000/> | ⇨ <br />[MultiArray Calculus](../tensor-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

