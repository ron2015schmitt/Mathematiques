
Now that you have completed installation, to use the Mathématiques library you need to 

## Overview

1. Include the library file `include/mathq.h` in your source code
```C++
#include "mathq.h"
```
2. Include the `include/` subdirectory during compilation using the `-I` option

3. Include the `lib/` subdirectory during linking using the `-L` option

4. Include the option `-lmathq` during linking

## Compiling and running the example

The `Makefile` and `example.cpp` source in the `examples` subdirectory are the starting point for development.

Copy the files of the `examples` subdirectory into your account.  Assuming you are in the top level directory of Mathematiques, run the following commands:
```bash
mkdir ~/my-first-mathq-project/
cp examples/* ~/my-first-mathq-project/
```
Now compile `example.cpp` and run 
```bash
cd ~/my-first-mathq-project/
make example
./example
```


## Delaing with Errors

To see verbose error messages for your project, use

```bash
make example "COPT=--verbose"
```

For help, use

```bash
make help
```

For a list of all Makefile variables and their values, use
```bash
make info
```


## What's in the files?

The contents `Makefile` and `example.cpp` are listed below for convenience.

## example.cpp

__SOURCE_FILE__

<br>
<br>


## Makefile

__MAKEFILE__

<br>
<br>

