[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.039</h1>](../../../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../../../README.md)<br>
Chapter 1. [License](../../../license/README.md)<br>
Chapter 2. [About](../../../about/README.md)<br>
Chapter 3. [Why?](../../../why/README.md)<br>
Chapter 4. [Objectives](../../../objectives/README.md)<br>
Chapter 5. [Versioning](../../../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../../../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../../../development-schedule/README.md)<br>
Chapter 8. [Introduction with Examples](../../../intro/README.md)<br>
Chapter 9. [Installation](../../../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../../../first-project/README.md)<br>
Chapter 11. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
Chapter 12. [Benchmarks](../../../benchmarks/README.md)<br>
Chapter 13. [Tests](../../../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [11. Usage Guide: Syntax, Data Types, Functions, etc](../../README.md)<br>
11.1. [Usage Guide Notation](../../notation/README.md)<br>
11.2. [Scalar Types (Real, Imaginary, Complex & Quaternion)](../../numbers/README.md)<br>
11.3. _Container Types (Vector, Matrix & MultiArray)_ <br>
11.4. [Operators](../../operators/README.md)<br>
11.5. [Functions](../../functions/README.md)<br>
11.6. [Linear Algebra](../../linear-algebra/README.md)<br>
11.7. [Indexing, Masks, and Sorting](../../indexing-sorting/README.md)<br>
11.8. [Ranges and Grids](../../ranges-grids/README.md)<br>
11.9. [Calculus](../../calculus/README.md)<br>
11.10. [Vector Calculus](../../vector-calculus/README.md)<br>
11.11. [MultiArray Calculus](../../tensor-calculus/README.md)<br>
11.12. [Display of Results](../../display/README.md)<br>
11.13. [FILE I/O](../../file-io/README.md)<br>
11.14. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Container Types (Vector, Matrix & MultiArray)</summary>

# [11.3. Container Types (Vector, Matrix & MultiArray)](../README.md)<br>

11.3.1. _Vector_ <br>
11.3.2. [Matrix](../matrix/README.md)<br>
11.3.3. [MultiArray](../multi-array/README.md)<br>


</details>



# 11.3.1. Vector



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
☀ velocity2D ➜ Vector<double,2> {0, 0};
☀ velocity3D ➜ Vector<double,3> {0, 0, 0};
☀ vector ➜ Vector<double,11> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

Vector<double, 2> velocity2D(0);
Vector<double, 3> velocity3D(1);
☀ velocity2D ➜ Vector<double,2> {0, 0};
☀ velocity3D ➜ Vector<double,3> {1, 1, 1};

Vector<double, 2> velocity2D;
velocity2D = 4;
Vector<double, 3> velocity3D;
velocity3D = -0.55;
☀ velocity2D ➜ Vector<double,2> {4, 4};
☀ velocity3D ➜ Vector<double,3> {-0.55, -0.55, -0.55};

Vector<double, 2> velocity2D({ 70.5, -30 });
Vector<double, 3> velocity3D({ 10, 0, -15 });
☀ velocity2D ➜ Vector<double,2> {70.5, -30};
Vector<double> v3(3);
☀ velocity3D ➜ Vector<double,3> {10, 0, -15};

Vector<double, 2> velocity2D = Vector<double, 2>({ 70.5, -30 });
Vector<double, 3> velocity3D = Vector<double, 3>({ 70.5, -30 });
☀ velocity2D ➜ Vector<double,2> {70.5, -30};
☀ velocity3D ➜ Vector<double,3> {70.5, -30, -15};
```



<br>

### Runtime-sized and Dynamically-sized vectors


```C++

☀ sizeof(array<double, 2>)/sizeof(double) ➜ 2;
☀ sizeof(Vector<double, 2>)/sizeof(double) ➜ 2;

☀ sizeof(array<double, 100>)/sizeof(double) ➜ 100;
☀ sizeof(Vector<double, 100>)/sizeof(double) ➜ 100;

☀ sizeof(array<array<double, 2>, 100>)/sizeof(double) ➜ 200;
☀ sizeof(Vector<Vector<double, 2>, 100>)/sizeof(double) ➜ 200;
```

<br>

## Size of Vectors


```C++
```

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
```
## Functions

Mathématiques supports several quaternion functions.  These are listed in detail in the section on functions.
Below are a few examples.



```C++
```
## Containers of Quaternions

Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `MultiArray<D>` can have quaternions as their underlying type.
Below are examples of container math with quaternions.  Mixed math is allowed.


```C++
```


| ⇦ <br />  | [Container Types (Vector, Matrix & MultiArray)](../README.md)<br />Vector<br /><img width=1000/> | ⇨ <br />[Matrix](../matrix/README.md)   |
| ------------ | :-------------------------------: | ------------ |

