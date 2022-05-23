
#ifndef MBOOLEXPR_H
#define MBOOLEXPR_H


#include <string>
#include <sstream>


namespace mathq {







  /****************************************************************************
   * MboolBinOp Operator Expression Template 
   *
   * matrix/matrix binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class MboolBinOp : public  Mexpr<bool,MboolBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;

  public:
    MboolBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
    }
    inline bool operator()(const index_type i) const {
      return OP::apply(a_(i), b_(i));
    }

    inline bool operator()(const index_type r, const index_type c) const {
      return OP::apply(a_(r,c), b_(r,c));
    }

    inline size_type Nrows(void) const {
      if  (a_.Nrows() !=  b_.Nrows() ) {
	return badsize;
      } else {
	return a_.Nrows();
      }
    }

    inline size_type Ncols(void) const {
      if  (a_.Ncols() !=  b_.Ncols() ) {
	return badsize;
      } else {
	return a_.Ncols();
      }
    }


    inline size_type size(void) const {
      if ( (Nrows()==badsize) || (Ncols()==badsize) )
	return badsize;
      else
	return a_.size();
    }


    bool mustcopy(const void *maddr) const {
      return (a_.mustcopy(maddr)) || (b_.mustcopy(maddr));
    }
 
    inline static METypes metype(void)  {
      return ME_MBoolBinOp;
    }

    std::string expression(void) const {
      std::string sa = a_.expression();
      if (a_.metype() != ME_Matrix) 
	sa = "(" + sa + ")";
      std::string sb = b_.expression();
      if (b_.metype() != ME_Matrix) 
	sb = "(" + sb + ")";
      return OP::expression(sa,sb);
    }




  };







  /****************************************************************************
   * BoolMatOpScal Operator Template 
   *
   * matrix/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class BoolMatOpScal : public Mexpr<bool,BoolMatOpScal<D,A,OP> > {

  private:
    const A& a_;
    D val_;

  public:
    BoolMatOpScal(const A& a, const D b)
      : a_(a), val_(b)
    { }

    inline bool operator()(const index_type i) const {
      return OP::apply(a_(i), val_);
    }

    inline bool operator()(const index_type r, const index_type c) const {
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


    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }

    inline METypes metype(void) const {
      return ME_BoolMatOpScal;
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





  };





  /****************************************************************************
   * BoolScalOpMat Operator Template 
   *
   * scalar/matrix binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class BoolScalOpMat : public Mexpr<bool,BoolScalOpMat<D,B,OP> > {

  private:
    D val_;
    const B& b_;

  public:
    BoolScalOpMat(const D a, const B& b)
      :  val_(a), b_(b)
    { }

    inline bool operator()(const index_type i) const {
      return OP::apply(val_, b_(i));
    }

    inline bool operator()(const index_type r, const index_type c) const {
      return OP::apply(val_, b_(r,c));
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


    bool mustcopy(const void *maddr) const {
      return b_.mustcopy(maddr);
    }

    inline METypes metype(void) const {
      return ME_BoolScalOpMat;
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



  };




  /****************************************************************************
   * MboolFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class MboolFuncOp  : public  Mexpr<bool,MboolFuncOp<D,A,FUNC> >{
  
  private:
    const A& a_;
  
  public:
    MboolFuncOp(const A& a) : a_(a) { }

    inline bool operator()(const index_type i) const {
      return FUNC::apply(a_(i));
    }

    inline bool operator()(const index_type r, const index_type c) const {
      return FUNC::apply(a_(r,c));
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
      return ME_MBoolFuncOp;
    }

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }


    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }




  };










};

#endif
