<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.78-c++17</h1>

<details>

<summary>User Manual</summary>

# [User Manual](../../../README.md)<br>
1. [About](../../../about/README.md)<br>
2. [License](../../../license/README.md)<br>
3. [Status, Planned Work & Release Notes](../../../status-release/README.md)<br>
4. [Description and Example Usage](../../../description-examples/README.md)<br>
5. [Installation](../../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../../first-project/README.md)<br>
7. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
8. [Benchmarks](../../../benchmarks/README.md)<br>
9. [Tests](../../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [7. Usage Guide: Syntax, Data Types, Functions, etc](../../README.md)<br>
7.1. [Usage Guide Notation](../../notation/README.md)<br>
7.2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../../scalars/README.md)<br>
7.3. _Container Types (Vector, Matrix & Tensor)_ <br>
7.4. [Operators](../../operators/README.md)<br>
7.5. [Functions](../../functions/README.md)<br>
7.6. [Linear Algebra](../../linear-algebra/README.md)<br>
7.7. [Indexing, Masks, and Sorting](../../indexing-sorting/README.md)<br>
7.8. [Ranges and Grids](../../ranges-grids/README.md)<br>
7.9. [Calculus](../../calculus/README.md)<br>
7.10. [Vector Calculus](../../vector-calculus/README.md)<br>
7.11. [Tensor Calculus](../../tensor-calculus/README.md)<br>
7.12. [Display of Results](../../display/README.md)<br>
7.13. [FILE I/O](../../file-io/README.md)<br>
7.14. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Container Types (Vector, Matrix & Tensor)</summary>

# [7.3. Container Types (Vector, Matrix & Tensor)](../README.md)<br>

7.3.1. _Vectors_ <br>
7.3.2. [Matrices](../matrix/README.md)<br>
7.3.3. [Tensors](../tensor/README.md)<br>


</details>



# 7.3.1. Vectors



## Introduction
Mathématiques vector variables have type `Vector<E>`, which is a template class that holds a number of elements of type `E`.
The element type `E` can be either a scalar type, such as a real or complex type, or another container type.
The most common case is where `E=double`, ie `Vector<double>`.
Vectors can be defined as fixed-size or dynamically-sized.
This class can be used to create linear algebra vectors, as well as physical vectors such velocity.



<br>

## Declaring and initializing Vector Variables in Mathématiques.
Vectors can be defined as fixed-size or dynamically-sized.
### Fixed size vectors
To declare a fixed-size vector, the size must be a complie-time constant, making it suitable for 2D, 3D, and 3+1D physical vectors, such as velocity, position, force, electric field, etc.  
The syntax for a fixed-size vector is `Vector<double,NE>`, where `NE` is a positive integer.
Vectors can be declared and initialized in a variety of ways:


```C++
using namespace mathq;

auto velocity2D = Vector<double, 2>(0);
auto velocity3D = Vector<double, 3>(0);
auto vector = Vector<double, 11>(0);
☀ velocity2D ➜ Vector<double,NE=2> {0, 0};
☀ velocity3D ➜ Vector<double,NE=3> {0, 0, 0};
☀ vector ➜ Vector<double,NE=11> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

Vector<double, 2> velocity2D(0);
Vector<double, 3> velocity3D(1);
☀ velocity2D ➜ Vector<double,NE=2> {0, 0};
☀ velocity3D ➜ Vector<double,NE=3> {1, 1, 1};

Vector<double, 2> velocity2D;
velocity2D = 4;
Vector<double, 3> velocity3D;
velocity3D = -0.55;
☀ velocity2D ➜ Vector<double,NE=2> {4, 4};
☀ velocity3D ➜ Vector<double,NE=3> {-0.55, -0.55, -0.55};

Vector<double, 2> velocity2D({ 70.5, -30 });
Vector<double, 3> velocity3D({ 10, 0, -15 });
☀ velocity2D ➜ Vector<double,NE=2> {70.5, -30};
Vector<double> v3(3);
☀ velocity3D ➜ Vector<double,NE=3> {10, 0, -15};

Vector<double, 2> velocity2D = Vector<double, 2>({ 70.5, -30 });
Vector<double, 3> velocity3D = Vector<double, 3>({ 70.5, -30 });
☀ velocity2D ➜ Vector<double,NE=2> {70.5, -30};
☀ velocity3D ➜ Vector<double,NE=3> {70.5, -30, -15};
```



<br>

