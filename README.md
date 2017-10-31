## compile_time [![Build Status](https://travis-ci.org/lakshayg/compile_time.svg?branch=master)](https://travis-ci.org/lakshayg/compile_time)

compile_time is a bag-of-tricks which allows the user to
perform computation at compile time. The project requires
C++11. To use compile_time in your project, clone the
project and add the include directory to your include path.

The functions provided in this library can be evaluated both
at compile and run times but it is strongly discouraged that
you use these at run time since the performance is likely to
be extremely poor as compared to an implementation done
specifically for run time.

### Dependencies

- **NONE** for using the library
- Boost.Test for building tests

### Usage

Please have a look at the tests for the header you want to use.

### Available Functions

#### Math
- `Integer factorial(Integer n)`
- `Real abs(Real num)`
- `bool is_even(Integer num)`
- `bool is_odd(Integer num)`
- `bool is_negative(Real num)`
- `Real pow(Real a, Integer n)`
- `Real max(Real a, Real b)`
- `Real max(Real a, Real b, Compare comp)`
- `Real min(Real a, Real b)`
- `Real min(Real a, Real b, Compare comp)`
- `Real sqrt(Real x)`
- `Real hypot(Real a, Real b)`
- `Real sqr(Real x)`
- `Integer choose(Integer n, Integer k)`
- `Integer fibonacci(Integer iter)`
- `Real deg2rad(Real deg)`
- `Real rad2deg(Real rad)`
- `Integer floor(Floating x)`
- `Integer ceil(Floating x)`
- `Real exp(Real x)`
- `Real sin(Real x)`
- `Real cos(Real x)`
- `Real tan(Real x)`
- `Real csc(Real x)`
- `Real sec(Real x)`
- `Real cot(Real x)`
- `Real fast_atan(Real x)`
- `Integer ilog(Real x, Real b = e)`

#### Strings
- `int isalnum(int ch)`
- `int isalpha(int ch)`
- `int islower(int ch)`
- `int isupper(int ch)`
- `int isdigit(int ch)`
- `int isxdigit(int ch)`
- `int iscntrl(int ch)`
- `int isgraph(int ch)`
- `int isspace(int ch)`
- `int isblank(int ch)`
- `int isprint(int ch)`
- `int ispunct(int ch)`
- `int tolower(int ch)`
- `int toupper(int ch)`
- `size_t strlen(string_literal str)`
- `int strcmp(string_literal a, string_literal b)`

### Demo

```
// demo.cpp
#include <cmath>
#include "compile_time/math.hpp"

namespace CT = compile_time;

int main() {
    constexpr auto x     = 1.2;
    constexpr auto sin_1 = CT::sin(x); // evaluates at compile_time
    auto           sin_2 = CT::sin(x); // compiler decides when to evaluate
    volatile auto  sin_3 = CT::sin(x); // evaluates at runtime
    auto           sin_4 =   ::sin(x); // cmath sin, evaluates at runtime
    return (int)(sin_1 + sin_2 + sin_3 + sin_4); // to ensure the vars are not optimized out
}
```

Here is a call log of the program showing the functions called (generated using valgrind)
![Valgrind output](http://oi63.tinypic.com/o8arnm.jpg)

### Code Guidelines

Every function:
- must be accompanied by a test case
- must perform error checking and report errors
- should try to be runnable at compile and run times
- should be named after the corresponding stdlib function if it exists
