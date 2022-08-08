#ifndef MATHQ__SLICES
#define MATHQ__SLICES


namespace mathq {

  template <typename T>
  class slc {

  private:
    const T start_;
    const T end_;
    const T step_;

  public:

  slc(const T start, const T end, const T step)
    : start_(start), end_(end), step_(step) {
    //PRINTF3("slc(start=%d, end=%d, step=%d)\n",start, end, step);
  }

  slc(const T start, const T end)
    : start_(start), end_(end), step_(1) {
    //PRINTF3("slc(start=%d, end=%d)\n",start, end);
  }

  T start(void) const {
    return start_;
  }
  T end(void) const {
    return end_;
  }
  T step(void) const {
    return step_;
  }

  std::string expression() const {
    std::stringstream  ss;
    ss << *this;
    return ss.str();
  }

  std::string classname() const {
    return ClassName();
  }

  static std::string ClassName() {
    return "slc";
  }

  friend std::ostream& operator<<(std::ostream& stream, const mathq::slc<T>& slice) {
    using namespace display;
    Style name_style = CREATESTYLE(CYAN);
    Style punct_style = CREATESTYLE(GRAY1);
    Style num_style = CREATESTYLE(BOLD);
    stream << num_style.apply(num2string(slice.start()));
    stream << punct_style.apply(":");
    stream << num_style.apply(num2string(slice.end()));
    stream << punct_style.apply(":");
    stream << num_style.apply(num2string(slice.step()));
    return stream;
  }

    //**********************************************************************
    //                      CONVERSION OPERATORS 
    // use to static_cast a Vector to another type of container
    //**********************************************************************

  };



  namespace SLC {
    const mathq::slc all(0, -1, 1);
    const mathq::slc rev(-1, 0, -1);
    const mathq::slc even(0, -1, 2);
    const mathq::slc odd(1, -1, 2);
  };



};


#endif
