
template <class Number>
class
  NotDefined {
public:
  Number a = 0;
  NotDefined() {
  }
  ~NotDefined() {
  }
};


template <class Number>
class
  Point {
public:
  Number a = 1;
  Point() {
  }
  ~Point() {
  }
};


template <class Number>
class
  Intervale {
public:
  Number a = 2;
  Intervale() {
  }
  ~Intervale() {
  }
};




template <class Number, int ii>
class
  Helper {
public:
  typedef NotDefined<Number> Type;
};
template <class Number>
class
  Helper<Number, 0> {
public:
  typedef NotDefined<Number> Type;
};
template <class Number>
class
  Helper<Number, 1> {
public:
  typedef Point<Number> Type;
};
template <class Number>
class
  Helper<Number, 2> {
public:
  typedef Intervale<Number> Type;
};


template <template <typename> class T, typename Number>
T<Number>& value(const std::variant<NotDefined<Number>, Point<Number>, Intervale<Number>>& var, const T<Number>& dummy) {
  return std::get<T<Number>>(var);
}



template <class Number>
class
  NoGrid : public mathq::GridSet<Number> {
public:
  NoGrid() : mathq::GridSet<Number>(true) {
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

template <class Number>
class
  Coordinate2 {
public:
  const std::string name;
  std::variant<NotDefined<Number>, Point<Number>, Intervale<Number>> definition;
  const int index;

  Coordinate2() :
    name("[no-name]") {
  }

  Coordinate2(const std::string& name, const NotDefined<Number>& realSet) :
    name(name),
    definition(realSet),
    index(0) {
  }
  Coordinate2(const std::string& name, const Point<Number>& realSet) :
    name(name),
    definition(realSet),
    index(1) {
  }
  Coordinate2(const std::string& name, const Intervale<Number>& realSet) :
    name(name),
    definition(realSet),
    index(2) {
  }

  ~Coordinate2() {
  }

  template <template <typename> class T>
  T<Number>& getRealSet() {
    return std::get<T<Number>>(definition);
  }

};
