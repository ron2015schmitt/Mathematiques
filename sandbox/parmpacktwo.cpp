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
  static constexpr size_t size() noexcept { return sizeof...(_Idx); }
};



// put in a namespace so that the enums don't clash
namespace DimensionsKinds {
  enum Type { fixed, dynamic };
};
using DimensionsKindEnum = DimensionsKinds::Type;




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
namespace Dimensions_space {
  enum Type { dynamic = 0 };
};
using DimensionsEnum = Dimensions_space::Type;


constexpr static size_t dynamic = 0;
// template<bool...> struct bool_pack;
// template<bool... bs> 
// using all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;

template<size_t... dims>
class Dims {
public:
  typedef size_t Type;

  constexpr static size_t rawsize = sizeof...(dims);
  constexpr static std::array<size_t, rawsize> rawdata = { (static_cast<size_t>(dims))... };

  constexpr static bool is_dynamic() noexcept {
    return rawdata[0] == 0;
  }
  static constexpr bool is_all_zeros(std::initializer_list<size_t> list) {
    for (auto elem : list) {
      if (elem != 0) return false;
    }
    return true;
  }
  static constexpr bool is_all_nonzero(std::initializer_list<size_t> list) {
    for (auto elem : list) {
      if (elem == 0) return false;
    }
    return true;
  }

  constexpr static size_t rank() noexcept {
    static_assert(rawsize > 0, "This class must have at least one parameter");
    if constexpr (is_dynamic()) {
      if constexpr ((rawsize == 2) && (rawdata[1] > 0)) {
        // second parmeter gives the length
        // eg. Dims<dynamic, 10>
        return rawdata[1];
      }
      else {
        static_assert(is_all_zeros({ dims... }), "Dynamic instances with rank>2 must be of form Dims<dynamic,dynamic,dynamic,...>");
        return rawsize;
      }
    }
    else {
      static_assert(is_all_nonzero({ dims... }), "Fixed-dimensions instance must have every dimension > 0");
      return rawsize;
    }
  }

  typedef typename std::conditional<is_dynamic(), std::array<size_t, rank()>, const std::array<size_t, rank()> >::type ArrayType;
  ArrayType data;

  // Default constructor

  explicit Dims() : data({ (static_cast<size_t>(dims))... }) {
    if constexpr (is_dynamic()) {
      for (size_t n = 0; n < rank(); n++) {
        data[n] = 0;
      }
    }
  }

  // Dynamic init constructor

  // TODO: need constraint that all T=size_t and there are rank() of T
  template<typename...T, size_t DUMMY = 0, mathq::EnableIf<DUMMY==0 && is_dynamic()> = 0>
  Dims(T... dynamic_dims) {
    // if (rawsize != 2) {
    //   for (size_t n = 0; n < rawsize; n++) {
    //   }
    // }

    data = { (static_cast<size_t>(dynamic_dims))... };
  }

  // "read/write"
  // std::enable_if<is_dynamic(), size_t&> operator[](const size_t n) {
  size_t& operator[](const size_t n) {
    size_t k = n;
    if (k < 0) {
      k += rank();
    }
    return data[k];
  }

  // read
  const size_t& operator[](const size_t n) const {
    size_t k = n;
    if (k < 0) {
      k += rank();
    }
    return data[k];
  }



  static inline std::string classname() {
    using namespace display;
    std::string s = "Dims";
    s += StyledString::get(ANGLE1).get();
    for (size_t ii = 0; ii < rank(); ii++) {
      if (ii>0)  s += StyledString::get(COMMA).get();
      size_t value = rawdata[ii];
      if (value == 0) {
        s += "dynamic";
      }
      else {
        s += num2string(value);
      }
    }
    s += StyledString::get(ANGLE2).get();
    return s;
  }


  inline friend std::ostream& operator<<(std::ostream& stream, const Dims& dims2) {
    using namespace display;
    stream << "{";
    for (size_t ii = 0; ii < dims2.rank(); ii++) {
      if (ii>0)  stream << ", ";
      dispval_strm(stream, dims2[ii]);
    }
    stream << "}";
    return stream;

  }

};




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

// template <typename T>
// bool is_const = std::is_same<T, std::remove_const<T>>::value;

//  pointer with right const (pointer cannot be changed))
template <typename T>
bool is_pointer_const = std::is_pointer<T>::value && std::is_const<T>::value;

