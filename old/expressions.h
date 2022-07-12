#ifndef MATRICKS__EXPRESSIONS_H
#define MATRICKS__EXPRESSIONS_H



namespace matricks {



  

  //---------------------------------------------------------------------------
  // ExpressionR_Unary    unary expressions
  //---------------------------------------------------------------------------
    
    template <class Element, class A, typename Number, int depth, FUNC> 
      class ExpressionR_Unary  : public  ExpressionR<Number,ExpressionR_Unary<Number,A,FUNC,depth>> {
    public:
      typedef ExpressionR<Element,A,Number,depth> TIN;
  
  private:
    const TIN& a_;
    VectorofPtrs *vptrs;
  
  public:



  ExpressionR_Unary(const TIN& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      DISP3(a);
    }
    
  ~ExpressionR_Unary() {
      delete vptrs;
    }

  const Number dat(const size_t i) const {
    return FUNC::apply(a_.dat(i));
  }
  
  const Element operator[](const size_t i) const {
    return FUNC::apply(a_[i]);
  }

    
  VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
  size_t size(void) const {
      return a_.size();
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
  bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
  size_t total_size(void) const {
    if constexpr(depth<2) {
      return this->size();
    } else {
      return (this->size())*(this->el_total_size());
    }
  }

  std::string classname() const {
      return "ExpressionR_Unary";
  }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };


  //---------------------------------------------------------------------------
  // ExpressionR_Binary    binary operator expressions
  //               note that there is no easy way to define the first template
  //               of ExpressionR<> below so use NT1
  //---------------------------------------------------------------------------
  template<class A, class B, class NT1, class NT2, class OP, int D1, int D2>
    class ExpressionR_Binary : public  ExpressionR<typename ResultType<NT1,NT2,typename OP::Type>::Type,ExpressionR_Binary<A,B,NT1,NT2,OP,D1,D2> > {
  public:
    typedef typename std::conditional<D1==0,const A,const A&>::type TypeA;
    typedef typename std::conditional<D2==0,const B,const B&>::type TypeB;

  private:
    TypeA a_;
    TypeB b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberTrait<NT1>::Type NumType1;
    typedef typename NumberTrait<NT2>::Type NumType2;
    typedef typename OP::Type NumTypeOut;
    typedef typename ResultType<NT1,NT2,typename OP::Type>::Type MultiArrayTypeOut;
    

  ExpressionR_Binary(TypeA a, TypeB b)
    : a_(a), b_(b) {
      vptrs = new VectorofPtrs();
    }

