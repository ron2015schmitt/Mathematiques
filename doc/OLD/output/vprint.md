
[Table of Contents](README.md)


# \*Formatted and styled printing in Mathématiques
_This document was automatically generated from file_ **`vprint.cpp`** (Mathématiques-v3.2-r1).

* The examples in this section can be found in file_ `examples/printing.cpp`

* All of the functions decribed in this section are in the namespace `display`
* Practically speaking, this functionality is one of the most useful aspects of Mathématiques.
## The function `DISP(x)`


The function `DISP(x)` displays both the variable name (or expression) as well as its value, formatted according to the user.   This is an incredibly useful function.


**EXAMPLE 1**: simple examples of `DISP(x)` usage


Define and initialize some variables:


```C++
int n = 45;
int m =256;
double x = 3.14;
double vals[] = {1.1,2.2,3.3};
bool done = true;
Vector<double> v = range<double>(1,10);
char str[] = "hello";
std::string s = "world";
ComplexDouble z(1,-1);
```
display each variable using `disp`:


```C++
DISP(n);
DISP(m);
DISP(x);
DISP(vals);
DISP(done);
DISP(v);
DISP(str);
DISP(s);
DISP(z);
```


The actual screen-shot of the output is shown below:


![disp example 1](disp_example1.png)
## The function `TLDISP(x)`


The function `TLDISP(x)` displays the variable type, in addition to the variable name and value


**EXAMPLE 2**:  `TLDISP(x)` usage


```C++
TLDISP(n);
TLDISP(m);
TLDISP(x);
TLDISP(vals);
TLDISP(done);
TLDISP(v);
TLDISP(str);
TLDISP(s);
TLDISP(z);
```


The actual screen-shot of the output is shown below:


![disp example 2](disp_example2.png)
## The function `MDISP(x1,x2,...)`


* The function `MDISP(x1,x2,...)` displays multiple variables (from 1 to 10) on the same line.
* Very useful for displaying:
  * the arguments passed to a function
  * the variables inside a for loop


**EXAMPLE 3**:  `MDISP(x1,x2,...)` usage


```C++
MDISP(n,m,x,vals,done,str,s,z);
```


The actual screen-shot of the output is shown below:


![disp example 3](disp_example3.png)
## The function `DISPVAL(x)`


* The function `DISPVAL(x)` prints only the variable value, without the name and equals sign, and _without a carriage return_.


**EXAMPLE 4**:  `DISPVAL(x)` usage


```C++
DISPVAL(n);
DISPVAL(m);
```


The actual screen-shot of the output is shown below:


![disp example 3b](disp_example3b.png)
## Displaying expressions


* The functions introduced above can also be used to display expressions.
* vector and matrix expressions can be displayed in this manner.


**EXAMPLE 5**:  displaying expressions


```C++
DISP(n+3);
DISP(10*x-1);
DISP(!done);
DISP( round(10*sin(pi/10*v) + 10) );
DISP(s+" tour");
```


The actual screen-shot of the output is shown below:


![disp example 4](disp_example4.png)
## Supported Types


The following types are currently supported by the display commands
* **Any class** with methods `.classname()` and `operator<<` is automatically supported
* `mathq::Vector<D>` vectors
* `mathq::Matrix<D>` matrices
* `bool`
* `short`, `int`, `long`, `long long`
* `unsigned short`, `unsigned int`, `unsigned long`, `unsigned long long`
* `float`, `double`, `long double`
* `char`, `unsigned char`
* `char[]` C-style strings
* `D[]` C-style arrays
* `std::string` C++ strings
* `std::complex<D>` complex numbers
* `std::vector` C++ vectors
* `std::valarray` C++ valarrays
* `std::vector` C++ vectors
* `std::list` C++ lists
* `std::queue` C++ queues
* `std::map` C++ maps
* `std::initializer_list` C++11 
## Printing to other streams: `DISP_STRM`, `dispval_strm`, `tdisp_strm`, `mdisp_strm`
* The default stream is `MOUT` (refer to next section)
* You can also utilize all the formatting and color functionality of mathq and print to any output stream you like, including files.  The corresponding functions are shown below.


