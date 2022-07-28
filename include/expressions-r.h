#ifndef MATHQ__EXPRESSIONSR
#define MATHQ__EXPRESSIONSR

// "READ ONLY"  expressions

namespace mathq {

  //---------------------------------------------------------------------------
  // ExpressionR_Unary    unary expressions
  //---------------------------------------------------------------------------

  // NOTE: Number and Element are the output types!
  //       only the function/functor needs the input types

  template <class Derived, class Element, typename Number, size_t depth_, size_t rank_, class FUNC>
  class ExpressionR_Unary : public ExpressionR<ExpressionR_Unary<Derived, Element, Number, depth_, rank_, FUNC>, Element, Number, depth_, rank_> {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank_;
    constexpr static size_t depth_value = depth_;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Element;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Unary<Derived, ElementType, NumberType, depth_value, rank_value, FUNC>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;

  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    const Derived& x_;
    VectorofPtrs* vptrs;

  public:

    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Unary(const Derived& x) : x_(x) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      // DISP3(x);
    }

    ~ExpressionR_Unary() {
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return rank_value;
    }

    size_t depth(void) const {
      return depth_value;
    }

    size_t size(void) const {
      return x_.size();
    }

    size_t total_size(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->el_total_size());
      }
    }

    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }

    size_t el_total_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }

    //**********************************************************************
    //                        Dimensions
    //**********************************************************************


    const Dimensions& dims(void) const {
      return x_.dims();
    }

    ElementDimensionsType& element_dims(void) const {
      return x_.element_dims();
    }

    RecursiveDimensions& recursive_dims(void) const {
      return x_.recursive_dims();
    }



    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const NumberType dat(const size_t i) const {
      return FUNC::apply(x_.dat(i));
    }

    //**********************************************************************
    //***************** Element ACCESS *************************************
    //**********************************************************************

    const Element operator[](const size_t i) const {
      return FUNC::apply(x_[i]);
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline const std::string expression_name() const {
      return "ExpressionR_Unary";
    }


#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return FUNC::expression(sx);
    }
#endif

  };




  //---------------------------------------------------------------------------
  // ExpressionR_Unary_User    unary expressions
  //---------------------------------------------------------------------------

  // NOTE: Number and Element are the output types!
  //       only the function/functor needs the input types
  template <class Derived, class Element, typename Number, size_t depth_, size_t rank_>
  class ExpressionR_Unary_User : public ExpressionR<ExpressionR_Unary_User<Derived, Element, Number, depth_, rank_>, Element, Number, depth_, rank_> {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank_;
    constexpr static size_t depth_value = depth_;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************
    using FUNC = typename FunctionType1<Number, Number>::type;

    using ElementType = Element;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Unary_User<Derived, ElementType, NumberType, depth_value, rank_value>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;

  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    const Derived& x_;
    FUNC& f_;
    VectorofPtrs* vptrs;

  public:

    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Unary_User(const FUNC& f, const Derived& x) : x_(x), f_(f) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      // DISP3(x);
    }

    ~ExpressionR_Unary_User() {
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return rank_value;
    }

    size_t depth(void) const {
      return depth_value;
    }

    size_t size(void) const {
      return x_.size();
    }

    size_t total_size(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->el_total_size());
      }
    }

    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }

    size_t el_total_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }

    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    const Dimensions& dims(void) const {
      return x_.dims();
    }

    ElementDimensionsType& element_dims(void) const {
      return x_.element_dims();
    }

    RecursiveDimensions& recursive_dims(void) const {
      return x_.recursive_dims();
    }

    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const NumberType dat(const size_t i) const {
      return f_(x_.dat(i));
    }

    //**********************************************************************
    //***************** Element ACCESS *************************************
    //**********************************************************************

    const Element operator[](const size_t i) const {
      return f_(x_[i]);
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionR_Unary_User";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return expression(sx);
    }
