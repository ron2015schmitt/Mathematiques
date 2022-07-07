#ifndef MATHQ__DIMENSIONS_H
#define MATHQ__DIMENSIONS_H



namespace mathq {



  // ***************************************************************************
  // Dimensions 
  //
  // Vector of fixed  = rank_
  // if all non-zero ints... are provided, the values will be fixed as well
  // ***************************************************************************


  template<size_t rank_, size_t... ints>
  class Dimensions : public Vector<size_t, rank_> {
  public:
    using Type = Dimensions<rank_, ints...>;
    using Parent = Vector<size_t, rank_>;
    using ElementType = size_t;

    constexpr static size_t dims_rank() noexcept {
      return rank_;
    }
    constexpr static bool is_dynamic() noexcept {
      return check_dynamic<rank_, ints...>();
    }
    constexpr static size_t Nints = sizeof...(ints);
    constexpr static std::array<size_t, Nints> static_dims_array = { (static_cast<size_t>(ints))... };



    explicit Dimensions() {
      for (size_t n = 0; n < rank_; n++) {
        if (n < Nints) {
          Parent::operator[](n) = static_dims_array[n];
        } else {
          Parent::operator[](n) = 0;
        }
      }
    }

    template<typename...T, size_t DUMMY = is_dynamic(), mathq::EnableIf<(DUMMY == true) && (sizeof...(T) == rank_) && (std::conjunction<std::is_integral<T>...>::value)> = 0>
    Dimensions(T... dynamic_dims) {
      std::array<size_t, rank_> temp = { (static_cast<size_t>(dynamic_dims))... };
      for (size_t n = 0; n < rank_; n++) {
        Parent::operator[](n) = temp[n];
      }
    }
    // void foo(Args&& ... args) {
    // auto&& first = std::get<0>(std::forward_as_tuple(std::forward<Args>(args)...));

    Dimensions(const Dimensions<rank_>& dims2) {
      for (size_t n = 0; n < rank_; n++) {
        Parent::operator[](n) = dims2[n];
      }
    }

    // "read/write"
    template <bool value = is_dynamic()>
    typename std::enable_if<value, size_t&>::type operator[](const size_t n) {
      return Parent::operator[](n);
    }

    // "read"
    const size_t& operator[](const size_t n) const {
      return Parent::operator[](n);
    }

    template <bool value = is_dynamic()>
    typename std::enable_if<value, size_t&>::type resize(const size_t n) {
      return Parent::resize(n);
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
      s += StyledString::get(ANGLE1).get();
      s += num2string(rank_);
      for (size_t n = 0; n < Nints; n++) {
        s += StyledString::get(COMMA).get();
        s += num2string(static_dims_array[n]);
      }
      s += StyledString::get(ANGLE2).get();
      return s;
    }



  };


  template <size_t rank1, typename T1, size_t rank2, typename T2>
  inline bool equiv(const Dimensions<rank1>& dims1, const Dimensions<rank2>& dims2) {
    return dims1.equiv(dims2);
  }





};
#endif
