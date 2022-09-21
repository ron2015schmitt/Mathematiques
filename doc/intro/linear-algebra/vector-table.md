| function | operator form | operation | standard notation | requirements |
| :---: | :---: | :---: | :---: | :---: | 
| `dot(v, w)` | `v \| w` | inner product | $\mathbf{v} \cdot \mathbf{w} = \displaystyle\sum_{i=1}^{N} v_i w_i$ | vectors must be of same length | 
| `tensor_product(v,w)` | `v & w` | outer/tensor product | $\mathbf{v} \mathbf{w} = \left[ v_i w_j \right]$ | none | 
| `cross(v,w)` | `v ^ w` | cross product | $\mathbf{v} \times \mathbf{w} = \left(  v_2 w_3 - v_3 w_2, \enspace v_3 w_1 - v_1 w_3, \enspace v_1 w_2 - v_2 w_1 \right)$ | vectors must be of length $N = 3$ | 
| `conj(v)` | `~v` | complex conjugate | $\mathbf{v}^*$ | none | 