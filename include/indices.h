#ifndef MATHQ__INDICES_H
#define MATHQ__INDICES_H



namespace mathq {


  class Indices : public std::vector<size_t> {
  private:
  public:
    typedef typename std::vector<size_t> Parent;
    typedef typename Parent::iterator Iterator;


    template<size_t rank, typename Derived>
    static size_t index(const mathq::Indices& inds, const Dimensions<rank, Derived>& dims) {
      size_t k = 0;
      for (size_t n = 0; n < rank; n++) {
        size_t N = dims[n];
        size_t j = inds[n];
        k = N*k + j;
      }
      return k;
    }


    template<size_t rank, typename Derived>
    static mathq::Indices& indices(const size_t k, const Dimensions<rank, Derived>& dims) {
      mathq::Indices& myinds = *(new mathq::Indices(rank));
      size_t prev = k;
      // This loop must go in reverse order.  Do NOT change.
      for (size_t n = rank-1; n > 0; n--) {
        size_t N = dims[n];
        size_t temp = prev/N;
        myinds[n] = prev - N*temp;
        prev = temp;
      }
      if (rank>0) {
        myinds[0] = prev;
      }
      return myinds;
    }


    Indices(const Indices& inds) {
      resize(inds.size(), 0);
      for (int k = 0; k < inds.size(); k++) {
        (*this)[k] = inds[k];
      }
    }
    Indices() {
      resize(0, 0);
    }
    Indices(const size_t n) {
      resize(n, 0);
    }

    // arbitrary size. can alos use "push_back"
    Indices(const Parent& inds) {
      resize(inds.size(), 0);
      for (int k = 0; k < inds.size(); k++) {
        (*this)[k] = inds[k];
      }
    }

    Indices(const std::initializer_list<size_t> list) {
      const size_t N = list.size();
      resize(N, 0);
      size_t i = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = list.begin(); it != list.end(); ++it) {
        (*this)[i++] = *it;
      }
    }

    Indices(const std::list<size_t>& mylist) {
      const size_t N = mylist.size();
      resize(N, 0);
      size_t i = 0;
      std::list<size_t>::const_iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)[i++] = *it;
      }
    }


    bool equiv(const Indices& inds) const {
      return (*this == inds);
    }

    Indices& getReverse() const {
      Indices& revinds = *(new Indices());
      for (int k = this->size()-1; k >= 0; k--) {
        revinds.push_back((*this)[k]);
      }
      return revinds;
    }


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



  // // -------------------------------------------------------------------
  // //
  // // Deepindices - class to full indices of nested MultiArrays
  // // -------------------------------------------------------------------
  // template <typename NestedDims>
  // class DeepIndices : public NestedDims {
  // public:

  //   DeepIndices() : deepdims_(deepdims) {

  //   }


  //   DeepIndices& operator++(int dum) {
  //     const size_t N = deepdims_.size();
  //     size_t m = N;
  //     while (true) {
  //       if (m == 0) {
  //         this->clear();
  //         return *this;
  //       }
  //       m--;
  //       while ((*this)[m].size() == 0) {
  //         if (m == 0) {
  //           this->clear();
  //           return *this;
  //         }
  //         m--;
  //       }
  //       Dimensions& dims = deepdims_[m];
  //       Indices& inds = (*this)[m];
  //       size_t n = dims.size();
  //       size_t d = 0;
  //       size_t sz = dims[n-d-1];
  //       size_t ind = ++(inds[n-d-1]);
  //       // MDISP(m, n, d, sz, ind, inds[n-d-1]);
  //       while (ind >= sz) {
  //         inds[n-d-1] = 0;
  //         d++;
  //         if (d >= n) {
  //           break;
  //         }
  //         sz = dims[n-d-1];
  //         ind = ++(inds[n-d-1]);
  //       }
  //       if (d < n) {
  //         return *this;
  //       }
  //     } // while true
  //     return *this;  // should never get here
  //   }


  //   DeepIndices& getReverse() const {
  //     const size_t N = size();
  //     std::vector<Dimensions> rddims(N);
  //     for (int k = 0; k < N; k++) {
  //       rddims[k] = deepdims_[N-k-1];
  //     }
  //     DeepIndices& revinds = *(new DeepIndices(rddims));
  //     for (int k = 0; k < N; k++) {
  //       revinds[k] = (*this)[N-k-1];
  //     }
  //     return revinds;
  //   }


  //   inline friend std::ostream& operator<<(std::ostream& stream, const DeepIndices& dinds) {
  //     using namespace display;
  //     stream << "{";
  //     for (size_t ii = 0; ii < dinds.size(); ii++) {
  //       if (ii>0)  stream << ", ";
  //       dispval_strm(stream, dinds[ii]);
  //     }
  //     stream << "}";
  //     return stream;
  //   }

  //   std::string classname() const {
  //     return "DeepIndices";
  //   }
  // };


  //*******************************************************
  //     NestedInitializerList  Type Definition
  //*******************************************************


  template<typename Element, int L>
  class NestedInitializerListDef {
  public:
    using type = std::initializer_list<
      typename NestedInitializerListDef<Element, L-1>::type
    >;
    template <int rank>
    static void compute(MultiArray<Element, rank>& t, const type& list, int& i) {

      for (auto nlist : list) {
        NestedInitializerListDef<Element, L-1>::compute(t, nlist, i);
      }
    }

    // static Dimensions& dims(const type& list) {
    //   Dimensions& dims = *(new Dimensions());
    //   return NestedInitializerListDef::dims(list, dims);
    // }
    // static Dimensions& dims(const type& list, Dimensions& dims) {
    //   const int nl = list.size();
    //   dims.push_back(nl);
    //   if (nl==0) {
    //     return dims;
    //   }
    //   else {
    //     return NestedInitializerListDef<Element, L-1>::dims(*(list.begin()), dims);
    //   }
    // }


  };

  template<typename Element>
  class NestedInitializerListDef<Element, 0> {
  public:
    using type = Element;

    template <int rank>
    static void compute(MultiArray<Element, rank>& t, const type& item, int& i) {
      //TLDISP(item);
      t[i++] = item;
    }


  };



  // Type to use NestedInitializerListDef<T,int>

  template<typename T, int T_levels>
  using NestedInitializerList = typename NestedInitializerListDef<T, T_levels>::type;



};
#endif
