<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.78-c++17</h1>

<details>

<summary>User Manual</summary>

# [User Manual](../README.md)<br>

1. _About_ <br>
2. [License](../license/README.md)<br>
3. [Status, Planned Work & Release Notes](../status-release/README.md)<br>
4. [Description and Example Usage](../description-examples/README.md)<br>
5. [Installation](../installation/README.md)<br>
6. [Your First Mathématiques Project](../first-project/README.md)<br>
7. [Usage Guide: Syntax, Data Types, Functions, etc](../usage-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# 1. About

## Goal - Phase 1

The goal of the Mathématiques project is to provide a _library_ for 
* numerical computation
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

Design a C++ style language and compiler for high-performance mathematics that

* is open-source
* is module/package based instead of C headers
* includes a package manager and online repository
* is strongly typed and compiles to native and web assembly code
* multi-paradigm and concurrent, drawing influence and features from C++, Rust, JavaScript/TypeScript, and D
* processes Mathématiques syntax without the need for all intricate the expression templating
* support templating and operator overloading
* supports Unicode-16 source code including greek letter variables and many possible operators for overloading
* has debug modes that include bounds checking and reflection without the need for macros
* provides user-friendly compiler error messages
* supports 2D and 3D graphics
* interoperability with other languages, frameworks, and run-times
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


| ⇦ <br />  | [User Manual](../README.md)<br />About<br /><img width=1000/> | ⇨ <br />[License](../license/README.md)   |
| ------------ | :-------------------------------: | ------------ |

