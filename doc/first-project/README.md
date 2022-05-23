<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.78-c++17</h1>

<details>

<summary>User Manual</summary>

# [User Manual](../README.md)<br>
1. [About](../about/README.md)<br>
2. [License](../license/README.md)<br>
3. [Status, Planned Work & Release Notes](../status-release/README.md)<br>
4. [Description and Example Usage](../description-examples/README.md)<br>
5. [Installation](../installation/README.md)<br>
6. _Your First Mathématiques Project_ <br>
7. [Usage Guide: Syntax, Data Types, Functions, etc](../usage-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# 6. Your First Mathématiques Project


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


| ⇦ <br />[Installation](../installation/README.md)  | [User Manual](../README.md)<br />Your First Mathématiques Project<br /><img width=1000/> | ⇨ <br />[Usage Guide: Syntax, Data Types, Functions, etc](../usage-guide/README.md)   |
| ------------ | :-------------------------------: | ------------ |