| `MOUT`  | `ostream` |
| ------------- | ------------- |
| `DISPVAL(x)`  | `dispval_strm(ostream,x)`  |
| `DISP(x)`  | `DISP_STRM(ostream,x)`  |
| `TLDISP(x)`  | `TDISP_STRM(ostream,x)`  |
| `MDISP(x,y,...)`  | `MDISP_STRM(ostream,x,y,...)`  |


## Debug-only printing


### Debug-only printing: `disp[123]`, `tdisp[123]`, `mdisp[123]`


The display commands also have versions that only display when the code is compiled with the debug flag `MATHQ_DEBUG` set.
* `disp1`, `tdisp1`, `mdisp1` will
  * when `MATHQ_DEBUG >= 1`: behave like `disp`, `tdisp`, `mdisp`
  * when `MATHQ_DEBUG == 0` or is undefined: compile to null statements (ie no output and no real-time hit)
* `disp2`, `tdisp2`, `mdisp2` will
  * when `MATHQ_DEBUG >= 2`: behave like `disp`, `tdisp`, `mdisp`
  * when `MATHQ_DEBUG < 2` or is undefined: compile to null statements (ie no output and no real-time hit)
* `disp3`, `tdisp3`, `mdisp3` will
  * when `MATHQ_DEBUG >= 3`: behave like `disp`, `tdisp`, `mdisp`
  * when `MATHQ_DEBUG < 3` or is undefined: compile to null statements (ie no output and no real-time hit)
### Debug-only printing: `print[123]`, `printf[123]`


* The functions `print1`, `print2`, `print3` each take a single std::string (or C string) as input and print the string to the stream `MOUT` followed by a carriage return.
* The functions `PRINTF1`, `PRINTF2`, `PRINTF3` function like printf, but actually use sprintf and then output to the stream `MOUT` using C++ methodlogy.
## Changing the mathq output stream and controlling color
* All output uses C++ streams (*no* `printf`)
* By default all output is sent to `std::cout`
* The output stream can be set using `Terminal::setmout(std::ostream&)`.
For example to set the output to stderr:
```C++

Terminal::setmout(std::cerr);
```

* You can use the mathq output stream via `Terminal::getmout()` or the macro `MOUT`
For example, you can output a string:
```C++

MOUT << "Hello World" << std::endl;

```

* By default, mathq uses color when it detects that the output stream is connected to a terminal.
* By default, mathq disables color when it detects that the output stream is piped to a file.
* However, the user can override this behavior as follows

To force mathq to use plain text, use the following settings:
```C++

Terminal::setColorOverride(true);
Terminal::setOverrideValue(false);
```

To force mathq to use color text, use the following settings:
```C++

Terminal::setColorOverride(true);
Terminal::setOverrideValue(true);
```

This latter setting can be used to print in colors to a file, which will display properly when the file is viewed via a terminal command like `more`,`less`, or `cat`.



