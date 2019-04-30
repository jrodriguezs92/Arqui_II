/**
 * Clase que define el componente MUX con dos entradas y 1 salida
 * Autor: Jeremy Rodriguez Solorzano
 */

#include <iostream>
#include <string>

using namespace std;

class Mux2a1 {

    public:

        /**
         * Maneja las senyales de entrada para producir una salida de acuerdo a la senyal de seleccion
         */
        string handleSignal(short sel, string in1, string in2);
};