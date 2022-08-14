
1. updating `g++`

```bash
g++ --version
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt update
sudo apt install build-essential
sudo apt -y install g++-9 g++-10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10
g++ --version
sudo update-alternatives --config g++
```

1. [dialects suppported by `g++`](https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html)

This is set using the `-std=<dialect>`  option

Currently using `c++20` and `g++ 10.3`

1. [g++ release list](https://gcc.gnu.org/releases.html)

1. turning an object "inside out" is referred to as __eversion__

1. template parameter packs, eg `size_t... dims`, cannot have a default value

1. You cannot specify or even determine the number of paramters for C-style variadic function parameters.  You have to pass the size first or have the size as a template and hope the user doesn't provide less because it will segmentation fault.  Same problem as arrays.

1. for the `Vector = MultiArray<Element, 1, N1>` specialization, Vector can be used for the constructor but it must be specified as `Vector<Element, N1>()`. The decontructor must be `~Vector()`. Best to use MultiArray instead


1. parameter pack function - method 1
```C++
    void foo(Args ... args) {
      const size_t N = sizeof...(dynamic_dims);
      std::array<size_t, N> temp = { (static_cast<size_t>(dynamic_dims))... };

    }
```

1. parameter pack function - method 2
```C++
    void foo(Args&& ... args) {
    auto&& first = std::get<0>(std::forward_as_tuple(std::forward<Args>(args)...));
    }
```

1. `error: there are no arguments to ‘size’ that depend on a template parameter, so a declaration of ‘size’ must be available [-fpermissive]`

Solution:  call `this->size()` instead of `size()`

    
1. type traits like `NumberTrait` do not find derived classes.  You need to specialize for all derived classes. Hence it must be specialized for `Dimensions` even though it inherits from Vector

1. `error: invalid use of incomplete type` template classes vs. non-template classes: template classes can be defined after their usage in other code (two-pass compilation).   Non-template classes must be defined before use (one-pass compilation).    So two solutions to `error: invalid use of incomplete type` are: 1) change the offending class to a template class or 2) move the code that uses the class so that it is after the class definition.

1. reference instance variables take up memory regardless if they are referenced to a const or constexpr

1. object that takes up no space

```C++
struct Empty {}; 
[[no_unique_address]] Empty e;
```

1. variadic constructor

```C++
    template<typename...T, mathq::EnableIf<(std::conjunction<std::is_integral<T>...>::value)> = 0>
    Dimensions(T... dynamic_dims) {
      const size_t N = sizeof...(dynamic_dims);
      std::array<size_t, N> temp = { (static_cast<size_t>(dynamic_dims))... };

      this->resize(N);
      for (size_t n = 0; n < N; n++) {
        Parent::operator[](n) = temp[n];
      }
    }
```

