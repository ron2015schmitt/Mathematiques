
template <class D>
class
  NotDefined {
public:
  D a = 0;
  NotDefined() {
  }
  ~NotDefined() {
  }
};


template <class D>
class
  Point {
public:
  D a = 1;
  Point() {
  }
  ~Point() {
  }
};


template <class D>
class
  Intervale {
public:
  D a = 2;
  Intervale() {
  }
  ~Intervale() {
  }
};




template <class D, int ii>
class
  Helper {
public:
  typedef NotDefined<D> Type;
};
template <class D>
class
  Helper<D, 0> {
public:
  typedef NotDefined<D> Type;
};
template <class D>
class
  Helper<D, 1> {
public:
  typedef Point<D> Type;
};
template <class D>
class
  Helper<D, 2> {
public:
  typedef Intervale<D> Type;
};


template <template <typename> class T, typename D>
T<D>& value(const std::variant<NotDefined<D>, Point<D>, Intervale<D>>& var, const T<D>& dummy) {
  return std::get<T<D>>(var);
}



template <class D>
class
  NoGrid : public mathq::GridSet<D> {
public:
  NoGrid() : mathq::GridSet<D>(true) {
  }
  ~NoGrid() {
  }
};

// mathq::NoGrid
template <typename T>
inline void dispval_strm(std::ostream& stream, const NoGrid<T>& var) {
  stream << "{}";
}

// need to be able to place thes ein a std::vector so they need to have same type

template <class D>
class
  Coordinate2 {
public:
  const std::string name;
  std::variant<NotDefined<D>, Point<D>, Intervale<D>> definition;
  const int index;

  Coordinate2() :
    name("[no-name]") {
  }

  Coordinate2(const std::string& name, const NotDefined<D>& realSet) :
    name(name),
    definition(realSet),
    index(0) {
  }
  Coordinate2(const std::string& name, const Point<D>& realSet) :
    name(name),
    definition(realSet),
    index(1) {
  }
  Coordinate2(const std::string& name, const Intervale<D>& realSet) :
    name(name),
    definition(realSet),
    index(2) {
  }

  ~Coordinate2() {
  }

  template <template <typename> class T>
  T<D>& getRealSet() {
    return std::get<T<D>>(definition);
  }

};
