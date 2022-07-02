#ifndef MATHQ__VECTOR_H
#define MATHQ__VECTOR_H 1




namespace mathq {

 
 
  
  /****************************************************************************
   * Vector -- mathematical vector class.
   ****************************************************************************   
   */

  template <typename Number> class Vector :
    public MArrayExpRW<Number,Vector<Number> > {
  private:

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    //**********************************************************************
    
    std::valarray<Number>* data_;


  public:     
    typedef Number DataType;
    typedef typename SimpleNumberTrait<Number>::Type PrimDataType;



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // -------------------  DEFAULT  CONSTRUCTOR: Vector()  --------------------
    explicit Vector<Number>() {
      data_ = new std::valarray<Number>(0); 
      constructorHelper();
    }


    // --------------------- Vector(N)  ---------------------

    explicit Vector<Number>(const size_t   N) { 
      data_ = new std::valarray<Number>(N);
      constructorHelper();
    }


    // --------------------- Vector(N,value)  ---------------------

    explicit Vector<Number>(const size_t   N, const Number val) {
      data_ = new std::valarray<Number>(val, N); 
      constructorHelper();
    }


    // --------------------- array[]  CONSTRUCTOR ---------------------
    Vector<Number>(const size_t   N, const Number (vals)[]) {
      // allocate store
	data_ = new std::valarray<Number>(vals, N); 
	constructorHelper();
    }

    // ************* C++11 initializer_list CONSTRUCTOR---------------------
    Vector<Number>(std::initializer_list<Number> mylist) {
      const size_t   N =  mylist.size();
      data_ = new std::valarray<Number>(N); 
      *this = mylist;
      constructorHelper();
    }



    // --------------------- Vector(valarray)  ---------------------
     Vector<Number>(const std::valarray<Number>& valar) {
      data_ = new std::valarray<Number>(valar); 
      constructorHelper();
    }


    // --------------------- Vector(Vector) --------------------

    Vector<Number>(const Vector<Number>& v2) {
      const size_t   N = v2.size();
      data_ = new std::valarray<Number>(N); 
      *this = v2;
      constructorHelper();
    }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------

    template <class A>
    Vector<Number>(const MArrayExpR<Number,A>& x) 
    {
      const size_t   N = x.size();
      data_ = new std::valarray<Number>(N);
      *this = x;
      constructorHelper();
    }




    // --------------------- constructorHelper() --------------------
    
    void constructorHelper() {
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Vector<Number>() {
      delete  data_ ;

      //remove from directory
    }
  

    inline size_t   size(void) const {
      return data_->size();
    }
    size_t   depth(void) const {
      return 1;
    }

    size_t   rank(void) const {
      return 1;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(size());
      return dimensions;
    }
    bool isExpression(void) const {
      return false;
    }
    MultiArrays getEnum() const {
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
    TERW_Resize<Number>  resize(void) { 
      return  TERW_Resize<Number>(*this);
    }

    // this is used to empty the vector of its datastore
    TERW_Resize<Number>  resize(void) const {
      this->resize(0);
      return  TERW_Resize<Number>(*this);
    }

    // --------------------- .resize(N) ---------------------

    Vector<Number>&  resize(const size_t   N) { 
      if (N==this->size())
	return *this;
      // reallocate store
      //      delete  data_ ;
      //      data_ = new std::valarray<Number>(N);
      data_->resize(N);
      return *this;
    }

    // -------------------------- .reshape(nr,nc) --------------------------------
    // morph into a matrix, pillaging this object of its data store.
    //
    Matrix<Number>& reshape(const size_t   nr, const size_t   nc) { 
      const size_t   N = nr*nc;
      // rob the data_
      Matrix<Number> m = new Matrix<Number>(nr, nc, this->data_);
      this->data_ = new std::valarray<Number>(0);
      // return the new Matrix, while we live on at zero size...
      return *m;
    }




    //**********************************************************************
    //************************** ACCSS() ***********************************
    //**********************************************************************

        // -------------------- ELEMENT ACCESS[] --------------------

    // "read/write": unsigned
    Number& operator[](const size_t   n)  {
      return (*data_)[n]; 
    }

    // "read/write": signed
    Number& operator[](const size_t   k)  {
      size_t   index = k;
      if (k < 0) {
	index += size();
      }
      return (*data_)[index]; 
    }


    // "read only": unsigned
    inline const Number operator[](const size_t   n) const {
      return (const Number)(*data_)[n]; 
    }
    // "read only": signed
    inline const Number operator[](const size_t   k) const {
      size_t   index = k;
      if (k < 0) {
	index += size();
      }
      return (const Number)(*data_)[index]; 
    }




    // Accessing a slice of values
    
    TERW_Subset<Number> operator[](const slc& slice)  { 
      return (*this)[slice.toIndexVector(size())];
    }
    const TERW_Subset<Number>  operator[](const slc& slice) const  {
      //      display::log3("Vector","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexVector(size())];
    }
      
    

    // Accessing a SET of values using a vector of ints

    TERW_Subset<Number> operator[](const Vector<size_t>& ii) {
      return TERW_Subset<Number>(*this, ii);
    }
    const TERW_Subset<Number> operator[](const Vector<size_t>& ii) const {
      return TERW_Subset<Number>(*this, ii);
    }



    
    // Accessing a SET of values using a MASK
    
    TERW_Submask<Number> operator[](const Vector<bool>& mask)  {
      return  TERW_Submask<Number>(*this,mask);
    }
    const TERW_Submask<Number> operator[](const Vector<bool>& mask)  const {
      return  TERW_Submask<Number>(*this,mask);
    }



    //Accessing a SET of values using a list

    TERW_Subset<Number> operator[](const std::initializer_list<size_t>& list) {
      return  TERW_Subset<Number>(*this, list);
    }
    const TERW_Subset<Number> operator[](const std::initializer_list<size_t>& list) const {
      return  TERW_Subset<Number>(*this, list);
    }


    // -------------------- ELEMENT ACCESS --------------------

    // "read/write": unsigned
    Number& operator()(const size_t   n)  {
      return (*data_)[n]; 
    }

    // "read/write": signed
    Number& operator()(const size_t   k)  {
      size_t   index = k;
      if (k < 0) {
	index += size();
      }
      return (*data_)[index]; 
    }


    // "read only": unsigned
    inline const Number operator()(const size_t   n) const {
      return (const Number)(*data_)[n]; 
    }
    // "read only": signed
    inline const Number operator()(const size_t   k) const {
      size_t   index = k;
      if (k < 0) {
	index += size();
      }
      return (const Number)(*data_)[index]; 
    }




    // Accessing a slice of values
    
    TERW_Subset<Number> operator()(const slc& slice)  { 
      return (*this)[slice.toIndexVector(size())];
    }
    const TERW_Subset<Number>  operator()(const slc& slice) const  {
      //      display::log3("Vector","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexVector(size())];
    }
      
    

    // Accessing a SET of values using a vector of ints

    TERW_Subset<Number> operator()(const Vector<size_t>& ii) {
      return TERW_Subset<Number>(*this, ii);
    }
    const TERW_Subset<Number> operator()(const Vector<size_t>& ii) const {
      return TERW_Subset<Number>(*this, ii);
    }



    
    // Accessing a SET of values using a MASK
    
    TERW_Submask<Number> operator()(const Vector<bool>& mask)  {
      return  TERW_Submask<Number>(*this,mask);
    }
    const TERW_Submask<Number> operator()(const Vector<bool>& mask)  const {
      return  TERW_Submask<Number>(*this,mask);
    }



    //Accessing a SET of values using a list

    TERW_Subset<Number> operator()(const std::initializer_list<size_t>& list) {
      return  TERW_Subset<Number>(*this, list);
    }
    const TERW_Subset<Number> operator()(const std::initializer_list<size_t>& list) const {
      return  TERW_Subset<Number>(*this, list);
    }



    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- getInternalStdArray() --------------------
    // "read/write" to the wrapped valarray
    std::valarray<Number>& getInternalStdArray()  {
      return *data_; 
    }

    // -------------------- setValArray(*valarray) --------------------
    Vector<Number>& setValArray(std::valarray<Number>* valptr)  {
      delete  data_ ;
      const size_t   N = valptr->size();
      data_ = valptr;
      return *this;
    }

    
    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to MArrayExpRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    Vector<Number>& equals(const Number d) { 
      for(size_t i=size(); i--;) 
	(*data_)[i]=d; 
      return *this;
    }
    Vector<Number>& operator=(const Number d) { 
      return equals(d);
    }


    // Assignment to a vector expression
    template <class A>  Vector<Number>& equals(const MArrayExpR<Number,A>& x) {  

      // resize to avoid segmentation faults
      resize(x.size());

      //      MOUT<<std::endl<< "inside normal Vector operator=" <<std::endl;
      if (common(*this,x)){
	//MOUT<< "  common addresses found" <<std::endl;
	Vector<Number> vtemp(size());
	for (size_t i = 0; i < size(); i++) 
	  vtemp[i] = x[i];   // Inlined expression
	for (size_t i = 0; i < size(); i++) 
	  (*data_)[i] = vtemp[i];
      } else {
	//MOUT<< "  NO common addresses found" <<std::endl;
	for (size_t i = 0; i < size(); i++) 
	  (*data_)[i] = x[i];   // Inlined expression
      }
      //MOUT<<std::endl<< "DONE normal Vector operator=" <<std::endl;  
      return *this; 
    }
    
    template <class A>  Vector<Number>& operator=(const MArrayExpR<Number,A>& x) {  
      return equals(x);
    }
    


    // doesn't work
    //    template <class A, class B>  Vector<Number>& equals(const MArrayExpR<MArrayExpR<Number,A>,B>& x) {  
    //    template <class A, class B>  Vector<Number>& operator=(MArrayExpR<MArrayExpR<typename SimpleNumberTrait<Number>::Type,A>,B>& x) {
    //    template <class A, class B>  Vector<Number>& operator=(MArrayExpR<MArrayExpR<Number,A>,B>) {
    //    template <class A>  Vector<Number>& operator=(A& x) {
    //    template <class A, class B>  Vector<Number>& operator=(const MArrayExpR<MArrayExpR<typename SimpleNumberTrait<Number>::Type,A>,B>& x) {
    //    template <class A, class B>  Vector<Number>& operator=(const MArrayExpR<MArrayExpR<typename SimpleNumberTrait<Number>::Type,A>,B> x) {
    //    template <template<class,class> class A, class B, class C>  Vector<Number>& operator=(const MArrayExpR<A<Number,B>,C>& x) {
    //    template <template<class,class> class A, class B, class C>  Vector<Number>& operator=(const MArrayExpR<A<PrimDataType,B>,C>& x) {
   // WORKS
    //    template <class A>  Vector<Number>& operator=(A x) {
    //    template <class A>  Vector<Number>& operator=(const A x) {
    //    template <class A>  Vector<Number>& operator=(const A& x) {
    //    template <class A, class B>  Vector<Number>& operator=(const MArrayExpR<A,B> x) {
    //  template <class A, class B>  Vector<Number>& operator=(const MArrayExpR<A,B>& x) {
 

    template <class X, class Y>  Vector<Number>& operator=(const MArrayExpR<X,Y>& x) {
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
      for (size_t i = 0; i<size(); i--) {
	//	Object<Number> q = y[i];
	//	for (size_t j = 0; j<y[i].size(); j--) {
	//	  MDISP(i,j,q[j]);
	//	}
      }
      return *this; 
    }


    std::string bottom(){
      typename SimpleNumberTrait<Number>::Type d;
      return display::getTypeName(d);
    }



    // ------------------------ matrix = array[] ----------------

    Vector<Number>& equals(const Number array[]) {
      for (size_t i = 0; i < size(); i++)  { 
	(*this)[i] = array[i];
      }
      return *this;
    }
    Vector<Number>& operator=(const Number array[]) {
      return equals(array);
    }




    

    // Copy asignment
    Vector<Number>& equals(const Vector<Number>& v2) {

      // resize to avoid segmentation faults
      resize(v2.size());

      for(size_t i=size(); i--;)
	(*data_)[i] = v2[i];    
      return *this;
    }



    Vector<Number>& operator=(const Vector<Number>& v2) {
      return equals(v2);
    }
    template <class B>
    Vector<Number>& operator=(const TERW_Resize<Number>& b) { 
      return *this;
    }


    Vector<Number>& equals(const std::list<Number>& mylist) {
      // resize to avoid segmentation faults
      resize(mylist.size());
      size_t   i = 0;
      for (typename std::list<Number>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[i++] = *it;
      }
      return *this;
    }
    Vector<Number>& operator=(const std::list<Number>& mylist) {
      return equals(mylist);
    }

    
    // assignment to a C++11 list
    Vector<Number>& equals(const std::initializer_list<Number>& mylist) {
      // resize to avoid segmentation faults
      resize(mylist.size());

      size_t   k = 0;
      typename std::initializer_list<Number>::iterator it; 
      for (it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[k++] = *it;
      }

      return *this;
    }
    Vector<Number>& operator=(const std::initializer_list<Number>& mylist) {
      return equals(mylist);
    }




    // assignment to a std::vector
    Vector<Number>& equals(const std::vector<Number>& vstd) {
      

      // resize to avoid segmentation faults
      resize(vstd.size());

      for(size_t i=size(); i--;)
	(*data_)[i] = vstd[i];    

      return *this;
    }


    Vector<Number>& operator=(const std::vector<Number>& vstd) {
      return equals(vstd);
    }



    // assignment to a std::array
    template <size_t   N>
    Vector<Number>& equals(const std::array<Number,N>& varray) {
      

      // resize to avoid segmentation faults
      resize(N);

      for(size_t i=size(); i--;)
	(*data_)[i] = varray[i];    

      return *this;
    }


    template <size_t   N>
    Vector<Number>& operator=(const std::array<Number,N>& varray) {
      return equals(varray);
    }



    // assignment to a std::val_array
    Vector<Number>& equals(const std::valarray<Number>& varray) {
      

      // resize to avoid segmentation faults
      resize(varray.size());

      for(size_t i=size(); i--;)
	(*data_)[i] = varray[i];    

      return *this;
    }

    Vector<Number>& operator=(const std::valarray<Number>& varray) {
      return equals(varray);
    }




    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************


    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place
    
    Vector<Number>&  roundzero(Number tolerance = MatricksHelper<Number>::tolerance) { 
      for(size_t i=size(); i--;) {
	(*data_)[i] = mathq::roundzero((*data_)[i], tolerance);
      }
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T=Number >
      typename std::enable_if<is_complex<T>{}, Vector<T>& >::type conj() {
      using std::conj;
      for(size_t i=size(); i--;) {
	(*data_)[i] = conj((*data_)[i]);
      }
      return *this;
    }



    //**********************************************************************
    //***************** in-place modification********************************
    //**********************************************************************

    // .sort()
    //         sorts in place and returns the permuted indices

    Vector<size_t>& sort() {

      const size_t   N = size();
      Vector<size_t> &ivec = *(new Vector<size_t>(N));

      if (N==0)
	return ivec;
    
      std::vector<Pair<Number> > temp(N);

      for (size_t i = 0; i < N ; i++ ) {
	temp[i].index = i;
	temp[i].data = (*data_)[i];
      }
    
    
      std::sort(temp.begin(),temp.end());
    
    
      for (size_t i = 0; i < N ; i++ ) {
	ivec[i] = temp[i].index;
	(*data_)[i] = temp[i].data;
      }
    
      return ivec;

    }


    // .quniq()
    //         removes adjacent duplicates

    Vector<size_t>& quniq() {

      const size_t   N = size();

      if (N==0)
	return *(new Vector<size_t>(0));
    
      std::queue<Pair<Number> > unique;
	
      Pair<Number> prevpair(0, (*data_)[0]);
      unique.push(prevpair);
      for (size_t i = 1; i < N ; i++ ) {
	Pair<Number> mypair(i, (*data_)[i]);
	if (mypair.data != prevpair.data) {
	  unique.push(mypair);
	  prevpair = mypair;
	} 
      }

      const size_t   Nnew = unique.size();
      Vector<size_t> &indexvec = *(new Vector<size_t>(Nnew));
      resize(Nnew);
      for (size_t i = 0; i < Nnew ; i++ ) {
	Pair<Number> mypair = unique.front();
	unique.pop();
	indexvec[i] = mypair.index;
	(*data_)[i] = mypair.data;
      }

      return indexvec;
    }


    // .uniq()
    //         removes all duplicates

    Vector<size_t>& uniq() {

      const size_t   N = size();

      if (N==0)
	return *(new Vector<size_t>(0));
    
      std::map<size_t,Number> mymap;
      for (size_t j = 0; j < N ; j++ ) {
	mymap[j] = (*data_)[j];
      }

      for (size_t j = 0; j < N ; j++ ) {
	if (mymap.find(j) == mymap.end()) continue;
	Pair<Number> pair1(j, (*data_)[j]);
	for (size_t k = j+1; k < N ; k++ ) {
	  if (mymap.find(k) == mymap.end()) continue;
	  Pair<Number> pair2(k, (*data_)[k]);
	  if (pair1.data == pair2.data) {
	    mymap.erase(k);
	  } 
	}
      }

      const size_t   Nnew = mymap.size();
      Vector<size_t> &indexvec = *(new Vector<size_t>(Nnew));
      resize(Nnew);
      size_t   k = 0;
      for (typename std::map<size_t,Number>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
	indexvec[k] = it->first;
	(*data_)[k++] = it->second;
      }

      return indexvec;
    }


    Vector<Number>& reverse() {

      const size_t   N = size();
      if (N==0)
	return *this;
   
      for (size_t i = 0; i < N/2 ; i++ ) {
	Number temp = (*data_)[i];
	(*data_)[i] = (*data_)[N-i-1];
	(*data_)[N-i-1] = temp;
      }
      
      return *this;
      
    }


    // .cumsum() -- cumulative sum

    Vector<Number>& cumsum() {
      const size_t   N = size();
      Number sum = 0;
      for (size_t i = 0; i < N ; i++ ) {
	sum += (*data_)[i];
	(*data_)[i] = sum;
      }
      return *this;
    }

    // .cumprod()  --  cumulative product

    Vector<Number>& cumprod() {
      const size_t   N = size();
      Number prod = 1;
      for (size_t i = 0; i < N ; i++ ) {
	prod *= (*data_)[i];
	(*data_)[i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation

    Vector<Number>& cumtrapz() {
      const size_t   N = size();
      if (N==0) return *this;
      Number sum = (*data_)[0]/2;
      (*data_)[0] = 0;
      for (size_t i = 1; i < N ; i++ ) {
	sum += (*data_)[i];
	(*data_)[i] = sum - (*data_)[i]/2;
      }
      return *this;
    }

    // integrate_a2x(order)
    // order  name
    //     0  rectangular
    //     1  trapazoidal
    Vector<Number>& integrate_a2x(const Number a, const Number b, const int order=1) {
      std::valarray<Number> &mydata = *data_;

      const size_t   N = size();

      if (order == 0) {
	this->cumsum();
	const Number dx = (b-a)/Number(N);
	for (size_t i = 0; i < N ; i++ ) {
	  mydata[i] *= dx;
	}
      } else if (order == 1) {
	this->cumtrapz();
	const Number dx = (b-a)/Number(N-1);
	for (size_t i = 0; i < N ; i++ ) {
	  mydata[i] *= dx;
	}
      }  else {
	//TODO: issue error
      }
      return *this;
    }


    // .cumsumrev() -- cumulative sum -- from last to first

    Vector<Number>& cumsum_rev() {
      std::valarray<Number> &mydata = *data_;
      const size_t   N = size();

      Number sum = 0;
      for (size_t i = 0; i < N ; i++ ) {
	sum += mydata[N-1-i];
	mydata[N-1-i] = sum;
      }
      return *this;
    }

    // .cumprodrev()  --  cumulative product  -- from last to first

    Vector<Number>& cumprod_rev() {
      std::valarray<Number> &mydata = *data_;
      const size_t   N = size();

      Number prod = 1;
      for (size_t i = 0; i < N ; i++ ) {
	prod *= mydata[N-1-i];
	mydata[N-1-i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation -- from last to first

    Vector<Number>& cumtrapz_rev() {
      std::valarray<Number> &mydata = *data_;
      const size_t   N = size();
      if (N==0) return *this;

      Number sum = mydata[N-1]/2;
      mydata[N-1] = 0;
      for (size_t i = 1; i < N ; i++ ) {
	sum += mydata[N-1-i];
	mydata[N-1-i] = sum - mydata[N-1-i]/2;
      }
      return *this;
    }



    // integrate_x2b
    // order  name
    //     0  rectangular
    //     1  trapazoidal
    Vector<Number>& integrate_x2b(const Number a, const Number b, const int order=1) {
      std::valarray<Number> &mydata = *data_;
      const size_t   N = size();

      if (order == 0) {
	this->cumsum_rev();
	const Number dx = (b-a)/(N);
	for (size_t i = 0; i < N ; i++ ) {
	  mydata[N-1-i] *= dx;
	}
      } else if (order == 1) {
	this->cumtrapz_rev();
	const Number dx = (b-a)/(N-1);
	for (size_t i = 0; i < N ; i++ ) {
	  mydata[N-1-i] *= dx;
	}
      }  else {
	//TODO: issue error
      }
      return *this;
    }



    // diff   (v[n] = v[n] - v[n-1])
    Vector<Number>& diff(const bool periodic=false) {
      std::valarray<Number> &mydata = *data_;
      const size_t   N = size();
      if (N<=1) return *this;

      Number temp;
      if (periodic) {
	temp = mydata[0] - mydata[N-1];
      } else {
	temp = mydata[1] - mydata[0];
      }

      for (size_t i = 0; i < N-1 ; i++ ) {
	mydata[N-1-i] = mydata[N-1-i] - mydata[N-2-i];
      }

      mydata[0] = temp;
      return *this;
    }

    // diff_rev   (v[n] = v[n+1] - v[n])
    Vector<Number>& diff_rev(const bool periodic=false) {
      const size_t   N = size();
      std::valarray<Number> &mydata = *data_;
      if (N<=1) return *this;

      Number temp;
      if (periodic) {
	temp = mydata[0] - mydata[N-1];
      } else {
	temp = mydata[N-1] - mydata[N-2];
      }

      for (size_t i = 0; i < N-1 ; i++ ) {
	mydata[i] = mydata[i+1] - mydata[i];
      }

      mydata[N-1] = temp;
      return *this;
    }


    // deriv -  derivative
    // any change in the default parameters must be likewise made in vfunctions.h: deriv(...)

    Vector<Number>& deriv(const Number a, const Number b, const int n=1, int Dpts=7, const bool periodic=false) {
      std::valarray<Number> &dat = *data_;
      //MDISP(a,b,n,Dpts,periodic);
      const size_t   N = size();
      if (N<=1) return *this;

      const Number dx = (b-a)/Number(N-1);

      if (Dpts > N ) {
	//TODO: error or warning
	Dpts = N;
      }

      if (Dpts == 2) {
	this->diff(periodic);
	for (size_t i = 0; i < N ; i++ ) {
	  dat[i] /= dx;
	}
	
      } else if (Dpts == 3) {
	Number prev;
	Number curr;
	Number last;
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
	
	const Number c0 = 0.5/dx;
	for (size_t i = 1; i < N-1 ; i++ ) {
	  curr = dat[i+1] - dat[i-1];
	  dat[i-1] = c0*prev;
	  prev = curr;
	}
	dat[N-2] = c0*prev;
	dat[N-1] = c0*last;
	
      } else if (Dpts == 5) {
	Number prev1;
	Number prev2;
	Number curr;
	Number last;
	Number lastminus1;
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
	
	const Number c0 = 1/(12*dx);
	for (size_t i = 2; i < N-2 ; i++ ) {
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
	Number prev1;
	Number prev2;
	Number prev3;
	Number curr;
	Number last;
	Number lastminus1;
	Number lastminus2;
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
	const Number c0 = 1/(60*dx);
	for (size_t i = 3; i < N-3 ; i++ ) {
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
      Number d;
      return "Vector"+display::bracketAndStyleTypename(d);
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif




    // stream << operator

    friend std::ostream& operator<<(std::ostream &stream, const Vector<Number>& v) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      stream << style.apply(FormatDataVector::string_opening);
      const size_t   N = FormatDataVector::max_elements_per_line;
      size_t   k = 0;
      for (size_t ii = 0; ii < v.size(); ii++, k++) {
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


    //template <typename Number>	
    friend inline std::istream& operator>>(const std::string s,  Vector<Number>& x) {	
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream,  Vector<Number>& x) {	
      // const size_t   LINESZ = 32768;
      // char line[LINESZ];
      // std::vector<Number> v;
      // size_t   N = 0;
      // const size_t   Nold = x.size();
      // Number temp;
      // size_t   Nlines = 0;
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
      // 	    size_t   Nchars=0;
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
      // 	      size_t   Nchars=0;
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
      // 	      size_t   Nchars=0;
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

      // for(size_t i=0; i<N; i++)
      // 	x[i] = v[i];
      
      // return restore_stream(stream,strmline);
      return stream;
    }

    // --------------------- FRIENDS ---------------------

  

  };




};


#endif 

