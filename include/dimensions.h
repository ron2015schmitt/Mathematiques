#ifndef MATHQ__DIMENSIONS_H
#define MATHQ__DIMENSIONS_H



namespace mathq {





  // ***************************************************************************
  // Dimensions 
  //
  // need to use resiable because we need the same exact type for NestedDimensions elements
  // ***************************************************************************
  template <size_t rank_>
  class Dimensions : public Vector<size_t, rank_> {
  public:
    using Type = Dimensions<rank_>;
    using Parent = Vector<size_t>;
    using ElementType = size_t;


    Dimensions() {
    }

    Dimensions(const size_t N) {
      this->resize(N);
    }

    template <size_t rank2>
    Dimensions(const Dimensions<rank2>& dims2) {
      this->resize(dims2.size());
      for (size_t n = 0; n < this->size(); n++) {
        (*this)[n] = dims2[n];
      }
    }

    Dimensions(const std::initializer_list<size_t>& ilist) {
      if constexpr (this->is_dynamic_value) {
        this->resize(ilist.size());
      }
      size_t k = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        (*this)[k] = *it;
      }
    }


    Dimensions<0>& getReducedDims() const {
      Dimensions<0>& v = *(new Dimensions{});
      v.resize(this->size());
      for (size_t i = 0; i < this->size(); i++) {
        v[i] = (*this)[i];
      }
      return v;
    }

    template <size_t rank2>
    bool equiv(const Dimensions<rank2>& dims2) const {
      return (this->getReducedDims() == dims2.getReducedDims());
    }

    Dimensions<rank_>& getReverse() const {
      Dimensions<rank_>& v = *(new Dimensions<rank_>());
      v.resize(this->size());
      // reverse order
      size_t ii = 0;
      for (size_t k = this->size()-1; k >= 0; k--) {
        v[ii++] = (*this)[k];
      }
      return v;
    }


    operator Dimensions<0>() {
      return *(new Dimensions<0>(*this));
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "Dimensions";
      s += StyledString::get(ANGLE1).get();
      s += template_resizable_to_string(rank_);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

  };




  //
  //  NumberTrait specialization for  Dimensions
  //

  template <typename NewNumber, size_t rank>
  class
    NumberTrait<Dimensions<rank>, NewNumber> {
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




  template <size_t rank1, size_t rank2>
  inline bool equiv(const Dimensions<rank1>& dims1, const Dimensions<rank2>& dims2) {
    return dims1.equiv(dims2);
  }




  template <typename Element, size_t N1>
  Dimensions<Vector<Element, N1>::rank_value>& Vector<Element, N1>::dims(void) const {
    if constexpr (is_dynamic_value) {
      return *(new Dimensions<rank_value>(size()));
    }
    else {
      return *(new Dimensions<rank_value>());
    }
  }


  // ***************************************************************************
  // NestedDimensions 
  //
  // ***************************************************************************

  template<size_t depth_ = 0>
  class NestedDimensions;

  template<size_t depth_>
  class NestedDimensions : public Vector<Dimensions<0>, depth_> {

  public:
    using Parent = Vector<Dimensions<0>, depth_>;
    constexpr static size_t depth_value = depth_;

    NestedDimensions() {
    }

    template<size_t dyn = Parent::is_dynamic_value, EnableIf<dyn> = 0>
    NestedDimensions(const size_t depth) {
      this->resize(depth);
    }

    NestedDimensions(const std::initializer_list<Dimensions<0>>& ilist) {
      if constexpr (this->is_dynamic_value) {
        this->resize(ilist.size());
      }
      size_t k = 0;
      typename std::initializer_list<Dimensions<0>>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        (*this)[k] = *it;
      }
    }


    inline std::string classname() const {
      using namespace display;
      std::string s = "NestedDimensions";
      s += StyledString::get(ANGLE1).get();
      s += template_resizable_to_string(depth_);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

  };



};
#endif
