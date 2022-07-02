#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>
#include <variant>
#include <cmath>
#include <cassert>
#include <numeric>
#include "mathq.h"



// --------------------------------------------------------------
// template functions with parameter packs
// --------------------------------------------------------------


// functions can have multiple parameter packs

template < typename... Types1, template <typename...> class T
  , typename... Types2, template <typename...> class V
  , typename U >
  void
  func1(const T<Types1...>&, const V<Types2...>&, const U& u) {
  class D {};
  std::cout << sizeof...(Types1) << std::endl;
  std::cout << sizeof...(Types2) << std::endl;
  std::cout << u << std::endl;
}



// in template functions, paramter packs can be placed anywhere

template <typename... U, int... INTS, bool ColMajor = false>
void func2(U... ints) {
  const int size = sizeof...(ints);
  int intarray[size] = { ints... };
  std::cout << "(";
  for (int i = 0; i < size; i++) {
    if (i>0) std::cout << ", ";
    std::cout << intarray[i];
  }
  std::cout << ")" << std::endl;
}


// can use SINFAE to create int paramter pack in a function as follows
// not sure if there is a use for this

template <typename... U, bool ColMajor = false>
typename std::enable_if<(std::is_same<U, int>::value && ...), void>::type func3(U... ints) {
  const int size = sizeof...(ints);
  int intarray[size] = { ints... };
  std::cout << "(";
  for (int i = 0; i < size; i++) {
    if (i>0) std::cout << ", ";
    std::cout << intarray[i];
  }
  std::cout << ")" << std::endl;
}


// --------------------------------------------------------------
// template classes with parameter packs
// --------------------------------------------------------------

// classes:
// - can NOT have multiple parameter packs
// - parameter pack must be last

// struct
template <typename... Types>
struct foo {};


// you can nest them though ot get the same effect

template <int Ndims, int... Sizes>
class Foo {
public:
  static constexpr int Ngiven = sizeof...(Sizes);
  static constexpr auto sizes = std::array<int, Ndims>{std::forward<int>(Sizes)...};
  Foo() {
    std::cout << "Ndims=" <<  Ndims << "\n (";
    std::cout << "Ngiven=" <<  Ngiven << "\n (";
    for (int n = 0; n < Ndims; n++) {
      if (n > 0) std::cout << ", ";
      std::cout << sizes[n];
    }
    std::cout << ")\n";
  }


  // nested class
  // here we derive formt he outer class but this is not necessary

  template <bool... Highs>
  class FooExtra : public Foo<Ndims, std::forward<int>(Sizes)...> {
  public:
    static constexpr int Hgiven = sizeof...(Highs);
    static constexpr auto highs = std::array<bool, Ndims>{std::forward<bool>(Highs)...};
    FooExtra() : Foo() {
      std::cout << "Ndims=" <<  Ndims << "\n (";
      std::cout << "Hgiven=" <<  Hgiven << "\n (";
      for (int n = 0; n < Ndims; n++) {
        if (n > 0) std::cout << ", ";
        std::cout << highs[n] ? "H" : "L";
      }
      std::cout << ")\n";
    }
  }; // end of inner class
}; // end of outer class





// EXAMPLE: template tempalte parameter

template < typename T>
class Container {
public:
  Container() {
    std::cout << "Container()\n";
  }
};


template < template<typename> typename C, int... sizes>
class ContainerContainer {
public:
  ContainerContainer() {
    C<double> x;
    std::cout << "ContainerContainer()\n";
  }
};


template<size_t... ints>
void print_sequence(std::index_sequence<ints...> int_seq) {
  std::cout << "The sequence of size " << int_seq.size() << ": ";
  ((std::cout << ints << ' '), ...);
  std::cout << '\n';
}

template <size_t... Indices>
static constexpr auto GenerateArray(std::index_sequence<Indices...>)->std::array<size_t, sizeof...(Indices)> {
  return { (static_cast<size_t>(Indices))... };
}

// need enable if that ensures that T is a an integer sequence
template < typename T>
class Container2 {
public:
  static constexpr auto x = T{};
  static constexpr auto myArray = GenerateArray(T{});
  // static constexpr auto myArray2 = std::to_array(T{});   // C++20
  static constexpr int Ngiven = T::size();

  // template <size_t... nums>
  // static constexpr auto sizes = std::array<int, Ngiven>{std::forward<int>(Sizes)...};
  Container2() {
    print_sequence(x);
    std::cout << "Container2(): Ngiven=" << Ngiven;
    std::cout  << "; ints=";
    for (size_t n = 0; n < myArray.size(); n++) {
      if (n > 0) std::cout << ", ";
      std::cout << myArray[n];
    }
    std::cout << "\n";
  }
};



/// Class template integer_sequence
template<typename _Tp, _Tp... _Idx>
struct integer_sequence2 {
  typedef _Tp value_type;
  static constexpr size_t   size() noexcept { return sizeof...(_Idx); }
};





// // put in a namespace so that the enums don't clash
// namespace Qualifiers {
//   enum Type { None = 0, ConstLeft = 1, ConstRight = 2, Pointer = 4, Ref = 8, RefRef = 16 };
// };
// using QualifiersEnum = Qualifiers::Type;

