#include <type_traits>
#include <string>
#include <iostream>




class AbstractClass {
public:
  virtual AbstractClass &self() = 0;
  virtual int size() = 0;
};


class Concrete : public AbstractClass {
public:
  typedef Concrete Type;
  typedef double Type2;

  Concrete() {}

  Concrete &self() {
    std::cout << " (in self) ";
    Concrete &q = *this;
    return q;
  }

  int size() {
    return 2;
  }
};




int main(int argc, char *argv[]) {
  using namespace std;
  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " << myname << std::endl;
  cout << std::endl;

  Concrete *y = new Concrete();
  cout << "y.size()=" << y->size() << endl;

  AbstractClass *x = y;
  cout << "x.size()=" << x->size() << endl;

  cout << "x.self.size()=" << x->self().size() << endl;


  remove_pointer<decltype(y)>::type z;
  // typename Concrete::Type  y = *(new Concrete());

  // The following is of type AbstractClass
  // There is no getting around it
  // remove_reference<decltype(x->self())>::type w;

  // this does nto compile
  //  Concrete& w = x->self();

  cout << "typeid(*x).name()=" << typeid(x).name() << endl;

  // This gives the correct resultof "Concrete"
  cout << "typeid(x->self()).name()=" << typeid(x->self()).name() << endl;


  //------------------------------------------------------

  cout << std::endl;
  cout << "done: " << myname << std::endl;
  cout << std::endl;
  cout << std::endl;


  return 0;
}
