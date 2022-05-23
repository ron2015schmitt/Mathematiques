#include <cstdio>
#include <complex>
#include <string>
#include <iostream>
#include <sstream>
#include <type_traits> // C++11

#define MATHQ_DEBUG 0
#include "mathq.h"


using namespace std;


// enable_if examples
// from  http://codeofthedamned.com/index.php/enable_if

// as return type
template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
mysum(T a, T b) {
  return (a + b);
}

// as function argument
template <typename T>
T mysum2(T a, T b,
         typename std::enable_if<std::is_integral<T>::value, T>::type * = 0) {
  return (a + b);
}





template <class D>
class Box {
private:
  D d_;

public:
  Box(D d) : d_(d) {}

  D value() {
    return d_;
  }

  template <typename T = D>
  typename std::enable_if<is_arithmetic<T>::value, T>::type
  negate() {
    return -d_;
  }
};





class Object {
public:
  Object() {}
  string info() {
    return name() + "()";
  }
  string static name() {
    return "Object";
  }
};

class Simple {
public:
  Simple() {}
  string info() {
    return name() + "()";
  }
  string static name() {
    return "Simple";
  }
};

class Child : public Simple {
public:
  Child() {}
  string info() {
    return name() + "()";
  }
  string static name() {
    return "Child";
  }
};


template <class D>
class Container {
  D d_;

public:
  Container() {
  }
  Container(D d) {
    d_ = d;
  }
  string info() {
    stringstream ss;
    ss << d_;
    return string(name() + "(") + ss.str() + ")";
  }
  string static name() {
    return string("Container<") + typeid(D).name() + ">";
  }
};


template <class D>
class SpecialContainer {
  D d_;

public:
  SpecialContainer() {
  }
  SpecialContainer(D d) {
    d_ = d;
  }
  string info() {
    stringstream ss;
    ss << d_;
    return string(name() + "(") + ss.str() + ")";
  }
  string static name() {
    return string("SpecialContainer<") + typeid(D).name() + ">";
  }
};

template <class D>
class SpecialChildContainer : public SpecialContainer<D> {
  D d_;

public:
  SpecialChildContainer() {
  }
  SpecialChildContainer(D d) {
    d_ = d;
  }
  string info() {
    stringstream ss;
    ss << d_;
    return string(name() + "(") + ss.str() + ")";
  }
  string static name() {
    return string("SpecialChildContainer<") + typeid(D).name() + ">";
  }
};


//---------------------------------------------
//   get() functions
//---------------------------------------------

// NOTE: template functions only have overloading.  NO specialization.
// so each function needs a different parameter signature


// template<class A, typename = std::enable_if_t<!(std::is_base_of<Simple,A>::value)&&!(std::is_arithmetic<A>::value)> >
// string get(A x, string s) {
//   return "get(A x):  "+s;
// }

template <class A>
string get(A x, string s) {
  return "get(A x):  " + s;
}

template <class D, template <class> class C>
string get(C<D> x, string s) {
  return "get(C<D> x):  " + s;
}

template <class D>
string get(SpecialContainer<D> x, string s) {
  return "get(SpecialContainer<D> x):  " + s;
}

// NOTE: can't use it has same signature of the genera function when: int, float etc
template <class F, typename = std::enable_if_t<std::is_arithmetic<F>::value>>
string get(F x, string s) {
  return "get(A:floating x):  " + s;
}

// template<class T, typename = std::enable_if_t<std::is_base_of<Simple,T>::value> >
// void get(T x, string s) {
//   std::cout<< "get(T <: Simple x):  "<<s;
// }


//---------------------------------------------
//   yet() functions
//---------------------------------------------
//   Unlike get, yet has no general version
//   so we can use aritmtric types

template <class A>
typename std::enable_if<
    !(std::is_base_of<Simple, A>::value) && !(std::is_arithmetic<A>::value), string>::type
yet(A x, string s) {
  return "yet(A x):  " + s;
}


template <class D, template <class> class C>
string yet(C<D> x, string s) {
  return "yet(C<D> x):  " + s;
}

template <class D>
string yet(SpecialContainer<D> x, string s) {
  return "yet(SpecialContainer<D> x):  " + s;
}

template <class D>
typename std::enable_if<std::is_arithmetic<D>::value, string>::type
yet(D x, string s) {
  return "yet(D:arithmetic x):  " + s;
}

