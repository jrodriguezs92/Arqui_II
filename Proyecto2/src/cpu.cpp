/**
 * Copyright (C) 2019 
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * Ejecucion en el procesador
 *
 * @Author: Jeremy Rodriguez
 * @Date  : 03.05.2019
 */

#include "pipeline.hpp"
#include "comp.hpp"

std::vector<std::string> arqII::memInstr;
std::vector<std::vector<unsigned short int>> arqII::memV;
std::vector<short int> arqII::memE;
std::vector<std::vector<unsigned short int>> arqII::bancRegsV;
std::vector<unsigned short int> arqII::bancRegsE;

arqII::IFID arqII::ifid;
arqII::IDEX arqII::idex;
arqII::EXMEM arqII::exmem;
arqII::MEMWB arqII::memwb;

int main(int argc, char *argv[]) {

    // Verificar argumentos de entrada
    if (argc != 2) {
        std::cerr << "Por favor ingrese el nombre del archivo como argumento del programa" << std::endl;
        return 0;
    }

    // Inicializa memorias y Bancos de registros

    // Memoria vectorial
    std::vector<unsigned short int> tmpMemV;
    for (int i=0; i<65536; i++) {
        arqII::memV.push_back(tmpMemV);
    }
    // Memoria escalar
    short int tmpMemE;
    for (int i=0; i<128; i++) {
        arqII::memE.push_back(tmpMemE);
    }
    // Banco de registros vectoriales
    std::vector<unsigned short int> tmpBancV;
    for (int i=0; i<16; i++) {
        arqII::bancRegsV.push_back(tmpBancV);
    }
    // Banco de registros escalares
    unsigned short int tmpBancE;
    for (int i=0; i<32; i++) {
        arqII::bancRegsE.push_back(tmpBancE);
    }

    // Llenar memoria de instrucciones

    // Limpia vector para memoria de instrucciones
    arqII::memInstr.clear();

    // Abre el archivo a ejecutar, con el nombre dado por el argumento argv[1]
    std::ifstream myfile;
    myfile.open(argv[1]);

    if(myfile.is_open()) {
        // Linea leida
        std::string temp_string;
        while (getline (myfile,temp_string)) {

            // Compilar linea
            arqII::compile(temp_string);
        }
        myfile.close();
    } else {
        std::cerr << "Error al abrir archivo fuente" << std::endl;
    }

    // Abre el archivo binario
    std::ifstream myfileBin;
    myfileBin.open("machCode.txt");

    if(myfileBin.is_open()) {
        // Linea leida
        std::string temp_string;
        while (getline (myfileBin,temp_string)) {

            // Agregar instruccion a la memoria
            arqII::memInstr.push_back(temp_string);
        }
        myfileBin.close();
    } else {
        std::cerr << "Error al abrir archivo fuente" << std::endl;
    }

    // Ejecucion

    std::cout << "Inicia.." << std::endl;

    for (short int i=0; i<arqII::memInstr.size(); i++) {

        // IF
        std::cout << "IF/ID" << std::endl;
        arqII::IF(i);
        std::cout << "SIGNALS:" << std::endl << arqII::ifid.instruccion << std::endl;
    }

    std::cout << "Termina.." << std::endl;

    return 0;
}