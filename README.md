

# Mathématiques v0.41.138-c++20


## Phase 1 (in progress): C++ Numerical Library
 
 
Create an extensive, open source, numerical C++ library that 

* provides compact **data structures** that represent **mathematical objects** 
* allows for user **code that looks like mathematical notation**
* provides **state of the art performance** (both speed and memory usage)
* supports convenient **pretty printing of results** including **data type information**
* supports several **compilation modes** (DEBUG, PRODUCTION) via command line flags and the C++ macro preprocessor
  + **DEBUG mode** checks bounds, vector and matrix sizes, etc and generate clear, pretty printed errors to stderr
  + **PRODUCTION mode** runs as without any checks
* supports  **i/o in popular formats**
* maintained via opened-source **github** repo 
* includes **extensive automated tests** 
* [**Continuous Integration**](https://en.wikipedia.org/wiki/Continuous_integration) / [**Continuous Texting**](https://en.wikipedia.org/wiki/Continuous_testing)

The above goals are accomplished, in part, by 
* following the **definitions of modern formal mathematics** and 
* using the techniques of **modern C++** (ie C++11, C++14, C++17, and C++20).

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
* has an http interface
* has a modern package loader
* has a package repository site, eg [npm for NodeJs](https://www.npmjs.com/) for user-created open-source packages

The current language candidates to build upon are [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)) and [Carbon](https://en.wikipedia.org/wiki/Carbon_(programming_language)).

