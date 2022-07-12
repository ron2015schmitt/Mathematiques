#ifndef MATHQ__MATRIX_OUExpressionR_PRODUCT_H
#define MATHQ__MATRIX_OUExpressionR_PRODUCT_H 1

namespace mathq {

  /********************************************************************
   * OuterProductMatrix is a Matrix that can be written as
   *  an outer product (akak tensor product) of rank Vectors
   ********************************************************************
   */

  template <class Element, int rank, size_t... ints>
  class
    OuterProductMatrix : public MultiArray<Element, rank, ints...>  {
  public:
  };

};
#endif
