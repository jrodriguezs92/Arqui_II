/**
 * Clase que define el componente MUX con dos entradas y 1 salida
 * Autor: Jeremy Rodriguez Solorzano
 */

#include "Mux2a1.hpp"

string Mux2a1::handleSignal(short sel, string in1, string in2) {
    return sel ? in2 : in1;
}