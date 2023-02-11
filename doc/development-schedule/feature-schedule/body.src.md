## Planned Work


### bugs 
1. `numtrue(!(v > 2))`  does not compile
1. `auto err = abs(result1-result2)`  err becomes an expression not a MultiArray, see `doc/intro/vector-calculus/body.cpp`
1. allow a  multiarray with elements `complex<double>` be set equal to a `double`
1. `ETV(sin(f));` does not work. f is NumericalFunction. see `doc/intro/multi-var-calculus/body.cpp`
1. `g = d(sqrt(f))` does nto work for f and g are NumericalFunction. see `doc/intro/multi-var-calculus/body.cpp`

```C++
    // these compile and work
    g = x + 2*f - d(f);
    g = d(f);
    g = sqrt(f);
    g = sqrt(d(f));

    g = d(sqrt(f)); // <-- does NOT compile
```
1. `real` and `imag` of ComplexFunction doesn't work

```C++
    ComplexCoords<double, false> coords({
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 5)
      });
    ETV(coords);
    // ComplexMathFunction<std::complex<double>> field0(coords);
    ComplexMathFunction<std::complex<double>, decltype(coords)> field(coords);
    ComplexMathFunction<std::complex<double>, ComplexCoords<double, false>> field2({
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 5)
      });

    ECHO(auto& z = coords.z());
    ECHO(field = exp(z));  // shoudl be field = 
    ETV(field);
    ETV(real(field));
    ETV(imag(field));
```


### Tensor Fields and Calculus in general coordinates 
1. contravariant and covariant vectors
   * define Rank0: 
      * Vector<NE=1>
   * define Rank1<N,bool>: 
      * Matrix<N,1> for bool=true (contravariant/high indices)
      * Matrix<1,N> for bool=false (covariant/low indices)
   * define Rank2<N,bool,bool>: 
      * MultiArray<R=4> with dimenions (N,1,N,1) for <true,true> 
      * MultiArray<R=4> with dimenions (N,1,1,N) for <true,false> 
      * MultiArray<R=4> with dimenions (1,N,N,1) for <false,true> 
      * MultiArray<R=4> with dimenions (1,N,1,N) for <false,false>  
1. Use compomnent-free notation  for inner products (Carroll; Misner, Wheeler, Thorne; Frankel)
1. `g(o,v)` notation
1. `contract(t1,t2,{i1,i2})`
1. generalized coordinate systems
   * basis vectors
   * metric tensor
   * index contraction / dot products
   * raising and lowering operations using the metric tensor
   * currying
1. Define k-vector fields 
  * wedge product
  * Hodge dual


## Future work

### Documentation Refactoring
1. Complete _Usage Guide_ covering all the functionality
1. New in-depth _Developer Guide_

### Display Refactoring
1. This is includes files:
  * display.h
  * display.cpp
1. utilize `static ClassName()` in addition to instance `classname()`. How does inheritance effect this?  DO the same for styling of class name
1. support wstrings. look at  [Consistent character literal encoding](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2316r2.pdf)
1. include &, ConstLeft, ConstRight, &&, and volatile qualifiers
  * dispatch to different functions using a type teaits technique, is_const<int>::value etc (instead of calling getTypeName directly)
  * refer to sandbox/parmpacktwo.cpp
  * use this to check that AddQualifiers works properly
