/**
 * Clase que define el componente sumador con un numero binario + 1
 * Autor: Jeremy Rodriguez Solorzano
 */

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Sumador {

    private:
        
        /**
         * Convierte el string que representa al numero binario, a un decimal.
         */
        int binToDec(string bin);

        /**
         * Convierte el entero que representa al numero decimal, a un string binario.
         */
        string decToBin(int dec);

    public:
        
        /**
         * Realiza la suma ( data+1 )
         */
        string sum (string data);
};