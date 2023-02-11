<h1 style='border: 2px solid; text-align: center'><a href='../../../README.md'>Mathématiques 0.42.8</a></h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Versioning](../versioning/README.md)<br>
Chapter 4. [Status & Release Notes](../status-release/README.md)<br>
Chapter 5. [Upcoming Development](../development-schedule/README.md)<br>
Chapter 6. _Introduction with Examples_ <br>
Chapter 7. [Installation](../installation/README.md)<br>
Chapter 8. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 9. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 10. [Benchmarks](../benchmarks/README.md)<br>
Chapter 11. [Tests](../test/README.md)<br>
Chapter 12. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [6. Introduction with Examples](../README.md)<br>
6.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
6.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
6.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
6.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
6.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
6.6. [MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)<br>
6.7. [Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)<br>
6.8. [Linear Algebra](../linear-algebra/README.md)<br>
6.9. [Indexing, Masks, Slicing, Sorting, etc.](../sort-mask-slice/README.md)<br>
6.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
6.11. [Numerical / Discretized Mathematical Function Objects](../numerical-functions/README.md)<br>
6.12. [Functions of Complex Variables](../complex-calculus/README.md)<br>
6.13. _Vector Calculus and Curvilinear Coordinates_ <br>
6.14. [Tensors](../tensors/README.md)<br>
6.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.13. Vector Calculus and Curvilinear Coordinates


Mathématiques provides classes and extensive functionality for curvilinear coordinate systems as well as scalar, vector, and rank >=2 functions using these coordinates.

<br>

## Curvilinear Coordinates
Currently Cartesian and polar coordinates are supported.
To save memory, the coordinate grids are stored in a special type of multiarray that only contains a vector, which is then repeated.
In 3D+Time, this reduces the storage from $N^4$ to $N$. For 1000 points this is a reduction from $10^{12}$ data points to $1000$ data points for each coordinate.

### Cartesian Coordinates
```C++
CartesianCoords<double, 2> coords({
  Interval<double>::interval(-2,2,5),  // x domain
  Interval<double>::interval(2,3,3)    // y domain
})
☀ coords.x() ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {-2, -2, -2},
  {-1, -1, -1},
  {0, 0, 0},
  {1, 1, 1},
  {2, 2, 2}
};
☀ coords.y() ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {2, 2.5, 3},
  {2, 2.5, 3},
  {2, 2.5, 3},
  {2, 2.5, 3},
  {2, 2.5, 3}
};
```


### Polar Coordinates
```C++
using namespace std::numbers;
PolarCoords<double> coords({
  Interval<double>::interval(0,1,5),  // r domain
  Interval<double>::c_interval_o(0,2*pi,4)    // phi domain
})
☀ coords.r() ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {0, 0, 0, 0},
  {0.25, 0.25, 0.25, 0.25},
  {0.5, 0.5, 0.5, 0.5},
  {0.75, 0.75, 0.75, 0.75},
  {1, 1, 1, 1}
};
☀ coords.phi() ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {0, 1.5708, 3.14159, 4.71239},
  {0, 1.5708, 3.14159, 4.71239},
  {0, 1.5708, 3.14159, 4.71239},
  {0, 1.5708, 3.14159, 4.71239},
  {0, 1.5708, 3.14159, 4.71239}
};
```

NOTE: The above syntax `Interval<double>::c_interval_o` specifies the interval $[0,2\pi)$, so that the point $\phi = 2 \pi$ is not included (since it is the same point in space as $\phi = 0$).

<br>

## Vector fields
Now that we have coordinate systems, we can create vector fields using the `CurvilinearField` class. 

$$\vec{v}(x,y) \hspace1ex = -3x \hspace0.5ex \hat{x} + 2y \hspace0.5ex \hat{y} $$


```C++
CartesianCoords<double, 2, false> coords({ Interval<double>::interval(-2,2,5), Interval<double>::interval(2,3,3), });

auto& x = coords.x();
auto& y = coords.y();

CurvilinearField<double, 1, decltype(coords)> v(coords);
v = expr{ -3*x, 2*y };
☀ v ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=2,TimeCoord=false>> {
{
  {6, 6, 6},
  {3, 3, 3},
  {-0, -0, -0},
  {-3, -3, -3},
  {-6, -6, -6}
}, 
{
  {4, 5, 6},
  {4, 5, 6},
  {4, 5, 6},
  {4, 5, 6},
  {4, 5, 6}
}};
```


