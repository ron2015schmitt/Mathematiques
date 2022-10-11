#ifndef MATHQ__CODA
#define MATHQ__CODA


namespace mathq {

  template <typename X>
  X pow(const X& x, const exponent_symbols::Transpose& t) {
    return transpose(x);
  }
  template <typename X>
  X pow(const X& x, const exponent_symbols::Conjugate& t) {
    return mathq::conj(x);
  }
  template <typename X>
  X pow(const X& x, const exponent_symbols::Hermitian& t) {
    return adjoint(x);
  }



};


#endif
