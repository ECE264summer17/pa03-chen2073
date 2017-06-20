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
// This is the only file you have to include

// Given intg_arg, this function performs numerical integration of 
// the function intg_arg.func_to_be_integrated over the range
// intg_arg.lower_lilmit to intg_arg.upper_limit
// 
// The range is divided into intg_arg.n_intervals uniform intervals, where the
// left-most interval has a left boundary of intg_arg.lower_limit and the 
// right-most interval has a right boundary of intg_arg.upper_limit (assuming 
// intg_arg.lower_limit <= intg_arg.upper_limit).  
// 
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that intg_arg.n_intervals >= 1
// Therefore, this function may assume that intg_arg.n_intervals >= 1
//
double integration(integrand intg_arg)
{
  return 0;
}
