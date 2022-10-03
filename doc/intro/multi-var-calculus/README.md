[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.025</h1>](../../../README.md)

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
8.11. _NumericalFunction_ <br>
8.12. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
8.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
8.14. [Tensors](../tensors/README.md)<br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.11. NumericalFunction



Mathématiques provides classes and extensive functionality for single- and multi-variate numerical functions.
## Introduction
The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. 
With this defintion, we can create a function, e.g. $f(x) = 1 + x + \frac{x^2}{2} + \frac{x^3}{6} + \frac{x^4}{24}$ 
```C++
NumericalFunction<double> f;

auto x = f.coordinates[0];
☀ x ➜ MultiArray_RepeatVector<double, rank=1> vector_index=0, dims=5
{0, 0.25, 0.5, 0.75, 1};

f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
☀ f ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=1,TimeCoord=false>> {1, 1.28402, 1.64844, 2.11475, 2.70833};

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
☀ g ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=1,TimeCoord=false>> {-2, -2.31738, -2.78646, -3.42676, -4.25};
```


<br>

## Specifying the function domain
As mentioned above, the default syntax uses the interval $[0,1]$ for the domain. 
Other domains can be explicitly given as shown below.

### Linear equispaced interval
```C++
NumericalFunction<double> f({ Interval<double>::interval(-2, 2, 5) });

auto x = f.coordinates[0];
☀ x ➜ MultiArray_RepeatVector<double, rank=1> vector_index=0, dims=5
{-2, -1, 0, 1, 2};

f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
☀ f ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=1,TimeCoord=false>> {0.333333, 0.375, 1, 2.70833, 7};

```



### Log-spaced interval
```C++
NumericalFunction<double> f({ PointSequence<double>::log10(1, 10, 11) });

auto x = f.coordinates[0];
☀ x ➜ MultiArray_RepeatVector<double, rank=1> vector_index=0, dims=11
{1, 1.25893, 1.58489, 1.99526, 2.51189, 3.16228, 3.98107, 5.01187, 6.30957, 7.94328, 10};

f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
☀ f ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=1,TimeCoord=false>> {2.70833, 3.48858, 4.76725, 6.97005, 10.9669, 18.5994, 33.8877, 65.8433, 135.117, 289.9, 644.333};

```



### Arbitrary sequence of points
```C++
NumericalFunction<double> f({ PointSequence<double>({1,10}) });

auto x = f.coordinates[0];
☀ x ➜ MultiArray_RepeatVector<double, rank=1> vector_index=0, dims=2
{1, 10};

f = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
☀ f ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=1,TimeCoord=false>> {2.70833, 644.333};

```



<br>

## Specifying the function target set
The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. 
With this defintion, we can create a function, e.g. $f(x) = 1 + x + \frac{x^2}{2} + \frac{x^3}{6} + \frac{x^4}{24}$ 

<br>

## Specifying the function boundary conditions
The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. 
With this defintion, we can create a function, e.g. $f(x) = 1 + x + \frac{x^2}{2} + \frac{x^3}{6} + \frac{x^4}{24}$ 

<br>

## Multivariate functions
The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. 
With this defintion, we can create a function, e.g. $f(x) = 1 + x + \frac{x^2}{2} + \frac{x^3}{6} + \frac{x^4}{24}$ 
```C++
NumericalFunction<double, 2> H({
  Interval<double>::interval(-1, 1, 5),
  Interval<double>::interval(-10, 10, 5)
})

☀ H ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0}
};
auto x = H.coordinates[0];
auto p = H.coordinates[1];
double m = 2;
double k = 25;

☀ x ➜ MultiArray_RepeatVector<double, rank=2> vector_index=0, dims=5⨯5
{
  {-1, -1, -1, -1, -1},
  {-0.5, -0.5, -0.5, -0.5, -0.5},
  {0, 0, 0, 0, 0},
  {0.5, 0.5, 0.5, 0.5, 0.5},
  {1, 1, 1, 1, 1}
};
☀ p ➜ MultiArray_RepeatVector<double, rank=2> vector_index=1, dims=5⨯5
{
  {-10, -5, 0, 5, 10},
  {-10, -5, 0, 5, 10},
  {-10, -5, 0, 5, 10},
  {-10, -5, 0, 5, 10},
  {-10, -5, 0, 5, 10}
};

H = 1/(2*m) * pow(p, 2) + 0.5*k * pow(x, 2);
☀ H ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {37.5, 18.75, 12.5, 18.75, 37.5},
  {28.125, 9.375, 3.125, 9.375, 28.125},
  {25, 6.25, 0, 6.25, 25},
  {28.125, 9.375, 3.125, 9.375, 28.125},
  {37.5, 18.75, 12.5, 18.75, 37.5}
};
```

<br>

## Time-varying functions
The syntax `NumericalFunction<NumberType>` can be used to represent a function of one real variable of type `NumberType`.  This default syntax uses the interval $[0,1]$ for the function domain. 
With this defintion, we can create a function, e.g. $f(x) = 1 + x + \frac{x^2}{2} + \frac{x^3}{6} + \frac{x^4}{24}$ 

<br>

## Other functionality
Integrals
Support for units via [user-defined literals](https://en.cppreference.com/w/cpp/language/user_literal)

<br>



| ⇦ <br />[Common and Special Mathematical Functions](../math-functions/README.md)  | [Introduction with Examples](../README.md)<br />NumericalFunction<br /><img width=1000/> | ⇨ <br />[Calculus on Complex Number Domains](../complex-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

