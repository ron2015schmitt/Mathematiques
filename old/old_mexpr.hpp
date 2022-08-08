#ifndef MVEXPR_H
#define MVEXPR_H 



namespace mathq {

  template <class A> 
  inline Matrix<size_t> findtrue( const MorE<bool,A>& a );

  template <class A> 
  inline Vector<size_t> findtruesi( const MorE<bool,A>& a );


  /****************************************************************************
   * Mexpr -- Matrix Expression template abstract class
   ****************************************************************************
   */
  template<class D, class EXP> 
  class Mexpr : public MorE<D,Mexpr<D,EXP> > {
  private:
    typedef  D DataT;
    inline EXP& derived() {
      return static_cast<EXP&>(*this);
    }
    inline const  EXP& derived() const {
      return static_cast<const EXP&>(*this);
    }

  public:

    inline const D operator()(const size_t i) const {
      return derived()(i);
    }

    inline const D operator()(const size_t r, const size_t c) const {
      return r*Ncols() + c;
    }


    inline size_t Nrows(void) const {
      return derived().Nrows();
    }
    
    inline size_t Ncols(void) const {
      return derived().Ncols();
    }

    inline size_t size(void) const {
      return derived().size();
    }

    inline METypes metype(void) const {
      return derived().metype();
    }


    std::string expression(void) const {
      return derived().expression();
    }



    bool mustcopy(const void* maddr) const {
      return derived().mustcopy(maddr);
    }

    bool addrmatch(const void *maddr) const {
      return derived().addrmatch(maddr);
    }



  };










  /****************************************************************************
   * ExpressionRW Expression Template 
   *
   * abstract class 
   ****************************************************************************
   */
  template <class D, class DERIVED>
  class MWrapperObj : public  Mexpr<D,MWrapperObj<D,DERIVED> > {
  private:
    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

  public:

    inline const D operator()(const size_t i) const {  
      const size_t index = derived().index(i);
      return derived().data(index);
    }

    inline D& operator()(const size_t i) {  
      const size_t index = derived().index(i);
      return derived().data(index);
    }

    inline size_t index(void) const {
      return derived().index();
    }

    inline size_t size(void) const {
      return derived().size();
    }

    inline size_t Nrows(void) const {
      return derived().Nrows();
    }

    inline size_t Ncols(void) const {
      return  derived().Ncols();
    }

    inline size_t asize(void) const {
      return derived().asize();
    }
    inline size_t aID(void) const {
      return derived().aID();
    }

    inline size_t aNrows(void) const {
      return derived().aNrows();
    }

    inline size_t aNcols(void) const {
      return  derived().aNcols();
    }



    inline METypes metype(void) const {
      return derived().metype();
    }


    // Assign to constant value
    DERIVED& equals(const D d) { 
      for(size_t i=0; i<size(); i++) 
	(*this)(i)=d; 
      return derived();
    }

    // assign to recon object (issue error)
    DERIVED& equals(const MReconObj<D>& b) { 
      return derived();
    }


    //assign to vector(expression)
    
    template <class B>
    DERIVED& equals(const ExpressionR<D,B>& rhs) { 
      
      const size_t N =size();


      if ( rhs.addrmatch(derived().addr()) ) {    
	Vector<D> y(N);
	for(register size_t i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(register size_t i=0; i<N; i++) 
	  derived()(i) = y[i]; 
      } else {
	for(register size_t i=0; i<N; i++) 
	  derived()(i) = rhs[i]; 
      }
      return derived();
    }



    // assignment to matrix (expression)
    template <class B>
    DERIVED& equals(const MorE<D,B>& rhs) {

      const size_t N =size();
      const size_t NR = Nrows();
      const size_t NC = Ncols();


      if ( rhs.addrmatch(derived().addr()) ) {    
	Matrix<D> y(NR,NC);

	for(register size_t i=0; i<N; i++) 
	  y(i) = rhs(i); 
	for(register size_t i=0; i<N; i++) 
	  derived()(i) = y(i); 
      } else {
	for(register size_t i=0; i<N; i++) 
	  derived()(i) = rhs(i); 
      }
      return derived();
    }


    std::string expression(void) const {
      return derived().expression();
    }


    bool mustcopy(const void *maddr) const {
      return derived().mustcopy(maddr);
    }

    bool addrmatch(const void *maddr) const {
      return derived().addrmatch(maddr);
    }

    const void *addr(void) const {
      return derived().addr();
    }
    
  };



