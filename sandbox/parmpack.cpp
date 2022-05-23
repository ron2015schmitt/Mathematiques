#include <iostream>



template <typename... U>
typename std::enable_if<(std::is_same<U, int>::value && ...), void>::
type test(U... ints) {
  const int size = sizeof...(ints);
  int intarray[size] = {ints...};
  std::cout << "(";
  for(int i = 0; i < size; i++){
    if (i>0) std::cout << ", ";
    std::cout << intarray[i];
  }
  std::cout << ")" << std::endl;
}


int main(int argc, char *argv[])
{
  std::string myname = argv[0];

  using namespace std;
  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  

  test();
  test(-10,78);
  test(1,4,0);


  //------------------------------------------------------
  
  cout << std::endl;
  cout << "done: " << myname << std::endl;
  cout << std::endl;
  cout << std::endl;

  
  return 0;
}
