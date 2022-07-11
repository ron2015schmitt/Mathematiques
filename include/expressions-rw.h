#ifndef MATHQ__EXPRESSIONSRW_H
#define MATHQ__EXPRESSIONSRW_H


namespace mathq {




  //---------------------------------------------------------------------------
  // TERW_Subset   Subset Expression
  //---------------------------------------------------------------------------
  template<typename Number>
  class TERW_Subset : public  ExpressionRW<TERW_Subset<Number>, Number, Number, 1, 1> {
  public:
    constexpr static int rank_value = 1;
    constexpr static int depth_value = 1;
    typedef Materialize<Number, Number, depth_value, rank_value> ConcreteType;
    typedef Number ElementType;
    typedef Number NumberType;

  private:
    // can't be constant since we alow to be on left hand side
    Vector<Number>& x_;
    const Vector<size_t>& ii_;
    const bool delete_ii_;
    VectorofPtrs* vptrs;
  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;

    TERW_Subset(Vector<Number>& x, const Vector<size_t>& ii)
      : x_(x), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }
    TERW_Subset(Vector<Number>& x, const std::initializer_list<size_t>& list)
      : x_(x), ii_(*(new Vector<size_t>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }

    ~TERW_Subset() {
      if (delete_ii_) delete& ii_;
      delete vptrs;
    }


    const Number dat(const size_t i) const {
      size_t ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_.dat(ind);
    }
    MyNumberType& dat(const size_t i) {
      size_t ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_.dat(ind);
    }

    const Number operator[](const size_t i) const {
      size_t ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_[ind];
    }
    Number& operator[](const size_t i) {
      size_t ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_[ind];
    }

    template <class Y, class NT2>
    TERW_Subset<Number>& operator=(const ExpressionR<Y, NT2, NT2, depth_value, rank_value>& rhs) {
      return this->equals(rhs);
    }

    TERW_Subset<Number>& operator=(const Number d) {
      return this->equals(d);
    }

    //----------------------------------------------

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return ii_.size();
    }
    size_t rank(void) const {
      return x_.rank();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    RecursiveDimensions<depth_value>& recursive_dims(void) const {
      return x_.recursive_dims();
    }
    RecursiveDimensions<depth_value>& recursive_dims(RecursiveDimensions<depth_value>& parentdims) const {
      return x_.recursive_dims(parentdims);
    }

    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth_value;
    }
    size_t element_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }
    size_t total_size(void) const {
      if constexpr (depth_value<=1) {
        return this->size();
      }
      else {
        return (this->size())*(this->el_total_size());
      }
    }
    std::string expression_name() const {
      return "TERW_Subset";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_TERW_Subset(a_.expression(),ii_.expression());
    }
#endif
  };



  //--------------------------------------------------------------------------
  // TERW_Submask   Submask Expression
  //--------------------------------------------------------------------------
  template<typename Number>
  class TERW_Submask : public  ExpressionRW<TERW_Submask<Number>, Number, Number, 1, 1> {
  public:
    constexpr static int rank_value = 1;
    constexpr static int depth_value = 1;
    typedef Materialize<Number, Number, depth_value, rank_value> ConcreteType;
    typedef Number ElementType;
    typedef Number NumberType;

  private:
    // can't be constant since we alow to be on left hand side
    Vector<Number>& x_;
    const Vector<size_t>& ii_;
    VectorofPtrs* vptrs;

  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;

    TERW_Submask(Vector<Number>& x, const Vector<bool>& mask)
      : x_(x), ii_(*(new Vector<size_t>(findtrue(mask)))) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }
    ~TERW_Submask() {
      delete& ii_;
      delete vptrs;
    }


    const Number dat(const size_t i) const {
      size_t ind = ii_[i];
      return x_.dat(ind);
    }
    MyNumberType& dat(const size_t i) {
      size_t ind = ii_[i];
      return x_.dat(ind);
    }

    const Number operator[](const size_t i) const {
      size_t ind = ii_[i];
      return x_[ind];
    }
    Number& operator[](const size_t i) {
      size_t ind = ii_[i];
      return x_[ind];
    }

    template <class Y, class NT2>
    TERW_Submask<Number>& operator=(const ExpressionR<Y, NT2, NT2, depth_value, rank_value>& rhs) {
      return this->equals(rhs);
    }

    TERW_Submask<Number>& operator=(const Number d) {
      return this->equals(d);
    }

    //---------------------------------------------

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return ii_.size();
    }
    size_t rank(void) const {
      return x_.rank();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    RecursiveDimensions<depth_value>& recursive_dims(void) const {
      return x_.recursive_dims();
    }
    RecursiveDimensions<depth_value>& recursive_dims(RecursiveDimensions<depth_value>& parentdims) const {
      return x_.recursive_dims(parentdims);
    }

    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      return depth_value;
    }
    size_t element_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }
    size_t total_size(void) const {
      if constexpr (depth_value<=1) {
        return this->size();
      }
      else {
        return (this->size())*(this->el_total_size());
      }
    }
    std::string expression_name() const {
      return "TERW_Submask";
    }




#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_TERW_Submask(a_.expression(),ii_.expression());
    }
