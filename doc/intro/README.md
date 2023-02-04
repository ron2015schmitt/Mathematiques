<h1 style='border: 2px solid; text-align: center'><a href='../../README.md'>Mathématiques 0.42.6</a></h1>

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
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



# 6. Introduction with Examples

**Basics**<br>
6.1. [Pretty Printing and Debugging](print-debug/README.md)<br>
6.2. [Number Systems and Arithmetic](numbers/README.md)<br>
<br>**MultiArrays**<br>
6.3. [Vectors, Matrices, and MultiArrays](multiarrays/README.md)<br>
6.4. [Nested MultiArrays](nested-multiarrays/README.md)<br>
6.5. [Special Vectors, Matrices, and MultiArrays](special-multiarrays/README.md)<br>
<br>**Mathematics**<br>
6.6. [MultiArray Arithmetic and Operators](multiarray-arithmetic/README.md)<br>
6.7. [Mixed-Rank & Mixed-Depth Arithmetic](arithmetic-mixed/README.md)<br>
6.8. [Linear Algebra](linear-algebra/README.md)<br>
6.9. [Indexing, Masks, Slicing, Sorting, etc.](sort-mask-slice/README.md)<br>
6.10. [Common and Special Mathematical Functions](math-functions/README.md)<br>
<br>**Discretized Functions, Tensors, and Calculus**<br>
6.11. [Numerical / Discretized Mathematical Function Objects](numerical-functions/README.md)<br>
6.12. [Functions of Complex Variables](complex-calculus/README.md)<br>
6.13. [Vector Calculus and Curvilinear Coordinates](vector-calculus/README.md)<br>
6.14. [Tensors](tensors/README.md)<br>
6.15. [Series and transforms](series-transforms/README.md)<br>


## Planned Features



### Algorithms and Solvers

To be implemented using other libraries:

1. Matrix inverse and matrix decompositions
1. FFTs via [FFTW](https://en.wikipedia.org/wiki/FFTW)
1. Interpolation and smoothing
1. Differential Equation Solvers via libraries

### Basic Features

1. Parallel processing
1. File I/O

### Advanced Mathematical Structures

1. Special Matrices / MultiArrays
1. Finish Algebraic Tensors
    + Symmetric and AntiSymmetric tensors as child classes of Symmetric and AntiSymmetric multiarrays
    + Levi-Civita psuedo-tensor
    + [Exterior algebra](https://en.wikipedia.org/wiki/Exterior_algebra)
    + [Symmetric algebra](https://en.wikipedia.org/wiki/Symmetric_algebra)
    + [musical operators](https://en.wikipedia.org/wiki/Musical_isomorphism)
    + [Hodge Dual](https://en.wikipedia.org/wiki/Hodge_star_operator)
1. Tensor Calculus in Generalized Coordinates
    + `TensorCoords`
    + `TensorField`
    + [k-cells](https://en.wikipedia.org/wiki/K-cell_(mathematics))
    + [exterior derivative](https://en.wikipedia.org/wiki/Exterior_derivative)
    + [differential forms](https://en.wikipedia.org/wiki/Differential_form)
    + [k-blades](https://en.wikipedia.org/wiki/Blade_(geometry))
1. Differential Geometry in curved space-time
    + `RiemannianCoords`
1. Graded Algebras and their fields
    + Grassman/Clifford algebras, Weyl algebras
1. Differentiation
  * support any derivative stencil size for both uniform and and non-uniform grids
  * support causal (backward stencil), anti-causal (forward stencil), and non-causal (centered stencil) functions
  * support periodic and Neumann [boundary conditions](https://en.wikipedia.org/wiki/Boundary_value_problem)
1. General Differential Operators and Expressions
    + Differential Operator from k-blades and graded algebra k-blades
1. Integration
  * support an assortment of [integration techniques](https://en.wikipedia.org/wiki/Numerical_integration)
1. Integral operators
    + Integral Operator from k-forms
    + [k-simplexes](https://en.wikipedia.org/wiki/Simplex)
    + [k-chains](https://en.wikipedia.org/wiki/Chain_(algebraic_topology))
1. [dual](https://en.wikipedia.org/wiki/Duality_(mathematics)) function/operator. See also [bra-ket](https://en.wikipedia.org/wiki/Bra%E2%80%93ket_notation)
1. [Ordinary Differential equation solvers](https://en.wikipedia.org/wiki/Numerical_methods_for_ordinary_differential_equations)
1. [Partial Differential equation solvers](https://en.wikipedia.org/wiki/Numerical_methods_for_partial_differential_equations)
1. Lie groups
1. Spinors
1. Finite groups
1. Division algebras: Octonians, Sedonians
