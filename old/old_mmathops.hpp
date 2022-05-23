#ifndef MMATHOPS_H
#define MMATHOPS_H


namespace mathq {



  //  ELEMENT-WISE MATHEMATHICAL OPERATIONS
  //  i.e. the operation such as sin is performed independently
  //  on each individual matrix element


 /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */

  // pow_el(matrix,matrix)

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Pow<D> > 
  pow_el(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Pow<D> >(a,b);
  }


  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * D = data type, e.g. double _el(matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */






  // pow_el(matrix,scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Pow<D> > 
  pow_el(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Pow<D> >(a,b);
  }

  // pow_el(scalar,matrix)

  template <class D, class B> 
  inline ScalOpMat<D,MorE<D,B>,Fun_Pow<D> > 
  pow_el( const D a, const MorE<D,B>& b)
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Pow<D> >(a,b);
  }





  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Matrix or a Mexpr
   *****************************************************************
   */



  // sin_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Sin<D> > 
  sin_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Sin<D> >(a);
  }


  // cos_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Cos<D> > 
  cos_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Cos<D> >(a);
  }



  // tan_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Tan<D> > 
  tan_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Tan<D> >(a);
  }
  // sqrt_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Sqrt<D> > 
  sqrt_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Sqrt<D> >(a);
  }
  // sqr_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Sqr<D> > 
  sqr_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Sqr<D> >(a);
  }
  // cube_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Cube<D> > 
  cube_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Cube<D> >(a);
  }
  // exp_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Exp<D> > 
  exp_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Exp<D> >(a);
  }
  // abs(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Abs<D> > 
  abs(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Abs<D> >(a);
  }
  // sgn(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Sgn<D> > 
  sgn(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Sgn<D> >(a);
  }
  // log_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Log<D> > 
  log_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Log<D> >(a);
  }
  // log10_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Log10<D> > 
  log10_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Log10<D> >(a);
  }
  // asin_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Asin<D> > 
  asin_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Asin<D> >(a);
  }

  // acos_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Acos<D> > 
  acos_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Acos<D> >(a);
  }
  // atan_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Atan<D> > 
  atan_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Atan<D> >(a);
  }
  // atan2_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Atan2<D> > 
  atan2_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Atan2<D> >(a);
  }
  // ceil_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Ceil<D> > 
  ceil_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Ceil<D> >(a);
  }
  // floor_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Floor<D> > 
  floor_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Floor<D> >(a);
  }
  // round_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Round<D> > 
  round_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Round<D> >(a);
  }
  // sinh_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Sinh<D> > 
  sinh_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Sinh<D> >(a);
  }
  // cosh_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Cosh<D> > 
  cosh_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Cosh<D> >(a);
  }
  // tanh_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Tanh<D> > 
  tanh_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Tanh<D> >(a);
  }

  

};


#endif 
