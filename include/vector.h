#ifndef MATHQ__VECTOR_H
#define MATHQ__VECTOR_H 1



namespace mathq {


  /********************************************************************
   * Vector<Element>    -- variable size vector (valarray)
   *                 Element  = type for elements
   * Vector<Element,N1> -- fixed size vector (array)
   *                 N1 = size = number of elements
   *
   * DO NOT SPECIFY: Number,depth
   *                 The defaults are defined in the declaration in
   *                 preface.h
   *                 Number = number type
   *                   = underlying algebraic field
   *                     ex. int, double, std::complex<double>
   *                 depth = tensor depth. if Element=Number, then depth=1.
  ********************************************************************
   */

  template <class Element, int N1> class Vector :
    public MArrayExpRW<Vector<Element, N1>, Element, typename NumberTrait<Element>::Type, 1 + NumberTrait<Element>::getDepth(), 1> {

  public:
    typedef typename NumberTrait<Element>::Type Number;
    typedef typename OrderedNumberTrait<Number>::Type OrderedNumber;

    typedef typename ArrayType<Element, N1>::Type MyArrayType;
    constexpr static int rank = 1;
    constexpr static int depth = 1 + NumberTrait<Element>::getDepth();

    // rename these
    typedef typename NumberTrait<Element>::Type DType;
    typedef typename OrderedNumberTrait<Number>::Type FType;
    typedef Vector<Element, N1> XType;
    typedef Element EType;
    constexpr static int rank_value = 1;


    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    //**********************************************************************


  private:
    MyArrayType data_;


  public:

    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // TODO: never use new. just resize the valarray  


    // -------------------  DEFAULT  CONSTRUCTOR: Vector()  --------------------
    explicit Vector<Element, N1>() {
      constructorHelper();
    }


    // --------------------- Vector(N)  ---------------------

    template<size_t NE1 = N1, EnableIf<NE1 == 0> = 0>

    explicit Vector<Element, N1>(const size_t N) {
      data_.resize(N);
      constructorHelper();
    }


    // --------------------- Vector(N,value)  ---------------------

    template<size_t NE1 = N1, EnableIf<NE1 == 0> = 0>

    explicit Vector<Element, N1>(const size_t N, const Element val) {
      data_.resize(N);
      *this = val;
      constructorHelper();
    }

    // --------------------- Vector(std::initializer_list<Dimensions>)  ---------------------

    template<size_t NE1 = N1, EnableIf<(NE1 > 0)> = 0>

    explicit Vector<Element, N1>(const std::initializer_list<Dimensions> deepdims) {
      // TRDISP(deepdims);
      this->resize(std::vector<Dimensions>(deepdims));
      constructorHelper();
    }
    // --------------------- Vector(std::vector<Dimensions>)  ---------------------

    template<size_t NE1 = N1, EnableIf<(NE1 > 0)> = 0>

    explicit Vector<Element, N1>(const std::vector<Dimensions> deepdims) {
      // TRDISP(deepdims);
      this->resize(deepdims);
      constructorHelper();
    }


    // --------------------- Vector(Element value)  ---------------------

    template<size_t NE1 = N1, EnableIf<(NE1 > 0)> = 0>

    explicit Vector<Element, N1>(const Element val) {
      *this = val;
      constructorHelper();
    }

    // --------------------- Vector(Number value)  ---------------------

    template<size_t NE1 = N1, EnableIf<(NE1 > 0)&&(depth>1)> = 0>

    explicit Vector<Element, N1>(const Number val) {
      *this = val;
      constructorHelper();
    }


    // --------------------- array[]  CONSTRUCTOR ---------------------

    template<size_t NE1 = N1, EnableIf<NE1 == 0> = 0>

    Vector<Element, N1>(const size_t N, const Element(vals)[]) {
      data_.resize(N);
      *this = vals;
      constructorHelper();
    }

    // ************* C++11 initializer_list CONSTRUCTOR---------------------
    Vector<Element, N1>(const std::initializer_list<Element>& mylist) {
      *this = mylist;
      constructorHelper();
    }


    // --------------------- Vector(Vector) --------------------

    template <int NE2>
    Vector<Element, N1>(const Vector<Element, NE2>& v2) {
      *this = v2;
      constructorHelper();
    }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------

    template <class X>
    Vector<Element, N1>(const MArrayExpR<X, Element, Number, depth, rank_value>& x) {
      if constexpr (N1==0) {
        this->resize(x.size());
      }

      *this = x;
      constructorHelper();
    }




    // --------------------- Vector(valarray)  ---------------------
    Vector<Element, N1>(const std::valarray<Element>& valar) {
      if constexpr (N1==0) {
        this->resize(valar.size());
      }
      *this = valar;
      constructorHelper();
    }



    // --------------------- constructorHelper() --------------------

    void constructorHelper() {
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Vector<Element, N1>() {
    }


    //**********************************************************************
    //************************** SIZE ******************************
    //**********************************************************************


    bool isExpression(void) const {
      return false;
    }
    MultiArrays getEnum() const {
      return T_VECTOR;
    }
    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    inline size_t size(void) const {
      return data_.size();
    }
    size_t ndims(void) const {
      return 1;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(size());
      return dimensions;
    }
    Dimensions tdims(void) const {
      Dimensions dimensions(N1);
      return dimensions;
    }


    inline size_t getDepth(void) const {
      return depth;
    }

    Dimensions eldims(void) const {
      Dimensions dimensions();
      if constexpr (depth>1) {
        if (size()>0) {
          return data_[0].dims();
        }
      }
      return *(new Dimensions());
    }

    // the size of each element
    inline size_t elsize(void) const {
      if constexpr (depth<2) {
        return 1;
      }
      else {
        const size_t NElements = this->size();
        if (NElements==0) {
          return 0;
        }
        else {
          return data_[0].size();
        }
      }
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_t eldeepsize(void) const {
      if constexpr (depth<2) {
        return 1;
      }
      else {
        const size_t NElements = this->size();
        if (NElements==0) {
          return 0;
        }
        else {
          return data_[0].deepsize();
        }
      }
    }

    // the total number of numbers in this data structure
    size_t deepsize(void) const {
      if constexpr (depth<2) {
        return this->size();
      }
      else {
        return (this->size())*(this->eldeepsize());
      }
    }

    std::vector<Dimensions>& deepdims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return deepdims(ddims);
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      parentdims.push_back(dims());
      if constexpr (depth>1) {
        if (size()>0) {
          data_[0].deepdims(parentdims);
        }
      }
      return parentdims;
    }






    //**********************************************************************
    //************************** RESIZE & REHSAPCE ******************************
    //**********************************************************************

    // --------------------- .resize() ---------------------

    // These allow the user to resize a vector



    // --------------------- .resize(N) ---------------------

    template<size_t NE1 = N1, EnableIf<NE1 == 0> = 0>

    Vector<Element, N1>& resize(const size_t N) {
      if (N==this->size())
        return *this;
      // reallocate store
      //      delete  data_ ;
      //      data_ = new std::valarray<Number>(N);
      data_.resize(N);
      return *this;
    }

    // TODO: should just pass an index and make deepdims const

    Vector<Element, N1>& resize(const std::vector<Dimensions>& deepdims_in) {
      std::vector<Dimensions> deepdims(deepdims_in);
      Dimensions newdims = deepdims[0];
      const size_t Nnew = newdims[0];
      if constexpr (N1==0) {
        resize(Nnew);
      }
      if constexpr (depth>1) {
        deepdims.erase(deepdims.begin());
        for (size_t i = 0; i < size(); i++) {
          std::vector<Dimensions> ddims(deepdims);
          data_[i].resize(ddims);
        }
      }

      return *this;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [deepsize()] and note return type

    // "read/write"
    Number& dat(const size_t n) {
      using namespace::display;
      if constexpr (depth < 2) {
        int k = n;
        if (k < 0) {
          k += size();
        }
        return data_[k];
      }
      else {
        const int Ndeep = this->eldeepsize();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return data_[j].dat(k);
      }
    }

    // read
    const Number& dat(const size_t n)  const {
      using namespace::display;
      if constexpr (depth < 2) {
        int k = n;
        if (k < 0) {
          k += size();
        }
        return data_[k];
      }
      else {
        const int Ndeep = this->eldeepsize();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return data_[j].dat(k);
      }
    }

    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------

    // "read/write": x.dat(DeepIndices)
    Number& dat(const DeepIndices& dinds) {
      const size_t mydepth = dinds.size();
      size_t n = dinds[mydepth -depth][0];

      if constexpr (depth>1) {
        return (*this)(n).dat(dinds);
      }
      else {
        return (*this)(n);
      }
    }

    // "read": x.dat(DeerIndices)
    const Number dat(const DeepIndices& dinds)  const {
      const size_t mydepth = dinds.size();
      size_t n = dinds[mydepth -depth][0];

      if constexpr (depth>1) {
        return (*this)(n).dat(dinds);
      }
      else {
        return (*this)(n);
      }
    }


    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------

    // "read/write": x.dat(Indices)
    Number& dat(const Indices& inds) {
      Indices inds_next(inds);
      // MOUT << "Vector: "<<std::endl;
      // error if (inds.size() != sum deepdims[i].rank
      size_t n = inds_next[0];
      // MOUT << "  ";
      inds_next.erase(inds_next.begin());
      if constexpr (depth>1) {
        return (*this)(n).dat(inds_next);
      }
      else {
        return (*this)(n);
      }
    }

    // "read": x.dat(Indices)
    const Number dat(const Indices& inds)  const {
      Indices inds_next(inds);
      // error if (inds.size() != sum deepdims[i].rank
      size_t n = inds_next[0];
      inds_next.erase(inds_next.begin());
      if constexpr (depth>1) {
        return (*this)(n).dat(inds_next);
      }
      else {
        return (*this)(n);
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // "read/write"
    Element& operator[](const size_t n) {
      int k = n;
      if (k < 0) {
        k += size();
      }
      return data_[k];
    }

    // read
    const Element& operator[](const size_t n)  const {
      int k = n;
      if (k < 0) {
        k += size();
      }
      return data_[k];
    }


    //**********************************************************************
    //***************MultiArray cast *********************
    //**********************************************************************

    operator MultiArray<Element, rank, Number, depth>() const {
      MultiArray<Element, 1, Number, depth> ma(*this);
    }

      //**********************************************************************
      //***************MultiArray-style Element Access: v(n) *********************
      //**********************************************************************


      // "read/write"
      Element& operator()(const size_t n) {
      return data_[n];
    }

    // "read only"
    const Element& operator()(const size_t n)  const {
      return data_[n];
    }




    // Accessing a slice of values

    TERW_Subset<Element> operator[](const slc& slice) {
      return (*this)[slice.toIndexVector(size())];
    }
    const TERW_Subset<Element>  operator[](const slc& slice) const {
      //      display::log3("Vector","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexVector(size())];
    }


    // Accessing a SET of values using a vector of ints

    TERW_Subset<Element> operator[](const Vector<size_t>& ii) {
      return TERW_Subset<Element>(*this, ii);
    }
    const TERW_Subset<Element> operator[](const Vector<size_t>& ii) const {
      return TERW_Subset<Element>(*this, ii);
    }




    // Accessing a SET of values using a MASK

    TERW_Submask<Element> operator[](const Vector<bool>& mask) {
      return  TERW_Submask<Element>(*this, mask);
    }
    const TERW_Submask<Element> operator[](const Vector<bool>& mask)  const {
      return  TERW_Submask<Element>(*this, mask);
    }


    //Accessing a SET of values using a list

    TERW_Subset<Element> operator[](const std::initializer_list<size_t>& list) {
      return  TERW_Subset<Element>(*this, list);
    }
    const TERW_Subset<Element> operator[](const std::initializer_list<size_t>& list) const {
      return  TERW_Subset<Element>(*this, list);
    }





    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- getInternalStdArray() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& getInternalStdArray() {
      return data_;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    Element* data() {
      if constexpr (N1 == 0) {
        // valarray<Element>
        return &(data_[0]);
      }
      else {
        // array<Element>
        return data_.data();
      }
    }


    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to MArrayExpRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    Vector<Element, N1>& operator=(const Element& e) {
      for (size_t i = 0; i < size(); i++) {
        (*this)[i] = e;
      }
      return *this;
    }

    template <class T = Element>
    typename std::enable_if<!std::is_same<T, Number>::value, Vector<T, N1>& >::type operator=(const Number& d) {
      for (size_t i = 0; i < deepsize(); i++) {
        (*this).dat(i) = d;
      }
      return *this;
    }




    // ------------------------ Vector = Vector<Element,NE2,Number,depth> ----------------

    template <int NE2>
    Vector<Element, N1>& operator=(const Vector<Element, NE2>& v) {
      if constexpr (depth<=1) {
        if constexpr (N1==0) {
          if (this->size() != v.size()) {
            resize(v.size());
          }
        }
        for (size_t i = 0; i < size(); i++) {
          (*this)[i] = v[i];
        }
      }
      else {
        resize(v.deepdims());
        for (size_t i = 0; i < deepsize(); i++) {
          this->dat(i) = v.dat(i);
        }
      }
      return *this;
    }


    // ------------------------ Vector = MArrayExpR ----------------

    template <class X>
    Vector<Element, N1>& operator=(const MArrayExpR<X, Element, Number, depth, rank_value>& x) {

      if constexpr (depth<=1) {
        if constexpr (N1==0) {
          if (this->size() != x.size()) {
            resize(x.size());
          }
        }
        for (size_t i = 0; i < size(); i++) {
          (*this)[i] = x[i];
        }
      }
      else {
        resize(x.deepdims());
        for (size_t i = 0; i < deepsize(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }



    // ------------------------ Vector = array[] ----------------

    Vector<Element, N1>& operator=(const Element array[]) {
      for (size_t i = 0; i < size(); i++) {
        (*this)(i) = array[i];
      }
      return *this;
    }


    // ------------------------ Vector = list ----------------

    Vector<Element, N1>& operator=(const std::list<Element>& mylist) {
      if constexpr (N1==0) {
        // TODO: warn if not in constructor
        if (this->size() != mylist.size()) {
          resize(mylist.size());
        }
      }
      size_t i = 0;
      for (typename std::list<Element>::const_iterator it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)(i++) = *it;
      }
      return *this;
    }


    // ------------------------ Vector = initializer_list ----------------

    Vector<Element, N1>& operator=(const std::initializer_list<Element>& mylist) {
      if constexpr (N1==0) {
        // TODO: warn if not in constructor
        if (this->size() != mylist.size()) {
          data_.resize(mylist.size());
        }
      }

      size_t k = 0;
      typename std::initializer_list<Element>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it, k++) {
        data_[k] = *it;
      }

      return *this;
    }




    // ------------------------ Vector = std::vector ----------------

    Vector<Element, N1>& operator=(const std::vector<Element>& vstd) {
      // resize to avoid segmentation faults
      if constexpr (N1==0) {
        if (this->size() != vstd.size()) {
          resize(vstd.size());
        }
      }
      for (size_t i = 0; i < size(); i++)
        (*this)(i) = vstd[i];
      return *this;
    }





    // ------------------------ Vector = std::array ----------------

    template <std::size_t N>
    Vector<Element, N1>& operator=(const std::array<Number, N>& varray) {
      // resize to avoid segmentation faults
      if constexpr (N1==0) {
        if (this->size() != varray.size()) {
          resize(varray.size());
        }
      }

      for (size_t i = 0; i < size(); i++)
        (*this)(i) = varray[i];

      return *this;
    }





    // ------------------------ Vector = std::valarray ----------------

    Vector<Element, N1>& operator=(const std::valarray<Element>& varray) {

      // resize to avoid segmentation faults
      if constexpr (N1==0) {
        if (this->size() != varray.size()) {
          resize(varray.size());
        }
      }

      for (size_t i = 0; i < size(); i++)
        (*this)(i) = varray[i];

      return *this;
    }




    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************


    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    Vector<Element, N1>& roundzero(OrderedNumber tolerance = Functions<OrderedNumber>::tolerance) {
      for (size_t i = size(); i--;) {
        data_[i] = mathq::roundzero(data_[i], tolerance);
      }
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template<typename T = Number> EnableMethodIf<is_complex<T>{}, Vector<T>&>

    conj() {
      using std::conj;
      for (size_t i = size(); i--;) {
        data_[i] = conj(data_[i]);
      }
      return *this;
    }



    //**********************************************************************
    //***************** in-place modification********************************
    //**********************************************************************

    // .sort()
    //         sorts in place and returns the permuted indices

    Vector<size_t>& sort() {

      const size_t N = size();
      Vector<size_t>& ivec = *(new Vector<size_t>(N));

      if (N==0)
        return ivec;

      std::vector<Pair<Element> > temp(N);

      for (size_t i = 0; i < N; i++) {
        temp[i].index = i;
        temp[i].data = data_[i];
      }


      std::sort(temp.begin(), temp.end());


      for (size_t i = 0; i < N; i++) {
        ivec(i) = temp[i].index;
        data_[i] = temp[i].data;
      }

      return ivec;

    }


    // .quniq()
    //         removes adjacent duplicates
    //  template<typename T=Number> EnableMethodIf<is_complex<T>{}, Vector<T>&> 
    template<typename T = size_t> EnableMethodIf<N1==0, Vector<T>& >

    quniq() {

      const size_t N = size();

      if (N==0)
        return *(new Vector<size_t>(0));

      std::queue<Pair<Element> > unique;

      Pair<Element> prevpair(0, data_[0]);
      unique.push(prevpair);
      for (size_t i = 1; i < N; i++) {
        Pair<Element> mypair(i, data_[i]);
        if (mypair.data != prevpair.data) {
          unique.push(mypair);
          prevpair = mypair;
        }
      }

      const size_t Nnew = unique.size();
      Vector<size_t>& indexvec = *(new Vector<size_t>(Nnew));
      resize(Nnew);
      for (size_t i = 0; i < Nnew; i++) {
        Pair<Element> mypair = unique.front();
        unique.pop();
        indexvec(i) = mypair.index;
        data_[i] = mypair.data;
      }

      return indexvec;
    }


    // .uniq()
    //         removes all duplicates
    template<typename T = size_t> EnableMethodIf<N1==0, Vector<T>& >

    uniq() {

      const size_t N = size();

      if (N==0)
        return *(new Vector<size_t>(0));

      std::map<size_t, Number> mymap;
      for (size_t j = 0; j < N; j++) {
        mymap[j] = data_[j];
      }

      for (size_t j = 0; j < N; j++) {
        if (mymap.find(j) == mymap.end()) continue;
        Pair<Element> pair1(j, data_[j]);
        for (size_t k = j+1; k < N; k++) {
          if (mymap.find(k) == mymap.end()) continue;
          Pair<Element> pair2(k, data_[k]);
          if (pair1.data == pair2.data) {
            mymap.erase(k);
          }
        }
      }

      const size_t Nnew = mymap.size();
      Vector<size_t>& indexvec = *(new Vector<size_t>(Nnew));
      resize(Nnew);
      size_t k = 0;
      for (typename std::map<size_t, Number>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        indexvec(k) = it->first;
        data_[k++] = it->second;
      }

      return indexvec;
    }


    Vector<Element, N1>& reverse() {

      const size_t N = size();
      if (N==0)
        return *this;

      for (size_t i = 0; i < N/2; i++) {
        Element temp = data_[i];
        data_[i] = data_[N-i-1];
        data_[N-i-1] = temp;
      }

      return *this;

    }


    // .cumsum() -- cumulative sum

    Vector<Element, N1>& cumsum() {
      const size_t N = size();
      Element sum = 0;
      for (size_t i = 0; i < N; i++) {
        sum += data_[i];
        data_[i] = sum;
      }
      return *this;
    }

    // .cumprod()  --  cumulative product

    Vector<Element, N1>& cumprod() {
      const size_t N = size();
      Element prod = 1;
      for (size_t i = 0; i < N; i++) {
        prod *= data_[i];
        data_[i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation

    Vector<Element, N1>& cumtrapz() {
      const size_t N = size();
      if (N==0) return *this;
      Element sum = data_[0]/2;
      data_[0] = 0;
      for (size_t i = 1; i < N; i++) {
        sum += data_[i];
        data_[i] = sum - data_[i]/2;
      }
      return *this;
    }

    // integrate_a2x(order)
    // order  name
    //     0  rectangular
    //     1  trapazoidal
    Vector<Element, N1>& integrate_a2x(const Element a, const Element b, const int order = 1) {

      const size_t N = size();

      if (order == 0) {
        this->cumsum();
        const Element dx = (b-a)/Number(N);
        for (size_t i = 0; i < N; i++) {
          data_[i] *= dx;
        }
      }
      else if (order == 1) {
        this->cumtrapz();
        const Element dx = (b-a)/Number(N-1);
        for (size_t i = 0; i < N; i++) {
          data_[i] *= dx;
        }
      }
      else {
        //TODO: issue error
      }
      return *this;
    }


    // .cumsumrev() -- cumulative sum -- from last to first

    Vector<Element, N1>& cumsum_rev() {
      const size_t N = size();

      Element sum = 0;
      for (size_t i = 0; i < N; i++) {
        sum += data_[N-1-i];
        data_[N-1-i] = sum;
      }
      return *this;
    }

    // .cumprodrev()  --  cumulative product  -- from last to first

    Vector<Element, N1>& cumprod_rev() {
      const size_t N = size();

      Element prod = 1;
      for (size_t i = 0; i < N; i++) {
        prod *= data_[N-1-i];
        data_[N-1-i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation -- from last to first

    Vector<Element, N1>& cumtrapz_rev() {
      const size_t N = size();
      if (N==0) return *this;

      Element sum = data_[N-1]/2;
      data_[N-1] = 0;
      for (size_t i = 1; i < N; i++) {
        sum += data_[N-1-i];
        data_[N-1-i] = sum - data_[N-1-i]/2;
      }
      return *this;
    }



    // integrate_x2b
    // order  name
    //     0  rectangular
    //     1  trapazoidal
    Vector<Element, N1>& integrate_x2b(const Element a, const Element b, const int order = 1) {
      const size_t N = size();

      if (order == 0) {
        this->cumsum_rev();
        const Element dx = (b-a)/(N);
        for (size_t i = 0; i < N; i++) {
          data_[N-1-i] *= dx;
        }
      }
      else if (order == 1) {
        this->cumtrapz_rev();
        const Element dx = (b-a)/(N-1);
        for (size_t i = 0; i < N; i++) {
          data_[N-1-i] *= dx;
        }
      }
      else {
        //TODO: issue error
      }
      return *this;
    }



    // diff   (v[n] = v[n] - v[n-1])
    Vector<Element, N1>& diff(const bool periodic = false) {
      const size_t N = size();
      if (N<=1) return *this;

      Element temp;
      if (periodic) {
        temp = data_[0] - data_[N-1];
      }
      else {
        temp = data_[1] - data_[0];
      }

      for (size_t i = 0; i < N-1; i++) {
        data_[N-1-i] = data_[N-1-i] - data_[N-2-i];
      }

      data_[0] = temp;
      return *this;
    }

    // diff_rev   (v[n] = v[n+1] - v[n])
    Vector<Element, N1>& diff_rev(const bool periodic = false) {
      const size_t N = size();
      if (N<=1) return *this;

      Element temp;
      if (periodic) {
        temp = data_[0] - data_[N-1];
      }
      else {
        temp = data_[N-1] - data_[N-2];
      }

      for (size_t i = 0; i < N-1; i++) {
        data_[i] = data_[i+1] - data_[i];
      }

      data_[N-1] = temp;
      return *this;
    }


    // deriv -  derivative
    // any change in the default parameters must be likewise made in vfunctions.h: deriv(...)
    // n: number of derivatives to take
    // Dpts: window size = number of points used in derivative formula
    // periodic: if true, perform derivative with start and end connected: 
    //           dat[-1] == dat[n-1], dat[n] == dat[0] etc

    Vector<Element, N1>& deriv(const Element a, const Element b, const int n = 1, int Dpts = 7, const bool periodic = false) {
      //MDISP(a,b,n,Dpts,periodic);
      const size_t N = size();
      if (N<=1) return *this;

      const Element dx = (b-a)/Number(N-1);

      if (Dpts > N) {
        //TODO: error or warning
        Dpts = N;
      }

      if (Dpts == 2) {
        this->diff(periodic);
        for (size_t i = 0; i < N; i++) {
          data_[i] /= dx;
        }

      }
      else if (Dpts == 3) {
        Element prev;
        Element curr;
        Element last;
        if (periodic) {
          // first point
          prev = data_[1] - data_[N-1];
          // last
          last = data_[0] - data_[N-2];
        }
        else {
          // first point
          prev = -3*data_[0] + 4*data_[1] - data_[2];
          // last
          last = 3*data_[N-1] - 4*data_[N-2] + data_[N-3];
        }

        const Element c0 = 0.5/dx;
        for (size_t i = 1; i < N-1; i++) {
          curr = data_[i+1] - data_[i-1];
          data_[i-1] = c0*prev;
          prev = curr;
        }
        data_[N-2] = c0*prev;
        data_[N-1] = c0*last;

      }
      else if (Dpts == 5) {
        Element prev1;
        Element prev2;
        Element curr;
        Element last;
        Element lastminus1;
        if (periodic) {
          // second to last point
          lastminus1 = data_[N-4] - 8*data_[N-3] + 8*data_[N-1] - data_[0];
          // last
          last = data_[N-3] - 8*data_[N-2] + 8*data_[0]   - data_[1];
          // first point
          prev2 = data_[N-2] - 8*data_[N-1] + 8*data_[1]   - data_[2];
          // second point
          prev1 = data_[N-1] - 8*data_[0]   + 8*data_[2]   - data_[3];
        }
        else {
          lastminus1 = -data_[N-5] +  6*data_[N-4] - 18*data_[N-3] + 10*data_[N-2] +  3*data_[N-1];
          last = 3*data_[N-5] - 16*data_[N-4] + 36*data_[N-3] - 48*data_[N-2] + 25*data_[N-1];
          prev2 = -3*data_[4]   + 16*data_[3]   - 36*data_[2]   + 48*data_[1]   - 25*data_[0];
          prev1 = data_[4]   -  6*data_[3]   + 18*data_[2]   - 10*data_[1]   -  3*data_[0];
        }

        const Element c0 = 1/(12*dx);
        for (size_t i = 2; i < N-2; i++) {
          curr = data_[i-2] - 8*data_[i-1] + 8*data_[i+1]  - data_[i+2];
          data_[i-2] = c0*prev2;
          prev2 = prev1;
          prev1 = curr;
        }
        data_[N-4] = c0*prev2;
        data_[N-3] = c0*prev1;
        data_[N-2] = c0*lastminus1;
        data_[N-1] = c0*last;

      }
      else if (Dpts == 7) {
        Element prev1;
        Element prev2;
        Element prev3;
        Element curr;
        Element last;
        Element lastminus1;
        Element lastminus2;
        if (periodic) {
          lastminus2 = -data_[N-6] + 9*data_[N-5] - 45*data_[N-4] + 45*data_[N-2]  - 9*data_[N-1] + data_[0];
          lastminus1 = -data_[N-5] + 9*data_[N-4] - 45*data_[N-3] + 45*data_[N-1]  - 9*data_[0] + data_[1];
          last = -data_[N-4] + 9*data_[N-3] - 45*data_[N-2] + 45*data_[0]  - 9*data_[1] + data_[2];
          prev3 = -data_[N-3] + 9*data_[N-2] - 45*data_[N-1] + 45*data_[1]  - 9*data_[2] + data_[3];
          prev2 = -data_[N-2] + 9*data_[N-1] - 45*data_[0]   + 45*data_[2]  - 9*data_[3] + data_[4];
          prev1 = -data_[N-1] + 9*data_[0]   - 45*data_[1]   + 45*data_[3]  - 9*data_[4] + data_[5];
        }
        else {
          lastminus2 = -(2*data_[N-1] - 24*data_[N-2] -  35*data_[N-3] +  80*data_[N-4] -  30*data_[N-5] +  8*data_[N-6] -    data_[N-7]);
          lastminus1 = -(-10*data_[N-1] - 77*data_[N-2] + 150*data_[N-3] - 100*data_[N-4] +  50*data_[N-5] - 15*data_[N-6] +  2*data_[N-7]);
          last = -(-147*data_[N-1] +360*data_[N-2]- 450*data_[N-3] + 400*data_[N-4] - 225*data_[N-5] + 72*data_[N-6] - 10*data_[N-7]);

          prev3 = -147*data_[0] + 360*data_[1] - 450*data_[2] + 400*data_[3] - 225*data_[4] + 72*data_[5] - 10*data_[6];
          prev2 = -10*data_[0] -  77*data_[1] + 150*data_[2] - 100*data_[3] +  50*data_[4] - 15*data_[5] +  2*data_[6];
          prev1 = 2*data_[0] -  24*data_[1] -  35*data_[2] +  80*data_[3] -  30*data_[4] +  8*data_[5] -    data_[6];
        }
        const Element c0 = 1/(60*dx);
        for (size_t i = 3; i < N-3; i++) {
          curr = -data_[i-3] + 9*data_[i-2] - 45*data_[i-1] + 45*data_[i+1]  - 9*data_[i+2] + data_[i+3];
          data_[i-3] = c0*prev3;
          prev3 = prev2;
          prev2 = prev1;
          prev1 = curr;
        }
        data_[N-6] = c0*prev3;
        data_[N-5] = c0*prev2;
        data_[N-4] = c0*prev1;
        data_[N-3] = c0*lastminus2;
        data_[N-2] = c0*lastminus1;
        data_[N-1] = c0*last;


      }
      else {
        //TODO: issue error
      }
      if (n>1) {
        return this->deriv(a, b, n-1, Dpts, periodic);
      }
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string bottom() {
      typename OrderedNumberTrait<Element>::Type d;
      return display::getTypeName(d);
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "Vector";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      if (N1!=0) {
        s += StyledString::get(COMMA).get();
        s += "N1=";
        s += num2string(N1);
      }
      //    if (depth>1) {
      //      s += StyledString::get(COMMA).get();
      //      s += "depth=";
      //      s += num2string(depth);
      //    }
      s += StyledString::get(ANGLE2).get();
      return s;
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif




    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Vector<Element, N1>& v) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      stream << style.apply(FormatDataVector::string_opening);
      const size_t N = FormatDataVector::max_elements_per_line;
      size_t k = 0;
      for (size_t ii = 0; ii < v.size(); ii++, k++) {
        if (k >= N) {
          stream << style.apply(FormatDataVector::string_endofline);
          k = 0;
        }
        dispval_strm(stream, v(ii));
        if (ii < v.size()-1) {
          stream << style.apply(FormatDataVector::string_delimeter);
        }
      }
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }


    friend inline std::istream& operator>>(const std::string s, Vector<Element, N1>& x) {
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, Vector<Element, N1>& x) {
      // const size_t LINESZ = 32768;
      // char line[LINESZ];
      // std::vector<Element> v;
      // size_t N = 0;
      // const size_t Nold = x.size();
      // Element temp;
      // size_t Nlines = 0;
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
      // 	    size_t Nchars=0;
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
      // 	      size_t Nchars=0;
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
      // 	      size_t Nchars=0;
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

    // --------------------- CONVERSION OPERATORS ---------------------





    // std::vector()


    operator std::vector<Element>() const {
      const size_t N = size();
      std::vector<Element> y(N);
      for (size_t i = 0; i<N; i++) {
        y[i] = (*this)[i];
      }
      return y;
    }


    operator Element* () const {
      const size_t N = size();
      Element* ptr = new Element[N];
      for (size_t i = 0; i<N; i++) {
        ptr[i] = (*this)[i];
      }
      return ptr;
    }


    // valarray<Element>

    operator std::valarray<Element>() const {
      const size_t N = size();
      std::valarray<Element> y(N);
      for (size_t i = 0; i<N; i++) {
        y[i] = (*this)[i];
      }
      return y;
    }


  };




};


#endif 

