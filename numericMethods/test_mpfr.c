#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpfr.h>
#include <gmp.h>

	mpfr_t *returnValue(mpfr_t *value);
	int main(int argc, char *argv[]){
	   mpfr_t bignum, *other;
	   mpfr_init2(bignum, 512);
	   mpfr_set_d(bignum, 3e-80, MPFR_RNDD);
           other = returnValue(&bignum);
	   mpfr_out_str (stdout, 10, 0, bignum, MPFR_RNDD);
	   printf("\n\nO outro valor\n\n");
	   mpfr_printf("para testar : %.85R*f", MPFR_RNDN, *other);
	
	 
	 return 0;	
	}
	
	

	mpfr_t *returnValue(mpfr_t *value){
               mpfr_mul_d(*value, *value, 5, MPFR_RNDN);


	  return value;
	
	}
