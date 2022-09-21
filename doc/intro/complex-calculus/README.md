[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.014</h1>](../../../README.md)

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
8.11. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
8.12. _Calculus on Complex Number Domains_ <br>
8.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
8.14. [Tensors](../tensors/README.md)<br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.12. Calculus on Complex Number Domains




CurvilinearField - Complex 1D
☀ rect ➜ ComplexRectangle<double> ( real: [-1, 1], N=5; imag: [-2, 2], N=5 );
☀ rect.dims() ➜ Dimensions 5⨯5;
☀ rect.grid_complex() ➜ Matrix<std::complex<double>> 
{
  {(-1,-2), (-1,-1), (-1,0), (-1,1), (-1,2)},
  {(-0.5,-2), (-0.5,-1), (-0.5,0), (-0.5,1), (-0.5,2)},
  {(0,-2), (0,-1), (0,0), (0,1), (0,2)},
  {(0.5,-2), (0.5,-1), (0.5,0), (0.5,1), (0.5,2)},
  {(1,-2), (1,-1), (1,0), (1,1), (1,2)}
};
☀ rect.grid_real() ➜ Vector<double> {-1, -0.5, 0, 0.5, 1};
☀ rect.grid_imag() ➜ Vector<double> {-2, -1, 0, 1, 2};
☀ coords ➜ ComplexCoords<double,TimeCoord=0> {
  vector_index=0, dims=5⨯5
{
  {-1, -1, -1, -1, -1},
  {-0.5, -0.5, -0.5, -0.5, -0.5},
  {0, 0, 0, 0, 0},
  {0.5, 0.5, 0.5, 0.5, 0.5},
  {1, 1, 1, 1, 1}
}; 
  vector_index=1, dims=5⨯5
{
  {-2, -1, 0, 1, 2},
  {-2, -1, 0, 1, 2},
  {-2, -1, 0, 1, 2},
  {-2, -1, 0, 1, 2},
  {-2, -1, 0, 1, 2}
}
}};
☀ coords.grid_dims() ➜ Dimensions 5⨯5;
☀ IsComplexCoords<decltype(coords)> ➜ bool true;
☀ coords.x() ➜ MultiArray_RepeatVector<double, rank=2> vector_index=0, dims=5⨯5
{
  {-1, -1, -1, -1, -1},
  {-0.5, -0.5, -0.5, -0.5, -0.5},
  {0, 0, 0, 0, 0},
  {0.5, 0.5, 0.5, 0.5, 0.5},
  {1, 1, 1, 1, 1}
};
☀ coords.y() ➜ MultiArray_RepeatVector<double, rank=2> vector_index=1, dims=5⨯5
{
  {-2, -1, 0, 1, 2},
  {-2, -1, 0, 1, 2},
  {-2, -1, 0, 1, 2},
  {-2, -1, 0, 1, 2},
  {-2, -1, 0, 1, 2}
};
☀ coords.z() ➜ Matrix<std::complex<double>> 
{
  {(-1,-2), (-1,-1), (-1,0), (-1,1), (-1,2)},
  {(-0.5,-2), (-0.5,-1), (-0.5,0), (-0.5,1), (-0.5,2)},
  {(0,-2), (0,-1), (0,0), (0,1), (0,2)},
  {(0.5,-2), (0.5,-1), (0.5,0), (0.5,1), (0.5,2)},
  {(1,-2), (1,-1), (1,0), (1,1), (1,2)}
};
ComplexMathFunction<std::complex<double>, decltype(coords)> field0(coords);
auto& x = coords.x();
auto& y = coords.y();
auto& z = coords.z();
field0() = -3*x + 5*Imaginary<double>(1)*x;
☀ field0 ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(3,-5), (3,-5), (3,-5), (3,-5), (3,-5)},
  {(1.5,-2.5), (1.5,-2.5), (1.5,-2.5), (1.5,-2.5), (1.5,-2.5)},
  {(-0,0), (-0,0), (-0,0), (-0,0), (-0,0)},
  {(-1.5,2.5), (-1.5,2.5), (-1.5,2.5), (-1.5,2.5), (-1.5,2.5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)}
};
☀ real(field0) ➜ Scalar<Matrix<double>> 
{

};
☀ imag(field0) ➜ Scalar<Matrix<double>> 
{

};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ pd(field0, 0) ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)}
};
☀ IsMultiArray<decltype(field0)> ➜ bool true;
☀ IsMultiArray<decltype(field0())> ➜ bool true;
☀ IsComplex<typename NumberTrait<decltype(field0)>::Type>::value ➜ bool true;
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ fr ➜ Vector<double> {3, 1.5, -0, -1.5, -3};
☀ fi ➜ Vector<double> {-5, -2.5, 0, 2.5, 5};
☀ fr ➜ Vector<double> {-3, -3, -3, -3, -3};
☀ fi ➜ Vector<double> {5, 5, 5, 5, 5};
☀ f ➜ Vector<std::complex<double>> {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)};
☀ dz(field0) ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)},
  {(-3,5), (-3,5), (-3,5), (-3,5), (-3,5)}
};
field0() = -3*x + 5*Imaginary<double>(1)*y;
☀ dz_star(field0) ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=0>> 
{
  {(0,5), (0,5), (0,5), (0,5), (0,5)},
  {(0,5), (0,5), (0,5), (0,5), (0,5)},
  {(0,5), (0,5), (0,5), (0,5), (0,5)},
  {(0,5), (0,5), (0,5), (0,5), (0,5)},
  {(0,5), (0,5), (0,5), (0,5), (0,5)}
};
CurvilinearField - Complex 1D with time
☀ coords.z() ➜ MultiArray<std::complex<double>, rank=3> 
{
  {
    {(-1,-2), (-1,-2)},
    {(-1,0), (-1,0)},
    {(-1,2), (-1,2)}
  },
  {
    {(-0.5,-2), (-0.5,-2)},
    {(-0.5,0), (-0.5,0)},
    {(-0.5,2), (-0.5,2)}
  },
  {
    {(0,-2), (0,-2)},
    {(0,0), (0,0)},
    {(0,2), (0,2)}
  },
  {
    {(0.5,-2), (0.5,-2)},
    {(0.5,0), (0.5,0)},
    {(0.5,2), (0.5,2)}
  },
  {
    {(1,-2), (1,-2)},
    {(1,0), (1,0)},
    {(1,2), (1,2)}
  }
};
☀ coords.t() ➜ MultiArray_RepeatVector<double, rank=3> vector_index=2, dims=5⨯3⨯2
{
  {
    {0, 1},
    {0, 1},
    {0, 1}
  },
  {
    {0, 1},
    {0, 1},
    {0, 1}
  },
  {
    {0, 1},
    {0, 1},
    {0, 1}
  },
  {
    {0, 1},
    {0, 1},
    {0, 1}
  },
  {
    {0, 1},
    {0, 1},
    {0, 1}
  }
};
ComplexMathFunction<std::complex<double>, decltype(coords)> field0(coords);
auto& x = coords.x();
auto& z = coords.z();
auto& t = coords.t();
field0() = exp(2*z) + 5*t;
☀ field0 ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=1>> 
{
  {
    {(-0.088461,0.102422), (4.91154,0.102422)},
    {(0.135335,0), (5.13534,0)},
    {(-0.088461,-0.102422), (4.91154,-0.102422)}
  },
  {
    {(-0.240462,0.278412), (4.75954,0.278412)},
    {(0.367879,0), (5.36788,0)},
    {(-0.240462,-0.278412), (4.75954,-0.278412)}
  },
  {
    {(-0.653644,0.756802), (4.34636,0.756802)},
    {(1,0), (6,0)},
    {(-0.653644,-0.756802), (4.34636,-0.756802)}
  },
  {
    {(-1.77679,2.0572), (3.22321,2.0572)},
    {(2.71828,0), (7.71828,0)},
    {(-1.77679,-2.0572), (3.22321,-2.0572)}
  },
  {
    {(-4.82981,5.59206), (0.170191,5.59206)},
    {(7.38906,0), (12.3891,0)},
    {(-4.82981,-5.59206), (0.170191,-5.59206)}
  }
};
☀ pd(field0, 2) ➜ ComplexMathFunction<std::complex<double>,ComplexCoords<double,TimeCoord=1>> 
{
  {
    {(5,0), (5,0)},
    {(5,0), (5,0)},
    {(5,0), (5,0)}
  },
  {
    {(5,0), (5,0)},
    {(5,0), (5,0)},
    {(5,0), (5,0)}
  },
  {
    {(5,0), (5,0)},
    {(5,0), (5,0)},
    {(5,0), (5,0)}
  },
  {
    {(5,0), (5,0)},
    {(5,0), (5,0)},
    {(5,0), (5,0)}
  },
  {
    {(5,0), (5,0)},
    {(5,0), (5,0)},
    {(5,0), (5,0)}
  }
};

<br>



| ⇦ <br />[Mutlivariate Calculus](../multi-var-calculus/README.md)  | [Introduction with Examples](../README.md)<br />Calculus on Complex Number Domains<br /><img width=1000/> | ⇨ <br />[Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)   |
| ------------ | :-------------------------------: | ------------ |