  /****************************************************************************
   * MSubmatObj Expression Template 
   *
   * wrapper for submatrices
   ****************************************************************************
   */
  template<class D>
  class MSubmatObj : public   MWrapperObj<D,MSubmatObj<D> >{
  private:
    Matrix<D>& a_;
    const size_t a_NC;
    const size_t rstart_;
    const size_t rend_;
    const size_t cstart_;
    const size_t cend_;
    const size_t NR_;
    const size_t NC_;

  public:
    explicit MSubmatObj(Matrix<D>& a, 
	       const size_t rstart, const size_t rend, 
	       const size_t cstart, const size_t cend)
      : a_(a), a_NC(a.Ncols()),
	rstart_(rstart), rend_(rend), 
	cstart_(cstart), cend_(cend),
	NR_(rend_-rstart_+1), NC_(cend_-cstart_+1)
    { 
    }

    inline const D data(size_t i) const{
      return a_(i);
    }
    inline D& data(size_t i) {
      return a_(i);
    }

    inline size_t index(size_t i) const{
      const std::div_t result = std::div(int(i),int(Ncols()));
      const size_t r = static_cast<size_t>(rstart_ + result.quot);
      const size_t c = static_cast<size_t>(cstart_ + result.rem);
      const size_t ind = r*a_NC + c;
      return ind;
    }

    inline size_t Nrows(void) const {
      return NR_;
    }

    inline size_t Ncols(void) const {
      return NC_;
    }

    inline size_t size(void) const {
      return NR_*NC_;
    }

    inline size_t aNrows(void) const {
      return a_.Nrows();
    }
    inline size_t aNcols(void) const {
      return a_.Ncols();
    }
    inline size_t asize(void) const {
      return a_.size();
    }


    inline METypes metype(void) const {
      return ME_MSubmatObj;
    }

    template <class B>
    MSubmatObj<D>& operator=(const B& b) { 
      return equals(b);
    }

    MSubmatObj<D>& operator=(const MSubmatObj<D>& b) { 
      return equals(b);
    }

    std::string expression(void) const {
      return "";
    }

    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) ;
    }


