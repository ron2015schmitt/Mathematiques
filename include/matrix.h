#ifndef MATHQ__MATRIX_H
#define MATHQ__MATRIX_H 1

namespace mathq {

  /********************************************************************
   * Matrix<Element>    -- variable size matrix (valarray)
   *                 Element  = type for elements
   * Matrix<Element,N1> -- fixed number of rows (valarray)
   *                 N1 = number of rows
   * Matrix<Element,N1,N2> -- fixed number of rows and cols (array)
   *                 N2 = number of cols
   *
   *                 NumberType = number type
   *                   = underlying algebraic field
   *                     ex. int, double, std::complex<double>
   *                 depth_value = tensor depth. if Element=NumberType, then depth_value=1.
   *
   ********************************************************************
   */

  template <typename Element, size_t N1 = 0, size_t N2 = 0>
  class MatrixHelper {
  public:
    constexpr static size_t rank_value = 2;
    constexpr static bool is_dynamic = (N1 == 0) || (N2 == 0);
    constexpr static bool num_compile_time_elements = N1 * N2;

    using ConcreteType = Matrix<Element, N1, N2>;
    using DimensionsType = typename std::conditional< is_dynamic, DynamicDims<rank_value, N1, N2>, FixedDims<N1, N2> >::type;

    // ---- same for all subtypes --------
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();
    using MyArrayType = typename ArrayTypeTrait<Element, num_compile_time_elements>::Type;
    using NestedDimensionsType = RecursiveDimensions<DimensionsType, ElementDimensionsType>;
    using ElementDimensionsType = typename std::conditional< (depth_value == 1), NullDims, Element::DimensionsType>::type;

    // ---- same for all subtypes --------
    using ParentType = ExpressionRW<
      ConcreteType,  // Derived
      Element,  // Element
      typename NumberTrait<Element>::Type, // Number
      depth_value,  // depth
      rank_value,  // rank
      DimensionsType, // DimensionsT
    >;
  };



  template <typename Element, size_t N1, size_t N2>
  class MultiArray<Element, 2, N1, N2> : public MatrixHelper<Element, N1, N2>::ParentType {


  public:

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************


    using Helper = MatrixHelper<Element, N1, N2>;

    // ---- same for all subtypes --------
    using ConcreteType = typename Helper::ConcreteType;
    using MyArrayType = Helper::MyArrayType;
    using DimensionsType = typename Helper::DimensionsType;
    using ElementDimensionsType = typename Helper::ElementDimensionsType;
    using NestedDimensionsType = typename Helper::NestedDimensionsType;
    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;



    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = Helper::rank_value;
    constexpr static size_t depth_value = Helper::depth_value;
    constexpr static size_t template_dimensions_value = DimensionsType;

    constexpr static bool is_dynamic() noexcept {
      return Helper::is_dynamic;
    }


  public:
    static constexpr bool resizable = (N1*N2==0) ? true : false;
    static constexpr bool resizableRows = (N1==0) ? true : false;
    static constexpr bool resizableCols = (N2==0) ? true : false;

    // if either N1 or N2 is 0, then we use valarray

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    MyArrayType data_;


  public:
    if constexpr (is_dynamic()) {
      size_t n1 = N1;
      size_t n2 = N2;
    } else {
      static constexpr size_t n1 = N1;
      static constexpr size_t n2 = N2;
    }



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    Matrix<Element, N1, N2>() {
      resize(N1, N2);
    }


    // --------------------- constant=0 CONSTRUCTOR ---------------------
    template<size_t NN = N1*N2, EnableIf<NN == 0> = 0>

    explicit Matrix<Element, N1, N2>(const size_t Nr, const size_t Nc) {
      resize(Nr, Nc);
    }


    // --------------------- constant CONSTRUCTOR ---------------------
    template<size_t NN = N1*N2, EnableIf<NN == 0> = 0>

    explicit Matrix<Element, N1, N2>(const size_t Nr, const size_t Nc, const NumberType& val) {
      resize(Nr, Nc);
      *this = val;
    }

    // --------------------- 2D array  CONSTRUCTOR ---------------------
    template<size_t NN = N1*N2, EnableIf<NN == 0> = 0>

