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
  static constexpr size_t size() noexcept { return sizeof...(_Idx); }
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

// constexpr static size_t dynamic = 0;
// template<bool...> struct bool_pack;
// template<bool... bs> 
// using all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;




template<size_t Rank, typename Derived> class BaseDims;
template<size_t... dims> class FixedDims;
template<size_t Rank> class DynamicDims;

template<typename Dims, typename NextDims = void> class NestedDims;



template<typename Dims, typename NextDims>
class NestedDims : public Dims {
public:
  typedef NestedDims<Dims, NextDims> Type;
  typedef Dims DimsType;
  typedef NextDims NextDimsType;
  constexpr static bool hasNext = true;

  Dims dimensions;
  NextDims nextDimensions;

  NestedDims() : dimensions(*(new DimsType)), nextDimensions(*(new NextDimsType)) {
  }
  NestedDims(Dims dims_) : dimensions(dims_), nextDimensions(*(new NextDimsType)) {
  }
  NestedDims(Dims dims_, NextDims nextDims_) : dimensions(dims_), nextDimensions(nextDims_) {
  }

  Dims& dims() {
    return dimensions;
  }
  const Dims& dims() const {
    return dimensions;
  }

  size_t rank() const {
    return dimensions.rank();
  }

  NextDims& next() {
    return nextDimensions;
  }
  const NextDims& next() const {
    return nextDimensions;
  }


  size_t depth() const {
    return 1 + nextDimensions.depth();
  }

  inline std::string classname() const {
    using namespace display;
    std::string s = "NestedDims";
    s += StyledString::get(ANGLE1).get();
    s += dimensions.classname();
    s += StyledString::get(COMMA).get();
    s += nextDimensions.classname();
    s += StyledString::get(ANGLE2).get();
    return s;
  }

  inline friend std::ostream& operator<<(std::ostream& stream, const Type& dims2) {
    using namespace display;
    dispval_strm(stream, dims2.dimensions);
    stream << ", ";
    dispval_strm(stream, dims2.nextDimensions);
    return stream;
  }


};

template<typename Dims>
class NestedDims<Dims, void> : public Dims {
public:
  typedef NestedDims<Dims, void> Type;
  typedef Dims DimsType;
  typedef void NextDimsType;
  constexpr static bool hasNext = false;

  Dims dimensions;

  NestedDims() : dimensions(*(new DimsType)) {
  }
  NestedDims(Dims dims_) : dimensions(dims_) {
  }

  size_t rank() const {
    return dimensions.rank();
  }

  size_t depth() const {
    return 1;
  }

  Dims& dims() {
    return dimensions;
  }
  const Dims& dims() const {
    return dimensions;
  }
  inline std::string classname() const {
    using namespace display;
    std::string s = "NestedDims";
    s += StyledString::get(ANGLE1).get();
    s += dimensions.classname();
    s += StyledString::get(ANGLE2).get();
    return s;
  }

  inline friend std::ostream& operator<<(std::ostream& stream, const Type& dims2) {
    using namespace display;
    dispval_strm(stream, dims2.dimensions);
    return stream;
  }

};



template<size_t Rank, typename Derived>
class BaseDims {
public:
  typedef BaseDims<Rank, Derived> Type;
  typedef Derived DerivedType;


  constexpr static size_t rank() noexcept {
    return Rank;
  }
  constexpr static bool is_dynamic() noexcept {
    return Derived::is_dynamic;
  }

  Derived& derived() {
    return static_cast<Derived&>(*this);
  }
  const Derived& derived() const {
    return static_cast<const Derived&>(*this);
  }

  // read
  const size_t& operator[](const size_t n) const {
    return derived()[n];
  }

  size_t index(const mathq::Indices& inds) const {
    const size_t M = this->rank();
    size_t k = 0;
    for (size_t n = 0; n < M; n++) {
      size_t N = (*this)[n];
      size_t j = inds[n];
      k = N*k + j;
    }
    return k;
  }


  inline mathq::Indices& indices(const size_t k) const {
    mathq::Indices& myinds = *(new mathq::Indices(rank()));
    size_t prev = k;
    // This loop must go in reverse order.  Do NOT change.
    for (size_t n = rank()-1; n > 0; n--) {
      size_t N = (*this)[n];
      size_t temp = prev/N;
      myinds[n] = prev - N*temp;
      prev = temp;
    }
    if (rank()>0) {
      myinds[0] = prev;
    }
    return myinds;
  }


  size_t datasize() const {
    return derived().datasize();
  }

