#ifndef MATHQ__DIMENSIONS_H
#define MATHQ__DIMENSIONS_H



namespace mathq {





  // ***************************************************************************
  // Dimensions 
  //
  // need to use resiable because we need the same exact type for NestedDimensions elements
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
  //  NumberTrait specialization for  Dimensions
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



  inline bool equiv(const Dimensions& dims1, const Dimensions& dims2) {
    return dims1.equiv(dims2);
  }




  // ***************************************************************************
  // NestedDimensions 
  //
  // ***************************************************************************

  template<size_t depth_ = 0>
  class NestedDimensions;

  template<size_t depth_>
  class NestedDimensions : public Vector<Dimensions, depth_> {

  public:
    using Parent = Vector<Dimensions, depth_>;
    constexpr static size_t depth_value = depth_;

    NestedDimensions() {
    }

    template<size_t dyn = Parent::is_dynamic_value, EnableIf<dyn> = 0>
    NestedDimensions(const size_t depth) {
      this->resize(depth);
    }

    NestedDimensions(const std::initializer_list<Dimensions>& ilist) {
      if constexpr (this->is_dynamic_value) {
        this->resize(ilist.size());
      }
      size_t k = 0;
      typename std::initializer_list<Dimensions>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        (*this)[k] = *it;
      }
    }


  };



};
#endif
