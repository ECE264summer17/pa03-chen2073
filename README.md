# Learning Goals 

You should learn:
1. How to perform integration of a function
2. How to define a structure needed 
3. How to use argc and argv correctly in main
4. How to use function pointers

## Getting Started 

To get started, read this README in its entirety.  Browse through the
answer03.h and answer03.c files to see what code needs to be written. 
You will be writing code in the answer03.c file. You will also write code 
in the pa03.c file to call the function in answer03.c. Files answer03.c and
pa03.c contain the comments that tell you the code that needs to be written 
in answer03.c and pa03.c, respectively.  You should also read both answer03.c 
and pa03.c to figure out the structure that needs to be defined in 
answer03.h.

## Submitting Your Assignment 

You must submit three files:
1. `answer03.h` (4 points): 4 points for defining the structure properly
2. `answer03.c` (4 points): 4 points for the integration function
3. `pa03.c` (4 points): 4 points for the main function 


# Functions/Structure you have to define 

You are to define a structure in answer03.h, define a function in
answer03.c, and define the main function in pa03.c.  

## Defining the structure 

we need to work on four parameters for a successful the integration:
`double lower_limit`, `double upper_limit`, `int n_intervals` and the `function_to_be_integrated`.
All these parameters should be components of a structure. 
To relax that such that the integration
function can be used for any function that accepts a double as 
an input parameter and returns a double as output, we must also 
pass the address of such a function to the integration function.

In pa03, we are allowed to pass only a structure to the integration function.

You task is to define such a structure in `answer03.h`.
In this structure, you must store double lower_limit, double upper_limit,
and int n_intervals.  Moreover, you must store the address of the
function to be integrated.  The structure is partially defined.  You
have to complete the definition.

You may ask what is the type of the address of the function to be
integrated.  Let's understand the meaning of 

int (*func)(double, int);

`(Note that this is NOT the type that you should use in your structure.)`
Here, it says that func is the name of the location storing something.
The * in front of func says that func is going to store an address.
It is important that the parentheses enclose "*func".  Without the
parentheses around "*func", it becomes a declaration of a function called
func and func returns "int *".

The parentheses following (*func) indicate that func is going to 
store an address pointing to a function, and that function expects
two input variables, the first being a double and the second being
an int.  Now, the int before (*func) indicates that the function returns
an int.

Essentially, the statement declare func to be a variable that
would store an address pointing to a function that accepts a double and
an int, and returns an int.

You should ask yourself if you want to declare in the integrand structure
a field called `func_to_be_integrated` to store the address of a function that 
accepts a double as an input parameter and returns a double as output, how 
you should declare the type of func_to_be_integrated.

The answer to that would allow you to define in answer03.h your structure 
called integrand, which should contain the fields lower_limit, upper_limit,
n_intervals, and func_to_be_integrated.  Use these names exactly.  Otherwise,
we may not be to evaluate your submission properly. 

You need only FOUR fields in your structure, one of which is already defined
for you.  DO NOT include any other fields in your structure.

## Integrate a Function

This assignment asks you to write a C function to calculate the definite integration of a function. Suppose f is a function that can be integrated over the range [lowerlimit, upperlimit]. If it is possible to find a closed form for the integration of `f`, let's call it `int_f`, then the answer would be simple:

`int_f(upperlimit) - int_f(lowerlimit)`

In many cases, however, a closed form is unavailable and we can use numeric methods to approximate the answer.

One easy approximation assumes that f can be approximated by a straight line. Thus, the integration can be approximated by using the middle of [lowerlimit, upperlimit]:

`(upperlimit - lowerlimit) x f((upperlimit + lowerlimit) / 2)`

This approximation is incorrect if f is not a a straight line. This assignment asks you to approximate the answer by dividing [`lowerlimit`, `upperlimit`] into several intervals. Let's use n as the number of intervals. The integration is approximated by

