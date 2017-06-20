#include <stdio.h>
#include <stdlib.h>
#include "pa03_aux.h"
// do not change this part, if you do, your code may not compile
//
/* test for structure defined by student */
#ifndef NTEST_STRUCT 
#include "answer03.h"
#else
#include "answer03_key.h"
#endif /* NTEST_STRUCT */
//
// do not change above this line, if you do, your code may not compile

int main(int argc, char * * argv)
{
   if (argc != 5) {  // incorrect number of arguments
      return EXIT_FAILURE;
   } else { // now, try to parse the arguments and call the correct function
      
      // fill in the correct statements to complete the main function
      // we expect four arguments:
      //
      // the first argument is 1 character from the sets {"1", "2", "3"}
      // it specifies the function to be integrated
      // 1:  function_1
      // 2:  function_2
      // 3:  function_3
      // otherwise: return EXIT_FAILURE
      
      // to integrate any of the three functions, expect the next three 
      // arguments to be the lower limit of the integration (double), 
      // the upper limit of the integration (double), and the number of 
      // intervals for the integration (int)
      //
      // if the number of steps is less than 1, set it to 1

      // use atof to convert an argument to a double 
      // use atoi to convert an argument to an int

      // fill in the rest of the statements here
      // so that the correct function is called based on the first argument

     // You should use the four arguments to initialise the structure, and pass the structure to the integration function.

     double integral = 0.0;
     integrand intg_arg;


     // fill in the rest of the statements above this line

      printf("%.10e\n", integral); //do not change this line, you might get zero if you have any other printf statements 

   }
   return EXIT_SUCCESS;
}