//  pointer with left const (value pointed to cannot be changed))
template <typename T>
bool is_const_pointer = std::is_pointer<T>::value && std::is_const<std::remove_pointer_t<T>>::value;



// see also
// https://stackoverflow.com/questions/69186185/issue-with-variadic-template-template-parameter-pack

// https://stackoverflow.com/questions/9831501/how-can-i-have-multiple-parameter-packs-in-a-variadic-template

// https://stackoverflow.com/questions/24661902/fixed-length-variadic-parameter-packs-in-c11

// 2020 proposal for universal template paramters
// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p1985r0.pdf

int main(int argc, char* argv[]) {
  using namespace std;
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



  CR();
  ECHO_CODE(Dims<1, 4, 2> dims);
  TRDISP(dims.is_dynamic());
  TRDISP(dims.rank());
  TRDISP(dims.data);
  TRDISP(dims.data[1]);
  TRDISP(dims);

  // dims.data[1] = 42;
  // dims[1] = 42;
  // TRDISP(dims.data[1]);



  CR();
  ECHO_CODE(Dims<dynamic> dims2);
  TRDISP(dims2.is_dynamic());
  TRDISP(dims2.rank());
  TRDISP(dims2);

  dims2.data[0] = 42;
  TRDISP(dims2);
  dims2[0] = 101;
  TRDISP(dims2);
  std::array<size_t, 1> a = std::array<size_t, 1>{56};
  TRDISP(a);
  dims2.data = a;
  TRDISP(dims2);


  CR();
  ECHO_CODE(Dims<dynamic, dynamic> dims3);
  TRDISP(dims3.is_dynamic());
  TRDISP(dims3.rank());
  TRDISP(dims3);

  CR();
  ECHO_CODE(Dims<dynamic, dynamic, dynamic> dims4);
  TRDISP(dims4.is_dynamic());
  TRDISP(dims4.rank());
  TRDISP(dims4);


  CR();
  ECHO_CODE(Dims<dynamic, 2> dims5);
  TRDISP(dims5.is_dynamic());
  TRDISP(dims5.rank());
  TRDISP(dims5);

  CR();
  ECHO_CODE(Dims<dynamic, 2> dims6(5, 2));
  TRDISP(dims6.is_dynamic());
  TRDISP(dims6.rank());
  TRDISP(dims6);

  CR();
  ECHO_CODE(Dims<dynamic> dims7(42));
  TRDISP(dims7.is_dynamic());
  TRDISP(dims7.rank());
  TRDISP(dims7);

  // generates an error via static_assert
  // Dims<dynamic,dynamic,5> dims_test(1,2,3); 

  // generates an error via static_assert
  // Dims<5,dynamic> dims_test; 


  /*
    int ii = 3;
    TRDISP(ii);
    int* ip = &ii;
    TRDISP(ip);
    const int ii2 = 2;
    TRDISP(ii2);

    const int jj = 3;
    TRDISP(jj);

    int const kk = 3;
    TRDISP(kk);

    const int& jjj = ii;
    TRDISP(jjj);
    // jjj = ii2;


    int variable_int;
    const int const_int = 0;

    TRDISP(is_const<decltype(variable_int)>::value);
    TRDISP(is_const<decltype(const_int)>::value);
    TRDISP(std::is_const<std::remove_pointer_t<decltype(const_int)>>::value);


    int* variable_pointer;
    const int* const_pointer;
    int* const pointer_const = &ii;
    const int* const const_pointer_const = &ii;


    //  pointer with right const (pointer cannot be changed)
    CR();
    TRDISP(is_pointer_const<decltype(const_int)>);
    TRDISP(is_pointer_const<decltype(variable_pointer)>);
    TRDISP(is_pointer_const<decltype(const_pointer)>);
    TRDISP(is_pointer_const<decltype(pointer_const)>);
    TRDISP(is_pointer_const<decltype(const_pointer_const)>);

    //  pointer with left const (value pointed to cannot be changed))
    CR();
    TRDISP(is_const_pointer<decltype(const_int)>);
    TRDISP(is_const_pointer<decltype(variable_pointer)>);
    TRDISP(is_const_pointer<decltype(const_pointer)>);
    TRDISP(is_const_pointer<decltype(pointer_const)>);
    TRDISP(is_const_pointer<decltype(const_pointer_const)>);


    // left

    // AddQualifiers<int, Qualifiers::ConstLeft&Qualifiers::ConstRight >::Type iiii;

  */
  return 0;
}