// template <class T>
// typename std::enable_if<std::is_same<T, Simple>::value, string>::type
// yet(T x, string s) {
//   return "yet(T==Simple x):  "+s;
// }

template <class T>
typename std::enable_if<std::is_base_of<Simple, T>::value, string>::type
yet(T x, string s) {
  return "yet(T<=Simple x):  " + s;
}


template <typename T1, typename T2>
class ArithmeticType {
public:
  T1 x1;
  T2 x2;
  typedef decltype(x1 + x2) Type;
};



template <class D>
D bin(D x1, D x2) {
  D y = x1 + x2;
  cout << "D  bin(D x1, D x2) = ";
  cout << x1 << "+" << x2 << " = ";
  return y;
}


template <class D1, class D2>
typename ArithmeticType<D1, D2>::Type bin(D1 x1, D2 x2) {
  typedef typename ArithmeticType<D1, D2>::Type D3;
  D3 y = x1 + x2;
  cout << "ArithmeticType<D1,D2>::Type  bin(D1 x1, D2 x2) = ";
  cout << x1 << "+" << x2 << " = ";
  return y;
}


int main(int argc, char *argv[]) {
  using namespace std;
  string myname = argv[0];

  cout << endl
       << myname << endl;

  printf("hello\n");
  Object o;
  cout << endl
       << get(o, "Object") << endl;
  cout << endl
       << yet(o, "Object") << endl;

  Simple s;
  cout << endl
       << get(s, "Simple") << endl;
  cout << endl
       << yet(s, "Simple") << endl;

  Child ch;
  cout << endl
       << get(ch, "Child") << endl;
  cout << endl
       << yet(ch, "Child") << endl;

  Container<int> c(1);
  cout << endl
       << get(c, "Container<int>") << endl;
  cout << endl
       << yet(c, "Container<int>") << endl;

  SpecialContainer<int> sc(2);
  cout << endl
       << get(sc, "SpecialContainer<int>") << endl;
  cout << endl
       << yet(sc, "SpecialContainer<int>") << endl;

  SpecialChildContainer<int> sch(3);
  cout << endl
       << get(sch, "SpecialChildContainer<int>") << endl;
  cout << endl
       << yet(sch, "SpecialChildContainer<int>") << endl;

  int n;
  //  cout << endl << get(n,"int") << endl;
  cout << endl
       << yet(n, "int") << endl;

  std::complex<int> z(1, -2);
  cout << endl
       << yet(n, "complex<int>") << endl;

  bool q = false;
  cout << endl
       << yet(n, "bool") << endl;

  cout << endl;


  // double d;
  // //cout << endl << s.info() << endl;
  // cout << endl << get(d) << endl;
  // cout << endl;

  {
    int n = 2;
    long m = 5;
    cout << bin(n, m) << endl;

    int n1 = 12;
    int n2 = 21;
    cout << bin(n1, n2) << endl;
  }

  // bit-wise operators work for all integral types
  {
    unsigned int x = 1;
    unsigned int y = 0;
    unsigned int z = x & y;
    cout << "x=" << x << " and ~x=" << ~x << endl;
  }
  {
    int x = 1;
    int y = 0;
    int z = x & y;
    cout << "x=" << x << " and ~x=" << ~x << endl;
  }
  {
    bool x = true;
    bool y = false;
    bool z = x & y;
    cout << "x=" << x << " and ~x=" << ~x << endl;
  }
  {
    float x = 0;
    float y = 0;
    // doesn't exist
    //    float z = x&y;
  }

  {
    printf("\nmysum: test of enable_if as return type\n");
    int x = 1;
    int y = 0;
    int z = mysum(x, y);
    cout << "x=" << x << " y=" << y << " z=" << z << endl;
  }

  {
    float x = 1;
    float y = 0;
    // the following doesn;t exist
    // float z = mysum(x,y);
    // cout<< "x=" << x << " y="<<y<<" z="<<z << endl;
  }

  {
    printf("\nmysum2: test of enable_if function argument\n");
    int x = 1;
    int y = 0;
    int z = mysum2(x, y);
    cout << "x=" << x << " y=" << y << " z=" << z << endl;
  }


  {
    printf("\nBox class\n");
    Box<int> x(1);
    Box<string> s("hi");
    cout << "x=" << x.value() << " s=" << s.value() << endl;
    cout << "negate(x)=" << x.negate() << endl;
    // cout<< "negate(s)=" << s.negate() <<  endl;
  }


  return 0;
}
