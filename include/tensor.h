
#ifndef MATHQ_TENSOR
#define MATHQ_TENSOR



namespace mathq {



  //***********************************************************************
  //      indexing
  //***********************************************************************

  // ***************************************************************************
  // * TensorIndex enum
  // ***************************************************************************

  // put in a namespace so that the enums don't clash
  namespace TensorIndex {
    enum Type { COVARIANT = false, CONTRAVARIANT = true };
    namespace LH {
      constexpr Type L = Type::COVARIANT;
      constexpr Type H = Type::CONTRAVARIANT;
    }
  };

  using TensorIndexEnum = TensorIndex::Type;


  constexpr TensorIndexEnum operator!(TensorIndexEnum x) {
    if (x == TensorIndex::LH::L) {
      return TensorIndex::LH::H;
    }
    else {
      return TensorIndex::LH::L;
    }
  }


  // *****************************************************************************************
  // VectorFromTrait
  //
  // ****************************************************************************************

  template <typename T, size_t index = 0>
  class VectorFrom {
  public:
    using Type = void;
  };


  // 

  template <typename Element, size_t index, size_t rank>
  class VectorFrom<MultiArray<Element, rank>, index> {
  public:
    using Type = Vector<Element>;
  };

  // template <typename Element, size_t index, TensorIndexEnum... enums> requires (sizeof...(enums) == 2)


  template <typename Element, size_t index, size_t rank, size_t... ints>
  class VectorFrom<MultiArray<Element, rank, ints...>, index> {
  public:
    constexpr static std::array<size_t, rank> static_dims_array = { ints... };
    constexpr static size_t sz = std::get<index>(static_dims_array);
    using Type = Vector<Element, sz>;
  };



  template <typename T, size_t index = 0>
  class TensorFrom {
  public:
    constexpr static TensorIndexEnum ti = std::get<index>(T::static_enums_array);
    using Type = typename Vector<typename T::ElementType>::Tensor<ti>;
    using DualType = typename Vector<typename T::ElementType>::Tensor<!ti>;
  };


  // template <typename Element, size_t index, TensorIndexEnum... enums> requires (sizeof...(enums) == 2)
//   template <typename Element, size_t index, TensorIndexEnum E1, TensorIndexEnum E2>


  template <typename Element>
  using AAA = typename Matrix<Element>::Tensor<TensorIndex::LH::H, TensorIndex::LH::H>;

  template <typename Element>
  void aaa(const typename Matrix<Element>::Tensor<TensorIndex::LH::H, TensorIndex::LH::H>& x) {

  }

  // template <typename Element, size_t index>
  // class TensorFrom<Matrix<Element>, index> {
  // public:
  //   // constexpr static std::array<TensorIndexEnum, 2> enum_array = { enums... };
  //   // constexpr static TensorIndexEnum ti = std::get<index>(enum_array);
  //   using Type = typename Vector<Element>::Tensor<TensorIndex::LH::L>;
  // };





};


#endif




