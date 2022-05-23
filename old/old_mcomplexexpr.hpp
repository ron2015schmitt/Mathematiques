#ifndef MCOMPLEXEXPR_H
#define MCOMPLEXEXPR_H 1


namespace mathq {








  /****************************************************************************
   * CMatOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class CMatOpScal : public Mexpr<std::complex<D>,CMatOpScal<D,A,OP> > {

  private:
    const A& a_;
    const D& val_;

  public:
    CMatOpScal(const A& a, const D& b)
      : a_(a), val_(b)
    { }

    inline const std::complex<D> operator()(const index_type i) const { 
      return OP::apply(a_(i), val_); 
    }

   inline const std::complex<D> operator()(const index_type r, const index_type c) const {
      return OP::apply(a_(r,c), val_);
    }

    inline size_type Nrows(void) const {
      return a_.Nrows();
    }

    inline size_type Ncols(void) const {
      return a_.Ncols();
    }

    inline size_type size(void) const {
      return a_.size();
    }

    inline METypes metype(void) const {
      return ME_CMatOpScal;
    }

    std::string expression(void) const {
      std::string sa = a_.expression();
      if (a_.metype() != ME_Matrix) 
	sa = "(" + sa + ")";
      std::ostringstream stream;
      stream << val_;
      std::string sb = stream.str();
      return OP::expression(sa,sb);
    }



    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }



  };





  /****************************************************************************
   * CScalOpMat Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */

  
  template<class D, class B, class OP>
  class CScalOpMat : public Mexpr<std::complex<D>,CScalOpMat<D,B,OP> > {

  private:
    const D& val_;
    const B& b_;

  public:
    CScalOpMat(const D& a, const B& b)
      :  val_(a), b_(b)
    { }

    inline const std::complex<D> operator()(const index_type i) const { 
      return OP::apply(val_,b_(i)); 
    }

   inline const std::complex<D> operator()(const index_type r, const index_type c) const {
      return OP::apply(val_,b_(r,c));
    }

   inline size_type Nrows(void) const {
      return b_.Nrows();
    }

    inline size_type Ncols(void) const {
      return b_.Ncols();
    }


    inline size_type size(void) const {
      return b_.size();
    }

    inline METypes metype(void) const {
      return ME_CScalOpMat;
    }

    std::string expression(void) const {
      std::ostringstream stream;
      stream << val_;
      std::string sa = stream.str();
      std::string sb = b_.expression();
      if (b_.metype() != ME_Matrix) 
	sb = "(" + sb + ")";
      return OP::expression(sa,sb);
    }



    bool mustcopy(const void *maddr) const {
      return b_.mustcopy(maddr);
    }



  };



};

#endif 
