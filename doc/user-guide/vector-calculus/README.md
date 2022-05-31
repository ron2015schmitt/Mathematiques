<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.40.12-c++17</h1>

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

☀ d1 ➜ mathq::Nabla (Ndims=1, Nwindow=7, periodic=0);
☀ u ➜ mathq::TargetSet<std::complex<double>> (Ndims=1, rank=0);
Coordinate<double> x_coord("x");
☀ x_coord ➜ mathq::Coordinate<double> (name="x");
Coordinate<double> y_coord("y");
☀ y_coord ➜ mathq::Coordinate<double> (name="y");
Coordinates<double> xy_coords("xy",{x_coord, y_coord});
☀ xy_coords ➜ mathq::Coordinates<double> (name="xy", coordinates={(name="x"), (name="y")});
Coordinates<double> xy_coords2("xy",{"x","y"});
☀ xy_coords2 ➜ mathq::Coordinates<double> (name="xy", coordinates={(name="x"), (name="y")});
Interval<double> x_interval("x", -1, 1, 5);
☀ x_interval ➜ mathq::Interval<double> (name="x", a=-1, b=1, N=5, gridState=deflated);
Interval<double> y_interval("y", 0, 3, 4);
☀ y_interval ➜ mathq::Interval<double> (name="y", a=0, b=3, N=4, gridState=deflated);
auto gridX0 = x_interval.getGrid();
☀ x_interval ➜ mathq::Interval<double> (name="x", a=-1, b=1, N=5, gridState=inflated);
☀ gridX0 ➜ Vector<double> {-1, -0.5, 0, 0.5, 1};
☀ g ➜ Vector<double,NE=5> {-1, -0.5, 0, 0.5, 1};
☀ gridX ➜ Vector<double> {-1, -0.5, 0, 0.5, 1};
Region<double> xy_region("Cartesian-2D", { x_interval, y_interval });
☀ xy_region ➜ mathq::Region<double> ( Ndims=2, name="Cartesian-2D", intervals={(name="x", a=-1, b=1, N=5, gridState=inflated), (name="y", a=0, b=3, N=4, gridState=deflated)} );
```


| ⇦ <br />[Calculus](../calculus/README.md)  | [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br />Vector Calculus<br /><img width=1000/> | ⇨ <br />[MultiArray Calculus](../tensor-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

