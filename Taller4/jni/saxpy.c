#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

#define tam 1010000
#define a 5.43

int main (){

    double start_time, run_time;

    /*define vectors*/
    float x[tam];
    float y[tam];

    /*fill vectors with random numbers*/
    srand(time(NULL));
    float n;
    for (int i=0; i<tam; i++){
        n = (float)rand()/(float)(RAND_MAX/100);
        x[i] = n;
        n = (float)rand()/(float)(RAND_MAX/100);
        y[i] = n;
    }

    /*SAXPY*/
    /*start timer */
    start_time = omp_get_wtime();
    
    for (int i=0; i<tam; i++){
        x[i] = a*x[i] + y[i];
    }

    /*end timer*/
    run_time = omp_get_wtime() - start_time;

    printf("SAXPY operation in %f seconds \n", run_time);

    return 1;
}