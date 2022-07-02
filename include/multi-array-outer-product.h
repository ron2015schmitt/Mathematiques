#ifndef MATHQ__MULTI_ARRAY_OUTER_PRODUCT_H
#define MATHQ__MULTI_ARRAY_OUTER_PRODUCT_H 1

namespace mathq {

  /********************************************************************
   * OuterProductMultiArray is a MultiArray that can be written as
   *  an outer product (akak tensor product) of rank Vectors
   ********************************************************************
   */

  template <class Element, int rank, size_t... ints>
  class
    OuterProductMultiArray : public MultiArray<Element, rank, ints>  {
  public:
  };

};
#endif
