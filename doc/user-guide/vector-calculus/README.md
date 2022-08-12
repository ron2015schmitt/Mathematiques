<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.8-c++20</h1>

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

☀ d1 ➜ Nabla<> (Nwindow=7);

RealSet<double> rs(-2, +2, 5);
☀ rs ➜ RealSet<double> {interval=[-2, 2], N=5, scale=LINEAR};
☀ rs.getGrid() ➜ Vector<double> {-2, -1, 0, 1, 2};

RealSet<double> rs1(-2, +3, 5, GridScale::LINEAR, true, false);
☀ rs1 ➜ RealSet<double> {interval=[-2, 3], N=5, scale=LINEAR};
☀ rs1.getGrid() ➜ Vector<double> {-2, -1, 0, 1, 2};

RealSet<double> rs2 = RealSet<double>::realLine();
☀ rs2 ➜ RealSet<double> {interval=[-inf, inf], N=0, scale=LINEAR};

RealSet<double> rs3(10, 1e5, 10, GridScale::LOG);
☀ rs3 ➜ RealSet<double> {interval=[10, 100000], N=10, scale=LOG};
☀ rs3.getGrid() ➜ Vector<double> {10, 27.8256, 77.4264, 215.443, 599.484, 1668.1, 4641.59, 12915.5, 35938.1, 100000};
☀ mathq::log10(rs3.getGrid()) ➜ Vector<double> {1, 1.44444, 1.88889, 2.33333, 2.77778, 3.22222, 3.66667, 4.11111, 4.55556, 5};

auto rs4 = RealSet<double>::point(2.5);
☀ rs4 ➜ RealSet<double> {point=2.5};
☀ rs4.getGrid() ➜ Vector<double> {2.5};

RealSet<double> rx(-10, +10, 3);
☀ rx ➜ RealSet<double> {interval=[-10, 10], N=3, scale=LINEAR};
☀ rx.getGrid() ➜ Vector<double> {-10, 0, 10};

RealSet<double> ry(-20, 20, 5, GridScale::LINEAR);
☀ ry ➜ RealSet<double> {interval=[-20, 20], N=5, scale=LINEAR};
☀ ry.getGrid() ➜ Vector<double> {-20, -10, 0, 10, 20};
RealSet<double> rz(30, 33, 4, GridScale::LINEAR);
☀ rz ➜ RealSet<double> {interval=[30, 33], N=4, scale=LINEAR};
☀ rz.getGrid() ➜ Vector<double> {30, 31, 32, 33};
```


| ⇦ <br />[Calculus](../calculus/README.md)  | [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br />Vector Calculus<br /><img width=1000/> | ⇨ <br />[MultiArray Calculus](../tensor-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

