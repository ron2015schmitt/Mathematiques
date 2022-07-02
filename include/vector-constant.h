#ifndef MATHQ__VECTOR_CONSTANT_H
#define MATHQ__VECTOR_CONSTANT_H 1

namespace mathq {

  /********************************************************************
   * ConstantVector is a MultiArray with every element the same
   ********************************************************************
   */

  template <class Element, size_t   N1>
  class
    ConstantVector : public MultiArray<Element, 1, N1> {
  public:
  };

};
#endif
