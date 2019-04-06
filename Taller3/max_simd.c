#include <emmintrin.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("Calcular valor maximo de cada columna de matriz 2x8...\n\n");
    printf("Ingrese datos...\n\n");

    //Datos de usuario

    short a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16;
    //Fila 1
    printf("Fila 1 columna 1 de la matriz: ");
    scanf("%hi",&a1);
    printf("Fila 1 columna 2 de la matriz: ");
    scanf("%hi",&a2);
    printf("Fila 1 columna 3 de la matriz: ");
    scanf("%hi",&a3);
    printf("Fila 1 columna 4 de la matriz: ");
    scanf("%hi",&a4);
    printf("Fila 1 columna 5 de la matriz: ");
    scanf("%hi",&a5);
    printf("Fila 1 columna 6 de la matriz: ");
    scanf("%hi",&a6);
    printf("Fila 1 columna 7 de la matriz: ");
    scanf("%hi",&a7);
    printf("Fila 1 columna 8 de la matriz: ");
    scanf("%hi",&a8);
    //Fila 2
    printf("Fila 2 columna 1 de la matriz: ");
    scanf("%hi",&a9);
    printf("Fila 2 columna 2 de la matriz: ");
    scanf("%hi",&a10);
    printf("Fila 2 columna 3 de la matriz: ");
    scanf("%hi",&a11);
    printf("Fila 2 columna 4 de la matriz: ");
    scanf("%hi",&a12);
    printf("Fila 2 columna 5 de la matriz: ");
    scanf("%hi",&a13);
    printf("Fila 2 columna 6 de la matriz: ");
    scanf("%hi",&a14);
    printf("Fila 2 columna 7 de la matriz: ");
    scanf("%hi",&a15);
    printf("Fila 2 columna 8 de la matriz: ");
    scanf("%hi",&a16);

    //Ingresar datos a vectores

    __m128i fila1 = _mm_set_epi16(a8,a7,a6,a5,a4,a3,a2,a1);
    __m128i fila2 = _mm_set_epi16(a16,a15,a14,a13,a12,a11,a10,a9);

    //Escoger mayor

    __m128i resultado = _mm_max_epi16 (fila1, fila2);

    //Imprimir resultado

    int dato = 0;

    printf("RESULTADO... \n");

    dato = _mm_extract_epi16(resultado,0);
    printf("%d \t", dato);
    dato = _mm_extract_epi16(resultado,1);
    printf("%d \t", dato);
    dato = _mm_extract_epi16(resultado,2);
    printf("%d \t", dato);
    dato = _mm_extract_epi16(resultado,3);
    printf("%d \t", dato);
    dato = _mm_extract_epi16(resultado,4);
    printf("%d \t", dato);
    dato = _mm_extract_epi16(resultado,5);
    printf("%d \t", dato);
    dato = _mm_extract_epi16(resultado,6);
    printf("%d \t", dato);
    dato = _mm_extract_epi16(resultado,7);
    printf("%d \t", dato);

    printf("\n");

    return 1;
}