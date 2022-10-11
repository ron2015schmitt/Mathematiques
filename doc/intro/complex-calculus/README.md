<h1 style='border: 2px solid; text-align: center'><a href='../README.md'>Mathématiques 0.42.2</a></h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Versioning](../../versioning/README.md)<br>
Chapter 4. [Status & Release Notes](../../status-release/README.md)<br>
Chapter 5. [Upcoming Development](../../development-schedule/README.md)<br>
Chapter 6. _Introduction with Examples_ <br>
Chapter 7. [Installation](../../installation/README.md)<br>
Chapter 8. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 9. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 10. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 11. [Tests](../../test/README.md)<br>
Chapter 12. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


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
6.12. _Functions of Complex Variables_ <br>
6.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
6.14. [Tensors](../tensors/README.md)<br>
6.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.12. Functions of Complex Variables

Mathématiques supports complex domains, ie functions of a complex variable.

### Example 1
As an example consider the function:

$$ f\colon [-2,2] \times i[-2,2] \rightarrow\mathbb{C}$$

$$ f(z) = e^{10 z} $$

$$ \frac{df}{dz} $$

$$ \frac{df}{dz^*} $$

Code

```C++
ComplexCoords<double, false> coords({ Interval<double>::interval(-2, 2, 5), Interval<double>::interval(-2, 2, 5) });
ComplexMathFunction<std::complex<double>, decltype(coords)> f(coords);

auto& z = coords.z();
f = exp(10*z);
```

Results

```C++
☀ z ➜ Matrix<std::complex<double>> 
{
  {(-2,-2), (-2,-1), (-2,0), (-2,1), (-2,2)},
  {(-1,-2), (-1,-1), (-1,0), (-1,1), (-1,2)},
  {(0,-2), (0,-1), (0,0), (0,1), (0,2)},
  {(1,-2), (1,-1), (1,0), (1,1), (1,2)},
  {(2,-2), (2,-1), (2,0), (2,1), (2,2)}
};

☀ f ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(8.4112e-10,-1.88172e-09), (-1.72946e-09,1.12131e-09), (2.06115e-09,0), (-1.72946e-09,-1.12131e-09), (8.4112e-10,1.88172e-09)},
  {(1.85269e-05,-4.14477e-05), (-3.80938e-05,2.46985e-05), (4.53999e-05,0), (-3.80938e-05,-2.46985e-05), (1.85269e-05,4.14477e-05)},
  {(0.408082,-0.912945), (-0.839072,0.544021), (1,0), (-0.839072,-0.544021), (0.408082,0.912945)},
  {(8988.61,-20109), (-18481.8,11982.9), (22026.5,0), (-18481.8,-11982.9), (8988.61,20109)},
  {(1.97987e+08,-4.42929e+08), (-4.07088e+08,2.6394e+08), (4.85165e+08,0), (-4.07088e+08,-2.6394e+08), (1.97987e+08,4.42929e+08)}
};

☀ dz(f) ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(-4.94848e+07,1.10706e+08), (1.01747e+08,-6.59691e+07), (-1.21262e+08,0), (1.01747e+08,6.59691e+07), (-4.94848e+07,-1.10706e+08)},
  {(1.64944e+07,-3.69007e+07), (-3.39148e+07,2.1989e+07), (4.04194e+07,0), (-3.39148e+07,-2.1989e+07), (1.64944e+07,3.69007e+07)},
  {(-1.64929e+07,3.68974e+07), (3.39117e+07,-2.1987e+07), (-4.04157e+07,0), (3.39117e+07,2.1987e+07), (-1.64929e+07,-3.68974e+07)},
  {(4.95043e+07,-1.10749e+08), (-1.01787e+08,6.5995e+07), (1.2131e+08,0), (-1.01787e+08,-6.5995e+07), (4.95043e+07,1.10749e+08)},
  {(4.12437e+08,-9.22689e+08), (-8.48027e+08,5.49827e+08), (1.01067e+09,0), (-8.48027e+08,-5.49827e+08), (4.12437e+08,9.22689e+08)}
};
☀ dz_star(f) ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(-1.73698e-08,6.43998e-09), (5.25748e-09,2.5347e-10), (-1.72329e-26,-1.8087e-09), (-5.25748e-09,2.5347e-10), (1.73698e-08,6.43998e-09)},
  {(-0.000382596,0.00014185), (0.000115804,5.58304e-06), (1.12938e-21,-3.98393e-05), (-0.000115804,5.58304e-06), (0.000382596,0.00014185)},
  {(-8.42724,3.12446), (2.55075,0.122975), (4.62593e-18,-0.877519), (-2.55075,0.122975), (8.42724,3.12446)},
  {(-185622,68820.7), (56184,2708.7), (-7.57912e-13,-19328.6), (-56184,2708.7), (185622,68820.7)},
  {(-4.0886e+09,1.51588e+09), (1.23753e+09,5.96631e+07), (-1.98682e-08,-4.25742e+08), (-1.23753e+09,5.96631e+07), (4.0886e+09,1.51588e+09)}
};

```

