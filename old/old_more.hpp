#ifndef MATRICKS__MORE_H
#define MATRICKS__MORE_H


namespace mathq {


  /****************************************************************************
   * Matrix Enumerations
   ****************************************************************************   
   */


  enum METypes {ME_Matrix, ME_MSubmatObj,
		ME_MRangeObj, ME_MSetObj, ME_MDualSetObj, ME_MDualRangeObj,
		ME_MSetRangeObj, ME_MRangeSetObj,
		ME_MReconObj, ME_MBinOp, ME_MDotOp,
		ME_MatOpScal, ME_ScalOpMat, 
		ME_MFuncOp, ME_MFuncVec, ME_MFuncReshape,
		ME_MBoolBinOp, ME_BoolMatOpScal, ME_BoolScalOpMat, ME_MBoolFuncOp,
		ME_CMatOpScal, ME_CScalOpMat, ME_MAdjOp};

  enum MTypes {M_Matrix}; 

    /****************************************************************************
   * MorE -- Abstract class that represents either a matrix or a matrix expression
   ****************************************************************************   
   */

  template <class D, class ME> class MorE {
  public:
    inline ME& derived() {
      return static_cast<ME&>(*this);
    }
    inline const  ME& derived() const {
      return static_cast<const ME&>(*this);
    }


    inline const D operator()(const size_t i) const {
      return derived()(i);
    }

    inline const D operator()(const size_t r, const size_t c) const {
      return derived()(r,c);
    }


    inline size_t size(void) const {
      return derived().size();
    }

    inline size_t Nrows(void) const {
      return derived().Nrows();
    }

    inline size_t Ncols(void) const {
      return derived().Ncols();
    }

    std::string expression(void) const {
      return derived().expression();
    }

    inline METypes metype(void) const {
      return derived().metype();
    }

    bool mustcopy(const void* maddr) const {
      return derived().mustcopy(maddr);
    }

    bool addrmatch(const void *maddr) const {
      return derived().addrmatch(maddr);
    }
  };

  template <class A> 
    Vector<size_t> sub2ind(const MorE<size_t,A>& subs, const size_t NR, const size_t NC);



  

  
};


#endif
