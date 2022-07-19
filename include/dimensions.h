#ifndef MATHQ__DIMENSIONS_H
#define MATHQ__DIMENSIONS_H



namespace mathq {


  // ***************************************************************************
  // Dimensions 
  //
  // size = rank of the MultiArray that the Dimensions correspond to
  // Cannot size by template parameter because because we need the same exact type for RecursiveDimensions elements
  // ***************************************************************************

  class Dimensions : public std::valarray<size_t> {
  public:
    using Type = Dimensions;
    using Parent = std::valarray<size_t>;
    using ElementType = size_t;


    Dimensions() {
      this->resize(0);
    }

    Dimensions(const size_t N) {
      this->resize(N);
    }

    Dimensions(const Dimensions& var) {
      *this = var;
    }

    Dimensions(const std::vector<size_t>& var) {
      *this = var;
    }

    Dimensions(const std::valarray<size_t>& var) {
      *this = var;
    }

    template <size_t rank2>
    Dimensions(const std::array<size_t, rank2>& var) {
      *this = var;
    }

    Dimensions(const std::initializer_list<size_t>& var) {
      *this = var;
    }

    Dimensions& getReducedDims() const {
      // remove all dimensiosn equal to 1
      Dimensions& v = *(new Dimensions{});
  
      size_t N = 0;
      for (size_t i = 0; i < this->size(); i++) {
        if((*this)[i] > 1) {
          N++;
        }
      }
      v.resize(N);
  
      size_t n = 0;
      for (size_t i = 0; i < this->size(); i++) {
        if((*this)[i] > 1) {
          v[n++] = (*this)[i];
        }
      }
      return v;
    }

    bool operator==(const Dimensions& var) const {
      if (size() != var.size()) return false;
      for (size_t i = 0; i < this->size(); i++) {
        if ((*this)[i] != var[i]) {
          return false;
        }
      }
      return true;
    }


    bool equiv(const Dimensions& var) const {
      return (this->getReducedDims() == var.getReducedDims());
    }

    Dimensions& reverse() {
      // reverse order
      size_t k = size()-1;
      for (size_t ii = 0; ii < this->size()/2; ii++, k--) {
        size_t temp = (*this)[ii];
        (*this)[ii] = (*this)[k];
        (*this)[k] = temp;
      }
      return *this;
    }

    Dimensions& getReverse() const {
      Dimensions& dd = *(new Dimensions(*this));
      return dd.reverse();
    }

    inline size_t product(void) const {
      size_t sz = 1;
      for (size_t i = 0; i < this->size(); i++) {
        sz *= (*this)[i];
      }
      return sz;
    }


