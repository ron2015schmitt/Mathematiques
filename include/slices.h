#ifndef MATHQ__SLICES_H
#define MATHQ__SLICES_H


namespace mathq {



  class slc {
  private:
    const size_t start_;
    const size_t end_;
    const size_t step_;
  public:
    slc(const size_t start, const size_t end, const size_t step);
    slc(const size_t start, const size_t end);
    size_t start(void) const;
    size_t end(void) const;
    size_t step(void) const;
    Vector<size_t>& toIndexVector(const size_t N) const;
    std::string expression() const;
    std::string classname() const;
    friend std::ostream& operator<<(std::ostream& stream, const slc& slice);
  };

  namespace SLC {
    const mathq::slc all(0, -1, 1);
    const mathq::slc rev(-1, 0, -1);
    const mathq::slc even(0, -1, 2);
    const mathq::slc odd(1, -1, 2);
  };

};


#endif
