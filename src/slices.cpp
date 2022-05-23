#define MATHQ_DEBUG 1
#include "mathq.h"

// *************************************************************
  // remove this after debugging is complete
// *************************************************************

namespace mathq {

  slc::slc(const index_type start, const index_type end, const index_type step)
    : start_(start), end_(end), step_(step) {
    //PRINTF3("slc::slc(start=%d, end=%d, step=%d)\n",start, end, step);
  }

  slc::slc(const index_type start, const index_type end)
    : start_(start), end_(end), step_(1) {
    //PRINTF3("slc::slc(start=%d, end=%d)\n",start, end);
  }




  index_type slc::start(void) const {
    return start_;
  }
  index_type slc::end(void) const {
    return end_;
  }
  index_type slc::step(void) const {
    return step_;
  }

  Vector<index_type>& slc::toIndexVector(const size_type N) const {
    //    PRINTF3("slc::toIndexVector(N=%lu)\n",N);
    index_type mystart = start_;
    if (mystart < 0) {
      mystart += N;
    }
    index_type myend = end_;
    if (myend < 0) {
      myend += N;
    }

    index_type mystep = step_;

    std::queue<index_type> indices;

    if (myend-mystart >= 0) {
      if (mystep > 0) {
        for (index_type k = mystart; k <= myend; k += mystep) {
          if (k < 0) continue;
          if (k >= N) break;
          indices.push(k);
        }
      }
    }
    else {
      if (mystep < 0) {
        for (index_type k = mystart; k >= myend; k += mystep) {
          if (k >= N) continue;
          if (k < 0)  break;
          indices.push(k);
        }
      }
    }

    const size_type Nnew = indices.size();
    Vector<index_type>& indexvec = *(new Vector<index_type>(Nnew));
    for (index_type i = 0; i < Nnew; i++) {
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


