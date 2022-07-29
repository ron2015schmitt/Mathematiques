#ifndef MATHQ__VECTOR
#define MATHQ__VECTOR 1


/********************************************************************
 * Vector<Element>    -- variable size vector (valarray)
 *                 Element  = type for elements
 * Vector<Element,N1> -- fixed size vector (array)
 *                 N1 = size = number of elements
 *
 * DO NOT SPECIFY: NumberType,depth
 *                 The defaults are defined in the declaration in
 *                 declarations.h
 *                 NumberType = number type
 *                   = underlying algebraic field
 *                     ex. int, double, std::complex<double>
 *                 depth = tensor depth. if Element=NumberType, then depth=1.
********************************************************************
 */


namespace mathq {

  template <typename Element, size_t... sizes>
  class MultiArray<Element, 1, sizes...> : public ExpressionRW<
    Vector<Element, sizes...>,  // Derived
    Element,  // Element
    typename NumberTrait<Element>::Type, // Number
    1 + NumberTrait<Element>::depth(),  // depth
    1  // rank
  > {
  public:


    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 1;
    constexpr static std::array<size_t, rank_value> static_dims_array = { sizes... };
    constexpr static size_t N1 = get<0>(static_dims_array);
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = ( sizeof...(sizes) == 0 );
    constexpr static size_t compile_time_size = calc_size<rank_value, N1>();

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using Type = MultiArray<Element, rank_value, sizes...>;
    using ConcreteType = Vector<Element, sizes...>;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using ParentType = ExpressionRW<
      ConcreteType,  // Derived
      Element,  // Element
      NumberType, // Number
      depth_value,  // depth
      rank_value  // rank
    >;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<Element>::Type;
    using MyArrayType = typename ArrayTypeTrait<Element, N1>::Type;


    //**********************************************************************
    // OBJECT DATA 
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    //
    // size is taken from data_.size
    //**********************************************************************

  // private:
    MyArrayType data_;

  public:

    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************


    // -------------------  default  --------------------
    MultiArray() {
    }

    // --------------------- copy constructor --------------------
    MultiArray(const Type& var) {
      *this = var;
    }

    // ----------------------- initializer_list ---------------------
    // not explicit: allows use of nested init lists when depth_value > 1
    MultiArray(const std::initializer_list<Element>& var) {
      if (is_dynamic_value) {
        resize(var.size());
      }
      *this = var;
    }

   

    // ----------------------- std::vector ---------------------
    explicit MultiArray(const std::vector<Element>& var) {
      if (is_dynamic_value) {
        resize(var.size());
      }
      *this = var;
    }

    // ----------------------- std::valarray ---------------------
    explicit MultiArray(const std::valarray<Element>& var) {
      if (is_dynamic_value) {
        resize(var.size());
      }
      *this = var;
    }

    // ----------------------- std::array ---------------------
    template<size_t NE2>
    explicit MultiArray(const std::array<Element, NE2>& var) {
      if (is_dynamic_value) {
        resize(var.size());
      }
      *this = var;
    }

    //--------------------- EXPRESSION CONSTRUCTOR --------------------
    template <class Derived>
    MultiArray(const ExpressionR<Derived, Element, NumberType, depth_value, rank_value>& x) {
      if constexpr (is_dynamic_value) {
        this->resize(x.size());
      }
      *this = x;
    }


    //**********************************************************************
    //                    CONSTRUCTORS: FIXED size  
    //**********************************************************************

    // --------------------- FIXED SIZE: from dynamic size --------------------
    template<bool enabled = !is_dynamic_value> requires (enabled)
    explicit MultiArray(const Vector<Element>& var) {
      *this = var;
    }

    // --------------------- FIXED SIZE: set all elements to same value   ---------------------

    template<bool enabled = !is_dynamic_value> requires (enabled)
    explicit MultiArray(const Element val) {
      *this = val;
    }

    // --------------------- FIXED SIZE: set all bottom elements to same value   ---------------------

    template<bool enabled = !is_dynamic_value> requires (enabled && (depth_value > 1) && (!std::is_same<Element, NumberType>::value) )
      explicit MultiArray(const NumberType val) {
      *this = val;
    }

    //**********************************************************************
    //                    CONSTRUCTORS: Dynamic size  
    //**********************************************************************

    // --------------------- copy constructor --------------------
    template<size_t NE2, bool enabled = is_dynamic_value> requires (enabled)
    MultiArray(const Vector<Element, NE2>& var) {
      resize(var.size());
      *this = var;
    }

    // --------------------- DYNAMIC SIZE: set size from int  ---------------------
    // need condition otherwise floats can be converted
    // can't have is_unsigned because 0 and positive ints are of type `int` by default.
    template<typename T> requires (is_dynamic_value && (std::is_integral<T>::value))
    explicit MultiArray(const T N) {
      resize(N);
    }

    // --------------------- DYNAMIC SIZE: set size from Dimensions  ---------------------

    template<bool enabled = is_dynamic_value> requires (enabled)
    explicit MultiArray(const Dimensions& dims) {
      // TRDISP(dims);
      this->resize(dims);
    }

    // --------------------- DYNAMIC SIZE: set size from RecursiveDimensions  ---------------------

    template<size_t dim_depth> requires ( is_dynamic_value && (dim_depth <= depth_value) )
    explicit MultiArray(const RecursiveDimensions& recursive_dims) {
      // TRDISP(recursive_dims);
      this->resize(recursive_dims);
    }



    // --------------------- DYNAMIC SIZE: set size = N and set all to same value  ---------------------

    template<bool enabled = is_dynamic_value> requires (enabled)
    explicit MultiArray(const size_t N, const Element val) {
      resize(N);
      *this = val;
    }

    // --------------------- array[]  CONSTRUCTOR ---------------------

    template<bool enabled = is_dynamic_value> requires (enabled)
    explicit MultiArray(const size_t N, const Element(vals)[]) {
      resize(N);
      *this = vals;
    }


    // --------------------- slice  CONSTRUCTOR ---------------------
    // N is the length that the slice is referenced to. 
    // The Vector will have size of the slice referenced to N

    template<typename T, bool enabled = is_dynamic_value> requires (enabled)
    explicit MultiArray(const size_t N, const slc<T>& s) {
      T mystart = s.start();
      if (mystart < 0) {
        mystart += N;
      }
      T myend = s.end();
      if (myend < 0) {
        myend += N;
      }

      T mystep = s.step();
      std::queue<T> indices;

      if (myend - mystart >= 0) {
        if (mystep > 0) {
          for (T k = mystart; k <= myend; k += mystep) {
            if (k < 0) continue;
            if (k >= N) break;
            indices.push(k);
          }
        }
      }
      else {
        if (mystep < 0) {
          for (T k = mystart; k >= myend; k += mystep) {
            if (k >= N) continue;
            if (k < 0)  break;
            indices.push(k);
          }
        }
      }

      const Element Nnew = indices.size();
      data_.resize(Nnew);
      for (T i = 0; i < Nnew; i++) {
        (*this)[i] = static_cast<Element>(indices.front());
        indices.pop();
      }

    }



    //**********************************************************************
    //                             DESTRUCTOR 
    //**********************************************************************

    ~MultiArray() {
    }


    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return false;
    }
    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return rank_value;
    }

    inline size_t depth(void) const {
      return depth_value;
    }

    inline size_t size(void) const {
      return data_.size();
    }

    // // the total number of numbers in this data structure
    size_t total_size(void) const {
      if constexpr (depth_value<2) {
        return this->size();
      }
      else {
        return (this->size())*(this->el_total_size());
      }
    }

    // the size of each element
    inline size_t element_size(void) const {
      if constexpr (depth_value<2) {
        return 1;
      }
      else {
        if (size() > 0) {
          return data_[0].size();
        }
        else {
          Element& x = *(new Element);
          return x.size();
        }
      }
    }

    // the total number of numbers in an element
    inline size_t el_total_size(void) const {
      if constexpr (depth_value<2) {
        return 1;
      }
      else {
        if (size() > 0) {
          return data_[0].total_size();
        }
        else {
          Element& x = *(new Element);
          return x.total_size();
        }
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    Dimensions& dims(void) const {
      return *(new Dimensions({ this->size() }));
    }

    inline std::array<size_t, rank_value> dims_array(void) const {
      if constexpr (is_dynamic_value) {
        return *(new std::array<size_t, rank_value>{ this->size() });
      } else {
        return static_dims_array;
      }
    }


    ElementDimensionsType& element_dims(void) const {
      if constexpr (depth_value>1) {
        if (this->size()>0) {
          return data_[0].dims();
        }
        else {
          Element& x = *(new Element);
          return x.dims();
        }
      }
      return *(new ElementDimensionsType{});
    }


    RecursiveDimensions& recursive_dims(void) const {
      RecursiveDimensions& rdims = *(new RecursiveDimensions(depth_value));
      this->recurse_dims(rdims, 0);
      return rdims;
    }

    const Type& recurse_dims(RecursiveDimensions& parent_rdims, const size_t di = 0) const {
      size_t depth_index = di;
      parent_rdims[depth_index++] = dims();
      if constexpr (depth_value>1) {
        if (size() > 0) {
          data_[0].recurse_dims(parent_rdims, depth_index);
        }
        else {
          Element& x = *(new Element);
          x.recurse_dims(parent_rdims, depth_index);
        }
      }
      return *this;
    }


    //**********************************************************************
    //                          Resize
    //**********************************************************************

    Type& resize(const size_t N) {
      if constexpr (is_dynamic_value) {
        if (N != this->size()) {
          data_.resize(N);
        }
      }
      return *this;
    }

    Type& resize(const Dimensions& new_dims) {
      return resize(new_dims[0]);
    }

    // new_rdims.size() <= depth_value
    Type& resize(const RecursiveDimensions& new_rdims) {
      return recurse_resize(new_rdims);
    }

    // helper functions
    Type& recurse_resize(const RecursiveDimensions& parent_rdims, size_t di = 0) {
      size_t depth_index = di;
      size_t resize_depth = parent_rdims.size();
      const size_t newSize = parent_rdims[depth_index++];
      if constexpr (is_dynamic_value) {
        resize(newSize);
      }
      if constexpr (depth_value >= 1) {
        if (depth_index < resize_depth) {
          for (size_t ii = 0; ii < size(); ii++) {
            data_[ii].recurse_resize(parent_rdims, depth_index);
          }
        }
      }
      return *this;
    }



    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- dataobj() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& data_obj() {
      return data_;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    Element* data() {
      if constexpr (is_dynamic_value) {
        // valarray<Element>
        return &(data_[0]);
      }
      else {
        // array<Element>
        return data_.data();
      }
    }

    //**********************************************************************
    //                              v(n) - tensor access
    //**********************************************************************

    // "read/write"
    Element& operator()(const size_t n) {
      return data_[n];
    }

    // "read only"
    const Element& operator()(const size_t n) const {
      return data_[n];
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [total_size()] and note return type

    // "read/write"
    NumberType& dat(const size_t n) {
      using namespace::display;
      if constexpr (depth_value < 2) {
        int k = n;
        if (k < 0) {
          k += size();
        }
        return data_[k];
      }
      else {
        const int Ndeep = this->el_total_size();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return data_[j].dat(k);
      }
    }

    // read
    const NumberType& dat(const size_t n)  const {
      using namespace::display;
      if constexpr (depth_value < 2) {
        int k = n;
        if (k < 0) {
          k += size();
        }
        return data_[k];
      }
      else {
        const int Ndeep = this->el_total_size();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return data_[j].dat(k);
      }
    }


    //**********************************************************************
    //************* Array-style Element Access: v[n] ***********************
    //**********************************************************************

    // "read/write"
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
    Element& operator[](const T n) {
      return data_[n];
    }

    // read
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
    const Element& operator[](const T n)  const {
      return data_[n];
    }

    // NOTE: if you feed literals, the following will be called, unless you use the `u` suffix, eg `10000u`
    // "read/write"
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
    Element& operator[](const T n) {
      T m = signed_index_to_unsigned_index(n, size());
      return data_[m];
    }

    // read
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
    const Element& operator[](const T n)  const {
      
      T m = signed_index_to_unsigned_index(n, size());
      return data_[m];
    }


    //**********************************************************************
    //************************** v[Indices] ***********************************
    //**********************************************************************


    // "read/write"
    Element& operator[](const Indices& inds) {
      return data_[inds[0]];
    }

    // "read only"
    const Element& operator[](const Indices& inds)  const {
      return data_[inds[0]];
    }

    // -------------------------------------------------------------
    //                        [DeepIndices] 
    // -------------------------------------------------------------

    // "read/write"
    NumberType& operator[](const DeepIndices& dinds) {
      const size_t mydepth = dinds.size();
      size_t n = dinds[mydepth - depth_value][0];

      if constexpr (depth_value > 1) {
        return (*this)[n][dinds];
      }
      else {
        return (*this)[n];
      }
    }

    // "read"
    const NumberType& operator[](const DeepIndices& dinds) const {
      const size_t mydepth = dinds.size();
      size_t n = dinds[mydepth - depth_value][0];

      if constexpr (depth_value > 1) {
        return (*this)[n][dinds];
      }
      else {
        return (*this)[n];
      }
    }


    //**********************************************************************
    //                          subset: v[Vector]      
    //**********************************************************************

    // Accessing a SET of values using a vector of ints

    ExpressionRW_Subset<Element> operator[](const Vector<size_t>& ii) {
      return ExpressionRW_Subset<Element>(*this, ii);
    }
    const ExpressionRW_Subset<Element> operator[](const Vector<size_t>& ii) const {
      return ExpressionRW_Subset<Element>(*this, ii);
    }


    //**********************************************************************
    //                              V[mask]
    //**********************************************************************


    // Accessing a SET of values using a MASK

    ExpressionRW_Submask<Element> operator[](const Vector<bool>& mask) {
      return  ExpressionRW_Submask<Element>(*this, mask);
    }
    const ExpressionRW_Submask<Element> operator[](const Vector<bool>& mask)  const {
      return  ExpressionRW_Submask<Element>(*this, mask);
    }


    //Accessing a SET of values using a list

    ExpressionRW_Subset<Element> operator[](const std::initializer_list<size_t>& list) {
      return  ExpressionRW_Subset<Element>(*this, list);
    }
    const ExpressionRW_Subset<Element> operator[](const std::initializer_list<size_t>& list) const {
      return  ExpressionRW_Subset<Element>(*this, list);
    }


    //**********************************************************************
    //                              v[slice]
    //**********************************************************************

    // Accessing a slice of values
    template <typename T>
    ExpressionRW_Subset<Element> operator[](const slc<T>& slice) {
      Vector<size_t>& ii = *(new Vector<size_t>(size(), slice));
      return ExpressionRW_Subset<Element>(*this, ii);
    }

    template <typename T>
    const ExpressionRW_Subset<Element> operator[](const slc<T>& slice) const {
      Vector<size_t>& ii = *(new Vector<size_t>(size(), slice));
      return ExpressionRW_Subset<Element>(*this, ii);
    }



    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to ExpressionRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    Type& operator=(const Element& e) {
      for (size_t i = 0; i < size(); i++) {
        (*this)[i] = e;
      }
      return *this;
    }

    // set bottom elements to same value
    template <class T = Element>
    typename std::enable_if<!std::is_same<T, NumberType>::value, Vector<T, N1>& >::type operator=(const NumberType& d) {
      for (size_t i = 0; i < total_size(); i++) {
        (*this).dat(i) = d;
      }
      return *this;
    }




    // ------------------------ Vector = Vector----------------

    template <int NE2>
    Type& operator=(const Vector<Element, NE2>& v) {
      if constexpr (depth_value <= 1) {
        if constexpr (is_dynamic_value) {
          if (this->size() != v.size()) {
            resize(v.size());
          }
        }
        for (size_t i = 0; i < size(); i++) {
          (*this)[i] = v[i];
        }
      }
      else {
        if constexpr (is_dynamic_value) {
          resize(v.recursive_dims());
        }
        for (size_t i = 0; i < total_size(); i++) {
          this->dat(i) = v.dat(i);
        }
      }
      return *this;
    }


    // // ------------------------ Vector = ExpressionR ----------------

    template <class X>
    Type& operator=(const ExpressionR<X, Element, NumberType, depth_value, rank_value>& x) {

      if constexpr (depth_value <= 1) {
        if constexpr (is_dynamic_value) {
          if (this->size() != x.size()) {
            resize(x.size());
          }
        }
        for (size_t i = 0; i < size(); i++) {
          (*this)[i] = x[i];
        }
      }
      else {
        resize(x.recursive_dims());
        for (size_t i = 0; i < total_size(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }



    // ------------------------ Vector = array[] ----------------

    Type& operator=(const Element array[]) {
      for (size_t i = 0; i < size(); i++) {
        (*this)(i) = array[i];
      }
      return *this;
    }


    // ------------------------ Vector = list ----------------

    Type& operator=(const std::list<Element>& mylist) {
      if constexpr (is_dynamic_value) {
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

    Type& operator=(const std::initializer_list<Element>& mylist) {
      if constexpr (is_dynamic_value) {
        resize(mylist.size());
      }

      size_t k = 0;
      typename std::initializer_list<Element>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it, k++) {
        data_[k] = *it;
      }

      return *this;
    }


    // ------------------------ Vector = std::vector ----------------

    Type& operator=(const std::vector<Element>& vstd) {
      if constexpr (is_dynamic_value) {
        if (this->size() != vstd.size()) {
          resize(vstd.size());
        }
      }
      for (size_t i = 0; i < size(); i++)
        (*this)(i) = vstd[i];
      return *this;
    }


    // ------------------------ Vector = std::array ----------------

    template <size_t N>
    Type& operator=(const std::array<NumberType, N>& varray) {
      if constexpr (is_dynamic_value) {
        if (this->size() != varray.size()) {
          resize(varray.size());
        }
      }

      for (size_t i = 0; i < size(); i++)
        (*this)(i) = varray[i];

      return *this;
    }


    // ------------------------ Vector = std::valarray ----------------

    Type& operator=(const std::valarray<Element>& varray) {

      if constexpr (is_dynamic_value) {
        if (this->size() != varray.size()) {
          resize(varray.size());
        }
      }

      for (size_t i = 0; i < size(); i++)
        (*this)(i) = varray[i];

      return *this;
    }








    //**********************************************************************
    //***************** in-place modification*******************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------

    Type& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
      for (size_t i = 0; i < size(); i++) {
        data_[i] = mathq::roundzero(data_[i], tolerance);
      }
      return *this;
    }


    //----------------- .conj() ---------------------------

    template<typename T = NumberType> EnableMethodIf<is_complex<T>::value, Vector<T>&>
    conj() {
      using std::conj;
      for (size_t i = 0; i < size(); i++) {
        data_[i] = conj(data_[i]);
      }
      return *this;
    }

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
    //         returns a new vector with the preserved indices
    template<typename T = size_t> EnableMethodIf<is_dynamic_value, Vector<T>& >
    quniq() {

      const size_t N = size();

      if (N==0)
        return *(new Vector<size_t>());

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
    //         returns a new vector with the preserved indices
    template<typename T = size_t> EnableMethodIf<is_dynamic_value, Vector<T>& >
    uniq() {

      const size_t N = size();

      if (N==0)
        return *(new Vector<size_t>(0u));

      std::map<size_t, NumberType> mymap;
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
      for (typename std::map<size_t, NumberType>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        indexvec(k) = it->first;
        data_[k++] = it->second;
      }

      return indexvec;
    }


    Type& reverse() {
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

    Type& cumsum() {
      const size_t N = size();
      Element sum = 0;
      for (size_t i = 0; i < N; i++) {
        sum += data_[i];
        data_[i] = sum;
      }
      return *this;
    }

    // .cumprod()  --  cumulative product

    Type& cumprod() {
      const size_t N = size();
      Element prod = 1;
      for (size_t i = 0; i < N; i++) {
        prod *= data_[i];
        data_[i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation

    Type& cumtrapz() {
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
    Type& integrate_a2x(const Element a, const Element b, const int order = 1) {

      const size_t N = size();

      if (order == 0) {
        this->cumsum();
        const Element dx = (b-a)/NumberType(N);
        for (size_t i = 0; i < N; i++) {
          data_[i] *= dx;
        }
      }
      else if (order == 1) {
        this->cumtrapz();
        const Element dx = (b-a)/NumberType(N-1);
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

    Type& cumsum_rev() {
      const size_t N = size();

      Element sum = 0;
      for (size_t i = 0; i < N; i++) {
        sum += data_[N-1-i];
        data_[N-1-i] = sum;
      }
      return *this;
    }

    // .cumprodrev()  --  cumulative product  -- from last to first

    Type& cumprod_rev() {
      const size_t N = size();

      Element prod = 1;
      for (size_t i = 0; i < N; i++) {
        prod *= data_[N-1-i];
        data_[N-1-i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation -- from last to first

    Type& cumtrapz_rev() {
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
    Type& integrate_x2b(const Element a, const Element b, const int order = 1) {
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
    Type& diff(const bool periodic = false) {
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
    Type& diff_rev(const bool periodic = false) {
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

    Type& deriv(const Element a, const Element b, const int n = 1, int Dpts = 7, const bool periodic = false) {
      //MDISP(a,b,n,Dpts,periodic);
      const size_t N = size();
      if (N<=1) return *this;

      const Element dx = (b-a)/NumberType(N-1);

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

    // instance classname() method 

    inline std::string classname() const {
      return ClassName();
    }

    // static ClassName() method 

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "Vector";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      if constexpr (!is_dynamic_value) {
        s += StyledString::get(COMMA).get();
        s += "N1=";
        s += std::to_string(N1);
      }
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif


    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Type& v) {
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


    friend inline std::istream& operator>>(const std::string s, Type& x) {
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, Type& x) {
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


    //**********************************************************************
    //                      CONVERSION OPERATORS 
    // use to dynamic_cast a Vector to another type of container
    //**********************************************************************

    operator Element* () const {
      const size_t N = size();
      Element* ptr = new Element[N];
      for (size_t i = 0; i<N; i++) {
        ptr[i] = (*this)[i];
      }
      return ptr;
    }


    // std::list()

    operator std::list<Element>() const {
      const size_t N = size();
      std::list<Element> y(N);
      for (size_t i = 0; i<N; i++) {
        y.push_back();
      }
      return y;
    }


    // std::vector()

    operator std::vector<Element>() const {
      const size_t N = size();
      std::vector<Element> y(N);
      for (size_t i = 0; i<N; i++) {
        y[i] = (*this)[i];
      }
      return y;
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


    // array<Element>
    template <size_t NE2>
    operator std::array<Element, NE2>() const {
      const size_t N = size();
      std::array<Element, NE2> y(N);
      for (size_t i = 0; i<N; i++) {
        y[i] = (*this)[i];
      }
      return y;
    }

  };




};


#endif 

