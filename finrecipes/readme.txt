Code for the manuscript
 "Financial Numerical Recipes in C++"

The code is in the two subdirectories:
 all_cc_progs/: Code to create library
 examples_cc/: Examples of library use, many of the same examples that are contained in the manuscript

The subdirectory  "all_cc_progs/" contains the source codes for
the routines, with a makefile that will compile all the c++ files
and put them into the library "librecipes.a" To make, cd into the
directory and do "make lib"

The resulting library, contained in "librecipes.a",
need to be copied into the "examples_cc" directory. 
After that, run the examples by cd'ing to that directory and do
"make run"

The library also contains code that uses a number of other 
C++ libraries: 

IT++: C++ matrix class.
Newmat: C++ matrix class.
GSL: Gnu Scientific Library.

If you want to use these routines, you first need to install the
relevant libraries. Then you need to uncomment the relevant places in the 
makefiles of the subdirectories. It should be clear from the context
what to uncomment. It may also be necessary to change paths to the
various libraries. 

Below are some notes on installing the external libraries:

IT++: This needs to be installed including the matrix libraries:
     LAPACK, BLAS, CBLAS (alternatively ATLAS). See IT++ documentation.