### Grids, Functions, and Vector Calculus


```C++

☀ d1 ➜ mathq::Nabla (Ndims=1, Nwindow=7, periodic=0);
☀ rx ➜ mathq::Domain<double> (-1,1,3);
☀ gridX ➜ Vector<double> {-1, 0, 1};
☀ divX ➜ Vector<double> {1, 1, 1};
☀ gridX2 ➜ Vector<double> {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
☀ gradX2 ➜ Vector<double> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
☀ gradX2_2 ➜ Vector<double> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
☀ sqr(gridX + 2) ➜ TER_Unary Vector<double> {1, 4, 9};
☀ func(-3) ➜ double 1;
☀ fgrid(func, gridX) ➜ Vector<double> {1, 4, 9};
☀ func2(1) ➜ double 2.71828;
☀ fgrid(func2, gridX) ➜ Vector<double> {0.367879, 1, 2.71828};
☀ static_cast<double (*)(double)>(&std::exp)(1) ➜ double 2.71828;
☀ func3(1) ➜ double 2.71828;
☀ fgrid(func3, gridX) ➜ Vector<double> {0.367879, 1, 2.71828};
☀ func4(-3) ➜ double 0.0497871;
☀ fgrid(func4, gridX) ➜ Vector<double> {0.367879, 1, 2.71828};

☀ ry ➜ mathq::Domain<double> (0,3,4);
☀ grid(ry) ➜ Vector<double> {0, 1, 2, 3};
☀ rz ➜ mathq::Domain<double> (10,11,2);
☀ grid(rz) ➜ Vector<double> {10, 11};
☀ gridXY(0) ➜ Matrix<double> { {-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1} };
☀ gridXY(1) ➜ Matrix<double> { {0, 0, 0}, {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };
☀ R ➜ Matrix<double> { {1, 0, 1}, {1.41421, 1, 1.41421}, {2.23607, 2, 2.23607}, {3.16228, 3, 3.16228} };
☀ R2 ➜ Matrix<double> { {1, 0, 1}, {1.41421, 1, 1.41421}, {2.23607, 2, 2.23607}, {3.16228, 3, 3.16228} };
☀ gradXY(0) ➜ Matrix<double> { {-2, 0, 2}, {-0.828427, 0, 0.828427}, {-0.472136, 0, 0.472136}, {-0.324555, 0, 0.324555} };
☀ gradXY(1) ➜ Matrix<double> { {1, 0, 1}, {1.41421, 1, 1.41421}, {2.23607, 2, 2.23607}, {3.16228, 3, 3.16228} };
☀ gradXY(0) ➜ Matrix<double> { {-2, 0, 2}, {-0.828427, 0, 0.828427}, {-0.472136, 0, 0.472136}, {-0.324555, 0, 0.324555} };
☀ gradXY(1) ➜ Matrix<double> { {1, 0, 1}, {1.41421, 1, 1.41421}, {2.23607, 2, 2.23607}, {3.16228, 3, 3.16228} };

☀ gridXYZ(0) ➜ Tensor<double> 
{
  {
    {-1, -1},
    {0, 0},
    {1, 1}
  },
  {
    {-1, -1},
    {0, 0},
    {1, 1}
  },
  {
    {-1, -1},
    {0, 0},
    {1, 1}
  },
  {
    {-1, -1},
    {0, 0},
    {1, 1}
  }
};
☀ gridXYZ(1) ➜ Tensor<double> 
{
  {
    {0, 0},
    {0, 0},
    {0, 0}
  },
  {
    {1, 1},
    {1, 1},
    {1, 1}
  },
  {
    {2, 2},
    {2, 2},
    {2, 2}
  },
  {
    {3, 3},
    {3, 3},
    {3, 3}
  }
};
☀ gridXYZ(2) ➜ Tensor<double> 
{
  {
    {10, 11},
    {10, 11},
    {10, 11}
  },
  {
    {10, 11},
    {10, 11},
    {10, 11}
  },
  {
    {10, 11},
    {10, 11},
    {10, 11}
  },
  {
    {10, 11},
    {10, 11},
    {10, 11}
  }
};
☀ R3D ➜ Tensor<double,R=3> 
{
  {
    {10.0499, 11.0454},
    {10, 11},
    {10.0499, 11.0454}
  },
  {
    {10.0995, 11.0905},
    {10.0499, 11.0454},
    {10.0995, 11.0905}
  },
  {
    {10.247, 11.225},
    {10.198, 11.1803},
    {10.247, 11.225}
  },
  {
    {10.4881, 11.4455},
    {10.4403, 11.4018},
    {10.4881, 11.4455}
  }
};
☀ R3D_2 ➜ Tensor<double,R=3> 
{
  {
    {10.0499, 11.0454},
    {10, 11},
    {10.0499, 11.0454}
  },
  {
    {10.0995, 11.0905},
    {10.0499, 11.0454},
    {10.0995, 11.0905}
  },
  {
    {10.247, 11.225},
    {10.198, 11.1803},
    {10.247, 11.225}
  },
  {
    {10.4881, 11.4455},
    {10.4403, 11.4018},
    {10.4881, 11.4455}
  }
};



<br>

### Runtime-sized and Dynamically-sized vectors



☀ sizeof(array<double, 2>)/sizeof(double) ➜ 2;
☀ sizeof(Vector<double, 2>)/sizeof(double) ➜ 2;

☀ sizeof(array<double, 100>)/sizeof(double) ➜ 100;
☀ sizeof(Vector<double, 100>)/sizeof(double) ➜ 100;

☀ sizeof(array<array<double, 2>, 100>)/sizeof(double) ➜ 200;
☀ sizeof(Vector<Vector<double, 2>, 100>)/sizeof(double) ➜ 200;
```

