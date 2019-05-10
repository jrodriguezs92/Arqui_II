/**
 * Copyright (C) 2019 
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * Definicion de segmentos para el procesador pipeline vectorial
 *
 * @Author: Jeremy Rodriguez
 * @Date  : 03.05.2019
 */


#ifndef PIPELINE_H_INCLUDED
#define PIPELINE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <thread>
#include <cstring>
#include <sstream>
#include <algorithm>

namespace arqII 
{

    // Declaracion de componentes estaticos

    static int clk = 0;
    std::vector<std::string> memInstr;                       // Memoria de instruciones
    std::vector<std::vector<unsigned short int>> memV;       // Memoria de datos vectoriales
    std::vector<short int> memE;                             // Memoria de datos escalares
    std::vector<std::vector<unsigned short int>> bancRegsV;  // Banco de registros vectoriales
    std::vector<unsigned short int> bancRegsE;               // Banco de registros escalares
    static bool isIFIDOcupado = false;                       // Evita sobreescritura sobre pipe IFID
    static bool isIDEXOcupado = false;                       // Evita sobreescritura sobre pipe IDEX
    static bool isEXMEMOcupado = false;                      // Evita sobreescritura sobre pipe EXMEM
    static bool isMEMWBOcupado = false;                      // Evita sobreescritura sobre pipe MEMWB

    // Estructura para parametros de los hilos de EX
    struct EXThreadStruct {
        std::vector<unsigned short int> parAV;
        std::vector<unsigned short int> parBV;
        short int parInm;
        std::vector<unsigned short int> resultado;
        short int op;
    };

    // Registros pipeline

    struct IFID {
        std::string instruccion;      // Instruccion
    };

    struct IFID ifid;


    struct IDEX {
        std::vector<unsigned short int> DOAV;  // Dato A de salida del banco de registro vectorial
        std::vector<unsigned short int> DOBV;  // Dato A de salida del banco de registro vectorial
        unsigned short int DOAE;               // Dato A de salida del banco de registro escalar
        short int dst1;                        // Datos dst de [11,8], formatos I y R
        short int dst2;                        // Datos dst de [11,7], formato LE
        short int inm1;                        // Dato Inm de [7,0], formato I
        short int inm2;                        // Dato Inm de [6,0], formato LE

        // Senyales de control
        struct {
            unsigned short int RegVWrite;                   // Senyal de control: Escritura en banco de registros vectorial
            unsigned short int RegVRead;                    // Senyal de control: Lectura en banco de registros vectorial
            unsigned short int RegEWrite;                   // Senyal de control: Escritura en banco de registros escalar
            unsigned short int RegERead;                    // Senyal de control: Lectura en banco de registros vectorial
            unsigned short int MemVWrite;                   // Senyal de control: Escritura en memoria vectorial
            unsigned short int MemVRead;                    // Senyal de control: Lectura en memoria vectorial
            unsigned short int MemEWrite;                   // Senyal de control: Escritura en memoria escalar
            unsigned short int MemERead;                    // Senyal de control: Lectura en memoria escalar
            short int MuxABancRegV;                         // Senyal de control: MUX a la entrada DirA del banco de registros vectoriales / 0->Inst[11,8], 1->Inst[7,4], -1->Disable
            short int MuxBALU;                              // Senyal de control: MUX a la entrada B de la ALU / 0->Inm[7,0], 1->DOBV, -1->Disable
            short int MuxWB;                                // Senyal de control: MUX en segmento WB / 0->ALUOut, 1->DOAV, -1->Disable
            short int ALUCtrl;                              // Senyal de control de operaciones de las unidades funcionales /0->XOR, 1->SUMA, 2->RESTA, 3->SHIFT C DER, 4->SHIFT C IZQ, 5->SHIFT DER, 6->SHIFT IZQ, 7->SUMA INM, 8->RESTA INM
        }control;
    };

    struct IDEX idex, idextmp;


    struct EXMEM {
        std::vector<unsigned short int> ALUOut;                 // Dato resultado de unidad Funcional
        std::vector<unsigned short int> DOAV;                   // Dato A de salida de la memoria vectorial
        unsigned short int DOAE;                                // Dato A de salida de la memoria escalar
        short int dst1;                                         // Datos dst de [11,8], formatos I y R
        short int dst2;                                         // Datos dst de [11,7], formato LE
        short int inm2;                                         // Dato Inm de [6,0], formato LE

        // Senyales de control
        struct {
            unsigned short int RegVWrite;                   // Senyal de control: Escritura en banco de registros vectorial
            unsigned short int RegEWrite;                   // Senyal de control: Escritura en banco de registros escalar
            unsigned short int MemVWrite;                   // Senyal de control: Escritura en memoria vectorial
            unsigned short int MemVRead;                    // Senyal de control: Lectura en memoria vectorial
            unsigned short int MemEWrite;                   // Senyal de control: Escritura en memoria escalar
            unsigned short int MemERead;                    // Senyal de control: Lectura en memoria escalar
            short int MuxWB;                                // Senyal de control: MUX en segmento WB / 0->ALUOut, 1->DOAV, -1->Disable
        }control;
    };

    struct EXMEM exmem;


    struct MEMWB {
        std::vector<unsigned short int> ALUOut;                 // Dato resultado de unidad Funcional
        std::vector<unsigned short int> DOMemV;                 // Dato de salida la memoria vectorial
        unsigned short int DOMemE;                              // Dato de salida la memoria escalar
        short int dst1;                                         // Datos dst de [11,8], formatos I y R
        short int dst2;                                         // Datos dst de [11,7], formato LE

        // Senyales de control
        struct {
            unsigned short int RegVWrite;                       // Senyal de control: Escritura en banco de registros vectorial
            unsigned short int RegEWrite;                       // Senyal de control: Escritura en banco de registros escalar
            short int MuxWB;                                    // Senyal de control: MUX en segmento WB / 0->ALUOut, 1->DOAV, -1->Disable
        }control;
    };

    struct MEMWB memwb;


    // Prototipos

    /**
     * Ejecuta segmento Instruction Fetch
     */
    void IF (short int);
    
    /**
     * Ejecuta segmento Instruction Decode
     */ 
    void ID (void);

    /**
     * Ejecuta segmento Execute
     */
    void EX (void);

    /**
     * Ejecuta segmento Memmory
     */
    void MEM (void);

    /**
     * Ejecuta segmento Write Back
     */
    void WB (void);

    // Funciones complementarias

    /**
     * Ejecucion de lane
     */
    void* runLane (void*);

    /**
     * Compilacion
     */
    void compile (std::string);

    /**
     * Convertir un numero entero a un binario.
     * Con un numero de bits deseado.
     */
    std::string decToBin(int, int);

} //namespace arquiII
#endif