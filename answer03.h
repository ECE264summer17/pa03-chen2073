#ifndef ANSWER03_KEY_H
#define ANSWER03_KEY_H 
//Do not modify above lines

typedef struct _integrand {
	
	double lower_limit;
	double upper_limit;
	int n_intervals;   
	
	double (*function_to_be_integrated)(double);
} integrand;

double integration(integrand intg_arg);

#endif
