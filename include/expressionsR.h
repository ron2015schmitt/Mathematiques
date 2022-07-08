#ifndef MATHQ__EXPRESSIONSR_H
#define MATHQ__EXPRESSIONSR_H

// "READ ONLY"  expressions

namespace mathq {

  //---------------------------------------------------------------------------
  // TER_Unary    unary expressions
  //---------------------------------------------------------------------------

  // NOTE: Number and Element are the output types!
  //       only the function/functor needs the input types

  template <class X, class Element, typename Number, int depth, int rank, class FUNC>
  class TER_Unary : public MArrayExpR<TER_Unary<X, Element, Number, depth, rank, FUNC>, Element, Number, depth, rank> {
  public:
    typedef Materialize<Element, Number, depth, rank> ConcreteType;
    typedef Element ElementType;
    typedef Number NumberType;
    constexpr static int rank_value = rank;
    constexpr static int depth_value = depth;

  private:
    const X& x_;
    VectorofPtrs* vptrs;

  public:
    TER_Unary(const X& x) : x_(x) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      // DISP3(x);
    }

    ~TER_Unary() {
      delete vptrs;
    }

    const Number dat(const size_t i) const {
      return FUNC::apply(x_.dat(i));
    }

    const Element operator[](const size_t i) const {
      return FUNC::apply(x_[i]);
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return x_.size();
    }
    size_t rank(void) const {
      return rank;
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& nested_dims(void) const {
      return x_.nested_dims();
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      return x_.nested_dims(parentdims);
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth;
    }
    Dimensions element_dims(void) const {
      return x_.element_dims();
    }
    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->eldeepsize());
      }
    }

    std::string classname() const {
      return "TER_Unary";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return FUNC::expression(sx);
    }
#endif
  };

  //---------------------------------------------------------------------------
  // TER_Unary_User    unary expressions
  //---------------------------------------------------------------------------

  // NOTE: Number and Element are the output types!
  //       only the function/functor needs the input types

  template <class X, class Element, typename Number, int depth, int rank>
  class TER_Unary_User : public MArrayExpR<TER_Unary_User<X, Element, Number, depth, rank>, Element, Number, depth, rank> {
  public:
    typedef Materialize<Element, Number, depth, rank> ConcreteType;
    typedef Element ElementType;
    typedef Number NumberType;
    typedef typename FunctionType1<Number, Number>::type FUNC;
    constexpr static int rank_value = rank;
    constexpr static int depth_value = depth;

  private:
    const X& x_;
    FUNC& f_;
    VectorofPtrs* vptrs;

  public:
    TER_Unary_User(const FUNC& f, const X& x) : x_(x), f_(f) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      // DISP3(x);
    }

    ~TER_Unary_User() {
      delete vptrs;
    }

    const Number dat(const size_t i) const {
      return f_(x_.dat(i));
    }

    const Element operator[](const size_t i) const {
      return f_(x_[i]);
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return x_.size();
    }
    size_t rank(void) const {
      return rank;
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& nested_dims(void) const {
      return x_.nested_dims();
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      return x_.nested_dims(parentdims);
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth;
    }
    Dimensions element_dims(void) const {
      return x_.element_dims();
    }
    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->eldeepsize());
      }
    }

    std::string classname() const {
      return "TER_Unary_User";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return expression(sx);
    }
