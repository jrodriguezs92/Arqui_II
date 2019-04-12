#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
//#include <arm_neon.h>

#define tam 10000 //Vector size

int main (){

    int nprocs, i;

    double start_time, run_time;

    /*define vectors and 'a' constant*/
    float x[tam];
    float y[tam];
    float a = 2;

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

    /* Use double of system processors (threads) */
    nprocs=omp_get_num_procs();

    omp_set_num_threads(nprocs);
    /*start timer */
    start_time = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp for
        for (i=0; i<tam; i++){
            x[i] = a*x[i]+y[i];
        }
    }

    /*end timer*/
    run_time = omp_get_wtime() - start_time;

    printf("SAXPY operation in %f seconds \n", run_time);

    return 1;
}