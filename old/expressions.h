#ifndef MATRICKS__EXPRESSIONS_H
#define MATRICKS__EXPRESSIONS_H



namespace matricks {



  

  //---------------------------------------------------------------------------
  // TER_Unary    unary expressions
  //---------------------------------------------------------------------------
    
    template <class E, class A, class D, int M, FUNC> 
      class TER_Unary  : public  TensorR<D,TER_Unary<D,A,FUNC,M>> {
    public:
      typedef TensorR<E,A,D,M> TIN;
  
  private:
    const TIN& a_;
    VectorofPtrs *vptrs;
  
  public:



  TER_Unary(const TIN& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      DISP3(a);
    }
    
  ~TER_Unary() {
      delete vptrs;
    }

  const D dat(const index_type i) const {
    return FUNC::apply(a_.dat(i));
  }
  
  const E operator[](const index_type i) const {
    return FUNC::apply(a_[i]);
  }

    
  VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
  size_type size(void) const {
      return a_.size();
    }
  size_type ndims(void) const {
      return a_.ndims();
    }
  Dimensions dims(void) const {
      return a_.dims();
    }
  Dimensions tdims(void) const {
      return this->dims();
    }
  bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
  size_type deepsize(void) const {
    if constexpr(M<2) {
      return this->size();
    } else {
      return (this->size())*(this->eldeepsize());
    }
  }

  std::string classname() const {
      return "TER_Unary";
  }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };


  //---------------------------------------------------------------------------
  // TER_Binary    binary operator expressions
  //               note that there is no easy way to define the first template
  //               of TensorR<> below so use D1
  //---------------------------------------------------------------------------
  template<class A, class B, class D1, class D2, class OP, int M1, int M2>
    class TER_Binary : public  TensorR<typename ResultType<D1,D2,typename OP::Type>::Type,TER_Binary<A,B,D1,D2,OP,M1,M2> > {
  public:
    typedef typename std::conditional<M1==0,const A,const A&>::type TypeA;
    typedef typename std::conditional<M2==0,const B,const B&>::type TypeB;

  private:
    TypeA a_;
    TypeB b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D1>::Type NumType1;
    typedef typename NumberType<D2>::Type NumType2;
    typedef typename OP::Type NumTypeOut;
    typedef typename ResultType<D1,D2,typename OP::Type>::Type TensorTypeOut;
    

  TER_Binary(TypeA a, TypeB b)
    : a_(a), b_(b) {
      vptrs = new VectorofPtrs();
    }

