#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>
#include <variant>
#include <cmath>
#include <cassert>
#include <numeric>
#include "mathq.h"



// template <typename T>
// bool is_const = std::is_same<T, std::remove_const<T>>::value;

//  pointer with right const (pointer cannot be changed))
template <typename T>
bool is_pointer_const = std::is_pointer<T>::value && std::is_const<T>::value;

//  pointer with left const (value pointed to cannot be changed))
template <typename T>
bool is_const_pointer = std::is_pointer<T>::value && std::is_const<std::remove_pointer_t<T>>::value;


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;


  int ii = 3;
  TRDISP(ii);
  int* ip = &ii;
  TRDISP(ip);
  const int ii2 = 2;
  TRDISP(ii2);

  const int jj = 3;
  TRDISP(jj);

  int const kk = 3;
  TRDISP(kk);

  const int& jjj = ii;
  TRDISP(jjj);
  // jjj = ii2;


  int variable_int;
  const int const_int = 0;

  TRDISP(is_const<decltype(variable_int)>::value);
  TRDISP(is_const<decltype(const_int)>::value);
  TRDISP(std::is_const<std::remove_pointer_t<decltype(const_int)>>::value);


  int* variable_pointer;
  const int* const_pointer;
  int* const pointer_const = &ii;
  const int* const const_pointer_const = &ii;


  //  pointer with right const (pointer cannot be changed)
  CR();
  TRDISP(is_pointer_const<decltype(const_int)>);
  TRDISP(is_pointer_const<decltype(variable_pointer)>);
  TRDISP(is_pointer_const<decltype(const_pointer)>);
  TRDISP(is_pointer_const<decltype(pointer_const)>);
  TRDISP(is_pointer_const<decltype(const_pointer_const)>);

  //  pointer with left const (value pointed to cannot be changed))
  CR();
  TRDISP(is_const_pointer<decltype(const_int)>);
  TRDISP(is_const_pointer<decltype(variable_pointer)>);
  TRDISP(is_const_pointer<decltype(const_pointer)>);
  TRDISP(is_const_pointer<decltype(pointer_const)>);
  TRDISP(is_const_pointer<decltype(const_pointer_const)>);


  // left

  // AddQualifiers<int, Qualifiers::ConstLeft&Qualifiers::ConstRight >::Type iiii;

  return 0;
}
