#ifndef MATHQ__VECTOR_H
#define MATHQ__VECTOR_H 1




namespace mathq {

 
 
  
  /****************************************************************************
   * Vector -- mathematical vector class.
   ****************************************************************************   
   */

  template <class D> class Vector :
    public TensorRW<D,Vector<D> > {
  private:

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    //**********************************************************************
    
    std::valarray<D>* data_;


  public:     
    typedef D DataType;
    typedef typename FundamentalType<D>::Type PrimDataType;



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // -------------------  DEFAULT  CONSTRUCTOR: Vector()  --------------------
    explicit Vector<D>() {
      data_ = new std::valarray<D>(0); 
      constructorHelper();
    }


    // --------------------- Vector(N)  ---------------------

    explicit Vector<D>(const size_type N) { 
      data_ = new std::valarray<D>(N);
      constructorHelper();
    }


    // --------------------- Vector(N,value)  ---------------------

    explicit Vector<D>(const size_type N, const D val) {
      data_ = new std::valarray<D>(val, N); 
      constructorHelper();
    }


    // --------------------- array[]  CONSTRUCTOR ---------------------
    Vector<D>(const size_type N, const D (vals)[]) {
      // allocate store
	data_ = new std::valarray<D>(vals, N); 
	constructorHelper();
    }

    // ************* C++11 initializer_list CONSTRUCTOR---------------------
    Vector<D>(std::initializer_list<D> mylist) {
      const size_type N =  mylist.size();
      data_ = new std::valarray<D>(N); 
      *this = mylist;
      constructorHelper();
    }



    // --------------------- Vector(valarray)  ---------------------
     Vector<D>(const std::valarray<D>& valar) {
      data_ = new std::valarray<D>(valar); 
      constructorHelper();
    }


    // --------------------- Vector(Vector) --------------------

    Vector<D>(const Vector<D>& v2) {
      const size_type N = v2.size();
      data_ = new std::valarray<D>(N); 
      *this = v2;
      constructorHelper();
    }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------

    template <class A>
    Vector<D>(const TensorR<D,A>& x) 
    {
      const size_type N = x.size();
      data_ = new std::valarray<D>(N);
      *this = x;
      constructorHelper();
    }




    // --------------------- constructorHelper() --------------------
    
    void constructorHelper() {
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Vector<D>() {
      delete  data_ ;

      //remove from directory
    }
  

    inline size_type size(void) const {
      return data_->size();
    }
    size_type depth(void) const {
      return 1;
    }

    size_type ndims(void) const {
      return 1;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(size());
      return dimensions;
    }
    bool isExpression(void) const {
      return false;
    }
    Tensors getEnum() const {
      return T_VECTOR;
    }
    VectorofPtrs getAddresses(void) const  {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }


    
    //**********************************************************************
    //************************** RESIZE & REHSAPCE ******************************
    //**********************************************************************

    // --------------------- .resize() ---------------------

    // These allow the user to resize a vector


    // *** this is used for resize-by-assignment ***
    TERW_Resize<D>  resize(void) { 
      return  TERW_Resize<D>(*this);
    }

    // this is used to empty the vector of its datastore
    TERW_Resize<D>  resize(void) const {
      this->resize(0);
      return  TERW_Resize<D>(*this);
    }

    // --------------------- .resize(N) ---------------------

    Vector<D>&  resize(const size_type N) { 
      if (N==this->size())
	return *this;
      // reallocate store
      //      delete  data_ ;
      //      data_ = new std::valarray<D>(N);
      data_->resize(N);
      return *this;
    }

    // -------------------------- .reshape(nr,nc) --------------------------------
    // morph into a matrix, pillaging this object of its data store.
    //
    Matrix<D>& reshape(const size_type nr, const size_type nc) { 
      const size_type N = nr*nc;
      // rob the data_
      Matrix<D> m = new Matrix<D>(nr, nc, this->data_);
      this->data_ = new std::valarray<D>(0);
      // return the new Matrix, while we live on at zero size...
      return *m;
    }




    //**********************************************************************
    //************************** ACCSS() ***********************************
    //**********************************************************************

        // -------------------- ELEMENT ACCESS[] --------------------

    // "read/write": unsigned
    D& operator[](const size_type n)  {
      return (*data_)[n]; 
    }

    // "read/write": signed
    D& operator[](const index_type k)  {
      index_type index = k;
      if (k < 0) {
	index += size();
      }
      return (*data_)[index]; 
    }


    // "read only": unsigned
    inline const D operator[](const size_type n) const {
      return (const D)(*data_)[n]; 
    }
    // "read only": signed
    inline const D operator[](const index_type k) const {
      index_type index = k;
      if (k < 0) {
	index += size();
      }
      return (const D)(*data_)[index]; 
    }




    // Accessing a slice of values
    
    TERW_Subset<D> operator[](const slc& slice)  { 
      return (*this)[slice.toIndexVector(size())];
    }
    const TERW_Subset<D>  operator[](const slc& slice) const  {
      //      display::log3("Vector","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexVector(size())];
    }
      
    

    // Accessing a SET of values using a vector of ints

    TERW_Subset<D> operator[](const Vector<index_type>& ii) {
      return TERW_Subset<D>(*this, ii);
    }
    const TERW_Subset<D> operator[](const Vector<index_type>& ii) const {
      return TERW_Subset<D>(*this, ii);
    }



    
    // Accessing a SET of values using a MASK
    
    TERW_Submask<D> operator[](const Vector<bool>& mask)  {
      return  TERW_Submask<D>(*this,mask);
    }
    const TERW_Submask<D> operator[](const Vector<bool>& mask)  const {
      return  TERW_Submask<D>(*this,mask);
    }



    //Accessing a SET of values using a list

    TERW_Subset<D> operator[](const std::initializer_list<index_type>& list) {
      return  TERW_Subset<D>(*this, list);
    }
    const TERW_Subset<D> operator[](const std::initializer_list<index_type>& list) const {
      return  TERW_Subset<D>(*this, list);
    }


    // -------------------- ELEMENT ACCESS --------------------

    // "read/write": unsigned
    D& operator()(const size_type n)  {
      return (*data_)[n]; 
    }

    // "read/write": signed
    D& operator()(const index_type k)  {
      index_type index = k;
      if (k < 0) {
	index += size();
      }
      return (*data_)[index]; 
    }


    // "read only": unsigned
    inline const D operator()(const size_type n) const {
      return (const D)(*data_)[n]; 
    }
    // "read only": signed
    inline const D operator()(const index_type k) const {
      index_type index = k;
      if (k < 0) {
	index += size();
      }
      return (const D)(*data_)[index]; 
    }




    // Accessing a slice of values
    
    TERW_Subset<D> operator()(const slc& slice)  { 
      return (*this)[slice.toIndexVector(size())];
    }
    const TERW_Subset<D>  operator()(const slc& slice) const  {
      //      display::log3("Vector","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexVector(size())];
    }
      
    

    // Accessing a SET of values using a vector of ints

    TERW_Subset<D> operator()(const Vector<index_type>& ii) {
      return TERW_Subset<D>(*this, ii);
    }
    const TERW_Subset<D> operator()(const Vector<index_type>& ii) const {
      return TERW_Subset<D>(*this, ii);
    }



    
    // Accessing a SET of values using a MASK
    
    TERW_Submask<D> operator()(const Vector<bool>& mask)  {
      return  TERW_Submask<D>(*this,mask);
    }
    const TERW_Submask<D> operator()(const Vector<bool>& mask)  const {
      return  TERW_Submask<D>(*this,mask);
    }



    //Accessing a SET of values using a list

    TERW_Subset<D> operator()(const std::initializer_list<index_type>& list) {
      return  TERW_Subset<D>(*this, list);
    }
    const TERW_Subset<D> operator()(const std::initializer_list<index_type>& list) const {
      return  TERW_Subset<D>(*this, list);
    }



    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- getValArray() --------------------
    // "read/write" to the wrapped valarray
    std::valarray<D>& getValArray()  {
      return *data_; 
    }

    // -------------------- setValArray(*valarray) --------------------
    Vector<D>& setValArray(std::valarray<D>* valptr)  {
      delete  data_ ;
      const size_t N = valptr->size();
      data_ = valptr;
      return *this;
    }

    
    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to TensorRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    Vector<D>& equals(const D d) { 
      for(index_type i=size(); i--;) 
	(*data_)[i]=d; 
      return *this;
    }
    Vector<D>& operator=(const D d) { 
      return equals(d);
    }


    // Assignment to a vector expression
    template <class A>  Vector<D>& equals(const TensorR<D,A>& x) {  

      // resize to avoid segmentation faults
      resize(x.size());

      //      MOUT<<std::endl<< "inside normal Vector operator=" <<std::endl;
      if (common(*this,x)){
	//MOUT<< "  common addresses found" <<std::endl;
	Vector<D> vtemp(size());
	for (index_type i = 0; i < size(); i++) 
	  vtemp[i] = x[i];   // Inlined expression
	for (index_type i = 0; i < size(); i++) 
	  (*data_)[i] = vtemp[i];
      } else {
	//MOUT<< "  NO common addresses found" <<std::endl;
	for (index_type i = 0; i < size(); i++) 
	  (*data_)[i] = x[i];   // Inlined expression
      }
      //MOUT<<std::endl<< "DONE normal Vector operator=" <<std::endl;  
      return *this; 
    }
    
    template <class A>  Vector<D>& operator=(const TensorR<D,A>& x) {  
      return equals(x);
    }
    


    // doesn't work
    //    template <class A, class B>  Vector<D>& equals(const TensorR<TensorR<D,A>,B>& x) {  
    //    template <class A, class B>  Vector<D>& operator=(TensorR<TensorR<typename FundamentalType<D>::Type,A>,B>& x) {
    //    template <class A, class B>  Vector<D>& operator=(TensorR<TensorR<D,A>,B>) {
    //    template <class A>  Vector<D>& operator=(A& x) {
    //    template <class A, class B>  Vector<D>& operator=(const TensorR<TensorR<typename FundamentalType<D>::Type,A>,B>& x) {
    //    template <class A, class B>  Vector<D>& operator=(const TensorR<TensorR<typename FundamentalType<D>::Type,A>,B> x) {
    //    template <template<class,class> class A, class B, class C>  Vector<D>& operator=(const TensorR<A<D,B>,C>& x) {
    //    template <template<class,class> class A, class B, class C>  Vector<D>& operator=(const TensorR<A<PrimDataType,B>,C>& x) {
   // WORKS
    //    template <class A>  Vector<D>& operator=(A x) {
    //    template <class A>  Vector<D>& operator=(const A x) {
    //    template <class A>  Vector<D>& operator=(const A& x) {
    //    template <class A, class B>  Vector<D>& operator=(const TensorR<A,B> x) {
    //  template <class A, class B>  Vector<D>& operator=(const TensorR<A,B>& x) {
 

    template <class X, class Y>  Vector<D>& operator=(const TensorR<X,Y>& x) {
      MOUT << __FUNCTION__ <<" ";
      //      return *this;
      const Y& y = x.derived();
      DISP(y.classname());
      DISP(y.isExpression());
      CR();
      Vector<double> v(2);
      y[0];  // dies here somewhere
      
      return *this;
            
      //TLDISP(b0);
      for (index_type i = 0; i<size(); i--) {
	//	Object<D> q = y[i];
	//	for (index_type j = 0; j<y[i].size(); j--) {
	//	  MDISP(i,j,q[j]);
	//	}
      }
      return *this; 
    }


    std::string bottom(){
      typename FundamentalType<D>::Type d;
      return display::getTypeName(d);
    }



    // ------------------------ matrix = array[] ----------------

    Vector<D>& equals(const D array[]) {
      for (index_type i = 0; i < size(); i++)  { 
	(*this)[i] = array[i];
      }
      return *this;
    }
    Vector<D>& operator=(const D array[]) {
      return equals(array);
    }




    

    // Copy asignment
    Vector<D>& equals(const Vector<D>& v2) {

      // resize to avoid segmentation faults
      resize(v2.size());

      for(index_type i=size(); i--;)
	(*data_)[i] = v2[i];    
      return *this;
    }



    Vector<D>& operator=(const Vector<D>& v2) {
      return equals(v2);
    }
    template <class B>
    Vector<D>& operator=(const TERW_Resize<D>& b) { 
      return *this;
    }


    Vector<D>& equals(const std::list<D>& mylist) {
      // resize to avoid segmentation faults
      resize(mylist.size());
      index_type i = 0;
      for (typename std::list<D>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[i++] = *it;
      }
      return *this;
    }
    Vector<D>& operator=(const std::list<D>& mylist) {
      return equals(mylist);
    }

    
    // assignment to a C++11 list
    Vector<D>& equals(const std::initializer_list<D>& mylist) {
      // resize to avoid segmentation faults
      resize(mylist.size());

      size_type k = 0;
      typename std::initializer_list<D>::iterator it; 
      for (it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[k++] = *it;
      }

      return *this;
    }
    Vector<D>& operator=(const std::initializer_list<D>& mylist) {
      return equals(mylist);
    }




    // assignment to a std::vector
    Vector<D>& equals(const std::vector<D>& vstd) {
      

      // resize to avoid segmentation faults
      resize(vstd.size());

      for(size_type i=size(); i--;)
	(*data_)[i] = vstd[i];    

      return *this;
    }


    Vector<D>& operator=(const std::vector<D>& vstd) {
      return equals(vstd);
    }



    // assignment to a std::array
    template <std::size_t N>
    Vector<D>& equals(const std::array<D,N>& varray) {
      

      // resize to avoid segmentation faults
      resize(N);

      for(size_type i=size(); i--;)
	(*data_)[i] = varray[i];    

      return *this;
    }


    template <std::size_t N>
    Vector<D>& operator=(const std::array<D,N>& varray) {
      return equals(varray);
    }



    // assignment to a std::val_array
    Vector<D>& equals(const std::valarray<D>& varray) {
      

      // resize to avoid segmentation faults
      resize(varray.size());

      for(size_type i=size(); i--;)
	(*data_)[i] = varray[i];    

      return *this;
    }

    Vector<D>& operator=(const std::valarray<D>& varray) {
      return equals(varray);
    }




    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************


    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place
    
    Vector<D>&  roundzero(D tolerance = MatricksHelper<D>::tolerance) { 
      for(index_type i=size(); i--;) {
	(*data_)[i] = mathq::roundzero((*data_)[i], tolerance);
      }
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T=D >
      typename std::enable_if<is_complex<T>{}, Vector<T>& >::type conj() {
      using std::conj;
      for(index_type i=size(); i--;) {
	(*data_)[i] = conj((*data_)[i]);
      }
      return *this;
    }



    //**********************************************************************
    //***************** in-place modification********************************
    //**********************************************************************

    // .sort()
    //         sorts in place and returns the permuted indices

    Vector<index_type>& sort() {

      const size_type N = size();
      Vector<index_type> &ivec = *(new Vector<index_type>(N));

      if (N==0)
	return ivec;
    
      std::vector<Pair<D> > temp(N);

      for (index_type i = 0; i < N ; i++ ) {
	temp[i].index = i;
	temp[i].data = (*data_)[i];
      }
    
    
      std::sort(temp.begin(),temp.end());
    
    
      for (index_type i = 0; i < N ; i++ ) {
	ivec[i] = temp[i].index;
	(*data_)[i] = temp[i].data;
      }
    
      return ivec;

    }


    // .quniq()
    //         removes adjacent duplicates

    Vector<index_type>& quniq() {

      const size_type N = size();

      if (N==0)
	return *(new Vector<index_type>(0));
    
      std::queue<Pair<D> > unique;
	
      Pair<D> prevpair(0, (*data_)[0]);
      unique.push(prevpair);
      for (index_type i = 1; i < N ; i++ ) {
	Pair<D> mypair(i, (*data_)[i]);
	if (mypair.data != prevpair.data) {
	  unique.push(mypair);
	  prevpair = mypair;
	} 
      }

      const size_type Nnew = unique.size();
      Vector<index_type> &indexvec = *(new Vector<index_type>(Nnew));
      resize(Nnew);
      for (index_type i = 0; i < Nnew ; i++ ) {
	Pair<D> mypair = unique.front();
	unique.pop();
	indexvec[i] = mypair.index;
	(*data_)[i] = mypair.data;
      }

      return indexvec;
    }


    // .uniq()
    //         removes all duplicates

    Vector<index_type>& uniq() {

      const size_type N = size();

      if (N==0)
	return *(new Vector<index_type>(0));
    
      std::map<index_type,D> mymap;
      for (index_type j = 0; j < N ; j++ ) {
	mymap[j] = (*data_)[j];
      }

      for (index_type j = 0; j < N ; j++ ) {
	if (mymap.find(j) == mymap.end()) continue;
	Pair<D> pair1(j, (*data_)[j]);
	for (index_type k = j+1; k < N ; k++ ) {
	  if (mymap.find(k) == mymap.end()) continue;
	  Pair<D> pair2(k, (*data_)[k]);
	  if (pair1.data == pair2.data) {
	    mymap.erase(k);
	  } 
	}
      }

      const size_type Nnew = mymap.size();
      Vector<index_type> &indexvec = *(new Vector<index_type>(Nnew));
      resize(Nnew);
      index_type k = 0;
      for (typename std::map<index_type,D>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
	indexvec[k] = it->first;
	(*data_)[k++] = it->second;
      }

      return indexvec;
    }


    Vector<D>& reverse() {

      const size_type N = size();
      if (N==0)
	return *this;
   
      for (index_type i = 0; i < N/2 ; i++ ) {
	D temp = (*data_)[i];
	(*data_)[i] = (*data_)[N-i-1];
	(*data_)[N-i-1] = temp;
      }
      
      return *this;
      
    }


    // .cumsum() -- cumulative sum

    Vector<D>& cumsum() {
      const size_type N = size();
      D sum = 0;
      for (index_type i = 0; i < N ; i++ ) {
	sum += (*data_)[i];
	(*data_)[i] = sum;
      }
      return *this;
    }

    // .cumprod()  --  cumulative product

    Vector<D>& cumprod() {
      const size_type N = size();
      D prod = 1;
      for (index_type i = 0; i < N ; i++ ) {
	prod *= (*data_)[i];
	(*data_)[i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation

    Vector<D>& cumtrapz() {
      const size_type N = size();
      if (N==0) return *this;
      D sum = (*data_)[0]/2;
      (*data_)[0] = 0;
      for (index_type i = 1; i < N ; i++ ) {
	sum += (*data_)[i];
	(*data_)[i] = sum - (*data_)[i]/2;
      }
      return *this;
    }

    // integrate_a2x(order)
    // order  name
    //     0  rectangular
    //     1  trapazoidal
    Vector<D>& integrate_a2x(const D a, const D b, const int order=1) {
      std::valarray<D> &mydata = *data_;

      const size_type N = size();

      if (order == 0) {
	this->cumsum();
	const D dx = (b-a)/D(N);
	for (index_type i = 0; i < N ; i++ ) {
	  mydata[i] *= dx;
	}
      } else if (order == 1) {
	this->cumtrapz();
	const D dx = (b-a)/D(N-1);
	for (index_type i = 0; i < N ; i++ ) {
	  mydata[i] *= dx;
	}
      }  else {
	//TODO: issue error
      }
      return *this;
    }


    // .cumsumrev() -- cumulative sum -- from last to first

    Vector<D>& cumsum_rev() {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();

      D sum = 0;
      for (index_type i = 0; i < N ; i++ ) {
	sum += mydata[N-1-i];
	mydata[N-1-i] = sum;
      }
      return *this;
    }

    // .cumprodrev()  --  cumulative product  -- from last to first

    Vector<D>& cumprod_rev() {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();

      D prod = 1;
      for (index_type i = 0; i < N ; i++ ) {
	prod *= mydata[N-1-i];
	mydata[N-1-i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation -- from last to first

    Vector<D>& cumtrapz_rev() {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();
      if (N==0) return *this;

      D sum = mydata[N-1]/2;
      mydata[N-1] = 0;
      for (index_type i = 1; i < N ; i++ ) {
	sum += mydata[N-1-i];
	mydata[N-1-i] = sum - mydata[N-1-i]/2;
      }
      return *this;
    }



    // integrate_x2b
    // order  name
    //     0  rectangular
    //     1  trapazoidal
    Vector<D>& integrate_x2b(const D a, const D b, const int order=1) {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();

      if (order == 0) {
	this->cumsum_rev();
	const D dx = (b-a)/(N);
	for (index_type i = 0; i < N ; i++ ) {
	  mydata[N-1-i] *= dx;
	}
      } else if (order == 1) {
	this->cumtrapz_rev();
	const D dx = (b-a)/(N-1);
	for (index_type i = 0; i < N ; i++ ) {
	  mydata[N-1-i] *= dx;
	}
      }  else {
	//TODO: issue error
      }
      return *this;
    }



    // diff   (v[n] = v[n] - v[n-1])
    Vector<D>& diff(const bool periodic=false) {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();
      if (N<=1) return *this;

      D temp;
      if (periodic) {
	temp = mydata[0] - mydata[N-1];
      } else {
	temp = mydata[1] - mydata[0];
      }

      for (index_type i = 0; i < N-1 ; i++ ) {
	mydata[N-1-i] = mydata[N-1-i] - mydata[N-2-i];
      }

      mydata[0] = temp;
      return *this;
    }

    // diff_rev   (v[n] = v[n+1] - v[n])
    Vector<D>& diff_rev(const bool periodic=false) {
      const size_type N = size();
      std::valarray<D> &mydata = *data_;
      if (N<=1) return *this;

      D temp;
      if (periodic) {
	temp = mydata[0] - mydata[N-1];
      } else {
	temp = mydata[N-1] - mydata[N-2];
      }

      for (index_type i = 0; i < N-1 ; i++ ) {
	mydata[i] = mydata[i+1] - mydata[i];
      }

      mydata[N-1] = temp;
      return *this;
    }


    // deriv -  derivative
    // any change in the default parameters must be likewise made in vfunctions.h: deriv(...)

    Vector<D>& deriv(const D a, const D b, const int n=1, int Dpts=7, const bool periodic=false) {
      std::valarray<D> &dat = *data_;
      //MDISP(a,b,n,Dpts,periodic);
      const size_type N = size();
      if (N<=1) return *this;

      const D dx = (b-a)/D(N-1);

      if (Dpts > N ) {
	//TODO: error or warning
	Dpts = N;
      }

      if (Dpts == 2) {
	this->diff(periodic);
	for (index_type i = 0; i < N ; i++ ) {
	  dat[i] /= dx;
	}
	
      } else if (Dpts == 3) {
	D prev;
	D curr;
	D last;
	if (periodic) {
	  // first point
	  prev = dat[1] - dat[N-1];
	  // last
	  last = dat[0] - dat[N-2];
	} else {
	  // first point
	  prev = -3*dat[0] + 4*dat[1] - dat[2];
	  // last
	  last = 3*dat[N-1] - 4*dat[N-2] + dat[N-3];
	}
	
	const D c0 = 0.5/dx;
	for (index_type i = 1; i < N-1 ; i++ ) {
	  curr = dat[i+1] - dat[i-1];
	  dat[i-1] = c0*prev;
	  prev = curr;
	}
	dat[N-2] = c0*prev;
	dat[N-1] = c0*last;
	
      } else if (Dpts == 5) {
	D prev1;
	D prev2;
	D curr;
	D last;
	D lastminus1;
	if (periodic) {
	  // second to last point
	  lastminus1 = dat[N-4] - 8*dat[N-3] + 8*dat[N-1] - dat[0];
	  // last
	  last       = dat[N-3] - 8*dat[N-2] + 8*dat[0]   - dat[1];
	  // first point
	  prev2      = dat[N-2] - 8*dat[N-1] + 8*dat[1]   - dat[2];
	  // second point
	  prev1      = dat[N-1] - 8*dat[0]   + 8*dat[2]   - dat[3];
	} else {
	  lastminus1 =   -dat[N-5] +  6*dat[N-4] - 18*dat[N-3] + 10*dat[N-2] +  3*dat[N-1];
	  last       =  3*dat[N-5] - 16*dat[N-4] + 36*dat[N-3] - 48*dat[N-2] + 25*dat[N-1];
	  prev2      = -3*dat[4]   + 16*dat[3]   - 36*dat[2]   + 48*dat[1]   - 25*dat[0];
	  prev1      =    dat[4]   -  6*dat[3]   + 18*dat[2]   - 10*dat[1]   -  3*dat[0];
	}
	
	const D c0 = 1/(12*dx);
	for (index_type i = 2; i < N-2 ; i++ ) {
	  curr = dat[i-2] - 8*dat[i-1] + 8*dat[i+1]  - dat[i+2];
	  dat[i-2] = c0*prev2;
	  prev2 = prev1;
	  prev1 = curr;
	}
	dat[N-4] = c0*prev2;
	dat[N-3] = c0*prev1;
	dat[N-2] = c0*lastminus1;
	dat[N-1] = c0*last;
	
      } else if (Dpts == 7) {
	D prev1;
	D prev2;
	D prev3;
	D curr;
	D last;
	D lastminus1;
	D lastminus2;
	if (periodic) {
	  lastminus2 = -dat[N-6] + 9*dat[N-5] - 45*dat[N-4] + 45*dat[N-2]  - 9*dat[N-1] + dat[0];
	  lastminus1 = -dat[N-5] + 9*dat[N-4] - 45*dat[N-3] + 45*dat[N-1]  - 9*dat[0] + dat[1];
	  last  = -dat[N-4] + 9*dat[N-3] - 45*dat[N-2] + 45*dat[0]  - 9*dat[1] + dat[2];
	  prev3 = -dat[N-3] + 9*dat[N-2] - 45*dat[N-1] + 45*dat[1]  - 9*dat[2] + dat[3];
	  prev2 = -dat[N-2] + 9*dat[N-1] - 45*dat[0]   + 45*dat[2]  - 9*dat[3] + dat[4];
	  prev1 = -dat[N-1] + 9*dat[0]   - 45*dat[1]   + 45*dat[3]  - 9*dat[4] + dat[5];
	} else {
	  lastminus2= -(  2*dat[N-1] - 24*dat[N-2] -  35*dat[N-3] +  80*dat[N-4] -  30*dat[N-5] +  8*dat[N-6] -    dat[N-7]);
	  lastminus1= -(-10*dat[N-1] - 77*dat[N-2] + 150*dat[N-3] - 100*dat[N-4] +  50*dat[N-5] - 15*dat[N-6] +  2*dat[N-7]);
	  last =     -(-147*dat[N-1] +360*dat[N-2]- 450*dat[N-3] + 400*dat[N-4] - 225*dat[N-5] + 72*dat[N-6] - 10*dat[N-7]);
	  
	  prev3 = -147*dat[0] + 360*dat[1] - 450*dat[2] + 400*dat[3] - 225*dat[4] + 72*dat[5] - 10*dat[6];
	  prev2 =  -10*dat[0] -  77*dat[1] + 150*dat[2] - 100*dat[3] +  50*dat[4] - 15*dat[5] +  2*dat[6];
	  prev1 =    2*dat[0] -  24*dat[1] -  35*dat[2] +  80*dat[3] -  30*dat[4] +  8*dat[5] -    dat[6];
	}
	const D c0 = 1/(60*dx);
	for (index_type i = 3; i < N-3 ; i++ ) {
	  curr = -dat[i-3] + 9*dat[i-2] - 45*dat[i-1] + 45*dat[i+1]  - 9*dat[i+2] + dat[i+3];
	  dat[i-3] = c0*prev3;
	  prev3 = prev2;
	  prev2 = prev1;
	  prev1 = curr;
	}
	dat[N-6] = c0*prev3;
	dat[N-5] = c0*prev2;
	dat[N-4] = c0*prev1;
	dat[N-3] = c0*lastminus2;
	dat[N-2] = c0*lastminus1;
	dat[N-1] = c0*last;

	
      }  else {
	//TODO: issue error
      }
      if (n>1) {
	return this->deriv(a,b,n-1,Dpts,periodic);
      } 
      return *this;
    }


    
    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      D d;
      return "Vector"+display::getBracketedTypeName(d);
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif




    // stream << operator

    friend std::ostream& operator<<(std::ostream &stream, const Vector<D>& v) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      stream << style.apply(FormatDataVector::string_opening);
      const mathq::index_type N = FormatDataVector::max_elements_per_line;
      mathq::index_type k = 0;
      for (mathq::index_type ii = 0; ii < v.size(); ii++, k++) {
	if (k >= N)  {
	  stream << style.apply(FormatDataVector::string_endofline);
	  k = 0;
	}
	dispval_strm(stream, v[ii]);
	if (ii < v.size()-1)  {
	  stream << style.apply(FormatDataVector::string_delimeter);
	}
      }
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  Vector<D>& x) {	
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream,  Vector<D>& x) {	
      // const size_type LINESZ = 32768;
      // char line[LINESZ];
      // std::vector<D> v;
      // size_type N = 0;
      // const size_type Nold = x.size();
      // D temp;
      // size_type Nlines = 0;
      // std::istringstream strmline;

      // switch (x.textformat()) {
      // case text_braces: 
      // 	{
      // 	  enum States {begin, invec, waitingforcomma, end};
      // 	  States state = begin;

      // 	  while( (state!=end) && stream.getline(line,LINESZ)){
      // 	    Nlines++;
      // 	    strmline.clear();
      // 	    strmline.str(line);
	
      // 	    char c;
      // 	    size_type Nchars=0;
      // 	    while((state!=end) && strmline.get(c) ){
      // 	      Nchars++;
      // 	      if (isspace(c))
      // 		continue;
      // 	      if (c=='%')
      // 		break; // ignore rest of line "%" signifies a comment
	  
      // 	      switch (state) {
      // 	      case begin:
      // 		if  (c=='{')  {
      // 		  state = invec;
      // 		  break;
      // 		}else {
      // 		  std::string extrastr = "Expecting an opening brace.";
      // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
      // 		  return stream;
      // 		}
      // 		break;
      // 	      case invec:
      // 		if  (c=='}') {
      // 		  state = end;
      // 		  break;
      // 		}
      // 		strmline.putback(c);
      // 		if (strmline>>temp){
      // 		  v.push_back(temp);
      // 		  N++;
      // 		  state = waitingforcomma;
      // 		  break;
      // 		}else {
      // 		  std::string extrastr = "Expecting a vector element.";
      // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
      // 		  return stream;
      // 		}
      // 		return stream;
      // 	      case waitingforcomma:
      // 		if  (c=='}') {
      // 		  state = end;
      // 		  break;
      // 		}
      // 		if  (c==',') {
      // 		  state = invec;
      // 		  break;
      // 		}else {
      // 		  std::string extrastr = "Expecting a comma.";
      // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
      // 		  return stream;
      // 		}
      // 		break;
      // 	      case end:
      // 		{
      // 		  std::string extrastr = "Expecting a closing brace.";
      // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
      // 		}
      // 		return stream;
      // 		break;
      // 	      default:
      // 		bug_report(__FILE__,__LINE__);
      // 		return stream;
      // 		break;
      // 	      }
      // 	    }
      // 	  }
      // 	  if (Nold==0) {
      // 	    x.resize(N);
      // 	  } else if (N != Nold) {
      // 	    vbad_input_stream_size(x.name(),line,N,Nold);
      // 	    return stream;
      // 	  }
      // 	}
      // 	break;
      // case text_nobraces: 
      // 	{
      // 	  std::string oldline = line;
      // 	  if (Nold==0) { // read until stream ends
      // 	    while( stream.getline(line,LINESZ) ){
      // 	      Nlines++;
      // 	      strmline.clear();
      // 	      strmline.str(line);
      // 	      char c;
      // 	      size_type Nchars=0;
      // 	      while(strmline.get(c)){
      // 		Nchars++;
      // 		if (isspace(c))
      // 		  continue;
      // 		if (c=='%')
      // 		  break; // ignore rest of line "%" signifies a comment
		
      // 		strmline.putback(c);
      // 		if (strmline>>temp){
      // 		  v.push_back(temp);
      // 		  N++;
      // 		} else { 
      // 		  std::string extrastr ="";
      // 		  if ( (c=='{') || (c=='}')||(c==','))
      // 		    extrastr = "Braces and commas are not allowed in 'text_nobraces' mode";
      // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
      // 		  return stream;
      // 		}
      // 	      }
      // 	    }
      // 	    x.resize(N);
      // 	  } else { // just read in N elements and stop
      // 	    while( (N<Nold) && stream.getline(line,LINESZ) ){
      // 	      Nlines++;
      // 	      strmline.clear();
      // 	      strmline.str(line);
      // 	      char c;
      // 	      size_type Nchars=0;
      // 	      while((N<Nold) && strmline.get(c) ){
      // 		Nchars++;
      // 		std::string stemp = strmline.str();
      // 		if (isspace(c))
      // 		  continue;
      // 		if (c=='%')
      // 		  break; // ignore rest of line "%" signifies a comment
		
      // 		strmline.putback(c);
      // 		if (strmline>>temp){
      // 		  v.push_back(temp);
      // 		  N++;
      // 		} else { 
      // 		  std::string extrastr ="";
      // 		  if ( (c=='{') || (c=='}')||(c==','))
      // 		    extrastr = "Braces and commas are not allowed in 'text_nobraces' mode";
      // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
      // 		  return stream;
      // 		}
      // 	      }
      // 	      oldline = line;
      // 	    }
      // 	    if (N != Nold) {
      // 	      vinput_stream_size_too_small(x.name(),oldline,N,Nold);
      // 	      return stream;
      // 	    }
      // 	  }
      // 	}
      // 	break;
      // default:
      // 	bug_report(__FILE__,__LINE__);
      // 	break;
      // } //switch

      // for(size_type i=0; i<N; i++)
      // 	x[i] = v[i];
      
      // return restore_stream(stream,strmline);
      return stream;
    }

    // --------------------- FRIENDS ---------------------

  

  };




};


#endif 