<br>

## Fields of any rank
In fact, the `CurvilinearField` class supports fields of any rank: scalar=0, vector=1, matrix=2, etc. 


Define 2D Cartesian Coordinates

```C++
CartesianCoords<double, 2, false> coords({ Interval<double>::interval(-2,2,5), Interval<double>::interval(2,3,3), });
auto& x = coords.x();
auto& y = coords.y();
```


<br>

Scalar field: $$f(x,y) \hspace1ex = 2 x^2 + y^2 $$

```C++
CurvilinearField<double, 0, decltype(coords)> scalar_field(coords);
scalar_field = 2*pow(x, 2) + pow(y, 2);
☀ scalar_field ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {12, 14.25, 17},
  {6, 8.25, 11},
  {4, 6.25, 9},
  {6, 8.25, 11},
  {12, 14.25, 17}
};
```


<br>

Vector field: $$\vec{v}(x,y) \hspace1ex = -3x \hspace0.5ex \hat{x} + 2y \hspace0.5ex \hat{y} $$

```C++
CurvilinearField<double, 1, decltype(coords)> vector_field(coords);
vector_field = expr{ -3*x, 2*y };
☀ vector_field ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=2,TimeCoord=false>> {
{
  {6, 6, 6},
  {3, 3, 3},
  {-0, -0, -0},
  {-3, -3, -3},
  {-6, -6, -6}
}, 
{
  {4, 5, 6},
  {4, 5, 6},
  {4, 5, 6},
  {4, 5, 6},
  {4, 5, 6}
}};
```


<br>

"Matrix" (rank 2 tensor) field: $$\stackrel{\leftrightarrow}{T}(x,y) \hspace1ex = \vec{v} \vec{v} $$

```C++
CurvilinearField<double, 2, decltype(coords)> tensor_field(coords);
tensor_field = vector_field & vector_field;
☀ tensor_field ➜ CurvilinearField<double,2,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {
{
  {36, 36, 36},
  {9, 9, 9},
  {0, 0, 0},
  {9, 9, 9},
  {36, 36, 36}
}, 
{
  {24, 30, 36},
  {12, 15, 18},
  {-0, -0, -0},
  {-12, -15, -18},
  {-24, -30, -36}
}},
  {
{
  {24, 30, 36},
  {12, 15, 18},
  {-0, -0, -0},
  {-12, -15, -18},
  {-24, -30, -36}
}, 
{
  {16, 25, 36},
  {16, 25, 36},
  {16, 25, 36},
  {16, 25, 36},
  {16, 25, 36}
}}
};
```

Note: the class `NumericalFunction` from the previous section is actually just a type alias for `CurvilinearField<double, 0>`

<br>

## Grad, Div, Curl
<table>
<thead>
<tr>
<td align="center"><b>function</b></td>
<td align="center"><b>operator form</b></td>
<td align="center"><b>operation</b></td>
<td align="center"><b>standard notation</b></td>
</tr>
</thead>
<tbody>

<!-- grad -->
<tr>
<td align="center"> 

```C++
grad(f)
```
  
</td>
<td align="center"> 
  
```C++
nabla & f
```
  
</td>
<td align="center">gradient</td>
<td align="center">
   
$$
\vec \nabla f
$$

</td>
</tr>

<!-- div  -->

<tr>
<td align="center"> 

```C++
div(A)
```

</td>
<td align="center"> 
  
```C++
nabla | A 
```

</td>
<td align="center">divergence</td>
<td align="center">
   
$$
\vec{\nabla} \cdot \vec{A}
$$

</td>
</tr>

<!-- curl  -->
<tr>
<td align="center"> 

```C++
curl(A)
```

</td>
<td align="center"> 

```C++
nabla ^ A 
```
  

</td>
<td align="center">curl</td>
<td align="center">
   
$$
\vec \nabla \times \vec A
$$

</td>

</tr>


</tbody>
</table>


<br>

## Maxwell's Equations

The code below calculates, in 3D, the time-dependent, complex-valued potentials

$$\Phi(\vec{x},t) \hspace1ex \dot{=} \hspace1ex A_0 \frac{c^2 k_y}{\omega} \hspace0.5ex e^{i(k_y y - \omega t)}$$

$$\vec{A}(\vec{x},t) \hspace1ex \dot{=} \hspace1ex A_0 \hspace0.5ex e^{i(k_z z - \omega t)} \hspace0.5ex \hat{x} \hspace1ex + \hspace1ex A_0 \hspace0.5ex e^{i(k_y y - \omega t)} \hspace0.5ex \hat{y}$$

