#include <stdio.h>
#include <xmmintrin.h>
#include <smmintrin.h>
#include <tmmintrin.h>
#include <immintrin.h>

// Definir macro para extraer valores del vector de presicion simple _m128.
// Esto ya que la funcion '_mm_extract_ps()' no funciona correctamente segun la documentacion
// v -- Vector
// i -- Indice
// Referencia: https://github.com/searchivarius/BlogCode/blob/master/2014/5/14/mm_extract_ps.cpp
#define MM_EXTRACT_FLOAT(v,i)  _mm_cvtss_f32(_mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, i)))
/////////////////////////////////////////////////////////////////////////////////////////////

int main() {

    printf("Calcular resultado de multiplicar dos matrices de 4x4...\n\n");

    // Definir valores
    float c11 = 8.15;
    float c12 = 9.15;
    float c13 = 10.15;
    float c14 = 11.15;

    // Estblece las filas de la primera matriz en vectores
    __m128 M1Fila1 = _mm_set_ps(c11,c11,c11,c11);
    __m128 M1Fila2 = _mm_set_ps(c12,c12,c12,c12);
    __m128 M1Fila3 = _mm_set_ps(c13,c13,c13,c13);
    __m128 M1Fila4 = _mm_set_ps(c14,c14,c14,c14);

    // Print mat a
    printf("MAT A:\n");
    printf("%f\t%f\t%f\t%f\n",c11,c11,c11,c11);
    printf("%f\t%f\t%f\t%f\n",c12,c12,c12,c12);
    printf("%f\t%f\t%f\t%f\n",c13,c13,c13,c13);
    printf("%f\t%f\t%f\t%f\n",c14,c14,c14,c14);

    // Establece las columnas de la segunda matriz en vectores
    __m128 M2Columna1 = _mm_set_ps(c11,c11,c11,c11);
    __m128 M2Columna2 = _mm_set_ps(c12,c12,c12,c12);
    __m128 M2Columna3 = _mm_set_ps(c13,c13,c13,c13);
    __m128 M2Columna4 = _mm_set_ps(c14,c14,c14,c14);

    // Print mat b
    printf("\nMAT B:\n");
    printf("%f\t%f\t%f\t%f\n",c11,c12,c13,c14);
    printf("%f\t%f\t%f\t%f\n",c11,c12,c13,c14);
    printf("%f\t%f\t%f\t%f\n",c11,c12,c13,c14);
    printf("%f\t%f\t%f\t%f\n",c11,c12,c13,c14);

    // Definir datos para almacenar resultados y extracciones
    float dato1 = 0;
    float dato2 = 0;
    float dato3 = 0;
    float dato4 = 0;

    float resultado1 = 0;
    float resultado2 = 0;
    float resultado3 = 0;
    float resultado4 = 0;
    float resultado5 = 0;
    float resultado6 = 0;
    float resultado7 = 0;
    float resultado8 = 0;
    float resultado9 = 0;
    float resultado10 = 0;
    float resultado11 = 0;
    float resultado12 = 0;
    float resultado13 = 0;
    float resultado14 = 0;
    float resultado15 = 0;
    float resultado16 = 0;

    ///////////////////// Celda 1,1
    // Multiplicacion
    __m128 vect = _mm_mul_ps(M1Fila1,M2Columna1);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado1 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 1,2
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila1,M2Columna2);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado2 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 1,3
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila1,M2Columna3);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado3 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 1,4
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila1,M2Columna4);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado4 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 2,1
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila2,M2Columna1);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado5 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 2,2
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila2,M2Columna2);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado6 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 2,3
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila2,M2Columna3);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado7 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 2,4
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila2,M2Columna4);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado8 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 3,1
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila3,M2Columna1);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado9 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 3,2
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila3,M2Columna2);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado10 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 3,3
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila3,M2Columna3);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado11 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 3,4
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila3,M2Columna4);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado12 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 4,1
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila4,M2Columna1);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado13 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 4,2
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila4,M2Columna2);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado14 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 4,3
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila4,M2Columna3);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado15 = dato1+dato2+dato3+dato4;

    ///////////////////// Celda 4,4
    // Multiplicacion
    vect = _mm_mul_ps(M1Fila4,M2Columna4);
    // Suma
    dato1 = MM_EXTRACT_FLOAT(vect, 0);
    dato2 = MM_EXTRACT_FLOAT(vect, 1);
    dato3 = MM_EXTRACT_FLOAT(vect, 2);
    dato4 = MM_EXTRACT_FLOAT(vect, 3);
    // Resultado
    resultado16 = dato1+dato2+dato3+dato4;

    printf("\nMatriz resultante: \n");
    printf("%f \t %f \t %f \t %f \n",resultado1, resultado2, resultado3, resultado4);
    printf("%f \t %f \t %f \t %f \n",resultado5, resultado6, resultado7, resultado8);
    printf("%f \t %f \t %f \t %f \n",resultado9, resultado10, resultado11, resultado12);
    printf("%f \t %f \t %f \t %f \n",resultado13, resultado14, resultado15, resultado16);

    return 1;
}