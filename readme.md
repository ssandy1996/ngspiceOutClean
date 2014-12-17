ngspiceOutClean
===========

C program that can be used to clean [ngspice][1] simulation output files and import the  
formatted .txt files into programs such as [Scilab][2] and analyse the data.

### Procedure ###
 * Command line arguments of file name
 * Executing the C code without arguments 

### Contents ###
 * Source folder contains the main.c code that implements this funcationality
 * Sample folder contains some [ngspice][1] output files and respective formatted .txt files 

### Limitations ###
 1. Can clean output files that have maximum 3 data points
 2. Fixed output file names 

[1]: http://ngspice.sourceforge.net/
[2]: http://www.scilab.org/

