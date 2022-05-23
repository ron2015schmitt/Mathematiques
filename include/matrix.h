#ifndef MATHQ__MATRIX_H
#define MATHQ__MATRIX_H 1




namespace mathq {


  /********************************************************************
   * Matrix<E>    -- variable size matrix (valarray)
   *                 E  = type for elements
   * Matrix<E,NR> -- fixed number of rows (valarray)
   *                 NR = number of rows
   * Matrix<E,NR,NC> -- fixed number of rows and cols (array)
   *                 NC = number of cols
   *
   * DO NOT SPECIFY: D,M
   *                 The defaults are defined in the declaration in
   *                 preface.h
   *                 D = number type
   *                   = underlying algebraic field
   *                     ex. int, double, std::complex<double>
   *                 M = tensor depth. if E=D, then M=1.
   *
   * ROW MAJOR CONVENTION
   ********************************************************************
   */


  template <class E, int NR, int NC, typename D, int M>
  class Matrix : public TensorRW<Matrix<E, NR, NC, D, M>, E, D, M, 2> {

  public:
    constexpr static int R = 2;
    constexpr static int Rvalue = 2;
    constexpr static int Mvalue = M;
    static constexpr bool resizable = (NR*NC==0) ? true : false;
    static constexpr bool resizableRows = (NR==0) ? true : false;
    static constexpr bool resizableCols = (NC==0) ? true : false;
    typedef Matrix<E, NR, NC, D, M> XType;
    typedef E EType;
    typedef D DType;
    typedef typename FundamentalType<D>::Type FType;


    // if either NR or NC is 0, then we use valarray
    typedef typename ArrayType<E, NR* NC>::Type MyArrayType;

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    MyArrayType data_;

    index_type Nrows_;
    index_type Ncols_;





    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    Matrix<E, NR, NC, D, M>() {
      resize(NR, NC);
    }


    // --------------------- constant=0 CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit Matrix<E, NR, NC, D, M>(const size_type Nr, const size_type Nc) {
      resize(Nr, Nc);
    }