#endif
  };



  //---------------------------------------------------------------------------
  // ExpressionR_Binary    binary expressions
  //---------------------------------------------------------------------------

  template <class A, class B, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t D1, size_t D2, size_t D3, size_t R1, size_t R2, size_t R3, class OP>
  class ExpressionR_Binary : public ExpressionR<ExpressionR_Binary<A, B, E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3, OP>, E3, NT3, D3, R3> {
  public:
    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = R3;
    constexpr static size_t depth_value = D3;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = E3;
    using NumberType = NT3;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Binary<A, B, E1, E2, ElementType, NT1, NT2, NumberType, D1, D2, depth_value, R1, R2, rank_value, OP>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;

    using TempA = typename std::conditional<D1 == 0, B, A>::type::ConcreteType;
    using TempB = typename std::conditional<D2 == 0, A, B>::type::ConcreteType;

    using TypeA = typename std::conditional<D1 == 0, const A, const A&>::type;
    using TypeB = typename std::conditional<D2 == 0, const B, const B&>::type;

  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    TypeA a_;
    TypeB b_;
    VectorofPtrs* vptrs;

  public:
    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Binary(const A& a, const B& b) : a_(a), b_(b) {
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

    ~ExpressionR_Binary() {
      // DISP3(vptrs);
      delete vptrs;
    }


    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return dims().size();
    }

    size_t depth(void) const {
      if constexpr (D1 >= D2) {
        return D1;
      }
      else {
        return D2;
      }
    }

    size_t size(void) const {
      if constexpr (D1 >= D2) {
        return a_.size();
      }
      else {
        return b_.size();
      }
    }

    size_t total_size(void) const {
      if constexpr (D1 >= D2) {
        return a_.total_size();
      }
      else {
        return b_.total_size();
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

    size_t el_total_size(void) const {
      if constexpr (D1 >= D2) {
        return a_.el_total_size();
      }
      else {
        return b_.el_total_size();
      }
    }

    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    DimensionsType& dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.dims();
      }
      else {
        return b_.dims();
      }
    }

    ElementDimensionsType& element_dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.element_dims();
      }
      else {
        return b_.element_dims();
      }
    }

    RecursiveDimensions& recursive_dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.recursive_dims();
      }
      else {
        return b_.recursive_dims();
      }
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
      size_t j = i % b_.total_size();
      return OP::apply(a_.dat(i), b_.dat(j));
    }

    // helper for: T + T<Element>
    const NT3 dat_top2(const size_t i) const {
      size_t j = i / b_.element_size();
      return OP::apply(a_.dat(j), b_.dat(i));
    }
    // helper for: Element + T<Element>
    const NT3 dat_el2(const size_t i) const {
      size_t j = i % a_.total_size();
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


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionR_Binary";
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
  // ExpressionR_Binary_User    binary expressions
  //---------------------------------------------------------------------------

  template <class A, class B, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t D1, size_t D2, size_t D3, size_t R1, size_t R2, size_t R3>
  class ExpressionR_Binary_User : public ExpressionR<ExpressionR_Binary_User<A, B, E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3>, E3, NT3, D3, R3> {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = R3;
    constexpr static size_t depth_value = D3;




    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = E3;
    using NumberType = NT3;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Binary_User<A, B, E1, E2, ElementType, NT1, NT2, NumberType, D1, D2, depth_value, R1, R2, rank_value>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;

    using TempA = typename std::conditional<D1 == 0, B, A>::type::ConcreteType;
    using TempB = typename std::conditional<D2 == 0, A, B>::type::ConcreteType;

    using TypeA = typename std::conditional<D1 == 0, const A, const A&>::type;
    using TypeB = typename std::conditional<D2 == 0, const B, const B&>::type;

    using FUNC = typename FunctionType2<NT1, NT2, NT3>::type;

  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    TypeA a_;
    TypeB b_;
    FUNC& f_;
    VectorofPtrs* vptrs;

  public:

    //**********************************************************************
    //                      Constructors
    //**********************************************************************
    ExpressionR_Binary_User(const FUNC& f, const A& a, const B& b) : f_(f), a_(a), b_(b) {
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

    ~ExpressionR_Binary_User() {
      delete vptrs;
    }



    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************
    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************
    size_t rank(void) const {
      return dims().size();
    }

    size_t depth(void) const {
      if constexpr (D1 >= D2) {
        return D1;
      }
      else {
        return D2;
      }
    }

    size_t size(void) const {
      if constexpr (D1 >= D2) {
        return a_.size();
      }
      else {
        return b_.size();
      }
    }
    size_t total_size(void) const {
      if constexpr (D1 >= D2) {
        return a_.total_size();
      }
      else {
        return b_.total_size();
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
    size_t el_total_size(void) const {
      if constexpr (D1 >= D2) {
        return a_.el_total_size();
      }
      else {
        return b_.el_total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************
    DimensionsType& dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.dims();
      }
      else {
        return b_.dims();
      }
    }
    RecursiveDimensions& recursive_dims(void) const {
      if constexpr (D1 >= D2) {
        return a_.recursive_dims();
      }
      else {
        return b_.recursive_dims();
      }
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
      size_t j = i % b_.total_size();
      return f_(a_.dat(i), b_.dat(j));
    }

    // helper for: T + T<Element>
    const NT3 dat_top2(const size_t i) const {
      size_t j = i / b_.element_size();
      return f_(a_.dat(j), b_.dat(i));
    }
    // helper for: Element + T<Element>
    const NT3 dat_el2(const size_t i) const {
      size_t j = i % a_.total_size();
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


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************


    std::string expression_name() const {
      return "ExpressionR_Binary_User";
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
  // ExpressionR_Ternary    ternary expressions
  //---------------------------------------------------------------------------

  template <
    class A, class B, class C,
    class E1, class E2, class E3, class E4,
    class NT1, class NT2, class NT3, typename NT4,
    size_t D1, size_t D2, size_t D3, size_t D4,
    size_t R1, size_t R2, size_t R3, size_t R4,
    class OP>
  class ExpressionR_Ternary : public ExpressionR<
    ExpressionR_Ternary<A, B, C, E1, E2, E3, E4, NT1, NT2, NT3, NT4, D1, D2, D3, D4, R1, R2, R3, R4, OP>,
    E4, NT4, D4, R4
  > {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = R4;
    constexpr static size_t depth_value = D4;




    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = E4;
    using NumberType = NT4;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Ternary<A, B, C, E1, E2, E3, ElementType, NT1, NT2, NT3, NumberType, D1, D2, D3, depth_value, R1, R2, R3, rank_value, OP>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;

    using TypeA = typename std::conditional<D1 == 0, const A, const A&>::type;
    using TypeB = typename std::conditional<D2 == 0, const B, const B&>::type;
    using TypeC = typename std::conditional<D3 == 0, const C, const C&>::type;

  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    TypeA a_;
    TypeB b_;
    TypeC c_;
    VectorofPtrs* vptrs;

  public:

    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Ternary(const A& a, const B& b, const C& c) : a_(a), b_(b), c_(c) {
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

    ~ExpressionR_Ternary() {
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return dims().size();
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

    size_t total_size(void) const {
      if constexpr (D1 > 0) {
        return a_.total_size();
      }
      else if constexpr (D2 > 0) {
        return b_.total_size();
      }
      else {
        return c_.total_size();
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

    size_t el_total_size(void) const {
      if constexpr (D1 > 0) {
        return a_.el_total_size();
      }
      else if constexpr (D2 > 0) {
        return b_.el_total_size();
      }
      else {
        return c_.el_total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    DimensionsType& dims(void) const {
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

    ElementDimensionsType& element_dims(void) const {
      if constexpr (D1 > 0) {
        return a_.element_dims();
      }
      else if constexpr (D2 > 0) {
        return b_.element_dims();
      }
      else {
        return c_.element_dims();
      }
    }


    RecursiveDimensions& recursive_dims(void) const {
      if constexpr (D1 > 0) {
        return a_.recursive_dims();
      }
      else if constexpr (D2 > 0) {
        return b_.recursive_dims();
      }
      else {
        return c_.recursive_dims();
      }
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    const NT4 dat(const size_t i) const {
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


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionR_Ternary";
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
  // ExpressionR_Series    used for Taylor and Maclaurin series
  //---------------------------------------------------------------------------

  template <class A, class Derived, class Element, typename Number, size_t depth_, size_t rank_>
  class ExpressionR_Series : public ExpressionR<ExpressionR_Series<A, Derived, Element, Number, depth_, rank_>, Element, Number, depth_, rank_> {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank_;
    constexpr static size_t depth_value = depth_;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Element;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Series<A, Derived, ElementType, NumberType, depth_value, rank_value>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;

  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    const A& a_;
    const Derived& x_;
    const size_t N_;
    const NumberType x0_;
    VectorofPtrs* vptrs;

  public:

    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Series(const A& a, const Derived& x, const size_t N, const NumberType x0)
      : a_(a), x_(x), N_(N), x0_(x0) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }
    ExpressionR_Series(const A& a, const Derived& x, const size_t N)
      : a_(a), x_(x), N_(N), x0_(0) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }

    ~ExpressionR_Series() {
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return rank_value;
    }

    size_t depth(void) const {
      return depth_value;
    }

    size_t size(void) const {
      return x_.size();
    }

    size_t total_size(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->el_total_size());
      }
    }

    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }

    size_t el_total_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************


    const Dimensions& dims(void) const {
      return x_.dims();
    }

    ElementDimensionsType& element_dims(void) const {
      return x_.element_dims();
    }

    RecursiveDimensions& recursive_dims(void) const {
      return x_.recursive_dims();
    }


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************

    const NumberType dat(const size_t i) const {

      const NumberType x = x_.dat(i) - x0_;
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

    //**********************************************************************
    //***************** Element ACCESS *************************************
    //**********************************************************************

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

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionR_Series";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return sx;
    }
#endif

  };





  //---------------------------------------------------------------------------
  // ExpressionR_Series2    used for fourier series
  //---------------------------------------------------------------------------

  template <class A, class B, class Derived, typename Number, class OP1, class OP2>
  class ExpressionR_Series2 : public ExpressionR<ExpressionR_Series2<A, B, Derived, Number, OP1, OP2>, Number, Number, 1, 1> {
  public:
    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 1;
    constexpr static size_t depth_value = 1;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Number;
    using NumberType = Number;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Series2<A, B, Derived, NumberType, OP1, OP2>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;



  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    const A& a_;
    const B& b_;
    const Derived& x_;
    const size_t N_;
    const NumberType k1_;
    Vector<Number>& k_;
    bool initialized;
    VectorofPtrs* vptrs;

  public:
    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Series2(const A& a, const A& b, const Derived& x, const size_t N, const NumberType k1)
      : a_(a), b_(b), x_(x), N_(N), k1_(k1), k_(*(new Vector<Number>(N))) {

      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      vptrs->add(x_.getAddresses());
      vptrs->add(k_.getAddresses());

      for (size_t n = 0; n < N_; n++) {
        k_[n] = n * k1_;
      }
    }
    ~ExpressionR_Series2() {
      delete& k_;
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return rank_value;
    }

    size_t depth(void) const {
      return depth_value;
    }

    size_t size(void) const {
      return x_.size();
    }

    size_t total_size(void) const {
      if constexpr (depth_value <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->el_total_size());
      }
    }

    size_t element_size(void) const {
      if constexpr (depth_value <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }

    size_t el_total_size(void) const {
      if constexpr (depth_value <= 1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    DimensionsType& dims(void) const {
      return x_.dims();
    }
    DimensionsType& element_dims(void) const {
      return x_.element_dims();
    }
    RecursiveDimensions& recursive_dims(void) const {
      return x_.recursive_dims();
    }



    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************

    const NumberType dat(const size_t i) const {
      return (*this)[i];
    }

    //**********************************************************************
    //***************** Element ACCESS *************************************
    //**********************************************************************
    const ElementType operator[](const size_t i) const {
      Number sum = 0;
      // TODO: check a_.size >= N
      for (size_t n = 0; n < N_; n++) {
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



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionR_Series2";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return sx;
    }
#endif
  };





  //-----------------------------------------------------------------------------
  // ExpressionR_Transpose   tensor transpose, ie reverse the order of indices (RHS only)
  //-----------------------------------------------------------------------------

  template <class Derived, class Element, typename Number, size_t depth_, size_t rank_, class FUNC>
  class ExpressionR_Transpose : public ExpressionR<ExpressionR_Transpose<Derived, Element, Number, depth_, rank_, FUNC>, Element, Number, depth_, rank_> {
  public:
    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank_;
    constexpr static size_t depth_value = depth_;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Element;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Transpose<Derived, ElementType, NumberType, depth_value, rank_value, FUNC>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;


  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    const Derived& x_;
    VectorofPtrs* vptrs;
    DimensionsType* reverse_dims;

  public:
    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Transpose(const Derived& x) : x_(x) {
      reverse_dims = &(x_.dims().getReverse());
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
    }

    ~ExpressionR_Transpose() {
      delete reverse_dims;
      delete vptrs;
    }


    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }


    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************
    size_t rank(void) const {
      return rank_value;
    }

    size_t depth(void) const {
      return depth_value;
    }

    size_t size(void) const {
      return x_.size();
    }

    size_t total_size(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->el_total_size());
      }
    }

    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }

    size_t el_total_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }



    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    DimensionsType& dims(void) const {
      return *reverse_dims;
    }
    DimensionsType& element_dims(void) const {
      return x_.element_dims().reverse();
    }
    RecursiveDimensions& recursive_dims(void) const {
      return x_.recursive_dims().reverse_each();
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    const NumberType dat(const size_t i) const {
      if constexpr (depth <= 1) {
        return (*this[i]);
      }
      else {
        size_t j = i / x_.element_size();
        size_t k = i % x_.element_size();
        return (*this[j][k]);
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    const Element operator[](const size_t index1) const {
      const Indices inds1 = Indices::indices(index1, *reverse_dims);
      const Indices inds2 = inds1.getReverse();
      const size_t index2 = inds2.index(x_.dims());
      return FUNC::apply(x_[index2]);
      return Element(0);
    }


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionR_Transpose";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sa = x_.expression();
      return FUNC::expression(sa);
    }
#endif
  };





  //---------------------------------------------------------------------------
  // VER_Join   joining two Vectors (RHS only)
  //---------------------------------------------------------------------------

  template <class X, class Y, class Element, typename Number, size_t depth_>
  class ExpressionR_Join : public ExpressionR<ExpressionR_Join<X, Y, Element, Number, depth_>, Element, Number, depth_, 1> {
  public:
    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 1;
    constexpr static size_t depth_value = depth_;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Element;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Join<X, Y, Element, Number, depth_>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;
  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    const X& x_;
    const Y& y_;
    VectorofPtrs* vptrs;

  public:
    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Join(const X& x, const Y& y) : x_(x), y_(y) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      vptrs->add(y_.getAddresses());
      // DISP3(x);
    }

    ~ExpressionR_Join() {
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }


    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return rank_value;
    }
    size_t depth(void) const {
      return depth;
    }
    size_t size(void) const {
      return x_.size() + y_.size();
    }
    size_t total_size(void) const {
      if constexpr (depth <= 1) {
        return this->size();
      }
      else {
        return x_.total_size() + y_.total_size();
      }
    }
    size_t element_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr (depth <= 1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************
    DimensionsType& dims(void) const {
      DimensionsType d(x_.size() + y_.size());
      return d;
    }
    DimensionsType& element_dims(void) const {
      return x_.element_dims();
    }
    RecursiveDimensions& recursive_dims(void) const {
      RecursiveDimensions rdims = x_.recursive_dims() + y_.recursive_dims();
      return rdims;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    const NumberType dat(const size_t i) const {
      if (i < x_.total_size()) {
        return x_.dat(i);
      }
      else {
        return y_.dat(i - x_.total_size());
      }
    }
    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    const Element operator[](const size_t i) const {
      if (i < x_.size()) {
        return x_[i];
      }
      else {
        return y_[i - x_.size()];
      }
    }


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************


    std::string expression_name() const {
      return "ExpressionR_Join";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return sx;
    }
#endif
  };





  //---------------------------------------------------------------------------
  // ExpressionR_Rep  repeat a vector
  //---------------------------------------------------------------------------

  template <class A, typename Number>
  class ExpressionR_Rep : public ExpressionR<ExpressionR_Rep<A, Number>, Number, Number, 1, 1> {
  public:
    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 1;
    constexpr static size_t depth_value = 1;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Number;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionR_Rep<A, NumberType>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;
  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    const A& a_;
    const size_t m_;
    const size_t N_;
    VectorofPtrs* vptrs;

  public:
    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionR_Rep(const A& a, const size_t m)
      : a_(a), m_(m), N_(a_.size()) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }

    ~ExpressionR_Rep() {
      delete vptrs;
    }


    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return true;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }



    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************
    size_t rank(void) const {
      return a_.rank();
    }
    size_t depth(void) const {
      return depth_value;
    }
    size_t size(void) const {
      return m_ * a_.size();
    }
    size_t total_size(void) const {
      if constexpr (depth_value <= 1) {
        return this->size();
      }
      else {
        return (this->size()) * (this->el_total_size());
      }
    }
    size_t element_size(void) const {
      if constexpr (depth_value <= 1) {
        return 1;
      }
      else {
        return a_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr (depth_value <= 1) {
        return 1;
      }
      else {
        return a_.el_total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************
    DimensionsType dims(void) const {
      return a_.dims();
    }
    RecursiveDimensions& recursive_dims(void) const {
      return a_.recursive_dims();
    }


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const NumberType dat(const size_t i) const {
      size_t index = size_t(i % total_size());
      return a_.dat(i);
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const ElementType operator[](const size_t i) const {
      size_t index = size_t(i % N_);
      //      PRINTF3("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
      return a_[index];
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************



    std::string expression_name() const {
      return "ExpressionR_Rep";
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      return "";
      //      return expression_VER_Join(a_.expression(),ii_.expression());
    }
#endif
  };



}; // namespace mathq
#endif
