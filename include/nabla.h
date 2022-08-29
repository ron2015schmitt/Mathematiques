#ifndef MATHQ__NABLA
#define MATHQ__NABLA 1


namespace mathq {

  // ***************************************************************************
  // * nabla object
  // ***************************************************************************

  template <class T>
  class Nabla {
  public:
    const unsigned int Nwindow;
  public:
    Nabla(const unsigned int Nwindow = 7) :
      Nwindow(Nwindow) {
    }
    ~Nabla() {
    }



    inline std::string classname() const {
      return ClassName();
    }

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "Nabla";
      s += StyledString::get(ANGLE1).get();
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const Nabla<T>& var) {
      using namespace display;
      stream << "(Nwindow=";
      dispval_strm(stream, var.Nwindow);
      stream << ")";
      return stream;
    }


  };




};

#endif 
