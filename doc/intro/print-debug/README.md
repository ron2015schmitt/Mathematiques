[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.140-c++20</h1>](../../../README.md)

<details>

<summary>Documentation</summary>

# [Chapter  Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Status, Planned Work & Release Notes](../../status-release/README.md)<br>
Chapter 4. _Introduction with Examples_ <br>
Chapter 5. [Installation](../../installation/README.md)<br>
Chapter 6. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 7. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 8. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 9. [Tests](../../test/README.md)<br>
Chapter 10. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [4. Introduction with Examples](../README.md)<br>

4.1. _Pretty Printing and Debugging_ <br>
4.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
4.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
4.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
4.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
4.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
4.7. [Linear Algebra](../linear-algebra/README.md)<br>
4.8. [Sorting, Masks, Slices, etc.](../sort-mask-slice/README.md)<br>
4.9. [Mathematical functions](../math-functions/README.md)<br>
4.10. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
4.11. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
4.12. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
4.13. [Tensors](../tensors/README.md)<br>
4.14. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 4.1. Pretty Printing and Debugging



## Pretty Printing to a terminal
Mathématiques provides printing of ASCII and Unicode text that is cleanly formatted, colored and stylized.
Colors and styles require a terminal that support [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code). 
## ECHO() for C++ statements
The `ECHO` macro prints the enclosed C++ statement to the stdout, in addition to the statement being compiled and included in the executable.
```C++
ECHO(int x = 5);
ECHO(double y = x * 3.1415);
```

<br>

The above C++ code will print the following the terminal (actual screen capture):
[image]
## ETV() for C++ variables and expressions
`ETV` stands for 'Expression Type Value', and that is what it prints.  All results are preceded by the `☀` Unicode character to distinguish results from code.
```C++
ECHO(int x = 5);
ETV(x);
ETV(3 * 25 * std::sin(3.1415/20));
ETV(mathq::Vector<double> {1, 2, 3});

```

<br>

The above C++ code will print the following the terminal (actual screen captures):

int x = 5;
☀ x ➜ int 5;
☀ 3 * 25 * std::sin(3.1415/20) ➜ double 11.7322;
☀ mathq::Vector<double> {1, 2, 3} ➜ Vector<double> {1, 2, 3};

Light mode in Ubuntu WSL2 terminal on Windows
[image]
Dark mode in VS Code terminal
[image]
## Markdown code box generation
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

<br>

The above C++ code generates the following markdown code box:
```C++
int x = 5;
mathq::Vector<double> v{ 1, 2, 3 };
☀ 10*v + 100*x ➜ Vector<double> {510, 520, 530};
```

<br>

Other macros and functions are also available, including macros that aid in creating[github markdown]() files.
A full refactoring of the printing functionality is underway.
## Compilation Modes and Debugging Support
Mathématiques supports various compilations modes to aid in debugging:
```C++
unsigned int n = 23;
☀ n ➜ unsigned int 23;
☀ n + 102 - 2*4 ➜ unsigned int 117;
☀ n - 24 ➜ unsigned int 4294967295;
☀ n/2 ➜ unsigned int 11;
☀ n % 2 ➜ unsigned int 1;
```

<br>

A full refactoring of the printing functionality is planned.  Currently all debug messages are disabled until the printing code is refactored.
However, the `` preprocessor symbol can be utilized in user code at present.


| ⇦ <br />  | [Introduction with Examples](../README.md)<br />Pretty Printing and Debugging<br /><img width=1000/> | ⇨ <br />[Number Systems and Arithmetic](../numbers/README.md)   |
| ------------ | :-------------------------------: | ------------ |