  std::vector<size_t>& reduce() const {
    std::vector<size_t>& v = *(new std::vector<size_t>{});
    for (size_t i = 0; i < this->rank(); i++) {
      if ((*this)[i] != 1) {
        v.push_back((*this)[i]);
      }
    }
    return v;
  }

  template <size_t rank2, typename T2>
  bool equiv(const BaseDims<rank2, T2>& dims2) const {
    return (this->reduce() == dims2.reduce());
  }

  DynamicDims<Rank>& getReverse() const {
    DynamicDims<Rank>& dims2 = *(new DynamicDims<Rank>{});
    // reverse order
    size_t ii = 0;
    for (size_t k = this->rank()-1; k >= 0; k--) {
      dims2[ii++] = (*this)[k];
    }
    return dims2;
  }

  explicit operator DynamicDims<Rank>() const {
    DynamicDims<Rank>& dims2 = *(new DynamicDims<Rank>{});
    // reverse order
    for (size_t k = 0; k < rank(); k++) {
      dims2[k] = (*this)[k];
    }
    return dims2;
  }

  inline std::string classname() const {
    using namespace display;
    std::string s = "BaseDims";
    s += StyledString::get(ANGLE1).get();
    s += num2string(Rank);
    s += StyledString::get(COMMA).get();
    s += derived().classname();
    s += StyledString::get(ANGLE2).get();
    return s;
  }

