/*
Calculate the integral of a defined function with the composite trapezoidal method
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

/*define function*/
#define f(x) sqrt(sin(x))

int main() {

    double start_time, run_time;

    int i;
    float n = 1010000;
    float a = 0;
    float b = 3;
    float h, result, sum;

    printf("Solution for integration of function defined in 'f(x) = sqrt(sin(x))' \n");
    printf("With lower limit = %f \n", a);
    printf("With top limit = %f \n", b);
    printf("With step value = %f \n", n);

    h=(b-a)/n;
    sum=0;

    /*start timer */
    start_time = omp_get_wtime();

    for(i=1;i<n;i++) {
        sum=sum+f(a+i*h);
    }
    /*end timer*/
    run_time = omp_get_wtime() - start_time;

    result=(h/2)*(f(a)+f(b)+2*sum);
    
    printf("Integrate result is %.4f in %f seconds \n", result,run_time);

    return 1;
}