```(upperlimit - lowerlimit) / n x 
(
f(lowerlimit) + 
f((lowerlimit) +       (upperlimit - lowerlimit) / n) +
f((lowerlimit) + 2 * (upperlimit - lowerlimit) / n) +
f((lowerlimit) + 3 * (upperlimit - lowerlimit) / n)  +
...
f(lowerlimit + (n - 1) * (upperlimit - lowerlimit) / n) 
)
```

You can assume that `n` is a positive integer. You do not need to check whether `n` is zero. You can assume that `upperlimit` is greater than `lowerlimit`.


##  The main function 

The executable of this exercise expects `4` arguments.  If executable is
not supplied with exactly 4 arguments, the function returns EXIT_FAILURE.

The `first` argument specifies which of the three functions you are supposed
to be integrate.  If the first argument is "1", you should
perform integration of function_1.  If the first argument is "2", you should perform the integration
of function_2.  If the first argument is "3", you should
perform integration
of function_3. All three functions are defined in `pa03_aux.c` for your reference and also declared in `pa03_aux.h` header file.

The `second` argument provides the lower limit (double) of the integral. 
You should use `atof` (from stdlib.h) to convert the first argument into a double.

The `third` argument provides the upper limit (double) of the integral. 
You should use atof to convert the second argument into a double.

The `fourth` argument provides the number of intervals you should use for the
approximation.  You should use atoi (from stdlib.h) to convert the
third argument into an int.  If the conversion of the third argument results 
in an int that is less than 1, you should supply 1 (numeric one) as the number
of intervals for approximation.

You should declare and initialize the fields of a variable `intg_arg`
(of type `integrand`), i.e., `intg_arg.lower_limit`, `intg_arg.upper_limit`, 
`intg_arg.n_intervals`, and `intg_arg.func_to_be_integrated`, with the lower 
limit, the upper limit, the number of intervals, and the appropriate 
function to integrate.

The variable `intg_arg` should be passed to the integration function.  

Upon the successful completion of the integration, print
the approximation using the format "%.10e\n" using the function
printf. (That is the format to be used, and this is the only printf
statement in the entire exercise.  If you print other messages, your
exercises will receive a zero score.)

After printing, the main function returns EXIT_SUCCESS.

## Compilation and testing your program 

You should compile your program with the following command:

> gcc -Wall -Wshadow -Werror -g pa03.c answer03.c pa03_aux.c -o pa03 -lm

Note that -lm is required because the functions function_1, function_2 and function_3 contain 
function calls to math functions declared in math.h.

## Running your program 

To integrate function_1, you can use for example,

> ./pa03 1 0.0 10.0 5

If your integration function is correct, it should print following for every command
```
> ./pa03 1 1 2 10000

1.4999500000e+00

> ./pa03 1 -1 3 10000

3.9992000000e+00

> ./pa03 2 0.8 2.9 10000

-3.6961543346e+00

> ./pa03 2 -1 31.0 20000

8.4899754803e+03

> ./pa03 3 -1.0 3.0 100000

2.5128967491e+00

> ./pa03 3 1.0 2.0 100000

1.0242800275e+00
```
# Warning 

Other than the approximated integral, you should not be printing anything else.
If the output of your program is not as expected, you get 0 for that test case.

Although you can make changes to answer03.h (since you are submitting
the file), the only changes you are allowed to make is to define the type
integrand in answer03.h.  You should not make other changes to answer03.h.

You can declare and define additional functions that you have to use in
pa03.c and answer03.c. 

In answer03.c and pa03.c, the first few lines of the files include the
following statements:

```// do not change this part, if you do, your code may not compile
//
/* test for structure defined by student */
#ifndef NTEST_STRUCT 
#include "answer03.h"
#else 
#include "answer03_key.h"
#endif /* NTEST_STRUCT */
//
// do not change above this line, if you do, your code may not compile
```

#ifndef states that if the macro NTEST_STRUCT is not defined,
the file answer03.h is included.  Otherwise, the file 
answer03_key.h is included.  (Note that answer03_key.h is 
withheld from you.  You do not have this file.)  This is to facilitate 
grading so that if your answer03.h does not work, we can still use
answer03_key.h (provided by the instructor) to compile and test your code.  
Do not make changes to these lines.

