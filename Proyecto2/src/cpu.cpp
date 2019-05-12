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

    // Insertar datos necesarios a bancos de registros
    std::vector<unsigned short int> v1;
    v1.push_back(12);
    v1.push_back(13);
    v1.push_back(14);
    v1.push_back(15);
    v1.push_back(16);
    v1.push_back(17);
    v1.push_back(18);
    v1.push_back(19);
    arqII::bancRegsV.at(13) = v1;

    for (short int i=0; i<arqII::memInstr.size(); i++) {
        std::cout << "-------- INSTRUCCION " << i << "--------" << std::endl;

        // IF
        std::cout << "----- IF -----" << std::endl;
        arqII::IF(i);
        std::cout << "IF/ID" << std::endl;
        std::cout << "### DATA:" << std::endl;
        std::cout << "instruccion: "<< arqII::ifid.instruccion << std::endl;

        // ID
        std::cout << "----- ID -----" << std::endl;
        arqII::ID();
        std::cout << "ID/EX" << std::endl;
        std::cout << "### DATA:" << std::endl;
        std::cout << "DOAV: ";
        if (arqII::idex.DOAV.size() == 0) {
            std::cout << std::endl;
        }
        else {
            for (int i=0; i<arqII::idex.DOAV.size(); i++) {
                std::cout << arqII::idex.DOAV.at(i) << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "DOBV: ";
        if (arqII::idex.DOBV.size() == 0) {
            std::cout << std::endl;
        }
        else {
            for (int i=0; i<arqII::idex.DOBV.size(); i++) {
                std::cout << arqII::idex.DOBV.at(i) << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "DOAE: " << arqII::idex.DOAE << std::endl;
        std::cout << "dst1: " << arqII::idex.dst1 << std::endl;
        std::cout << "dst2: " << arqII::idex.dst2 << std::endl;
        std::cout << "inm1: " << arqII::idex.inm1 << std::endl;
        std::cout << "inm2: " << arqII::idex.inm2 << std::endl;
        std::cout << "### CONTROL:" << std::endl;
        std::cout << "RegVWrite: " << arqII::idex.control.RegVWrite << std::endl;
        std::cout << "RegVRead: " << arqII::idex.control.RegVRead << std::endl;
        std::cout << "RegEWrite: " << arqII::idex.control.RegEWrite << std::endl;
        std::cout << "RegERead: " << arqII::idex.control.RegERead << std::endl;
        std::cout << "MemVWrite: " << arqII::idex.control.MemVWrite << std::endl;
        std::cout << "MemVRead: " << arqII::idex.control.MemVRead << std::endl;
        std::cout << "MemEWrite: " << arqII::idex.control.MemEWrite << std::endl;
        std::cout << "MemERead: " << arqII::idex.control.MemERead << std::endl;
        std::cout << "MuxABancRegV: " << arqII::idex.control.MuxABancRegV << std::endl;
        std::cout << "MuxBALU: " << arqII::idex.control.MuxBALU << std::endl;
        std::cout << "MuxWB: " << arqII::idex.control.MuxWB << std::endl;
        std::cout << "ALUCrtl: " << arqII::idex.control.ALUCtrl << std::endl;

        // EX
        std::cout << "----- EX -----" << std::endl;
        arqII::EX();
        std::cout << "EX/MEM" << std::endl;
        std::cout << "### DATA:" << std::endl;
        std::cout << "ALUOut: ";
        if (arqII::exmem.ALUOut.size() == 0) {
            std::cout << std::endl;
        }
        else {
            for (int i=0; i<arqII::exmem.ALUOut.size(); i++) {
                std::cout << arqII::exmem.ALUOut.at(i) << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "DOAV: ";
        if (arqII::exmem.DOAV.size() == 0) {
            std::cout << std::endl;
        }
        else {
            for (int i=0; i<arqII::exmem.DOAV.size(); i++) {
                std::cout << arqII::exmem.DOAV.at(i) << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "DOAE: " << arqII::exmem.DOAE << std::endl;
        std::cout << "dst1: " << arqII::exmem.dst1 << std::endl;
        std::cout << "dst2: " << arqII::exmem.dst2 << std::endl;
        std::cout << "inm2: " << arqII::exmem.inm2 << std::endl;
        std::cout << "### CONTROL:" << std::endl;
        std::cout << "RegVWrite: " << arqII::exmem.control.RegVWrite << std::endl;
        std::cout << "RegEWrite: " << arqII::exmem.control.RegEWrite << std::endl;
        std::cout << "MemVWrite: " << arqII::exmem.control.MemVWrite << std::endl;
        std::cout << "MemVRead: " << arqII::exmem.control.MemVRead << std::endl;
        std::cout << "MemEWrite: " << arqII::exmem.control.MemEWrite << std::endl;
        std::cout << "MemERead: " << arqII::exmem.control.MemERead << std::endl;
        std::cout << "MuxWB: " << arqII::idex.control.MuxWB << std::endl;

        // MEM
        std::cout << "----- MEM -----" << std::endl;
        arqII::MEM();
        std::cout << "MEM/WB" << std::endl;
        std::cout << "### DATA:" << std::endl;
        std::cout << "ALUOut: ";
        if (arqII::memwb.ALUOut.size() == 0) {
            std::cout << std::endl;
        }
        else {
            for (int i=0; i<arqII::memwb.ALUOut.size(); i++) {
                std::cout << arqII::memwb.ALUOut.at(i) << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "DOMemV: ";
        if (arqII::memwb.DOMemV.size() == 0) {
            std::cout << std::endl;
        }
        else {
            for (int i=0; i<arqII::memwb.DOMemV.size(); i++) {
                std::cout << arqII::memwb.DOMemV.at(i) << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "DOMemE: " << arqII::memwb.DOMemE << std::endl;
        std::cout << "dst1: " << arqII::memwb.dst1 << std::endl;
        std::cout << "dst2: " << arqII::memwb.dst2 << std::endl;
        std::cout << "### CONTROL:" << std::endl;
        std::cout << "RegVWrite: " << arqII::memwb.control.RegVWrite << std::endl;
        std::cout << "RegEWrite: " << arqII::memwb.control.RegEWrite << std::endl;
        std::cout << "MuxWB: " << arqII::memwb.control.MuxWB << std::endl;

        // WB
        std::cout << "----- WB -----" << std::endl;
        arqII::WB();
    }

    std::cout << "Termina.." << std::endl;

    return 0;
}