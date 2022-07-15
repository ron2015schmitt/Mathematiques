
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

