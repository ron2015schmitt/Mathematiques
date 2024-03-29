

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
