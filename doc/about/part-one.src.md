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

Design a C-style language and compiler for high-performance mathematics:

**Open-source**
* Free and customizable

**Compiled and Modern**
* Compiles to native machine code and web assembly code
* Strongly typed
* User-friendly compiler error messages
* Module/package based instead of legacy C header-based
* Package manager and online repository
* Influenced by 
  * C++
  * [D](https://en.wikipedia.org/wiki/D_(programming_language)
  * [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)

**Versatile and easy-to-read**
* Templating and metaprogramming
* Operator overloading
* Unicode-16 source code 
  * greek letter variables
  * many possible unicode operators for overloading

**Debug and production modes**
* Debug modes that include 
  * bounds-checking
  * reflection and meta-data access (variable names, etc) without the need for macros
* Production mode
  * debug features are not available outside debug modes
  * runs at maximum efficiency

**Multi-paradigm**
* drawing influence and features from
  * C++
  * Java
  * JavaScript/TypeScript
* interoperability with other languages, frameworks, and run-times

**Reliable and Conncurrent**
* drawing influence and features from [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)

**Core Math Types Defined and built into language**
* Processes Mathématiques types without the need for all intricate the expression templating
* number types
  * integer
  * floating point
  * complex
  * imaginary
  * quaternion
  * Multi-vector
  * Clifford algebras
* multi-arrays
  * vector
  * matrix
  * multi-array
* tensors and differential forms
  * covariant / contravariant tensors of any rank
  * spinors etc
* calculus operators

**Core numerical support**
* support core computational features of  
  * Matlab
  * Mathematica
  * Julia

**Package repository for added functionality**
* 2D and 3D graphics
* LateX / Notebook interoperability

