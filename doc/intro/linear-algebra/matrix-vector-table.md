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
dot(v, A)
```
  
</td>
<td align="center"> 
  
```C++
v | A
```
  
</td>
<td align="center">inner product</td>
<td align="center">
   
$$
\mathbf{v} \cdot \mathbf{A} = \displaystyle\sum_{i=1}^{M} v_{i} A_{ij}
$$

</td>
<td align="center">
      
$$
\left. \begin{array}{l} \mathbf{v} \text{ has length}=M   \\
\mathbf{A} \text{ has dimensions}=M \times N   \end{array} \right. 
$$

</td>
</tr>


<!-- dot product 2  -->
<tr>
<td align="center"> 

```C++
dot(A, v)
```
  
</td>
<td align="center"> 
  
```C++
A | v
```
  
</td>
<td align="center">inner product</td>
<td align="center">
   
$$
\mathbf{A} \cdot \mathbf{v} = \displaystyle\sum_{j=1}^{N}  A_{ij} v_{j}
$$

</td>
<td align="center">
      
$$
\left. \begin{array}{l} \mathbf{A} \text{ has dimensions}=M \times N   \\
\mathbf{v} \text{ has length}=N \end{array} \right. 
$$

</td>
</tr>



<!-- outer product  -->

<tr>
<td align="center"> 

```C++
tensor_product(v, A)
```

</td>
<td align="center"> 
  
```C++
v & A
```

</td>
<td align="center">outer/tensor product</td>
<td align="center">
   
$$
\mathbf{v} \mathbf{A} = \left[ v_{i} A_{jk} \right]
$$

</td>
<td align="center">
none
</td>
</tr>



<!-- outer product  -->

<tr>
<td align="center"> 

```C++
tensor_product(A,v)
```

</td>
<td align="center"> 
  
```C++
A & v
```

</td>
<td align="center">outer/tensor product</td>
<td align="center">
   
$$
\mathbf{A} \mathbf{v} = \left[ A_{ij} v_{k} \right]
$$

</td>
<td align="center">
none
</td>
</tr>


</tbody>
</table>