    // --------------------- constant CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit Matrix<E, NR, NC, D, M>(const size_type Nr, const size_type Nc, const D& val) {
      resize(Nr, Nc);
      *this = val;
    }

    // --------------------- 2D array  CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    Matrix<E, NR, NC, D, M>(const size_type Nr, const size_type Nc, const D** vals) {
      resize(Nr, Nc);
      *this = vals;
    }

    // --------------------- Matrix(D value)  ---------------------

    template<size_t NN = NR*NC, EnableIf<(NN > 0)> = 0>

    explicit Matrix<E, NR, NC, D, M>(const E val) {
      *this = val;
    }


    // --------------------- Matrix(D value)  ---------------------

    template<size_t NN = NR*NC, EnableIf<(NN > 0)&&(M>1)> = 0>

    explicit Matrix<E, NR, NC, D, M>(const D val) {
      *this = val;
    }


    // ************* C++11 initializer_list 2D CONSTRUCTOR---------------------
    Matrix<E, NR, NC, D, M>(const std::initializer_list<std::initializer_list<E> >& list1) {
      const int Nr = list1.size();
      const int Nc = (*(list1.begin())).size();
      resize(Nr, Nc);
      *this = list1;
    }





    // --------------------- COPY CONSTRUCTOR --------------------

    template <int NR2, int NC2>
    Matrix<E, NR, NC, D, M>(const Matrix<E, NR2, NC2, D, M>& m2) {
      resize(m2.Nrows(), m2.Ncols());
      *this = m2;
    }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class X>
    Matrix<E, NR, NC, D, M>(const TensorR<X, E, D, M, R>& x) {
      resize(x.dims()[0], x.dims()[1]);
      *this = x;
    }


    // --------------------- 1D valarray CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    Matrix<E, NR, NC, D, M>(const size_type Nr, const size_type Nc, const std::valarray<E>& valar) {
      resize(Nr, Nc);
      *this = valar;
    }


    // --------------------- 1D array[]  CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    Matrix<E, NR, NC, D, M>(const size_type Nr, const size_type Nc, const D(vals)[]) {
      resize(Nr, Nc);
      *this = vals;
    }










    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Matrix<E, NR, NC, D, M>() {
      //remove from directory
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    size_type ndims(void)  const {
      return R;
    }


    inline size_type size(void) const {
      return data_.size();
    }
    inline size_type Nrows(void) const {
      return Nrows_;
    }
    inline size_type Ncols(void) const {
      return Ncols_;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(Nrows_, Ncols_);
      return dimensions;
    }


    bool isExpression(void) const {
      return false;
    }
    Tensors getEnum() const {
      return T_MATRIX;
    }

    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    Dimensions tdims(void) const {
      Dimensions dimensions(NR, NC);
      return dimensions;
    }


    constexpr size_type depth(void) const {
      return M;
    }
    Dimensions eldims(void) const {
      Dimensions dimensions();
      if constexpr (M>1) {
        if (size()>0) {
          return data_[0].dims();
        }
      }
      return *(new Dimensions());
    }

    // the size of each element
    inline size_type elsize(void) const {
      if constexpr (M<=1) {
        return 1;
      }
      else {
        const size_type Nelements = this->size();
        if (Nelements==0) {
          return 0;
        }
        else {
          return data_[0].size();
        }
      }
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_type eldeepsize(void) const {
      if constexpr (M<2) {
        return 1;
      }
      else {
        const size_type Nelements = this->size();
        if (Nelements==0) {
          return 0;
        }
        else {
          return data_[0].deepsize();
        }
      }
    }

    // the total number of numbers in this data structure
    size_type deepsize(void) const {
      if constexpr (M<2) {
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
      if constexpr (M>1) {
        if (size()>0) {
          data_[0].deepdims(parentdims);
        }
      }
      return parentdims;
    }




    //**********************************************************************
    //************************** RESIZE, RESHAPE, TRANSPOSE*****************
    //**********************************************************************
    // --------------------- resize() --------------------

    Matrix<E, NR, NC, D, M>& resize(const int Nr, const int Nc) {
      Nrows_ = NR;
      Ncols_ = NC;
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

    Matrix<E, NR, NC, D, M>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }


    // TODO: should just pass an index and make deepdims const

    Matrix<E, NR, NC, D, M>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> deepdims(deepdims_new);
      Dimensions newdims = deepdims[0];
      resize(newdims);
      if constexpr (M>1) {
        deepdims.erase(deepdims.begin());
        for (index_type i = 0; i < size(); i++) {
          std::vector<Dimensions> ddims(deepdims);
          data_[i].resize(ddims);
        }
      }


      return *this;
    }



    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    Matrix<E, NR, NC, D, M>& reshape(const size_type nr, const size_type nc) {
      const size_type nn = nr*nc;
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
    Vector<E>& reshape(const size_type N) {
      // TODO: check that N==size()
      // rob the data_
      Vector<E> m = new Vector<E>(N, this->data_);
      this->data_ = new std::valarray<E>(0);
      // return the new Matrix, while we live on at zero size...
      return *m;
    }

    // -------------------------- transpose() --------------------------------
    // In-place transpose. 
    // 1) For square matrices this operation is quick and easy.
    // 2) For non-square matrices, this changes the shape and operation is time-consuming
    //    Note: Transpose function is much quicker. only use this for when memory is critical
    Matrix<E, NR, NC, D, M>& transpose(void) {
      const index_type Nr = Nrows_;
      const index_type Nc = Ncols_;
      const index_type N = size();
      const index_type Nminus1 = N-1;

      // square matrix  
      if (Nc == Nr) {
        index_type r, c;
        D temp;
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
      index_type move[Nmove];
      for (index_type i = 0; i < Nmove; ++i)
        move[i] = false;


      // there are always at least 2 fixed points (at j=0 and j=Nminus1)
      index_type count = 2;
      // find the rest of the fixed points
      if (Nc >= 3 && Nr >= 3)
        count += gcd(Nc - 1, Nr - 1) - 1;	/* # fixed points */

      index_type jstart = 1;
      index_type magicnum = Nc;

      while (1) {
        index_type jnext, jnextc;
        index_type jstartC = Nminus1 - jstart;
        index_type j = jstart;
        index_type jC = jstartC;
        D dstart = (*this)[jstart];
        D dstartC = (*this)[jstartC];

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
          const  index_type max = Nminus1-jstart+1;
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

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, Matrix<T>& >::type adjoint() {
      this->conj();
      this->transpose();
      return *this;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [deepsize()] and note return type

    // "read/write"
    D& dat(const index_type n) {
      using namespace::display;
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #1")<<std::endl;
      if constexpr (M<=1) {
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
    const D& dat(const index_type n)  const {
      using namespace::display;
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #2")<<std::endl;
      if constexpr (M<=1) {
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

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------


    // "read/write": x.dat(Indices)
    D& dat(const Indices& inds) {
      Indices inds_next(inds);
      //MOUT << "Matrix: "<<std::endl;
      // error if (inds.size() != sum deepdims[i].rank)
      index_type n = inds_next[0];
      inds_next.erase(inds_next.begin());
      index_type m = inds_next[0];
      inds_next.erase(inds_next.begin());
      //MOUT << "  ";
      //MDISP(n,m); 
      //MOUT << "  ";
      //TLDISP(inds_next);

      if constexpr (M>1) {
        return (*this)(n, m).dat(inds_next);
      }
      else {
        return (*this)(n, m);
      }
    }

    // "read": x.dat(Indices)
    const D dat(const Indices& inds)  const {
      Indices inds_next(inds);
      // error if (inds.size() != sum deepdims[i].rank)
      index_type n = inds_next[0];
      inds_next.erase(inds_next.begin());
      index_type m = inds_next[0];
      inds_next.erase(inds_next.begin());
      if constexpr (M>1) {
        return (*this)(n, m).dat(inds_next);
      }
      else {
        return (*this)(n, m);
      }
    }


    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------

    // "read/write": x.dat(DeepIndices)
    D& dat(const DeepIndices& dinds) {
      const index_type depth = dinds.size();
      const Indices& inds = dinds[depth-M];
      index_type n = inds[0];
      index_type m = inds[1];

      if constexpr (M>1) {
        return (*this)(n, m).dat(dinds);
      }
      else {
        return (*this)(n, m);
      }
    }

    // "read": x.dat(DeepIndices)
    const D dat(const DeepIndices& dinds)  const {
      const index_type depth = dinds.size();
      const Indices& inds = dinds[depth-M];
      index_type n = inds[0];
      index_type m = inds[1];

      if constexpr (M>1) {
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
    E& operator[](const index_type n) {
      int k = n;
      if (k < 0) {
        k += size();
      }
      return data_[k];
    }

    // read
    const E& operator[](const index_type n)  const {
      int k = n;
      if (k < 0) {
        k += size();
      }
      return data_[k];
    }



    // matrix[slice]

    TERW_Subset<E> operator[](const slc& slice) {
      return (*this)[slice.toIndexVector(size())];
    }
    const TERW_Subset<E>  operator[](const slc& slice) const {
      return (*this)[slice.toIndexVector(size())];
    }



    // matrix[Vector<index_type>]

    TERW_Subset<E> operator[](const Vector<index_type>& ii) {
      return TERW_Subset<E>(*this, ii);
    }
    const TERW_Subset<E> operator[](const Vector<index_type>& ii) const {
      return TERW_Subset<E>(*this, ii);
    }




    // matrix[mask]

    TERW_Submask<E> operator[](const Matrix<bool>& mask) {
      return  TERW_Submask<E>(*this, mask);
    }
    const TERW_Submask<E> operator[](const Matrix<bool>& mask)  const {
      return  TERW_Submask<E>(*this, mask);
    }



    // matrix[initializer_list]

    TERW_Subset<E> operator[](const std::initializer_list<index_type>& list) {
      return  TERW_Subset<E>(*this, list);
    }
    const TERW_Subset<E> operator[](const std::initializer_list<index_type>& list) const {
      return  TERW_Subset<E>(*this, list);
    }


    //**********************************************************************
    //***************Tensor-style Element Access: A(r,c) *********************
    //**********************************************************************

    // --------------------------- index(r,c) -----------------------------

    index_type index(const index_type r, const index_type c) const {
      //TODO: bounds check
      return c + Ncols_*r; // row major
    }

    // --------------------------- indices(k) -----------------------------

    // This is the inverse of the above function
    Indices& indices(const index_type k) const {
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
    E& operator()(const index_type r, const index_type c) {
      return data_[index(r, c)];
    }
    const E operator()(const index_type r, const index_type c) const {
      return data_[index(r, c)];
    }

    // TODO: slices etc.



    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to TensorRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // ----------------- matrix = e ----------------
    Matrix<E, NR, NC, D, M>&
      operator=(const E& e) {
      for (index_type i = 0; i < size(); i++) {
        data_[i] = e;
      }
      return *this;
    }

    // ----------------- matrix = d ----------------
    template <class T = E>
    typename std::enable_if<!std::is_same<T, D>::value, Matrix<E, NR, NC, D, M>& >::type operator=(const D& d) {

      for (index_type i = 0; i < deepsize(); i++) {
        data_.dat(i) = d;
      }
      return *this;
    }

    // ----------------------Matrix = Matrix<E,NR2,NC2,D,M> ----------------

    template<int NR2, int NC2>
    Matrix<E, NR, NC, D, M>& operator=(const Matrix<E, NR2, NC2, D, M>& m) {
      if constexpr (M<=1) {
        TLDISP(m.dims());
        resize(m.dims());
        for (index_type i = 0; i < size(); i++) {
          (*this)[i] = m[i];
        }
      }
      else {
        resize(m.deepdims());
        for (index_type i = 0; i < deepsize(); i++) {
          this->dat(i) = m.dat(i);
        }
      }
      return *this;
    }


    // ----------------- matrix = TensorR<X,E,D,M,R> ----------------
    template <class X> Matrix<E, NR, NC, D, M>&
      operator=(const TensorR<X, E, D, M, R>& x) {

      if constexpr (M<=1) {
        resize(x.dims());
        // TODO: use (r,c) instead
        for (index_type i = 0; i < size(); i++) {
          (*this)[i] = x[i];
        }
      }
      else {
        resize(x.deepdims());
        for (index_type i = 0; i < deepsize(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }




    // ----------------- matrix = D[][] ----------------
    Matrix<E, NR, NC, D, M>&
      operator=(const E** array) {
      index_type k = 0;
      for (index_type r = 0; r < Nrows_; r++) {
        for (index_type c = 0; c < Ncols_; c++) {
          (*this)[k++] = array[r][c];
        }
      }
      return *this;
    }




    // ----------------- matrix = initializer_list<initializer_list>  ----------------
    Matrix<E, NR, NC, D, M>&
      operator=(const std::initializer_list<std::initializer_list<E> >& mylist) {
      const int Nr = mylist.size();
      const int Nc = (*(mylist.begin())).size();
      resize(Nr, Nc);
      // TODO: size check
      index_type i = 0;
      typename std::initializer_list<std::initializer_list<E> >::iterator itR;
      for (itR = mylist.begin(); itR != mylist.end(); ++itR) {
        const std::initializer_list<E>& row = *itR;
        // TODO: check that each row has same # cols
        typename std::initializer_list<E>::iterator itC;
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

    Matrix<E, NR, NC, D, M>& operator=(const std::valarray<E>& valar) {
      for (index_type i = 0; i < size(); i++) {
        (*this)[i] = valar[i];
      }
      return *this;
    }

    // ------------------------ matrix = array[] ----------------
    Matrix<E, NR, NC, D, M>&
      operator=(const E array1[]) {
      for (index_type i = 0; i < size(); i++) {
        (*this)[i] = array1[i];
      }
      return *this;
    }


    // --------------- matrix = initializer_list ------------------
    Matrix<E, NR, NC, D, M>&
      operator=(const std::initializer_list<E>& mylist) {

      // TODO: bound scheck 
      size_type i = 0;
      typename std::initializer_list<E>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)[i++] = *it;
      }

      return *this;
    }



    //**********************************************************************
    //************************** data_ access ***********************************
    //**********************************************************************

    // -------access to the internal data valarray --------------------

    // "read/write" to the wrapped valarray
    std::valarray<E>& getValArray() {
      return *data_;
    }
    Matrix<E, NR, NC, D, M>& setValArray(std::valarray<E>* valptr) {
      delete  data_;
      const size_t N = valptr->size();
      data_ = valptr;
      return *this;
    }

    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    Matrix<E, NR, NC, D, M>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      for (index_type i = size(); i--;) {
        data_[i] = mathq::roundzero(data_[i], tolerance);
      }
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, Matrix<T>& >::type conj() {
      for (index_type i = size(); i--;) {
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
      E e;
      s += getTypeName(e);
      if (NR!=0) {
        s += StyledString::get(COMMA).get();
        s += "NR=";
        s += num2string(NR);
      }
      if (NC!=0) {
        s += StyledString::get(COMMA).get();
        s += "NC=";
        s += num2string(NC);
      }
      //    if (M>1) {
      //      s += StyledString::get(COMMA).get();
      //      s += "M=";
      //      s += num2string(M);
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


    friend std::ostream& operator<<(std::ostream& stream, const Matrix<E, NR, NC, D, M>& m) {
      using namespace display;

      Style& style = FormatDataMatrix::style_for_punctuation;
      stream << style.apply(FormatDataMatrix::string_opening);
      const mathq::index_type N = FormatDataMatrix::max_elements_per_line;

      for (mathq::index_type r = 0; r < m.Nrows(); r++) {
        stream << style.apply(FormatDataMatrix::string_row_opening);
        mathq::index_type k = 0;
        for (mathq::index_type c = 0; c < m.Ncols(); c++, k++) {
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


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s, Matrix<E, NR, NC, D, M>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, Matrix<E, NR, NC, D, M>& m2) {
      return stream;
    }




  };




};


#endif 

