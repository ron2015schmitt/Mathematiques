[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.032</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. _About_ <br>
Chapter 3. [Why?](../why/README.md)<br>
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



# Chapter 2. About



## History

Development for this project originally took place in very rough form during the years 2003-2008 using the C99/C++.

The code was resurrected in 2019: refactored, extended, improved, simplified, and updated with C++11, C++14, C++17 features.

In early 2020, the project was officially launched as _Mathématiques_ and uploaded to a github.

In 2022, the versioning was changed and the old code was moved to [Mathematiques-old](https://github.com/ron2015schmitt/Mathematiques-old) repo.


## Techniques

The code uses a form of C++ [template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming) called [expression templating](https://en.wikipedia.org/wiki/Expression_templates), the library provides computational efficiency on par with C/Fortran.

1. *Expression templating* produces complex code in the library itself, but the *user code* is simple, clean, and extremely efficient.
1. *Type traits* design pattern
1. *operator overloading*
1. using templates for all functions
1. _Avoid_ use of virtual functions completely to minimize size of instance in memory and run-time cost
1. avoid use of class hierarchies
1. use C++ *concepts* introduced in C++ 20 (constraints and requirements)

References
1. Andrei Alexandrescu, __Modern C++ Design: Generic Programming and Design Patterns Applied__, 2001.
2. David Vandevoorde, Douglas Gregor, Nicolai M Josuttis, __C++ Templates: The Complete Guide__, 2nd edition, 2018.

## Platform

The initial platform chosen is
* language
  1. C++20 or higher, necessary to create the syntax
* compiler
  1. GNU g++ compiler that supports C++20: 11.2 or later
* OS
  1. Linux: Ubuntu 22.04.1 LTS (unless you want to manually install g++ 11.2)
* packages
  1. LAPACK: for the more advanced linear algebra functions: matrix inverse, and decompositions

Other configurations are of course possible with modification.






| ⇦ <br />[License](../license/README.md)  | [Documentation](../README.md)<br />About<br /><img width=1000/> | ⇨ <br />[Why?](../why/README.md)   |
| ------------ | :-------------------------------: | ------------ |

