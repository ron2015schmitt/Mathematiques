# Refactor FormatData

_Back to [Table of Contents](../README.md)_

* use Python to generate code
* use instances instead of class variables and use `constexpr` as needed
* collect all formats into one class
   * use a specific instance for disp/MOUT format
   * use a different specific instance for file i/o
* Define formats (via ENUM) for:
   * default-condensed
   * default-code
   * matlab
   * mathematica
   * csv,tsv,wsv 