    ~TER_Binary() {
      delete vptrs;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    const NumTypeOut dat(const index_type i) const {
      if constexpr((M1==0)&&(M2==0)) {
	return OP::apply(a_, b_);
      } else if constexpr((M1==0)&&(M2>0)) {
	  return OP::apply(a_, b_.dat(i));
      } else if constexpr((M1>0)&&(M2==0)) {
	  return OP::apply(a_.dat(i), b_);
      } else {
	if constexpr(M1==M2) {
	  return OP::apply(a_.dat(i), b_.dat(i));
	} else if constexpr(M1==M2+1) {
	  index_type j = i % b_.deepsize();
	  return OP::apply(a_.dat(i), b_.dat(j));
	} else if constexpr(M2==M1+1) {
	  index_type j = i % a_.deepsize();
	  return OP::apply(a_.dat(j), b_.dat(i));
	}
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const NumTypeOut operator[](const index_type i) const {
      if constexpr((M1==0)&&(M2==0)) {
	return OP::apply(a_, b_);
      } else if constexpr((M1==0)&&(M2==1)) {
	  return OP::apply(a_, b_[i]);
      } else if constexpr((M1==1)&&(M2==0)) {
	  return OP::apply(a_[i], b_);
      } else {
	if constexpr((M1==1)&&(M2==1)) {
	    return OP::apply(a_[i], b_[i]);
	} 
      }
    }

   

       
    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      if constexpr(M1>=M2) {
        return a_.size();
      } else {
        return b_.size();
      }
    }
    size_type ndims(void) const {
      return dims().size();
    }
    Dimensions dims(void) const {
      if constexpr(M1>=M2) {
        return a_.dims();
      } else {
        return b_.dims();
      }
    }
    bool isExpression(void) const {
      return true;
    }
    size_type depth(void) const {
      if constexpr(M1>=M2) {
        return M1;
      } else {
        return M2;
      }
    }
    size_type elsize(void) const {
      if constexpr(M1>=M2) {
        return a_.elsize();
      } else {
        return b_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr(M1>=M2) {
        return a_.eldeepsize();
      } else {
        return b_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr(M1>=M2) {
        return a_.deepsize();
      } else {
        return b_.deepsize();
      }
    }

    std::string classname() const {
      return "TER_Binary";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      // use typeof or typeid isnteadof  the above
      return "";
    }
#endif 


  };



  //---------------------------------------------------------------------------
  // TER_Ternary    ternary operator expressions
  //               note that there is no easy way to define the first template
  //               of TensorR<> below so use D1
  //---------------------------------------------------------------------------
  template<class A, class B, class C, class D1, class D2, class D3, class OP, int M1, int M2, int M3>
    class TER_Ternary : public  TensorR<typename ResultType<D1,D2,typename OP::Type>::Type,TER_Ternary<A,B,C,D1,D2,D3,OP,M1,M2,M3> > {
  public:
    typedef typename std::conditional<M1==0,const A,const A&>::type TypeA;
    typedef typename std::conditional<M2==0,const B,const B&>::type TypeB;
    typedef typename std::conditional<M3==0,const C,const C&>::type TypeC;

    
  private:
    TypeA a_;
    TypeB b_;
    TypeC c_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D1>::Type NumType1;
    typedef typename NumberType<D2>::Type NumType2;
    typedef typename NumberType<D3>::Type NumType3;
    typedef typename OP::Type NumTypeOut;
    

  TER_Ternary(TypeA a, TypeB b, TypeC c)
    : a_(a), b_(b), c_(c) {
      vptrs = new VectorofPtrs();
    }

    ~TER_Ternary() {
      delete vptrs;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    // TODO: below assumes c_ is a scalar. add other cases as needed
    
    const NumTypeOut dat(const index_type i) const {
      if constexpr((M1==0)&&(M2==0)) {
	  return OP::apply(a_, b_, c_);
      } else if constexpr((M1==0)&&(M2>0)) {
	  return OP::apply(a_, b_.dat(i), c_);
      } else if constexpr((M1>0)&&(M2==0)) {
	  return OP::apply(a_.dat(i), b_, c_);
      } else {
	if constexpr(M1==M2) {
	    return OP::apply(a_.dat(i), b_.dat(i), c_);
	} else if constexpr(M1==M2+1) {
	  index_type j = i % b_.deepsize();
	  return OP::apply(a_.dat(i), b_.dat(j), c_);
	} else if constexpr(M2==M1+1) {
	  index_type j = i % a_.deepsize();
	  return OP::apply(a_.dat(j), b_.dat(i), c_);
	}
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    // TODO: below assumes c_ is a scalar. add other cases as needed

    const NumTypeOut operator[](const index_type i) const {
      if constexpr((M1==0)&&(M2==0)) {
	  return OP::apply(a_, b_, c_);
      } else if constexpr((M1==0)&&(M2==1)) {
	  return OP::apply(a_, b_[i], c_);
      } else if constexpr((M1==1)&&(M2==0)) {
	  return OP::apply(a_[i], b_, c_);
      } else {
	if constexpr((M1==1)&&(M2==1)) {
	    return OP::apply(a_[i], b_[i], c_);
	} 
      }
    }

  
    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    // TODO: below assumes c_ is a scalar. add other cases as needed

    size_type size(void) const {
      if constexpr(M1>=M2) {
        return a_.size();
      } else {
        return b_.size();
      }
    }
    size_type ndims(void) const {
      if constexpr(M1>=M2) {
        return a_.ndims();
      } else {
        return b_.ndims();
      }
    }
    Dimensions dims(void) const {
      if constexpr(M1>=M2) {
        return a_.dims();
      } else {
        return b_.dims();
      }
    }
    bool isExpression(void) const {
      return true;
    }
    size_type depth(void) const {
      if constexpr(M1>=M2) {
        return M1;
      } else {
        return M2;
      }
    }
    size_type elsize(void) const {
      if constexpr(M1>=M2) {
        return a_.elsize();
      } else {
        return b_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr(M1>=M2) {
        return a_.eldeepsize();
      } else {
        return b_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr(M1>=M2) {
        return a_.deepsize();
      } else {
        return b_.deepsize();
      }
    }

    std::string classname() const {
      return "TER_Ternary";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      // use typeof or typeid isnteadof  the above
      return "";
    }
#endif 


  };


  

  
  

  //---------------------------------------------------------------------------
  // TERW_Subset   Subset Expression
  //---------------------------------------------------------------------------
  template<class D, int M>
    class TERW_Subset :  public  TensorRW<D,TERW_Subset<D,M> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>& ii_;
    const bool delete_ii_;
    VectorofPtrs *vptrs;
  public:
    typedef typename NumberType<D>::Type MyNumberType;

  TERW_Subset(Vector<D>& a, const Vector<index_type>& ii)
    : a_(a), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
  }
  TERW_Subset(Vector<D>& a, const std::initializer_list<index_type>& list)
    : a_(a), ii_(*(new Vector<index_type>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
  }
    
    ~TERW_Subset() {
      if (delete_ii_) delete &ii_;
      delete vptrs;
    }


    const MyNumberType dat(const index_type i) const {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.deepsize() + ind;
      }
      return a_.dat(ind);
    }
    MyNumberType& dat(const index_type i)  {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.deepsize() + ind;
      }
      return a_.dat(ind);
    }
  
    const D operator[](const index_type i) const {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }
    D& operator[](const index_type i)  {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }

    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return ii_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TERW_Subset";
    }


    template <class D2, class B>
      TERW_Subset<D>& operator=(const TensorR<D2,B>& rhs) { 
      return this->equals(rhs);
    }
    
    TERW_Subset<D>& operator=(const MyNumberType d) { 
      return this->equals(d);
    }
    
   
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_TERW_Subset(a_.expression(),ii_.expression());
    }
#endif



  };








  


  //---------------------------------------------------------------------------
  // TERW_Submask   subset of a tensor from a mask
  //---------------------------------------------------------------------------
  template<class D, int M>
    class TERW_Submask :  public  TensorRW<D,TERW_Submask<D,M> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>* ii_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TERW_Submask(Vector<D>& a, const Vector<bool>& mask)
    : a_(a), ii_(new Vector<index_type>(findtrue(mask))) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }


    ~TERW_Submask(){ 
      delete  ii_;
      delete vptrs;
    }

    const D operator[](const index_type i) const{
      index_type ind = (*ii_)[i];
      return a_[ind];
    }
     D& operator[](const index_type i) {
      index_type ind = (*ii_)[i];
      return a_[ind];
    }
     const MyNumberType dat(const index_type i) const {
       index_type ind = (*ii_)[i];
       return a_.dat(ind);
     }
     MyNumberType& dat(const index_type i)  {
       index_type ind = (*ii_)[i];
       return a_.dat(ind);
     }
  

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return ii_->size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TERW_Submask";
    }



    template <class D2, class B>
      TERW_Submask<D>& operator=(const TensorR<D2,B>& rhs) { 
      return this->equals(rhs);
    }
    
    TERW_Submask<D>& operator=(const MyNumberType d) { 
      return this->equals(d);
    }
    

    
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_TERW_Submask(a_.expression(),ii_->expression());
    }
#endif 



  };








