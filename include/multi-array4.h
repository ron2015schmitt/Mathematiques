#ifndef MATHQ__MULTI_ARRAY4_H
#define MATHQ__MULTI_ARRAY4_H 1

namespace mathq {

  /********************************************************************
   * MArray4<Element>    -- variable size matrix (valarray)
   *                 Element  = type for elements
   * MArray4<Element,N1> -- fixed number of rows (valarray)
   *                 N1 = number of rows
   * MArray4<Element,N1,N2> -- fixed number of rows and cols (array)
   *                 N2 = number of cols
   * MArray4<Element,N1,N2,N4> -- fixed number of rows and cols and stories (array)
   *                 N4 = number of stories
   *
   *                 NumberType = number type
   *                   = underlying algebraic field
   *                     ex. int, double, std::complex<double>
   *                 depth_value = tensor depth. if Element=NumberType, then depth_value=1.
   *
   ********************************************************************
   */

  template <typename Element, size_t N1 = 0, size_t N2 = 0, size_t N3 = 0, size_t N4 = 0>
  class MArray4Helper {
  public:
    constexpr static size_t rank_value = 4;
    constexpr static bool is_dynamic = (N1 == 0) || (N2 == 0) || (N3 == 0) || (N4 == 0);
    constexpr static bool num_compile_time_elements = N1 * N2 * N3 * N4;

    using ConcreteType = MArray4<Element, N1, N2, N3, N4>;
    using DimensionsType = typename std::conditional< is_dynamic, DynamicDims<rank_value, N1, N2, N3, N4>, FixedDims<N1, N2, N3, N4> >::type;


    // ---- same for all subtypes --------
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();
    using MyArrayType = typename ArrayTypeTrait<Element, num_compile_time_elements>::Type;
    using NestedDimensionsType = NestedDims<DimensionsType, ElementDimensionsType>;
    using ElementDimensionsType = typename std::conditional< (depth_value == 1), NullDims, Element::DimensionsType>::type;

    // ---- same for all subtypes --------
    using ParentType = MArrayExpRW<
      ConcreteType,  // Derived
      Element,  // Element
      typename NumberTrait<Element>::Type, // Number
      depth_value,  // depth
      rank_value,  // rank
      DimensionsType, // DimensionsT
    >;
  };


  template <typename Element, size_t N1, size_t N2, size_t N3, size_t N4>
  class MultiArray<Element, 4, N1, N2, N3, N4> : public MArray4Helper<Element, N1, N2, N3, N4>::ParentType {

  public:

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************


    using Helper = MArray4Helper<Element, N1, N2, N3, N4>;



    // ---- same for all subtypes --------
    using ConcreteType = typename Helper::ConcreteType;
    using MyArrayType = Helper::MyArrayType;
    using DimensionsType = typename Helper::DimensionsType;
    using ElementDimensionsType = typename Helper::ElementDimensionsType;
    using NestedDimensionsType = typename Helper::NestedDimensionsType;
    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;




    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = Helper::rank_value;
    constexpr static size_t depth_value = Helper::depth_value;
    constexpr static size_t template_dimensions_value = DimensionsType;

    constexpr static bool is_dynamic() noexcept {
      return Helper::is_dynamic;
    }



    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    MyArrayType data_;


  public:
    if constexpr (is_dynamic()) {
      size_t n1 = N1;
      size_t n2 = N2;
      size_t n3 = N3;
      size_t n4 = N4;
    } else {
      static constexpr size_t n1 = N1;
      static constexpr size_t n2 = N2;
      static constexpr size_t n3 = N3;
      static constexpr size_t n4 = N4;
    }




    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    MArray4<Element, N1, N3, N2, N4>() {
    }


  };

};

#endif 
