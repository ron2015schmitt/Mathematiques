[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.029</h1>](../../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Why?](../../why/README.md)<br>
Chapter 4. [Objectives](../../objectives/README.md)<br>
Chapter 5. [Versioning](../../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../../development-schedule/README.md)<br>
Chapter 8. _Introduction with Examples_ <br>
Chapter 9. [Installation](../../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 11. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 12. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 13. [Tests](../../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [8. Introduction with Examples](../README.md)<br>
8.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
8.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
8.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
8.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
8.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
8.6. [MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)<br>
8.7. [Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)<br>
8.8. [Linear Algebra](../linear-algebra/README.md)<br>
8.9. [Indexing, Masks, Slicing, Sorting, etc.](../sort-mask-slice/README.md)<br>
8.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
8.11. [Numerical / Discretized Mathematical Function Objects](../multi-var-calculus/README.md)<br>
8.12. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
8.13. _Vector Calculus and Curvilinear Coordinates_ <br>
8.14. [Tensors](../tensors/README.md)<br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.13. Vector Calculus and Curvilinear Coordinates



Mathématiques supports 
CartesianCoords - default constructor
CartesianCoords<double, 2, false> coords;
☀ HasTimeCoord<decltype(coords)> ➜ bool false;
☀ HasNotTimeCoord<decltype(coords)> ➜ bool true;
2D CartesianCoords & CurvilinearField
2D CartesianCoords from Intervals
CartesianCoords<double, 2, false> coords1({ Interval<double>::interval(-1,1,5), Interval<double>::interval(2,3,3), });
2D CartesianCoords copy constructor
CartesianCoords<double, 2, false> coords(coords1);
☀ coords ➜ CartesianCoords<double,Ndims=2,TimeCoord=false> (x=[-1, 1], N=5; y=[2, 3], N=3);
☀ HasTimeCoord<decltype(coords)> ➜ bool false;
☀ HasNotTimeCoord<decltype(coords)> ➜ bool true;
CurvilinearField - Scalar 2D
CurvilinearField<double, 0, decltype(coords)> field0(coords);
auto& x = coords.x();
auto& y = coords.y();
field0() = -3*x + 2*y;
☀ field0 ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {7, 8, 9},
  {5.5, 6.5, 7.5},
  {4, 5, 6},
  {2.5, 3.5, 4.5},
  {1, 2, 3}
};
☀ x ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {-1, -1, -1},
  {-0.5, -0.5, -0.5},
  {0, 0, 0},
  {0.5, 0.5, 0.5},
  {1, 1, 1}
};
☀ y ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {2, 2.5, 3},
  {2, 2.5, 3},
  {2, 2.5, 3},
  {2, 2.5, 3},
  {2, 2.5, 3}
};
☀ IsGridlike<decltype(x)> ➜ bool true;
☀ IsMultiArray<decltype(x)> ➜ bool true;
☀ IsWritableExpressionOrArray<decltype(x)> ➜ bool true;
☀ x.isNotExpression ➜ bool true;
partials of a 2D grid
☀ coords.pd(x, 0) ➜ Matrix<double> 
{
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1}
};
☀ coords.pd(x, 1) ➜ Matrix<double> 
{
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};
partials of a 2D Scalar CurvilinearField
☀ pd(field0, 0) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3}
};
☀ pd(field0, 1) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2}
};
Gradient of a 2D grid
☀ coords.grad(x) ➜ Vector<Matrix<double>,2> {
{
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1}
}, 
{
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
}};
☀ coords.grad(y) ➜ Vector<Matrix<double>,2> {
{
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
}, 
{
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1}
}};
Gradient of a 2D CurvilinearField
☀ grad(field0) ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=2,TimeCoord=false>> {
{
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3}
}, 
{
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2}
}};
Divergence of a 2D CurvilinearField - ex 1
auto A = grad(field0);
☀ A ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=2,TimeCoord=false>> {
{
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3},
  {-3, -3, -3}
}, 
{
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2},
  {2, 2, 2}
}};
☀ div(A) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};
Divergence of a 2D CurvilinearField - ex 2
field0() = sqrt(x*x+y*y);
☀ grad(field0) ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=2,TimeCoord=false>> {
{
  {-0.445087, -0.370614, -0.315896},
  {-0.24283, -0.19622, -0.164443},
  {0, -2.22045e-16, -2.22045e-16},
  {0.24283, 0.19622, 0.164443},
  {0.445087, 0.370614, 0.315896}
}, 
{
  {0.899848, 0.92621, 0.952571},
  {0.971999, 0.979828, 0.987658},
  {1, 1, 1},
  {0.971999, 0.979828, 0.987658},
  {0.899848, 0.92621, 0.952571}
}};
☀ div(grad(field0)) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=false>> 
{
  {0.389616, 0.365133, 0.33398},
  {0.47427, 0.393548, 0.335884},
  {0.499185, 0.399716, 0.333215},
  {0.47427, 0.393548, 0.335884},
  {0.389616, 0.365133, 0.33398}
};
2+1D CartesianCoords & CurvilinearField
2+1D CartesianCoords Properties
CartesianCoords<double, 2, true> coords({ Interval<double>::interval(-1,1,3), Interval<double>::interval(-1,1,3), Interval<double>::interval(0,2,3), });
☀ coords ➜ CartesianCoords<double,Ndims=2,TimeCoord=true> (x=[-1, 1], N=3; y=[-1, 1], N=3; t=[0, 2], N=3);
☀ HasTimeCoord<decltype(coords)> ➜ bool true;
☀ HasNotTimeCoord<decltype(coords)> ➜ bool false;
☀ coords[0] ➜ MultiArray_RepeatVector<double, rank=3> 
{
  {
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1}
  }
};
☀ coords.x() ➜ MultiArray_RepeatVector<double, rank=3> 
{
  {
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1}
  }
};
☀ coords[1] ➜ MultiArray_RepeatVector<double, rank=3> 
{
  {
    {-1, -1, -1},
    {0, 0, 0},
    {1, 1, 1}
  },
  {
    {-1, -1, -1},
    {0, 0, 0},
    {1, 1, 1}
  },
  {
    {-1, -1, -1},
    {0, 0, 0},
    {1, 1, 1}
  }
};
☀ coords.y() ➜ MultiArray_RepeatVector<double, rank=3> 
{
  {
    {-1, -1, -1},
    {0, 0, 0},
    {1, 1, 1}
  },
  {
    {-1, -1, -1},
    {0, 0, 0},
    {1, 1, 1}
  },
  {
    {-1, -1, -1},
    {0, 0, 0},
    {1, 1, 1}
  }
};
☀ coords[2] ➜ MultiArray_RepeatVector<double, rank=3> 
{
  {
    {0, 1, 2},
    {0, 1, 2},
    {0, 1, 2}
  },
  {
    {0, 1, 2},
    {0, 1, 2},
    {0, 1, 2}
  },
  {
    {0, 1, 2},
    {0, 1, 2},
    {0, 1, 2}
  }
};
☀ coords.t() ➜ MultiArray_RepeatVector<double, rank=3> 
{
  {
    {0, 1, 2},
    {0, 1, 2},
    {0, 1, 2}
  },
  {
    {0, 1, 2},
    {0, 1, 2},
    {0, 1, 2}
  },
  {
    {0, 1, 2},
    {0, 1, 2},
    {0, 1, 2}
  }
};
☀ coords.J() ➜ double 1;
☀ coords.g() ➜ Matrix<double, 2⨯2> 
{
  {1, 0},
  {0, 1}
};
☀ coords.basis_vec(0) ➜ Vector<double,2> {1, 0};
☀ coords.basis_vec(1) ➜ Vector<double,2> {0, 1};
☀ coords.basis() ➜ Vector<Vector<double,2>,2> {{1, 0}, {0, 1}};
☀ coords.at(0, 0, 0) ➜ CartesianCoords<double,Ndims=2,TimeCoord=true>::Point (x=-1, y=-1, t=0);
☀ coords.at(1, 2, 2) ➜ CartesianCoords<double,Ndims=2,TimeCoord=true>::Point (x=0, y=1, t=2);
☀ coords.at(0, 0, 0)+coords.at(1, 2, 2) ➜ Vector<double> {-1, 0, 2};
2+1D Scalar CurvilinearField
CurvilinearField<double, 0, decltype(coords)> field(coords);
auto& x = coords.x();
auto& y = coords.y();
field() = -4*x + 5*y;
☀ field ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=true>> 
{
  {
    {-1, -1, -1},
    {4, 4, 4},
    {9, 9, 9}
  },
  {
    {-5, -5, -5},
    {0, 0, 0},
    {5, 5, 5}
  },
  {
    {-9, -9, -9},
    {-4, -4, -4},
    {1, 1, 1}
  }
};
2+1D Partials of Scalar CurvilinearField
☀ pd(field, 0) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=true>> 
{
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  },
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  },
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  }
};
☀ pd(field, 1) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=true>> 
{
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  },
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  },
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  }
};
☀ pd(field, 2) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=true>> 
{
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  }
};
2+1D Gradient of Scalar CurvilinearField
☀ grad(field) ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=2,TimeCoord=true>> {
{
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  },
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  },
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  }
}, 
{
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  },
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  },
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  }
}};
Divergence of a 2D+1 CurvilinearField - ex 1
auto A = grad(field);
☀ A ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=2,TimeCoord=true>> {
{
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  },
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  },
  {
    {-4, -4, -4},
    {-4, -4, -4},
    {-4, -4, -4}
  }
}, 
{
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  },
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  },
  {
    {5, 5, 5},
    {5, 5, 5},
    {5, 5, 5}
  }
}};
☀ div(A) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=true>> 
{
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  }
};
Divergence of a 2D+1 CurvilinearField - ex 2
field() = sqrt(x*x+y*y);
☀ grad(field) ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=2,TimeCoord=true>> {
{
  {
    {-0.828427, -0.828427, -0.828427},
    {-2, -2, -2},
    {-0.828427, -0.828427, -0.828427}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0.828427, 0.828427, 0.828427},
    {2, 2, 2},
    {0.828427, 0.828427, 0.828427}
  }
}, 
{
  {
    {-0.828427, -0.828427, -0.828427},
    {0, 0, 0},
    {0.828427, 0.828427, 0.828427}
  },
  {
    {-2, -2, -2},
    {0, 0, 0},
    {2, 2, 2}
  },
  {
    {-0.828427, -0.828427, -0.828427},
    {0, 0, 0},
    {0.828427, 0.828427, 0.828427}
  }
}};
☀ div(grad(field)) ➜ CurvilinearField<double,0,CartesianCoords<double,Ndims=2,TimeCoord=true>> 
{
  {
    {1.65685, 1.65685, 1.65685},
    {2.82843, 2.82843, 2.82843},
    {1.65685, 1.65685, 1.65685}
  },
  {
    {2.82843, 2.82843, 2.82843},
    {4, 4, 4},
    {2.82843, 2.82843, 2.82843}
  },
  {
    {1.65685, 1.65685, 1.65685},
    {2.82843, 2.82843, 2.82843},
    {1.65685, 1.65685, 1.65685}
  }
};
2D PolarCoords & CurvilinearField
2D PolarCoords Properties
PolarCoords<double, false> coords({ Interval<double>::o_interval_c(0,1,3), Interval<double>::c_interval_o(0,2*3.14159265,5), });
☀ coords ➜ PolarCoords<double,Ndims=2,TimeCoord=false> (r=(0, 1), N=3; 𝜑=[0, 6.28319], N=5);
☀ HasTimeCoord<decltype(coords)> ➜ bool false;
☀ HasNotTimeCoord<decltype(coords)> ➜ bool true;
☀ coords.r() ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {0.333333, 0.333333, 0.333333, 0.333333, 0.333333},
  {0.666667, 0.666667, 0.666667, 0.666667, 0.666667},
  {1, 1, 1, 1, 1}
};
☀ coords.phi() ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {0, 1.25664, 2.51327, 3.76991, 5.02655},
  {0, 1.25664, 2.51327, 3.76991, 5.02655},
  {0, 1.25664, 2.51327, 3.76991, 5.02655}
};
☀ coords.dims() ➜ Dimensions 2;
☀ coords.J() ➜ MultiArray_RepeatVector<double, rank=2> 
{
  {0.333333, 0.333333, 0.333333, 0.333333, 0.333333},
  {0.666667, 0.666667, 0.666667, 0.666667, 0.666667},
  {1, 1, 1, 1, 1}
};
☀ coords.g() ➜ Matrix<Matrix<double>, 2⨯2> 
{
  {
{
  {1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1}
}, 
{
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0}
}},
  {
{
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0}
}, 
{
  {0.111111, 0.111111, 0.111111, 0.111111, 0.111111},
  {0.444444, 0.444444, 0.444444, 0.444444, 0.444444},
  {1, 1, 1, 1, 1}
}}
};
☀ coords.basis_vec(0) ➜ Vector<Matrix<double>,2> {
{
  {1, 0.309017, -0.809017, -0.809017, 0.309017},
  {1, 0.309017, -0.809017, -0.809017, 0.309017},
  {1, 0.309017, -0.809017, -0.809017, 0.309017}
}, 
{
  {0, 0.951057, 0.587785, -0.587785, -0.951057},
  {0, 0.951057, 0.587785, -0.587785, -0.951057},
  {0, 0.951057, 0.587785, -0.587785, -0.951057}
}};
☀ coords.basis_vec(1) ➜ Vector<Matrix<double>,2> {
{
  {-0, -0.951057, -0.587785, 0.587785, 0.951057},
  {-0, -0.951057, -0.587785, 0.587785, 0.951057},
  {-0, -0.951057, -0.587785, 0.587785, 0.951057}
}, 
{
  {1, 0.309017, -0.809017, -0.809017, 0.309017},
  {1, 0.309017, -0.809017, -0.809017, 0.309017},
  {1, 0.309017, -0.809017, -0.809017, 0.309017}
}};
☀ coords.basis() ➜ Vector<Vector<Matrix<double>,2>,2> {{
{
  {1, 0.309017, -0.809017, -0.809017, 0.309017},
  {1, 0.309017, -0.809017, -0.809017, 0.309017},
  {1, 0.309017, -0.809017, -0.809017, 0.309017}
}, 
{
  {0, 0.951057, 0.587785, -0.587785, -0.951057},
  {0, 0.951057, 0.587785, -0.587785, -0.951057},
  {0, 0.951057, 0.587785, -0.587785, -0.951057}
}}, {
{
  {-0, -0.951057, -0.587785, 0.587785, 0.951057},
  {-0, -0.951057, -0.587785, 0.587785, 0.951057},
  {-0, -0.951057, -0.587785, 0.587785, 0.951057}
}, 
{
  {1, 0.309017, -0.809017, -0.809017, 0.309017},
  {1, 0.309017, -0.809017, -0.809017, 0.309017},
  {1, 0.309017, -0.809017, -0.809017, 0.309017}
}}};
☀ coords.at(0, 0) ➜ PolarCoords<double,Ndims=2,TimeCoord=false>::Point (r=0.333333, 𝜑=0);
☀ coords.at(1, 2) ➜ PolarCoords<double,Ndims=2,TimeCoord=false>::Point (r=0.666667, 𝜑=2.51327);
☀ coords.at(0, 0)+coords.at(1, 2) ➜ Vector<double> {1, 2.51327};
2D PolarCoords Scalar CurvilinearField
CurvilinearField<double, 0, decltype(coords)> field(coords);
auto& r = coords.r();
auto& phi = coords.phi();
field() = -4*r + 5*phi;
☀ field ➜ CurvilinearField<double,0,PolarCoords<double,Ndims=2,TimeCoord=false>> 
{
  {-1.33333, 4.94985, 11.233, 17.5162, 23.7994},
  {-2.66667, 3.61652, 9.8997, 16.1829, 22.4661},
  {-4, 2.28319, 8.56637, 14.8496, 21.1327}
};
2D  PolarCoords Partials of Scalar CurvilinearField
☀ pd(field, 0) ➜ CurvilinearField<double,0,PolarCoords<double,Ndims=2,TimeCoord=false>> 
{
  {-4, -4, -4, -4, -4},
  {-4, -4, -4, -4, -4},
  {-4, -4, -4, -4, -4}
};
☀ pd(field, 1) ➜ CurvilinearField<double,0,PolarCoords<double,Ndims=2,TimeCoord=false>> 
{
  {5, 5, 5, 5, 5},
  {5, 5, 5, 5, 5},
  {5, 5, 5, 5, 5}
};
☀ pd(field, 1)()/r ➜ Matrix<double> 
{
  {15, 15, 15, 15, 15},
  {7.5, 7.5, 7.5, 7.5, 7.5},
  {5, 5, 5, 5, 5}
};
2D PolarCoords Gradient of Scalar CurvilinearField
☀ grad(field) ➜ CurvilinearField<double,1,PolarCoords<double,Ndims=2,TimeCoord=false>> {
{
  {-4, -4, -4, -4, -4},
  {-4, -4, -4, -4, -4},
  {-4, -4, -4, -4, -4}
}, 
{
  {15, 15, 15, 15, 15},
  {7.5, 7.5, 7.5, 7.5, 7.5},
  {5, 5, 5, 5, 5}
}};
Divergence of a 2D PolarCoords CurvilinearField - ex 1
auto A = grad(field);
☀ A ➜ CurvilinearField<double,1,PolarCoords<double,Ndims=2,TimeCoord=false>> {
{
  {-4, -4, -4, -4, -4},
  {-4, -4, -4, -4, -4},
  {-4, -4, -4, -4, -4}
}, 
{
  {15, 15, 15, 15, 15},
  {7.5, 7.5, 7.5, 7.5, 7.5},
  {5, 5, 5, 5, 5}
}};
☀ div(A) ➜ CurvilinearField<double,0,PolarCoords<double,Ndims=2,TimeCoord=false>> 
{
  {-12, -12, -12, -12, -12},
  {-6, -6, -6, -6, -6},
  {-4, -4, -4, -4, -4}
};
Divergence of a 2D+1 CurvilinearField - ex 2
field() = r*r;
☀ grad(field) ➜ CurvilinearField<double,1,PolarCoords<double,Ndims=2,TimeCoord=false>> {
{
  {0.666667, 0.666667, 0.666667, 0.666667, 0.666667},
  {1.33333, 1.33333, 1.33333, 1.33333, 1.33333},
  {2, 2, 2, 2, 2}
}, 
{
  {0, -1.10436e-17, 1.10436e-17, 1.10436e-17, 0},
  {0, -2.20872e-17, 2.20872e-17, 2.20872e-17, 0},
  {0, 0, 0, 0, 0}
}};
☀ div(grad(field)) ➜ CurvilinearField<double,0,PolarCoords<double,Ndims=2,TimeCoord=false>> 
{
  {4, 4, 4, 4, 4},
  {4, 4, 4, 4, 4},
  {4, 4, 4, 4, 4}
};
3D curl of a CurvilinearField - ex1: output is curlA = {0,1,0}
☀ coords ➜ CartesianCoords<double,Ndims=3,TimeCoord=false> (x=[-1, 1], N=5; y=[-1, 1], N=5; z=[-1, 1], N=5);
CurvilinearField<double, 1, CartesianCoords<double, 3, false>> A(coords);
A[0] = coords.z();
auto B = curl(A);
☀ B ➜ CurvilinearField<double,1,CartesianCoords<double,Ndims=3,TimeCoord=false>> {
{
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  }
}, 
{
  {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
  },
  {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
  },
  {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
  },
  {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
  },
  {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
  }
}, 
{
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  }
}};

<br>



| ⇦ <br />[Calculus on Complex Number Domains](../complex-calculus/README.md)  | [Introduction with Examples](../README.md)<br />Vector Calculus and Curvilinear Coordinates<br /><img width=1000/> | ⇨ <br />[Tensors](../tensors/README.md)   |
| ------------ | :-------------------------------: | ------------ |

