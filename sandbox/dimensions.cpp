#include "mathq.h"



int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  CR();
  ECHO_CODE(Vector<double, 3> v1);
  TRDISP(v1.size());
  TRDISP(v1.is_dynamic_value);
  TRDISP(v1.static_dims_array);
  TRDISP(v1);
  v1[0] = 2.2;
  TRDISP(v1);
  v1 = { 2.2, 4.4, -100.1 };
  TRDISP(v1);
  TRDISP(v1.dims());
  TRDISP(sizeof(v1)/(v1.total_size()*sizeof(double)));


  CR();
  ECHO_CODE(Vector<double> v2{ 3.1, 22.5, 100 });
  TRDISP(v2);
  TRDISP(v2.size());
  TRDISP(v2.dims());
  TRDISP(v2.is_dynamic_value);
  TRDISP(v2.static_dims_array);
  TRDISP(v2.resize(4));

  CR();
  ECHO_CODE(Vector<double, 3> v3{ 42.1, -2.5, 6.8 });
  TRDISP(v3);
  TRDISP(v3.size());
  TRDISP(v3.is_dynamic_value);
  TRDISP(v3.static_dims_array);
  TRDISP(v3.dims());

  CR();
  ECHO_CODE(Vector<double> v4);
  TRDISP(v4);
  TRDISP(v4.size());
  TRDISP(v4.is_dynamic_value);
  TRDISP(v4.static_dims_array);
  TRDISP(v4.dims());

  CR();
  ECHO_CODE(Vector<double> v4b(3));  // size 3
  TRDISP(v4b);
  TRDISP(v4b.size());
  TRDISP(v4b.is_dynamic_value);
  TRDISP(v4b.static_dims_array);
  TRDISP(v4b.dims());

  CR();
  ECHO_CODE(Vector<double, 5> v4c(3.14));  // set all vlaues to 3.14
  TRDISP(v4c);
  TRDISP(v4c.size());
  TRDISP(v4c.is_dynamic_value);
  TRDISP(v4c.static_dims_array);
  TRDISP(v4c.dims());


  CR();
  ECHO_CODE(Dimensions dims);
  TRDISP(dims.size());
  TRDISP(dims);
  ECHO_CODE(dims.resize(2));
  ECHO_CODE(dims[0] = 14);
  ECHO_CODE(dims[1] = 42);
  TRDISP(dims);



  CR();
  ECHO_CODE(Dimensions dims2);
  ECHO_CODE(dims2 = { 3,2,1 });
  TRDISP(dims2);
  TRDISP(dims2.getReduced());
  ECHO_CODE(Dimensions dims2b);
  ECHO_CODE(dims2b = { 3,1,2,1 });
  TRDISP(dims2b);
  TRDISP(dims2b.getReduced());
  TRDISP(equiv(dims2, dims2b));



  CR();
  ECHO_CODE(Dimensions dims3{ 33, 46, 77, 81 });
  TRDISP(dims3.size());
  TRDISP(dims3);
  ECHO_CODE(dims3 = { 13, 42, 56, 99 });
  TRDISP(dims3);


  CR();
  ECHO_CODE(Dimensions dims4 = *(new Dimensions(5)));
  TRDISP(dims4);

  CR();
  ECHO_CODE(Dimensions dims5{ 33, 46, 77, 81 });
  TRDISP(dims5.size());
  TRDISP(dims5);
  ECHO_CODE(dims5 = { 13, 42, 56, 99 });
  TRDISP(dims5);
  TRDISP(dims5.getReduced());
  TRDISP(dims5.num_elements());
  TRDISP(dims5.num_elements() == 13*42*56*99);



  CR();
  ECHO_CODE(RecursiveDimensions ndims1(2));
  TRDISP(ndims1.size());
  TRDISP(ndims1);
  ndims1[0] = dims;
  ndims1[1] = dims3;
  TRDISP(ndims1);


  CR();
  ECHO_CODE(RecursiveDimensions ndims2(2));
  TRDISP(ndims2.size());
  TRDISP(ndims2);
  ndims2 = { dims, dims3 };
  TRDISP(ndims2);

  CR();
  ECHO_CODE(RecursiveDimensions ndims3{ dims, dims3 });
  TRDISP(ndims3);

  CR();
  ECHO_CODE(RecursiveDimensions ndims4{ {3,2}, {5,7,1}, {3} });
  TRDISP(ndims4);
  TRDISP(ndims4.getEverse());

  CR();
  TRDISP(v1);
  TRDISP(v1.size());
  TRDISP(v1.element_size());
  TRDISP(v1.total_size());
  TRDISP(v1.dims());
  TRDISP(v1.depth());
  TRDISP(v1.recursive_dims());
  TRDISP(v1.element_dims());


  CR();
  ECHO_CODE(Vector<Vector<double, 2>> u2);
  TRDISP(u2);
  TRDISP(u2.size());
  TRDISP(u2.element_size());
  TRDISP(u2.total_size());
  TRDISP(u2.dims());
  TRDISP(u2.depth());
  TRDISP(u2.recursive_dims());
  TRDISP(u2.element_dims());


  CR();
  ECHO_CODE(Vector<Vector<double, 2>, 3> u);
  TRDISP(u.size());
  TRDISP(u.element_size());
  TRDISP(u.dims());
  u[0] = { 1,2 };
  u[1] = { 3,4 };
  u[2] = { 5,6 };
  TRDISP(u);
  TRDISP(u.recursive_dims());
  u = { {11,12}, {13,14}, {15,16} };
  TRDISP(u);
  TRDISP(u.size());
  TRDISP(u.element_size());
  TRDISP(u.el_total_size());
  TRDISP(u.total_size());
  TRDISP(u.dims());
  TRDISP(u.dims_array());
  TRDISP(u.depth());
  TRDISP(u.recursive_dims());
  TRDISP(u.element_dims());
  TRDISP(u[0]);
  TRDISP(u[2]);
  TRDISP(u.dat(0));
  TRDISP(u.dat(5));

  TRDISP(Indices{ 1,1 });
  TRDISP(DeepIndices{ {0},{0} });
  TRDISP(u[DeepIndices{ {0},{0} }]);
  TRDISP(DeepIndices{ {0},{1} });
  TRDISP(u[DeepIndices{ {0},{1} }]);
  TRDISP(DeepIndices{ {1},{0} });
  TRDISP(u[DeepIndices{ {1},{0} }]);
  TRDISP(DeepIndices{ {1},{1} });
  TRDISP(u[DeepIndices{ {1},{1} }]);
  TRDISP(DeepIndices{ {2},{0} });
  TRDISP(u[DeepIndices{ {2},{0} }]);
  TRDISP(DeepIndices{ {2},{1} });
  TRDISP(u[DeepIndices{ {2},{1} }]);

  TRDISP(sizeof(u)/(u.total_size()*sizeof(double)));


  CR();
  ECHO_CODE(Vector<double> v6(3));
  TRDISP(v6.size());
  TRDISP(v6.element_size());
  TRDISP(v6.dims());
  v6[0] = { 1 };
  v6[1] = { 3 };
  v6[2] = { 5 };
  TRDISP(v6);

  CR();
  ECHO_CODE(Dimensions dims7({ 3 }));
  TRDISP(dims7);
  ECHO_CODE(Vector<double> v7(dims7));
  TRDISP(v7.size());
  TRDISP(v7.element_size());
  TRDISP(v7.dims());
  v7[0] = { 1 };
  v7[1] = { 3 };
  v7[2] = { 5 };
  TRDISP(v7);


  CR();
  ECHO_CODE(Vector<double> v9(6, 7));
  TRDISP(v9.size());
  TRDISP(v9.element_size());
  TRDISP(v9.dims());
  TRDISP(v9);

  CR();
  ECHO_CODE(Vector<double> v10({ 2.2, 3.3, 4.4 }));
  TRDISP(v10.size());
  TRDISP(v10.element_size());
  TRDISP(v10.dims());
  TRDISP(v10);

  CR();
  ECHO_CODE(Vector<double> v11{ 2.2, 3.3, 4.4 });
  TRDISP(v11.size());
  TRDISP(v11.element_size());
  TRDISP(v11.dims());
  TRDISP(v11);

  CR();
  ECHO_CODE(Vector<double, 3> v12({ 2.2, 3.3, 4.4 }));
  TRDISP(v12.size());
  TRDISP(v12.element_size());
  TRDISP(v12.dims());
  TRDISP(v12);

  CR();
  ECHO_CODE(Vector<double, 3> v13{ 2.2, 3.3, 4.4 });
  TRDISP(v13.size());
  TRDISP(v13.element_size());
  TRDISP(v13.dims());
  TRDISP(v13);
  TRDISP(static_cast<std::valarray<double>>(v13));


  CR();
  ECHO_CODE(Indices ind1{ 2 });
  TRDISP(ind1);
  TRDISP(v13[ind1]);

  CR();
  ECHO_CODE(Vector<double> k = 100*range<double>(0, 10));
  TRDISP(k);
  TRDISP(SLC::even);
  ECHO_CODE(Vector<size_t> vindex(11, SLC::even));
  TRDISP(vindex);
  TRDISP(k[vindex]);
  TRDISP(k[SLC::even]);
  TRDISP(k[-1]);
  TRDISP(k[-2]);


  TRDISP(InitializerTrait< std::initializer_list<double> >::depth());
  {
    ECHO_CODE(typename InitializerTrait< std::initializer_list<double> >::BottomType temp{ 0 });
    TRDISP(temp);
  }
  TRDISP(InitializerTrait< std::initializer_list<std::initializer_list<double>> >::depth());
  {
    ECHO_CODE(typename InitializerTrait< std::initializer_list<std::initializer_list<double>> >::BottomType temp{ 0 });
    TRDISP(temp);
  }

  TRDISP(InitializerTrait< std::initializer_list<double> >::get_size_array({ 1 , 2, 3 }));
  TRDISP(InitializerTrait< std::initializer_list< std::initializer_list<double> > >::get_size_array({ {1, 2}, {3, 4}, {5, 6} }));

  using List0 = typename MakeInitializer<double, 0>::Type;
  TRDISP(display::getTypeName< List0 >());
  using List1 = typename MakeInitializer<double, 1>::Type;
  TRDISP(List0{ 4.4 });
  TRDISP(display::getTypeName< List1 >());
  TRDISP(List1{ 1,2,3 });
  using List2 = typename MakeInitializer<double, 2>::Type;
  TRDISP(display::getTypeName< List2 >());
  TRDISP(List2{ {1, 2}, {3, 4}, {5, 6} });


  TRDISP(array_of_one_value<int, 7, -1>());

  TRDISP((std::is_unsigned<decltype(1)>::value));
  TRDISP((std::is_unsigned<decltype(1u)>::value));
  TRDISP((std::is_unsigned<decltype(0)>::value));
  TRDISP((std::is_unsigned<decltype(0u)>::value));
  TRDISP((std::is_convertible<decltype(0), size_t>::value));
  TRDISP((std::is_convertible<decltype(-1), size_t>::value));
  TRDISP((std::is_convertible<decltype(3.14), size_t>::value));

  return 0;
}
