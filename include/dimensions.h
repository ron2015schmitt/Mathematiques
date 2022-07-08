#ifndef MATHQ__DIMENSIONS_H
#define MATHQ__DIMENSIONS_H



namespace mathq {


  /// TODO:
  // 1. does Dimensions work with a dummy template parmater?
  // 2. try N1 as the parameter instead of Element
  // 3. this means NestedDims can only work with size = 0 but that's fine
  // 4. get equiv function working
  // 5. finished nested dims
  // 6. implement diemnsiosn functions in Vector



  // ***************************************************************************
  // Dimensions 
  //
  // need to use resiable because we need the same exact type for NestedDimensions
  // ***************************************************************************
  // template <typename Element>
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

      this->resize(N);
      for (size_t n = 0; n < N; n++) {
        Parent::operator[](n) = temp[n];
      }
    }

    Dimensions(const Dimensions& dims2) {
      resize(dims2.size());
      for (size_t n = 0; n < this->size(); n++) {
        (*this)[n] = dims2[n];
      }
    }

    Dimensions& getReducedDims() const {
      Dimensions& v = *(new Dimensions{});
      v.resize(this->size());
      for (size_t i = 0; i < this->size(); i++) {
        v[i] = (*this)[i];
      }
      return v;
    }

    bool equiv(const Dimensions& dims2) const {
      return (this->getReducedDims() == dims2.getReducedDims());
    }

    Dimensions& getReverse() const {
      Dimensions& v = *(new Dimensions{});
      v.resize(this->size());
      // reverse order
      size_t ii = 0;
      for (size_t k = this->size()-1; k >= 0; k--) {
        v[ii++] = (*this)[k];
      }
      return v;
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "Dimensions";
      s += StyledString::get(ANGLE1).get();
      s += StyledString::get(ANGLE2).get();
      return s;
    }

  };


  //
  //  NumberTrait for  Dimensions
  //
  template <typename NewNumber>
  class
    NumberTrait<Dimensions, NewNumber> {
  public:
    using InputType = Vector<size_t>;
    using Type = typename NumberTrait<size_t>::Type;
    using ReplacedNumberType = Vector<typename NumberTrait<size_t, NewNumber>::ReplacedNumberType>;
    using ReplacedElementType = Vector<NewNumber>; // this is correct, see comment above

    constexpr static bool value = false;
    constexpr static size_t depth() {
      return 1 + NumberTrait<size_t, NewNumber>::depth();
    }
    inline static size_t size(const InputType& x) {
      return x.size();
    }
    inline static size_t deepsize(const InputType& x) {
      return x.deepsize();
    }
  };



  // template <size_t rank1, typename T1, size_t rank2, typename T2>
  // inline bool equiv(const Dimensions& dims1, const Dimensions& dims2) {
  //   return dims1.equiv(dims2);
  // }


  // ***************************************************************************
  // NestedDimensions 
  //
  // Vector of fixed  = rank_
  // if all non-zero ints... are provided, the values will be fixed as well
  // ***************************************************************************

  template<size_t depth_ = 0>
  // class NestedDimensions : public Vector<Dimensions, depth_> {   // this causes "error: invalid use of incomplete type ".  Need to make Dimensions into a templated type
  // class NestedDimensions : public Vector<Vector<size_t>, depth_> {

  class NestedDimensions : public Vector<Dimensions, depth_> {

    // need to make Dimensions a template with Element type because otherwise when we get elements they will be of type Vector
    // unless we cast them in the operators[]
  // class NestedDimensions : public Vector<Vector<size_t>, depth_> {

    // template<typename T, size_t depth_>
    // class NestedDimensions : public Vector<T, depth_> {
  public:

  };


};
#endif
