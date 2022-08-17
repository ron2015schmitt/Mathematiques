#include "mathq.h"


namespace mathq {


};


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;



  Domain<double> dom1 = Domain<double>::interval_CC(0, 10, 11);
  TRDISP(dom1);
  TRDISP(dom1.grid());

  CurvilinearCoords<double, 2, NullType> tcoords;
  TRDISP(tcoords[0]);
  TRDISP(tcoords[1]);

  CartesianCoords<double, 2> cart_coords2a;
  TRDISP(cart_coords2a);

  CartesianCoords<double, 2> cart_coords2b({
      Domain<double>::interval_CC(-1,1,5),
      Domain<double>::interval_CC(2,3,3),
    });
  TRDISP(cart_coords2b);
  TRDISP(cart_coords2b.grid_dims());
  TRDISP(cart_coords2b[0]);
  TRDISP(cart_coords2b[1]);

  ECHO_CODE(CartesianCoords<double, 2> cart_coords2c(cart_coords2b));
  TRDISP(cart_coords2c);

  TRDISP(cart_coords2c[0]);
  TRDISP(cart_coords2c[1]);
  TRDISP(cart_coords2c.J());
  TRDISP(cart_coords2c.g());
  TRDISP(cart_coords2c.basis_vec(0));
  TRDISP(cart_coords2c.basis_vec(1));
  TRDISP(cart_coords2c.basis());
  TRDISP(cart_coords2c.at(0, 0));
  TRDISP(cart_coords2c.at(3, 2));
  TRDISP(cart_coords2c.at(3, 2).classname());

  return 0;
}
