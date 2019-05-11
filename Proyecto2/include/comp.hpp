/**
 * Copyright (C) 2019 
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * Definicion de funciones para compilador
 *
 * @Author: Jeremy Rodriguez
 * @Date  : 03.05.2019
 */


#ifndef COMP_H_INCLUDED
#define COMP_H_INCLUDED

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

namespace arqII 
{
    /**
     * Compilacion
     */
    void compile (std::string);

    /**
     * Convertir un numero entero a un binario.
     * Con un numero de bits deseado.
     */
    std::string decToBin(int, int);
}
#endif