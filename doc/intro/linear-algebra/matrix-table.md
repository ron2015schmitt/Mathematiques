<table>
<thead>
<tr>
<td align="center"><b>function</b></td>
<td align="center"><b>operator form</b></td>
<td align="center"><b>operation</b></td>
<td align="center"><b>standard notation</b></td>
<td align="center"><b>requirements</b></td>
</tr>
</thead>
<tbody>

<!-- dot product  -->
<tr>
<td align="center"> 

```C++
dot(A, B)
```
  
</td>
<td align="center"> 
  
```C++
A | B
```
  
</td>
<td align="center">inner product</td>
<td align="center">
   
$$
\mathbf{A} \cdot \mathbf{B} = \displaystyle\sum_{j=1}^{M} A_{ij} B_{jk}
$$

</td>
<td align="center">
      
$$
\left. \begin{array}{c} \mathbf{A} = L \negmedspace \times  \negmedspace M \text{matrix} \\\\ 
\mathbf{B} = M  \negmedspace \times  \negmedspace  N \text{matrix} \end{array}  \right.
$$

</td>
</tr>

<!-- outer product  -->

<tr>
<td align="center"> 

```C++
tensor_product(A,B)
```

</td>
<td align="center"> 
  
```C++
A & B
```

</td>
<td align="center">outer/tensor product</td>
<td align="center">
   
$$
\mathbf{A} \mathbf{B} = \left[ A_{ij} B_{kl} \right]
$$

</td>
<td align="center">
none
</td>
</tr>

<!-- conjugate  -->
<tr>
<td align="center"> 

```C++
conj(A,B)
```

</td>
<td align="center"> 
  

</td>
<td align="center">conjugate</td>
<td align="center">
   
$$
\left\{ \begin{array}{ll} \mathbf{A} & \mathbf{A} \enspace \text{real} \\\\ \mathbf{A}^{*}  & \mathbf{A} \enspace \text{complex}  \end{array} \right. 
$$

</td>
<td align="center">
none
</td>
</tr>

<!-- transpose  -->
<tr>
<td align="center"> 

```C++
transpose(A,B)
```

</td>
<td align="center"> 
  
```C++

```

</td>
<td align="center">transpose</td>
<td align="center">
   
$$
\mathbf{A}^T
$$

</td>
<td align="center">
none
</td>
</tr>


<!-- adjoint  -->
<tr>
<td align="center"> 

```C++
adjoint(A,B)
```

</td>
<td align="center"> 
  
```C++
~A
```

</td>
<td align="center">adjoint</td>
<td align="center">
   
$$
\left\{ \begin{array}{ll} \mathbf{A}^T & \mathbf{A} \enspace \text{real} \\\\ \mathbf{A}^{*T}  & \mathbf{A} \enspace \text{complex}  \end{array} \right. 
$$

</td>
<td align="center">
none
</td>
</tr>

</tbody>
</table>