    Matrix<Element, N1, N2>(const size_t Nr, const size_t Nc, const NumberType** vals) {
      resize(Nr, Nc);
      *this = vals;
    }

    // --------------------- Matrix(NumberType value)  ---------------------

    template<size_t NN = N1*N2, EnableIf<(NN > 0)> = 0>

    explicit Matrix<Element, N1, N2>(const Element val) {
      *this = val;
    }

    // --------------------- Matrix(NumberType value)  ---------------------

    template<size_t NN = N1*N2, EnableIf<(NN > 0)&&(depth_value>1)> = 0>

    explicit Matrix<Element, N1, N2>(const NumberType val) {
      *this = val;
    }


    // ************* C++11 initializer_list 2D CONSTRUCTOR---------------------
    Matrix<Element, N1, N2>(const std::initializer_list<std::initializer_list<Element> >& list1) {
      const int Nr = list1.size();
      const int Nc = (*(list1.begin())).size();
      resize(Nr, Nc);
      *this = list1;
    }



    Matrix<Element, N1, N2>(const std::list<std::list<Element> >& list1) {
      const int Nr = list1.size();
      const int Nc = (*(list1.begin())).size();
      resize(Nr, Nc);
      *this = list1;
    }




    // --------------------- COPY CONSTRUCTOR --------------------

    template <int N12, int N22>
    Matrix<Element, N1, N2>(const Matrix<Element, N12, N22>& m2) {
      resize(m2.Nrows(), m2.Ncols());
      *this = m2;
    }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class X>
    Matrix<Element, N1, N2>(const ExpressionR<X, Element, NumberType, depth_value, rank>& x) {
      resize(x.dims()[0], x.dims()[1]);
      *this = x;
    }


    // --------------------- 1D valarray CONSTRUCTOR ---------------------
    template<size_t NN = N1*N2, EnableIf<NN == 0> = 0>

    Matrix<Element, N1, N2>(const size_t Nr, const size_t Nc, const std::valarray<Element>& valar) {
      resize(Nr, Nc);
      *this = valar;
    }


    // --------------------- 1D array[]  CONSTRUCTOR ---------------------
    template<size_t NN = N1*N2, EnableIf<NN == 0> = 0>

    Matrix<Element, N1, N2>(const size_t Nr, const size_t Nc, const NumberType(vals)[]) {
      resize(Nr, Nc);
      *this = vals;
    }










    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Matrix<Element, N1, N2>() {
      //remove from directory
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    size_t getRank(void)  const {
      return rank;
    }


    inline size_t size(void) const {
      return data_.size();
    }
    inline size_t Nrows(void) const {
      return Nrows_;
    }
    inline size_t Ncols(void) const {
      return Ncols_;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(Nrows_, Ncols_);
      return dimensions;
    }


    bool isExpression(void) const {
      return false;
    }
    MultiArrays getEnum() const {
      return T_MATRIX;
    }

    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    Dimensions template_dims(void) const {
      Dimensions dimensions(N1, N2);
      return dimensions;
    }


    constexpr size_t depth(void) const {
      return depth_value;
    }
    Dimensions element_dims(void) const {
      Dimensions dimensions();
      if constexpr (depth_value>1) {
        if (size()>0) {
          return data_[0].dims();
        }
      }
      return *(new Dimensions());
    }

    // the size of each element
    inline size_t element_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        const size_t Nelements = this->size();
        if (Nelements==0) {
          return 0;
        }
        else {
          return data_[0].size();
        }
      }
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_t el_total_size(void) const {
      if constexpr (depth_value<2) {
        return 1;
      }
      else {
        const size_t Nelements = this->size();
        if (Nelements==0) {
          return 0;
        }
        else {
          return data_[0].total_size();
        }
      }
    }

    // the total number of numbers in this data structure
    size_t total_size(void) const {
      if constexpr (depth_value<2) {
        return this->size();
      }
      else {
        return (this->size())*(this->el_total_size());
      }
    }
    std::vector<Dimensions>& recursive_dims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return recursive_dims(ddims);
    }
    std::vector<Dimensions>& recursive_dims(std::vector<Dimensions>& parentdims) const {
      parentdims.push_back(dims());
      if constexpr (depth_value>1) {
        if (size()>0) {
          data_[0].recursive_dims(parentdims);
        }
      }
      return parentdims;
    }




