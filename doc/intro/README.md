[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.0+c++20</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Why?](../why/README.md)<br>
Chapter 4. [Objectives](../objectives/README.md)<br>
Chapter 5. [Versioning](../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../development-schedule/README.md)<br>
Chapter 8. _Introduction with Examples_ <br>
Chapter 9. [Installation](../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 11. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 12. [Benchmarks](../benchmarks/README.md)<br>
Chapter 13. [Tests](../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# 8. Introduction with Examples

**Basics**<br>
8.1. [Pretty Printing and Debugging](print-debug/README.md)<br>
8.2. [Number Systems and Arithmetic](numbers/README.md)<br>
<br>**MultiArrays**<br>
8.3. [Vectors, Matrices, and MultiArrays](multiarrays/README.md)<br>
8.4. [Nested MultiArrays](nested-multiarrays/README.md)<br>
8.5. [Special Vectors, Matrices, and MultiArrays](special-multiarrays/README.md)<br>
<br>**Mathematics**<br>
8.6. [MultiArray Arithmetic](multiarray-arithmetic/README.md)<br>
8.7. [Linear Algebra](linear-algebra/README.md)<br>
8.8. [Sorting, Masks, Slices, etc.](sort-mask-slice/README.md)<br>
8.9. [Common and Special Mathematical Functions](math-functions/README.md)<br>
<br>**Calculus**<br>
8.10. [Mutlivariate Calculus](multi-var-calculus/README.md)<br>
8.11. [Calculus on Complex Number Domains](complex-calculus/README.md)<br>
8.12. [Vector Calculus and Curvilinear Coordinates](vector-calculus/README.md)<br>
8.13. [Tensors](tensors/README.md)<br>
8.14. [Series and transforms](series-transforms/README.md)<br>


# Planned Features

1. Tensor Calculus in Generalized Coordinates 
1. Differential Geometry in curved space-time
1. Matrix inverse and matrix decompositions
  + via [BLAS](https://netlib.org/blas/index.html#_documentation) or other available linear algebra libraries [1](https://en.wikipedia.org/wiki/Comparison_of_linear_algebra_libraries), [2](https://en.wikipedia.org/wiki/List_of_numerical_libraries) [3]([GSL](http://www.gnu.org/s/gsl/)
  + Implement Special Matrices and MultiArrays
1. FFTs via [FFTW](https://en.wikipedia.org/wiki/FFTW)]
1. Interpolation and smoothing
1. Parallel processing
1. General Differential Operators and Expressions
1. Integral operators
  +	function to create bra (of bra-kets) operator for `NumericalFunction` via `bra` or `~operator`
1. Differential Equation Solvers via libraries
  + [FEM](https://en.wikipedia.org/wiki/Category:Finite_element_software)
  + ODEPACK
1. File I/O
1. Finite groups
1. Lie groups
1. Graded algebras: Clifford algebras
1. Graded algebras: geometric and spacetime algebras
1. Division algebras: Octonians