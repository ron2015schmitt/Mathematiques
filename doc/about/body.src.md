

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




