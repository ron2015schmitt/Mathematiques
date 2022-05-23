<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.50-c++17</h1>

<details>

<summary>User Guide</summary>

# [User Guide](../README.md)<br>
1. [About](../about/README.md)<br>
2. [License](../license/README.md)<br>
3. [Release Notes](../release-notes/README.md)<br>
4. [Installation](../installation/README.md)<br>
5. [Makefile / Using Mathématiques](../using-mathematiques/README.md)<br>
6. [Code Examples](../examples/README.md)<br>
7. [Coding Guide / Syntax](../coding-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. _New Feature Plans_ <br>
11. [Developer Guide](../developer-guide/README.md)<br>


</details>



# 10. New Feature Plans

## Planned Releases


### v3.5 Documentation Refactoring
1. add variable for the C++ version used, currently C++17.  append to version string. 
2. Complete _Coding Guide_, covering all the functionality
3. New in-depth _Developer Guide_

### v3.6 Indexing Refactoring
1. Refactor of vector/matrix/tensor indexing, including
  + new index/iterator types such as slices similar to Fortran and Python
  + [Index class and new indexing methodology](topics/index.md)

### v3.7 Display Refactoring
1. This is includes files:
  * display.h
  * display.cpp
1. add support for std::tuple
1. move ostream operators guts to FormatData:  `stdout << Vector` etc
1. implement istream operators:  `stdin >> Vector` etc
1. refactor Style, StyledString, Terminal, and Display, Log
  1. reformat all files using VSCode C++ extension
  1. StyleStrgn should allow chnage of the Style
  1. replace anti-pattern `*(new Display())` as `Display()` for all classes. This is not Java
  1. don't use pointers
  1. DISPLAY: Allow to use different strigns for ```=``` and ```;``` when displaying results by adding ability to chaneg expression SyledString etc
    * have profiles for text ("->", ""), matlab ("=", ";"), mathematica ("=", ";")
  1. take advantage of std::optional<T> for optional arguments
1. [Refactor MOUT and dout](topics/refactormout.md)
1. Group macros together, as much as possible. Clearly notate in a specific section in the documentation.
1. [Refactor getTypeName](topics/gettypename.md)
1. [Refactor FormatData](topics/formatdata.md)
1. Fix Printing of ```complex<Vector<double>>>``` etc
1. Make sure data type to output of inner products works
  * DISP(v1 | v2) = Vector<double> {16, -6}; 
  * DISP(M1 | v2) = ^Vector<double>^ {-10, -10};  # missing part between the ^'s
1. [Tensor class FormatData](topics/tensorformatdata.md)
   1. compact 
   1. by aligned rows and columns with and without braces
   1. Mathematica
   1. Matlab
   2. python
1. move the SPECIALIZE_getTypeName into .h file and python script

### v3.8 I/O Refactoring
1. [Save tensor to file](topics/filesave.md)
1. [Implement >> operators](topics/inputstreams.md)
1. [Load tensor from file](topics/fileload.md)

### v3.9 Debug Refactoring
1. put example.cpp::printoptsfile  into  print_mathq_info by grabbing (or passing) the file_name
  * handle when no filename
  * handle when no .g++_copts file
1. [Create Tensor Pool and Tensor info](topics/poolandinfo.md)
1. [Exceptions and Assertions](topics/exceptions.md)
1. [Implement all error checking](topics/errorchecking.md)
1. Implement `VectorOfPtrs` code properly
   * should only be included in debug mode
   * only needed for non-elemental functions
   * only needed when same vector appears on both sides of `=`



### Miscellaneous Small Features
* BUG: let  `v = Vector<Quaternion<double>>`
  * `(exp(v) + int)` works
  * `(exp(v) + double)` works
  * `(exp(v) + complex)` works
  * `(exp(v) + quaternion)` doesn;t compile
* use https://doxygen.nl/manual/docblocks.html os similar to generate method and function docs?
* reformat all files using VSCode plugin
* all objects should ave .invert() and conjugate(), not .inv and .conj
* inv<D>(D x) for real, integers, imaginar, complex, quaternion
* make all temp README.md files read-only
* refactor the headers so that 
  * vectors, matrices display tensors Scalar are broken out into different headers
  * use copious #ifdefs so that order of inclusion matters
* User Guide: create an index, with denotation for `types`, `functions`, `operators`
* Create a `Number` class to generalize (division alegra numbers) real,s imaginary and complex, quaternions?
  * see https://en.cppreference.com/w/cpp/types/is_arithmetic
  * <complex> C++ std::complex
    * https://en.cppreference.com/w/cpp/numeric/complex
    * https://en.cppreference.com/w/cpp/numeric/complex/operator%22%22i
  * <complex.h> C macros
    * https://en.cppreference.com/w/c/numeric/complex
    * https://en.cppreference.com/w/c/numeric/complex/complex
    * https://en.cppreference.com/w/c/numeric/complex/imaginary
    * https://en.cppreference.com/w/c/numeric/complex/I
* Refactor `NumberType` etc to use constexpr fields instead of static methods
* overload `^` as exponentiation for vectors and matrices?
* pow(container, scalar)
* pow(container, container)
* dotel(container1, container2, depth): depth specifies at what level the dot product takes place
* implement adjoint(Matrix) and ~(Matrix)
* `+=`, `-=`, `*=`, `/=`, operators for all tensors
* `logspace` function similar to `matlab`
* element wise dotproducts (in process)
* refactor: `::Type` to `::type`
* Add support for the rest of the [common math functions](https://en.cppreference.com/w/cpp/numeric/math) introduced in `C++11` and `C++20`: `frexp`, `isnan` etc, `ldexp`, `logb`, `ilogb`, `modf`, `div`, `remiander`, `remqou`, `fmod`, `ispow2`, `trunc`, `nearbyint`, `ceil2`, `floor2`, etc.
* `TensorRW` implementation of `real(t)` and `imag(t)`
* `TensorRW` implementation of `A.row(r)` and `A.col(r)`
* `Matrix` constructor and assignment using parameter pack (or list?) of `Vector`, as either cols or rows
* Modify Taylor Series to operate at top level (not deep level.)  Test with Scalar<Matrix> and Vector <Matrix> 
   * dat(i) must call [i].
   * perhaps have a boolean in all TensorR subclasses that denotes which is faster: [i] or dat(i)
* `Vector` size modifications. Refer to [C++ Containers library](https://en.cppreference.com/w/cpp/container)
   * implement `join` functions for Vector and a scalar
   * Implement `insert(i)`, `remove(i)`,`pop_front`,`push_front`, `pop_back`,`push_back`, methods to `Vector` class
   * `NE == -1` -> use `std::vector` for storage
   * `NE == -2` -> use `std::list` for storage
   * `NE == -3` -> use `std::forward_list` for storage
   * `NE == -4` -> use `std::stack` for storage
   * `NE == -5` -> use `std::froward_stack` for storage
* `Matrix` size modifications. 
   * Implement `insertRow/Col(i)`, `removeRow/Col(i)`,`pop_top/bot`,`push_top/bot`, `pop_left/right`,`push_left/right`, methods to `Matrix` class
   * support column major matrices and tensors
* add latex helper functions for disp?


## Futrue work

### Unit testing
1. [Unit Testing](unittesting.md)
2. list requirements to perform testing in about section of top-level README

### Continuous Integration (CI) / Contunous Testing (CT)
1. set up CI / CT on [Github Actions](https://docs.github.com/en/actions) and using Docker 


### Calculus
1. `Interval` virtual class with subclasses `AB(a,b,N)`, `aB(a,b,N)` etc
1. Generalize linspace to generate grids in any number of dimensions. 
  * utilize `RepColMatrix` and `RepRowMatrix`
1. Integrals and derivatives along each dimension of Matrix or Tenspr
   *  best way to re-use code?

### Matrix Math via Lapack/Blas
1. [Special matrices](topics/diagonal.md)
  * use python script to generate matrix code
1. [Matrix operations](topics/matrixlapack.md)
1. openblas multi-threading support?
1. Optimize Dot Products for Special Matrices
* use LAPACK / BLAS where efficacious to do so


### Tensor Products
1. [Tensor dot product](topics/dotproduct.md)
1. [Outer Product and Wedge Product](topics/outerwedge.md)
1. [Add Benchmarks](topics/benchmarks.md)


### Vector Calculus
1. [2D and 3D Curvilinear Coordinate Systems](topics/coordsystems.md)
1. [Functions: R^n -> R^m](topics/functions.md)



### Tensor Calculus 
1. contravariant and covariant vectors
   * define Rank0: 
      * Vector<NE=1>
   * define Rank1<N,bool>: 
      * Matrix<N,1> for bool=true (contravariant/high indices)
      * Matrix<1,N> for bool=false (covariant/low indices)
   * define Rank2<N,bool,bool>: 
      * Tensor<R=4> with dimenions (N,1,N,1) for <true,true> 
      * Tensor<R=4> with dimenions (N,1,1,N) for <true,false> 
      * Tensor<R=4> with dimenions (1,N,N,1) for <false,true> 
      * Tensor<R=4> with dimenions (1,N,1,N) for <false,false>  
1. Use compomnent-free notation  for inner products (Misner, Wheeler, Thorne; Frankel)
     
1. generalized coordinate systems
   * basis vectors
   * metric tensor
   * index contraction / dot products
   * raising and lowering operations using the metric tensor
   * currying

### FFT Support via FFTW

### Filters 
1. FIR
1. IIR

### Interpolation and Smoothing

1. Linear using `C++20` functions `midpoint` and `lerp`
1. least squares smoothing and derivatives
1. [Savitsky-Golay](https://en.wikipedia.org/wiki/Savitzky%E2%80%93Golay_filter)
1. splines

### Random Numbers and statistics
* Random vectors for variety of distrubutions
   * utilize [C++11 random distributions functionality](https://en.cppreference.com/w/cpp/numeric/random)
* statistics: multiple linear regression, polynomial least-squares fitting (vandermonde matrix), pricples components analysis



### Possibilities
* investigate use of [swap](https://en.cppreference.com/w/cpp/algorithm/swap)
* investigate use of [multi-threading](https://en.cppreference.com/w/cpp/thread/thread)
* new functions
  * spherical harmonics
* Support other division algebras data types
   * Octonions
* Graded algebras, such as Clifford Algebras
   * use of Clifford Algebra for Computer Graphics applications
* Create a [new Programming language](topics/newlanguage.md) based on Mathématiques

### New C++ features
* Ubuntu 20.04 uses GCC 9.4 which implements C++17 and some of C++20

* C++11 features see [c++11 features](https://en.cppreference.com/w/cpp/11) and [compiler support](https://en.cppreference.com/w/cpp/compiler_support/11) and [GCC C++11 Status](https://gcc.gnu.org/projects/cxx-status.html#cxx11)
  * GCC 5.X supports all C++11
  * [exact rational arithmatic](https://en.cppreference.com/w/cpp/numeric/ratio/ratio)
  * [tuples](https://en.cppreference.com/w/cpp/utility/tuple)

* C++14 features see [c++14 features](https://en.cppreference.com/w/cpp/14) and [compiler support](https://en.cppreference.com/w/cpp/compiler_support/14) and [GCC C++14 Status](https://gcc.gnu.org/projects/cxx-status.html#cxx14)
  * GCC 5.X supports all C++11
  * [variable templates](https://en.cppreference.com/w/cpp/language/variable_template)

* C++17 features see [c++17 features](https://en.cppreference.com/w/cpp/17) and [compiler support](https://en.cppreference.com/w/cpp/compiler_support/17) and [GCC C++17 Status](https://gcc.gnu.org/projects/cxx-status.html#cxx17) 
  * GCC 7.X supports all of C++17, except
    * [to_chars, from_chars, chars_format](https://en.cppreference.com/w/cpp/utility#Elementary_string_conversions) in GCC 8 and 11
    * [Hardware interference size](https://en.cppreference.com/w/cpp/thread/hardware_destructive_interference_size) in GCC 12
    * [Standardization of Parallelism TS](https://wg21.link/P0063R3) in GCC 9
    * [C++17 should refer to C11 instead of C99](https://en.cppreference.com/w/cpp/header/memory_resource) in GCC
    * [Polymorphic memory resources]() in GCC 9
    * []() in GCC
  * [lambdas](https://en.cppreference.com/w/cpp/language/lambda) enhanced in C++20
  * [inline (templated) variables](https://en.cppreference.com/w/cpp/language/inline)

* C++20 features. see [c++20 features](https://en.cppreference.com/w/cpp/20) and [compiler support](https://en.cppreference.com/w/cpp/compiler_support/20) and [GCC C++20 Status](https://gcc.gnu.org/projects/cxx-status.html#cxx20)
  * GCC Started C++20 in 8.X continues through at least 12.X 
  * [feature `<version>` macros](https://en.cppreference.com/w/cpp/header/version)
  * [Mathematical constants](https://en.cppreference.com/w/cpp/numeric/constants)
  * `a <=> b` [three-way operator (-1,+1,0)](https://en.cppreference.com/w/cpp/language/operator_comparison#three-way-comparison)). need GNU 10 
  * immediate functions: [consteval](https://en.cppreference.com/w/cpp/language/consteval)
  * [`std::type_identity`](https://en.cppreference.com/w/cpp/types/type_identity)
  * [modules](https://en.cppreference.com/w/cpp/language/modules)
  * [constinit](https://en.cppreference.com/w/cpp/language/constinit)
  * [aggregate initialization enhancements](https://en.cppreference.com/w/cpp/language/aggregate_initialization)
  * [is_constant_evaluated](https://en.cppreference.com/w/cpp/types/is_constant_evaluated)
  * [coroutines](https://en.cppreference.com/w/cpp/language/coroutines)
  * [concepts and constraints](https://en.cppreference.com/w/cpp/language/constraints)
  * [Class template argument deduction for alias templates](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1975r0.html)
  * `__VA_OPT__` for preprocessor comma elision
* C++23 features. see [c++23 features](https://en.cppreference.com/w/cpp/23) and [compiler support](https://en.cppreference.com/w/cpp/compiler_support/23) and [GCC C++23 Status](https://gcc.gnu.org/projects/cxx-status.html#cxx23)
  * multidimensional array operator
  * Consistent character literal encoding
  * if consteval
  * Non-literal variables (and labels and gotos) in constexpr functions
* C++ Experimental
  * [Transactional Memory](Transactional Memory)

 
### Contact

To contact me regarding suggestions, bugs, or volunteer work send an email to `Ron dot Schmitt @ me dot com`



| ⇦ <br />[Tests](../test/README.md)  | [User Guide](../README.md)<br />New Feature Plans<br /><img width=1000/> | ⇨ <br />[Developer Guide](../developer-guide/README.md)   |
| ------------ | :-------------------------------: | ------------ |

