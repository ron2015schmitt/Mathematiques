## Status

Currently, in 2022, Mathématiques is undergoing the final changes to make it sponsorship-ready.  This process includes full documentation in markdown, finalizing the syntax, and code refactoring.

## News 

The first step of refactoring has been completed.

+ v3.4 Documenation
  + Full refactoring of the online documentation
    + expanable table of contents header
    + navigation footer

## Coming soon

+ v3.5 Documenation
  + Rewritten User Manual
  + Complete _Usage Guide_, covering all the functionality
  + New _Developer Guide_

+ v3.6 Indexing
  + Refactor of vector/matrix/tensor indexing, including
    + new index/iterator types such as slices similar to Fortan and Python

+ v3.7 Display 
  + Refactor of Display

+ v3.8 Debugging Modes
  + Refactor of Debugging Modes

+ v4.0+ 
  + More matrix types
  + covariant and contravariant tensors
  + tensor operations
  + curvilinear coordinate systems

## Release Notes

### **v3.4** Documentation Refactoring
  + Full refactoring of the online documentation
  + expanable table of contents header
  + navigation footer

### **v3.3** Build Process Refactoring
  + The build process has been fully refactored, simplified, and streamlined
  + The documentation refactoring has begun
  
### **v3.2** First Official Release

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
  + element-wise mathematics for Vectors, Matrices, and Tensors
  + dot/inner product
  + outer product and wedge products in progress 

**Calculus**
  + Calculus (derivatives and integrals)
  + Taylor series
  + Fourier Series

**Tensor algreba**
  + convariant / contravairant tensors and operations are in progress...
 
**Tests**
  + 237 unit tests (so far), with a very clear and elegant output.
  + Python unit test generation in progress
  + CI/CT using Docker images in progress
