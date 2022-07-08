#ifndef MATHQ__DIMENSIONS_H
#define MATHQ__DIMENSIONS_H



namespace mathq {



  // ***************************************************************************
  // Dimensions 
  //
  // need to use resiable because we need the same exact type for NestedDimensions
  // ***************************************************************************

  class Dimensions : public Vector<size_t> {
  public:
    using Type = Dimensions;
    using Parent = Vector<size_t>;
    using ElementType = size_t;


    Dimensions() {
    }

    template<typename...T, mathq::EnableIf<(std::conjunction<std::is_integral<T>...>::value)> = 0>
    Dimensions(T... dynamic_dims) {
      const size_t N = sizeof...(dynamic_dims);
      std::array<size_t, N> temp = { (static_cast<size_t>(dynamic_dims))... };

      resize(N);
      for (size_t n = 0; n < N; n++) {
        Parent::operator[](n) = temp[n];
      }
    }
    // void foo(Args&& ... args) {
    // auto&& first = std::get<0>(std::forward_as_tuple(std::forward<Args>(args)...));

    Dimensions(const Dimensions& dims2) {
      resize(dims2.size());
      for (size_t n = 0; n < size(); n++) {
        (*this)[n] = dims2[n];
      }
    }

    // std::vector<size_t>& reduce() const {
    //   std::vector<size_t>& v = *(new std::vector<size_t>{});
    //   for (size_t i = 0; i < this->rank(); i++) {
    //     if ((*this)[i] != 1) {
    //       v.push_back((*this)[i]);
    //     }
    //   }
    //   return v;
    // }

    // template <size_t rank2, typename T2>
    // bool equiv(const Dimensions<rank2, T2>& dims2) const {
    //   return (this->reduce() == dims2.reduce());
    // }

    // DynamicDims<rank_>& getReverse() const {
    //   DynamicDims<rank_>& dims2 = *(new DynamicDims<rank_>{});
    //   // reverse order
    //   size_t ii = 0;
    //   for (size_t k = this->rank()-1; k >= 0; k--) {
    //     dims2[ii++] = (*this)[k];
    //   }
    //   return dims2;
    // }

    // explicit operator DynamicDims<rank_>() const {
    //   DynamicDims<rank_>& dims2 = *(new DynamicDims<rank_>{});
    //   // reverse order
    //   for (size_t k = 0; k < rank(); k++) {
    //     dims2[k] = (*this)[k];
    //   }
    //   return dims2;
    // }

    inline std::string classname() const {
      using namespace display;
      std::string s = "Dimensions";
      return s;
    }

  };



  // template <size_t rank1, typename T1, size_t rank2, typename T2>
  // inline bool equiv(const Dimensions& dims1, const Dimensions& dims2) {
  //   return dims1.equiv(dims2);
  // }


  template <typename Element>
  class Tester : public Vector<Element> {
  public:
    using Type = Tester<Element>;
    using ConcreteType = Tester<Element>;
    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    Tester() {
    }
  };


  // ***************************************************************************
  // NestedDimensions 
  //
  // Vector of fixed  = rank_
  // if all non-zero ints... are provided, the values will be fixed as well
  // ***************************************************************************

  template<size_t depth_ = 0>
  // class NestedDimensions : public Vector<Dimensions, depth_> {   // this causes "error: invalid use of incomplete type ".  Need to make Dimensions into a templated type
  // class NestedDimensions : public Vector<Vector<size_t>, depth_> {
  class NestedDimensions : public Vector<Vector<size_t>, depth_> {

    // template<typename T, size_t depth_>
    // class NestedDimensions : public Vector<T, depth_> {
  public:

  };


};
#endif
