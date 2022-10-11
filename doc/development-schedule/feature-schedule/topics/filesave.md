# Save tensor to file

_Back to [Table of Contents](../README.md)_

* file i/o should have own copy of collected FormatData, separate from the display copy
* ```save``` command
   * implement CSV, TSV, WSV, braces-compact, braces-code, matlab, Matemematuca
   * implement at least oen binary output style
     * both Mathematica and Matlab support
     * can save multiple variables to one file
   * for Vectors, allow varg vectors and save as columns
   * provide for optional header text 