<br>

## Size of Vectors

<br>

## Arithmetic Operators
The 4 fundamental arithmetic operators can be used with quaternions.
Mathématiques supports the four arithmetic operators for quaternions:

```C++
```
## Methods
Assume `q`  is of type `Quaternion<D>` with 

> _q_ = _a_ + _b_ **i** + _c_ **j** + _d_ **k** 

The scalar+vector form of q is 

>  _q_ = _a_ + **v**. 

The polar form of q is: 

> _q_ = ||_q_|| ( cos _φ_ + **n̂** sin _φ_ ). 

where  

> _φ_ ≐  cos<sup-1></sup>( _a_/||_q_|| ). 

and  

> **n̂** ≐ **v**/||**v**||

Note that for complex numbers **n̂** = +i or -i.  

| syntax | modifies q? | description | 
| :---: | :---: | :---: | 
| `Quaternion<D> invert()` | yes | q := 1/q, returns `q` | 
| `Quaternion<D> negate()` | yes | q := -q, returns `q` | 
| `Quaternion<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | 
| `D real()` | no | returns the real part of `q` | 
| `D imag()` | no | returns the i-component part of `q` | 
| `D jmag()` | no | returns the j-component part of `q` | 
| `D kmag()` | no | returns the k-component of `q` | 
| `D abs()` | no | returns \|\|_q_\|\|, the magnitude of `q` | 
| `D normsqr()` | no | returns the magnitude-squared of `q` | 
| `D scalar()` | no | same as real() | 
| `Quaternion<D> normalized()` | no | returns _q_/\|\|_q_\|\| | 
| `Vector<D,3> vector()` | no | returns **v**, the vector part of `q` | 
| `Vector<D,3> unitvector()` | no | returns **n̂**, the vector part of `q` normalized to 1 | 
| `D vabs()` | no | returns, _v_=\|\|**v**\|\| the magnitude of `q.vector()` | 
| `D vnormsqr()` | no | returns \|\|**v**\|\|<sup>2</sup> | 
| `D angle()` | no | returns φ as defined above | 
| `std::tuple<D, D, Vector<D, 3>> polar()` | no | returns { \|\|_q_\|\|, φ, **n̂** } as a tuple | 
| `Matrix<std::complex<D>, 2, 2> matrix2by2()` | no | returns **Q**, the 2x2 matrix form<sup>1</sup> of _q_ | 

1. **Q** = [  _a_ + **i** _b_,  _c_ + **i** _d_; 
             -_c_ + **i** _d_,  _a_ - **i** _b_  ]

A few examples are shown below.

```C++
## Functions

Mathématiques supports several quaternion functions.  These are listed in detail in the section on functions.
Below are a few examples.



```C++
```
## Containers of Quaternions

Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>` can have quaternions as their underlying type.
Below are examples of container math with quaternions.  Mixed math is allowed.


```C++
```


| ⇦ <br />  | [Container Types (Vector, Matrix & Tensor)](../README.md)<br />Vectors<br /><img width=1000/> | ⇨ <br />[Matrices](../matrix/README.md)   |
| ------------ | :-------------------------------: | ------------ |

