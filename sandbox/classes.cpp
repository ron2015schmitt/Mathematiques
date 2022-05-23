#include <vector>
#include <string>

#define MATHQ_DEBUG 0
#include "mathq.h"



class ClassA {
private:
  int value_;

public:
  ClassA() : value_(-1) {
  }

  ClassA(int value) : value_(value) {
  }

  std::string classname() const {
    return "ClassA";
  }

  friend std::ostream &operator<<(std::ostream &stream, const ClassA &that) {
    using namespace display;

    stream << that.value_;
    return stream;
  }
};



class ClassB {
private:
  int value_;

public:
  // has no effect
  explicit ClassB() : value_(-2) {
  }

  // prevents ClassB b = intval;
  explicit ClassB(int value) : value_(value) {
  }

  std::string classname() const {
    return "ClassB";
  }

  friend std::ostream &operator<<(std::ostream &stream, const ClassB &that) {
    using namespace display;

    stream << that.value_;
    return stream;
  }
};



class ClassC {
private:
  int value_;

public:
  // has no effect
  explicit ClassC() : value_(-3) {
  }

  explicit ClassC(int value) : value_(value) {
  }

  std::string classname() const {
    return "ClassC";
  }

  ClassC &operator=(const int &n) {
    value_ = n;
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &stream, const ClassC &that) {
    using namespace display;

    stream << that.value_;
    return stream;
  }
};


class ClassD {
private:
  int value_;

public:
  // has no effect
  explicit ClassD() : value_(-4) {
  }


  std::string classname() const {
    return "ClassD";
  }


  friend std::ostream &operator<<(std::ostream &stream, const ClassD &that) {
    using namespace display;

    stream << that.value_;
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
    ClassA a;
    TLDISP(a);
    TLDISP(ClassA());
    TLDISP(*(new ClassA()));
  }

  CR();
  {
    ClassA a(8);
    TLDISP(a);
    TLDISP(ClassA(8));
    TLDISP(*(new ClassA(8)));
  }

  CR();
  {
    ClassA a = 100;
    TLDISP(a);
  }

  CR();
  {
    ClassA a{101}; // works
    TLDISP(a);
  }

  CR();
  {
    ClassA a = {102}; // also works!
    TLDISP(a);
  }

  CR();
  {
    ClassB b;
    TLDISP(b);
    TLDISP(ClassB());
    TLDISP(*(new ClassB()));
  }
  CR();
  {
    ClassB b(9);
    TLDISP(b);
  }
  CR();
  {
    // error: conversion from ‘int’ to non-scalar type ‘MyClass’ requested
    // ClassB b = 9;
  }
  CR();
  {
    ClassB b{6}; // works !
    TLDISP(b);
  }


  CR();
  {
    ClassC c;
    TLDISP(c);
    TLDISP(ClassC());
    TLDISP(*(new ClassC()));
  }
  CR();
  {
    ClassC c(10);
    TLDISP(c);
    c = 23;
    TLDISP(c);
  }
  CR();
  {
    // still doesn't work. = use the constructor
    // ClassC c = 11;
    // TLDISP(c);
  }

  CR();
  {
    ClassD d;
    TLDISP(d);
  }

  CR();
  {
    // doesn't work
    // ClassD d {22};
    // TLDISP(d);
  }


  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();
  return 0;
}