<br>

### Example 2
Consider the function:

$$ f\colon [-2,2] \times i[-2,2] \rightarrow\mathbb{C}$$

$$ f(z) = \frac{z + 1}{z - 1} $$

$$ \frac{df}{dz} $$

$$ \frac{df}{dz^*} $$

Code

```C++

ComplexMathFunction<std::complex<double>, ComplexCoords<double, false>> f({ Interval<double>::interval(-1, 1, 5), Interval<double>::interval(-2, 2, 5) });
auto& z = f.coords().z();
f = (z + 1)/(z - 1);
```

Results

```C++
☀ f ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(0.5,0.5), (0.2,0.4), (-0,-0), (0.2,-0.4), (0.5,-0.5)},
  {(0.52,0.64), (0.0769231,0.615385), (-0.333333,-0), (0.0769231,-0.615385), (0.52,-0.64)},
  {(0.6,0.8), (-0,1), (-1,-0), (-0,-1), (0.6,-0.8)},
  {(0.764706,0.941176), (0.2,1.6), (-3,-0), (0.2,-1.6), (0.764706,-0.941176)},
  {(1,1), (1,2), (inf,-nan), (1,-2), (1,-1)}
};
☀ dz(f) ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(0.0158824,0.246471), (-0.184615,0.523077), (-inf,-nan), (-0.184615,-0.523077), (0.0158824,-0.246471)},
  {(0.0852941,0.308824), (-0.261538,0.507692), (inf,-nan), (-0.261538,-0.507692), (0.0852941,-0.308824)},
  {(0.242941,0.318235), (0.0307692,1.04615), (-inf,-nan), (0.0307692,-1.04615), (0.242941,-0.318235)},
  {(0.411176,0.225294), (0.876923,1.21538), (inf,-nan), (0.876923,-1.21538), (0.411176,-0.225294)},
  {(0.512353,-0.0194118), (2.46154,0.0923077), (inf,-nan), (2.46154,-0.0923077), (0.512353,0.0194118)}
};
☀ dz_star(f) ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(-0.1,0.15), (-0.35,-0.3), (0,-0.45), (0.35,-0.3), (0.1,0.15)},
  {(0.196923,0.467692), (-0.689231,-0.418462), (0,-0.713846), (0.689231,-0.418462), (-0.196923,0.467692)},
  {(1.6,1.2), (-1.6,-0.6), (0,-1.2), (1.6,-0.6), (-1.6,1.2)},
  {(8.28235,2.54118), (-4.89412,-0.847059), (0,-1.97647), (4.89412,-0.847059), (-8.28235,2.54118)},
  {(-inf,-nan), (inf,-nan), (0,-2.5), (-inf,-nan), (inf,-nan)}
};
```




<br>



| ⇦ <br />[Numerical / Discretized Mathematical Function Objects](../numerical-functions/README.md)  | [Introduction with Examples](../README.md)<br />Functions of Complex Variables<br /><img width=1000/> | ⇨ <br />[Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

