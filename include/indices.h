#ifndef MATHQ__INDICES_H
#define MATHQ__INDICES_H 1



namespace mathq {


  class Indices : public std::vector<size_t> {
  private:
  public:
    typedef typename std::vector<size_t> Parent;
    typedef typename Parent::iterator Iterator;

    //**********************************************************************
    //                         Static methods
    //
    //**********************************************************************

    // static size_t index(const mathq::Indices& inds, const Dimensions& dims) {
    //   const size_t rank = dims.size();
    //   size_t k = 0;
    //   for (size_t n = 0; n < rank; n++) {
    //     size_t N = dims[n];
    //     size_t j = inds[n];
    //     k = N*k + j;
    //   }
    //   return k;
    // }

    // static mathq::Indices& indices(const size_t k, const Dimensions& dims) {
    //   const size_t rank = dims.size();
    //   mathq::Indices& myinds = *(new mathq::Indices(rank));
    //   size_t prev = k;
    //   // This loop must go in reverse order.  Do NOT change.
    //   for (size_t n = rank-1; n > 0; n--) {
    //     size_t N = dims[n];
    //     size_t temp = prev/N;
    //     myinds[n] = prev - N*temp;
    //     prev = temp;
    //   }
    //   if (rank>0) {
    //     myinds[0] = prev;
    //   }
    //   return myinds;
    // }

    static mathq::Indices& indices(const size_t k, const Dimensions& dims) {
      const size_t rank = dims.size();
      mathq::Indices& myinds = *(new mathq::Indices(k, dims));
      return myinds;
    }



    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************

    Indices() {
      this->resize(0);
    }

    Indices(const size_t N) {
      this->resize(N);
    }

    Indices(const size_t k, const Dimensions& dims) {
      const size_t rank = dims.size();
      this->resize(rank);
      size_t prev = k;
      // This loop must go in reverse order.  Do NOT change.
      for (size_t n = rank-1; n > 0; n--) {
        size_t N = dims[n];
        size_t temp = prev/N;
        (*this)[n] = prev - N*temp;
        prev = temp;
      }
      if (rank > 0) {
        (*this)[0] = prev;
      }
    }

    Indices(const Indices& var) {
      *this = var;
    }

    Indices(const std::vector<size_t>& var) {
      *this = var;
    }

    Indices(const std::valarray<size_t>& var) {
      *this = var;
    }

    template <size_t rank2>
    Indices(const std::array<size_t, rank2>& var) {
      *this = var;
    }

    Indices(const std::initializer_list<size_t>& var) {
      *this = var;
    }



    size_t index(const Dimensions& dims) const {
      const size_t rank = dims.size();
      size_t k = 0;
      for (size_t n = 0; n < rank; n++) {
        size_t N = dims[n];
        size_t j = (*this)[n];
        k = N*k + j;
      }
      return k;
    }


    bool operator==(const Indices& var) const {
      if (size() != var.size()) return false;
      for (size_t i = 0; i < this->size(); i++) {
        if ((*this)[i] != var[i]) {
          return false;
        }
      }
      return true;
    }

    bool equiv(const Indices& inds) const {
      return (*this == inds);
    }

    size_t rank() const {
      return size();
    }

    Indices& reverse() {
      // reverse order
      size_t k = size()-1;
      for (size_t ii = 0; ii < this->size()/2; ii++, k--) {
        size_t temp = (*this)[ii];
        (*this)[ii] = (*this)[k];
        (*this)[k] = temp;
      }
      return *this;
    }

    Indices& getReverse() const {
      Indices& dd = *(new Indices(*this));
      return dd.reverse();
    }

    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************

