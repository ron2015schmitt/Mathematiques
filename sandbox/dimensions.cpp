#include "mathq.h"



int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  CR();
  ECHO(Vector<double, 3> v1);
  ETV(v1.size());
  ETV(v1.is_dynamic_value);
  ETV(v1.static_dims_array);
  ETV(v1);
  v1[0] = 2.2;
  ETV(v1);
  v1 = { 2.2, 4.4, -100.1 };
  ETV(v1);
  ETV(v1.dims());
  ETV(sizeof(v1)/(v1.total_size()*sizeof(double)));


  CR();
  ECHO(Vector<double> v2{ 3.1, 22.5, 100 });
  ETV(v2);
  ETV(v2.size());
  ETV(v2.dims());
  ETV(v2.is_dynamic_value);
  ETV(v2.static_dims_array);
  ETV(v2.resize(4));

  CR();
  ECHO(Vector<double, 3> v3{ 42.1, -2.5, 6.8 });
  ETV(v3);
  ETV(v3.size());
  ETV(v3.is_dynamic_value);
  ETV(v3.static_dims_array);
  ETV(v3.dims());

  CR();
  ECHO(Vector<double> v4);
  ETV(v4);
  ETV(v4.size());
  ETV(v4.is_dynamic_value);
  ETV(v4.static_dims_array);
  ETV(v4.dims());

  CR();
  ECHO(Vector<double> v4b(3));  // size 3
  ETV(v4b);
  ETV(v4b.size());
  ETV(v4b.is_dynamic_value);
  ETV(v4b.static_dims_array);
  ETV(v4b.dims());

  CR();
  ECHO(Vector<double, 5> v4c(3.14));  // set all vlaues to 3.14
  ETV(v4c);
  ETV(v4c.size());
  ETV(v4c.is_dynamic_value);
  ETV(v4c.static_dims_array);
  ETV(v4c.dims());


  CR();
  ECHO(Dimensions dims);
  ETV(dims.size());
  ETV(dims);
  ECHO(dims.resize(2));
  ECHO(dims[0] = 14);
  ECHO(dims[1] = 42);
  ETV(dims);



  CR();
  ECHO(Dimensions dims2);
  ECHO(dims2 = { 3,2,1 });
  ETV(dims2);
  ETV(dims2.getReduced());
  ECHO(Dimensions dims2b);
  ECHO(dims2b = { 3,1,2,1 });
  ETV(dims2b);
  ETV(dims2b.getReduced());
  ETV(equiv(dims2, dims2b));



  CR();
  ECHO(Dimensions dims3{ 33, 46, 77, 81 });
  ETV(dims3.size());
  ETV(dims3);
  ECHO(dims3 = { 13, 42, 56, 99 });
  ETV(dims3);


  CR();
  ECHO(Dimensions dims4 = *(new Dimensions(5)));
  ETV(dims4);

  CR();
  ECHO(Dimensions dims5{ 33, 46, 77, 81 });
  ETV(dims5.size());
  ETV(dims5);
  ECHO(dims5 = { 13, 42, 56, 99 });
  ETV(dims5);
  ETV(dims5.getReduced());
  ETV(dims5.num_elements());
  ETV(dims5.num_elements() == 13*42*56*99);



  CR();
  ECHO(RecursiveDimensions ndims1(2));
  ETV(ndims1.size());
  ETV(ndims1);
  ndims1[0] = dims;
  ndims1[1] = dims3;
  ETV(ndims1);


  CR();
  ECHO(RecursiveDimensions ndims2(2));
  ETV(ndims2.size());
  ETV(ndims2);
  ndims2 = { dims, dims3 };
  ETV(ndims2);

  CR();
  ECHO(RecursiveDimensions ndims3{ dims, dims3 });
  ETV(ndims3);

  CR();
  ECHO(RecursiveDimensions ndims4{ {3,2}, {5,7,1}, {3} });
  ETV(ndims4);
  ETV(ndims4.getEverse());

  CR();
  ETV(v1);
  ETV(v1.size());
  ETV(v1.element_size());
  ETV(v1.total_size());
  ETV(v1.dims());
  ETV(v1.depth());
  ETV(v1.recursive_dims());
  ETV(v1.element_dims());


  CR();
  ECHO(Vector<Vector<double, 2>> u2);
  ETV(u2);
  ETV(u2.size());
  ETV(u2.element_size());
  ETV(u2.total_size());
  ETV(u2.dims());
  ETV(u2.depth());
  ETV(u2.recursive_dims());
  ETV(u2.element_dims());


  CR();
  ECHO(Vector<Vector<double, 2>, 3> u);
  ETV(u.size());
  ETV(u.element_size());
  ETV(u.dims());
  u[0] = { 1,2 };
  u[1] = { 3,4 };
  u[2] = { 5,6 };
  ETV(u);
  ETV(u.recursive_dims());
  u = { {11,12}, {13,14}, {15,16} };
  ETV(u);
  ETV(u.size());
  ETV(u.element_size());
  ETV(u.el_total_size());
  ETV(u.total_size());
  ETV(u.dims());
  ETV(u.dims_array());
  ETV(u.depth());
  ETV(u.recursive_dims());
  ETV(u.element_dims());
  ETV(u[0]);
  ETV(u[2]);
  ETV(u.dat(0));
  ETV(u.dat(5));

  ETV(Indices{ 1,1 });
  ETV(DeepIndices{ {0},{0} });
  ETV(u[DeepIndices{ {0},{0} }]);
  ETV(DeepIndices{ {0},{1} });
  ETV(u[DeepIndices{ {0},{1} }]);
  ETV(DeepIndices{ {1},{0} });
  ETV(u[DeepIndices{ {1},{0} }]);
  ETV(DeepIndices{ {1},{1} });
  ETV(u[DeepIndices{ {1},{1} }]);
  ETV(DeepIndices{ {2},{0} });
  ETV(u[DeepIndices{ {2},{0} }]);
  ETV(DeepIndices{ {2},{1} });
  ETV(u[DeepIndices{ {2},{1} }]);

  ETV(sizeof(u)/(u.total_size()*sizeof(double)));


  CR();
  ECHO(Vector<double> v6(3));
  ETV(v6.size());
  ETV(v6.element_size());
  ETV(v6.dims());
  v6[0] = { 1 };
  v6[1] = { 3 };
  v6[2] = { 5 };
  ETV(v6);

  CR();
  ECHO(Dimensions dims7({ 3 }));
  ETV(dims7);
  ECHO(Vector<double> v7(dims7));
  ETV(v7.size());
  ETV(v7.element_size());
  ETV(v7.dims());
  v7[0] = { 1 };
  v7[1] = { 3 };
  v7[2] = { 5 };
  ETV(v7);


  CR();
  ECHO(Vector<double> v9(6, 7));
  ETV(v9.size());
  ETV(v9.element_size());
  ETV(v9.dims());
  ETV(v9);

  CR();
  ECHO(Vector<double> v10({ 2.2, 3.3, 4.4 }));
  ETV(v10.size());
  ETV(v10.element_size());
  ETV(v10.dims());
  ETV(v10);

  CR();
  ECHO(Vector<double> v11{ 2.2, 3.3, 4.4 });
  ETV(v11.size());
  ETV(v11.element_size());
  ETV(v11.dims());
  ETV(v11);

  CR();
  ECHO(Vector<double, 3> v12({ 2.2, 3.3, 4.4 }));
  ETV(v12.size());
  ETV(v12.element_size());
  ETV(v12.dims());
  ETV(v12);

  CR();
  ECHO(Vector<double, 3> v13{ 2.2, 3.3, 4.4 });
  ETV(v13.size());
  ETV(v13.element_size());
  ETV(v13.dims());
  ETV(v13);
  ETV(static_cast<std::valarray<double>>(v13));


  CR();
  ECHO(Indices ind1{ 2 });
  ETV(ind1);
  ETV(v13[ind1]);

  CR();
  ECHO(Vector<double> k = 100*range<double>(0, 10));
  ETV(k);
  ETV(SLC::even);
  ECHO(Vector<size_t> vindex(11, SLC::even));
  ETV(vindex);
  ETV(k[vindex]);
  ETV(k[SLC::even]);
  ETV(k[-1]);
  ETV(k[-2]);


  ETV(InitializerTrait< std::initializer_list<double> >::depth());
  {
    ECHO(typename InitializerTrait< std::initializer_list<double> >::BottomType temp{ 0 });
    ETV(temp);
  }
  ETV(InitializerTrait< std::initializer_list<std::initializer_list<double>> >::depth());
  {
    ECHO(typename InitializerTrait< std::initializer_list<std::initializer_list<double>> >::BottomType temp{ 0 });
    ETV(temp);
  }

  ETV(InitializerTrait< std::initializer_list<double> >::get_size_array({ 1 , 2, 3 }));
  ETV(InitializerTrait< std::initializer_list< std::initializer_list<double> > >::get_size_array({ {1, 2}, {3, 4}, {5, 6} }));

  using List0 = typename MakeInitializer<double, 0>::Type;
  ETV(display::getTypeName< List0 >());
  using List1 = typename MakeInitializer<double, 1>::Type;
  ETV(List0{ 4.4 });
  ETV(display::getTypeName< List1 >());
  ETV(List1{ 1,2,3 });
  using List2 = typename MakeInitializer<double, 2>::Type;
  ETV(display::getTypeName< List2 >());
  ETV(List2{ {1, 2}, {3, 4}, {5, 6} });


  ETV(array_of_one_value<int, 7, -1>());

  ETV((std::is_unsigned<decltype(1)>::value));
  ETV((std::is_unsigned<decltype(1u)>::value));
  ETV((std::is_unsigned<decltype(0)>::value));
  ETV((std::is_unsigned<decltype(0u)>::value));
  ETV((std::is_convertible<decltype(0), size_t>::value));
  ETV((std::is_convertible<decltype(-1), size_t>::value));
  ETV((std::is_convertible<decltype(3.14), size_t>::value));

  return 0;
}
