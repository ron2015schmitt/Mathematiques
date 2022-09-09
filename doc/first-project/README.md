[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.132-c++20</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Chapter  Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Status, Planned Work & Release Notes](../status-release/README.md)<br>
Chapter 4. [Introduction with Examples](../intro/README.md)<br>
Chapter 5. [Installation](../installation/README.md)<br>
Chapter 6. _Your First Mathématiques Project_ <br>
Chapter 7. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 8. [Benchmarks](../benchmarks/README.md)<br>
Chapter 9. [Tests](../test/README.md)<br>
Chapter 10. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# Chapter 6. Your First Mathématiques Project


Now that you have completed installation, to use the Mathématiques library you need to 

1. Include the library file `include/mathq.h` in your source code
```C++
#include "mathq.h"
```
2. Include the `include/` subdirectory during compilation using the `-I` option

3. Include the `lib/` subdirectory during linking using the `-L` option

4. Include the option `-lmathq` during linking

## EXAMPLE Makefile

An example makefile, `example/Makefile`, is created during [configuration](configuration) for your convenience.

*AFTER CONFIGURATION*, copy this makefile to YOUR source code directory (or cut and paste into an existing makefile).

Here is an example of a [typical Makefile](doc/sample/Makefile).

## EXAMPLE Code File

An example of a C++ source file can be found at [examples/example.cpp](examples/example.cpp).

Compile the code and run the code using the Makefile
```bash
make example
./example
```


| ⇦ <br />[Installation](../installation/README.md)  | [Documentation](../README.md)<br />Your First Mathématiques Project<br /><img width=1000/> | ⇨ <br />[Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)   |
| ------------ | :-------------------------------: | ------------ |

