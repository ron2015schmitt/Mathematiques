<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.26-c++20</h1>

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
1. [License](../license/README.md)<br>
2. [About](../about/README.md)<br>
3. _Status, Planned Work & Release Notes_ <br>
4. [Description and Example Usage](../overview/README.md)<br>
5. [Installation](../installation/README.md)<br>
6. [Your First Mathématiques Project](../first-project/README.md)<br>
7. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# 3. Status, Planned Work & Release Notes

## Status

Currently, in 2022, Mathématiques is undergoing the final changes to make it sponsorship-ready.  This process includes full documentation in markdown, finalizing the syntax, and code refactoring.

## News 

The first two refactoring projects have been completed.


## Coming soon

+ Vector Calculus
  + curvilinear coordinate systems

+ Tensor Calculus in generalized coordinates / Differential Geometry
  + covariant and contravariant tensors

+ Documenation
  + Rewritten User Manual
  + _Usage Guide_, covering all the functionality
  + New _Developer Guide_



## Release Notes

### **0.40** MultiArray Refactoring
  + changed numbering system to start with 0. V3.5 is now 0.40.
  + Now using `C++20` (`g++ 11.1.0`) to take advantage of concepts / constraints
  + Added constant and repeated-vector `MultiArray` types
  + Added compiler information for build
  + C++ version is set via file `c++.version.src.txt`
  + `Scalar`, `Vector`, and `Matrix` are now simply type aliases for `MultiArray` type via `C++20` concepts / constraints
  + Removed "hidden" `MultiArray` template parameters for Depth and NumberType: only needed in expressions
  + Refactored `Dimensions` and `Indices` classes as well as the uses of `Indices`
  + New `RecursiveDimensions`  and `DeepIndices` classes

### **alpha-3.4** Documentation Refactoring
  + Full refactoring of the online documentation
  + Expandable table of contents header
  + navigation footer

### **alpha-3.3** Build Process Refactoring
  + The build process has been fully refactored, simplified, and streamlined
  + The documentation refactoring has begun
  
### **alpha-3.2** First Official Release

**Design**
  + Simple Matlab-like syntax with no run-time cost
  + Performance comparable to C and Fortran
  + Pretty printing with styles and colors
  + Debugging mode
  + File I/O in various formats including formats for Matlab and Mathematica
  + Detailed pretty documentation in Markup.  
  + Markup Documents can be auto-generated from C++ code.
  + "Boiler plate" code is created using Python scripts for supporting functionality such as mixed-type math

**Data Types**
  + Arbitrary rank tensor arrays (Scalar, Vector, Matrix, etc)
  + tensors can have 
    + variable dimensions, using `valarray`:  `Vector<double>`
    + fixed dimensions, using `array`: `Vector<double,3>`
  + fixed array size is ideal for small vectors, eg 2D or 3D vector
  + Each tensor type can have tensor as datatype
    + eg. `Vector<Matrix<double>>` or `Matrix<Vector<double>>`, which can be used to represent a vector-valued function on a 2D or 3D mesh.
  + `Imaginary<D>` number template class that dovetails with the fundamental (real) types `D` and  with `std::complex<D>`

**Operators**
  + arithmetic defined for all types: ints, float, double, Complex, Vector, etc
  + mixed-type math with automatic type promotion: ints and floats, real and complex, vector and scalar, etc
    + eg. can add a vector of type `int` with a vector of type `std::complex<double>` and the output will be a vector of type `std::complex<double>`
    + eg. vector/scalar math, eg add a scalar value to every element of a vector or matrix
  + relational operators and boolean masks for vectors and matrices
  + boolean vector functions ```any```, ```all```, etc

**Mathematical functions**
  + most functions work on all datetypes: floats, Complex, Vector, etc
  + elemental math functions (sin, cos, exp, etc)
  + special functions such as Bessel functions (C++17).

**Linear algreba**
  + element-wise mathematics for Vectors, Matrices, and MultiArrays
  + dot/inner product
  + outer product and wedge products in progress 

**Calculus**
  + Calculus (derivatives and integrals)
  + Taylor series
  + Fourier Series

**MultiArray algreba**
  + convariant / contravairant tensors and operations are in progress...
 
**Tests**
  + 237 unit tests (so far), with a very clear and elegant output.
  + Python unit test generation in progress
  + CI/CT using Docker images in progress


| ⇦ <br />[About](../about/README.md)  | [Documentation](../README.md)<br />Status, Planned Work & Release Notes<br /><img width=1000/> | ⇨ <br />[Description and Example Usage](../overview/README.md)   |
| ------------ | :-------------------------------: | ------------ |

