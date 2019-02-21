/*

Realiza la operación SAXPY

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

	/*empezar tiempo */
	start_time = omp_get_wtime();

	for (int i=0;i<TAM;i++){
		y[i] = a*x[i]+y[i];
	}

	run_time = omp_get_wtime() - start_time;
	printf("\nLargo de %i \nresultado en %f segundos \n",TAM,run_time);

	return 0;
}