    //**********************************************************************
    //************************** RESIZE, RESHAPE, TRANSPOSE*****************
    //**********************************************************************
    // --------------------- resize() --------------------

    Matrix<Element, N1, N2>& resize(const int Nr, const int Nc) {
      Nrows_ = N1;
      Ncols_ = N2;
      if constexpr (resizableRows) {
        Nrows_ = Nr;
      }
      if constexpr (resizableCols) {
        Ncols_ = Nc;
      }
      if constexpr (resizable) {
        data_.resize(Nrows_*Ncols_);
      }
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    Matrix<Element, N1, N2>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }


    // TODO: should just pass an index and make recursive_dims const

    Matrix<Element, N1, N2>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> recursive_dims(deepdims_new);
      Dimensions newdims = recursive_dims[0];
      resize(newdims);
      if constexpr (depth_value>1) {
        recursive_dims.erase(recursive_dims.begin());
        for (size_t i = 0; i < size(); i++) {
          std::vector<Dimensions> ddims(recursive_dims);
          data_[i].resize(ddims);
        }
      }


      return *this;
    }



    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    Matrix<Element, N1, N2>& reshape(const size_t nr, const size_t nc) {
      const size_t nn = nr*nc;
      if (nn==size()) {
        if (nn == 0) {
          Nrows_ = 0;
          Ncols_ = 0;
        }
        else {
          Nrows_ = nr;
          Ncols_ = nc;
        }
      }
      return *this;
    }

    // -------------------------- .reshape(N) --------------------------------
    // morph into a vector, pillaging this object of its data store.
    //
    Vector<Element>& reshape(const size_t N) {
      // TODO: check that N==size()
      // rob the data_
      Vector<Element> m = new Vector<Element>(N, this->data_);
      this->data_ = new std::valarray<Element>(0);
      // return the new Matrix, while we live on at zero size...
      return *m;
    }

    // -------------------------- transpose() --------------------------------
    // In-place transpose. 
    // 1) For square matrices this operation is quick and easy.
    // 2) For non-square matrices, this changes the shape and operation is time-consuming
    //    Note: Transpose function is much quicker. only use this for when memory is critical
    Matrix<Element, N1, N2>& transpose(void) {
      const size_t Nr = Nrows_;
      const size_t Nc = Ncols_;
      const size_t N = size();
      const size_t Nminus1 = N-1;

      // square matrix  
      if (Nc == Nr) {
        size_t r, c;
        NumberType temp;
        for (r = 0; r < Nr; ++r)
          for (c = r + 1; c < Nr; ++c) {
            temp = (*this)[r + c * Nr];
            (*this)[r + c * Nr] = (*this)[c + r * Nr];
            (*this)[c + r * Nr] = temp;
          }
        return *this;
      }

      reshape(Nc, Nr);

      // for "vectors" 
      if (Nc == 1 || Nr==1) {
        return *this;
      }

      // boolean array to make searching faster
      // can set Nmove=1, but this will be very slow
      // Nmove=(Nr+Nc)/2 is optimal
      const bool Nmove = (Nr+Nc)/2;
      size_t move[Nmove];
      for (size_t i = 0; i < Nmove; ++i)
        move[i] = false;


      // there are always at least 2 fixed points (at j=0 and j=Nminus1)
      size_t count = 2;
      // find the rest of the fixed points
      if (Nc >= 3 && Nr >= 3)
        count += gcd(Nc - 1, Nr - 1) - 1;	/* # fixed points */

      size_t jstart = 1;
      size_t magicnum = Nc;

      while (1) {
        size_t jnext, jnextc;
        size_t jstartC = Nminus1 - jstart;
        size_t j = jstart;
        size_t jC = jstartC;
        NumberType dstart = (*this)[jstart];
        NumberType dstartC = (*this)[jstartC];

        // PROCESS THE CURRENT SEQUENcE AND ITS COMPLIMENTARY SEQUENcE
        while (1) {
          jnext = Nc * j - Nminus1 * (j / Nr);
          jnextc = Nminus1 - jnext;
          if (j < Nmove)
            move[j] = true;
          if (jC < Nmove)
            move[jC] = true;
          count += 2;
          if (jnext == jstart) {
            (*this)[j] = dstart;
            (*this)[jC] = dstartC;
            break;
          }
          if (jnext == jstartC) {
            (*this)[j] = dstartC;
            (*this)[jC] = dstart;
            break;
          }
          (*this)[j] = (*this)[jnext];
          (*this)[jC] = (*this)[jnextc];
          j = jnext;
          jC = jnextc;
        }
        // DONE PROCESSING SEQUENcE


        // CHECK TO SEE IF WE'RE FINISHED
        if (count >= N)
          break;

        // FIND THE START OF THE NEXT SEQUENcE
        while (1) {
          // skip fixed points (jstart==magicnum)
          do {
            jstart++;
            if ((magicnum += Nc)>Nminus1)
              magicnum -= Nminus1;
          } while (jstart==magicnum);

          jnext = magicnum;
          const  size_t max = Nminus1-jstart+1;
          if (jstart < Nmove) {
            if (!move[jstart])
              break;
          }
          else {
            // this while loop is needed to cull out previously 
            // processed slcuences
            while (jnext > jstart && jnext < max) {
              j = jnext;
              jnext = Nc * j - Nminus1 * (j / Nr);
            }
          }
          if (jnext == jstart)
            break;
        }
        // WE HAVE FOUND START OF THE NEXT SEQUENcE

      }
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = NumberType >
    typename std::enable_if<is_complex<T>{}, Matrix<T>& >::type adjoint() {
      this->conj();
      this->transpose();
      return *this;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [total_size()] and note return type

    // "read/write"
    NumberType& dat(const size_t n) {
      using namespace::display;
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #1")<<std::endl;
      if constexpr (depth_value<=1) {
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
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #2")<<std::endl;
      if constexpr (depth_value<=1) {
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

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------


    // "read/write": x.dat(Indices)
    NumberType& dat(const Indices& inds) {
      Indices inds_next(inds);
      //MOUT << "Matrix: "<<std::endl;
      // error if (inds.size() != sum recursive_dims[i].rank)
      size_t n = inds_next[0];
      inds_next.erase(inds_next.begin());
      size_t m = inds_next[0];
      inds_next.erase(inds_next.begin());
      //MOUT << "  ";
      //MDISP(n,m); 
      //MOUT << "  ";
      //TLDISP(inds_next);

      if constexpr (depth_value>1) {
        return (*this)(n, m).dat(inds_next);
      }
      else {
        return (*this)(n, m);
      }
    }

    // "read": x.dat(Indices)
    const NumberType dat(const Indices& inds)  const {
      Indices inds_next(inds);
      // error if (inds.size() != sum recursive_dims[i].rank)
      size_t n = inds_next[0];
      inds_next.erase(inds_next.begin());
      size_t m = inds_next[0];
      inds_next.erase(inds_next.begin());
      if constexpr (depth_value>1) {
        return (*this)(n, m).dat(inds_next);
      }
      else {
        return (*this)(n, m);
      }
    }


    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------

    // "read/write": x.dat(DeepIndices)
    NumberType& dat(const DeepIndices& dinds) {
      const size_t mydepth = dinds.size();
      const Indices& inds = dinds[mydepth -depth_value];
      size_t n = inds[0];
      size_t m = inds[1];

      if constexpr (depth_value>1) {
        return (*this)(n, m).dat(dinds);
      }
      else {
        return (*this)(n, m);
      }
    }

    // "read": x.dat(DeepIndices)
    const NumberType dat(const DeepIndices& dinds)  const {
      const size_t mydepth = dinds.size();
      const Indices& inds = dinds[mydepth -depth_value];
      size_t n = inds[0];
      size_t m = inds[1];

      if constexpr (depth_value>1) {
        return (*this)(n, m).dat(dinds);
      }
      else {
        return (*this)(n, m);
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



    // matrix[slice]

    ExpressionRW_Subset<Element> operator[](const slc& slice) {
      return (*this)[slice.toIndexVector(size())];
    }
    const ExpressionRW_Subset<Element>  operator[](const slc& slice) const {
      return (*this)[slice.toIndexVector(size())];
    }



    // matrix[Vector<size_t>]

    ExpressionRW_Subset<Element> operator[](const Vector<size_t>& ii) {
      return ExpressionRW_Subset<Element>(*this, ii);
    }
    const ExpressionRW_Subset<Element> operator[](const Vector<size_t>& ii) const {
      return ExpressionRW_Subset<Element>(*this, ii);
    }




    // matrix[mask]

    ExpressionRW_Submask<Element> operator[](const Matrix<bool>& mask) {
      return  ExpressionRW_Submask<Element>(*this, mask);
    }
    const ExpressionRW_Submask<Element> operator[](const Matrix<bool>& mask)  const {
      return  ExpressionRW_Submask<Element>(*this, mask);
    }



    // matrix[initializer_list]

    ExpressionRW_Subset<Element> operator[](const std::initializer_list<size_t>& list) {
      return  ExpressionRW_Subset<Element>(*this, list);
    }
    const ExpressionRW_Subset<Element> operator[](const std::initializer_list<size_t>& list) const {
      return  ExpressionRW_Subset<Element>(*this, list);
    }


    //**********************************************************************
    //***************MultiArray-style Element Access: A(r,c) *********************
    //**********************************************************************

    // --------------------------- index(r,c) -----------------------------

    size_t index(const size_t r, const size_t c) const {
      //TODO: bounds check
      return c + Ncols_*r; // row major
    }

    // --------------------------- indices(k) -----------------------------

    // This is the inverse of the above function
    Indices& indices(const size_t k) const {
      // NOTE: a divide is between 6 to 40 times more costly than a multiply
      //       https://stackoverflow.com/questions/4125033/floating-point-division-vs-floating-point-multiplication
      //       So avoid using this whenever possible
      //       simplest way to calc is (k/Ncols_, k%Ncols_)
      //       but the following guarantees that the compution is done efficently
      //TODO: bounds check
      Indices& myinds = *(new Indices(2));
      myinds[0] = k/Ncols_;      // row
      myinds[1] = k - Ncols_*myinds[0];  // column
      return myinds;
    }

    //**********************************************************************
    //************************** access (r,c) ***********************************
    //**********************************************************************


    // ----------------- matrix(r,c) ----------------
    Element& operator()(const size_t r, const size_t c) {
      return data_[index(r, c)];
    }
    const Element operator()(const size_t r, const size_t c) const {
      return data_[index(r, c)];
    }

    // TODO: slices etc.



    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to ExpressionRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // ----------------- matrix = e ----------------
    Matrix<Element, N1, N2>&
      operator=(const Element& e) {
      for (size_t i = 0; i < size(); i++) {
        data_[i] = e;
      }
      return *this;
    }

    // ----------------- matrix = d ----------------
    template <class T = Element>
    typename std::enable_if<!std::is_same<T, NumberType>::value, Matrix<Element, N1, N2>& >::type operator=(const NumberType& d) {

      for (size_t i = 0; i < total_size(); i++) {
        data_.dat(i) = d;
      }
      return *this;
    }

    // ----------------------Matrix = Matrix<Element,N12,N22,NumberType,depth_value> ----------------

    template<int N12, int N22>
    Matrix<Element, N1, N2>& operator=(const Matrix<Element, N12, N22>& m) {
      if constexpr (depth_value<=1) {
        TLDISP(m.dims());
        resize(m.dims());
        for (size_t i = 0; i < size(); i++) {
          (*this)[i] = m[i];
        }
      }
      else {
        resize(m.recursive_dims());
        for (size_t i = 0; i < total_size(); i++) {
          this->dat(i) = m.dat(i);
        }
      }
      return *this;
    }


    // ----------------- matrix = ExpressionR<X,Element,NumberType,depth_value,rank> ----------------
    template <class X> Matrix<Element, N1, N2>&
      operator=(const ExpressionR<X, Element, NumberType, depth_value, rank>& x) {

      if constexpr (depth_value<=1) {
        resize(x.dims());
        // TODO: use (r,c) instead
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




    // ----------------- matrix = NumberType[][] ----------------
    Matrix<Element, N1, N2>&
      operator=(const Element** array) {
      size_t k = 0;
      for (size_t r = 0; r < Nrows_; r++) {
        for (size_t c = 0; c < Ncols_; c++) {
          (*this)[k++] = array[r][c];
        }
      }
      return *this;
    }




    // ----------------- matrix = initializer_list<initializer_list>  ----------------
    Matrix<Element, N1, N2>&
      operator=(const std::initializer_list<std::initializer_list<Element> >& mylist) {
      const int Nr = mylist.size();
      const int Nc = (*(mylist.begin())).size();
      resize(Nr, Nc);
      // TODO: size check
      size_t i = 0;
      typename std::initializer_list<std::initializer_list<Element> >::iterator itR;
      for (itR = mylist.begin(); itR != mylist.end(); ++itR) {
        const std::initializer_list<Element>& row = *itR;
        // TODO: check that each row has same # cols
        typename std::initializer_list<Element>::iterator itC;
        for (itC = row.begin(); itC != row.end(); ++itC) {
          (*this)[i++] = *itC;
        }
      }

      return *this;
    }

    //*********************************************************
    //                   1D assignment
    //********************************************************

    // ------------------------ matrix = valarray[] ----------------

    Matrix<Element, N1, N2>& operator=(const std::valarray<Element>& valar) {
      for (size_t i = 0; i < size(); i++) {
        (*this)[i] = valar[i];
      }
      return *this;
    }

    // ------------------------ matrix = array[] ----------------
    Matrix<Element, N1, N2>&
      operator=(const Element array1[]) {
      for (size_t i = 0; i < size(); i++) {
        (*this)[i] = array1[i];
      }
      return *this;
    }


    // --------------- matrix = initializer_list ------------------
    Matrix<Element, N1, N2>&
      operator=(const std::initializer_list<Element>& mylist) {

      // TODO: bound scheck 
      size_t i = 0;
      typename std::initializer_list<Element>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)[i++] = *it;
      }

      return *this;
    }




    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- dataobj() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& dataobj() {
      return data_;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    Element* data() {
      if constexpr ((N1 == 0) && (N2 == 0)) {
        // valarray<Element>
        return &(data_[0]);
      }
      else {
        // array<Element>
        return data_.data();
      }
    }


    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    Matrix<Element, N1, N2>& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
      for (size_t i = 0; i < size(); i++) {
        data_[i] = mathq::roundzero(data_[i], tolerance);
      }
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = NumberType >
    typename std::enable_if<is_complex<T>{}, Matrix<T>& >::type conj() {
      for (size_t i = 0; i < size(); i++) {
        data_[i] = std::conj(data_[i]);
      }
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "Matrix";
      s += StyledString::get(ANGLE1).get();
      Element e;
      s += getTypeName(e);
      if (N1!=0) {
        s += StyledString::get(COMMA).get();
        s += "N1=";
        s += num2string(N1);
      }
      if (N2!=0) {
        s += StyledString::get(COMMA).get();
        s += "N2=";
        s += num2string(N2);
      }
      //    if (depth_value>1) {
      //      s += StyledString::get(COMMA).get();
      //      s += "depth_value=";
      //      s += num2string(depth_value);
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


    friend std::ostream& operator<<(std::ostream& stream, const Matrix<Element, N1, N2>& m) {
      using namespace display;

      Style& style = FormatDataMatrix::style_for_punctuation;
      stream << style.apply(FormatDataMatrix::string_opening);
      const size_t N = FormatDataMatrix::max_elements_per_line;

      for (size_t r = 0; r < m.Nrows(); r++) {
        stream << style.apply(FormatDataMatrix::string_row_opening);
        size_t k = 0;
        for (size_t c = 0; c < m.Ncols(); c++, k++) {
          if (k >= N) {
            stream << style.apply(FormatDataMatrix::string_endofline);
            k = 0;
          }
          dispval_strm(stream, m(r, c));
          if (c < m.Ncols()-1) {
            stream << style.apply(FormatDataMatrix::string_delimeter);
          }
          else {
            if (r < m.Nrows()-1) {
              stream << style.apply(FormatDataMatrix::string_row_closing);
            }
            else {
              stream << style.apply(FormatDataMatrix::string_lastrow_closing);
            }
          }
        }
      }
      stream << style.apply(FormatDataMatrix::string_closing);

      return stream;
    }


    //template <typename NumberType>	
    friend inline std::istream& operator>>(const std::string s, Matrix<Element, N1, N2>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, Matrix<Element, N1, N2>& m2) {
      return stream;
    }




  };




};


#endif 

