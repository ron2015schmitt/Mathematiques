[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.047</h1>](../../../README.md)

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
8.6. [MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)<br>
8.7. [Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)<br>
8.8. [Linear Algebra](../linear-algebra/README.md)<br>
8.9. [Indexing, Masks, Slicing, Sorting, etc.](../sort-mask-slice/README.md)<br>
8.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
8.11. _Numerical / Discretized Mathematical Function Objects_ <br>
8.12. [Functions of Complex Variables](../complex-calculus/README.md)<br>
8.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
8.14. [Tensors](../tensors/README.md)<br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.11. Numerical / Discretized Mathematical Function Objects



Mathématiques provides classes and extensive functionality for single- and multi-variate numerical functions, ie formal mathematical functions over a discretized domain.

<br>

## Introduction
The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. 
With this defintion, we can create a function, e.g. $f(x) = 1 + x + \frac{x^2}{2} + \frac{x^3}{6} + \frac{x^4}{24}$ 
```C++
NumericalFunction<double> f;

auto x = f.coordinates[0];
☀ x ➜ 
{0, 0.25, 0.5, 0.75, 1};

f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
☀ f ➜ {1, 1.28402, 1.64844, 2.11475, 2.70833};

```

To access the data as a Vector, use paretheses, `f()`.  The `NumericalFunction` type is actually a rank 0 (ie. scalar) `CurvilinearField`, which will be discussed in a later section.

```C++
☀ f() ➜ Vector<double> {1, 1.28402, 1.64844, 2.11475, 2.70833};
☀ f()[0] ➜ double 1;
☀ f()[{1, 3}] ➜ Vector<double> {1.28402, 2.11475};
```

We can easily create a second function, e.g. $g(x) = x + 2 f(x) - 4 \frac{df}{dx}$ 

```C++
NumericalFunction<double> g;

g = x + 2*f - 4*d(f);
☀ g ➜ {-2, -2.31738, -2.78646, -3.42676, -4.25};
```


<br>


<br>

## Specifying the function domain
As mentioned above, the default syntax uses the interval $[0,1]$ for the domain. 
Other domains can be explicitly given as shown below.

### Linear equispaced interval
```C++
NumericalFunction<double> f({ Interval<double>::interval(-2, 2, 5) });

auto x = f.coordinates[0];
☀ x ➜ 
{-2, -1, 0, 1, 2};

f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
☀ f ➜ {0.333333, 0.375, 1, 2.70833, 7};

```



### Log-spaced interval
```C++
NumericalFunction<double> f({ PointSequence<double>::log10(1, 10, 11) });

auto x = f.coordinates[0];
☀ x ➜ 
{1, 1.25893, 1.58489, 1.99526, 2.51189, 3.16228, 3.98107, 5.01187, 6.30957, 7.94328, 10};

f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
☀ f ➜ {2.70833, 3.48858, 4.76725, 6.97005, 10.9669, 18.5994, 33.8877, 65.8433, 135.117, 289.9, 644.333};

```



### Arbitrary sequence of points
```C++
NumericalFunction<double> f({ PointSequence<double>({1,10}) });

auto x = f.coordinates[0];
☀ x ➜ 
{1, 10};

f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
☀ f ➜ {2.70833, 644.333};

```



<br>


<br>

## Multivariate functions
Using the syntax `NumericalFunction<NumberType, N>` can create a function of `N` variables., e.g. 
$$H(x,p) = \frac{p^2}{2 m} + \frac{1}{2} k x^2 $$ 
```C++
NumericalFunction<double, 2> H({
  Interval<double>::interval(-1, 1, 5),
  Interval<double>::interval(-10, 10, 5)
})

auto x = H.coordinates[0];
auto p = H.coordinates[1];
double m = 2;
double k = 25;

☀ x ➜ 
{
  {-1, -1, -1, -1, -1},
  {-0.5, -0.5, -0.5, -0.5, -0.5},
  {0, 0, 0, 0, 0},
  {0.5, 0.5, 0.5, 0.5, 0.5},
  {1, 1, 1, 1, 1}
};
☀ p ➜ 
{
  {-10, -5, 0, 5, 10},
  {-10, -5, 0, 5, 10},
  {-10, -5, 0, 5, 10},
  {-10, -5, 0, 5, 10},
  {-10, -5, 0, 5, 10}
};

H = 1/(2*m) * pow(p, 2) + 0.5*k * pow(x, 2);
☀ H ➜ 
{
  {37.5, 18.75, 12.5, 18.75, 37.5},
  {28.125, 9.375, 3.125, 9.375, 28.125},
  {25, 6.25, 0, 6.25, 25},
  {28.125, 9.375, 3.125, 9.375, 28.125},
  {37.5, 18.75, 12.5, 18.75, 37.5}
};
☀ H()(1, 2) ➜ double 3.125;
```

