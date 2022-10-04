

# Mathématiques 0.42.1-alpha.034


## Phase 1 (in progress): C++ Numerical Library
  
Using modern C++ (C++20), create an extensive, open source, numerical C++ library that provides / supports

* compact **data structures** that represent **mathematical objects** 
* user **code that looks like mathematical notation**
* **state of the art performance** (both speed and memory usage)
* **multithreading**
* convenient **pretty printing of results** including **data type information**
* several **compilation modes** (DEBUG, PRODUCTION) via command line flags and the C++ macro preprocessor
  + **DEBUG mode** checks bounds, vector and matrix sizes, etc and generates clear, pretty printed errors to stderr
  + **PRODUCTION mode** runs as without any checks
* **i/o in popular formats** for analysis and plotting

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
<td align="center">

$\mathbf{E} = \mathbf{\nabla} \cdot \mathbf{\Phi}$

</td>
</tr>
</thead>
<tbody>
<tr>
<td>

```C++
E = nabla | Phi;
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

$$ \omega(V) = V(\omega) = V^i \omega\_j $$

$$ g(V,U) =  g_{ij} V^i U^j  = V_i U^i$$

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

[Why?](doc/why/README.md)

✳ [Introduction with Examples](doc/intro/README.md) ✳ 

[Benchmarks](doc/benchmarks/README.md)

[Full Documentation](doc/README.md)

<br>

---------------------------------
## Phase 2 (planned): Mathematics Built into a Modern High-Performance Language


From these, it is evident that all we need to use standard mathematical notation in C++ is
1. unicode support to allow math operator characters and greek letters, chalkboard letters etc.
2. Ability to define the math symbols as templated operators


Create a new language that implements the phase 1 library above plus
* supports unicode characters in source code 
  + supports greek language characters for variables
  + supports operator definitions for mathematical unicode symbols so that the code really looks like mathematical notation
  + also has multi-character ASCII symbols for each unicode symbol
* modern, cloud-based module/package loader
* package repository site, eg [npm for NodeJs](https://www.npmjs.com/) for user-created open-source packages
* web API for remote computation, likely using [gRPC](https://en.wikipedia.org/wiki/GRPC) and [GraphQL](https://en.wikipedia.org/wiki/GraphQL)

The current language candidates to build upon are [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)) and [Carbon](https://en.wikipedia.org/wiki/Carbon_(programming_language)).

