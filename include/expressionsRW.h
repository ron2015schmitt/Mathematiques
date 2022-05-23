#ifndef MATHQ__EXPRESSIONSRW_H
#define MATHQ__EXPRESSIONSRW_H


namespace mathq {




  //---------------------------------------------------------------------------
  // TERW_Subset   Subset Expression
  //---------------------------------------------------------------------------
  template<class D>
  class TERW_Subset : public  TensorRW<TERW_Subset<D>, D, D, 1, 1> {
  public:
    constexpr static int Rvalue = 1;
    constexpr static int Mvalue = 1;
    typedef Materialize<D, D, Mvalue, Rvalue> XType;
    typedef D EType;
    typedef D DType;

  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& x_;
    const Vector<index_type>& ii_;
    const bool delete_ii_;
    VectorofPtrs* vptrs;
  public:
    typedef typename NumberType<D>::Type MyNumberType;

    TERW_Subset(Vector<D>& x, const Vector<index_type>& ii)
      : x_(x), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }
    TERW_Subset(Vector<D>& x, const std::initializer_list<index_type>& list)
      : x_(x), ii_(*(new Vector<index_type>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }

    ~TERW_Subset() {
      if (delete_ii_) delete& ii_;
      delete vptrs;
    }


    const D dat(const index_type i) const {
      index_type ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_.dat(ind);
    }
    MyNumberType& dat(const index_type i) {
      index_type ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_.dat(ind);
    }

    const D operator[](const index_type i) const {
      index_type ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_[ind];
    }
    D& operator[](const index_type i) {
      index_type ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_[ind];
    }

    template <class Y, class D2>
    TERW_Subset<D>& operator=(const TensorR<Y, D2, D2, Mvalue, Rvalue>& rhs) {
      return this->equals(rhs);
    }

    TERW_Subset<D>& operator=(const D d) {
      return this->equals(d);
    }

    //----------------------------------------------

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return ii_.size();
    }
    size_type ndims(void) const {
      return x_.ndims();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions tdims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      return x_.deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return x_.deepdims(parentdims);
    }

