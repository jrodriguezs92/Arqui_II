/*

Realiza producto entre matriz y vector

Autor: Jeremy Rodríguez Solórzano

--------------------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

//CAMBIAR TAMANYO//
#define N 10000
//////////////////////////////
float x[N];
float r[N];
float y[N][N];
double start_time, run_time;
int nthreads = 0;
//////////////////////////////

/**
 * Llena el vector con numeros aleatorios.
 */
void fill_vector(float * vect)
{
    srand48(time(NULL));

    float num;

    for (int i=0;i<N;i++){
        num = (float)(drand48()*(100-1)+1);

        vect[i] = num;
    }
}

/**
 * Llena la matriz con numeros aleatorios.
 */
void fill_mat(float mat[N][N])
{
    srand48(time(NULL));

    float num;

    for (int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {

            num = (float)(drand48()*(100-1)+1);

            mat[i][j] = num;
        }
       
    }
}

/**
 * Operaciones de producto punto entre matriz y vector.
 * Para ejecutar con paralelismo: descomentar las lineas 74, 75 y 84.
 */
int main ()
{
    fill_vector(x);
    fill_mat(y);

    /* Cantidad de hilos, usar el doble de la cantidad de procesadores */
	//nthreads = 2*omp_get_num_procs();
    //omp_set_num_threads(nthreads);

    float suma;
    int i,j;

    /*empezar tiempo */
	start_time = omp_get_wtime();


        //#pragma omp parallel for private(j,suma)
        for(i=0;i<N;i++)
        {
            suma = 0;
            for(j=0;j<N;j++)
            {
                suma += y[i][j] * x[j];
            }
            r[i] = suma;
        }
    
    run_time = omp_get_wtime() - start_time;
	printf("\nLargo de %i \nresultado en %f segundos \nCon %i hilos\n",N,run_time,nthreads);

	return 0;
}