    ~ExpressionR_Binary() {
      delete vptrs;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    const NumTypeOut dat(const size_t i) const {
      if constexpr((D1==0)&&(D2==0)) {
	return OP::apply(a_, b_);
      } else if constexpr((D1==0)&&(D2>0)) {
	  return OP::apply(a_, b_.dat(i));
      } else if constexpr((D1>0)&&(D2==0)) {
	  return OP::apply(a_.dat(i), b_);
      } else {
	if constexpr(D1==D2) {
	  return OP::apply(a_.dat(i), b_.dat(i));
	} else if constexpr(D1==D2+1) {
	  size_t j = i % b_.total_size();
	  return OP::apply(a_.dat(i), b_.dat(j));
	} else if constexpr(D2==D1+1) {
	  size_t j = i % a_.total_size();
	  return OP::apply(a_.dat(j), b_.dat(i));
	}
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const NumTypeOut operator[](const size_t i) const {
      if constexpr((D1==0)&&(D2==0)) {
	return OP::apply(a_, b_);
      } else if constexpr((D1==0)&&(D2==1)) {
	  return OP::apply(a_, b_[i]);
      } else if constexpr((D1==1)&&(D2==0)) {
	  return OP::apply(a_[i], b_);
      } else {
	if constexpr((D1==1)&&(D2==1)) {
	    return OP::apply(a_[i], b_[i]);
	} 
      }
    }

   

       
    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      if constexpr(D1>=D2) {
        return a_.size();
      } else {
        return b_.size();
      }
    }
    size_t rank(void) const {
      return dims().size();
    }
    Dimensions dims(void) const {
      if constexpr(D1>=D2) {
        return a_.dims();
      } else {
        return b_.dims();
      }
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      if constexpr(D1>=D2) {
        return D1;
      } else {
        return D2;
      }
    }
    size_t element_size(void) const {
      if constexpr(D1>=D2) {
        return a_.element_size();
      } else {
        return b_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr(D1>=D2) {
        return a_.el_total_size();
      } else {
        return b_.el_total_size();
      }
    }
    size_t total_size(void) const {
      if constexpr(D1>=D2) {
        return a_.total_size();
      } else {
        return b_.total_size();
      }
    }

    std::string classname() const {
      return "ExpressionR_Binary";
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
  // ExpressionR_Ternary    ternary operator expressions
  //               note that there is no easy way to define the first template
  //               of ExpressionR<> below so use NT1
  //---------------------------------------------------------------------------
  template<class A, class B, class C, class NT1, class NT2, class NT3, class OP, int D1, int D2, int D3>
    class ExpressionR_Ternary : public  ExpressionR<typename ResultType<NT1,NT2,typename OP::Type>::Type,ExpressionR_Ternary<A,B,C,NT1,NT2,NT3,OP,D1,D2,D3> > {
  public:
    typedef typename std::conditional<D1==0,const A,const A&>::type TypeA;
    typedef typename std::conditional<D2==0,const B,const B&>::type TypeB;
    typedef typename std::conditional<D3==0,const C,const C&>::type TypeC;

    
  private:
    TypeA a_;
    TypeB b_;
    TypeC c_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberTrait<NT1>::Type NumType1;
    typedef typename NumberTrait<NT2>::Type NumType2;
    typedef typename NumberTrait<NT3>::Type NumType3;
    typedef typename OP::Type NumTypeOut;
    

  ExpressionR_Ternary(TypeA a, TypeB b, TypeC c)
    : a_(a), b_(b), c_(c) {
      vptrs = new VectorofPtrs();
    }

    ~ExpressionR_Ternary() {
      delete vptrs;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    // TODO: below assumes c_ is a scalar. add other cases as needed
    
    const NumTypeOut dat(const size_t i) const {
      if constexpr((D1==0)&&(D2==0)) {
	  return OP::apply(a_, b_, c_);
      } else if constexpr((D1==0)&&(D2>0)) {
	  return OP::apply(a_, b_.dat(i), c_);
      } else if constexpr((D1>0)&&(D2==0)) {
	  return OP::apply(a_.dat(i), b_, c_);
      } else {
	if constexpr(D1==D2) {
	    return OP::apply(a_.dat(i), b_.dat(i), c_);
	} else if constexpr(D1==D2+1) {
	  size_t j = i % b_.total_size();
	  return OP::apply(a_.dat(i), b_.dat(j), c_);
	} else if constexpr(D2==D1+1) {
	  size_t j = i % a_.total_size();
	  return OP::apply(a_.dat(j), b_.dat(i), c_);
	}
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    // TODO: below assumes c_ is a scalar. add other cases as needed

    const NumTypeOut operator[](const size_t i) const {
      if constexpr((D1==0)&&(D2==0)) {
	  return OP::apply(a_, b_, c_);
      } else if constexpr((D1==0)&&(D2==1)) {
	  return OP::apply(a_, b_[i], c_);
      } else if constexpr((D1==1)&&(D2==0)) {
	  return OP::apply(a_[i], b_, c_);
      } else {
	if constexpr((D1==1)&&(D2==1)) {
	    return OP::apply(a_[i], b_[i], c_);
	} 
      }
    }

  
    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    // TODO: below assumes c_ is a scalar. add other cases as needed

    size_t size(void) const {
      if constexpr(D1>=D2) {
        return a_.size();
      } else {
        return b_.size();
      }
    }
    size_t rank(void) const {
      if constexpr(D1>=D2) {
        return a_.rank();
      } else {
        return b_.rank();
      }
    }
    Dimensions dims(void) const {
      if constexpr(D1>=D2) {
        return a_.dims();
      } else {
        return b_.dims();
      }
    }
    bool isExpression(void) const {
      return true;
    }
    size_t depth(void) const {
      if constexpr(D1>=D2) {
        return D1;
      } else {
        return D2;
      }
    }
    size_t element_size(void) const {
      if constexpr(D1>=D2) {
        return a_.element_size();
      } else {
        return b_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr(D1>=D2) {
        return a_.el_total_size();
      } else {
        return b_.el_total_size();
      }
    }
    size_t total_size(void) const {
      if constexpr(D1>=D2) {
        return a_.total_size();
      } else {
        return b_.total_size();
      }
    }

    std::string classname() const {
      return "ExpressionR_Ternary";
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
  // ExpressionRW_Subset   Subset Expression
  //---------------------------------------------------------------------------
  template<typename Number, int depth>
    class ExpressionRW_Subset :  public  ExpressionRW<Number,ExpressionRW_Subset<Number,depth> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<Number>& a_;
    const Vector<size_t>& ii_;
    const bool delete_ii_;
    VectorofPtrs *vptrs;
  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;

  ExpressionRW_Subset(Vector<Number>& a, const Vector<size_t>& ii)
    : a_(a), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
  }
  ExpressionRW_Subset(Vector<Number>& a, const std::initializer_list<size_t>& list)
    : a_(a), ii_(*(new Vector<size_t>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
  }
    
    ~ExpressionRW_Subset() {
      if (delete_ii_) delete &ii_;
      delete vptrs;
    }


    const MyNumberType dat(const size_t i) const {
      size_t ind = ii_[i];
      if (ind < 0) {
	ind = a_.total_size() + ind;
      }
      return a_.dat(ind);
    }
    MyNumberType& dat(const size_t i)  {
      size_t ind = ii_[i];
      if (ind < 0) {
	ind = a_.total_size() + ind;
      }
      return a_.dat(ind);
    }
  
    const Number operator[](const size_t i) const {
      size_t ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }
    Number& operator[](const size_t i)  {
      size_t ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }

    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return ii_.size();
    }
    size_t rank(void) const {
      return a_.rank();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
      }
    }
    std::string classname() const {
      return "ExpressionRW_Subset";
    }


    template <class NT2, class B>
      ExpressionRW_Subset<Number>& operator=(const ExpressionR<NT2,B>& rhs) { 
      return this->equals(rhs);
    }
    
    ExpressionRW_Subset<Number>& operator=(const MyNumberType d) { 
      return this->equals(d);
    }
    
   
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_ExpressionRW_Subset(a_.expression(),ii_.expression());
    }
#endif



  };








  


  //---------------------------------------------------------------------------
  // ExpressionRW_Submask   subset of a tensor from a mask
  //---------------------------------------------------------------------------
  template<typename Number, int depth>
    class ExpressionRW_Submask :  public  ExpressionRW<Number,ExpressionRW_Submask<Number,depth> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<Number>& a_;
    const Vector<size_t>* ii_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;


  ExpressionRW_Submask(Vector<Number>& a, const Vector<bool>& mask)
    : a_(a), ii_(new Vector<size_t>(findtrue(mask))) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }


    ~ExpressionRW_Submask(){ 
      delete  ii_;
      delete vptrs;
    }

    const Number operator[](const size_t i) const{
      size_t ind = (*ii_)[i];
      return a_[ind];
    }
     Number& operator[](const size_t i) {
      size_t ind = (*ii_)[i];
      return a_[ind];
    }
     const MyNumberType dat(const size_t i) const {
       size_t ind = (*ii_)[i];
       return a_.dat(ind);
     }
     MyNumberType& dat(const size_t i)  {
       size_t ind = (*ii_)[i];
       return a_.dat(ind);
     }
  

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return ii_->size();
    }
    size_t rank(void) const {
      return a_.rank();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
      }
    }
    std::string classname() const {
      return "ExpressionRW_Submask";
    }



    template <class NT2, class B>
      ExpressionRW_Submask<Number>& operator=(const ExpressionR<NT2,B>& rhs) { 
      return this->equals(rhs);
    }
    
    ExpressionRW_Submask<Number>& operator=(const MyNumberType d) { 
      return this->equals(d);
    }
    

    
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_ExpressionRW_Submask(a_.expression(),ii_->expression());
    }
#endif 



  };








  //---------------------------------------------------------------------------
  // ExpressionRW_RealFromComplex  used for accessing real/imag part of complex vector
  //---------------------------------------------------------------------------
  template <typename Number, class OP, int depth>
    class ExpressionRW_RealFromComplex : public  ExpressionRW<Number,ExpressionRW_RealFromComplex<Number,OP,depth> > {
  private:
    Vector<std::complex<Number> >& a_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;


  ExpressionRW_RealFromComplex(Vector<std::complex<Number> >& a)
    :   a_(a) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~ExpressionRW_RealFromComplex() {
      delete vptrs;
    }

    const Number operator[](size_t i) const{
      return OP::give(a_[i]);
    }
    Number& operator[](size_t i) {
      return OP::give(a_[i]);
    }
    const MyNumberType dat(const size_t i) const {
      return OP::give(a_.dat(i));
    }
    MyNumberType& dat(const size_t i)  {
      return OP::give(a_.dat(i));
    }



    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return a_.size();
    }
    size_t rank(void) const {
      return a_.rank();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
      }
    }
    std::string classname() const {
      return "ExpressionRW_RealFromComplex";
    }


