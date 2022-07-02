#ifndef MATHQ__MATRIX_REPEAT_VECTOR_H
#define MATHQ__MATRIX_REPEAT_VECTOR_H 1

namespace mathq {

  /********************************************************************
   * RepeatedVectorMatrix is a Matrix that consists of a single 
   * vector across index `slot` repeated to fill the multiarray.
   * This is useful for grids.
   ********************************************************************
   */

  template <size_t slot, class Element, int rank, size_t... ints>
  class
    RepeatedVectorMatrix : public MultiArray<Element, rank, ints>  {
  public:
  };

};
#endif