    const void *addr(void) const {
      return &a_;
    }

  };


  /****************************************************************************
   * MRangeObj Expression Template 
   *
   * wrapper for single index matrix ranges  
   ****************************************************************************
   */
 
  template <class D>
  class MRangeObj : public  MWrapperObj<D,MRangeObj<D> > {
  private:
    Matrix<D>& a_;
    const slc& i_;

  public:
    explicit MRangeObj(Matrix<D>& a, const slc& i)
      :  a_(a), i_(i)
    { 
    }

    inline const D data(size_t i) const{
      return a_(i);
    }
    inline D& data(size_t i) {
      return a_(i);
    }

    // TODO: **FIX THIS**
    inline size_t index(size_t i) const{
      return 0;
    }


    inline size_t size(void) const {
      return 0;
      //      return i_.size();      
    }

    inline size_t asize(void) const {
      return a_.size();
    }

    inline size_t Nrows(void) const {
      return size();
    }

    inline size_t Ncols(void) const {
      return  1;
    }
    inline size_t aNrows(void) const {
      return a_.Nrows();
    }
    inline size_t aNcols(void) const {
      return a_.Ncols();
    }


    inline METypes metype(void) const {
      return ME_MRangeObj;
    }


    MRangeObj<D>& operator=(const MRangeObj<D>& b) { 
      return equals(b);
    }

    std::string expression(void) const {
      return "";
    }


    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return maddr==static_cast<const void*>(&a_);
    }

    const void *addr(void) const {
      return &a_;
    }


  };

 



  /****************************************************************************
   * MSetObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */
  template<class D>
  class MSetObj :  public  MWrapperObj<D,MSetObj<D> > {
  private:
    Matrix<D>& a_;
    const Vector<size_t>* iiptr_;
    const Vector<size_t>& ii_;
    const size_t indID_;
    const bool indisvector;
  public:
    explicit MSetObj(Matrix<D>& a, const Vector<size_t>& ii)
      : a_(a), 
	iiptr_(0), 
	ii_(ii),
	indID_(0),
	indisvector(true)
    {
    }
    explicit MSetObj(Matrix<D>& a, const Matrix<bool>& mask)
      : a_(a), 
	iiptr_(new Vector<size_t>(findtruesi(mask))), 
	ii_(*iiptr_),
	indID_(0),
	indisvector(false)
    {
    }
    explicit MSetObj(Matrix<D>& a, const Vector<bool>& mask)
      : a_(a), 
	iiptr_(new Vector<size_t>(findtrue(mask))), 
	ii_(*iiptr_),
	indID_(0),
	indisvector(true)
    {
    }
    explicit MSetObj(Matrix<D>& a, const Matrix<size_t>& subs)
      : a_(a), 
	iiptr_(new Vector<size_t>(sub2ind(subs,a.Ncols()))), 
	ii_(*iiptr_),
	indID_(0),
	indisvector(false)
    {
    }

    ~MSetObj()
    { 
      delete  iiptr_;
    }

    inline const D data(size_t i) const{
      return a_(i);
    }
    inline  D& data(size_t i) {
      return a_(i);
    }

    inline size_t index(size_t i) const{
      const size_t ind = ii_[i];
      return ind;
    }

    inline METypes metype(void) const {
      return ME_MSetObj;
    }

    inline size_t size(void) const {
      return ii_.size();
    }

    inline size_t Nrows(void) const {
      return size();
    }

    inline size_t Ncols(void) const {
      return  1;
    }

    inline size_t aNrows(void) const {
      return a_.Nrows();
    }
    inline size_t aNcols(void) const {
      return a_.Ncols();
    }
    inline size_t asize(void) const {
      return a_.size();
    }
    inline size_t aID(void) const {
      return 0;
    }

    template <class B>
    MSetObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MSetObj<D>& operator=(const MSetObj<D>& b) { 
      return equals(b);
    }


    std::string expression(void) const {
      return "";
    }


    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) ||(maddr==static_cast<const void*>(&ii_)) ;
    }


    const void *addr(void) const {
      return &a_;
    }


  };




  /****************************************************************************
   * MDualSetObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */
  template<class D>
  class MDualSetObj :  public  MWrapperObj<D,MDualSetObj<D> > {
  private:
    Matrix<D>& a_;
    const size_t a_NC;
    const Vector<size_t>* iiptr_;
    const Vector<size_t>& ii_;
    const Vector<size_t>* jjptr_;
    const Vector<size_t>& jj_;

  public:
    explicit MDualSetObj(Matrix<D>& a, const Vector<size_t>& ii,  const Vector<size_t>& jj)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	jjptr_(0), 
	jj_(jj)
    { }
    explicit MDualSetObj(Matrix<D>& a, const Vector<size_t>& ii,  const size_t j)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	jjptr_(new Vector<size_t>(1,j) ), 
	jj_(*jjptr_)
    {     }
    explicit MDualSetObj(Matrix<D>& a, const size_t i, const Vector<size_t>& jj)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(new Vector<size_t>(1,i) ), 
	ii_(*iiptr_),
	jjptr_(0), 
	jj_(jj)
    {     }

    ~MDualSetObj()
    { 
      delete  iiptr_;
      delete  jjptr_;
    }

    inline const D data(size_t i) const{
      return a_(i);
    }
    inline  D& data(size_t i) {
      return a_(i);
    }

    inline size_t index(size_t k) const{
      const std::div_t result = std::div(int(k),int(Ncols()));
      const int i = result.quot;
      const int j = result.rem;
      const size_t r = ii_[i];
      const size_t c = jj_[j];
      const size_t ind =  r*a_NC + c;
      return ind;
    }

    inline METypes metype(void) const {
      return ME_MDualSetObj;
    }

    inline size_t size(void) const {
      return Nrows()*Ncols();
    }
    
    inline size_t Nrows(void) const {
      return ii_.size();
    }
    
    inline size_t Ncols(void) const {
      return jj_.size();
    }

    inline size_t aNrows(void) const {
      return a_.Nrows();
    }
    inline size_t aNcols(void) const {
      return a_.Ncols();
    }
    inline size_t asize(void) const {
      return a_.size();
    }

    template <class B>
    MDualSetObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MDualSetObj<D>& operator=(const MDualSetObj<D>& b) { 
      return equals(b);
    }


    std::string expression(void) const {
      std::string s1,s2;
      if (iiptr_==0) 
	s1= ii_.expression();
      else
	s1= display::num2string(ii_[0]);
      if (jjptr_==0) 
	s2= jj_.expression();
      else
	s2= display::num2string(jj_[0]);
      return "";
    }


    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) 
	|| (maddr==static_cast<const void*>(&ii_)) 
	|| (maddr==static_cast<const void*>(&jj_));
    }


    const void *addr(void) const {
      return &a_;
    }


  };






  /****************************************************************************
   * MDualRangeObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */
  template<class D>
  class MDualRangeObj :  public  MWrapperObj<D,MDualRangeObj<D> > {
  private:
    Matrix<D>& a_;
    const size_t a_NC;
    const slc& i_;
    const slc& j_;

  public:
    explicit MDualRangeObj(Matrix<D>& a, const slc& i,  const slc& j )
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	j_(j)
    { }

    ~MDualRangeObj()
    { 
    }

    inline const D data(size_t i) const{
      return a_(i);
    }
    inline  D& data(size_t i) {
      return a_(i);
    }

    inline size_t index(size_t k) const{
      return 0;
    }

    inline METypes metype(void) const {
      return ME_MDualRangeObj;
    }

    inline size_t size(void) const {
      return Nrows()*Ncols();
    }
    
    inline size_t Nrows(void) const {
      //      return i_.size();
      return 0;
    }
    
    inline size_t Ncols(void) const {
      //      return j_.size();
      return 0;
    }

    inline size_t aNrows(void) const {
      return a_.Nrows();
    }
    inline size_t aNcols(void) const {
      return a_.Ncols();
    }
    inline size_t asize(void) const {
      return a_.size();
    }

    template <class B>
    MDualRangeObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MDualRangeObj<D>& operator=(const MDualRangeObj<D>& b) { 
      return equals(b);
    }

    std::string expression(void) const {
      return "";
    }


    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_));
    }

    const void *addr(void) const {
      return &a_;
    }


  };





  /****************************************************************************
   * MSetRangeObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */

  template<class D>
  class MSetRangeObj :  public  MWrapperObj<D,MSetRangeObj<D> > {
  private:
    Matrix<D>& a_;
    const size_t a_NC;
    const Vector<size_t>* iiptr_;
    const Vector<size_t>& ii_;
    const slc& j_;

  public:
    explicit MSetRangeObj(Matrix<D>& a, const Vector<size_t>& ii, const slc& j )
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	j_(j)
    { }
    explicit MSetRangeObj(Matrix<D>& a, const size_t i, const slc& j)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(new Vector<size_t>(1,i) ), 
	ii_(*iiptr_),
	j_(j)
    { }

    ~MSetRangeObj()
    { 
      delete  iiptr_;
    }

    inline const D data(size_t i) const{
      return a_(i);
    }
    inline  D& data(size_t i) {
      return a_(i);
    }

    inline size_t index(size_t k) const{
      return 0;
    }

    inline METypes metype(void) const {
      return ME_MSetRangeObj;
    }

    inline size_t size(void) const {
      return Nrows()*Ncols();
    }
    
    inline size_t Nrows(void) const {
      //return ii_.size();
      return 0;
    }
    
    inline size_t Ncols(void) const {
      //return j_.size();
      return 0;
    }

    inline size_t aNrows(void) const {
      return a_.Nrows();
    }
    inline size_t aNcols(void) const {
      return a_.Ncols();
    }
    inline size_t asize(void) const {
      return a_.size();
    }

    template <class B>
    MSetRangeObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MSetRangeObj<D>& operator=(const MSetRangeObj<D>& b) { 
      return equals(b);
    }


    std::string expression(void) const {
      std::string s;
      if (iiptr_==0) 
	s= ii_.expression();
      else
	s= display::num2string(ii_[0]);
      return "";
     }


    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) 
	|| (maddr==static_cast<const void*>(&ii_));
    }


    const void *addr(void) const {
      return &a_;
    }


  };





  /****************************************************************************
   * MRangeSetObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */

  template<class D>
  class MRangeSetObj :  public  MWrapperObj<D,MRangeSetObj<D> > {
  private:
    Matrix<D>& a_;
    const size_t a_NC;
    const slc& i_;
    const Vector<size_t>* jjptr_;
    const Vector<size_t>& jj_;

  public:
    explicit MRangeSetObj(Matrix<D>& a, const slc& i, const Vector<size_t>& jj )
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	jjptr_(0), 
	jj_(jj)
    { }
    explicit MRangeSetObj(Matrix<D>& a, const slc& i, const size_t j)
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	jjptr_(new Vector<size_t>(1,j) ), 
	jj_(*jjptr_)
    { }

    ~MRangeSetObj()
    { 
      delete  jjptr_;
    }

    inline const D data(size_t i) const{
      return a_(i);
    }
    inline  D& data(size_t i) {
      return a_(i);
    }

    inline size_t index(size_t k) const{
//       const std::div_t result = std::div(int(k),int(Ncols()));
//       const int i = result.quot;
//       const int j = result.rem;
//       const size_t r = i_[i];
//       const size_t c = jj_[j];
//       const size_t ind =  r*a_NC + c;
//       return ind;
      return 0;
    }

    inline METypes metype(void) const {
      return ME_MRangeSetObj;
    }

    inline size_t size(void) const {
      return Nrows()*Ncols();
    }
    
    inline size_t Nrows(void) const {
      //      return i_.size();
      return 0;
    }
    
    inline size_t Ncols(void) const {
      //      return jj_.size();
      return 0;
    }

    inline size_t aNrows(void) const {
      return a_.Nrows();
    }
    inline size_t aNcols(void) const {
      return a_.Ncols();
    }
    inline size_t asize(void) const {
      return a_.size();
    }

    template <class B>
    MRangeSetObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MRangeSetObj<D>& operator=(const MRangeSetObj<D>& b) { 
      return equals(b);
    }


    std::string expression(void) const {
      std::string s;
      if (jjptr_==0) 
	s= jj_.expression();
      else
	s= display::num2string(jj_[0]);
      return "";
    }


    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) 
	|| (maddr==static_cast<const void*>(&jj_));
    }


    const void *addr(void) const {
      return &a_;
    }


  };








  /****************************************************************************
   * MReconObj Expression Template 
   *
   * reallocate store
   ****************************************************************************
   */
  template<class D>
  class MReconObj :  public  Mexpr<D,MReconObj<D> > {
  private:
    Matrix<D>& a_;

  public:
    explicit MReconObj(Matrix<D>& a)
      : a_(a)
    { 
    }

    inline METypes metype(void) const {
      return ME_MReconObj;
    }

    template <class A>
    Matrix<D>& operator=(const MorE<D,A>& x) { 
      size_t NR = x.Nrows();
      size_t NC = x.Ncols();



      if ( x.addrmatch(&a_)) {    
	Matrix<D> y(NR,NC);
	y = x.derived();
	a_.resize(NR,NC);
	a_ = y;
	return a_;
      } else {
	a_.resize(NR,NC);
	a_ = x.derived();
	return a_;
      }
    }
    

    Matrix<D>& operator=(const MReconObj<D>& b) { 

      return a_;
    }


    std::string expression(void) const {
      return  a_.expression() +".resize()";
    }


    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return maddr==static_cast<const void*>(&a_);
    }


  };




  /****************************************************************************
   * MBinOp Operator Expression Template 
   *
   * matrix/matrix binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class MBinOp : public  Mexpr<D,MBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;

  public:
    explicit MBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
    }

    inline const D operator()(const size_t i) const {
      return OP::apply(a_(i), b_(i));
    }


    inline size_t Nrows(void) const {
      if  (a_.Nrows() !=  b_.Nrows() ) {
	return badsize;
      } else {
	return a_.Nrows();
      }
    }

    inline size_t Ncols(void) const {
      if  (a_.Ncols() !=  b_.Ncols() ) {
	return badsize;
      } else {
	return a_.Ncols();
      }
    }


    inline size_t size(void) const {
      if ( (Nrows()==badsize) || (Ncols()==badsize) )
	return badsize;
      else
	return a_.size();
    }


    bool mustcopy(const void *maddr) const {
      return (a_.mustcopy(maddr)) || (b_.mustcopy(maddr));
    }
 
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr) ||  b_.addrmatch(maddr);
    }

    inline static METypes metype(void)  {
      return ME_MBinOp;
    }

    std::string expression(void) const {
      return "";
    }



  };








  /****************************************************************************
   * MatOpScal Operator Template 
   *
   * matrix/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class MatOpScal : public Mexpr<D,MatOpScal<D,A,OP> > {

  private:
    const A& a_;
    const D val_;

  public:
    explicit MatOpScal(const A& a, const D b)
      : a_(a), val_(b)
    { }

    inline const D operator()(const size_t i) const {
      return OP::apply(a_(i), val_);
    }


    inline size_t Nrows(void) const {
      return a_.Nrows();
    }

    inline size_t Ncols(void) const {
      return a_.Ncols();
    }

    inline size_t size(void) const {
      return a_.size();
    }


    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr);
    }

    inline METypes metype(void) const {
      return ME_MatOpScal;
    }

    std::string expression(void) const {
      std::string s;
      return s;
      std::ostringstream stream;
      stream << val_;
      std::string sb = stream.str();
      std::string sa = expression_paren(a_.expression(),a_.metype());
      return OP::expression(sa,sb);
    }




  };





  /****************************************************************************
   * ScalOpMat Operator Template 
   *
   * scalar/matrix binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class ScalOpMat : public Mexpr<D,ScalOpMat<D,B,OP> > {

  private:
    const D val_;
    const B& b_;

  public:
    explicit ScalOpMat(const D a, const B& b)
      :  val_(a), b_(b)
    { }

    inline const D operator()(const size_t i) const {
      return OP::apply(val_, b_(i));
    }

    inline size_t Nrows(void) const {
      return b_.Nrows();
    }

    inline size_t Ncols(void) const {
      return b_.Ncols();
    }

    inline size_t size(void) const {
      return b_.size();
    }


    bool mustcopy(const void *maddr) const {
      return b_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return b_.addrmatch(maddr);
    }

    inline METypes metype(void) const {
      return ME_ScalOpMat;
    }

    std::string expression(void) const {
      std::ostringstream stream;
      stream << val_;
      std::string sa = stream.str();
      std::string sb = expression_paren(b_.expression(),b_.metype());
      return OP::expression(sa,sb);
    }



  };




  /****************************************************************************
   * MFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class MFuncOp  : public  Mexpr<D,MFuncOp<D,A,FUNC> >{
  
  private:
    const A& a_;
  
  public:
    explicit MFuncOp(const A& a) : a_(a) { }

    inline const D operator()(const size_t i) const {
      return FUNC::apply(a_(i));
    }

    inline size_t Nrows(void) const {
      return a_.Nrows();
    }

    inline size_t Ncols(void) const {
      return a_.Ncols();
    }

    inline size_t size(void) const {
      return a_.size();
    }

    inline METypes metype(void) const {
      return ME_MFuncOp;
    }

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr);
    }


    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }


  };






  /****************************************************************************
   * MFuncVec Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class MFuncVec  : public  Mexpr<D,MFuncVec<D,A,FUNC> >{
  
  private:
    const A& a_;
    const size_t NR_; 
    const size_t NC_;
  public:
    explicit MFuncVec(const A& a, const size_t NR, const size_t NC) : a_(a), NR_(NR), NC_(NC){ }

    inline const D operator()(const size_t i) const {
      return FUNC::apply(a_[i]);
    }

    inline size_t Nrows(void) const {
      return NR_;
    }

    inline size_t Ncols(void) const {
      return NC_;
    }

    inline size_t size(void) const {
      return a_.size();
    }

    inline METypes metype(void) const {
      return ME_MFuncVec;
    }

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr);
    }


    std::string expression(void) const {
      std::string sa =  a_.expression();
      return FUNC::expression(sa);
    }


  };




  /****************************************************************************
   * MFuncReshape Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class MFuncReshape  : public  Mexpr<D,MFuncReshape<D,A,FUNC> >{
  
  private:
    const A& a_;
    const size_t NR_; 
    const size_t NC_;
  
  public:
    explicit MFuncReshape(const A& a, const size_t NR, const size_t NC) : a_(a), NR_(NR), NC_(NC){ }

    inline const D operator()(const size_t i) const {
      return FUNC::apply(a_(i));
    }


    inline size_t Nrows(void) const {
      return NR_;
    }

    inline size_t Ncols(void) const {
      return NC_;
    }

    inline size_t size(void) const {
      return a_.size();
    }


    inline METypes metype(void) const {
      return ME_MFuncReshape;
    }

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr);
    }


    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }


  };




};

#endif
