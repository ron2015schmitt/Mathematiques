#define MATHQ_DEBUG 1
#include "mathq.h"

// *************************************************************
  // remove this after debugging is complete
// *************************************************************

namespace mathq {

  slc::slc(const size_t start, const size_t end, const size_t step)
    : start_(start), end_(end), step_(step) {
    //PRINTF3("slc::slc(start=%d, end=%d, step=%d)\n",start, end, step);
  }

  slc::slc(const size_t start, const size_t end)
    : start_(start), end_(end), step_(1) {
    //PRINTF3("slc::slc(start=%d, end=%d)\n",start, end);
  }




  size_t slc::start(void) const {
    return start_;
  }
  size_t slc::end(void) const {
    return end_;
  }
  size_t slc::step(void) const {
    return step_;
  }

  Vector<size_t>& slc::toIndexVector(const size_t N) const {
    //    PRINTF3("slc::toIndexVector(N=%lu)\n",N);
    size_t mystart = start_;
    if (mystart < 0) {
      mystart += N;
    }
    size_t myend = end_;
    if (myend < 0) {
      myend += N;
    }

    size_t mystep = step_;

    std::queue<size_t> indices;

    if (myend-mystart >= 0) {
      if (mystep > 0) {
        for (size_t k = mystart; k <= myend; k += mystep) {
          if (k < 0) continue;
          if (k >= N) break;
          indices.push(k);
        }
      }
    }
    else {
      if (mystep < 0) {
        for (size_t k = mystart; k >= myend; k += mystep) {
          if (k >= N) continue;
          if (k < 0)  break;
          indices.push(k);
        }
      }
    }

    const size_t Nnew = indices.size();
    Vector<size_t>& indexvec = *(new Vector<size_t>(Nnew));
    for (size_t i = 0; i < Nnew; i++) {
      indexvec[i] = indices.front();
      indices.pop();
    }

    return indexvec;
  }



  std::string slc::expression() const {
    std::stringstream  ss;
    ss << *this;
    return ss.str();
  }

  std::string slc::classname() const {
    return "slc";
  }

  std::ostream& operator<<(std::ostream& stream, const mathq::slc& slice) {
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


};