Then from these potentials, it calculates the electric and magnetic fields using

$$\vec{E}(\vec{x},t) \hspace1ex = - \vec{\nabla}\Phi - \frac{\partial \vec{A}}{\partial t} $$

$$\vec{B}(\vec{x},t) \hspace1ex = \vec{\nabla} \times  \vec{A}$$


<br>

Constant definitions
```C++
using namespace std::numbers;
using namespace mathq::unit_imaginary;
const size_t Npts = 10;
const double A0 = 1;
const double omega = 2;
const double c = 299792458;
const double kx = 0;
const double ky = 2;
const double kz = 1;
const Vector<double, 3> k{ kx, ky, kz };
const double Phi0 = A0 * pow(c, 2) * ky / omega;
```


<br>

3D+Time Cartesian Coordinates
```C++
CartesianCoords<double, 3, true> coords({
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(-1,1,Npts),
    Interval<double>::interval(0,1,Npts),
}) 
auto& x = coords.x();
auto& y = coords.y();
auto& z = coords.z();
auto& t = coords.t();
```


<br>

Type Definitons for convenience
```C++
using MyScalarField = CurvilinearField<std::complex<double>, 0, decltype(coords)>;
using MyVectorField = CurvilinearField<std::complex<double>, 1, decltype(coords)>;
```


<br>

Potentials
```C++
MyScalarField Phi(coords);
Phi = Phi0 * exp(i*(ky*y - omega*t));

MyVectorField A(coords);
A = expr{ A0 * exp(i*(kz*z - omega*t)), A0 * exp(i*(ky*y - omega*t)), 0 };
```


<br>

E and B fields
```C++
MyVectorField B(coords);
B = curl(A);

MyVectorField E(coords);
E = -grad(Phi) - pd(A, A.time);
```


<br>

Verify the Lorenz Gauge Condition, $\frac{1}{c^2} \frac{\partial \Phi}{\partial t} + \vec{\nabla} \cdot \vec{A} = 0$, to 0.2% accuracy at every point!
```C++
MyScalarField result1(coords);
result1 = div(A);

MyScalarField result2;
result2 = -1./(c*c) * pd(Phi, Phi.time);

☀ alltrue(approx(result1(), result2(), 0.002)) ➜ bool true;
```



<br>

## Derivative parameters
The default [stencil size](https://en.wikipedia.org/wiki/Stencil_(numerical_analysis)) for the derivative on uniform grids is set to 7 points for high accuracy.  Stencil size of 2, 3, 5, and 7 points are supported for uniform grids.    

For non-uniform grids, a stencil size of 3 points is currently supported.

The stencil size is set via the Nabla operator as shown in the example below.

```C++
Nabla nabla(3);  // 3pt stencil instead of default 7 pt
☀ nabla ➜ Nabla<> (Nstencil=3);

B = curl(A, nabla);  // 1. curl using function
B = nabla ^ A; // 2. curl using Nabla operator
```


<br>

## Integration
Numerical integration is in development.
### Definite integral example

```C++
const size_t N = 100000;
const double a = 0;
const double b = 1;
Vector<double> x(linspace_ab<double>(a, b, N));
Vector<double> f;
f = -log(log(1/x));
☀ integrate_a2b(f, a, b, 0) ➜ double 0.577168;
```

### Semi-Definite Integral example

```C++
using namespace std::numbers;
const size_t N = 21;
const double a = 0;
const double b = 4;
Vector<double> x(linspace<double>(a, b, N));
Vector<double> gaussian;
gaussian = 2/sqrt(pi)*exp(-sqr(x));
Vector<double> erf;
☀ erf = integrate_a2x(gaussian, a, b) ➜ Vector<double> {0, 0.221251, 0.425819, 0.600697, 0.73892, 0.83993, 0.908175, 0.950804, 0.975421, 0.988563, 0.995049, 0.998007, 0.999255, 0.999742, 0.999917, 0.999975, 0.999993, 0.999998, 1, 1, 1};
```


<br>



| ⇦ <br />[Functions of Complex Variables](../complex-calculus/README.md)  | [Introduction with Examples](../README.md)<br />Vector Calculus and Curvilinear Coordinates<br /><img width=1000/> | ⇨ <br />[Tensors](../tensors/README.md)   |
| ------------ | :-------------------------------: | ------------ |

