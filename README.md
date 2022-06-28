

# Mathématiques v0.40.71-c++17


## Documentation

[Documentation](doc/README.md)



## Goal - Phase 1

The goal of the Mathématiques project is to provide a _library_ for 
* numerical/scientific computation
* computational sciences
* machine learning / AI
* big data
* engineering simulations
* computer graphics

that is
* user friendly
* function and feature rich
* flexible

has 
* simple compact syntax
* looks more like math than code

with
* easy-to-use output functions that produce clearly formatted results in color, including type information
* debug modes for bounds and dimension checking
* production mode that runs as fast as possible, without any checking
* CI/CT workflow using Docker and github actions

producing executables that are
* fast
* memory efficient

## Language

C++ was chosen for its efficiency and because it has the features, such as templating, needed to create a syntax.

## Influences

* Matlab
* Fortran95
* Mathematica
* Boost C++
* Python

## Status

Currently, in 2022, Mathématiques is undergoing the final changes to make it sponsorship-ready.  This process includes full documentation in markdown, finalizing the syntax, and code refactoring.

## Goal - Phase 2

Design a C-style language and compiler for high-performance mathematics, likely based on Rust.

**Open-source**
* Free and customizable
* Package manager and online repository

**Compiled and Modern**
* Uses LLVM toolchain
* Compiles to native machine code and web assembly code
* Strongly typed
* Compiled, Strongly typed, and lack of garbage collection distinguishes it from Python and Julia
* User-friendly compiler error messages
* Module/package based instead of legacy C header-based
* Influenced by (in order)
  * [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)
  * C++
  * [D](https://en.wikipedia.org/wiki/D_(programming_language)

**Versatile and easy-to-read**
* Generics (aka "templates" in C++ terminology) and metaprogramming.  
* Use Java Interface and Stroustrup "concepts" (instead of inheritance?)
  * requirements and attibrutes
  * suport for mix-in methodology
* Operator overloading
* Unicode-16 source code 
  * greek letter variables
  * many possible unicode operators for overloading
* Named parameters like JavaScript and Fortran
* Initializer lists and initializer lists with names and/or types
* aggregator lists on LHS like JavaScript
* Improve upon C++ tuple, any, variant
  * the return value of a function can depend on which element is returned
* parameter pack type definition with type and size
* modern function support
  * lambda functions and closures
  * variadic parmeters of same type and of specified size
  * https://en.cppreference.com/w/cpp/language/function_template
* Support JavaScript-like string interpolation 
* No setters or getters
  * have optional methods that are called if present when obj.variable is referenced on LHS or RHS
  * variable aliases that incur no memory storage
* support for fixed size and dynamically sized containers and multiarrays

**Debug and production modes**
* Debug modes that include 
  * bounds-checking
  * reflection and meta-data access (variable names, etc) without the need for macros
* Production mode
  * debug features and reflection are not available outside debug modes
  * runs at maximum efficiency

**Multi-paradigm**
* drawing influence and features from
  * C++
  * Java
  * JavaScript/TypeScript
* interoperability with other languages, frameworks, and run-times via LLVM

**Reliable and Concurrent**
* drawing influence and features from [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)

**Core Math Types Defined and built into language**
* Processes Mathématiques types without the need for all intricate the expression templating
* number types
  * integer
  * floating point
  * complex
  * imaginary
  * quaternion
* multi-arrays
  * vector
  * matrix
  * multi-array
* tensors and differential forms
  * covariant / contravariant tensors of any rank
  * spinors etc
* Other types
  * Multi-vectors (Grassman algebras)
  * Clifford algebras
* Calculus operators

**Core numerical support**
* aim to support core computational features of  
  * Matlab
  * Mathematica
  * Julia
  * NumPy

**Package repository for added functionality**
* 2D and 3D graphics
* LateX / Notebook interoperability