## The `Style` class
* Color and other text attributes are controlled using the [ANSI escape codes for terminals](https://en.wikipedia.org/wiki/ANSI_escape_code).

* mathq defines the class `Style` for applying color and other attributes, such as **bold**

* The predefined styles are shown below

![styles](displaycolors.png)

You can combine the styles using the `+` sign

![stylescombined](displaycolorscombined.png)

* To use any of these, use the `CREATESTYLE` macro as the following example illustrates
```C++

Style mystyle = CREATESTYLE(BOLD+RED);

MOUT << mystyle.apply("with style") + " without style " << std::endl;

```

The output from the above two lines of code is:

![stylesexample](displaycolorsexample.png)


* _The Style class checks to see whether or not to actually use colors, as described in the previous sub-section_





### Custom styles
* The user can define a style for any foreground color and background color combination as follows:

```C++
int nf = 27;  // color for foreground
int nb = 227; // color for background
display::Style mystyle(nf,nb); 
display::MOUT << mystyle.apply("Hello World") << std::endl; 
```
* Style objects can added:

```C++
int nf = 27;  // color for foreground
int nb = 227; // color for background
display::Style mystyle(nf,nb);
display::Style bold(BOLD);
display::Style mybold = bold + mystyle;
display::MOUT << mybold.apply("Hello World") << std::endl; 
```
* Place the attributes, eg `BOLD`, `UNDERLINE`, before the color styles
* Wikipedia lists the allowable [8-bit color definitions](https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit)

## Customizing display format for data types


### Customizing number formats
You can set the number format for any of the primitive datatypes using template function `setFormatString<D>(std::string)`


**EXAMPLE 6**:  `double` number format
```C++
using namespace display;
double x = 2.51;
```

**Results**: The default format is `"%g"` which yields
```C++
  x = 2.51; 
```

```C++
setFormatString<double>("%+18.15f");
```

**Results**: The format `"%+18.15f"`  yields
```C++
  x = +2.510000000000000; 
```



**EXAMPLE 7**:  `int` number format
```C++
using namespace display;
int n = -1024;
```

**Results**: The default format is `"%d"` which yields
```C++
  n = -1024; 
```

```C++
setFormatString<int>("%10d");
```

**Results**: The format `"%10d"`  yields
```C++
  n =      -1024; 
```



### Customizing format for `char`,`string`, and `bool`
* The default format for `char` is `"%c"`
* The default format for `std::string` is `"%s"`
* For `bool` types, the following _class variables_ are used:
  * `FormatData<bool>::string_for_true`
  * `FormatData<bool>::string_for_false`
* The default `bool` string are `0` and `1`


```C++
using namespace display;
bool a = true;
```

**Results**: The default `bool` format which yields
```C++
  a = 1; 
  !a = 0; 
```



For example, we can change the bool display value to true/false as follows.
```C++
using namespace display;
FormatData<bool>::string_for_true = "true";
FormatData<bool>::string_for_false = "false";
```

**Results**: The above format yields
```C++
  a = true; 
  !a = false; 
```



### Customizing complex number format
The format for complex numbers is set using the function `setFormatStringComplex`.  The default format is `"(%s, %s)"`



**EXAMPLE 8**:  complex number formats
```C++
using namespace display;
ComplexDouble z(1,-2);
```


Default format: `"(%s, %s)"`

```C++
z = (1, -2); 
```


Matlab input format `"%s + i*%s"`

```C++
z = 1 + i*-2; 
```


Mathematica input format `"%s + I*%s"`

```C++
z = 1 + I*-2; 
```


Matlab output format / C++14 format `"%s + %si"`

```C++
z = 1 + -2i; 
```


Note that the format of the real and imaginary parts of `complex<D>` are controlled by the format string for the template data type.`

```C++
setFormatString<double>("%9.6f");
```
The above statement changes the display of `z` to

```C++
z =  1.000000 + -2.000000i; 
```
### Customizing Vector format


The format for `mathq:Vector` output is controlled by the following static class variables.


|`FormatDataVector` class variable|default value|
|------------------|------------------------|
|string_opening| "{"|
|string_delimeter | ","|
|max_elements_per_line | mathq::maxsize|
|string_endofline | "\n"|
|string_closing |   "}"|


**EXAMPLE 9**:  default Vector format
```C++
using namespace mathq;
Vector<double> v = range<double>(1001,1010);;
```
The default format yields

```C++
v = {1001,1002,1003,1004,1005,1006,1007,1008,1009,1010}; 
```
#### Mathematica-style Vector format


The Mathematica-style format allows you to cut and paste results directly into a Mathematica notebook.  
The function `set_mathematica_var_format()` sets these variables as follows


|`FormatDataVector` class variable|Mathematica value|
|------------------|------------------------|
|string_opening| "{\n    " |
|string_delimeter | ", " |
|max_elements_per_line | 5 |
|string_endofline | "\n    " |
|string_closing |   "\n}"   |


* This function also changes the format for doubles and complex numbers


```C++
setFormatString<double>("% 10.8e");
FormatData<double>::tens = true;
setFormatStringComplex("%s + I*%s");
```
**EXAMPLE10**:  Mathematica Vector format
```C++
using namespace mathq;
Vector<double> v = range<double>(1001,1010);;
set_mathematica_var_format();
```
The Mathematica format yields

```C++
v = {
     1.00100000 10^+03,  1.00200000 10^+03,  1.00300000 10^+03,  1.00400000 10^+03,  1.00500000 10^+03, 
     1.00600000 10^+03,  1.00700000 10^+03,  1.00800000 10^+03,  1.00900000 10^+03,  1.01000000 10^+03
}; 
```
#### Matlab-style Vector format


The Matlab-style format allows you to cut and paste results directly into the Matlab command line or m-file.  
The function `set_matlab_var_format()` sets these varibles as follows


|`FormatDataVector` class variable|Matlab value|
|------------------|------------------------|
|string_opening|   "[ ...\n    "  |
|string_delimeter | ", "  |
|max_elements_per_line | 5 |
|string_endofline |  " ...\n    "  |
|string_closing |   " ...\n]"  |


* This function also changes the format for doubles and complex numbers


```C++
setFormatString<double>("% 10.8e");
FormatData<double>::tens = false;
setFormatStringComplex("%s + i*%s");
```
**EXAMPLE11**:  Matlab Vector format
```C++
using namespace mathq;
Vector<double> v = range<double>(1001,1010);;
set_matlab_var_format();
```
The Matlab format yields

```C++
v = [ ...
     1.00100000e+03,  1.00200000e+03,  1.00300000e+03,  1.00400000e+03,  1.00500000e+03,  ...
     1.00600000e+03,  1.00700000e+03,  1.00800000e+03,  1.00900000e+03,  1.01000000e+03 ...
]; 
```
## Changing the color and style settings

* In addition to the formatting discussed above, each data type has Styles that control the color and text attributes (eg boldness) of output

### Color and style settings for floating point types



| `FormatData<D>` class variable | default value | 
|--------------------|----------------------------|
| style_for_type_name | Style(MAGENTA) | 
| style_for_value | Style(BLACK) | 
| style_for_zero | Style(GRAY1) | 


### Color and style settings for signed integer types



| `FormatData<D>` class variable | default value | 
|--------------------|----------------------------|
| style_for_type_name | Style(MAGENTA) | 
| style_for_value | Style(BLUE2) | 
| style_for_zero | Style(GRAY1) | 


### Color and style settings for unsigned integer types



| `FormatData<D>` class variable | default value | 
|--------------------|----------------------------|
| style_for_type_name | Style(MAGENTA) | 
| style_for_value | Style(VIOLET1) | 
| style_for_zero | Style(GRAY1) | 


### Color and style settings for `bool`



| `FormatData<D>` class variable | default value | 
|--------------------|----------------------------|
| style_for_type_name | Style(MAGENTA) | 
| style_for_true | Style(GREEN1) | 
| style_for_false | Style(GRAY1) | 


### Color and style settings for `char`



| `FormatData<D>` class variable | default value | 
|--------------------|----------------------------|
| style_for_type_name | Style(MAGENTA) | 
| style_for_value | Style(BLACK) | 


### Color and style settings for `string`



| `FormatData<D>` class variable | default value | 
|--------------------|----------------------------|
| style_for_type_name | Style(GREEN) | 
| style_for_value | Style(BLACK) | 


### Color and style settings for `std::complex`



| **FormatDataComplex** class variable | default value | 
|--------------------|----------------------------|
| style_for_type_name | Style(GREEN) | 
| style_for_punctuation | Style(GRAY1) | 


### Color and style settings for `Vector`



| **FormatDataVector** class variable | default value | 
|--------------------|----------------------------|
| style_for_type_name | Style(CYAN) | 
| style_for_punctuation | Style(GRAY1) | 



[Table of Contents](README.md)
