<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.40.26-c++17</h1>

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

☀ d1 ➜ mathq::Nabla (Nwindow=7);

RealSet<double> rs(-2, +2, 5);
☀ rs ➜ mathq::RealSet<double> {interval=[-2, 2], N=5, scale=LINEAR, gridState=deflated};
☀ rs.getGrid() ➜ Vector<double> {-2, -1, 0, 1, 2};
☀ rs.hasInflatedGrid_() ➜ bool 1;

RealSet<double> rs1(-2, +3, 5, GridScale::LINEAR, true, false);
☀ rs1 ➜ mathq::RealSet<double> {interval=[-2, 3], N=5, scale=LINEAR, gridState=deflated};
☀ rs1.getGrid() ➜ Vector<double> {-2, -1, 0, 1, 2};
☀ rs1.hasInflatedGrid_() ➜ bool 1;

RealSet<double> rs2 = RealSet<double>::realLine();
☀ rs2 ➜ mathq::RealSet<double> {interval=[-inf, inf], N=0, scale=LINEAR, gridState=deflated};

RealSet<double> rs3(10, 1e5, 10, GridScale::LOG);
☀ rs3 ➜ mathq::RealSet<double> {interval=[10, 100000], N=10, scale=LOG, gridState=deflated};
☀ rs3.getGrid() ➜ Vector<double> {10, 27.8256, 77.4264, 215.443, 599.484, 1668.1, 4641.59, 12915.5, 35938.1, 100000};
☀ mathq::log10(rs3.getGrid()) ➜ TER_Unary Vector<double> {1, 1.44444, 1.88889, 2.33333, 2.77778, 3.22222, 3.66667, 4.11111, 4.55556, 5};
☀ rs3.hasInflatedGrid_() ➜ bool 1;

auto rs4 = RealSet<double>::point(2.5);
☀ rs4 ➜ mathq::RealSet<double> {point=2.5, gridState=deflated};
☀ rs4.getGrid() ➜ Vector<double> {2.5};
☀ rs4.hasInflatedGrid_() ➜ bool 1;

RealSet<double> rx(-10, +10, 3);
☀ rx ➜ mathq::RealSet<double> {interval=[-10, 10], N=3, scale=LINEAR, gridState=deflated};

RealSet<double> ry(-20, 20, 5, GridScale::LINEAR);
☀ ry ➜ mathq::RealSet<double> {interval=[-20, 20], N=5, scale=LINEAR, gridState=deflated};
☀ ry.getGrid() ➜ Vector<double> {-20, -10, 0, 10, 20};
RealSet<double> rz(30, 33, 4, GridScale::LINEAR);
☀ rz ➜ mathq::RealSet<double> {interval=[30, 33], N=4, scale=LINEAR, gridState=deflated};
☀ rz.getGrid() ➜ Vector<double> {30, 31, 32, 33};

RealMultiSet<double, 2> setXY({ rx, ry });
☀ setXY ➜ RealMultiSet<double,NDIMS=2> { gridState=inflated, {
  {interval=[-10, 10], N=3, scale=LINEAR, gridState=deflated}, 
  {interval=[-20, 20], N=5, scale=LINEAR, gridState=inflated}
}};
☀ hasInflatedGrids_() ➜ bool 0;
inflategrids
☀ gdims ➜ Dimensions {3, 5};
☀ setXY.getGrid()[0] ➜ Matrix<double> { {-10, -10, -10, -10, -10}, {0, 0, 0, 0, 0}, {10, 10, 10, 10, 10} };
☀ hasInflatedGrids_() ➜ bool 1;
☀ setXY.getGrid()[1] ➜ Matrix<double> { {-20, -10, 0, 10, 20}, {-20, -10, 0, 10, 20}, {-20, -10, 0, 10, 20} };

RealMultiSet<double, 3> setXYZ({ rx, ry, rz });
☀ setXYZ ➜ RealMultiSet<double,NDIMS=3> { gridState=inflated, {
  {interval=[-10, 10], N=3, scale=LINEAR, gridState=deflated}, 
  {interval=[-20, 20], N=5, scale=LINEAR, gridState=inflated}, 
  {interval=[30, 33], N=4, scale=LINEAR, gridState=inflated}
}};
☀ hasInflatedGrids_() ➜ bool 0;
inflategrids
☀ gdims ➜ Dimensions {3, 5, 4};
☀ X ➜ MultiArray<double,R=3> 
{
  {
    {-10, -10, -10, -10},
    {-10, -10, -10, -10},
    {-10, -10, -10, -10},
    {-10, -10, -10, -10},
    {-10, -10, -10, -10}
  },
  {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  },
  {
    {10, 10, 10, 10},
    {10, 10, 10, 10},
    {10, 10, 10, 10},
    {10, 10, 10, 10},
    {10, 10, 10, 10}
  }
};
☀ Y ➜ MultiArray<double,R=3> 
{
  {
    {-20, -20, -20, -20},
    {-10, -10, -10, -10},
    {0, 0, 0, 0},
    {10, 10, 10, 10},
    {20, 20, 20, 20}
  },
  {
    {-20, -20, -20, -20},
    {-10, -10, -10, -10},
    {0, 0, 0, 0},
    {10, 10, 10, 10},
    {20, 20, 20, 20}
  },
  {
    {-20, -20, -20, -20},
    {-10, -10, -10, -10},
    {0, 0, 0, 0},
    {10, 10, 10, 10},
    {20, 20, 20, 20}
  }
};
☀ Z ➜ MultiArray<double,R=3> 
{
  {
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33}
  },
  {
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33}
  },
  {
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33},
    {30, 31, 32, 33}
  }
};

☀ v1 ➜ PolarCoordSystem::Coords<double> (r=10, φ=1.0472);
☀ polar ➜ PolarCoordSystem<double> { 
  coords=(r, 𝜑: periodic)
};
☀ phi/pi ➜ double 0.333333;
☀ polar.x(10, phi) ➜ double 5;
☀ polar.y(10, phi) ➜ double 8.66025;
☀ polar.J(10, phi) ➜ double 10;
☀ polar.g(10, phi) ➜ Matrix<double,NR=2,NC=2> { {1, 0}, {100, 0} };
☀ polar.r(5, 8.66025) ➜ double 10;
☀ polar.phi(5, 8.66025)/pi ➜ double 0.333333;
☀ polar.r_vec_cart(1,0) ➜ Vector<double,NE=2> {1, 0};
☀ polar.r_vec_cart(1,1) ➜ Vector<double,NE=2> {0.707107, 0.707107};
☀ polar.r_vec_cart(0,1) ➜ Vector<double,NE=2> {0, 1};
☀ polar.r_vec_cart(-1,0) ➜ Vector<double,NE=2> {-1, 0};
```


| ⇦ <br />[Calculus](../calculus/README.md)  | [Usage Guide: Syntax, Data Types, Functions, etc](../README.md)<br />Vector Calculus<br /><img width=1000/> | ⇨ <br />[MultiArray Calculus](../tensor-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

