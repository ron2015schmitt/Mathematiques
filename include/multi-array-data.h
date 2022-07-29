#ifndef MATHQ__MULTI_ARRAY_DATA
#define MATHQ__MULTI_ARRAY_DATA 1


namespace mathq {
  // **************************************************************************
  // *   ArrayTypeTrait
  //
  //
  // ************************************************************************** 

  template <typename Number, size_t NN>
  class ArrayTypeTrait {
  public:
    using Type = std::array<Number, NN>;
  };

  template <typename Number>
  class ArrayTypeTrait<Number, 0> {
  public:
    using Type = std::valarray<Number>;
  };






  template <typename Element, size_t rank, size_t... dim_ints > requires (validate_multi_array<rank, dim_ints...>())
  class MultiArrayData {
  public: 
    constexpr static size_t rank_value = rank;
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = (sizeof...(dim_ints) == 0);
    constexpr static size_t compile_time_size = calc_size<rank_value, dim_ints...>();

    // note that the following will be all zeroes for dyanmic multi-arrays
    constexpr static std::array<size_t, rank_value> static_dims_array = { (static_cast<size_t>(dim_ints))... };



    using Type = MultiArrayData<Element, rank_value, dim_ints...>;
    using ConcreteType = Type; 
    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;
    using MyArrayType = typename ArrayTypeTrait<Element, compile_time_size>::Type;

    MyArrayType data_;

    inline std::string classname() const {
      return ClassName();
    }

    // static ClassName() method 

    static inline std::string ClassName() {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      std::string s = "MultiArrayData";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += " rank=";
      s += std::to_string(rank_value);
      if constexpr (!is_dynamic_value) {
        for (size_t ii = 0; ii < static_dims_array.size(); ii++) {
          if (ii == 0) {
            s += StyledString::get(COMMA).get() + " ";
          }
          else {
            s += style.apply("⨯");
          }
          s += std::to_string(static_dims_array[ii]);
        }
      }
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Type& x) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;

      stream << style.apply(FormatDataVector::string_opening);
      stream << "\n  data = ";
      dispval_strm(stream, x.data_);
      stream << style.apply(FormatDataVector::string_delimeter);
      stream << "\n";
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }

  };



  //
  // specialization for DYNAMIC Matrices
  //

  // template <typename Element> 
  // class MultiArrayData<Element, 2> {
  //   public: 
  //     constexpr static size_t compile_time_size = calc_size<2, 0>();
  //     using MyArrayType = typename ArrayTypeTrait<Element, compile_time_size>::Type;
  //     MyArrayType data_;
  //     size_t N1;  
  //     size_t N2;  
     
  // };

  //
  // specialization: DYNAMIC arrays of higher rank
  //
  // These dynamic arrays need a dynamic_dims_array to keep track of the dimensions

  template <typename Element, size_t rank> requires (rank >= 2)
  class MultiArrayData<Element, rank> {
    public: 

    constexpr static size_t rank_value = rank;
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = false;
    constexpr static size_t compile_time_size = calc_size<rank_value, 0>();

    // note that the following will be all zeroes for dyanmic multi-arrays
    constexpr static std::array<size_t, rank_value> static_dims_array = {  };



    using Type = MultiArrayData<Element, rank_value>;
    using ConcreteType = Type; 
    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;
    using MyArrayType = typename ArrayTypeTrait<Element, compile_time_size>::Type;

    MyArrayType data_;
    std::array<size_t, rank> dynamic_dims_array = array_of_one_value<size_t, 0, rank>(); 

    inline std::string classname() const {
      return ClassName();
    }

    // static ClassName() method 

    static inline std::string ClassName() {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      std::string s = "MultiArrayData";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += " rank=";
      s += std::to_string(rank_value);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Type& x) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;

      stream << style.apply(FormatDataVector::string_opening);
      stream << "\n  data = ";
      dispval_strm(stream, x.data_);
      stream << style.apply(FormatDataVector::string_delimeter);
      stream << "\n  dims = ";
      dispval_strm(stream, x.dynamic_dims_array);
      stream << "\n";
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }

  };



};


#endif 
