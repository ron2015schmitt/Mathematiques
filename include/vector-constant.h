#ifndef MATHQ__VECTOR_CONSTANT
#define MATHQ__VECTOR_CONSTANT 1

namespace mathq {

  /********************************************************************
   * ConstantVector is a MultiArray with every element the same
   ********************************************************************
   */

  template <class Element, size_t N1>
  class
    ConstantVector : public MultiArray<Element, 1, N1> {
  public:
  };

};
#endif
