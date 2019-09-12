#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
#include<mpfr.h>


//in order to calculate derivative
double  solveDerivative(double, double detaX, float *vetX);
float *solveSystem(float matA[][6], float vetB[], int);
long double f(float argment);


int main()
{


    //control variable to calculate derivative
   // mpfr_t x0, y5linha, deltaX1, deltaX2, deltaX3, deltaX4, deltaX5;
    //mpfr_init2(x0, 512);
    //mpfr_init2(ylinha, 512);
    //mpfr_init2(deltaX1,512);
    //mpfr_init2(deltaX2, 512);
    //mpfr_init2(deltaX3, 512);
    //mpfr_init2(deltaX4, 512);
    //mpfr_init2(deltaX5, 512);
    	
     float x0 = M_PI/4;
     double y5linha;
     float deltX1 = 1e-2;
     float deltX2 = 1e-5;
     float deltX3 = 1e-10;
     float deltX4 = 1e-20;
     float deltX5 = 1e-60;
	
    //control variable to solve system
    int n = 6;
    float *vetX;
    float vetB[] = {0, 0, 0, 0, 0, 1};
    float matA[][6]= {1,   1,  1, 1, 1,  1,
                    -3,  -2, -1, 1, 2,  3,
                    9,    4,  1, 1, 4,  9,
                    -27, -8, -1, 1, 8,  27,
                    81,  16,  1, 1, 16, 81,
                    -243,-32,-1, 1, 32, 243};


    //scaling matrix system
    vetX = solveSystem(matA, vetB, n);

    //Calculate derivative
    y5linha = solveDerivative(x0, deltX5, vetX);
    printf("y5linha = %f\n\n", y5linha);
    //mpfr_out_str (stdout, 10, 0, s, MPFR_RNDD);
    
    return 0;

}


//solver system
float *solveSystem(float matA[][6], float vetB[], int n){

    float *vetX;
    vetX = calloc(n, sizeof(float));

    for (int k =0; k < n ; k++){
        for (int i = (k+1); i < n; i++){
            float m;
            m = matA[i][k]/matA[k][k];
            matA[i][k] = 0;

            for (int j=(k+1); j < n; j++){
                matA[i][j] = matA[i][j] - m*matA[k][j];
            }

            vetB[i] = vetB[i] - m*vetB[k];
        }
        //printf("lado b %d: %f\n", k, vetB[k]);
    }

    //show matrix staggered
    printf("\nmatriz escalonada\n");
    for (int i=0; i<n; i++){
        for (int j=0; j < n; j++){
            printf("\t%f", matA[i][j]);

        }
        printf("\t| %f", vetB[i]);
        printf("\n");

    }


    //solve the system
    *(vetX+n-1) = vetB[n-1]/matA[n-1][n-1];
    for (int i = (n - 2); i >= 0; i-- ){
        float soma = 0;
        for (int j = (i+1); j < n; j++ ){
            soma += matA[i][j]*(*(vetX+j));
        }

        *(vetX+i) = (vetB[i]-soma)/matA[i][i];
    }

    printf("\n");
    printf("A: %f \n", vetX[0]);
    printf("B: %f \n", vetX[1]);
    printf("C: %f \n", vetX[2]);
    printf("E: %f \n", vetX[3]);
    printf("F: %f \n", vetX[4]);
    printf("G: %f \n", vetX[5]);
    printf("\n\n");


    return vetX;
}

//solve derivative
    double solveDerivative(double x0, double deltaX, float *vetX){
    double y5linha;
    float A = vetX[0];
    float B = vetX[1];
    float C = vetX[2];
    float D = 0;
    float E = vetX[3];
    float F = vetX[4];
    float G = vetX[5];

    printf("\nCalcular a quinta derivada de cos(2*pi*60*x) em x=pi/4\n");
    
	
    y5linha = (A*f(x0-3*deltaX)+B*f(x0-2*deltaX)+C*f(x0-deltaX)+D*f(x0)+E*f(x0+deltaX)+F*f(x0+2*deltaX)+G*f(x0+3*deltaX))/(deltaX*deltaX*deltaX*deltaX*deltaX*deltaX);

    return y5linha;

}

//calcule cosine function
 long double f( float argument){
	
   long double fx;    
   fx = cos(2*M_PI*60*(argument));
   return fx;
}




