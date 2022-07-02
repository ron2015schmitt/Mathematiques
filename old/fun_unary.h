#ifndef MATHQ__FUN_UNARY_H
#define MATHQ__FUN_UNARY_H 1


  // TODO: convert macros to Python script


namespace mathq {



  // ************************************************************************
  // *              GENERAL UNARY FUNCTOR MACRO
  // ************************************************************************

  
#define FUNCTOR_UNARY(Function,ClassName)			\
  template <class Element, typename Number> class FUNCTOR_##ClassName {		\
  public:								\
    typedef Number NumberType;							\
    typedef Number DoutType;						\
    typedef Element ElementType;							\
    typedef Element EoutType;						\
    static Number apply(const Number d) {					\
      return Function(d);						\
    }									\
    template <class T=Element>						\
      static  typename std::enable_if<!std::is_same<T,Number>::value, Element& >::type \
      apply(const Element& e) {						\
      Element *e2 = new Element();						\
      *e2 = Function(e);						\
      return *e2;							\
    }									\
    static std::string expression(const std::string& sa) {		\
      using namespace display;						\
      std::string sout = "";						\
      sout = functor_style.apply(stringify(Function))+"("+ sa + ")";	\
      return sout;							\
    }									\
    static std::string classname() {					\
      using namespace display;						\
      Element e;								\
      return functor_namestyle.apply(stringify(FUNCTOR_##ClassName))+display::bracketAndStyleTypename(e); \
    }									\
  }
  
  // ************************************************************************
  // *             GENERAL UNARY FUNCTION MACRO
  // ************************************************************************

#define FUNCTION_UNARY(Function,Functor)		\
  template <class X, class Element, typename Number, int depth, int rank>			\
  inline auto Function(const MArrayExpR<X,Element,Number,depth,rank>& x) {		\
    return  TER_Unary<MArrayExpR<X,Element,Number,depth,rank>,Element,Number,depth,rank, Functor<Element,Number> >(x); \
    }



  // ************************************************************************
  // *             UNARY FUNCTOR / FUNCTION DEFINITIONS
  // ************************************************************************

  FUNCTOR_UNARY(!,not);
  FUNCTION_UNARY(operator!,FUNCTOR_not);

  FUNCTOR_UNARY(+,plus);
  FUNCTION_UNARY(operator+,FUNCTOR_plus);

  FUNCTOR_UNARY(-,minus);
  FUNCTION_UNARY(operator-,FUNCTOR_minus);

  FUNCTOR_UNARY(std::sin,sin);
  FUNCTION_UNARY(sin,FUNCTOR_sin);

  FUNCTOR_UNARY(std::cos,cos);
  FUNCTION_UNARY(cos,FUNCTOR_cos);

  FUNCTOR_UNARY(std::tan,tan);
  FUNCTION_UNARY(tan,FUNCTOR_tan);

  
  FUNCTOR_UNARY(std::asin,asin);
  FUNCTION_UNARY(asin,FUNCTOR_asin);

  FUNCTOR_UNARY(std::acos,acos);
  FUNCTION_UNARY(acos,FUNCTOR_acos);

  FUNCTOR_UNARY(std::atan,atan);
  FUNCTION_UNARY(atan,FUNCTOR_atan);

  
  FUNCTOR_UNARY(std::sinh,sinh);
  FUNCTION_UNARY(sinh,FUNCTOR_sinh);

  FUNCTOR_UNARY(std::cosh,cosh);
  FUNCTION_UNARY(cosh,FUNCTOR_cosh);

  FUNCTOR_UNARY(std::tanh,tanh);
  FUNCTION_UNARY(tanh,FUNCTOR_tanh);


  FUNCTOR_UNARY(std::asinh,asinh);
  FUNCTION_UNARY(asinh,FUNCTOR_asinh);

  FUNCTOR_UNARY(std::acosh,acosh);
  FUNCTION_UNARY(acosh,FUNCTOR_acosh);

  FUNCTOR_UNARY(std::atanh,atanh);
  FUNCTION_UNARY(atanh,FUNCTOR_atanh);

  FUNCTOR_UNARY(std::sqrt,sqrt);
  FUNCTION_UNARY(sqrt,FUNCTOR_sqrt);

 
  FUNCTOR_UNARY(std::cbrt,cbrt);
  FUNCTION_UNARY(cbrt,FUNCTOR_cbrt);
  
  FUNCTOR_UNARY(mathq::sqr,sqr);
  FUNCTION_UNARY(sqr,FUNCTOR_sqr);


  FUNCTOR_UNARY(mathq::cube,cube);
  FUNCTION_UNARY(cube,FUNCTOR_cube);


  FUNCTOR_UNARY(std::exp,exp);
  FUNCTION_UNARY(exp,FUNCTOR_exp);

  FUNCTOR_UNARY(std::exp2,exp2);
  FUNCTION_UNARY(exp2,FUNCTOR_exp2);


  FUNCTOR_UNARY(std::expm1,expm1);
  FUNCTION_UNARY(expm1,FUNCTOR_expm1);


  FUNCTOR_UNARY(std::log,log);
  FUNCTION_UNARY(log,FUNCTOR_log);


  FUNCTOR_UNARY(std::log10,log10);
  FUNCTION_UNARY(log10,FUNCTOR_log10);


  FUNCTOR_UNARY(std::log2,log2);
  FUNCTION_UNARY(log2,FUNCTOR_log2);


  FUNCTOR_UNARY(std::log1p,log1p);
  FUNCTION_UNARY(log1p,FUNCTOR_log1p);

  FUNCTOR_UNARY(std::logb,logb);
  FUNCTION_UNARY(logb,FUNCTOR_logb);


  
  FUNCTOR_UNARY(mathq::sgn,sgn);
  FUNCTION_UNARY(sgn,FUNCTOR_sgn);

  
  FUNCTOR_UNARY(std::ceil,ceil);
  FUNCTION_UNARY(ceil,FUNCTOR_ceil);

  
  FUNCTOR_UNARY(std::floor,floor);
  FUNCTION_UNARY(floor,FUNCTOR_floor);

  
  FUNCTOR_UNARY(std::round,round);
  FUNCTION_UNARY(round,FUNCTOR_round);


  FUNCTOR_UNARY(std::trunc,trunc);
  FUNCTION_UNARY(trunc,FUNCTOR_trunc);


  FUNCTOR_UNARY(std::erf,erf);
  FUNCTION_UNARY(erf,FUNCTOR_erf);

 
  FUNCTOR_UNARY(std::erfc,erfc);
  FUNCTION_UNARY(erfc,FUNCTOR_erfc);

  
  FUNCTOR_UNARY(std::tgamma,tgamma);
  FUNCTION_UNARY(tgamma,FUNCTOR_tgamma);

  
  FUNCTOR_UNARY(std::lgamma,lgamma);
  FUNCTION_UNARY(lgamma,FUNCTOR_lgamma);


  FUNCTOR_UNARY(std::expint,expint);
  FUNCTION_UNARY(expint,FUNCTOR_expint);


  FUNCTOR_UNARY(std::riemann_zeta,riemann_zeta);
  FUNCTION_UNARY(riemann_zeta,FUNCTOR_riemann_zeta);


  FUNCTOR_UNARY(std::comp_ellint_1,comp_ellint_1);
  FUNCTION_UNARY(comp_ellint_1,FUNCTOR_comp_ellint_1);


  FUNCTOR_UNARY(std::comp_ellint_2,comp_ellint_2);
  FUNCTION_UNARY(comp_ellint_2,FUNCTOR_comp_ellint_2);


  FUNCTOR_UNARY(mathq::zero,zero);
  FUNCTION_UNARY(zero,FUNCTOR_zero);

  

  // ************************************************************************
  // *              UNARY TYPE 2 FUNCTOR MACRO--DIFFERENT OUTPUT FROM INPUT
  // ************************************************************************

  
#define FUNCTOR_UNARY_TYPE2(Function,ClassName)		\
  template <class Element, class DIN, class DOUT> class FUNCTOR_##ClassName {		\
  public:								\
    typedef DIN NumberType;							\
    typedef DOUT DoutType;						\
    typedef Element ElementType;							\
    typedef typename NumberTrait<Element,DOUT>::ReplacedElementType EoutType;	      \
    static DOUT apply(const DIN d) {					\
      return Function(d);						\
    }									\
    template <class T=Element>						\
      static  typename std::enable_if<!std::is_same<T,DIN>::value, EoutType& >::type \
      apply(const Element& e) {						\
      EoutType *e2 = new EoutType();						\
      *e2 = Function(e);						\
      return *e2;							\
    }									\
    static std::string expression(const std::string& sa) {		\
      using namespace display;						\
      std::string sout = "";						\
      sout = functor_style.apply(stringify(Function))+"("+ sa + ")";	\
      return sout;							\
    }									\
    static std::string classname() {					\
      using namespace display;						\
      Element e;								\
      return functor_namestyle.apply(stringify(FUNCTOR_##ClassName))+display::bracketAndStyleTypename(e); \
    }									\
  }
  
  // ************************************************************************
  // *              UNARY TYPE 2 FUNCTOR MACRO--DIFFERENT OUTPUT FROM INPUT
  // ************************************************************************

#define FUNCTION_UNARY_TYPE2(Function,Functor,DIN,DOUT)			\
  template <class X, class Element, typename Number, int depth, int rank>			\
  inline auto Function(const MArrayExpR<X,Element,DIN,depth,rank>& x) {		\
    typedef typename NumberTrait<Element,DOUT>::ReplacedElementType EOUT;		\
    return  TER_Unary<MArrayExpR<X,Element,DIN,depth,rank>,EOUT,DOUT,depth,rank, Functor<Element,DIN,DOUT>>(x); \
    }
  
  // ************************************************************************
  // *             UNARY TYPE 2 FUNCTOR / FUNCTION DEFINITIONS
  // ************************************************************************
  
  FUNCTOR_UNARY_TYPE2(std::ilogb,ilogb);
  FUNCTION_UNARY_TYPE2(ilogb,FUNCTOR_ilogb,Number,int);

  


  // ************************************************************************
  // *             UNARY COMPLEX FUNCTIONS
  // ************************************************************************


  
  //***************************************************************
  // conj(x)
  //***************************************************************

  // function: conj(x) x=real

  template <class X, class Element, typename Number, int depth, int rank> 
    EnableMethodIf<std::is_arithmetic<Number>::value,const MArrayExpR<X,Element,Number,depth,rank>&>  
    conj(const MArrayExpR<X,Element,Number,depth,rank>& x) {
    return x;
  }


  // function: conj(y) y=imag
  
  template <class X, class Element, typename Number, int depth, int rank> 
  inline const auto conj(const MArrayExpR<X,Element,Imaginary<Number>,depth,rank>& x) {
    return  -x; 
  }
  

  // function: conj(z) z=complex

  FUNCTOR_UNARY(std::conj,conj_complex);

  template <class X, class Element, typename Number, int depth, int rank> 
    inline auto conj(const MArrayExpR<X,Element,std::complex<Number>,depth,rank>& x) {
    typedef std::complex<Number> DIN;
    return  TER_Unary<MArrayExpR<X,Element,DIN,depth,rank>,Element,DIN,depth,rank,FUNCTOR_conj_complex<Element,DIN>>(x); 
  }


  //***************************************************************
  // real(x)
  //***************************************************************

  // function: real(x) x=real
  
  template <class X, class Element, typename Number, int depth, int rank> EnableMethodIf<std::is_arithmetic<Number>::value,const MArrayExpR<X,Element,Number,depth,rank>&>  
    real(const MArrayExpR<X,Element,Number,depth,rank>& x) {
    return x;
  }

    
  // function: real(y) y=Imaginary

  FUNCTOR_UNARY_TYPE2(mathq::real,real_of_Imaginary);
  FUNCTION_UNARY_TYPE2(real,FUNCTOR_real_of_Imaginary, Imaginary<Number>, Number);

  
  // function: real(z) z=complex

  FUNCTOR_UNARY_TYPE2(std::real,real_of_complex);
  FUNCTION_UNARY_TYPE2(real,FUNCTOR_real_of_complex, std::complex<Number>, Number);



  //***************************************************************
  // imag(x)
  //***************************************************************


  // function: imag(x) x=real

  template <class X, class Element, typename Number, int depth, int rank> EnableMethodIf<std::is_arithmetic<Number>::value,TER_Unary<MArrayExpR<X,Element,Number,depth,rank>,Element,Number,depth,rank,FUNCTOR_zero<Element,Number>>>  
    imag(const MArrayExpR<X,Element,Number,depth,rank>& x) {
    return  TER_Unary<MArrayExpR<X,Element,Number,depth,rank>,Element,Number,depth,rank,FUNCTOR_zero<Element,Number>>(x); 
  }


    
  // imag(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::imag,imag_of_Imaginary);
  FUNCTION_UNARY_TYPE2(imag,FUNCTOR_imag_of_Imaginary, Imaginary<Number>, Number);



  // // imag(z) z=complex function

  FUNCTOR_UNARY_TYPE2(std::imag,imag_of_complex);
  FUNCTION_UNARY_TYPE2(imag,FUNCTOR_imag_of_complex, std::complex<Number>, Number);


  //***************************************************************
  // abs(x)
  //***************************************************************

  // function: abs(x) x=real
  
  FUNCTOR_UNARY(std::abs,abs_of_real);

  template <class X, class Element, typename Number, int depth, int rank> EnableMethodIf<std::is_arithmetic<Number>::value, TER_Unary<MArrayExpR<X,Element,Number,depth,rank>,Element,Number,depth,rank,FUNCTOR_abs_of_real<Element,Number>>>  
    abs(const MArrayExpR<X,Element,Number,depth,rank>& x) {
    return  TER_Unary<MArrayExpR<X,Element,Number,depth,rank>,Element,Number,depth,rank,FUNCTOR_abs_of_real<Element,Number>>(x); 
  }


  // function: abs(y) y=imaginary

  FUNCTOR_UNARY_TYPE2(mathq::abs,abs_of_Imaginary);
  FUNCTION_UNARY_TYPE2(abs,FUNCTOR_abs_of_Imaginary, Imaginary<Number>, Number);

    
  // function: abs(z) z=complex

  FUNCTOR_UNARY_TYPE2(std::abs,abs_of_complex);
  FUNCTION_UNARY_TYPE2(abs,FUNCTOR_abs_of_complex, std::complex<Number>, Number);



  //***************************************************************
  // arg(x)
  //***************************************************************

  // function: arg(x) x=real
  
  FUNCTOR_UNARY(std::arg,arg_of_real);

  template <class X, class Element, typename Number, int depth, int rank> EnableMethodIf<std::is_arithmetic<Number>::value, TER_Unary<MArrayExpR<X,Element,Number,depth,rank>,Element,Number,depth,rank,FUNCTOR_arg_of_real<Element,Number>>>  
    arg(const MArrayExpR<X,Element,Number,depth,rank>& x) {
    return  TER_Unary<MArrayExpR<X,Element,Number,depth,rank>,Element,Number,depth,rank,FUNCTOR_arg_of_real<Element,Number>>(x); 
  }


  // function: arg(y) y=imaginary

  FUNCTOR_UNARY_TYPE2(mathq::arg,arg_of_Imaginary);
  FUNCTION_UNARY_TYPE2(arg,FUNCTOR_arg_of_Imaginary, Imaginary<Number>, Number);

    
  // function: arg(z) z=complex

  FUNCTOR_UNARY_TYPE2(std::arg,arg_of_complex);
  FUNCTION_UNARY_TYPE2(arg,FUNCTOR_arg_of_complex, std::complex<Number>, Number);


  //***************************************************************
  // rproj(x)
  //***************************************************************

  // function: rproj(x) x=real

 
  FUNCTOR_UNARY_TYPE2(std::proj,rproj_of_real);

  template <class X, class Element, typename Number, int depth, int rank,EnableIf<std::is_arithmetic<Number>::value> = 0 > auto 
    rproj(const MArrayExpR<X,Element,Number,depth,rank>& x) {
     typedef std::complex<Number> DOUT;
     typedef typename NumberTrait<Element,DOUT>::ReplacedElementType EOUT;
     return  TER_Unary<MArrayExpR<X,Element,Number,depth,rank>,EOUT,DOUT,depth,rank, FUNCTOR_rproj_of_real<Element,Number,DOUT> >(x); 
  }


  // function: rproj(y) y=imaginary

  FUNCTOR_UNARY_TYPE2(mathq::proj,rproj_of_Imaginary);
  FUNCTION_UNARY_TYPE2(rproj,FUNCTOR_rproj_of_Imaginary, Imaginary<Number>, std::complex<Number>);

    
  // function: rproj(z) z=complex

  FUNCTOR_UNARY(std::proj,rproj_of_complex);

  template <class X, class Element, typename Number, int depth, int rank> 
    inline auto rproj(const MArrayExpR<X,Element,std::complex<Number>,depth,rank>& x) {
    typedef std::complex<Number> DIN;
    return  TER_Unary<MArrayExpR<X,Element,DIN,depth,rank>,Element,DIN,depth,rank,FUNCTOR_rproj_of_complex<Element,DIN>>(x); 
  }


  
  //***************************************************************
  // Imaginary<Number> functions
  //***************************************************************

  // exp(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::exp,exp_of_Imaginary);
  FUNCTION_UNARY_TYPE2(exp,FUNCTOR_exp_of_Imaginary, Imaginary<Number>, std::complex<Number>);
  
  // log(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::log,log_of_Imaginary);
  FUNCTION_UNARY_TYPE2(log,FUNCTOR_log_of_Imaginary, Imaginary<Number>, std::complex<Number>);

  // log10(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::log10,log10_of_Imaginary);
  FUNCTION_UNARY_TYPE2(log10,FUNCTOR_log10_of_Imaginary, Imaginary<Number>, std::complex<Number>);

  // sqrt(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::sqrt,sqrt_of_Imaginary);
  FUNCTION_UNARY_TYPE2(sqrt,FUNCTOR_sqrt_of_Imaginary, Imaginary<Number>, std::complex<Number>);

  // sin(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::sin,sin_of_Imaginary);
  FUNCTION_UNARY_TYPE2(sin,FUNCTOR_sin_of_Imaginary, Imaginary<Number>, Imaginary<Number>);

  // cos(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::cos,cos_of_Imaginary);
  FUNCTION_UNARY_TYPE2(cos,FUNCTOR_cos_of_Imaginary, Imaginary<Number>, Number);

  // tan(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::tan,tan_of_Imaginary);
  FUNCTION_UNARY_TYPE2(tan,FUNCTOR_tan_of_Imaginary, Imaginary<Number>, Imaginary<Number>);

  // asin(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::asin,asin_of_Imaginary);
  FUNCTION_UNARY_TYPE2(asin,FUNCTOR_asin_of_Imaginary, Imaginary<Number>, Imaginary<Number>);

  // acos(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::acos,acos_of_Imaginary);
  FUNCTION_UNARY_TYPE2(acos,FUNCTOR_acos_of_Imaginary, Imaginary<Number>, std::complex<Number>);

  // atan(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::atan,atan_of_Imaginary);
  FUNCTION_UNARY_TYPE2(atan,FUNCTOR_atan_of_Imaginary, Imaginary<Number>, std::complex<Number>);

  // sinh(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::sinh,sinh_of_Imaginary);
  FUNCTION_UNARY_TYPE2(sinh,FUNCTOR_sinh_of_Imaginary, Imaginary<Number>, Imaginary<Number>);

  // cosh(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::cosh,cosh_of_Imaginary);
  FUNCTION_UNARY_TYPE2(cosh,FUNCTOR_cosh_of_Imaginary, Imaginary<Number>, Number);

  // tanh(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::tanh,tanh_of_Imaginary);
  FUNCTION_UNARY_TYPE2(tanh,FUNCTOR_tanh_of_Imaginary, Imaginary<Number>, Imaginary<Number>);

  // asinh(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::asinh,asinh_of_Imaginary);
  FUNCTION_UNARY_TYPE2(asinh,FUNCTOR_asinh_of_Imaginary, Imaginary<Number>, std::complex<Number>);

  // acosh(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::acosh,acosh_of_Imaginary);
  FUNCTION_UNARY_TYPE2(acosh,FUNCTOR_acosh_of_Imaginary, Imaginary<Number>, std::complex<Number>);

  // atanh(y) y=Imaginary function

  FUNCTOR_UNARY_TYPE2(mathq::atanh,atanh_of_Imaginary);
  FUNCTION_UNARY_TYPE2(atanh,FUNCTOR_atanh_of_Imaginary, Imaginary<Number>, std::complex<Number>);



};

#endif 
