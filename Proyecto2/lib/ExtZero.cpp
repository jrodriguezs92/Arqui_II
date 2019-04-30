/**
 * Clase que define el componente extension de zero
 * Autor: Jeremy Rodriguez Solorzano
 */

#include "ExtZero.hpp"

string ExtZero::extZ(string n) {

    string z = "00000000000000000000000000000000000000000000000000000000";

    return z.append(n);
}