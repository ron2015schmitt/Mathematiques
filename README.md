

# Mathématiques v0.41.134-c++20


## Goal - Phase 1

Provide an extensive, open source, numerical C++ library that 
* provides compact data structures that represent mathematical objects and concepts
* allows for user code that looks like mathematical notation 
* provides state of the art performance (both speed and memory usage)
* supports convenient pretty printing of results (including data type information) as well as i/o in popular formats
* supports several compilation mdoes use command line flags and teh C++ macro preprocessor
* supports multi-threading
* stored on github and includes [CI](https://en.wikipedia.org/wiki/Continuous_integration) / [CT](https://en.wikipedia.org/wiki/Continuous_testing)

The above goals are accomplished, in part, by following the definitions of modern formal mathematics.

Of course, the user can also use standard C++ syntax and libraries in combination with Mathématiques.

## Goals - Phase 2

Create a new language that implements the phase 1 library above plus
* supports unicode characters in source code 
  + supports greek language characters for variables
  + supports operator definitions for mathematical unicode symbols so that the code really looks like mathematical notation
  + also has multi-character ASCII symbols for each unicode symbol
* has an http interface
* has a modern package loader
* has a package repository site, eg [npm for NodeJs](https://www.npmjs.com/) for user-created open-source packages

The current language candidates to build upon are [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)) and [Carbon](https://en.wikipedia.org/wiki/Carbon_(programming_language)).

## Documentation

✳ [Introduction with Examples](doc/intro/README.md)

[Full Documentation](doc/README.md)



