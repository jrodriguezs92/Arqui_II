/**
 * Copyright (C) 2019 
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * Ejecucion en el procesador
 *
 * @Author: Jeremy Rodriguez
 * @Date  : 03.05.2019
 */

#include "./include/pipeline.hpp"

namespace arqII
{
    int main(int argc, char *argv[]) {

        // Llenar memoria de instrucciones

        // Limpia vector para memoria de instrucciones
        memInstr.clear();

        // Abre el archivo a ejecutar, con el nombre dado por el argumento argv[1]
        std::ifstream myfile;
        myfile.open(argv[1]);

        if(myfile.is_open()) {
            // Linea leida
            std::string temp_string;
            while (getline (myfile,temp_string)) {
                // Agregar instruccion a la memoria
                memInstr.push_back(temp_string);
            }
            myfile.close();
        } else {
            std::cerr << "Error al abrir archivo fuente" << std::endl;
        }
    }
} //namespace arquiII