    Indices& operator=(const Indices& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    Indices& operator=(const std::vector<size_t>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    Indices& operator=(const std::valarray<size_t>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    template <size_t rank2>
    Indices& operator=(const std::array<size_t, rank2>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    Indices& operator=(const std::initializer_list<size_t>& ilist) {
      this->resize(ilist.size());
      size_t k = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        (*this)[k] = *it;
      }
      return *this;
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string classname() const {
      return "Indices";
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const Indices& inds) {
      using namespace display;

      stream << "{";
      for (size_t ii = 0; ii < inds.size(); ii++) {
        if (ii>0)  stream << ", ";
        dispval_strm(stream, inds[ii]);
      }
      stream << "}";

      return stream;
    }




  };


  inline bool equiv(const Indices& inds1, const Indices& inds2) {
    return inds1.equiv(inds2);
  }


  // -------------------------------------------------------------------
  //
  // Deepindices - class to full indices of nested MultiArrays
  // -------------------------------------------------------------------

  class DeepIndices : public std::vector<Indices> {

  public:
    using Parent = std::vector<Indices>;


    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************

    DeepIndices() {
      this->resize(0);
    }

    DeepIndices(const size_t depth) {
      this->resize(depth);
    }

    DeepIndices(const DeepIndices& var) {
      *this = var;
    }

    DeepIndices(const std::vector<size_t>& var) {
      *this = var;
    }

    DeepIndices(const std::valarray<size_t>& var) {
      *this = var;
    }

    template <size_t rank2>
    DeepIndices(const std::array<size_t, rank2>& var) {
      *this = var;
    }

    DeepIndices(const std::initializer_list<size_t>& var) {
      *this = var;
    }


    DeepIndices(const std::initializer_list<Indices>& var) {
      *this = var;
    }

    DeepIndices(const std::initializer_list<std::initializer_list<size_t>>& var) {
      *this = var;
    }




    DeepIndices& reverse_each() {
      for (size_t d = 0; d < size(); d++) {
        (*this)[d].reverse();
      }
      return*this;
    }

    DeepIndices& getReverseEach() {
      DeepIndices& dd = *(new DeepIndices(*this));
      return dd.reverse_each();
    }

  // this used to be called getReverse
    DeepIndices& evert() {
      // evert = turn inside out
      size_t k = size()-1;
      for (size_t ii = 0; ii < this->size()/2; ii++, k--) {
        Indices temp = (*this)[ii];
        (*this)[ii] = (*this)[k];
        (*this)[k] = temp;
      }
      return *this;
    }

    DeepIndices& getEverse() {
      DeepIndices& dd = *(new DeepIndices(*this));
      return dd.evert();
    }

    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************


    DeepIndices& operator=(const DeepIndices& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    DeepIndices& operator=(const std::vector<Indices>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    DeepIndices& operator=(const std::valarray<Indices>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    template <size_t rank2>
    DeepIndices& operator=(const std::array<Indices, rank2>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    DeepIndices& operator=(const std::initializer_list<Indices>& ilist) {
      this->resize(ilist.size());
      size_t k = 0;
      typename std::initializer_list<Indices>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        (*this)[k] = *it;
      }
      return *this;
    }

    DeepIndices& operator=(const std::initializer_list<std::initializer_list<size_t>>& ilist) {
      this->resize(ilist.size());
      size_t k = 0;
      typename std::initializer_list<std::initializer_list<size_t>>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        Indices d;
        d = *it;
        (*this)[k] = d;
      }
      return *this;
    }

    bool operator==(const DeepIndices& var) const {
      if (size() != var.size()) return false;
      for (size_t i = 0; i < this->size(); i++) {
        if ((*this)[i] != var[i]) {
          return false;
        }
      }
      return true;
    }

    DeepIndices& increment(RecursiveDimensions deepdims) {
      const size_t N = deepdims.size();
      size_t m = N;
      while (true) {
        if (m == 0) {
          this->clear();
          return *this;
        }
        m--;
        while ((*this)[m].size() == 0) {
          if (m == 0) {
            this->clear();
            return *this;
          }
          m--;
        }
        Dimensions& dims = deepdims[m];
        Indices& inds = (*this)[m];
        size_t n = dims.size();
        size_t d = 0;
        size_t sz = dims[n-d-1];
        size_t ind = ++(inds[n-d-1]);
        // MDISP(m, n, d, sz, ind, inds[n-d-1]);
        while (ind >= sz) {
          inds[n-d-1] = 0;
          d++;
          if (d >= n) {
            break;
          }
          sz = dims[n-d-1];
          ind = ++(inds[n-d-1]);
        }
        if (d < n) {
          return *this;
        }
      } // while true
      return *this;  // should never get here
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************


    inline std::string classname() const {
      using namespace display;
      std::string s = "DeepIndices";
      return s;
    }

    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const DeepIndices& v) {
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
        dispval_strm(stream, v[ii]);
        if (ii < v.size()-1) {
          stream << style.apply(FormatDataVector::string_delimeter);
        }
      }
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }


  };


  //*******************************************************
  //     NestedInitializerList  Type Definition
  //*******************************************************


  template<typename Element, size_t L>
  class NestedInitializerListDef {
  public:
    using type = std::initializer_list<
      typename NestedInitializerListDef<Element, L-1>::type
    >;
    template <size_t rank>
    static void compute(MultiArray<Element, rank>& t, const type& list, size_t& i) {
      for (auto nlist : list) {
        NestedInitializerListDef<Element, L-1>::compute(t, nlist, i);
      }
    }

    static Dimensions& dims(const type& list) {
      Dimensions& dims = *(new Dimensions());
      return NestedInitializerListDef::dims(list, dims);

    }
    static Dimensions& dims(const type& list, Dimensions& dims) {
      const size_t nl = list.size();
      dims.push_back(nl);
      if (nl==0) {
        return dims;
      }
      else {
        return NestedInitializerListDef<Element, L-1>::dims(*(list.begin()), dims);
      }
    }
  };

  template<typename Element>
  class NestedInitializerListDef<Element, 0> {
  public:
    using type = Element;

    template <size_t rank>
    static void compute(MultiArray<Element, rank>& t, const type& item, size_t& i) {
      //TLDISP(item);
      t[i++] = item;
    }
  };



  // Type to use NestedInitializerListDef<T,size_t>

  template<typename T, size_t T_levels>
  using NestedInitializerList = typename NestedInitializerListDef<T, T_levels>::type;



};
#endif
