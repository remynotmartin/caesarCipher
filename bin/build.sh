#!/bin/sh

g++ -Wall -g -std=c++11 $1

# the -g option enables the debugger warnings

# Mr. Bentley recommends trying to use -L to link in header files instead of using
# the #include directive in my source files.
