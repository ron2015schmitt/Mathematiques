
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
    constexpr Type L = Type::COVARIANT;
    constexpr Type H = Type::CONTRAVARIANT;
  };

  using TensorIndexEnum = TensorIndex::Type;


  constexpr TensorIndexEnum operator!(TensorIndexEnum x) {
    if (x == TensorIndex::L) {
      return TensorIndex::H;
    }
    else {
      return TensorIndex::L;
    }
  }


};


#endif




