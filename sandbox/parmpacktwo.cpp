#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>
#include <variant>
#include <cmath>
#include "mathq.h"



// classes can NOT have multiple parameter packs
// you can nest them though ot get tehy same effect
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

  };

};


// functions can have multiple parameter packs
template <typename... Types>
struct foo {};

template < typename... Types1, template <typename...> class T
  , typename... Types2, template <typename...> class V
  , typename U >
  void
  bar(const T<Types1...>&, const V<Types2...>&, const U& u) {
  class D {};
  std::cout << sizeof...(Types1) << std::endl;
  std::cout << sizeof...(Types2) << std::endl;
  std::cout << u << std::endl;
}


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;



  auto f = Foo<7, 21, 32, 43, 2>();
  auto t = Foo<4, 100, 20, 32>::FooExtra<true, false, true>();

  return 0;
}
