

# Mathématiques 0.42.3

Mathématiques is a novel mathematical library with 
* object classes based on **formal mathematical objects** and their operators
* _state of the art_ performance (both speed and memory usage)
* extensive printing and debugging tools


Mathématiques defines object classes for mathematical objects that are typically left to the user, greatly reducing development time:
  * nested multiarrays
  * discretized functions / mappings with definitions for domain, target
  * curvilinear and generalized coordinate systems
  * vector fields and vector calculus
  * tensor fields and tensor calculus
  * number systems / division algebras

Most importantly, Mathématiques fosters application code that is **compact** and **looks more like math** than code.


## Phase 1 (in progress): C++ Mathematical Library
  
Starting in the late 1990s and early 2000s, several C++ numerical libraries (such as [Armadillo](https://en.wikipedia.org/wiki/Armadillo_(C%2B%2B_library)), [Blitz++](https://en.wikipedia.org/wiki/Blitz%2B%2B), [boost uBLAS](https://www.boost.org/doc/libs/1_59_0/libs/numeric/ublas/doc/index.html), [Dlib](https://en.wikipedia.org/wiki/Dlib), [Eigen](https://en.wikipedia.org/wiki/Eigen_(C%2B%2B_library)), [MTL](https://en.wikipedia.org/wiki/Matrix_Template_Library), [Trilinos](https://en.wikipedia.org/wiki/Trilinos), [xtensor](https://xtensor.readthedocs.io/en/latest/index.html)) were created using the novel technique of [expression templating](https://en.wikipedia.org/wiki/Expression_templates) and mostly focus on linear algebra.  Expression templating is a technique independently developed by Todd Veldhuizen and David Vandevoorde that performs operations at compile time to produce C++ numerical code without the problem of intermediate objects and intermediate loops.

In the intervening years since the advent of expression templating, C++ has been greatly extended with five new versions (C++03, C++11, C++14, C++17, and C++20) and a sixth in progress (C++23).   It is these adavances that Mathématiques has built upon.   Most importantly is the introduction of [C++ concepts](https://en.wikipedia.org/wiki/Concepts_(C%2B%2B)).  Concepts are similar to [Java interfaces](https://en.wikipedia.org/wiki/Interface_(Java)) and allow for the definition of types according to properties instead of class hierarchies.  In other words, concepts are _compile-time_ [duck typing](https://en.wikipedia.org/wiki/Duck_typing): 

> If it walks like a duck and it quacks like a duck, then it must be a duck"

Not only do concepts avoid the problems associated with class hierarchies, they align with modern formal mathematics where objects and systems are defined via their properties.  An example is the definition of a [vector space](https://mathworld.wolfram.com/VectorSpace.html).


<br>


## Code Snippets


**Number Systems**

<table>
<thead>
<tr>
<td align="center">

$\mathbb{R}, \mathbb{I}, \mathbb{C}, \mathbb{H}$

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
double x = 23.2;
Imaginary<double> y = 5*i;
std::complex<double> z = 3 + 4*i;
Quaternion<double> q = 16 + 2*i + 3*j + 13*k;
```

</td>
</tr>
</tbody>
</table>
<br>




**Special Functions**

<table>
<thead>
<tr>
<td align="center">

$x \in [0,1]$ 

$f(x) = \Gamma(x)$ 

$g(x) = J_\nu(x)$ 

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
Vector<double> x = linspace(0., 1., 100);
Vector<double> f = tgamma(x);
Vector<double> g = cyl_bessel_j(nu, x);
```

</td>
</tr>
</tbody>
</table>
<br>


**Vectors, Matrices, and MultiArrays**

<table>
<thead>
<tr>
<td align="center">

$$\mathbf{v} =  \left[
\begin{matrix}
1 \cr
2 \cr
3 
\end{matrix} \right]$$

$$\mathbf{A} =  \left[
\begin{matrix}
1 & 2\cr
3 & 4
\end{matrix} \right]$$

$$\mathbf{M} =  \left[
\left[ \begin{matrix}
1 & 2\cr
3 & 4
\end{matrix} \right], 
\left[ \begin{matrix}
5 & 6\cr
7 & 8
\end{matrix} \right]
\right]$$

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
Vector<double, 3> v{ 1, 2, 3 };
Matrix<double, 2, 2> A{ {1 , 2}, {3, 4} };
MultiArray<double, 3, 2, 2, 2> M{ { {1,2}, {3,4} }, { {5,6}, {7,8} } };
```

</td>
</tr>
</tbody>
</table>
<br>




**Function of a vector**

<table>
<thead>
<tr>
<td align="center">

$\mathbf{w} = 1 + 10 \mathbf{v} + e^{i  [   2 \pi   +   \pi sin(  2 \pi \mathbf{v} + \pi / 6  )   ] }$

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
w = 1 + 10 * v + exp(i * (2 * pi + pi * sin(2 * pi * v + pi / 6)));
```

</td>
</tr>
</tbody>
</table>
<br>




**Linear Algebra**

<table>
<thead>
<tr>
<td align="center">

$\mathbf{y} = \mathbf{A} \cdot \mathbf{x}$

$\mathbf{y} = \mathbf{x}^\dagger \cdot ( \mathbf{A} \mathbf{A^\dagger} + \mathbf{A^\dagger} \mathbf{A}) \cdot \mathbf{x}$

$\mathbf{A} \overset {SVD}{\rightarrow} (\mathbf{U},\mathbf{S},\mathbf{V})$

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
y = A | x;
y = ~x | (A|~A + ~A|A) | x;
auto [U, S, V] = svd(A);
```

</td>
</tr>
</tbody>
</table>
<br>



**Discretized Mathematical Functions**

<table>
<thead>
<tr>
<td align="center">

$$H(x,p,t) = \frac{p^2}{2 m} + (1 + \frac{1}{2} \cos t)^2 x^2 $$ 

$$x \in [-1,1], \hspace2ex p \in [-10,10], \hspace2ex t \in [0,10]$$

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
NumericalFunction<double, 2, true> H({
        Interval<double>::interval(-1,1,100),
        Interval<double>::interval(-10,10,100),
        Interval<double>::interval(0,10,100)
      });

auto x = H.coordinates[0];
auto p = H.coordinates[1];
auto t = H.coordinates[2];
double m = 2;

H = 1/(2*m) * pow(p, 2) + pow(1 + 0.5*cos(t)*x, 2);
```

</td>
</tr>
</tbody>
</table>
<br>



**Vector Calculus**


<table>
<thead>
<tr>
<td align="center"><b>function</b></td>
<td align="center"><b>operator form</b></td>
<td align="center"><b>operation</b></td>
<td align="center"><b>standard notation</b></td>
</tr>
</thead>
<tbody>

<!-- grad -->
<tr>
<td align="center"> 

```C++
grad(f)
```
  
</td>
<td align="center"> 
  
```C++
nabla & f
```
  
</td>
<td align="center">gradient</td>
<td align="center">
   
$$
\vec \nabla f
$$

</td>
</tr>

<!-- div  -->

<tr>
<td align="center"> 

```C++
div(A)
```

</td>
<td align="center"> 
  
```C++
nabla | A 
```

</td>
<td align="center">divergence</td>
<td align="center">
   
$$
\vec{\nabla} \cdot \vec{A}
$$

</td>
</tr>

<!-- curl  -->
<tr>
<td align="center"> 

```C++
curl(A)
```

</td>
<td align="center"> 

```C++
nabla ^ A 
```
  

</td>
<td align="center">curl</td>
<td align="center">
   
$$
\vec \nabla \times \vec A
$$

</td>

</tr>


</tbody>
</table>

<br>
<table>
<thead>
<tr>
<td align="center">

$$\Phi(\vec{x},t) \hspace1ex \dot{=} \hspace1ex A_0 \frac{c^2 k_y}{\omega} \hspace0.5ex e^{i(k_y y - \omega t)}$$

$$\vec{A}(\vec{x},t) \hspace1ex \dot{=} \hspace1ex A_0 \hspace0.5ex e^{i(k_z z - \omega t)} \hspace0.5ex \hat{x} \hspace1ex + \hspace1ex A_0 \hspace0.5ex e^{i(k_y y - \omega t)} \hspace0.5ex \hat{y}$$

$$\vec{E}(\vec{x},t) \hspace1ex = - \vec{\nabla}\Phi - \frac{\partial \vec{A}}{\partial t} $$

$$\vec{B}(\vec{x},t) \hspace1ex = \vec{\nabla} \times  \vec{A}$$

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
Phi = A0 * c*c * ky / omega exp(i*(ky*y - omega*t));
A = expr{ A0 * exp(i*(kz*z - omega*t)), A0 * exp(i*(ky*y - omega*t)), 0 };
E = -nabla & Phi - pd(A, A.time);
B = nabla ^ A;
```

</td>
</tr>
</tbody>
</table>
<br>





**Tensors**

Utilizes index-free tensor notation.  Refer to e.g. [Misner, Thorne, Wheeler, _Gravitation_, 1973](https://en.wikipedia.org/wiki/Gravitation_(book)).


<table>
<thead>
<tr>
<td align="center">

$$ \omega(V) = V(\omega) = \omega_i V^i $$

$$ g(V,U) =  g_{ij} V^i U^j  = V_j U^j$$

$$ g(V,\cdot) =  g_{ij} V^i  = V_j$$

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
Vector<double, 3>::Tensor<L> omega{ 1,25,25 };
Vector<double, 3>::Tensor<H> V{ 1,2,3 };
Vector<double, 3>::Tensor<H> U{ 1,1,1 };
const NullType o;
Matrix<double, 3, 3>::Tensor<L, L> g{ {1, 0, 0}, {0, pow(r,2), 0}, {0, 0 , pow(r*sin(theta),2)} };

☀ omega(V) ➜ double 126;
☀ V(omega) ➜ double 126;

☀ g(V, U) ➜ double 126;
☀ g(V, o) ➜ Vector<double,3>::Tensor<L> {1, 50, 75};
```

</td>
</tr>
</tbody>
</table>
<br>




## Documentation

✳ [Introduction with Examples](doc/intro/README.md) ✳ 

[Benchmarks](doc/benchmarks/README.md)

[Full Documentation](doc/README.md)

<br>

---------------------------------
## Phase 2 (planned): Mathematics Built into High-Performance Language(s)

From the code examples above, it is evident that all we need to use standard mathematical notation in *C++* is
1. unicode support to allow math operator characters and greek letters (e.g. α β δ ε θ λ), chalkboard letters (e.g. ℕ ℤ ℚ ℝ ℂ) etc (ℵ ℑ ℌ ℜ ℨ ℓ ℱ ℒ ℛ)
2. ability to define the unicode math symbols (e.g. ✕, ∇, ∂, ∑, ∫, ⨂, ∧) as operators

Other language candidates to build upon are [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)) and [Carbon](https://en.wikipedia.org/wiki/Carbon_(programming_language)).

### Goals for Phase 2

Extend an existing high-performance language that internally implements the phase 1 library above plus
* supports unicode characters in source code 
  + supports greek language characters for variables
  + supports operator definitions for mathematical unicode symbols so that the code really looks like mathematical notation
  + also has multi-character ASCII alternatives for each unicode symbol
* modern, cloud-based module/package loader
* package repository site, eg [PyPi for Python](https://pypi.org/) and [npm for NodeJs](https://www.npmjs.com/), for **user-created** open-source packages
* web API for remote computation, likely using [gRPC](https://en.wikipedia.org/wiki/GRPC) and [GraphQL](https://en.wikipedia.org/wiki/GraphQL)
* support for Latex generation and interaction with Jupyter notebooks