    Dimensions& operator=(const Dimensions& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    Dimensions& operator=(const std::vector<size_t>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    Dimensions& operator=(const std::valarray<size_t>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    template <size_t rank2>
    Dimensions& operator=(const std::array<size_t, rank2>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    Dimensions& operator=(const std::initializer_list<size_t>& ilist) {
      this->resize(ilist.size());
      size_t k = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        (*this)[k] = *it;
      }
      return *this;
    }



    inline std::string classname() const {
      using namespace display;
      std::string s = "Dimensions";
      return s;
    }

    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Dimensions& v) {
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



  // ********************************************************************************
  // NullDimensions 
  //
  // This class is used for the dimensiosn of non-MultiArray classes: int, float,
  // std::complex, Imaginary, Quarternion, etc
  // ********************************************************************************

  class NullDimensions : public Dimensions {
  public:
    using Type = NullDimensions;
    using Parent = Dimensions;
    using ElementType = size_t;

    NullDimensions() {
      resize(0);
    }


    inline std::string classname() const {
      using namespace display;
      std::string s = "NullDimensions";
      return s;
    }

  };



  // ********************************************************************************
  // ScalarDimensions 
  //
  // This class is used for the dimensions of the Scalar class
  // ********************************************************************************

  class ScalarDimensions : public Dimensions {
  public:
    using Type = ScalarDimensions;
    using Parent = Dimensions;
    using ElementType = size_t;

    ScalarDimensions() {
      resize(1);
      (*this)[0] = 1;
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "ScalarDimensions";
      return s;
    }
  };



  // // ***************************************************************************
  // // NumberTrait specialization for  Dimensions
  // //
  // // Compiler can't compile this until after Dimensions has been defined
  // // ***************************************************************************

  // template <typename NewNumber, size_t rank>
  // class
  //   NumberTrait<Dimensions, NewNumber> {
  // public:
  //   using InputType = Vector<size_t>;
  //   using Type = typename NumberTrait<size_t>::Type;
  //   using ReplacedNumberType = Vector<typename NumberTrait<size_t, NewNumber>::ReplacedNumberType>;
  //   using ReplacedElementType = Vector<NewNumber>; // this is correct, see comment above

  //   constexpr static bool value = false;
  //   constexpr static size_t depth() {
  //     return 1 + NumberTrait<size_t, NewNumber>::depth();
  //   }
  //   inline static size_t size(const InputType& x) {
  //     return x.size();
  //   }
  //   inline static size_t total_size(const InputType& x) {
  //     return x.total_size();
  //   }
  // };



  // ***************************************************************************
  // equiv
  //
  // stand-alone function for two Dimensions instances
  // ***************************************************************************

  inline bool equiv(const Dimensions& dims1, const Dimensions& dims2) {
    return dims1.equiv(dims2);
  }







  // ***************************************************************************
  // RecursiveDimensions 
  //
  // ***************************************************************************

  class RecursiveDimensions : public std::valarray<Dimensions> {

  public:
    using Parent = std::valarray<Dimensions>;

    RecursiveDimensions() {
      this->resize(0);
    }

    RecursiveDimensions(const size_t depth) {
      this->resize(depth);
    }

    RecursiveDimensions(const RecursiveDimensions& var) {
      *this = var;
    }

    RecursiveDimensions(const std::vector<size_t>& var) {
      *this = var;
    }

    RecursiveDimensions(const std::valarray<size_t>& var) {
      *this = var;
    }

    template <size_t rank2>
    RecursiveDimensions(const std::array<size_t, rank2>& var) {
      *this = var;
    }

    RecursiveDimensions(const std::initializer_list<size_t>& var) {
      *this = var;
    }


    RecursiveDimensions(const std::initializer_list<Dimensions>& var) {
      *this = var;
    }

    RecursiveDimensions(const std::initializer_list<std::initializer_list<size_t>>& var) {
      *this = var;
    }



    RecursiveDimensions& reverse_each() {
      for (size_t d = 0; d < size(); d++) {
        (*this)[d].reverse();
      }
      return*this;
    }

    RecursiveDimensions& getReverseEach() {
      RecursiveDimensions& dd = *(new RecursiveDimensions(*this));
      return dd.reverse_each();
    }

    RecursiveDimensions& evert() {
      // evert = turn inside out
      size_t k = size()-1;
      for (size_t ii = 0; ii < this->size()/2; ii++, k--) {
        Dimensions temp = (*this)[ii];
        (*this)[ii] = (*this)[k];
        (*this)[k] = temp;
      }
      return *this;
    }

    RecursiveDimensions& getEverse() {
      RecursiveDimensions& dd = *(new RecursiveDimensions(*this));
      return dd.evert();
    }


    RecursiveDimensions& operator=(const RecursiveDimensions& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    RecursiveDimensions& operator=(const std::vector<Dimensions>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    RecursiveDimensions& operator=(const std::valarray<Dimensions>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    template <size_t rank2>
    RecursiveDimensions& operator=(const std::array<Dimensions, rank2>& var) {
      this->resize(var.size());
      for (size_t i = 0; i < this->size(); i++) {
        (*this)[i] = var[i];
      }
      return *this;
    }

    RecursiveDimensions& operator=(const std::initializer_list<Dimensions>& ilist) {
      this->resize(ilist.size());
      size_t k = 0;
      typename std::initializer_list<Dimensions>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        (*this)[k] = *it;
      }
      return *this;
    }

    RecursiveDimensions& operator=(const std::initializer_list<std::initializer_list<size_t>>& ilist) {
      this->resize(ilist.size());
      size_t k = 0;
      typename std::initializer_list<std::initializer_list<size_t>>::iterator it;
      for (it = ilist.begin(); it != ilist.end(); ++it, k++) {
        Dimensions d;
        d = *it;
        (*this)[k] = d;
      }
      return *this;
    }





    bool operator==(const RecursiveDimensions& var) const {
      if (size() != var.size()) return false;
      for (size_t i = 0; i < this->size(); i++) {
        if ((*this)[i] != var[i]) {
          return false;
        }
      }
      return true;
    }


    inline std::string classname() const {
      using namespace display;
      std::string s = "RecursiveDimensions";
      return s;
    }

    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const RecursiveDimensions& v) {
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



};
#endif
