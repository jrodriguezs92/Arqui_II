# Arquitectura de computadores II, Proyecto 2
Instituto Tecnológico de Costa Rica  
Computer Engineering (CE).
2019, I Semestre.    

## Ambiente
GNU/Linux Ubuntu 16.04.

## Instrucciones para compilación y ejecución
Abrir terminal en la ubicación raíz del del proyecto.

Ejecutar compilación mediante el comando:
```
make all
```

Mientras se contina ubicado en la carpeta raíz, ejecutar con:
```
./bin/cpu bin/inst.txt
```
Donde inst.txt se refiere al archivo fuente que contiene las instrucciones en lenguaje ensamblador propio, dentro de la carpeta bin.

Nota: cada vez que se quiera ejecutar, se debe borrar el archivo machCode.txt, ya sea directamente, o ejecutando el comando:
```
make clean
```
Seguido de una nueva compilación:
```
make all
```

## Autor
* Jeremy Rodríguez Solórzano  
jrodriguezs0292@gmail.com

## Version
1.0.0
