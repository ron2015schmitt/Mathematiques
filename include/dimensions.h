#ifndef MATHQ__DIMENSIONS
#define MATHQ__DIMENSIONS



namespace mathq {


  // ***************************************************************************
  // Dimensions 
  //
  // size = rank of the MultiArray that the Dimensions correspond to
  // Cannot size by template parameter because because we need the same exact type for RecursiveDimensions elements
  // ***************************************************************************

  class Dimensions {
  
  private:
    std::vector<size_t> data_;

  public:
    using Type = Dimensions;
    using ElementType = size_t;
    using iterator = std::vector<size_t>::iterator;
    using const_iterator = std::vector<size_t>::const_iterator;
    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************


    Dimensions() {
      this->resize(0);
    }

    Dimensions(const Dimensions& var) {
      *this = var;
    }

    explicit Dimensions(const size_t N) {
      this->resize(N);
    }

    explicit Dimensions(const std::vector<size_t>& var) {
      *this = var;
    }

    explicit Dimensions(const std::valarray<size_t>& var) {
      *this = var;
    }

    template <size_t rank2>
    explicit Dimensions(const std::array<size_t, rank2>& var) {
      *this = var;
    }

    explicit Dimensions(const std::initializer_list<size_t>& var) {
      *this = var;
    }

    inline size_t num_elements(void) const {
      if (rank() == 0) {
        return 1;
      }
      size_t sz = 1;
      for (size_t i = 0; i < this->size(); i++) {
        sz *= (*this)[i];
      }
      return sz;
    }

    size_t rank() const {
      return size();
    }

    size_t size() const {
      return data_.size();
    }
    Dimensions& resize(const size_t N) {
      data_.resize(N);
      return *this;
    }
    Dimensions& push_back(const size_t item) {
      data_.push_back(item);
      return *this;
    }
    Dimensions& erase(const iterator it) {
      data_.erase(it);
      return *this;
    }
    iterator begin() {
      return data_.begin();
    }
    const_iterator begin() const {
      return data_.begin();
    }
    iterator end() {
      return data_.end();
    }
    const_iterator end() const {
      return data_.end();
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

   //**********************************************************************
    //************* Array-style Element Access: v[n] ***********************
    //**********************************************************************

    // "read/write"
    size_t& operator[](const size_t n) {
      return data_[n];
    }

    // read
    const size_t& operator[](const size_t n)  const {
      return data_[n];
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


    bool equal_num_elements(const Dimensions& var) const {
      return (this->num_elements() == var.num_elements());
    }


    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************


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

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************



    inline std::string classname() const {
      return ClassName();
    }

    static inline std::string ClassName() {
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

    //**********************************************************************
    //                      CONVERSION OPERATORS 
    // use to dynamic_cast to another type of container
    //**********************************************************************

    // array<size_t,NE2>
    // Does this provide any utility?
    template <size_t NE2>
    operator std::array<size_t, NE2>() const {
      std::array<size_t, NE2> y;
      for (size_t i = 0; i < size(); i++) {
        y[i] = (*this)[i];
      }
      return y;
    }


    template <size_t NE2> std::array<size_t, NE2>
    toArray() const {
      std::array<size_t, NE2> y;
      for (size_t i = 0; i < size(); i++) {
        y[i] = (*this)[i];
      }
      return y;
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
      return ClassName();
    }

    static inline std::string ClassName() {      using namespace display;
      std::string s = "NullDimensions";
      return s;
    }

  };





  // ***************************************************************************
  // equiv
  //
  // stand-alone function for two Dimensions instances
  // ***************************************************************************

  inline bool equiv(const Dimensions& dims1, const Dimensions& dims2) {
    return dims1.equiv(dims2);
  }


  inline bool equal_num_elements(const Dimensions& dims1, const Dimensions& dims2) {
    return dims1.equal_num_elements(dims2);
  }






  // ***************************************************************************
  // RecursiveDimensions 
  //
  // ***************************************************************************

  class RecursiveDimensions {

  private:
    std::valarray<Dimensions> data_;

  public:


    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************

    RecursiveDimensions() {
      this->resize(0);
    }

    RecursiveDimensions(const RecursiveDimensions& var) {
      *this = var;
    }

    explicit RecursiveDimensions(const size_t depth) {
      this->resize(depth);
    }

    explicit RecursiveDimensions(const std::vector<Dimensions>& var) {
      *this = var;
    }

    explicit RecursiveDimensions(const std::valarray<Dimensions>& var) {
      *this = var;
    }

    template <size_t rank2>
    explicit RecursiveDimensions(const std::array<Dimensions, rank2>& var) {
      *this = var;
    }

    explicit RecursiveDimensions(const std::initializer_list<Dimensions>& var) {
      *this = var;
    }

    explicit RecursiveDimensions(const std::initializer_list<std::initializer_list<size_t>>& var) {
      *this = var;
    }


    size_t size() const {
      return data_.size();
    }
    RecursiveDimensions& resize(const size_t N) {
      data_.resize(N);
      return *this;
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

       //**********************************************************************
    //************* Array-style Element Access: v[n] ***********************
    //**********************************************************************

    // "read/write"
    Dimensions& operator[](const size_t n) {
      return data_[n];
    }

    // read
    const Dimensions& operator[](const size_t n)  const {
      return data_[n];
    }



    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************

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

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************


    inline std::string classname() const {
      return ClassName();
    }

    static inline std::string ClassName() {      using namespace display;
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

    //**********************************************************************
    //                      CONVERSION OPERATORS 
    // use to dynamic_cast to another type of container
    //**********************************************************************




  };



};
#endif
