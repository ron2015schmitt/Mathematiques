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

