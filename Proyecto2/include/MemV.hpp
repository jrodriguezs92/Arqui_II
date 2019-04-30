/**
 * Clase que define el componente memoria vectorial
 * Autor: Jeremy Rodriguez Solorzano
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MemV {

    public:

        /**
         * Numero de bloques para vectores de 64 bits
         */
        static size_t numBlocks;

        /**
         * Vector que contiene los registros de 64 bits cada uno
         */
        vector<string> blocks;
};