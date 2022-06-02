<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.40.15-c++17</h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
1. [License](../../license/README.md)<br>
2. [About](../../about/README.md)<br>
3. [Status, Planned Work & Release Notes](../../status-release/README.md)<br>
4. [Description and Example Usage](../../overview/README.md)<br>
5. [Installation](../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../first-project/README.md)<br>
7. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
8. [Benchmarks](../../benchmarks/README.md)<br>
9. [Tests](../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [7. Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br>
7.1. [Usage Guide Notation](../notation/README.md)<br>
7.2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../scalars/README.md)<br>
7.3. [Container Types (Vector, Matrix & MultiArray)](../multiarrays/README.md)<br>
7.4. [Operators](../operators/README.md)<br>
7.5. [Functions](../functions/README.md)<br>
7.6. [Linear Algebra](../linear-algebra/README.md)<br>
7.7. [Indexing, Masks, and Sorting](../indexing-sorting/README.md)<br>
7.8. [Ranges and Grids](../ranges-grids/README.md)<br>
7.9. [Calculus](../calculus/README.md)<br>
7.10. _Vector Calculus_ <br>
7.11. [MultiArray Calculus](../tensor-calculus/README.md)<br>
7.12. [Display of Results](../display/README.md)<br>
7.13. [FILE I/O](../file-io/README.md)<br>
7.14. [Debug Modes](../debug/README.md)<br>


</details>



# 7.10. Vector Calculus



## Introduction



<br>

### Grids, Functions, and Vector Calculus


```C++

* d1 -> mathq::Nabla (Ndims=1, Nwindow=7, periodic=0);
* u -> mathq::TargetSet<std::complex<double>> (Ndims=1, rank=0);
GridSet<double> gs;
* gs -> mathq::GridSet<double> {EmptySet};
Interval<double> x_interval(-1, 1, 5);
* x_interval -> mathq::Interval<double> (a=-1, b=1, N=5, gridState=deflated);
* rs.a -> double -2;
* rs.b -> double 2;
* rs.N -> unsigned long 5;
* rs.logscale -> bool 0;
* rs.include_a -> bool 1;
* rs.include_b -> bool 1;
* rs.hasInflatedGrid() -> bool 0;
* rs.makeGrid() -> Vector<double> {-2, -1, 0, 1, 2};
* rs.hasInflatedGrid() -> bool 1;
* rs1.a -> double -2;
* rs1.b -> double 3;
* rs1.N -> unsigned long 5;
* rs1.logscale -> bool 0;
* rs1.include_a -> bool 1;
* rs1.include_b -> bool 0;
* rs1.hasInflatedGrid() -> bool 0;
* rs1.makeGrid() -> Vector<double> {-2, -1, 0, 1, 2};
* rs1.hasInflatedGrid() -> bool 1;
* std::numeric_limits<double>::lowest() -> double -1.79769e+308;
RealSet<double> rs2 = RealSet<double>::realLine(10);
* rs2.a -> double -inf;
* rs2.N -> unsigned long 0;
* std::numeric_limits<double>::infinity() > 1 -> bool 1;
```


| ⇦ <br />[Calculus](../calculus/README.md)  | [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br />Vector Calculus<br /><img width=1000/> | ⇨ <br />[MultiArray Calculus](../tensor-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

