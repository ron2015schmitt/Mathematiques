#ifndef MATHQ__MULTI_ARRAY_CONSTANT_H
#define MATHQ__MULTI_ARRAY_CONSTANT_H 1

namespace mathq {

  /********************************************************************
   * ConstantMultiArray is a MultiArray with every element the same
   ********************************************************************
   */

  template <class Element, int rank, size_t... ints>
  class
    ConstantMultiArray : public MultiArray<Element, rank, ints...>  {
  public:
  };

};
#endif
