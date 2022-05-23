#include <vector>
#include <string>

#define MATHQ_DEBUG 0
#include "mathq.h"


union IndexUnion {
  int sindex;
  unsigned int uindex;
  IndexUnion(int i) { sindex = i; };
  IndexUnion(unsigned int i) { uindex = i; };
};



enum IndexType { IND_SIGNED,
                 IND_UNSIGNED };
class Index {
public:
  IndexUnion index;
  IndexType type_;
  Index(unsigned int u) : index(u), type_(IND_UNSIGNED) {
  }
  Index(int n) : index(n), type_(IND_SIGNED) {
  }


  inline std::string classname() const {
    return "Index";
  }

  inline IndexType getType() const {
    return type_;
  }
  inline unsigned int value(unsigned int N) const {
    switch (type_) {
    case IND_SIGNED:
      if (index.sindex < 0) {
        return N + index.sindex;
      } else {
        return index.sindex;
      }
    case IND_UNSIGNED:
      return index.uindex;
    }
    return 0;
  }

  inline int getn() const {
    return index.sindex;
  }
  inline unsigned int getu() const {
    return index.uindex;
  }


  inline friend std::ostream &operator<<(std::ostream &stream, const Index &index) {
    using namespace display;

    switch (IndexType t = index.getType()) {
    case IND_SIGNED:
      stream << "IND_SIGNED ";
      dispval_strm(stream, index.getn());
      break;
    case IND_UNSIGNED:
      stream << "IND_UNSIGNED ";
      dispval_strm(stream, index.getu());
      break;
    }
    return stream;
  }
};


class Holder {
private:
  std::valarray<double> *data_;

public:
  Holder() {
    data_ = new std::valarray<double>(5);
  }

  // "read/write":
  double &operator[](const Index &index) {
    return (*data_)[index.value(size())];
  }

  // "read only":
  const double &operator[](const Index &index) const {
    return (*data_)[index.value(size())];
  }

  inline int size() const {
    return data_->size();
  }

  inline std::string classname() const {
    return "Holder";
  }

  inline friend std::ostream &operator<<(std::ostream &stream, const Holder &h) {
    using namespace display;
    dispval_strm(stream, "(");
    for (int i = 0; i < h.size(); i++) {
      if (i > 0) {
        dispval_strm(stream, ", ");
      }
      dispval_strm(stream, h[i]);
    }
    dispval_strm(stream, ")");

    return stream;
  }
};




int main(int argc, char *argv[]) {



  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace mathq;
  using namespace display;
  using namespace std;

  Style bold = CREATESTYLE(BOLD);

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;
  print_mathq_info();


  {
    TLDISP(sizeof(int));
    TLDISP(sizeof(unsigned));
    TLDISP(sizeof(unsigned int));
    TLDISP(sizeof(IndexUnion));
  }

  {
    Holder h;
    TLDISP(h);

    Index ind(-1);
    TLDISP(ind);
    h[ind] = 4.4;
    TLDISP(h);

    Index ind2(1u);
    TLDISP(ind2);
    h[ind2] = 1.1;
    TLDISP(h);

    TLDISP(2u);
    h[2u] = 2.2;
    TLDISP(h);

    TLDISP(-2);
    h[-2] = 3.3;
    TLDISP(h);
  }





  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();
  return 0;
}
