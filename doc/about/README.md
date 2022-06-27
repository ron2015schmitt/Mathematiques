<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.40.46-c++17</h1>

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
1. [License](../license/README.md)<br>
2. _About_ <br>
3. [Status, Planned Work & Release Notes](../status-release/README.md)<br>
4. [Description and Example Usage](../overview/README.md)<br>
5. [Installation](../installation/README.md)<br>
6. [Your First Mathématiques Project](../first-project/README.md)<br>
7. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# 2. About

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



## History

Development for this project originally took place in very rough form during the years 2003-2008 using the C99/C++.

The code was resurrected in 2019: refactored, extended, improved, simplified, and updated with C++11, C++14, C++17 features.

In early 2020, the project was officially launched as _Mathématiques_ and uploaded to a github!


## Techniques

The code uses a form of C++ [template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming) called [expression templating](https://en.wikipedia.org/wiki/Expression_templates), the library provides computational efficiency on par with C/Fortran.

1. *Expression templating* produces complex code in the library itself, but the *user code* is simple, clean, and extremely efficient.
1. *Type traits* design pattern
1. *operator overloading*
1. using templates for all functions
1. _Avoid_ use of virtual functions completely to minimize size of instance in memory and run-time cost

Looking into:
1. kwargs for named arguments

References
1. Andrei Alexandrescu, __Modern C++ Design: Generic Programming and Design Patterns Applied__, 2001.
2. David Vandevoorde, Douglas Gregor, Nicolai M Josuttis, __C++ Templates: The Complete Guide__, 2nd edition, 2018.

## Platform

The initial platform chosen is
* language
  1. C++17 or higher, necessary to create the syntax
* compiler
  1. The GNU g++ compiler that supports C++17 XX or higher
* OS
  1. Linux: Ubuntu 20.05
* packages
  1. LAPACK: for the more advanced linear algebra functions: matrix inverse, and decompositions

Other configurations are of course possible with modification.




/home/rs2015/Mathematiques/doc


| ⇦ <br />[License](../license/README.md)  | [Documentation](../README.md)<br />About<br /><img width=1000/> | ⇨ <br />[Status, Planned Work & Release Notes](../status-release/README.md)   |
| ------------ | :-------------------------------: | ------------ |

