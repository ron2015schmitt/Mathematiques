<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.40.8-c++17</h1>

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
Domain<double> domX(-1, 1, 5, "x");
☀ domX ➜ mathq::Domain<double> (a=-1, b=1, N=5, name="x", gridState=deflated);
auto gridX0 = domX.getGrid();
☀ domX ➜ mathq::Domain<double> (a=-1, b=1, N=5, name="x", gridState=inflated);
☀ gridX0 ➜ Vector<double> {-1, -0.5, 0, 0.5, 1};
☀ g ➜ Vector<double,NE=5> {-1, -0.5, 0, 0.5, 1};
☀ gridX ➜ Vector<double> {-1, -0.5, 0, 0.5, 1};
☀ domY ➜ mathq::Domain<double> (a=0, b=3, N=4, name="y", gridState=deflated);
☀ { 1,2 } ➜ {1, 2};
☀ { 1,2 } ➜ std::list<int> {1, 2};
MultiDomain<double> domXY({ domX, domY }, "Cartesian-2D");
☀ domXY ➜ mathq::MultiDomain<double> (Ndims=2, name="Cartesian-2D", domains={(a=-1, b=1, N=5, name="x", gridState=inflated), (a=0, b=3, N=4, name="y", gridState=deflated)};
☀ domXY[0] ➜ mathq::Domain<double> (a=-1, b=1, N=5, name="x", gridState=inflated);
☀ domXY["x"] ➜ mathq::Domain<double> (a=-1, b=1, N=5, name="x", gridState=inflated);
MultiDomain<double> domXY2({ Domain<double>(-10, 10, 5), Domain<double>(0, 7, 4) });
☀ domXY2 ➜ mathq::MultiDomain<double> (Ndims=2, name="unnamed", domains={(a=-10, b=10, N=5, name="unnamed", gridState=deflated), (a=0, b=7, N=4, name="unnamed", gridState=deflated)};
☀ domXY3 ➜ mathq::MultiDomain<double> (Ndims=2, name="unnamed", domains={(a=-10, b=10, N=5, name="unnamed", gridState=deflated), (a=0, b=7, N=4, name="unnamed", gridState=deflated)};
☀ rz ➜ mathq::Domain<double> (a=10, b=11, N=2, name="unnamed", gridState=deflated);
☀ divX ➜ Vector<double> {1, 1, 1, 1, 1};
☀ gridX2 ➜ Vector<double> {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
☀ gradX2 ➜ Vector<double> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
☀ gradX2_2 ➜ Vector<double> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
☀ sqr(gridX + 2) ➜ TER_Unary Vector<double> {1, 2.25, 4, 6.25, 9};
☀ func(-3) ➜ double 1;
☀ fgrid(func, gridX) ➜ Vector<double> {1, 2.25, 4, 6.25, 9};
☀ func2(1) ➜ double 2.71828;
☀ fgrid(func2, gridX) ➜ Vector<double> {0.367879, 0.606531, 1, 1.64872, 2.71828};
☀ static_cast<double (*)(double)>(&std::exp)(1) ➜ double 2.71828;
☀ func3(1) ➜ double 2.71828;
☀ fgrid(func3, gridX) ➜ Vector<double> {0.367879, 0.606531, 1, 1.64872, 2.71828};
☀ func4(-3) ➜ double 0.0497871;
☀ fgrid(func4, gridX) ➜ Vector<double> {0.367879, 0.606531, 1, 1.64872, 2.71828};

☀ domY ➜ mathq::Domain<double> (a=0, b=3, N=4, name="y", gridState=deflated);
☀ grid(domY) ➜ Vector<double> {0, 1, 2, 3};
☀ rz ➜ mathq::Domain<double> (a=10, b=11, N=2, name="unnamed", gridState=deflated);
☀ grid(rz) ➜ Vector<double> {10, 11};
☀ gridXY(0) ➜ Matrix<double> { {-1, -0.5, 0, 0.5, 1}, {-1, -0.5, 0, 0.5, 1}, {-1, -0.5, 0, 0.5, 1}, {-1, -0.5, 0, 0.5, 1} };
☀ gridXY(1) ➜ Matrix<double> { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 3, 3, 3, 3} };
☀ R ➜ Matrix<double> { {1, 0.5, 0, 0.5, 1}, {1.41421, 1.11803, 1, 1.11803, 1.41421}, {2.23607, 2.06155, 2, 2.06155, 2.23607}, {3.16228, 3.04138, 3, 3.04138, 3.16228} };
☀ R2 ➜ Matrix<double> { {1, 0.5, 0, 0.5, 1}, {1.41421, 1.11803, 1, 1.11803, 1.41421}, {2.23607, 2.06155, 2, 2.06155, 2.23607}, {3.16228, 3.04138, 3, 3.04138, 3.16228} };
☀ gradXY(0) ➜ Matrix<double> { {0.666667, -1.66667, 0, 1.66667, -0.666667}, {-0.673967, -0.452828, -3.70074e-17, 0.452828, 0.673967}, {-0.445087, -0.24283, 0, 0.24283, 0.445087}, {-0.315896, -0.164443, -2.22045e-16, 0.164443, 0.315896} };
☀ gradXY(1) ➜ Matrix<double> { {1, 0.5, 0, 0.5, 1}, {1.41421, 1.11803, 1, 1.11803, 1.41421}, {2.23607, 2.06155, 2, 2.06155, 2.23607}, {3.16228, 3.04138, 3, 3.04138, 3.16228} };
☀ gradXY(0) ➜ Matrix<double> { {0.666667, -1.66667, 0, 1.66667, -0.666667}, {-0.673967, -0.452828, -3.70074e-17, 0.452828, 0.673967}, {-0.445087, -0.24283, 0, 0.24283, 0.445087}, {-0.315896, -0.164443, -2.22045e-16, 0.164443, 0.315896} };
☀ gradXY(1) ➜ Matrix<double> { {1, 0.5, 0, 0.5, 1}, {1.41421, 1.11803, 1, 1.11803, 1.41421}, {2.23607, 2.06155, 2, 2.06155, 2.23607}, {3.16228, 3.04138, 3, 3.04138, 3.16228} };

☀ gridXYZ(0) ➜ MultiArray<double> 
{
  {
    {-1, -1},
    {-0.5, -0.5},
    {0, 0},
    {0.5, 0.5},
    {1, 1}
  },
  {
    {-1, -1},
    {-0.5, -0.5},
    {0, 0},
    {0.5, 0.5},
    {1, 1}
  },
  {
    {-1, -1},
    {-0.5, -0.5},
    {0, 0},
    {0.5, 0.5},
    {1, 1}
  },
  {
    {-1, -1},
    {-0.5, -0.5},
    {0, 0},
    {0.5, 0.5},
    {1, 1}
  }
};
☀ gridXYZ(1) ➜ MultiArray<double> 
{
  {
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
  },
  {
    {1, 1},
    {1, 1},
    {1, 1},
    {1, 1},
    {1, 1}
  },
  {
    {2, 2},
    {2, 2},
    {2, 2},
    {2, 2},
    {2, 2}
  },
  {
    {3, 3},
    {3, 3},
    {3, 3},
    {3, 3},
    {3, 3}
  }
};
☀ gridXYZ(2) ➜ MultiArray<double> 
{
  {
    {10, 11},
    {10, 11},
    {10, 11},
    {10, 11},
    {10, 11}
  },
  {
    {10, 11},
    {10, 11},
    {10, 11},
    {10, 11},
    {10, 11}
  },
  {
    {10, 11},
    {10, 11},
    {10, 11},
    {10, 11},
    {10, 11}
  },
  {
    {10, 11},
    {10, 11},
    {10, 11},
    {10, 11},
    {10, 11}
  }
};
☀ R3D ➜ MultiArray<double,R=3> 
{
  {
    {10.0499, 11.0454},
    {10.0125, 11.0114},
    {10, 11},
    {10.0125, 11.0114},
    {10.0499, 11.0454}
  },
  {
    {10.0995, 11.0905},
    {10.0623, 11.0567},
    {10.0499, 11.0454},
    {10.0623, 11.0567},
    {10.0995, 11.0905}
  },
  {
    {10.247, 11.225},
    {10.2103, 11.1915},
    {10.198, 11.1803},
    {10.2103, 11.1915},
    {10.247, 11.225}
  },
  {
    {10.4881, 11.4455},
    {10.4523, 11.4127},
    {10.4403, 11.4018},
    {10.4523, 11.4127},
    {10.4881, 11.4455}
  }
};
☀ R3D_2 ➜ MultiArray<double,R=3> 
{
  {
    {10.0499, 11.0454},
    {10.0125, 11.0114},
    {10, 11},
    {10.0125, 11.0114},
    {10.0499, 11.0454}
  },
  {
    {10.0995, 11.0905},
    {10.0623, 11.0567},
    {10.0499, 11.0454},
    {10.0623, 11.0567},
    {10.0995, 11.0905}
  },
  {
    {10.247, 11.225},
    {10.2103, 11.1915},
    {10.198, 11.1803},
    {10.2103, 11.1915},
    {10.247, 11.225}
  },
  {
    {10.4881, 11.4455},
    {10.4523, 11.4127},
    {10.4403, 11.4018},
    {10.4523, 11.4127},
    {10.4881, 11.4455}
  }
};
```


| ⇦ <br />[Calculus](../calculus/README.md)  | [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br />Vector Calculus<br /><img width=1000/> | ⇨ <br />[MultiArray Calculus](../tensor-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

