/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"
#include <math.h>
#include <stdio.h>

double *
exp_1_svc(argp, rqstp)
	double *argp;
	struct svc_req *rqstp;
{
	printf("EXP");
	double eps = 1e-14;
	static double result;
	result = 1;
    double n=1;
    double a=1;
    while (1)
    {
        a=a*(*argp)/n;
        if (fabs(a) <= eps) break;
        result=result+a;
        n++;
	}
	return(&result);
}

double *
pi_1_svc(argp, rqstp)
	double *argp;
	struct svc_req *rqstp;
{
	printf("PI");
	static double result;
	result = 0;
	double eps = 1e-5;
	double n=1.0;
    double a=1.0;
	double m = 1;
	while (a > eps)
    {
        result+=a*m;
		m*=-1;
        n+=1;
		a = 1.0/(2*n - 1);
	}
	result*=4;
	return(&result);
}
