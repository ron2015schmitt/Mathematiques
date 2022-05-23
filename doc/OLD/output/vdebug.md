
[Table of Contents](README.md)


# Debugging in Mathématiques
_This document was automatically generated from file_ **`vdebug.cpp`** (Mathématiques-v3.2-r4).

The Mathématiques library provides extensive debugging operation, turned on using the flag `MATHQ_DEBUG`
In this mode extensive error checking is performed to notify the programmer of
 - out of bounds access for vectors or matrices (e.g. x[10] where x has size less than 9
 - adding/subtracting/multiplying/dividing vector or matrices of unequal size
 - invalid dot products of vector and/or matrices 
 - other assorted errors and warnings
## SETTING `MATHQ_DEBUG` MODE
There are two methods to accomplish this.
1. Use the provided sample makefile and specify `MATHQ_DEBUG=1` on the command line
```make clean MATHQ_DEBUG=1 myprogram```
The target `clean` is not needed, but is a recomended practice.
1. Add a `` statement BEFORE each `mathq.h` include statement
```C++

#include "mathq.h"
```
## DEBUG LEVELS
 to be written...
## RECOMMENDATIONS
* While developing your code, use `MATHQ_DEBUG` mode.  When you are convinced that it is operating without errors or warnings, run normally.
* Compile a `MATHQ_DEBUG` and a quick version of your code, giving the executables different names. This way if a segmentation fault occurs, or you otherwise suspect an error, you can quickly check the problem under careful mode.

[Table of Contents](README.md)
