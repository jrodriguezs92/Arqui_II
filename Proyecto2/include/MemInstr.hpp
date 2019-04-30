/**
 * Clase que define el componente memoria de instrucciones
 * Autor: Jeremy Rodriguez Solorzano
 */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class MemInstr {

    public:

        /**
         * Numero de bloques para instrucciones de 16 bits
         */
        static size_t numBlocks;

        /**
         * Vector que contiene los registros de 16 bits cada uno
         */
        vector<string> blocks;
};