  //---------------------------------------------------------------------------
  // TERW_RealFromComplex  used for accessing real/imag part of complex vector
  //---------------------------------------------------------------------------
  template <class D, class OP, int M>
    class TERW_RealFromComplex : public  TensorRW<D,TERW_RealFromComplex<D,OP,M> > {
  private:
    Vector<std::complex<D> >& a_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TERW_RealFromComplex(Vector<std::complex<D> >& a)
    :   a_(a) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TERW_RealFromComplex() {
      delete vptrs;
    }

    const D operator[](index_type i) const{
      return OP::give(a_[i]);
    }
    D& operator[](index_type i) {
      return OP::give(a_[i]);
    }
    const MyNumberType dat(const index_type i) const {
      return OP::give(a_.dat(i));
    }
    MyNumberType& dat(const index_type i)  {
      return OP::give(a_.dat(i));
    }



    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TERW_RealFromComplex";
    }


    template <class D2, class B>
      TERW_RealFromComplex<D,OP,M>& operator=(const TensorR<D2,B>& rhs) { 
      return this->equals(rhs);
    }
    
    TERW_RealFromComplex<D,OP,M>& operator=(const MyNumberType d) { 
      return this->equals(d);
    }
    

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return a_.expression();
      //      return expression_VSliceObj(a_.expression(),start_,end_,step_);
    }