<br>


<br>

## Time-varying functions
The syntax `NumericalFunction<NumberType, N, true>` can be used to include time as an independent variable.
As an example, consider 
$$H(x,p,t) = \frac{p^2}{2 m} + (1 + \frac{1}{2} \cos t)^2 x^2 $$ 
```C++
NumericalFunction<double, 2, true> H({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-10,10,5),
        Interval<double>::interval(0,10,5)
      }); 

auto x = H.coordinates[0];
auto p = H.coordinates[1];
auto t = H.coordinates[2];
double m = 2;

H = 1/(2*m) * pow(p, 2) + pow(1 + 0.5*cos(t)*x, 2);
☀ H ➜ 
{
  {
    {25.25, 26.9616, 25.7365, 25.6834, 27.0151},
    {6.5, 8.2116, 6.98645, 6.9334, 8.26508},
    {0.25, 1.9616, 0.736454, 0.683404, 2.01508},
    {6.5, 8.2116, 6.98645, 6.9334, 8.26508},
    {25.25, 26.9616, 25.7365, 25.6834, 27.0151}
  },
  {
    {25.5625, 26.4407, 25.8632, 25.8342, 26.4635},
    {6.8125, 7.69069, 7.1132, 7.08419, 7.71354},
    {0.5625, 1.44069, 0.863198, 0.834192, 1.46354},
    {6.8125, 7.69069, 7.1132, 7.08419, 7.71354},
    {25.5625, 26.4407, 25.8632, 25.8342, 26.4635}
  },
  {
    {26, 26, 26, 26, 26},
    {7.25, 7.25, 7.25, 7.25, 7.25},
    {1, 1, 1, 1, 1},
    {7.25, 7.25, 7.25, 7.25, 7.25},
    {26, 26, 26, 26, 26}
  },
  {
    {26.5625, 25.6395, 26.1469, 26.1808, 25.6245},
    {7.8125, 6.88954, 7.39686, 7.43083, 6.87447},
    {1.5625, 0.639543, 1.14686, 1.18083, 0.624467},
    {7.8125, 6.88954, 7.39686, 7.43083, 6.87447},
    {26.5625, 25.6395, 26.1469, 26.1808, 25.6245}
  },
  {
    {27.25, 25.3593, 26.3038, 26.3767, 25.3369},
    {8.5, 6.60931, 7.55378, 7.62667, 6.58694},
    {2.25, 0.359314, 1.30378, 1.37667, 0.336939},
    {8.5, 6.60931, 7.55378, 7.62667, 6.58694},
    {27.25, 25.3593, 26.3038, 26.3767, 25.3369}
  }
};
☀ H()(1, 2, 0) ➜ double 0.5625;
```

<br>


<br>

