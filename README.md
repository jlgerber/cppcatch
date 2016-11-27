# Catch Example 

## Intro 
The following builds a very simple (and not very good) ring buffer in order to play with the Catch Testing Framework for C++. The author of this library gave a talk about it in cppcon 2015. This is exercise is based on that talk.

Here is the [Catch](https://github.com/philsquared/Catch) library link.

## Instructions 

In order to use Catch, simply download and use it. Since catch is a single header file, it could not be any simpler. One trick to keep your compilation times reasonable is to create a separate main.cpp with the following in it:
```
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
```

Then, you create one or more test executables which include `catch.hpp` as well as the header(s) from the code under test. In this example, we are testing a template, implemented as a header. However, if we were testing a concrete class, we would build it as a library and link against our test application. 