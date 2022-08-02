#ifndef MATHQ__MATRIX_CONSTANT
#define MATHQ__MATRIX_CONSTANT 1

namespace mathq {

  /********************************************************************
   * ConstantMatrix is a Matrix with every element the same
   ********************************************************************
   */

  template <class Element, size_t N1, size_t N2>
  class
    ConstantMatrix : public MultiArray<Element, 2, N1, N2>  {
  public:
  };

};
#endif