1. split files, rename display namespace to mathq::text and mathq::streams
1. add support for std::tuple
1. all classes should have ostream operators:  `stdout << Vector` , and then dispval_strm should simply call
1. use `{}` for element lists. 
1. use [Formatting library of C++20](https://en.cppreference.com/w/cpp/utility/format)
1. support json format: use OPEN and CLOSE definitions for `{`. use EQUAL parameter `{ data: 25, name: "Joe" }`, ie `${OPEN} data${EQUAL}, name${EQUAL} "Joe" ${CLOSE}`
  1. How hard would it be to do string interpolation?
1. do same for getTypeName?
1. implement istream operators:  `stdin >> Vector` etc
1. refactor Style, StyledString, Terminal, and Display, Log
  1. reformat all files using VSCode C++ extension
  1. StyleStrgn should allow chnage of the Style
  1. don't use pointers
  1. DISPLAY: Allow to use different strigns for ```=``` and ```;``` when displaying results by adding ability to chaneg expression SyledString etc
    * have profiles for text ("->", ""), matlab ("=", ";"), mathematica ("=", ";")
  1. take advantage of std::optional<T> for optional arguments?
1. [Refactor MOUT and dout](topics/refactormout.md)
1. Group macros together, as much as possible. Clearly notate in a specific section in the documentation.
1. [Refactor getTypeName](topics/gettypename.md)
  * move the SPECIALIZE_getTypeName into .h file and python script. shorten to typename_str
1. [Refactor FormatData](topics/formatdata.md)
1. Fix Printing of ```complex<Vector<double>>>``` etc
1. Make sure data type to output of inner products works
  * ETV(v1 | v2) = Vector<double> {16, -6}; 
  * ETV(M1 | v2) = ^Vector<double>^ {-10, -10};  # missing part between the ^'s
1. [MultiArray class FormatData](topics/tensorformatdata.md)
   1. compact 
   1. by aligned rows and columns with and without braces
   1. Mathematica
   1. Matlab
   2. python
* add default arg so that it can be called without arguments
* need to fix up printing of nested MultiArrays: need to add an argument: indent_string = ""
* each MultiArray should have a dynamic cast to a list
* need function in display that converts (nested) lists to a string
* need to parse string lists into a list
* need to fix up printing of nested MultiArrays: need to add an argument: indent_string = ""
* each MultiArray should have a dynamic cast to a list
* need function in display that converts (nested) lists to a string
* use [std::source_location](https://en.cppreference.com/w/cpp/utility/source_location) in `log` functions
* optional command to print tensors as 2.35 ∇r + 3.43 ∇θ,  or  ∂x/∂r  etc and vector calc 2.35 r̂ + 3.43 θ^
* print expression classname preluded by the concrete type
* full support for ETV (expression type value) in every combination
* display_strm with no coloring option
* use C++ latex rednering library pus image display command like sudo apt install feh
* otpion to print strign with enclosing ""


### Test memory usage and speed (benchmarks) of a variety of usages and optimizerefactor as necessary
1. create benchmarks, include display of memory sizes
1. test speed of size_t indexing vs unsigned int indexing. Does compiler optimize for small fixed-size MultiArrays ?

### Indexing Refactoring
1. Refactor of vector/matrix/tensor indexing, including
  + support for constexpr bool column_major;
  + new index/iterator types such as slices similar to C++ stdlib, Fortran, and Python, including negative indices
  + [Index class and new indexing methodology](topics/index.md)
  + slices to get row or col of matrix
  + dope vector
  + use [C++20 Ranges](https://en.cppreference.com/w/cpp/ranges)
1. add vararg constructor for Dimensions or parameter pack 
1. consts: `o` and `all`
  + test by grabbing rows and cols of a Matrix
  + test by grabbing submatrix of a Matrix
  + test submatrix of rank=3
1. Is this correct for defining access to expressions? WHy is this different from MultiArray objects?
```C++
    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const Number dat(const size_t i) const {
      return derived().dat(i);
    }

    Number& dat(const size_t i) {
      return derived().dat(i);
    }

    // **********************************************************************
    // ***************** Element ACCESS *************************************
    // **********************************************************************

    const Element operator[](const size_t i) const {
      return derived()[i];
    }

    Element& operator[](const size_t i) {
      return derived()[i];
    }

    const Element operator[](const Indices& inds) const {
      return (*this)[inds.index(dims())];
    }

    Element& operator[](const Indices& inds) {
      return (*this)[inds.index(dims())];
    }
```
1. find a more succinct way to pass Dimensions to MultiArrays, currently its `MultiArray<double,3> A(Dimensions({2,3,4}))`
1. look into [Multidimensional subscript operator](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2128r6.pdfs)
1.  need to support indexing with the dimension=1 indices skipped via a new Indices method for Indices with dimension(s) = 1. 
  * see `verify` method of `MultiArray_RepeatVector`


### I/O Refactoring
1. [Save tensor to file](topics/filesave.md)
1. [Implement >> operators](topics/inputstreams.md)
1. [Load tensor from file](topics/fileload.md)


### Debug Refactoring
1. put example.cpp::printoptsfile  into  print_mathq_info by grabbing (or passing) the file_name
  * handle when no filename
  * handle when no .g++_copts file
1. [Create MultiArray Pool and MultiArray info](topics/poolandinfo.md)
1. [Exceptions and Assertions](topics/exceptions.md)
1. [Implement all error checking](topics/errorchecking.md)
1. Implement `VectorOfPtrs` code properly
   * should only be included in debug mode
   * only needed for non-elemental functions
   * only needed when same vector appears on both sides of `=`





### Miscellaneous Small Features
* differentiation
  * support any derivative stencil size for both uniform and and non-uniform grids
  * support causal (backward stencil), anti-causal (forward stencil), and non-causal (centered stencil) functions
  * support periodic Neumann [boundary conditions](https://en.wikipedia.org/wiki/Boundary_value_problem)
* look into && and forwarding
* add `static inline std::string ClassName()` to each class. see `Vector` for how to set up
* change replaceable strings in include-templates files from ##NAME## to __NAME__ so as to make syntax highlighting work properly
* create template versions of all C++ functions so that there is never overload ambiguity. Put inside namespace
  * use python to create
```C++
  template <class DIN>
  auto test(DIN x) {
    return std::exp(x);
  }
  template <>
  auto test<float>(float x) {
    return std::exp(x);
  }
  template <>
  auto test<long double>(long double x) {
    return std::exp(x);
  }
  // this seems to works for ints. if problems, use a helper class to determine which exp to call: expf expl, exp
```
* inv<D>(D x) for real, integers, imaginar, complex, quaternion
* make all temp README.md files read-only
* `operator=`.  have a constexpr that allows / disallows resizing durign equals. or resizable(x) =, where sizable gives an ExpressionRW
* add contraction product for rank>2 tensors whereby the contraction indices are specified 
* same but contacrt over mor ethan one indices
* implement functionality of matlab `cat`, `horzcat`, `vertcat`, `permute`, `repmat`, `squeeze`, and `reshape` commands
* conjugate OPERTOR~ for real ints wil give negative!!  make sure you dont take ~ of built-in types.  Use C++20 `requires` ?
* what about equals for (double = 0) == Imaginary<double>(0)? How shoudl this be defined?
* refactor the headers so that 
  * vectors, matrices display tensors Scalar are broken out into different headers
  * use copious #ifdefs so that order of inclusion matters
  * use [C++20 modules](https://en.cppreference.com/w/cpp/language/modules)?
* reformat all files using VSCode plugin: all done except sandbox

* constant `MultiArray`, ie every element is the same.  Matrix and Vector versions should inherit
* Grid stuff
  * 2D
    * Change GridType to use MatRep 
  * 3D
    * create MultiArray3 for xyz: (rows,columns, floors)
    * MArray3Rep
  * 3D
    * create MultiArray4 for xyzt: (rows,columns, floors, moments)
    * MArray4Rep
*  `class` -> `typename` usage in templates?

* constants in `namespace mathq::unit_imaginary`, `namespace mathq::unit_quaternion` should be template<SimpleNumber> constexpr variables

* units for numbers using [std::chrono](https://en.cppreference.com/w/cpp/chrono/duration) and [user-defined literals](https://en.cppreference.com/w/cpp/language/user_literal). See also Boost.
* formalize template notation for the following: types with ordering (ints and reals), division algebras, Multiarrays, Tensors
* refactor `NumberTrait` replacement functionality into a separate class `ReplaceNumber`
* use https://github.com/cheshirekow/kwargs for named arguments?
* replace std::enable_if<std::is_arithmetic<D>::value, D>::type> with mathq version that accepts Imaginary and Quaternions
* cast method for const std::initializer_list<E>?  is this possible
* use https://doxygen.nl/manual/docblocks.html os similar to generate method and function docs?
* all objects should have .invert() and conjugate(), not .inv and .conj
* Complex,Imaginary, Quaternion types that inherit from MArrays
  * just need to redefine * and / and define extras
  * can then allows complex, imaginary and quaternion to hold vectors 
    * resolve what would v1 + i*v2 be?  Vector<complex<D>> or complex<Vector<D>> similar to dot product issues
  * need to prevent nesting Complex, Imaginary, Quaternion, ie only 0 or one allowed in nest
    * static assert using a new type trait
  * modify NumberTrait, SimpleNumber, InversionType class
  * need AddType etc for auto-promotion 
    * do we have promotion AddType for Scalar + Vector?  we should.
* cast between various multi-arrays
  * https://en.cppreference.com/w/cpp/language/cast_operator
  * completed: MArray Constructor from Vector in multi-array.h
      // ************* Vector Constructor---------------------
    template <int NE>
    MultiArray<E, R, D, M>(const Vector<E, NE, D, M>& v) {
      resize(v.recursive_dims());
      for (int c = 0; c < v.total_size(); c++ ) {
        (*this)[c] = v[c];
      }
      constructorHelper();
    }
  * completed: cast Vector as MultiArray  in vector.h
    operator MultiArray<E, R, D, M>() const {
      MultiArray<E, 1, D, M> ma(*this);
    }
  * testing is in sandbox/multiarrays-conversion.cpp 
  *  what about expresssions? 
    * Can we have Constructor for Vector, Matrix, Exp from expressions?
    * Can we cast expressiosn to these?
  * Look into fixing or removing the enums for all multi-arrays


* Create a `Number` class to generalize division alegras (real's imaginary and complex, quaternions)?
  * see https://en.cppreference.com/w/cpp/types/is_arithmetic
  * <complex> C++ std::complex
    * https://en.cppreference.com/w/cpp/numeric/complex
    * https://en.cppreference.com/w/cpp/numeric/complex/operator%22%22i
  * <complex.h> C macros
    * https://en.cppreference.com/w/c/numeric/complex
    * https://en.cppreference.com/w/c/numeric/complex/complex
    * https://en.cppreference.com/w/c/numeric/complex/imaginary
    * https://en.cppreference.com/w/c/numeric/complex/I

* MultiArray<D> constructed from MultiArray<D,N> as well as equals
  * WHy does Vector<MultiArray<D,2>> create MultiArray<D> (R=0)?
* Refactor `NumberTrait` etc to use constexpr fields instead of static methods
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
* `ExpressionRW` implementation of `real(t)` and `imag(t)`
* `ExpressionRW` implementation of `A.row(r)` and `A.col(r)`
* `Matrix` constructor and assignment using parameter pack (or list?) of `Vector`, as either cols or rows
* Modify Taylor Series to operate at top level (not deep level.)  Test with Scalar<Matrix> and Vector <Matrix> 
   * dat(i) must call [i].
   * perhaps have a boolean in all ExpressionR subclasses that denotes which is faster: [i] or dat(i)
* `Vector` size modifications. Refer to [C++ Containers library](https://en.cppreference.com/w/cpp/container)
   * implement `join` functions for Vector and a scalar
   * Implement `insert(i)`, `remove(i)`,`pop_front`,`push_front`, `pop_back`,`push_back`, methods to `Vector` class
   * `NE == -1` -> use `std::array` for storage (fixed size)
   * `NE == -2` -> use `std::vector` for storage
   * `NE == -3` -> use `std::list` for storage
   * `NE == -4` -> use `std::forward_list` for storage
   * `NE == -5` -> use `std::stack` for storage
   * `NE == -6` -> use `std::froward_stack` for storage
* `Matrix` size modifications. 
   * Implement `insertRow/Col(i)`, `removeRow/Col(i)`,`pop_top/bot`,`push_top/bot`, `pop_left/right`,`push_left/right`, methods to `Matrix` class
   * support column major matrices and tensors
* add latex helper functions for disp?
* https://www.gccxml.org/HTML/Index.html


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
1. [Functions: R^n -> R^m](topics/functions.md)

### Matrix Math via uBlas (transition from LAPACK)
1. [Boost libs](https://www.boost.org/doc/libs/)
1. [ublas](https://www.boost.org/doc/libs/1_60_0/libs/numeric/ublas/doc/index.html)
1. [Special matrices](topics/sparse_matrices_vectors.md)
  * use python script to generate matrix code
  * constant vector
  * constant MultiArray
1. [Matrix operations](topics/matrixlapack.md)
1. openblas multi-threading support?
1. Optimize Dot Products for Special Matrices
* use LAPACK / BLAS where efficacious to do so


### MultiArray Products
1. [MultiArray dot product](topics/dotproduct.md)
1. [Outer Product and Wedge Product](topics/outerwedge.md)
1. [Add Benchmarks](topics/benchmarks.md)
1. define grassman p-vectors?
1. levi-cevita symbol





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

