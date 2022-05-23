#include <type_traits>
#include <string>
#include <iostream>



template <bool B>
using EnableConstructorIf = typename std::enable_if<B, int>::type;

template <bool B, class T>
using EnableMethodIf = typename std::enable_if<B, T>::type;


template <int N>
class MyClass {
public:
  std::string s;


  template <int M = N, EnableConstructorIf<(M < 0)> = 0>
  MyClass() {
    s = "Negative";
  }
  template <int M = N, EnableConstructorIf<(M == 0)> = 0>
  MyClass() {
    s = "Zero";
  }
  template <int M = N, EnableConstructorIf<(M > 0)> = 0>
  MyClass() {
    s = "Positive";
  }

  template <int M = N>
  EnableMethodIf<(M < 0), int> getSign() {
    return -1;
  }
  template <int M = N>
  EnableMethodIf<(M == 0), int> getSign() {
    return 0;
  }
  template <int M = N>
  EnableMethodIf<(M > 0), int> getSign() {
    return +1;
  }
};



int main(int argc, char *argv[]) {
  using namespace std;

  MyClass<-5> a;
  MyClass<0> b;
  MyClass<100> c;

  cout << "a.string = " << a.s << " ->" << a.getSign() << endl;
  cout << "b.string = " << b.s << " ->" << b.getSign() << endl;
  cout << "c.string = " << c.s << " ->" << c.getSign() << endl;


  return 0;
}
