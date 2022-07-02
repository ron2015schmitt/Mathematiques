#ifndef MATHQ__MULTI_ARRAY_REPEAT_VECTOR_H
#define MATHQ__MULTI_ARRAY_REPEAT_VECTOR_H 1

namespace mathq {

  /********************************************************************
   * OuterProductMultiArray is a MultiArray that consists of a single 
   * vector across index `slot` repeated to fill the multiarray.
   * This is useful for grids.
   ********************************************************************
   */

  template <size_t slot, class Element, int rank, size_t... ints>
  class
    RepeatedVectorMultiArray : public MultiArray<Element, rank, ints>  {
  public:
  };

};
#endif
