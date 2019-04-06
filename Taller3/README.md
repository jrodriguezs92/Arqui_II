# Arquitectura de computadores II, Taller 3
Instituto Tecnológico de Costa Rica  
Ingeniería en Computadores.  
2019, I Semestre.  

## Prerequisitos
Sistema operativo GNU/Linux, 64 bits.  

## Compilación y ejecución
Compilar cualquiera de los tres códigos fuente (hello_simd.c, mult_simd.c, max_simd.c) mediante el comando:
```
gcc -msse4 -o <filename ejecutable> <file name>.c
```
Donde <filename ejecutable> corresponde al nombre que se le quiera dar al archivo ejecutable resultado de la compilación, y <file name> corresponde al nombre del archivo que contiene el código fuente que se quiere compilar.  

Ejecutar cualquiera de los ejcutables mediante el comando:

```
./<filename ejecutable>
```

## Autor
* Jeremy Rodríguez Solórzano  
201209131  
jrodriguezs0292@gmail.com

## Version
1.0.0