#endif
  };



  //---------------------------------------------------------------------------
  // VERW_Join   joining two Vectors (RHS only)
  //---------------------------------------------------------------------------

  template <class X, class Y, class Element, typename Number, int depth>
  class TERW_Join : public  ExpressionRW<TERW_Join<X, Y, Element, Number, depth>, Element, Number, depth, 1> {
  public:
    constexpr static int rank_value = 1;
    constexpr static int depth_value = depth;
    typedef Materialize<Element, Number, depth, rank_value> ConcreteType;
    typedef Element ElementType;
    typedef Number NumberType;

  private:
    // can't be constant since we alow to be on left hand side
    X& x_;
    Y& y_;
    VectorofPtrs* vptrs;

  public:



    TERW_Join(X& x, Y& y) : x_(x), y_(y) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      vptrs->add(y_.getAddresses());
      // DISP3(x);
    }

    ~TERW_Join() {
      delete vptrs;
    }

    const Number dat(const size_t i) const {
      if (i < x_.total_size()) {
        return x_.dat(i);
      }
      else {
        return y_.dat(i-x_.total_size());
      }
    }
    Number& dat(const size_t i) {
      if (i < x_.total_size()) {
        return x_.dat(i);
      }
      else {
        return y_.dat(i-x_.total_size());
      }
    }
    const Element operator[](const size_t i) const {
      if (i < x_.size()) {
        return x_[i];
      }
      else {
        return y_[i-x_.size()];
      }
    }
    Element& operator[](const size_t i) {
      if (i < x_.size()) {
        return x_[i];
      }
      else {
        return y_[i-x_.size()];
      }
    }

    template <class Z>
    TERW_Join<X, Y, Element, Number, depth>& operator=(const ExpressionR<Z, Element, Number, depth, 1>& rhs) {
      return this->equals(rhs);
    }

    TERW_Join<X, Y, Element, Number, depth>& operator=(const Number d) {
      return this->equals(d);
    }
    TERW_Join<X, Y, Element, Number, depth>& operator=(const Element& e) {
      return this->equals(e);
    }

    //----------------------------------------------
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return x_.size()+y_.size();
    }
    size_t rank(void) const {
      return rank_value;
    }
    Dimensions dims(void) const {
      Dimensions d(x_.size()+y_.size());
      return d;
    }
    Dimensions template_dims(void) const {
      return this->dims();
    }
    RecursiveDimensions<depth_value>& recursive_dims(void) const {
      RecursiveDimensions<depth_value>& ddims = *(new RecursiveDimensions<depth_value>);
      return recursive_dims(ddims);
    }
    RecursiveDimensions<depth_value>& recursive_dims(RecursiveDimensions<depth_value>& parentdims) const {
      const int N = parentdims.size();
      RecursiveDimensions<depth_value>& ddims = x_.recursive_dims(parentdims);
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
      if constexpr (depth<=1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr (depth<=1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }
    size_t total_size(void) const {
      if constexpr (depth<=1) {
        return this->size();
      }
      else {
        return x_.total_size() + y_.total_size();
      }
    }

    std::string expression_name() const {
      return "TERW_Join";
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return sx;
    }
#endif

  };







  //   //---------------------------------------------------------------------------
  //   // TERW_RealFromComplex  used for accessing real/imag part of complex vector
  //   //---------------------------------------------------------------------------
  //   template <typename Number, class OP, int depth>
  //     class TERW_RealFromComplex : public  ExpressionRW<Number,TERW_RealFromComplex<Number,OP,depth> > {
  //   private:
    // can't be constant since we alow to be on left hand side
  //     Vector<std::complex<Number> >& a_;
  //     VectorofPtrs *vptrs;

  //   public:
  //     typedef typename NumberTrait<Number>::Type MyNumberType;


  //   TERW_RealFromComplex(Vector<std::complex<Number> >& a)
  //     :   a_(a) { 
  //       vptrs = new VectorofPtrs();
  //       vptrs->add(&a_);
  //     }

  //     ~TERW_RealFromComplex() {
  //       delete vptrs;
  //     }

  //     const Number operator[](size_t i) const{
  //       return OP::give(a_[i]);
  //     }
  //     Number& operator[](size_t i) {
  //       return OP::give(a_[i]);
  //     }
  //     const MyNumberType dat(const size_t i) const {
  //       return OP::give(a_.dat(i));
  //     }
  //     MyNumberType& dat(const size_t i)  {
  //       return OP::give(a_.dat(i));
  //     }



  //     VectorofPtrs getAddresses(void) const {
  //       return *vptrs;
  //     }
  //     size_t size(void) const {
  //       return a_.size();
  //     }
  //     size_t rank(void) const {
  //       return a_.rank();
  //     }
  //     Dimensions dims(void) const {
  //       return a_.dims();
  //     }
  //     bool isExpression(void) const {
  //       return true;
  //     }
  //   size_t depth(void) const {
  //       return depth;
  //     }
  //   size_t element_size(void) const {
  //     if constexpr(depth<2) {
  //       return 1;
  //     } else {
  //       return a_.element_size();
  //     }
  //   }
  //   size_t el_total_size(void) const {
  //     if constexpr(depth<2) {
  //       return 1;
  //     } else {
  //       return a_.el_total_size();
  //     }
  //   }
  //     size_t total_size(void) const {
  //       if constexpr(depth<2) {
  // 	  return this->size();
  // 	} else {
  // 	return (this->size())*(this->el_total_size());
  //       }
  //     }
  //     std::string expression_name() const {
  //       return "TERW_RealFromComplex";
  //     }


  //     template <class NT2, class B>
  //       TERW_RealFromComplex<Number,OP,depth>& operator=(const ExpressionR<NT2,B>& rhs) { 
  //       return this->equals(rhs);
  //     }

  //     TERW_RealFromComplex<Number,OP,depth>& operator=(const MyNumberType d) { 
  //       return this->equals(d);
  //     }


  // #if MATRICKS_DEBUG>=1
  //     std::string expression(void) const {
  //       return a_.expression();
  //       //      return expression_VSliceObj(a_.expression(),start_,end_,step_);
  //     }
  // #endif 

  //   };




};

#endif 
