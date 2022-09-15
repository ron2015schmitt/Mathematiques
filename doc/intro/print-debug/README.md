[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.157-c++20</h1>](../../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Objectives](../../objectives/README.md)<br>
Chapter 4. [Status & Release Notes](../../status-release/README.md)<br>
Chapter 5. [Upcoming Development](../../development-schedule/README.md)<br>
Chapter 6. _Introduction with Examples_ <br>
Chapter 7. [Installation](../../installation/README.md)<br>
Chapter 8. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 9. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 10. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 11. [Tests](../../test/README.md)<br>
Chapter 12. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [6. Introduction with Examples](../README.md)<br>

6.1. _Pretty Printing and Debugging_ <br>
6.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
6.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
6.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
6.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
6.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
6.7. [Linear Algebra](../linear-algebra/README.md)<br>
6.8. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
6.9. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
6.10. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
6.11. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
6.12. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
6.13. [Tensors](../tensors/README.md)<br>
6.14. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.1. Pretty Printing and Debugging



## Pretty Printing to a Terminal
Mathématiques provides functions and macros for printing of ASCII and Unicode text that is cleanly formatted, colored and stylized.
Colors and styles require a terminal that support [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code). 
### ECHO for C++ statements
The `ECHO` macro prints the enclosed C++ statement to the stdout, in addition to the statement being compiled and included in the executable.
```C++
ECHO(int x = 5);
ECHO(double y = x * 3.1415);
```
The above C++ code will print the following to stdout in the terminal (actual screen capture):
| <sub>Light mode in Ubuntu WSL2 terminal on Windows</sub> |
| --- |
| ![echo](https://user-images.githubusercontent.com/11559541/189542553-6190eb19-ca59-4a1e-92a3-debd5aa71335.png) |


<br>

### ETV for C++ variables and expressions
`ETV` stands for 'Expression Type Value', and that is what it prints.  All results are preceded by the `☀` Unicode character to distinguish results from code.
```C++
ECHO(int x = 5);
ETV(x);
ETV(3 * 25 * std::sin(3.1415/20));
ETV(mathq::Vector<double> {1, 2, 3});
```
The above C++ code will print the following to stdout in the terminal (actual screen captures):

| <sub>Light mode in Ubuntu WSL2 terminal on Windows</sub> |
| --- |
| ![etv-light mode](https://user-images.githubusercontent.com/11559541/189542566-fcb8bd50-b9ea-4fcc-9c89-5b7c287d5487.png) |

| <sub>Dark mode in VS Code terminal</sub> |
| --- |
| ![etv-dark mode](https://user-images.githubusercontent.com/11559541/189542572-43356054-59e2-4861-9d35-a004dc1215b5.png) |


<br>

### GMD_CODEBOX for Markdown code box generation
The macros `GMD_CODEBOX_START` and `GMD_CODEBOX_END` can be used to create a codebox using the [github markdown language](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).
In fact these online documentation files are automatically created using C++ files, python scripts for the table of contents and numbering, and make files that put it all together during the build process.
The documentation is generated for every new version.
This ensures that results shown for every example in the documenation will match what you compile.
```C++
GMD_CODE_START("C++");
ECHO(int x = 5);
ECHO(mathq::Vector<double> v{1, 2, 3});
ETV(10*v + 100*x);
GMD_CODE_END();
```
The above C++ code generates text for the following markdown code box:
```C++
int x = 5;
mathq::Vector<double> v{ 1, 2, 3 };
☀ 10*v + 100*x ➜ Vector<double> {510, 520, 530};
```

<br>

### Other printing functionality
Other macros and functions are also available.
A full refactoring of the printing functionality is underway.

<br>

## Compilation Modes and Debugging Support
Mathématiques supports various compilations modes to aid in debugging using the tab `MATHQ_DEBUG`.


### Setting the compilation mode
To compile in DEBUG mode, include `MATHQ_DEBUG=n` with your make command, where `n` is the DEBUG level. 
Using `MATHQ_DEBUG=0` is equivalent to not specifying a value, ie the production compilation mode is used.
```make
make filename MATHQ_DEBUG=1
```
The makefile then adds `-D "MATHQ_DEBUG = n"` to the compiler options.

In the C++ code, compilation will take place with the [C++ preprocessor](https://cplusplus.com/doc/tutorial/preprocessor/) symbol `MATHQ_DEBUG` defined and set to `n`.
That is, it will be as if the line `#define MATHQ_DEBUG n` is include at the top of each source file.

<br>

### .compiler files
When a C++ source file is compiled, a file with the extension `.compiler` is generated.

This file contains the following information:
* a timestamp
* the Mathématiques build version
* the linux distro and version
* the compiler and version
* the full compile command with options

An example is shown below.
```bash
EXAMPLE (not current)
Mathématiques v0.41.143-c++20
Description:    Ubuntu 22.04.1 LTS
g++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0
g++ -pipe -std=c++20 -O3 -finline-limit=750 -Wfatal-errors -I /home/rs2015/Mathematiques/include
```

<br>

### Compiler and Build Information in C++ code
The following information is available in C++

| variable | type | description |
| --- | --- | --- |
| `__cplusplus` | pre-processor symbol | C++ version number |
| `MATHQ_DEBUG` | pre-processor symbol | Mathématiques debug mode value |
| `mathq::version`  | `char[]` | Mathématiques version string |

```C++
ETV(__cplusplus);
ETV(MATHQ_DEBUG);
ETV(std::string(mathq::version));
```
```C++
☀ __cplusplus ➜ long 202002;
☀ MATHQ_DEBUG ➜ int 0;
☀ std::string(mathq::version) ➜ std::string v0.41.157-c++20;
```
This information can also be printed using the function `display::print_mathq_info()`
```C++
display::print_mathq_info();
```
```C++
                                                                               
Mathématiques v0.41.157-c++20 

compile-time settings
  MATHQ_DEBUG 0 (production) 
  C++ version: 202002
                                                                               
```

<br>

### Current Status
✏ A full refactoring of the debug functionality is planned.
Currently all debug messages are disabled.


| ⇦ <br />  | [Introduction with Examples](../README.md)<br />Pretty Printing and Debugging<br /><img width=1000/> | ⇨ <br />[Number Systems and Arithmetic](../numbers/README.md)   |
| ------------ | :-------------------------------: | ------------ |

