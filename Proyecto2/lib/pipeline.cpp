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

    void IF(short int pc) {
        ifid.instruccion = memInstr.at(pc);
    }

    void ID(void) {
        // Decodificacion de instruccion

        std::string opCode, dstV, op1V, op2V, op1E, inmI, inmLE, op1VR, dstLE;
        opCode.assign(ifid.instruccion,0,4);                            // OpCode = Inst[15,12]
        op1V.assign(ifid.instruccion, 4, 4);                            // op1V = Inst[11,8]
        dstV.assign(ifid.instruccion, 4, 4);                            // dstV = Inst[11,8]
        op2V.assign(ifid.instruccion, 12, 4);                           // op2V = Inst[3,0]
        op1VR.assign(ifid.instruccion, 8, 4);                           // op1VR = Inst[7,4]
        op1E.assign(ifid.instruccion, 8, 5);                            // op1E = Inst[7,3]
        inmI.assign(ifid.instruccion, 8, 8);                            // inmI = Inst[7,0]
        inmLE.assign(ifid.instruccion, 9, 7);                           // inmLE = Inst[6,0]
        dstLE.assign(ifid.instruccion, 4, 5);                           // dstLE = Inst[11,7]

        // Unidad de control

        // Convertir opCode a decimal para manipular con case,switch
        int decOpCode = strtol(opCode.c_str(), NULL, 2);

        switch(decOpCode) {
            // XOR
            case 0:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = 0;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 0;

                break;

            // SUMA
            case 1:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 1;
                idex.control.MuxBALU = 1;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 1;

                break;

            // RESTA
            case 2:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 1;
                idex.control.MuxBALU = 1;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 2;

                break;

            // SHIFT CIRC DER
            case 3:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = 0;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 3;

                break;

            // SHIFT CIRC IZQ
            case 4:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = 0;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 4;

                break;

            // SHIFT DER
            case 5:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = 0;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 5;

                break;

            // SHIFT IZQ
            case 6:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = 0;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 6;

                break;

            // CARGA VECTOR
            case 7:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 0;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 1;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 1;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = -1;
                idex.control.MuxWB = 1;
                idex.control.ALUCtrl = -1;

                break;

            // ALMACENAMIENTO VECTOR
            case 8:
                idex.control.RegVWrite = 0;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 1;
                idex.control.MemVWrite = 1;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = -1;
                idex.control.MuxWB = -1;
                idex.control.ALUCtrl = -1;

                break;

            // CARGA ESCALAR
            case 9:
                idex.control.RegVWrite = 0;
                idex.control.RegVRead = 0;
                idex.control.RegEWrite = 1;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 1;
                idex.control.MuxABancRegV = -1;
                idex.control.MuxBALU = -1;
                idex.control.MuxWB = -1;
                idex.control.ALUCtrl = -1;

                break;

            // SUMA INMEDIATA
            case 10:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = 0;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 7;

                break;

            // RESTA INMEDIATA
            case 11:
                idex.control.RegVWrite = 1;
                idex.control.RegVRead = 1;
                idex.control.RegEWrite = 0;
                idex.control.RegERead = 0;
                idex.control.MemVWrite = 0;
                idex.control.MemVRead = 0;
                idex.control.MemEWrite = 0;
                idex.control.MemERead = 0;
                idex.control.MuxABancRegV = 0;
                idex.control.MuxBALU = 0;
                idex.control.MuxWB = 0;
                idex.control.ALUCtrl = 8;

                break;

            // En caso de que el opCode dado no este contemplado
            default:
                std::cerr << "Error: OpCode invalido" << std::endl;

                break;
        }

        // Flujo de datos

        // Convertir datos
        int dst1;
        int dirAV1 = dst1 = std::strtol(op1V.c_str(), NULL, 2);
        int dirAV2 = std::strtol(op1VR.c_str(), NULL, 2);
        int dirBV = std::strtol(op2V.c_str(), NULL, 2);
        int dirAE = std::strtol(op1E.c_str(), NULL, 2);
        int inm1 = std::strtol(inmI.c_str(), NULL, 2);
        int dst2 = std::strtol(dstLE.c_str(), NULL, 2);
        int inm2 = std::strtol(inmLE.c_str(), NULL, 2);

        // Verificar senyales de direccion para lectura en banco de registros vectoriales
        if ((idex.control.RegVRead) && (idex.control.MuxABancRegV == 0)) {
            idex.DOAV = bancRegsV.at(dirAV1);
            idex.DOBV = bancRegsV.at(dirBV);
        }
        else if ((idex.control.RegVRead) && (idex.control.MuxABancRegV == 1)) {
            idex.DOAV = bancRegsV.at(dirAV2);
            idex.DOBV = bancRegsV.at(dirBV);
        }
        
        // Verificar senyales de direccion para lectura en banco de registros escalares
        if (idex.control.RegERead) {
            idex.DOAE = bancRegsE.at(dirAE);
        }

        // Pasar senyales a registro pipe IDEX
        idex.dst1 = dst1;
        idex.dst2 = dst2;
        idex.inm1 = inm1;
        idex.inm2 = inm2;
    }

    void EX(void) {
    }
    
    void MEM(void) {
    }

    void WB(void) {
    }
} //namespace arqII