    template <class NT2, class B>
      ExpressionRW_RealFromComplex<Number,OP,depth>& operator=(const ExpressionR<NT2,B>& rhs) { 
      return this->equals(rhs);
    }
    
    ExpressionRW_RealFromComplex<Number,OP,depth>& operator=(const MyNumberType d) { 
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
  // ExpressionR_Series    used for Taylor and Maclaurin series
  //---------------------------------------------------------------------------

  template<typename Number, class A, class X, int depth>
    class ExpressionR_Series : public  ExpressionR<Number,ExpressionR_Series<Number,A,X,depth> > {

  private:
    const A& a_;
    const X& x_;
    const int N_;
    const Number x0_;
    VectorofPtrs *vptrs;
    
  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;


  ExpressionR_Series(const A& a, const X& x, const int N, const Number x0)
    : a_(a), x_(x), N_(N), x0_(x0) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }
  ExpressionR_Series(const A& a, const X& x, const int N)
    : a_(a), x_(x), N_(N), x0_(0) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }

    ~ExpressionR_Series() {
      delete vptrs;
    }

    const Number operator[](const size_t i) const {
      const Number x = x_[i] - x0_;
      Number sum = 0;
      // TODO: check a_.size >= N
      Number xpow = 1;
      for (int n = 0; n <= N_ ; n++) {
	Number an = a_[n];
	if (an!=Number(0)) {
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
    size_t size(void) const {
      return x_.size();
      // TODO: check a_.size >= N
    }

    size_t rank(void) const {
      return a_.rank();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
      }
    }
    std::string classname() const {
      return "ExpressionR_Series";
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
  // ExpressionR_Series2    used for fourier series
  //---------------------------------------------------------------------------
  
  template<typename Number, class A, class B, class X, class OP1, class OP2, int depth>
    class ExpressionR_Series2 : public  ExpressionR<Number,ExpressionR_Series2< Number, A, B, X, OP1, OP2> > {

  private:
    const A& a_;
    const B& b_;
    const X& x_;
    const int N_;
    const Number k1_;
    Vector<Number>& k_;
    bool initialized;
    VectorofPtrs *vptrs;
    
  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;


  ExpressionR_Series2(const A& a, const A& b, const X& x, const int N, const Number k1)
    : a_(a), b_(b), x_(x), N_(N), k1_(k1), k_(*(new Vector<Number>(N))) {
      
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      vptrs->add(x_.getAddresses());
      vptrs->add(k_.getAddresses());
      
      for (int n = 0; n < N_ ; n++) {
	k_[n] = n*k1_;
      }
    }
    ~ExpressionR_Series2(){
      delete &k_;
      delete vptrs;
    }

    const Number operator[](const size_t i) const {
      Number sum = 0;
      // TODO: check a_.size >= N
      for (int n = 0; n < N_ ; n++) {
	Number kx = k_[n]*x_[i];
	Number an = a_[n];
	if (an != Number(0)) {
	  sum += an*OP1::apply(kx);
	}
	Number bn = b_[n];
	if (bn != Number(0)) {
	  sum += bn*OP2::apply(kx);
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
      return x_.rank();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
      }
    }
    std::string classname() const {
      return "ExpressionR_Series2";
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
  // ExpressionRW_Transpose   tensor transpose, ie reverse the order of indices (RHS only)
  //-----------------------------------------------------------------------------

  template<typename Number, class A, class FUNC, int depth>
    class ExpressionRW_Transpose  : public  ExpressionRW<Number,ExpressionRW_Transpose<Number,A,FUNC,depth> > {
  
  private:
    A& a_;
    VectorofPtrs *vptrs;
    Dimensions *rdims;
  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;



  ExpressionRW_Transpose(A& a) : a_(a) {
      rdims = &(a_.dims().getReverse());
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }
    
    ~ExpressionRW_Transpose() {
      delete rdims;
      delete vptrs;
    }

    const Number operator[](const size_t index1) const {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const size_t index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
    }
    Number& operator[](const size_t index1) {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const size_t index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
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
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
      }
    }
    std::string classname() const {
      return "ExpressionRW_Transpose";
    }

    template <class NT2, class B>
      ExpressionRW_Submask<Number>& operator=(const ExpressionR<NT2,B>& rhs) { 
      return this->equals(rhs);
    }
    
    ExpressionRW_Submask<Number>& operator=(const MyNumberType d) { 
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
  // ExpressionR_Transpose   tensor transpose, ie reverse the order of indices (RHS only)
  //-----------------------------------------------------------------------------

  template<typename Number, class A, class FUNC, int depth>
    class ExpressionR_Transpose  : public  ExpressionR<Number,ExpressionR_Transpose<Number,A,FUNC,depth> > {
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
    Dimensions *rdims;
  
  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;



  ExpressionR_Transpose(const A& a) : a_(a) {
      rdims = &(a_.dims().getReverse());
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }
    
    ~ExpressionR_Transpose() {
      delete rdims;
      delete vptrs;
    }

    const Number operator[](const size_t index1) const {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const size_t index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
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
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
      }
    }
    std::string classname() const {
      return "ExpressionR_Transpose";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };



  //---------------------------------------------------------------------------
  // VER_Join   joining two MultiArrays (RHS only)
  //---------------------------------------------------------------------------

  template<typename Number, class A, class B, int depth>
    class VER_Join : public  ExpressionR<Number,VER_Join<Number,A,B,depth> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;


  VER_Join(const A& a, const B& b)
    : a_(a), b_(b) { 

      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      
    }

    ~VER_Join() {
      delete vptrs;
    }
    
    const Number operator[](const size_t i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
  
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return a_.size() +b_.size();
    }
    size_t rank(void) const {
      return a_.rank();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
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


  template<typename Number, class A, class B, int depth>
    class VERW_Join : public  ExpressionRW<Number,VERW_Join<Number,A,B,depth> > {

  private:
    A& a_;
    B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;


  VERW_Join(A& a, B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
    }

    ~VERW_Join() {
      delete vptrs;
    }


    const Number operator[](const size_t i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
     Number& operator[](const size_t i) {
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return a_.size() +b_.size();
    }
    size_t rank(void) const {
      return a_.rank();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
      }
    }
    std::string classname() const {
      return "VERW_Join";
    }

    VERW_Join<Number,A,B>& operator=(ExpressionRW_Resize<Number>& b) { 
      return this->equals(b);
    }

    template <class C>
      VERW_Join<Number,A,B>& operator=(const ExpressionR<Number,C>& rhs) { 
      PRINTF2("VERW_Join<Number,A,B>& operator=(const ExpressionR<Number,C>& rhs)\n");
      return this->equals(rhs);
    }


    template <class NT2, class C>
      VERW_Join<Number,A,B>& operator=(const ExpressionR<NT2,C>& rhs) { 
      return this->equals(rhs);
    }
    
    VERW_Join<Number,A,B>& operator=(const MyNumberType d) { 
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

  template<typename Number, class A, int depth>
    class VER_Rep : public  ExpressionR<Number,VER_Rep<Number,A,depth> > {

  private:
    const A& a_;
    const size_t m_;
    const size_t N_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberTrait<Number>::Type MyNumberType;


  VER_Rep(const A& a, const size_t m)
    : a_(a), m_(m), N_(a_.size()) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }


    ~VER_Rep() {
      delete vptrs;
    }


    const Number operator[](const size_t i) const{
      size_t index = size_t(i % N_);
      //      PRINTF3("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
      return a_[index];
    }


    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_t size(void) const {
      return m_*a_.size();
    }
    size_t rank(void) const {
      return a_.rank();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_t depth(void) const {
      return depth;
    }
  size_t element_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.element_size();
    }
  }
  size_t el_total_size(void) const {
    if constexpr(depth<2) {
      return 1;
    } else {
      return a_.el_total_size();
    }
  }
    size_t total_size(void) const {
      if constexpr(depth<2) {
	  return this->size();
	} else {
	return (this->size())*(this->el_total_size());
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
