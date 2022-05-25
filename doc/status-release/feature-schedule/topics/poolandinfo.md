# Create MultiArray Pool and MultiArray info

_Back to [Table of Contents](../README.md)_

## MultiArrayPool

* Meyer's singleton
* map:
   * keys are of type ```(void \*)```: the pointer to the address of the tensor
   * values are of type ```MultiArrayInfo```

* Add tensor to the MultiArrayPool in the constructor
* Remove tensor from the MultiArrayPool in the deconstructor


## MultiArrayInfo

contains fields:
* ```MultiArrayAbstract*```  same as key point but cast as MultiArrayAbstract
* isRegistered boolean 
* variable name
* file name 
* line number
* function name
* pretty function name

* to get tensor 
   * use tensor enum method and then cast accordingly.

The rest are set by using ```dregister(t)``` macro

If a tensor has not been registered, the pointer address will be used for display.

## info

Define ```info``` function that displays all of the above, as well as tensor class, dimensions, and depth

   