#endif 

  };




  //---------------------------------------------------------------------------
  // TER_Series    used for Taylor and Maclaurin series
  //---------------------------------------------------------------------------

  template<class D, class A, class X, int M>
    class TER_Series : public  TensorR<D,TER_Series<D,A,X,M> > {

  private:
    const A& a_;
    const X& x_;
    const int N_;
    const D x0_;
    VectorofPtrs *vptrs;
    
  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_Series(const A& a, const X& x, const int N, const D x0)
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

    const D operator[](const index_type i) const {
      const D x = x_[i] - x0_;
      D sum = 0;
      // TODO: check a_.size >= N
      D xpow = 1;
      for (int n = 0; n <= N_ ; n++) {
	D an = a_[n];
	if (an!=D(0)) {
	  sum += an*xpow;
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
    size_type size(void) const {
      return x_.size();
      // TODO: check a_.size >= N
    }

    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TER_Series";
    }
  

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      // TODO: get this working
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sx = x_.expression(); */
      /* if (x_.vetype() != VE_Vector)  */
      /* 	sx = "(" + sx + ")"; */
      /* std::string sN = display::printf2str("%d",N_); */
      return "";
    }
#endif 


  };




  //---------------------------------------------------------------------------
  // TER_Series2    used for fourier series
  //---------------------------------------------------------------------------
  
  template<class D, class A, class B, class X, class OP1, class OP2, int M>
    class TER_Series2 : public  TensorR<D,TER_Series2< D, A, B, X, OP1, OP2> > {

  private:
    const A& a_;
    const B& b_;
    const X& x_;
    const int N_;
    const D k1_;
    Vector<D>& k_;
    bool initialized;
    VectorofPtrs *vptrs;
    
  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_Series2(const A& a, const A& b, const X& x, const int N, const D k1)
    : a_(a), b_(b), x_(x), N_(N), k1_(k1), k_(*(new Vector<D>(N))) {
      
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      vptrs->add(x_.getAddresses());
      vptrs->add(k_.getAddresses());
      
      for (int n = 0; n < N_ ; n++) {
	k_[n] = n*k1_;
      }
    }
    ~TER_Series2(){
      delete &k_;
      delete vptrs;
    }

    const D operator[](const index_type i) const {
      D sum = 0;
      // TODO: check a_.size >= N
      for (int n = 0; n < N_ ; n++) {
	D kx = k_[n]*x_[i];
	D an = a_[n];
	if (an != D(0)) {
	  sum += an*OP1::apply(kx);
	}
	D bn = b_[n];
	if (bn != D(0)) {
	  sum += bn*OP2::apply(kx);
	}
      }
      return sum; 
    }

  
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return x_.size();
    }
    size_type ndims(void) const {
      return x_.ndims();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TER_Series2";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      // TODO: get this working
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sx = x_.expression(); */
      /* if (x_.vetype() != VE_Vector)  */
      /* 	sx = "(" + sx + ")"; */
      /* std::string sN = display::printf2str("%d",N_); */
      /* return OP1::expression(sx); */
      return "";
    }
#endif 


  };







  








  //-----------------------------------------------------------------------------
  // TERW_Transpose   tensor transpose, ie reverse the order of indices (RHS only)
  //-----------------------------------------------------------------------------

  template<class D, class A, class FUNC, int M>
    class TERW_Transpose  : public  TensorRW<D,TERW_Transpose<D,A,FUNC,M> > {
  
  private:
    A& a_;
    VectorofPtrs *vptrs;
    Dimensions *rdims;
  public:
    typedef typename NumberType<D>::Type MyNumberType;



  TERW_Transpose(A& a) : a_(a) {
      rdims = &(a_.dims().getReverse());
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }
    
    ~TERW_Transpose() {
      delete rdims;
      delete vptrs;
    }

    const D operator[](const index_type index1) const {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const index_type index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
    }
    D& operator[](const index_type index1) {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const index_type index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
    }



    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return rdims->datasize();
    }
    size_type ndims(void) const {
      return rdims->ndims();
    }
    Dimensions dims(void) const {
      return *rdims;
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TERW_Transpose";
    }

    template <class D2, class B>
      TERW_Submask<D>& operator=(const TensorR<D2,B>& rhs) { 
      return this->equals(rhs);
    }
    
    TERW_Submask<D>& operator=(const MyNumberType d) { 
      return this->equals(d);
    }
    
    

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };





  //-----------------------------------------------------------------------------
  // TER_Transpose   tensor transpose, ie reverse the order of indices (RHS only)
  //-----------------------------------------------------------------------------

  template<class D, class A, class FUNC, int M>
    class TER_Transpose  : public  TensorR<D,TER_Transpose<D,A,FUNC,M> > {
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
    Dimensions *rdims;
  
  public:
    typedef typename NumberType<D>::Type MyNumberType;



  TER_Transpose(const A& a) : a_(a) {
      rdims = &(a_.dims().getReverse());
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }
    
    ~TER_Transpose() {
      delete rdims;
      delete vptrs;
    }

    const D operator[](const index_type index1) const {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const index_type index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return rdims->datasize();
    }
    size_type ndims(void) const {
      return rdims->ndims();
    }
    Dimensions dims(void) const {
      return *rdims;
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TER_Transpose";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };



  //---------------------------------------------------------------------------
  // VER_Join   joining two Tensors (RHS only)
  //---------------------------------------------------------------------------

  template<class D, class A, class B, int M>
    class VER_Join : public  TensorR<D,VER_Join<D,A,B,M> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  VER_Join(const A& a, const B& b)
    : a_(a), b_(b) { 

      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      
    }

    ~VER_Join() {
      delete vptrs;
    }
    
    const D operator[](const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
  
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return a_.size() +b_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "VER_Join";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VER_Join(a_.expression(),ii_.expression());
    }
#endif 

    
  };


  //---------------------------------------------------------------------------
  // VERW_Join  join two tensors
  //---------------------------------------------------------------------------


  template<class D, class A, class B, int M>
    class VERW_Join : public  TensorRW<D,VERW_Join<D,A,B,M> > {

  private:
    A& a_;
    B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  VERW_Join(A& a, B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
    }

    ~VERW_Join() {
      delete vptrs;
    }


    const D operator[](const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
     D& operator[](const index_type i) {
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return a_.size() +b_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "VERW_Join";
    }

    VERW_Join<D,A,B>& operator=(TERW_Resize<D>& b) { 
      return this->equals(b);
    }

    template <class C>
      VERW_Join<D,A,B>& operator=(const TensorR<D,C>& rhs) { 
      PRINTF2("VERW_Join<D,A,B>& operator=(const TensorR<D,C>& rhs)\n");
      return this->equals(rhs);
    }


    template <class D2, class C>
      VERW_Join<D,A,B>& operator=(const TensorR<D2,C>& rhs) { 
      return this->equals(rhs);
    }
    
    VERW_Join<D,A,B>& operator=(const MyNumberType d) { 
      return this->equals(d);
    }
    

    
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VER_Join(a_.expression(),ii_.expression());
    }
#endif 


  };


  


  //---------------------------------------------------------------------------
  // VER_Rep  repeat a tensor
  //---------------------------------------------------------------------------

  template<class D, class A, int M>
    class VER_Rep : public  TensorR<D,VER_Rep<D,A,M> > {

  private:
    const A& a_;
    const size_type m_;
    const size_type N_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  VER_Rep(const A& a, const size_type m)
    : a_(a), m_(m), N_(a_.size()) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }


    ~VER_Rep() {
      delete vptrs;
    }


    const D operator[](const index_type i) const{
      index_type index = index_type(i % N_);
      //      PRINTF3("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
      return a_[index];
    }


    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return m_*a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "VER_Rep";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VER_Join(a_.expression(),ii_.expression());
    }
#endif 

  };





};  //namespace matricks

#endif 