## Specifying the function target set
In all of the previous examples we used real-valued functions. That is, the function values come from the set of real numbers, $\mathbb{R}$. 
The set that a function's values come from is called the *target set* or *codomain*.
The modern definition of a [function](https://en.wikipedia.org/wiki/Function_(mathematics)) is a mapping from a [domain set](https://en.wikipedia.org/wiki/Domain_of_a_function) to a [target/codomain set](https://en.wikipedia.org/wiki/Codomain).
This definition is written symbolically as

$$ f\colon \text{Domain}\rightarrow\text{Target} $$

The syntax

```C++
NumericalFunction<Domain, N, is_time_varying, Target> f;
```
can be used to represent a function with a different target number type.
For example, we can define complex-valued functions and quaternion-valued functions, as shown below


### Complex-valued functions
As an example consider the complex-valued function:

$$ f\colon [0,1]\rightarrow\mathbb{C}$$
$$f(x) = e^{i \pi x} $$

```C++
using namespace mathq::unit_imaginary;
using namespace std::numbers;
NumericalFunction<double, 1, false, std::complex<double>> f;

auto x = f.coordinates[0];

f = roundzero(exp(i*pi*x));
☀ f ➜ {(1,0), (0.707107,0.707107), (0,1), (-0.707107,0.707107), (-1,0)};

```


### Quaternion-valued functions
As an example consider the quaternion-valued function over 2D:

$$ f\colon [0,1] \times [0,1]\rightarrow\mathbb{H}$$
$$ f(x,y) = e^{i \frac{\pi}{2} + j \pi x + k \pi y} $$

```C++
using namespace mathq::unit_imaginary;
using namespace mathq::unit_quaternion;
using namespace std::numbers;
NumericalFunction<double, 2, false, Quaternion<double>> f;

auto x = f.coordinates[0];
auto y = f.coordinates[1];

f = roundzero(exp(i*pi/2 + j*pi*x + k*pi*y));
☀ f ➜ 
{
  {i, -0.184347 + 0.879098*i + 0.439549*k, -0.6057 + 0.56264*i + 0.56264*k, -0.952395 + 0.16911*i + 0.253665*k, -0.932032 + -0.162059*i + -0.324118*k},
  {-0.184347 + 0.879098*i + 0.439549*j, -0.345741 + 0.766143*i + 0.383072*j + 0.383072*k, -0.707107 + 0.471405*i + 0.235702*j + 0.471405*k, -0.979486 + 0.107713*i + 0.0538565*j + 0.161569*k, -0.897136 + -0.192798*i + -0.0963988*j + -0.385595*k},
  {-0.6057 + 0.56264*i + 0.56264*j, -0.707107 + 0.471405*i + 0.471405*j + 0.235702*k, -0.912724 + 0.235892*i + 0.235892*j + 0.235892*k, -0.995329 + -0.046827*i + -0.046827*j + -0.0702405*k, -0.760926 + -0.264887*i + -0.264887*j + -0.529774*k},
  {-0.952395 + 0.16911*i + 0.253665*j, -0.979486 + 0.107713*i + 0.161569*j + 0.0538565*k, -0.995329 + -0.046827*i + -0.0702405*j + -0.046827*k, -0.856549 + -0.220051*i + -0.330077*j + -0.330077*k, -0.464341 + -0.328925*i + -0.493387*j + -0.657849*k},
  {-0.932032 + -0.162059*i + -0.324118*j, -0.897136 + -0.192798*i + -0.385595*j + -0.0963988*k, -0.760926 + -0.264887*i + -0.529774*j + -0.264887*k, -0.464341 + -0.328925*i + -0.657849*j + -0.493387*k, -1.83697e-16 + -0.333333*i + -0.666667*j + -0.666667*k}
};

```


<br>


<br>

## Other functionality

🚧 Further functionality is in development.
* function boundary conditions: constant, periodic, etc
* function causality (needed for differentiation): non-causal (centered derivative stencil), causal (backward derivative stencil), anti-causal (forward derivative stencil)
* Time-varying function object that is a time-series, $f_t(x) = f(x;t)$
* integration
* non-uniform 2D and 3D grids and multi-grid
* 2D and 3D meshes for [Finite Element Method](https://en.wikipedia.org/wiki/Finite_element_method) (triangulation)
* Support for units via [user-defined literals](https://en.cppreference.com/w/cpp/language/user_literal)


<br>



| ⇦ <br />[Common and Special Mathematical Functions](../math-functions/README.md)  | [Introduction with Examples](../README.md)<br />Numerical / Discretized Mathematical Function Objects<br /><img width=1000/> | ⇨ <br />[Functions of Complex Variables](../complex-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

