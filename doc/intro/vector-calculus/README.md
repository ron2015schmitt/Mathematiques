[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.043</h1>](../../../README.md)

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
8.11. [Numerical / Discretized Mathematical Function Objects](../numerical-functions/README.md)<br>
8.12. [Functions of Complex Variables](../complex-calculus/README.md)<br>
8.13. _Vector Calculus and Curvilinear Coordinates_ <br>
8.14. [Tensors](../tensors/README.md)<br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.13. Vector Calculus and Curvilinear Coordinates


Mathématiques provides classes and extensive functionality for curvilinear coordinate systems as well as scalar, vector, and rank >=2 functions using these coordinates.
### Fixed-length Vectors
```C++
Vector<double, 3> v{ 1,2,3 };

☀ v ➜ Vector<double,3> {1, 2, 3};
v = tuple{ 12, 1, x };
☀ I ➜ unsigned long 0;
☀ display::getTypeName(val) ➜ int;
☀ display::getTypeName((*this)[I]) ➜ double;
done with assignment
recurse
☀ I ➜ unsigned long 1;
☀ display::getTypeName(val) ➜ int;
☀ display::getTypeName((*this)[I]) ➜ double;
done with assignment
recurse
☀ I ➜ unsigned long 2;
☀ display::getTypeName(val) ➜ double;
☀ display::getTypeName((*this)[I]) ➜ double;
done with assignment
done
done
done
returned
☀ v ➜ Vector<double,3> {12, 1, 3.4};
☀ expr(1, 2, v) ➜ expr<> {1,2,{12, 1, 3.4}};
☀ realize(1) ➜ int 1;
☀ realize(v) ➜ Vector<double,3> {12, 1, 3.4};
☀ realize(2*v) ➜ Vector<double> {24, 2, 6.8};
☀ Realize_Type<decltype(2*v)>::Type() ➜ Vector<double> {};
☀ expr{ 1, 2, 2*v } ➜ expr<> {1,2,{24, 2, 6.8}};
```

<br>

## Curvilinear Coordinates

### Cartesian Coordinates
```C++
CartesianCoords<double, 2> coords({ Interval<double>::interval(-1,1,5), Interval<double>::interval(2,3,3), });
CurvilinearField<double, 0, decltype(coords)> field0(coords);
auto& x = coords.x();
auto& y = coords.y();
field0 = -3*x + 2*y;
☀ field0 ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {7, 8, 9},
  {5.5, 6.5, 7.5},
  {4, 5, 6},
  {2.5, 3.5, 4.5},
  {1, 2, 3}
};
```


### Polar Coordinates
```C++
PolarCoords<double> coords({ Interval<double>::interval(-1,1,5), Interval<double>::interval(2,3,3), });
```


### Polar Coordinates
```C++
PolarCoords<double, true> coords({ Interval<double>::interval(-1,1,5), Interval<double>::interval(2,3,3), Interval<double>::interval(0,1,3), });
```


<br>

## Vector fields

### TEST
```C++
CartesianCoords<double, 2, false> coords({ Interval<double>::interval(-1,1,5), Interval<double>::interval(2,3,3), });
CurvilinearField<double, 0, decltype(coords)> v(coords);
auto& x = coords.x();
auto& y = coords.y();
v = -3*x + 2*y;
☀ v ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {7, 8, 9},
  {5.5, 6.5, 7.5},
  {4, 5, 6},
  {2.5, 3.5, 4.5},
  {1, 2, 3}
};
```


<br>

## Fields of any rank

### TEST
```C++
CartesianCoords<double, 2, false> coords({ Interval<double>::interval(-1,1,5), Interval<double>::interval(2,3,3), });
CurvilinearField<double, 0, decltype(coords)> field0(coords);
auto& x = coords.x();
auto& y = coords.y();
field0 = -3*x + 2*y;
☀ field0 ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {7, 8, 9},
  {5.5, 6.5, 7.5},
  {4, 5, 6},
  {2.5, 3.5, 4.5},
  {1, 2, 3}
};
```


<br>

## Maxwell's Equations

### TEST
```C++
size_t Npts = 10;
CartesianCoords<double, 3, true> coords({ Interval<double>::interval(-1,1,Npts), Interval<double>::interval(-1,1,Npts), Interval<double>::interval(-1,1,Npts), Interval<double>::interval(0,1,Npts), });
auto& x = coords.x();
auto& y = coords.y();
auto& z = coords.z();
auto& t = coords.t();
using namespace std::numbers;
using namespace mathq::unit_imaginary;
Nabla nabla;
const double A0 = 1;
const double omega = 2;
const double c = 299792458;
const double kx = 0;
const double ky = 2;
const double kz = 1;
const Vector<double, 3> k{ kx, ky, kz };
const double Phi0 = A0 * pow(c, 2) * ky / omega;
using MyScalarField = CurvilinearField<std::complex<double>, 0, decltype(coords)>;
MyScalarField Phi(coords);
Phi = Phi0 * exp(i*(ky*y - omega*t));
CurvilinearField<std::complex<double>, 1, decltype(coords)> A(coords);
A = expr{ A0 * exp(i*(kz*z - omega*t)), A0 * exp(i*(ky*y - omega*t)), 0 };
hello
☀ I ➜ unsigned long 0;
☀ display::getTypeName(val) ➜ MultiArray<std::complex<double>, rank=4>;
☀ display::getTypeName((*this)[I]) ➜ MultiArray<std::complex<double>, rank=4>;
done with assignment
recurse
☀ I ➜ unsigned long 1;
☀ display::getTypeName(val) ➜ MultiArray<std::complex<double>, rank=4>;
☀ display::getTypeName((*this)[I]) ➜ MultiArray<std::complex<double>, rank=4>;
done with assignment
recurse
☀ I ➜ unsigned long 2;
☀ display::getTypeName(val) ➜ int;
☀ display::getTypeName((*this)[I]) ➜ MultiArray<std::complex<double>, rank=4>;
done with assignment
done
done
done
returned
goodbye
OK
auto result1 = i*k|A;
MyScalarField result2 = div(A);
MyScalarField dPhi_dt;
dPhi_dt = pd(Phi, 3);
MyScalarField result3;
result3 = -1./(c*c) * dPhi_dt;
☀ result1(0, 0, 0, 2) ➜ std::complex<double> (1.28407,-1.53335);
☀ result2()(0, 0, 0, 2) ➜ std::complex<double> (1.28607,-1.53275);
☀ result3()(0, 0, 0, 2) ➜ std::complex<double> (1.28407,-1.53335);
☀ alltrue(approx(result1, result2(), 0.015)) ➜ bool true;
☀ numtrue(approx(result1, result2(), 0.015)) ➜ unsigned long 10000;
☀ alltrue(approx(result1, result3(), 0.015)) ➜ bool true;
☀ numtrue(approx(result1, result3(), 0.015)) ➜ unsigned long 10000;
```



| ⇦ <br />[Functions of Complex Variables](../complex-calculus/README.md)  | [Introduction with Examples](../README.md)<br />Vector Calculus and Curvilinear Coordinates<br /><img width=1000/> | ⇨ <br />[Tensors](../tensors/README.md)   |
| ------------ | :-------------------------------: | ------------ |