1. How to specialize an alias template
  * [alias-template-specialisation](https://stackoverflow.com/questions/6622452/alias-template-specialisation)
```C++
template<class Vector> struct new_style2_aux;
template<class T> struct new_style2_aux<std::vector<T> >{
   typedef typename std::vector<T>::value_type type;
};
template<class Vector> using new_style2 = typename new_style2_aux<Vector>::type;
```

1. `size_t` performance

[performance of size_t in c](https://stackoverflow.com/questions/17384606/performance-of-size-t-in-c)

1. template `requires` size of param pack

```C++
  template <typename Element, size_t rank_, size_t... dim_ints> requires (sizeof...(dim_ints) > 0)
```

1. `requires` on size of argument

```C++
template <typename Element, size_t rank, size_t... dims > requires (rank < 100)
class Test;


template <typename Element, size_t rank, size_t... dims > requires (rank < 100)
class Test {
public:
  Test() {
    using namespace mathq;
    using namespace display;
    OUTPUT("\nInside main Test constructor");
    TRDISP(rank);
  }
};

template <typename Element, size_t rank> requires (rank < 100)
class Test<Element, rank> {
public:
  Test() {
    using namespace mathq;
    using namespace display;
    OUTPUT("\nInside specialization Test constructor");
    TRDISP(rank);
  }
};
```

1.  Approach to use of `std::initializer_list`:
  * define constructor and `operator=` for `std::initializer_list<Element>`. For top-level, we then use 
    * a flat list:
    * for nexted MultiArrays, the compiler will recursive traverse the nested `initializer_list`s
  * For `rank >= 2` also define constructor and `operator=` for `MakeInitializer<Element, rank_value>::Type`. For top-level, we then use 
    * a nested `initializer_list` with depth equal to the number of indicies
    * for nexted MultiArrays, the compiler will recursive traverse the nested `initializer_list`s via the definition of `Element`

1. Approach to *constructors*: use `explicit` except in certain cases: default and copy constructors should be implicit.
  * `MultiArray`s `initializer_list` constructors should be implicit so that compiler can recurse through nexted MultiArrays
  * `Indices` `initializer_list` constructors should be implicit so that initializer_lists can be converted to Indices by the compiler
  * Should `DeepIndices` `initializer_list` constructors be implicit? 
  * Should `Dimensions` and `DeepDimensions` `initializer_list` constructors be implicit? No, this will cause problems with initializer_list constructors of `MultiArray`s

1. Using `requires` and `std::enable_f` for a method: it must be templated and the boolean clause must contain one of the templated variables.
  * for `requires` put all the conditions in the requies clause.  put only one bool if using an enable bool 

1. `is_unsigned`: 0 and positive ints are of type `int` by default, so feeding such constants to a constructor requiring `is_unsigned` will fail.  Work-aroud: 1) Use 0u or 1u, or don't use `unsigned` and check in real time.

1. `std::is_convertible<float,size_t>` is truem so use `is_integral`

1. fix for the following error is to encure that (1) a non-explicit copy constructor exists as well as (2) a non-explicit ELEMENT constructor existsa
```C++
testunary.cpp:65:25: error: conversion from ‘double’ to non-scalar type ‘mathq::Scalar<double>’ {aka ‘mathq::MultiArray<double, 0>’} requested
   65 |     Scalar<double> s5 = 4.4;
```


1. C++ dialect 
  * Compiler version file in versioning
  * In variables.mk, have C++ version taken from file in version directory (`CPPC = g++ -pipe -std=c++17`)
  * add variable for the C++ version used, currently C++20.  append to version string. 
  * was using g++ 10.3.  10.4 has been released. now using 11.1
  * (upgrading g++ in Ubuntu)[https://www.ovenproof-linux.com/2016/09/upgrade-gcc-and-g-in-ubuntu.html]
  * (multiple versions of g++)[https://linuxconfig.org/how-to-switch-between-multiple-gcc-and-g-compiler-versions-on-ubuntu-20-04-lts-focal-fossa]
```bash
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9
```
1. https://linuxconfig.org/how-to-switch-between-multiple-gcc-and-g-compiler-versions-on-ubuntu-20-04-lts-focal-fossa
  * array/valarray internal data access via data()
  * https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
  * use &(a[0])



1. ` const Element& val` constrcutors and methods should always use `&` because `Element` may be a MultiArray. 
  * use `Element &&` for expressions?


1. Expanding a paramter pack as parameters

```C++
  template <typename Number, size_t NDIMS, size_t... ints>
  using MultiGrid_A = std::tuple< MultiArray_RepeatVector<Number, NDIMS, ints>...>;
```

1. *Do nothing SINFAE* A note on SINFAE and requires.   The following code will compile but will never match any types `T`
```C++
  template <typename T> requires (std::is_base_of_v< ExpressionR, T >)
    class MyTrait< T > {
    public:
      constexpr static int value = 100;
  };
```
This is because the expression `std::is_base_of_v< ExpressionR, T >` does not compile on its own. ExpressionR is not a type but a symbol for a templated type.  You must include all the parameters for it to be a type.   Try it out:
```C++
  bool q = std::is_base_of_v< ExpressionR, double >;
  bool p = std::is_base_of_v< ExpressionR, Vector<double> >;
```

The following attempt at a work-around also doesn't work because the parameters are not part of the input type.  The compile ris not able to figure out.
```C++
  template <typename T, class Derived, typename Element, typename Num, size_t depth, size_t rank> requires (std::is_base_of_v< ExpressionR<Derived, Element, Num, depth, rank>, T >)
    class MyTrait< T > {
    public:
      constexpr static int value = 100;
  };
```
