#ifndef MATHQ__COMPLEXFIELDS
#define MATHQ__COMPLEXFIELDS 1


namespace mathq {

  template <typename TargetElement, IsComplexCoords Coords>
  class ComplexMathFunction;




  // ***************************************************************************
  // * ComplexMathFunction
  // ***************************************************************************

  template <typename TargetElement, IsComplexCoords Coords>
  class
    ComplexMathFunction : public MultiArray< MultiArray<TargetElement, Coords::total_num_dims>, 0 > {
  public:
    static constexpr size_t rank_value = 0;
    constexpr static bool is_dynamic_value = true;

    using ParentType = MultiArray< MultiArray<TargetElement, Coords::total_num_dims>, rank_value >;
    using GridElement = TargetElement;
    using CoordGridType = Coords::NumberType;
    using Type = ComplexMathFunction<TargetElement, Coords>;
    using CoordsWithoutTime = typename Coords::TypeWithoutTime;
    using TypeWithoutTime = ComplexMathFunction<TargetElement, CoordsWithoutTime>;

    using ParentType::operator=;
    using ParentType::resize;  // needed to find overloaded funcs
    using ParentType::set_equal_to;  // needed to find overloaded funcs

    const Coords& coordinates;

    ComplexMathFunction(const Coords& coords) : coordinates(coords) {
      Dimensions d(rank_value);
      d = Coords::total_num_dims;
      if constexpr (rank_value > 0) {
        ParentType::resize(d);
      }
      grids_resize(coords.grid_dims());
    }


    Dimensions& grid_dims(void) const {
      if constexpr (rank_value > 0) {
        return (*this)[0].dims();
      }
      else {
        return (*this)().dims();
      }
    }

    Type& grids_resize(const Dimensions& dims) {
      if constexpr (rank_value == 0) {
        (*this)().resize(dims);
      }
      else {
        for (size_t c = 0; c < ParentType::size(); c++) {
          (*this)[c].resize(dims);
        }
      }
      return *this;
    }


    //**********************************************************************
    //                    coordinates access
    //  Note: you cannot change the reference that holds the Coordinates 
    //        because C++ never allows this.
    //        and cannot change the coordinates themselves becasue they are const.
    //**********************************************************************

    // "read only"
    const Coords& coords() const {
      return coordinates;
    }

    bool at_time(const size_t t_i) const
      requires (Coords::TimeCoord_value) {
      // TypeWithoutTime& field = *(new TypeWithoutTime)
      return true;
    }


    template<typename T>
    inline Type& operator=(const T& rhs) {
      // TRDISP(ParentType());
      ParentType::set_equal_to(rhs);
      return *this;
    }

    inline Type& operator=(const Type& rhs) {
      // OUTPUT("operator= of field");
      ParentType::set_equal_to(rhs);
      return *this;
    }


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    // instance classname() method 

    inline std::string classname() const {
      return ClassName();
    }

    // static ClassName() method 

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "ComplexMathFunction";
      s += StyledString::get(ANGLE1).get();
      TargetElement d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += Coords::ClassName();
      s += StyledString::get(ANGLE2).get();
      return s;
    }


  };



};

#endif 
