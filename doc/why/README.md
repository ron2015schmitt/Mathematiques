[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.019</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. _Why?_ <br>
Chapter 4. [Objectives](../objectives/README.md)<br>
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



# Chapter 3. Why?

## Why Create Another New Numerical Library?


High performance
Easy to set up environment and install
Easy to learn
Judiciously designed data structures
Modern math and objects that represent them.
Compact
Looks like math

Python has a package loader and repo site. So does JS, in node and others deno.  C++ needs this tech 


Two enablers
Technology advancements: C++ language, optimizations, etc below
Combination of
Mathematical objects using Modern formal definitions can be accommodate naturally with with C++ templates and C++ Concepts. (A duck quacks) (a division algebra has +-/* defined as operators.  For functions these correspond to discrete objects.
Multi-paradigm design using definitions and notation of modern formal mathematics as a guide. Design patterns, like visitor pattern for the interaction of Domain, Coords, BCs, and Function. Similar to linearization process of modern differential geometry. Also "Defaults Pattern" with named parameters in lists. tuples. auto types. Templates. Parameter type oacks and parameter integer / enum / bool /  packs. compile time variables expressions, functions and if then clauses.  Templated variables (pi<SimpleNumber).  
Strategy / axiom 
Design Type definitions to represent formal mathematical objects using template classes and functions and variables, templated operator definitions, and concepts. For functions and domains, differential operators, etc the definitions are for discretized versions of the objects.
Ansatz / claim
mathematics in C++20 can be written in symbolic form


Note that the inner working if Mathematiques are defined by modern formal mathematiques. The modern-formal-math naive user, however, can code by example. 

Only thing missing is support for unicode language tokens and certain unicode characters (greek, hebrew, blackboard, cyrillic) in symbol names + supports C++ operator definitions for the new tokens, with order of operations.

Don't use <MyConcept T> in template, use <typename T>  requires  (IsMyConcept<T>) so that we now can use T as a variable name.

Can also use T… parameter packs and out into tuple.


ConceptName auto x = from constructor;
ConceptName decltype(auto)
https://en.cppreference.com/w/cpp/language/auto


High performance implies
Fortran
C
C++

Rust
Carbon
Zip

There are many C++ numerical libraries and a few template numerical libraries already.

Template expressions, blitz++, mtl

Modern virtual and cloud computing make it easy to set up the exact linux o/s.  github, docker. Package managers and repo sites.  Gitlab, auto create. Can easily get packages for LAPACK, FFT, and even virtual machine o/s set up using Docker.

C++, much due to Boost, has many new features (const expr vars and functions, templated type aliases, concepts, tuples, numerical constants, special functions, type traits).  Var packs. Initializers lists. Named init lists.

FORTRAN:
Multiarrays, slices, complex number type. 
Index ranges
Vector operators and dot products built in
True Multi array indexing, unlike C
Debug compilation mode (bounds checks).
Named parameters!

MATLAB:
masks and index ranges
reshaping multiarray arrays
Taking pieces of multi arrays

PYTHON:
negative indexing
Slicing

Color syntax highlighting for ECHO

LaTex formatter for ETV expressions.  X_j is X<sub>j and X__j is X<sup>j

Functional programming
Template specializations and Concepts instead of class hierarchies

Solvers have default parameters and parameters can can specified using names init lists

Ubiquity of Color UNICODE terminals allows for much better printing of results.

g++ compiler optimizations much better
CPU must faster -> faster compile times

Use python for testing and for creating code from C++ boiler plates files.

New high-performance languages: Rust and Carbon. Time Start looking into math support.  LLVM toolchain

Structures for math objects like multivariable fields and tensors, quaternions, graded algebras, and lie groups.

Goes one step further than multi arrays by providing numerical data structures for discretitized mathematical functions and their calculus


Highest performance
Simple, elegant, looks like math
Easy to learn
Online auto-generated documentation
Debug and printing capabilities
Support Advanced structures : quaternions, tensors, vector fields, groups, graded algebras.

Gives the building blocks to write numerical code quickly.


| ⇦ <br />[About](../about/README.md)  | [Documentation](../README.md)<br />Why?<br /><img width=1000/> | ⇨ <br />[Objectives](../objectives/README.md)   |
| ------------ | :-------------------------------: | ------------ |