  inline friend std::ostream& operator<<(std::ostream& stream, const Type& dims2) {
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


template <size_t rank1, typename T1, size_t rank2, typename T2>
inline bool equiv(const BaseDims<rank1, T1>& dims1, const BaseDims<rank2, T2>& dims2) {
  return dims1.equiv(dims2);
}




template<size_t... dims>
class FixedDims : public BaseDims<sizeof...(dims), FixedDims<dims...>> {
public:
  typedef FixedDims<dims...> Type;
  typedef BaseDims<sizeof...(dims), Type> ParentType;

  constexpr static size_t size = sizeof...(dims);
  constexpr static std::array<size_t, size> data = { (static_cast<size_t>(dims))... };
  const static size_t numElements = mathq::compile_time_product(data);

  constexpr static size_t rank() noexcept {
    return size;
  }
  constexpr static bool is_dynamic() noexcept {
    return false;
  }

  // --- instance ---

  // Default constructor

  explicit FixedDims() {
  }

  // read
  const size_t& operator[](const size_t n) const {
    size_t k = n;
    if (k < 0) {
      k += rank();
    }
    return data[k];
  }

  size_t datasize() const {
    return numElements;
  }

  inline std::string classname() const {
    using namespace display;
    std::string s = "FixedDims";
    s += StyledString::get(ANGLE1).get();
    for (size_t ii = 0; ii < rank(); ii++) {
      if (ii>0)  s += StyledString::get(COMMA).get();
      size_t value = data[ii];
      s += num2string(value);
    }
    s += StyledString::get(ANGLE2).get();
    return s;
  }


};




template<size_t Rank>
class DynamicDims : public BaseDims<Rank, DynamicDims<Rank>> {
public:
  typedef DynamicDims<Rank> Type;
  typedef BaseDims<Rank, Type> ParentType;

  constexpr static size_t size = Rank;

  constexpr static size_t rank() noexcept {
    return size;
  }
  constexpr static bool is_dynamic() noexcept {
    return true;
  }


  // --- instance ---

  std::array<size_t, Rank> data;

  // Default constructor: all zeroes

  explicit DynamicDims() {
    for (size_t n = 0; n < rank(); n++) {
      data[n] = 0;
    }
  }

  // Dynamic constructor

  template<typename...T, size_t DUMMY = 0, mathq::EnableIf<(DUMMY == 0) && (sizeof...(T) == Rank) && (std::conjunction<std::is_integral<T>...>::value)> = 0>
  DynamicDims(T... dynamic_dims) {
    data = { (static_cast<size_t>(dynamic_dims))... };
  }

  template<typename T>
  DynamicDims(const BaseDims<Rank, T>& dims2) {
    *this = dims2;
  }

  DynamicDims(const std::initializer_list<size_t>& list) {
    // const size_t N = list.size();
    size_t i = 0;
    typename std::initializer_list<size_t>::iterator it;
    for (it = list.begin(); it != list.end(); ++it) {
      (*this)[i++] = *it;
    }
  }

  DynamicDims(const std::list<size_t>& mylist) {
    // const size_t N = mylist.size();
    size_t i = 0;
    for (auto it = mylist.begin(); it != mylist.end(); ++it) {
      (*this)[i++] = *it;
    }
  }

  DynamicDims(const std::vector<size_t>& vec) {
    for (int k = 0; k < vec.size(); k++) {
      (*this)[k] = vec[k];
    }
  }

  template<typename T>
  DynamicDims(const mathq::Vector<T, rank()>& vec) {
    for (int k = 0; k < vec.size(); k++) {
      (*this)[k] = vec[k];
    }
  }

  template<typename T>
  DynamicDims(const mathq::Vector<T, 0>& vec) {
    for (int k = 0; k < vec.size(); k++) {
      (*this)[k] = vec[k];
    }
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


  size_t datasize() const {
    return std::accumulate(data.begin(), data.end(), 1, std::multiplies<size_t>());
  }

  template<typename T>
  DynamicDims<Rank>& operator=(const BaseDims<Rank, T>& dims2) {
    for (size_t k = 0; k < rank(); k++) {
      (*this)[k] = dims2[k];
    }
    return *this;
  }


  inline std::string classname() const {
    using namespace display;
    std::string s = "DynamicDims";
    s += StyledString::get(ANGLE1).get();
    s += num2string(Rank);
    s += StyledString::get(ANGLE2).get();
    return s;
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
  ECHO_CODE(FixedDims<1, 4, 2> dims);
  TRDISP(dims.is_dynamic());
  TRDISP(dims.rank());
  TRDISP(dims.data);
  TRDISP(dims.data[1]);
  TRDISP(dims.datasize());
  TRDISP(dims);

  // dims.data[1] = 42;  // should cause compile error
  // dims[1] = 42;  // should cause compile error



  CR();
  ECHO_CODE(DynamicDims<1> dims2);
  TRDISP(dims2.is_dynamic());
  TRDISP(dims2.rank());
  TRDISP(dims2.datasize());
  TRDISP(dims2);

  ECHO_CODE(dims2.data[0] = 42);
  TRDISP(dims2);
  ECHO_CODE(dims2[0] = 101);
  TRDISP(dims2);
  ECHO_CODE(std::array<size_t, 1> a = std::array<size_t, 1>{56});
  TRDISP(a);
  ECHO_CODE(dims2.data = a);
  TRDISP(dims2.datasize());
  TRDISP(dims2);


  CR();
  ECHO_CODE(DynamicDims<2> dims3);
  TRDISP(dims3.is_dynamic());
  TRDISP(dims3.rank());
  TRDISP(dims3.datasize());
  TRDISP(dims3);

  CR();
  ECHO_CODE(DynamicDims<3> dims4);
  TRDISP(dims4.is_dynamic());
  TRDISP(dims4.rank());
  TRDISP(dims4.datasize());
  TRDISP(dims4);


  CR();
  ECHO_CODE(DynamicDims<2> dims5);
  TRDISP(dims5.is_dynamic());
  TRDISP(dims5.rank());
  TRDISP(dims5.datasize());
  TRDISP(dims5);

  CR();
  ECHO_CODE(DynamicDims<2> dims6(5, 2));
  TRDISP(dims6.is_dynamic());
  TRDISP(dims6.rank());
  TRDISP(dims6.datasize());
  TRDISP(dims6);

  CR();
  ECHO_CODE(DynamicDims<1> dims7(42));
  TRDISP(dims7.is_dynamic());
  TRDISP(dims7.rank());
  TRDISP(dims7.datasize());
  TRDISP(dims7);



  CR();
  ECHO_CODE(DynamicDims<2> dims8(42, 13));
  TRDISP(dims8.is_dynamic());
  TRDISP(dims8.rank());
  TRDISP(dims8.datasize());
  TRDISP(dims8);


  CR();
  ECHO_CODE(DynamicDims<3> dims9({ 12, 5, 81 }));
  TRDISP(dims9.is_dynamic());
  TRDISP(dims9.rank());
  TRDISP(dims9.datasize());
  TRDISP(dims9);

  CR();
  ECHO_CODE(NestedDims<decltype(dims9)> ndims1(dims9));
  TRDISP(ndims1);
  TRDISP(ndims1.rank());
  TRDISP(ndims1.depth());

  CR();
  ECHO_CODE(NestedDims<decltype(dims), decltype(ndims1)> ndims2(dims, ndims1));
  TRDISP(ndims2);
  TRDISP(ndims2.rank());
  TRDISP(ndims2.depth());


  // generates an error via static_assert
  // FixedDims<dynamic,dynamic,5> dims_test(1,2,3); 

  // generates an error via static_assert
  // FixedDims<5,dynamic> dims_test; 


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
