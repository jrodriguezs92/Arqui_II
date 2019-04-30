/**
 * Clase que define el componente banco de registros escalares
 * Autor: Jeremy Rodriguez Solorzano
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BancREsc {

    public:

        /**
         * Numero de registros
         */
        static size_t regsNum;

        /**
         * Vector que contiene los registros de 16 bits cada uno
         */
        vector<string> regs;
        
};