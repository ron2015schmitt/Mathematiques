[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.014</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Why?](../why/README.md)<br>
Chapter 4. _Objectives_ <br>
Chapter 5. [Versioning](../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../development-schedule/README.md)<br>
Chapter 8. [Introduction with Examples](../intro/README.md)<br>
Chapter 9. [Installation](../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 11. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 12. [Benchmarks](../benchmarks/README.md)<br>
Chapter 13. [Tests](../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# Chapter 4. Objectives



## Phase 1 (in progress): C++ Numerical Library
 
 
Create an extensive, open source, numerical C++ library that provieds / supports

* compact **data structures** that represent **mathematical objects** 
* user **code that looks like mathematical notation**
* **state of the art performance** (both speed and memory usage)
* **multithreading**
* convenient **pretty printing of results** including **data type information**
* several **compilation modes** (DEBUG, PRODUCTION) via command line flags and the C++ macro preprocessor
  + **DEBUG mode** checks bounds, vector and matrix sizes, etc and generates clear, pretty printed errors to stderr
  + **PRODUCTION mode** runs as without any checks
* **i/o in popular formats** for analysis and plotting
* open-source **github** repo for version control and distribution
* clear, online, automated **documentation** 
* **extensive automated testing** and **benchmarking**
* container-ized **Docker Images** 
* [**Continuous Integration**](https://en.wikipedia.org/wiki/Continuous_integration) / [**Continuous Texting**](https://en.wikipedia.org/wiki/Continuous_testing)

The above goals are accomplished, in part, by 
* following the **definitions of modern formal mathematics** and 
* using the techniques of **modern C++**, ie C++11, C++14, C++17, and C++20.

Of course, Mathématiques can be **combined with standard C++ syntax, techniques, and libraries**.

✳ [Introduction with Examples](doc/intro/README.md) ✳ 

[Full Documentation](doc/README.md)

---------------------------------
## Phase 2 (planned): Mathematics Built into a Modern Language

Create a new language that implements the phase 1 library above plus
* supports unicode characters in source code 
  + supports greek language characters for variables
  + supports operator definitions for mathematical unicode symbols so that the code really looks like mathematical notation
  + also has multi-character ASCII symbols for each unicode symbol
* has an http interface for remote computation
* has a modern, cloud-based package loader
* has a package repository site, eg [npm for NodeJs](https://www.npmjs.com/) for user-created open-source packages

The current language candidates to build upon are [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)) and [Carbon](https://en.wikipedia.org/wiki/Carbon_(programming_language)).


* instead of class hierarchies and templates
  + generics
  + concepts (constraints and requirements)
   + concept type defs
  + tuples
    + run-time access to elements without need for lambda visitation pattern
  + many operators
    + unicode character operators
  + mix-ins
    + concept interfaces for *provides* and *needs*
    
+ mathematical system concept definitions
  + group
  + ring
  + algebraic field
  + vector space
  + algebra
  + division algebra

# OLD verbiage

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




| ⇦ <br />[Why?](../why/README.md)  | [Documentation](../README.md)<br />Objectives<br /><img width=1000/> | ⇨ <br />[Versioning](../versioning/README.md)   |
| ------------ | :-------------------------------: | ------------ |

