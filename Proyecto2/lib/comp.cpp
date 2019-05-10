/**
 * Copyright (C) 2019 
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * Convierte lenguaje ensamblador propio a codigo maquina
 *
 * @Author: Jeremy Rodriguez
 * @Date  : 03.05.2019
 */

#include "pipeline.hpp"

namespace arqII
{

    /**
     * Compila la instruccion dada, la convierte a codigo maquina
     */
    void compile (std::string linea) {
        std::ofstream fs("machCode.txt", std::ios_base::app | std::ios_base::out);

        // Instruccion
        std::string instr = "";

        // Cast string linea a char *
        char * cstr = new char [linea.length()+1];
        std::strcpy(cstr, linea.c_str());

        // Separar mnemonico
        char * mn = std::strtok(cstr, " ");

        // Almacena operadores
        std::vector<char *> operadores;
        // Separar operadores por 'coma'
        char * op = std::strtok(NULL,",");
        operadores.push_back(op);
        while (op!=0) {
            op = std::strtok(NULL,",");
            operadores.push_back(op);
        }

        // Manejo de instrucciones

        // Tipo I
        if ( ((std::strcmp(mn, "vxori")) == 0) || 
            (std::strcmp(mn, "veshrc") == 0) || 
            (std::strcmp(mn, "veshlc") == 0) || 
            (std::strcmp(mn, "veshr") == 0)  ||
            (std::strcmp(mn, "veshl") == 0)  || 
            (std::strcmp(mn, "vvaddi") == 0) || 
            (std::strcmp(mn, "vvsubi") == 0)) {
            // Agregar opCode
            if ((std::strcmp(mn, "vxori")) == 0) {
                instr.append("0000");
            }
            else if ((std::strcmp(mn, "veshrc")) == 0) {
                instr.append("0011");
            }
            else if ((std::strcmp(mn, "veshlc")) == 0) {
                instr.append("0100");
            }
            else if ((std::strcmp(mn, "veshr")) == 0) {
                instr.append("0101");
            }
            else if ((std::strcmp(mn, "veshl")) == 0) {
                instr.append("0110");
            }
            else if ((std::strcmp(mn, "vvaddi")) == 0) {
                instr.append("1010");
            }
            else {
                instr.append("1011");
            }

            // Codificar operadores

            // vector
            char * opV = operadores.at(0);
            char * VRegNum = std::strtok(opV,"v");
            // Convertir numero de vector a entero para representar la direccion
            std::stringstream strTmpV;
            strTmpV << VRegNum;
            int intValueV;
            strTmpV >> intValueV;
            // Convertir a binario en string
            std::string opVBin = decToBin(intValueV, 4);
            // Concatenar a instr
            instr.append(opVBin);

            // Inmediato
            char * opInm = operadores.at(1);
            // Convertir numero de inmediato a entero
            std::stringstream strTmpInm;
            strTmpInm << opInm;
            int intValueInm;
            strTmpInm >> intValueInm;
            // Convertir a binario en string
            std::string opInmBin = decToBin(intValueInm, 8);
            // Concatenar a instr
            instr.append(opInmBin);
        }
        // Tipo R
        else if ( ((std::strcmp(mn, "vvadd")) == 0) || 
                ((std::strcmp(mn, "vvsub")) == 0)) {
            // Agregar opCode
            if ((std::strcmp(mn, "vvadd")) == 0) {
                instr.append("0001");
            }
            else {
                instr.append("0010");
            }        

            // Codificar operadores

            // vector dst
            char * opV1 = operadores.at(0);
            char * VRegNum1 = std::strtok(opV1,"v");
            // Convertir numero de vector a entero para representar la direccion
            std::stringstream strTmpV1;
            strTmpV1 << VRegNum1;
            int intValueV1;
            strTmpV1 >> intValueV1;
            // Convertir a binario en string
            std::string opV1Bin = decToBin(intValueV1, 4);
            // Concatenar a instr
            instr.append(opV1Bin);

            // vector op1
            char * opV2 = operadores.at(1);
            char * VRegNum2 = std::strtok(opV2,"v");
            // Convertir numero de vector a entero para representar la direccion
            std::stringstream strTmpV2;
            strTmpV2 << VRegNum2;
            int intValueV2;
            strTmpV2 >> intValueV2;
            // Convertir a binario en string
            std::string opV2Bin = decToBin(intValueV2, 4);
            // Concatenar a instr
            instr.append(opV2Bin);

            // vector op2
            char * opV3 = operadores.at(2);
            char * VRegNum3 = std::strtok(opV3,"v");
            // Convertir numero de vector a entero para representar la direccion
            std::stringstream strTmpV3;
            strTmpV3 << VRegNum3;
            int intValueV3;
            strTmpV3 >> intValueV3;
            // Convertir a binario en string
            std::string opV3Bin = decToBin(intValueV3, 4);
            // Concatenar a instr
            instr.append(opV3Bin);
        }
        // Tipo LSV
        else if ( (std::strcmp(mn, "vld") == 0) ||
                (std::strcmp(mn, "vstr") == 0)) {
            // Agregar opCode
            if (std::strcmp(mn, "vld") == 0) {
                instr.append("0111");
            }
            else {
                instr.append("1000");
            }

            // Codificar operadores

            // vector dst
            char * opV1 = operadores.at(0);
            char * VRegNum1 = std::strtok(opV1,"v");
            // Convertir numero de vector a entero para representar la direccion
            std::stringstream strTmpV1;
            strTmpV1 << VRegNum1;
            int intValueV1;
            strTmpV1 >> intValueV1;
            // Convertir a binario en string
            std::string opV1Bin = decToBin(intValueV1, 4);
            // Concatenar a instr
            instr.append(opV1Bin);

            // escalar
            char * opE = operadores.at(1);
            char * ERegNum1 = std::strtok(opE,"r");
            // Convertir numero de vector a entero para representar la direccion
            std::stringstream strTmpE;
            strTmpE << ERegNum1;
            int intValueE;
            strTmpE >> intValueE;
            // Convertir a binario en string
            std::string opEBin = decToBin(intValueE, 5);
            // Concatenar a instr
            instr.append(opEBin);
        }
        // Tipo LE
        else if ((std::strcmp(mn, "eld")) == 0){
            // Agregar opCode
            instr.append("1001");

            // Codificar operadores

            // escalar
            char * opE = operadores.at(0);
            char * ERegNum1 = std::strtok(opE,"r");
            // Convertir numero de vector a entero para representar la direccion
            std::stringstream strTmpE;
            strTmpE << ERegNum1;
            int intValueE;
            strTmpE >> intValueE;
            // Convertir a binario en string
            std::string opEBin = decToBin(intValueE, 5);
            // Concatenar a instr
            instr.append(opEBin);

            // Inmediato
            char * opInm = operadores.at(1);
            // Convertir numero de inmediato a entero
            std::stringstream strTmpInm;
            strTmpInm << opInm;
            int intValueInm;
            strTmpInm >> intValueInm;
            // Convertir a binario en string
            std::string opInmBin = decToBin(intValueInm, 7);
            // Concatenar a instr
            instr.append(opInmBin);
        }
        else {
            std::cerr << "Error: Instruccion desconocida" << std::endl;
        }

        // Concatenar instruccion en lenguaje maquina al archivo
        fs << instr << std::endl;;

        // Cerrar archivo leido
        fs.close();
    }






    std::string decToBin(int dec, int nBits){
        int n = dec;
        std::string res;
        while(n>0) {
            int a = n%2;
            res.append(std::to_string(a));    
            n= n/2;
        }
        std::reverse(res.begin(), res.end());

        if (res.length()<nBits) {
            std::string z = "";
            int longitud = res.length();
            while(longitud<nBits){
                z.append("0");
                longitud++;
            }
            z.append(res);
            res = z;
        }
        return res;
    }

} //namespace arqII