#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>


#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  {
    OUTPUT("Contraction of of simple (non-field) 3D vectors");

    using namespace mathq::TensorIndex;
    Vector<double, 3>::Tensor<COVARIANT> covec;
    covec = { 1,2,3 };
    // covec = 5.;
    ETV(covec);

    Vector<double, 3>::Tensor<CONTRAVARIANT> vec;
    vec = { 3,2,1 };
    ETV(vec);

    ETV(covec(vec));
    ETV(vec(covec));
    // ETV(vec(vec)); // should cause compile-time error
  }


  return 0;
}
