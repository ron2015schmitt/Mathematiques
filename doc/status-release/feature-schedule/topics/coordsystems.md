# 2D and 3D curvilinear coordinate systems

_Back to [Table of Contents](../README.md)_

1. 2D curvi-linear coordinate systems
   1. define methods 
      * `Vector<D,2> toXY(Vector<D,2>)`
      * `Vector<D,2> fromXY(Vector<D,2>)`
      * orthonormal basis vectors
      * `Matrix<D,2,2> metric(Vector<D,2>)`
      *  dot product in general curvi-linear coordinate systems: need the orthonormal basis vectors
      * `Vector<D,2> grad(Scalar<mesh>)`
      * `Scalar<D>   div(Vector<mesh,2>)`
   1. Pre-defined coordinate systems (polar)
   1. Arbitrary coordinate systems (pass lambdas for calculating)
   
1. Repeat Above for 3D (spherical, cylindrical)
   