#endif
  };

  //---------------------------------------------------------------------------
  // TER_Binary    binary expressions
  //---------------------------------------------------------------------------

  template <class A, class B, class E1, class E2, class E3, class NT1, class NT2, class NT3, int D1, int D2, int D3, int R1, int R2, int R3, class OP>
  class TER_Binary : public MArrayExpR<TER_Binary<A, B, E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3, OP>, E3, NT3, D3, R3> {
  public:
    typedef E3 ElementType;
    typedef NT3 NumberType;
    typedef typename std::conditional<D1 == 0, B, A>::type::ConcreteType TempA;
    typedef typename std::conditional<D2 == 0, A, B>::type::ConcreteType TempB;
    typedef Materialize<E3, NT3, D3, R3> ConcreteType;
    constexpr static int depth_value = D3;
    constexpr static int rank_value = R3;

    typedef typename std::conditional<D1 == 0, const A, const A&>::type TypeA;
    typedef typename std::conditional<D2 == 0, const B, const B&>::type TypeB;

  private:
    TypeA a_;
    TypeB b_;
    VectorofPtrs* vptrs;

  public:
    TER_Binary(const A& a, const B& b) : a_(a), b_(b) {
      vptrs = new VectorofPtrs();
      if constexpr (D1 > 0) {
        vptrs->add(a_.getAddresses());
      }
      if constexpr (D2 > 0) {
        vptrs->add(b_.getAddresses());
      }
      // DISP3(a);
      // DISP3(b);
      // DISP3(vptrs);
      // TLDISP3(E3());
      // TLDISP3(NT3());
      // MDISP3(D3, R3);
    }

    ~TER_Binary() {
      // DISP3(vptrs);
      delete vptrs;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    const NT3 dat(const size_t i) const {
      if constexpr ((D1 == 0) && (D2 == 0)) {
        return OP::apply(a_, b_);
      }
      else if constexpr ((D1 == 0) && (D2 > 0)) {
        return OP::apply(a_, b_.dat(i));
      }
      else if constexpr ((D1 > 0) && (D2 == 0)) {
        return OP::apply(a_.dat(i), b_);
      }
      else {
        if constexpr (D1 == D2) {
          return OP::apply(a_.dat(i), b_.dat(i));
        }
        else if constexpr (D1 == D2 + 1) {
          if constexpr ((D2 == 1) && (R2 == R1) && (R2 == E1::rank_value)) {
            if ((a_.size() == b_.size()) && (a_.element_size() == b_.size())) {
              return dat_el1(i); // note this is chosen by fiat
            }
            else if (a_.size() == b_.size()) {
              return dat_top1(i);
            }
            else if (a_.element_size() == b_.size()) {
              return dat_el1(i);
            }
            else {
              // TODO: error
              return 0;
            }
          }
          else if constexpr ((D2 == 1) && (R2 == R1)) {
            return dat_top1(i);
          }
          else if constexpr (R2 == E1::rank_value) {
            return dat_el1(i);
          }
          else {
            // TODO: error
            return 0;
          }
        }
        else if constexpr (D2 == D1 + 1) {
          if constexpr ((D1 == 1) && (R1 == R2) && (R1 == E2::rank_value)) {
            if ((a_.size() == b_.size()) && (a_.size() == b_.element_size())) {
              return dat_top2(i); // note this is chosen by fiat
            }
            else if (a_.size() == b_.size()) {
              return dat_top2(i);
            }
            else if (a_.size() == b_.element_size()) {
              return dat_el2(i);
            }
            else {
              // TODO: error
              return 0;
            }
          }
          else if constexpr ((D1 == 1) && (R1 == R2)) {
            return dat_top2(i);
          }
          else if constexpr (R1 == E2::rank_value) {
            return dat_el2(i);
          }
          else {
            // TODO: error
            return 0;
          }
        }
        else {
          // TODO: error
          return 0;
        }
      }
    }

    // helper for: T<Element> + T
    const NT3 dat_top1(const size_t i) const {
      size_t j = i / a_.element_size();
      return OP::apply(a_.dat(i), b_.dat(j));
    }
    // helper for: T<Element> + Element
    const NT3 dat_el1(const size_t i) const {
      size_t j = i % b_.deepsize();
      return OP::apply(a_.dat(i), b_.dat(j));
    }

    // helper for: T + T<Element>
    const NT3 dat_top2(const size_t i) const {
      size_t j = i / b_.element_size();
      return OP::apply(a_.dat(j), b_.dat(i));
    }
    // helper for: Element + T<Element>
    const NT3 dat_el2(const size_t i) const {
      size_t j = i % a_.deepsize();
      return OP::apply(a_.dat(j), b_.dat(i));
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const E3 operator[](const size_t i) const {
      if constexpr ((D1 == 0) && (D2 == 0)) {
        return OP::apply(a_, b_);
      }
      else if constexpr ((D1 == 0) && (D2 > 0)) {
        return OP::apply(a_, b_[i]);
      }
      else if constexpr ((D1 > 0) && (D2 == 0)) {
        return OP::apply(a_[i], b_);
      }
      else {
        if constexpr (D1 == D2) {
          return OP::apply(a_[i], b_[i]);
        }
        else if constexpr (D1 == D2 + 1) {
          if constexpr ((D2 == 1) && (R2 == R1) && (R2 == E1::rank_value)) {
            if ((a_.size() == b_.size()) && (a_.element_size() == b_.size())) {
              return el1(i); // note this is chosen by fiat
            }
            else if (a_.size() == b_.size()) {
              return top1(i);
            }
            else if (a_.element_size() == b_.size()) {
              return el1(i);
            }
            else {
              // TODO: error
              E3* e;
              return *e;
            }
          }
          else if constexpr ((D2 == 1) && (R2 == R1)) {
            return top1(i);
          }
          else if constexpr (R2 == E1::rank_value) {
            return el1(i);
          }
          else {
            // TODO: error
            E3* e;
            return *e;
          }
        }
        else if constexpr (D2 == D1 + 1) {
          if constexpr ((D1 == 1) && (R1 == R2) && (R1 == E2::rank_value)) {
            if ((a_.size() == b_.size()) && (a_.size() == b_.element_size())) {
              return top2(i); // note this is chosen by fiat
            }
            else if (a_.size() == b_.size()) {
              return top2(i);
            }
            else if (a_.size() == b_.element_size()) {
              return el2(i);
            }
            else {
              // TODO: error
              E3* e;
              return *e;
            }
          }
          else if constexpr ((D1 == 1) && (R1 == R2)) {
            return top2(i);
          }
          else if constexpr (R1 == E2::rank_value) {
            return el2(i);
          }
          else {
            // TODO: error
            E3* e;
            return *e;
          }
        }
        else {
          // TODO: error
          E3* e;
          return *e;
        }
      }
    }

    // helper for: T<Element> + T
    const E3 top1(const size_t i) const {
      return OP::apply(a_[i], b_[i]);
    }
    // helper for: T<Element> + Element
    const E3 el1(const size_t i) const {
      return OP::apply(a_[i], b_);
    }

    // helper for: T + T<Element>
    const E3 top2(const size_t i) const {
      return OP::apply(a_[i], b_[i]);
    }
    // helper for: Element + T<Element>
    const E3 el2(const size_t i) const {
      return OP::apply(a_, b_[i]);
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      if constexpr (D1 >= D2) {
        return a_.size();
      }
      else {
        return b_.size();
      }
    }
    size_t rank(void) const {
      return dims().size();
    }
    Dimensions dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.dims();
      }
      else {
        return b_.dims();
      }
    }
    std::vector<Dimensions>& nested_dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.nested_dims();
      }
      else {
        return b_.nested_dims();
      }
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      if constexpr (D1 >= D2) {
        return a_.nested_dims(parentdims);
      }
      else {
        return b_.nested_dims(parentdims);
      }
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      if constexpr (D1 >= D2) {
        return D1;
      }
      else {
        return D2;
      }
    }
    size_t element_size(void) const {
      if constexpr (D1 >= D2) {
        return a_.element_size();
      }
      else {
        return b_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (D1 >= D2) {
        return a_.eldeepsize();
      }
      else {
        return b_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (D1 >= D2) {
        return a_.deepsize();
      }
      else {
        return b_.deepsize();
      }
    }

    std::string classname() const {
      return "TER_Binary";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = a_.expression();
      std::string sy = a_.expression();
      return OP::expression(sx, sy);
    }
#endif
  };

  //---------------------------------------------------------------------------
  // TER_Binary_User    binary expressions
  //---------------------------------------------------------------------------

  template <class A, class B, class E1, class E2, class E3, class NT1, class NT2, class NT3, int D1, int D2, int D3, int R1, int R2, int R3>
  class TER_Binary_User : public MArrayExpR<TER_Binary_User<A, B, E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3>, E3, NT3, D3, R3> {
  public:
    typedef E3 ElementType;
    typedef NT3 NumberType;
    typedef typename std::conditional<D1 == 0, B, A>::type::ConcreteType TempA;
    typedef typename std::conditional<D2 == 0, A, B>::type::ConcreteType TempB;
    typedef Materialize<E3, NT3, D3, R3> ConcreteType;
    constexpr static int depth_value = D3;
    constexpr static int rank_value = R3;

    typedef typename std::conditional<D1 == 0, const A, const A&>::type TypeA;
    typedef typename std::conditional<D2 == 0, const B, const B&>::type TypeB;

    typedef typename FunctionType2<NT1, NT2, NT3>::type FUNC;

  private:
    TypeA a_;
    TypeB b_;
    FUNC& f_;
    VectorofPtrs* vptrs;

  public:
    TER_Binary_User(const FUNC& f, const A& a, const B& b) : f_(f), a_(a), b_(b) {
      vptrs = new VectorofPtrs();
      if constexpr (D1 > 0) {
        vptrs->add(a_.getAddresses());
      }
      if constexpr (D2 > 0) {
        vptrs->add(b_.getAddresses());
      }
      // DISP3(a);
      // DISP3(b);
    }

    ~TER_Binary_User() {
      delete vptrs;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    const NT3 dat(const size_t i) const {
      if constexpr ((D1 == 0) && (D2 == 0)) {
        return f_(a_, b_);
      }
      else if constexpr ((D1 == 0) && (D2 > 0)) {
        return f_(a_, b_.dat(i));
      }
      else if constexpr ((D1 > 0) && (D2 == 0)) {
        return f_(a_.dat(i), b_);
      }
      else {
        if constexpr (D1 == D2) {
          return f_(a_.dat(i), b_.dat(i));
        }
        else if constexpr (D1 == D2 + 1) {
          if constexpr ((D2 == 1) && (R2 == R1) && (R2 == E1::rank_value)) {
            if ((a_.size() == b_.size()) && (a_.element_size() == b_.size())) {
              return dat_el1(i); // note this is chosen by fiat
            }
            else if (a_.size() == b_.size()) {
              return dat_top1(i);
            }
            else if (a_.element_size() == b_.size()) {
              return dat_el1(i);
            }
            else {
              // TODO: error
              return 0;
            }
          }
          else if constexpr ((D2 == 1) && (R2 == R1)) {
            return dat_top1(i);
          }
          else if constexpr (R2 == E1::rank_value) {
            return dat_el1(i);
          }
          else {
            // TODO: error
            return 0;
          }
        }
        else if constexpr (D2 == D1 + 1) {
          if constexpr ((D1 == 1) && (R1 == R2) && (R1 == E2::rank_value)) {
            if ((a_.size() == b_.size()) && (a_.size() == b_.element_size())) {
              return dat_top2(i); // note this is chosen by fiat
            }
            else if (a_.size() == b_.size()) {
              return dat_top2(i);
            }
            else if (a_.size() == b_.element_size()) {
              return dat_el2(i);
            }
            else {
              // TODO: error
              return 0;
            }
          }
          else if constexpr ((D1 == 1) && (R1 == R2)) {
            return dat_top2(i);
          }
          else if constexpr (R1 == E2::rank_value) {
            return dat_el2(i);
          }
          else {
            // TODO: error
            return 0;
          }
        }
        else {
          // TODO: error
          return 0;
        }
      }
    }

    // helper for: T<Element> + T
    const NT3 dat_top1(const size_t i) const {
      size_t j = i / a_.element_size();
      return f_(a_.dat(i), b_.dat(j));
    }
    // helper for: T<Element> + Element
    const NT3 dat_el1(const size_t i) const {
      size_t j = i % b_.deepsize();
      return f_(a_.dat(i), b_.dat(j));
    }

    // helper for: T + T<Element>
    const NT3 dat_top2(const size_t i) const {
      size_t j = i / b_.element_size();
      return f_(a_.dat(j), b_.dat(i));
    }
    // helper for: Element + T<Element>
    const NT3 dat_el2(const size_t i) const {
      size_t j = i % a_.deepsize();
      return f_(a_.dat(j), b_.dat(i));
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const E3 operator[](const size_t i) const {
      if constexpr ((D1 == 0) && (D2 == 0)) {
        return f_(a_, b_);
      }
      else if constexpr ((D1 == 0) && (D2 > 0)) {
        return f_(a_, b_[i]);
      }
      else if constexpr ((D1 > 0) && (D2 == 0)) {
        return f_(a_[i], b_);
      }
      else {
        if constexpr (D1 == D2) {
          return f_(a_[i], b_[i]);
        }
        else if constexpr (D1 == D2 + 1) {
          if constexpr ((D2 == 1) && (R2 == R1) && (R2 == E1::rank_value)) {
            if ((a_.size() == b_.size()) && (a_.element_size() == b_.size())) {
              return el1(i); // note this is chosen by fiat
            }
            else if (a_.size() == b_.size()) {
              return top1(i);
            }
            else if (a_.element_size() == b_.size()) {
              return el1(i);
            }
            else {
              // TODO: error
              E3* e;
              return *e;
            }
          }
          else if constexpr ((D2 == 1) && (R2 == R1)) {
            return top1(i);
          }
          else if constexpr (R2 == E1::rank_value) {
            return el1(i);
          }
          else {
            // TODO: error
            E3* e;
            return *e;
          }
        }
        else if constexpr (D2 == D1 + 1) {
          if constexpr ((D1 == 1) && (R1 == R2) && (R1 == E2::rank_value)) {
            if ((a_.size() == b_.size()) && (a_.size() == b_.element_size())) {
              return top2(i); // note this is chosen by fiat
            }
            else if (a_.size() == b_.size()) {
              return top2(i);
            }
            else if (a_.size() == b_.element_size()) {
              return el2(i);
            }
            else {
              // TODO: error
              E3* e;
              return *e;
            }
          }
          else if constexpr ((D1 == 1) && (R1 == R2)) {
            return top2(i);
          }
          else if constexpr (R1 == E2::rank_value) {
            return el2(i);
          }
          else {
            // TODO: error
            E3* e;
            return *e;
          }
        }
        else {
          // TODO: error
          E3* e;
          return *e;
        }
      }
    }

    // helper for: T<Element> + T
    const E3 top1(const size_t i) const {
      return f_(a_[i], b_[i]);
    }
    // helper for: T<Element> + Element
    const E3 el1(const size_t i) const {
      return f_(a_[i], b_);
    }

    // helper for: T + T<Element>
    const E3 top2(const size_t i) const {
      return f_(a_[i], b_[i]);
    }
    // helper for: Element + T<Element>
    const E3 el2(const size_t i) const {
      return f_(a_, b_[i]);
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      if constexpr (D1 >= D2) {
        return a_.size();
      }
      else {
        return b_.size();
      }
    }
    size_t rank(void) const {
      return dims().size();
    }
    Dimensions dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.dims();
      }
      else {
        return b_.dims();
      }
    }
    std::vector<Dimensions>& nested_dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.nested_dims();
      }
      else {
        return b_.nested_dims();
      }
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      if constexpr (D1 >= D2) {
        return a_.nested_dims(parentdims);
      }
      else {
        return b_.nested_dims(parentdims);
      }
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      if constexpr (D1 >= D2) {
        return D1;
      }
      else {
        return D2;
      }
    }
    size_t element_size(void) const {
      if constexpr (D1 >= D2) {
        return a_.element_size();
      }
      else {
        return b_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (D1 >= D2) {
        return a_.eldeepsize();
      }
      else {
        return b_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (D1 >= D2) {
        return a_.deepsize();
      }
      else {
        return b_.deepsize();
      }
    }

    std::string classname() const {
      return "TER_Binary_User";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = a_.expression();
      std::string sy = a_.expression();
      return sx + sy;
    }
#endif
  };

  //---------------------------------------------------------------------------
  // TER_Ternary    ternary expressions
  //---------------------------------------------------------------------------

  template <class A, class B, class C, class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class D4, int D1, int D2, int D3, int M4, int R1, int R2, int R3, int R4, class OP>
  class TER_Ternary : public MArrayExpR<TER_Ternary<A, B, C, E1, E2, E3, E4, NT1, NT2, NT3, D4, D1, D2, D3, M4, R1, R2, R3, R4, OP>, E4, D4, M4, R4> {
  public:
    typedef E4 ElementType;
    typedef D4 NumberType;
    typedef Materialize<E4, D4, M4, R4> ConcreteType;
    constexpr static int depth_value = M4;
    constexpr static int rank_value = R4;

    typedef typename std::conditional<D1 == 0, const A, const A&>::type TypeA;
    typedef typename std::conditional<D2 == 0, const B, const B&>::type TypeB;
    typedef typename std::conditional<D3 == 0, const C, const C&>::type TypeC;

  private:
    TypeA a_;
    TypeB b_;
    TypeC c_;
    VectorofPtrs* vptrs;

  public:
    TER_Ternary(const A& a, const B& b, const C& c) : a_(a), b_(b), c_(c) {
      vptrs = new VectorofPtrs();
      if constexpr (D1 > 0) {
        vptrs->add(a_.getAddresses());
      }
      if constexpr (D2 > 0) {
        vptrs->add(b_.getAddresses());
      }
      if constexpr (D3 > 0) {
        // vptrs->add(c_.getAddresses());
      }
      // DISP3(a);
      // DISP3(b);
      // DISP3(c);
    }

    ~TER_Ternary() {
      delete vptrs;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    const D4 dat(const size_t i) const {
      if constexpr ((D1 == 0) && (D2 == 0) && (D3 == 0)) {
        return OP::apply(a_, b_, c_);
      }
      else if constexpr ((D1 == 0) && (D2 == 0) && (D3 > 0)) {
        return OP::apply(a_, b_, c_.dat(i));
      }
      else if constexpr ((D1 == 0) && (D2 > 0) && (D3 == 0)) {
        return OP::apply(a_, b_.dat(i), c_);
      }
      else if constexpr ((D1 == 0) && (D2 > 0) && (D3 > 0)) {
        return OP::apply(a_, b_.dat(i), c_.dat(i));
      }
      else if constexpr ((D1 > 0) && (D2 == 0) && (D3 == 0)) {
        return OP::apply(a_.dat(i), b_, c_);
      }
      else if constexpr ((D1 > 0) && (D2 == 0) && (D3 > 0)) {
        return OP::apply(a_.dat(i), b_, c_.dat(i));
      }
      else if constexpr ((D1 > 0) && (D2 > 0) && (D3 == 0)) {
        return OP::apply(a_.dat(i), b_.dat(i), c_);
      }
      else if constexpr ((D1 > 0) && (D2 > 0) && (D3 > 0)) {
        return OP::apply(a_.dat(i), b_.dat(i), c_.dat(i));
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const E4 operator[](const size_t i) const {
      if constexpr ((D1 == 0) && (D2 == 0) && (D3 == 0)) {
        return OP::apply(a_, b_, c_);
      }
      else if constexpr ((D1 == 0) && (D2 == 0) && (D3 > 0)) {
        return OP::apply(a_, b_, c_[i]);
      }
      else if constexpr ((D1 == 0) && (D2 > 0) && (D3 == 0)) {
        return OP::apply(a_, b_[i], c_);
      }
      else if constexpr ((D1 == 0) && (D2 > 0) && (D3 > 0)) {
        return OP::apply(a_, b_[i], c_[i]);
      }
      else if constexpr ((D1 > 0) && (D2 == 0) && (D3 == 0)) {
        return OP::apply(a_[i], b_, c_);
      }
      else if constexpr ((D1 > 0) && (D2 == 0) && (D3 > 0)) {
        return OP::apply(a_[i], b_, c_[i]);
      }
      else if constexpr ((D1 > 0) && (D2 > 0) && (D3 == 0)) {
        return OP::apply(a_[i], b_[i], c_);
      }
      else if constexpr ((D1 > 0) && (D2 > 0) && (D3 > 0)) {
        return OP::apply(a_[i], b_[i], c_[i]);
      }
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      if constexpr (D1 > 0) {
        return a_.size();
      }
      else if constexpr (D2 > 0) {
        return b_.size();
      }
      else {
        return c_.size();
      }
    }
    size_t rank(void) const {
      return dims().size();
    }
    Dimensions dims(void) const {
      if constexpr (D1 > 0) {
        return a_.dims();
      }
      else if constexpr (D2 > 0) {
        return b_.dims();
      }
      else {
        return c_.dims();
      }
    }
    std::vector<Dimensions>& nested_dims(void) const {
      if constexpr (D1 > 0) {
        return a_.nested_dims();
      }
      else if constexpr (D2 > 0) {
        return b_.nested_dims();
      }
      else {
        return c_.nested_dims();
      }
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      if constexpr (D1 > 0) {
        return a_.nested_dims(parentdims);
      }
      else if constexpr (D2 > 0) {
        return b_.nested_dims(parentdims);
      }
      else {
        return c_.nested_dims(parentdims);
      }
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      if constexpr (D1 > 0) {
        return a_.depth();
      }
      else if constexpr (D2 > 0) {
        return b_.depth();
      }
      else {
        return c_.depth();
      }
    }
    size_t element_size(void) const {
      if constexpr (D1 > 0) {
        return a_.element_size();
      }
      else if constexpr (D2 > 0) {
        return b_.element_size();
      }
      else {
        return c_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (D1 > 0) {
        return a_.eldeepsize();
      }
      else if constexpr (D2 > 0) {
        return b_.eldeepsize();
      }
      else {
        return c_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (D1 > 0) {
        return a_.deepsize();
      }
      else if constexpr (D2 > 0) {
        return b_.deepsize();
      }
      else {
        return c_.deepsize();
      }
    }

    std::string classname() const {
      return "TER_Ternary";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = a_.expression();
      std::string sy = b_.expression();
      std::string sz = c_.expression();
      return OP::expression(sx, sy, sz);
    }
#endif
  };

  //---------------------------------------------------------------------------
  // TER_Series    used for Taylor and Maclaurin series
  //---------------------------------------------------------------------------

  template <class A, class X, class Element, typename Number, int depth, int rank>
  class TER_Series : public MArrayExpR<TER_Series<A, X, Element, Number, depth, rank>, Element, Number, depth, rank> {
  public:
    typedef Materialize<Element, Number, depth, rank> ConcreteType;
    typedef Element ElementType;
    typedef Number NumberType;
    constexpr static int rank_value = rank;
    constexpr static int depth_value = depth;

  private:
    const A& a_;
    const X& x_;
    const int N_;
    const Number x0_;
    VectorofPtrs* vptrs;

  public:
    TER_Series(const A& a, const X& x, const int N, const Number x0)
      : a_(a), x_(x), N_(N), x0_(x0) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }
    TER_Series(const A& a, const X& x, const int N)
      : a_(a), x_(x), N_(N), x0_(0) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }

    ~TER_Series() {
      delete vptrs;
    }

    const Number dat(const size_t i) const {

      const Number x = x_.dat(i) - x0_;
      Number sum = 0;
      // TODO: check a_.size >= N
      Number xpow = 1;
      for (size_t n = 0; n <= N_; n++) {
        Number an = a_[n];
        if (an != Number(0)) {
          sum += an * xpow;
        }
        //	if (i==2) {
        //	  MDISP(x0_,x_[i],x,sum,xpow,N_,n,an);
        //	}
        xpow *= x;
      }
      return sum;
    }

    const Element operator[](const size_t i) const {
      const Element x = x_[i] - x0_;
      Element sum = 0;
      // TODO: check a_.size >= N
      Element xpow = 1;
      for (size_t n = 0; n <= N_; n++) {
        Number an = a_[n];
        if (an != Number(0)) {
          sum += an * xpow;
        }
        //	if (i==2) {
        //	  MDISP(x0_,x_[i],x,sum,xpow,N_,n,an);
        //	}
        xpow *= x;
      }
      return sum;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return x_.size();
    }
    size_t rank(void) const {
      return rank;
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& nested_dims(void) const {
      return x_.nested_dims();
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      return x_.nested_dims(parentdims);
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth;
    }
    Dimensions element_dims(void) const {
      return x_.element_dims();
    }
    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->eldeepsize());
      }
    }

    std::string classname() const {
      return "TER_Series";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return sx;
    }
#endif
  };

  //---------------------------------------------------------------------------
  // TER_Series2    used for fourier series
  //---------------------------------------------------------------------------

  template <class A, class B, class X, typename Number, class OP1, class OP2>
  class TER_Series2 : public MArrayExpR<TER_Series2<A, B, X, Number, OP1, OP2>, Number, Number, 1, 1> {
  public:
    typedef Materialize<Number, Number, 1, 1> ConcreteType;
    typedef Number ElementType;
    typedef Number NumberType;
    constexpr static int rank_value = 1;
    constexpr static int depth_value = 1;

  private:
    const A& a_;
    const B& b_;
    const X& x_;
    const int N_;
    const Number k1_;
    Vector<Number>& k_;
    bool initialized;
    VectorofPtrs* vptrs;

  public:
    TER_Series2(const A& a, const A& b, const X& x, const int N, const Number k1)
      : a_(a), b_(b), x_(x), N_(N), k1_(k1), k_(*(new Vector<Number>(N))) {

      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      vptrs->add(x_.getAddresses());
      vptrs->add(k_.getAddresses());

      for (int n = 0; n < N_; n++) {
        k_[n] = n * k1_;
      }
    }
    ~TER_Series2() {
      delete& k_;
      delete vptrs;
    }

    const Number dat(const size_t i) const {
      return (*this)[i];
    }

    const Number operator[](const size_t i) const {
      Number sum = 0;
      // TODO: check a_.size >= N
      for (int n = 0; n < N_; n++) {
        Number kx = k_[n] * x_[i];
        Number an = a_[n];
        if (an != Number(0)) {
          sum += an * OP1::apply(kx);
        }
        Number bn = b_[n];
        if (bn != Number(0)) {
          sum += bn * OP2::apply(kx);
        }
      }
      return sum;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return x_.size();
    }
    size_t rank(void) const {
      return rank_value;
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& nested_dims(void) const {
      return x_.nested_dims();
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      return x_.nested_dims(parentdims);
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth_value;
    }
    Dimensions element_dims(void) const {
      return x_.element_dims();
    }
    size_t element_size(void) const {
      if constexpr (depth_value <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (depth_value <= 1) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (depth_value <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->eldeepsize());
      }
    }

    std::string classname() const {
      return "TER_Series2";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return sx;
    }
#endif
  };

  //-----------------------------------------------------------------------------
  // TER_Transpose   tensor transpose, ie reverse the order of indices (RHS only)
  //-----------------------------------------------------------------------------

  template <class X, class Element, typename Number, int depth, int rank, class FUNC>
  class TER_Transpose : public MArrayExpR<TER_Transpose<X, Element, Number, depth, rank, FUNC>, Element, Number, depth, rank> {
  public:
    typedef Materialize<Element, Number, depth, rank> ConcreteType;
    typedef Element ElementType;
    typedef Number NumberType;
    constexpr static int rank_value = rank;
    constexpr static int depth_value = depth;

  private:
    const X& x_;
    VectorofPtrs* vptrs;
    Dimensions* rdims;

  public:
    TER_Transpose(const X& x) : x_(x) {
      rdims = &(x_.dims().getReverse());
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
    }

    ~TER_Transpose() {
      delete rdims;
      delete vptrs;
    }

    const Number dat(const size_t i) const {
      if constexpr (depth <= 1) {
        return (*this[i]);
      }
      else {
        size_t j = i / x_.element_size();
        size_t k = i % x_.element_size();
        return (*this[j][k]);
      }
    }

    const Element operator[](const size_t index1) const {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const size_t index2 = x_.dims().index(inds2);
      return FUNC::apply(x_[index2]);
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return rdims->datasize();
    }
    size_t rank(void) const {
      return rdims->rank();
    }
    Dimensions dims(void) const {
      return *rdims;
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth;
    }
    size_t element_size(void) const {
      if constexpr (depth < 2) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (depth < 2) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (depth < 2) {
        return this->size();
      }
      else {
        return (this->size()) * (this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TER_Transpose";
    }

#if MATRICKS_DEBUG >= 1
    std::string expression(void) const {
      std::string sa = x_.expression();
      return FUNC::expression(sa);
    }
#endif
  };

  //---------------------------------------------------------------------------
  // VER_Join   joining two Vectors (RHS only)
  //---------------------------------------------------------------------------

  template <class X, class Y, class Element, typename Number, int depth>
  class TER_Join : public MArrayExpR<TER_Join<X, Y, Element, Number, depth>, Element, Number, depth, 1> {
  public:
    constexpr static int rank_value = 1;
    constexpr static int depth_value = depth;
    typedef Materialize<Element, Number, depth, rank_value> ConcreteType;
    typedef Element ElementType;
    typedef Number NumberType;

  private:
    const X& x_;
    const Y& y_;
    VectorofPtrs* vptrs;

  public:
    TER_Join(const X& x, const Y& y) : x_(x), y_(y) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      vptrs->add(y_.getAddresses());
      DISP3(x);
    }

    ~TER_Join() {
      delete vptrs;
    }

    const Number dat(const size_t i) const {
      if (i < x_.deepsize()) {
        return x_.dat(i);
      }
      else {
        return y_.dat(i - x_.deepsize());
      }
    }
    const Element operator[](const size_t i) const {
      if (i < x_.size()) {
        return x_[i];
      }
      else {
        return y_[i - x_.size()];
      }
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return x_.size() + y_.size();
    }
    size_t rank(void) const {
      return rank_value;
    }
    Dimensions dims(void) const {
      Dimensions d(x_.size() + y_.size());
      return d;
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& nested_dims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return nested_dims(ddims);
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      const int N = parentdims.size();
      std::vector<Dimensions>& ddims = x_.nested_dims(parentdims);
      ddims[N] = this->dims();
      return ddims;
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth;
    }
    Dimensions element_dims(void) const {
      return x_.element_dims();
    }
    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return x_.deepsize() + y_.deepsize();
      }
    }

    std::string classname() const {
      return "TER_Join";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return sx;
    }
#endif
  };

  //---------------------------------------------------------------------------
  // TER_Rep  repeat a tensor
  //---------------------------------------------------------------------------

  template <class A, typename Number>
  class TER_Rep : public MArrayExpR<TER_Rep<A, Number>, Number, Number, 1, 1> {
  public:
    constexpr static int rank_value = 1;
    constexpr static int depth_value = 1;
    typedef Materialize<Number, Number, 1, 1> ConcreteType;
    typedef Number ElementType;
    typedef Number NumberType;

  private:
    const A& a_;
    const size_t m_;
    const size_t N_;
    VectorofPtrs* vptrs;

  public:
    TER_Rep(const A& a, const size_t m)
      : a_(a), m_(m), N_(a_.size()) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }

    ~TER_Rep() {
      delete vptrs;
    }

    const Number operator[](const size_t i) const {
      size_t index = size_t(i % N_);
      //      PRINTF3("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
      return a_[index];
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return m_ * a_.size();
    }
    size_t rank(void) const {
      return a_.rank();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& nested_dims(void) const {
      return a_.nested_dims();
    }
    std::vector<Dimensions>& nested_dims(std::vector<Dimensions>& parentdims) const {
      return a_.nested_dims(parentdims);
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth_value;
    }
    size_t element_size(void) const {
      if constexpr (depth_value <= 1) {
        return 1;
      }
      else {
        return a_.element_size();
      }
    }
    size_t eldeepsize(void) const {
      if constexpr (depth_value <= 1) {
        return 1;
      }
      else {
        return a_.eldeepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (depth_value <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TER_Rep";
    }

#if MATRICKS_DEBUG >= 1
    std::string expression(void) const {
      return "";
      //      return expression_VER_Join(a_.expression(),ii_.expression());
    }
#endif
  };

}; // namespace mathq
#endif
