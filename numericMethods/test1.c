#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpfr.h>
#include <gmp.h>

	int main(){
	   long double fx;
	   fx = cos((2*M_PI/4)*60*1e-15);
	   printf("%Lf", fx);
	
	
	 return 0;	
	}