// inline constexpr QualifiersEnum operator&(QualifiersEnum a, QualifiersEnum b) {
//   return static_cast<QualifiersEnum>(static_cast<int>(a) | static_cast<int>(b));
// }

// template <typename T, QualifiersEnum q>
// class AddQualifiers {
// public:

//   // template<typename S>
//   // using ConstLeftOperation = typename std::conditional< (q& Qualifiers::ConstLeft > 0), (const S), S>::type;

//   // //  it actually doesn't matter if you put const on right. what matters is the order
//   // template<typename S>
//   // using ConstRightOperation = typename std::conditional< (q& Qualifiers::ConstRight > 0), (S const), S>::type;

//   // template<typename S>
//   // using PointerOperation = typename std::conditional< (q& Qualifiers::Pointer > 0), (S*), S>::type;

//   // template<typename S>
//   // using RefOperation = typename std::conditional< (q& Qualifiers::Ref > 0), S&, S>::type;

//   // template<typename S>
//   // using RefRefOperation = typename std::conditional< (q& Qualifiers::RefRef > 0), S&&, S>::type;

//   // typedef ConstRightOperation<ConstLeftOperation<RefRefOperation<RefOperation<PointerOperation<T>>>>> Type;
//   // typedef PointerOperation<ConstLeftOperation<T>> Type;
//   // typedef ConstRightOperation<PointerOperation<T>> Type;
//   // typedef ConstRightOperation<PointerOperation<ConstLeftOperation<T>>> Type;
//   typedef T Type;
// };
// template <typename T>
// class AddQualifiers<T, Qualifiers::None> {
// public:
//   typedef T Type;
// };
// template <typename T>
// class AddQualifiers<T, Qualifiers::ConstLeft> {
// public:
//   typedef const T Type;
// };
// template <typename T>
// class AddQualifiers<T, Qualifiers::ConstRight> {
// public:
//   typedef T const Type;
// };
// template <typename T>
// class AddQualifiers<T, Qualifiers::Pointer> {
// public:
//   typedef T* Type;
// };
// template <typename T>
// class AddQualifiers<T, Qualifiers::Ref> {
// public:
//   typedef T& Type;
// };
// template <typename T>
// class AddQualifiers<T, Qualifiers::RefRef> {
// public:
//   typedef T&& Type;
// };



// if constexpr ((sizeof...(dims) > 0) && (std::get<0>(std::forward_as_tuple(dims...)) == 0)) {
  // static_assert ((sizeof...(dims) > 2), "if first index is zero, there must me exactly two indices");
//   return true;
// }
// else {
//   return false;
// }

// // put in a namespace so that the enums don't clash
// namespace Dimensions_space {
//   enum Type { dynamic = 0 };
// };
// using DimensionsEnum = Dimensions_space::Type;

// constexpr static size_t   dynamic = 0;
// template<bool...> struct bool_pack;
// template<bool... bs> 
// using all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;








// the following doesn;t quite do what we want

template < size_t... Sizes>
class Helper {
public:
  Helper() {
    std::cout << "Helper()\n";
  }
};

template < template<size_t...> typename H, typename... Types1>
class Bar {
public:
  // static constexpr int Hgiven = sizeof...(Highs);
  // static constexpr auto highs = std::array<bool, Ndims>{std::forward<bool>(Highs)...};
  Bar() {
    H<1, 2, 3> help;
    std::cout << "Bar()\n";

    // std::cout << "Ndims=" <<  Ndims << "\n (";
    // std::cout << "Hgiven=" <<  Hgiven << "\n (";
    // for (int n = 0; n < Ndims; n++) {
    //   if (n > 0) std::cout << ", ";
    //   std::cout << highs[n] ? "H" : "L";
    // }
    // std::cout << ")\n";

  }
};



template < typename... >
struct Typelist {};

template < typename A, int... B>
class Class3 {
public:
  Class3() {
    std::cout << "Class3()\n";
  }
};

// partial specialization
template < typename... A, int... B>
class Class3<Typelist<A...>, B...> {
public:
  Class3() {
    std::cout << "Class3()\n";
  }
};



// see also
// https://stackoverflow.com/questions/69186185/issue-with-variadic-template-template-parameter-pack

// https://stackoverflow.com/questions/9831501/how-can-i-have-multiple-parameter-packs-in-a-variadic-template

// https://stackoverflow.com/questions/24661902/fixed-length-variadic-parameter-packs-in-c11

// 2020 proposal for universal template paramters
// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p1985r0.pdf

int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;



  func3();
  func3(-10, 78);
  func3(1, 4, 0);


  auto f = Foo<7, 21, 32, 43, 2>();
  auto t = Foo<4, 100, 20, 32>::FooExtra<true, false, true>();

  Container<double> c;

  Container2<std::index_sequence<9, 2, 5, 1, 9, 1, 6>> cd;


  auto b = ContainerContainer< Container, 1, 2, 3>();



  Helper<1, 2, 3> help;
  auto bar = Bar< Helper, double, float>();

  return 0;
}
