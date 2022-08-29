#include "mathq.h"


namespace mathq {


};

auto func(std::initializer_list<std::variant<double, std::complex<double>>> mylist) {
  // TRDISP(std::get<double>(w[0]));
  for (std::initializer_list<std::variant<double, std::complex<double>>>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
    TRDISP(it->index());
  }
  return true;
}


using Variant = std::variant<mathq::Interval<double>, mathq::PointSequence<double>>;

template <mathq::IsNumber T>
auto func2(const std::initializer_list<mathq::DomainWrapper<T>>& mylist) {
  // TRDISP(std::get<double>(w[0]));
  for (typename std::initializer_list<mathq::DomainWrapper<T>>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
    TRDISP(it->index());
  }
  return true;
}


void title(const std::string& s) {
  using namespace std;
  using namespace mathq;
  using namespace display;

  Style mystyle1 = CREATESTYLE(BOLD + BLUE);
  CR();
  CR();
  MOUT <<  mystyle1.apply(s) << std::endl;
  CR();
}


void subtitle(const std::string& s) {
  using namespace std;
  using namespace mathq;
  using namespace display;

  Style mystyle1 = CREATESTYLE(BLUE);
  CR();
  MOUT <<  mystyle1.apply(s) << std::endl;
  CR();
}


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;
  using namespace display;


  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  Style mystyle1 = CREATESTYLE(BOLD + BLUE);



  {
    title("Interval - real uniform");
    ECHO_CODE(Interval<double> dom1 = Interval<double>::interval(0, 10, 11));
    TRDISP(dom1);
    TRDISP(dom1.grid());
  }

  {
    title("PointSequence");
    ECHO_CODE(PointSequence<double> dom1 = PointSequence<double>({ 0,1,3,4.5,5 }));
    TRDISP(dom1);
    TRDISP(dom1.grid());
  }


  {

    title("2D CartesianCoords from Intervals");
    ECHO_CODE(CartesianCoords<double, 2, false> coords({
        Interval<double>::interval(-1,1,3),
        Interval<double>::interval(2,3,3),
      }));

    TRDISP(coords);
    TRDISP(coords.grid_dims());
    TRDISP(coords[0]);
    TRDISP(coords[1]);
  }


  std::variant<Interval<double>, PointSequence<double>> test;  // need to put this here using g++ 11.1.0. bug with variant and is_copy_constructible_v
  TRDISP(std::is_copy_constructible_v<PointSequence<double>>);

  {
    std::variant<PointSequence<double>, Interval<double>> x;

    x = { Interval<double>::interval(-1, 1, 3) };
    Interval<double> y = std::get<Interval<double>>(x);
    TRDISP(y);

    PointSequence<double> p = PointSequence<double>({ 0,1,3,4.5,5 });
    TRDISP(p);
    PointSequence<double> q = p;
    TRDISP(q);
    std::variant<PointSequence<double>, Interval<double>> x2{ p };
    PointSequence<double> z = std::get<PointSequence<double>>(x2);
    TRDISP(z);
    x = p;
    x = y;
    x2 = z;
  }
  TRDISP(std::is_copy_constructible_v<PointSequence<double>>);

  {
    std::variant<double, std::complex<double>> x;
    x = 5.5;
    double y = std::get<double>(x);
    TRDISP(y);
    x = complex(1., 2.);
    std::complex<double> z = std::get<std::complex<double>>(x);
    TRDISP(z);

    std::vector<std::variant<double, std::complex<double>>> v(5);
    v[0] = 5.5;
    TRDISP(std::get<double>(v[0]));

    std::vector<std::variant<double, std::complex<double>>> w{ 5.5, complex(1., 2.) };
    TRDISP(std::get<double>(w[0]));
    TRDISP(std::get<std::complex<double>>(w[1]));

  }

  {
    double x = 5.5;
    std::complex<double> z = complex(1., 2.);
    TRDISP(func({ x,z }));

  }

  {
    Interval<double> x{ Interval<double>::interval(-1, 1, 3) };
    TRDISP(x);
    PointSequence<double> p = PointSequence<double>({ 0,1,3,4.5,5 });
    TRDISP(p);

    TRDISP(func2<double>({ x,p }));

    TRDISP(IsInterval<decltype(x)>);
    TRDISP(IsInterval<decltype(p)>);

    TRDISP(IsPointSequence<decltype(x)>);
    TRDISP(IsPointSequence<decltype(p)>);

  }


  {

    title("2D CartesianCoords from PointeSequence and Interval");
    ECHO_CODE(CartesianCoords<double, 2, false> coords({
        Interval<double>::interval(-1,1,3),
         PointSequence<double>({ 0,1,3,10 }),
      }));

    // ECHO_CODE(CartesianCoords<double, 2, false>::tester({
    //     Interval<double>::interval(-1,1,3),
    //      PointSequence<double>({ 0,1,3,10 }),
    //   }));

    TRDISP(coords);
    // TRDISP(coords.domains[0].index());
    TRDISP(coords.grid_dims());
    TRDISP(coords[0]);
    TRDISP(coords[1]);


  }





  return 0;
}
