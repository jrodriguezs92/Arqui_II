/*

Realiza la operación SAXPY con OpenMP

Autor: Jeremy Rodríguez Solórzano

--------------------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

//CAMBIAR TAMANYO DEL VECTOR//
#define TAM 100000000
//////////////////////////////
const float a = 5.0;
float x[TAM];
float y[TAM];

//////////////////////////////
//Numero de hilos
int nthreads;

void fill_vector(float * vect)
{
    srand48(time(NULL));

    float num;

    for (int i=0;i<TAM;i++){
        num = (float)(drand48()*(25-1)+1);

        vect[i] = num;
    }
}

int main ()
{
	double start_time, run_time;

    fill_vector(x);
    fill_vector(y);

    /* Cantidad de hilos, usar el doble de la cantidad de procesadores */
	nthreads = 2*omp_get_num_procs();
    omp_set_num_threads(nthreads);

	/*empezar tiempo */
	start_time = omp_get_wtime();

    #pragma omp parallel 
    {
        #pragma omp for
        for (int i=0;i<TAM;i++){
		    y[i] = a*x[i]+y[i];
	    }
    }
	
	run_time = omp_get_wtime() - start_time;
	printf("\nLargo de %i \nresultado en %f segundos \nCon %i hilos",TAM,run_time,nthreads);

	return 0;
}