    bool isExpression(void) const {
      return true;
    }
    size_type depth(void) const {
      return Mvalue;
    }
    size_type elsize(void) const {
      if constexpr (Mvalue<=1) {
        return 1;
      }
      else {
        return x_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr (Mvalue<=1) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr (Mvalue<=1) {
        return this->size();
      }
      else {
        return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
  template<class D>
  class TERW_Submask : public  TensorRW<TERW_Submask<D>, D, D, 1, 1> {
  public:
    constexpr static int Rvalue = 1;
    constexpr static int Mvalue = 1;
    typedef Materialize<D, D, Mvalue, Rvalue> XType;
    typedef D EType;
    typedef D DType;

  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& x_;
    const Vector<index_type>& ii_;
    VectorofPtrs* vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;

    TERW_Submask(Vector<D>& x, const Vector<bool>& mask)
      : x_(x), ii_(*(new Vector<index_type>(findtrue(mask)))) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }
    ~TERW_Submask() {
      delete& ii_;
      delete vptrs;
    }


    const D dat(const index_type i) const {
      index_type ind = ii_[i];
      return x_.dat(ind);
    }
    MyNumberType& dat(const index_type i) {
      index_type ind = ii_[i];
      return x_.dat(ind);
    }

    const D operator[](const index_type i) const {
      index_type ind = ii_[i];
      return x_[ind];
    }
    D& operator[](const index_type i) {
      index_type ind = ii_[i];
      return x_[ind];
    }

    template <class Y, class D2>
    TERW_Submask<D>& operator=(const TensorR<Y, D2, D2, Mvalue, Rvalue>& rhs) {
      return this->equals(rhs);
    }

    TERW_Submask<D>& operator=(const D d) {
      return this->equals(d);
    }

    //---------------------------------------------

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return ii_.size();
    }
    size_type ndims(void) const {
      return x_.ndims();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions tdims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      return x_.deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return x_.deepdims(parentdims);
    }

    bool isExpression(void) const {
      return true;
    }
    size_type depth(void) const {
      return Mvalue;
    }
    size_type elsize(void) const {
      if constexpr (Mvalue<=1) {
        return 1;
      }
      else {
        return x_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr (Mvalue<=1) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr (Mvalue<=1) {
        return this->size();
      }
      else {
        return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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

  template <class X, class Y, class E, class D, int M>
  class TERW_Join : public  TensorRW<TERW_Join<X, Y, E, D, M>, E, D, M, 1> {
  public:
    constexpr static int Rvalue = 1;
    constexpr static int Mvalue = M;
    typedef Materialize<E, D, M, Rvalue> XType;
    typedef E EType;
    typedef D DType;

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

    const D dat(const index_type i) const {
      if (i < x_.deepsize()) {
        return x_.dat(i);
      }
      else {
        return y_.dat(i-x_.deepsize());
      }
    }
    D& dat(const index_type i) {
      if (i < x_.deepsize()) {
        return x_.dat(i);
      }
      else {
        return y_.dat(i-x_.deepsize());
      }
    }
    const E operator[](const index_type i) const {
      if (i < x_.size()) {
        return x_[i];
      }
      else {
        return y_[i-x_.size()];
      }
    }
    E& operator[](const index_type i) {
      if (i < x_.size()) {
        return x_[i];
      }
      else {
        return y_[i-x_.size()];
      }
    }

    template <class Z>
    TERW_Join<X, Y, E, D, M>& operator=(const TensorR<Z, E, D, M, 1>& rhs) {
      return this->equals(rhs);
    }

    TERW_Join<X, Y, E, D, M>& operator=(const D d) {
      return this->equals(d);
    }
    TERW_Join<X, Y, E, D, M>& operator=(const E& e) {
      return this->equals(e);
    }

    //----------------------------------------------
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return x_.size()+y_.size();
    }
    size_type ndims(void) const {
      return Rvalue;
    }
    Dimensions dims(void) const {
      Dimensions d(x_.size()+y_.size());
      return d;
    }
    Dimensions tdims(void) const {
      return this->dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return deepdims(ddims);
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      const int N = parentdims.size();
      std::vector<Dimensions>& ddims = x_.deepdims(parentdims);
      ddims[N] = this->dims();
      return ddims;
    }
    bool isExpression(void) const {
      return true;
    }
    size_type depth(void) const {
      return M;
    }
    Dimensions eldims(void) const {
      return x_.eldims();
    }
    size_type elsize(void) const {
      if constexpr (M<=1) {
        return 1;
      }
      else {
        return x_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr (M<=1) {
        return 1;
      }
      else {
        return x_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr (M<=1) {
        return this->size();
      }
      else {
        return x_.deepsize() + y_.deepsize();
      }
    }

    std::string classname() const {
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
  //   template <class D, class OP, int M>
  //     class TERW_RealFromComplex : public  TensorRW<D,TERW_RealFromComplex<D,OP,M> > {
  //   private:
    // can't be constant since we alow to be on left hand side
  //     Vector<std::complex<D> >& a_;
  //     VectorofPtrs *vptrs;

  //   public:
  //     typedef typename NumberType<D>::Type MyNumberType;


  //   TERW_RealFromComplex(Vector<std::complex<D> >& a)
  //     :   a_(a) { 
  //       vptrs = new VectorofPtrs();
  //       vptrs->add(&a_);
  //     }

  //     ~TERW_RealFromComplex() {
  //       delete vptrs;
  //     }

  //     const D operator[](index_type i) const{
  //       return OP::give(a_[i]);
  //     }
  //     D& operator[](index_type i) {
  //       return OP::give(a_[i]);
  //     }
  //     const MyNumberType dat(const index_type i) const {
  //       return OP::give(a_.dat(i));
  //     }
  //     MyNumberType& dat(const index_type i)  {
  //       return OP::give(a_.dat(i));
  //     }



  //     VectorofPtrs getAddresses(void) const {
  //       return *vptrs;
  //     }
  //     size_type size(void) const {
  //       return a_.size();
  //     }
  //     size_type ndims(void) const {
  //       return a_.ndims();
  //     }
  //     Dimensions dims(void) const {
  //       return a_.dims();
  //     }
  //     bool isExpression(void) const {
  //       return true;
  //     }
  //   size_type depth(void) const {
  //       return M;
  //     }
  //   size_type elsize(void) const {
  //     if constexpr(M<2) {
  //       return 1;
  //     } else {
  //       return a_.elsize();
  //     }
  //   }
  //   size_type eldeepsize(void) const {
  //     if constexpr(M<2) {
  //       return 1;
  //     } else {
  //       return a_.eldeepsize();
  //     }
  //   }
  //     size_type deepsize(void) const {
  //       if constexpr(M<2) {
  // 	  return this->size();
  // 	} else {
  // 	return (this->size())*(this->eldeepsize());
  //       }
  //     }
  //     std::string classname() const {
  //       return "TERW_RealFromComplex";
  //     }


  //     template <class D2, class B>
  //       TERW_RealFromComplex<D,OP,M>& operator=(const TensorR<D2,B>& rhs) { 
  //       return this->equals(rhs);
  //     }

  //     TERW_RealFromComplex<D,OP,M>& operator=(const MyNumberType d) { 
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
