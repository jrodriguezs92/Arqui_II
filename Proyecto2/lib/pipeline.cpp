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
        while (isIFIDOcupado) {}
        ifid.instruccion = memInstr.at(pc);
        
        // Desactiva paso a la nueva instruccion, para evitar conflictos
        isIFIDOcupado = true;
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

        // Activa paso a la nueva instruccion
        isIFIDOcupado = false;

        // Unidad de control

        // Convertir opCode a decimal para manipular con case,switch
        int decOpCode = strtol(opCode.c_str(), NULL, 2);

        while (isIDEXOcupado) {}

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

        isIDEXOcupado = true;
    }

    void EX(void) {
        // Definir variables para almacenar datos del pipe anterior
        // Datos
        short int ALUBopInm;                        // Operando Inmediato de entrada a unidades funcionales
        std::vector<unsigned short int> ALUAop;     // Operando vector de entrada a unidades funcionales
        std::vector<unsigned short int> ALUBop;     // Operando vector de entrada a unidades funcionales
        // Senyales de Control
        short int MuxBALU, MuxWB, ALUCtrl;

        // Flujo de datos hacia el proximo pipe
        //Datos
        exmem.DOAV = idex.DOAV;
        exmem.DOAE = idex.DOAE;
        exmem.dst1 = idex.dst1;
        exmem.dst2 = idex.dst2;
        exmem.inm2 = idex.inm2;
        // Control
        exmem.control.RegVWrite = idex.control.RegVWrite;
        exmem.control.RegEWrite = idex.control.RegEWrite;
        exmem.control.MemVWrite = idex.control.MemVWrite;
        exmem.control.MemVRead = idex.control.MemVRead;
        exmem.control.MemEWrite = idex.control.MemEWrite;
        exmem.control.MemERead = idex.control.MemERead;
        exmem.control.MuxWB = idex.control.MuxWB;

        // Asignar datos y senyales desde pipe anterior
        // Datos
        ALUAop = idex.DOAV;
        ALUBop = idex.DOBV;
        ALUBopInm = idex.inm1;
        // Senyales de control
        MuxBALU = idex.control.MuxBALU;
        ALUCtrl = idex.control.ALUCtrl;

        isIDEXOcupado = false;

        while (isEXMEMOcupado) {}
        
        if (ALUCtrl != -1) {
            // Definir vectores para separar ejecucion
            std::vector<unsigned short int> lane1AOp;   // Vector de entrada para lane 1
            std::vector<unsigned short int> lane2AOp;   // Vector de entrada para lane 2
            std::vector<unsigned short int> lane3AOp;   // Vector de entrada para lane 3
            std::vector<unsigned short int> lane4AOp;   // Vector de entrada para lane 4

            // Separar ejecucion por lanes equitativamente
            int j = 1;
            for (int i=0; i<ALUAop.size(); i++) {
                if (j == 1) {
                    lane1AOp.push_back(ALUAop.at(i));
                    j++;
                }
                else if (j == 2) {
                    lane2AOp.push_back(ALUAop.at(i));
                    j++;
                }
                else if (j == 3) {
                    lane3AOp.push_back(ALUAop.at(i));
                    j++;
                }
                else if (j == 4) {
                    lane4AOp.push_back(ALUAop.at(i));
                    j = 1;
                }
            }

            // Calcular numero de hilos para concurrencia
            int numThreads = 4;
            if (ALUAop.size() < 4) {
                numThreads = ALUAop.size();
            }
            
            // Creacion de estructuras con datos para hilos
            struct EXThreadStruct args[numThreads];
            pthread_t tids[numThreads];

            // Vector de resultado final
            std::vector<unsigned short int> resultadoEX;

            // Ejecucion para operaciones vector-escalar
            if (MuxBALU == 0) {
                for (int i=0; i<numThreads; i++) {
                    args[i].parInm = ALUBopInm;
                    args[i].op = ALUCtrl;
                    if (i==0){
                        args[i].parAV = lane1AOp;
                    }
                    else if (i==1){
                        args[i].parAV = lane2AOp;
                    }
                    else if (i==2){
                        args[i].parAV = lane3AOp;
                    }
                    else if (i==3){
                        args[i].parAV = lane4AOp;
                    }

                    pthread_attr_t attr;
	                pthread_attr_init(&attr);
                    pthread_create(&tids[i], &attr, runLane, &args[i]);
                }

                // Esperar a que los hilos terminen de ejecutar los lane
                for (int i = 0; i < numThreads; i++) {
                    pthread_join(tids[i], NULL);

                    // Unir resultados
                    for (int index=0; index<args[i].resultado.size(); index++){
                        resultadoEX.push_back(args[i].resultado.at(index));
                    }
                }
            }
            // Ejecucion para operaciones vector-vector
            else if (MuxBALU == 1) {
                // Si el vector operador no es de tamanyo completo, entonces, ajustar tamanyo de vector operador B
                std::vector<unsigned short int> ALUBopTmp;
                if (ALUAop.size() < 8) {
                    for (int i=0; i<ALUAop.size(); i++) {
                        ALUBopTmp.push_back(ALUBop.at(i));
                    }
                }

                // Definir vectores para separar ejecucion
                std::vector<unsigned short int> lane1BOp;   // Vector de entrada para lane 1
                std::vector<unsigned short int> lane2BOp;   // Vector de entrada para lane 2
                std::vector<unsigned short int> lane3BOp;   // Vector de entrada para lane 3
                std::vector<unsigned short int> lane4BOp;   // Vector de entrada para lane 4

                // Separar ejecucion por lanes equitativamente
                int j = 1;
                for (int i=0; i<ALUBopTmp.size(); i++) {
                    if (j == 1) {
                        lane1BOp.push_back(ALUBopTmp.at(i));
                        j++;
                    }
                    else if (j == 2) {
                        lane2BOp.push_back(ALUBopTmp.at(i));
                        j++;
                    }
                    else if (j == 3) {
                        lane3BOp.push_back(ALUBopTmp.at(i));
                        j++;
                    }
                    else if (j == 4) {
                        lane4BOp.push_back(ALUBopTmp.at(i));
                        j = 1;
                    }
                }

                for (int i=0; i<numThreads; i++) {
                    args[i].op = ALUCtrl;
                    if (i==0){
                        args[i].parAV = lane1AOp;
                        args[i].parBV = lane1BOp;
                    }
                    else if (i==1){
                        args[i].parAV = lane2AOp;
                        args[i].parBV = lane2BOp;
                    }
                    else if (i==2){
                        args[i].parAV = lane3AOp;
                        args[i].parBV = lane3BOp;
                    }
                    else if (i==3){
                        args[i].parAV = lane4AOp;
                        args[i].parBV = lane4BOp;
                    }

                    pthread_attr_t attr;
	                pthread_attr_init(&attr);
                    pthread_create(&tids[i], &attr, runLane, &args[i]);
                }

                // Esperar a que los hilos terminen de ejecutar los lane
                for (int i = 0; i < numThreads; i++) {
                    pthread_join(tids[i], NULL);

                    // Unir resultados
                    for (int index=0; index<args[i].resultado.size(); index++){
                        resultadoEX.push_back(args[i].resultado.at(index));
                    }
                }
            }

            // Flujo de senyales
            exmem.ALUOut = resultadoEX;
        }

        isEXMEMOcupado = true;
    }
    
    void MEM(void) {
        // Definir variables para almacenar datos del pipe anterior
        // Datos
        short int inm2;
        unsigned short int DOAE;
        std::vector<unsigned short int> DOAV;
        // Senyales de control
        unsigned short int MemVWrite, MemVRead, MemEWrite, MemERead;

        // Flujo de datos hacia el proximo pipe
        //Datos
        memwb.ALUOut = exmem.ALUOut;
        memwb.dst1 = exmem.dst1;
        memwb.dst2 = exmem.dst2;
        // Control
        memwb.control.RegVWrite = exmem.control.RegVWrite;
        memwb.control.RegEWrite = exmem.control.RegEWrite;

        // Asignar datos y senyales desde pipe anterior
        // Datos
        inm2 = exmem.inm2;
        DOAE = exmem.DOAE;
        DOAV = exmem.DOAV;
        // Control
        MemVWrite = exmem.control.MemVWrite;
        MemVRead = exmem.control.MemVRead;
        MemEWrite = exmem.control.MemEWrite;
        MemERead = exmem.control.MemERead;

        isEXMEMOcupado = false;

        while (isMEMWBOcupado){}

        std::vector<unsigned short int> DOMemV;
        unsigned short int DOMemE;

        // Memoria vectorial
        if (MemVWrite) {
            // Escritura en memoria
            memV.at(DOAE) = DOAV;
        }
        else if (MemVRead) {
            // Lectura de memoria
            DOMemV = memV.at(DOAE);
        }

        // Memoria escalar
        if (MemERead) {
            // Lectura en memoria
            DOMemE = memE.at(inm2);
        }

        // Flujo de datos hacia WB
        memwb.DOMemV = DOMemV;
        memwb.DOMemE = DOMemE;

        isMEMWBOcupado = true;
    }

    void WB(void) {
        // Definir variables para almacenar datos del pipe anterior
        // Datos
        std::vector<unsigned short int> ALUOut, DOMemV;
        unsigned short int DOMemE;
        short int dst1, dst2, MuxWB;
        // Control
        unsigned short int RegVWrite, RegEWrite;

        // Asignar datos y senyales desde pipe anterior
        // Datos
        ALUOut = memwb.ALUOut;
        DOMemV = memwb.DOMemV;
        DOMemE = memwb.DOMemE;
        dst1 = memwb.dst1;
        dst2 = memwb.dst2;
        // Control
        RegVWrite = memwb.control.RegVWrite;
        RegEWrite = memwb.control.RegEWrite;
        MuxWB = memwb.control.MuxWB;

        isMEMWBOcupado = false;

        // MUX WB
        std::vector<unsigned short int> DatoARegV;
        if (MuxWB == 0) {
            // Dato desde Unidad funcional
            DatoARegV = ALUOut;
        }
        else if (MuxWB == 1) {
            // Dato desde memoria
            DatoARegV = DOMemV;
        }

        // WB
        if (RegVWrite) {
            // Escritura en registro vectorial
            bancRegsV.at(dst1) = DatoARegV;
        }
        if (RegEWrite) { 
            // Escritura en registro escalar
            bancRegsE.at(dst2) = DOMemE;
        }
    }


    // Funciones complementarias

    void* runLane (void* arg) {
        struct EXThreadStruct *arg_struct = (struct EXThreadStruct*) arg;

        std::vector<unsigned short int> res;
        switch (arg_struct->op) {
            unsigned short int resultadoTmp;
            // XOR
            case 0:
                for (int i=0; i<arg_struct->parAV.size(); i++) {
                    resultadoTmp = (arg_struct->parAV.at(i)) ^ (arg_struct->parInm);
                    res.push_back(resultadoTmp);
                }

                break;
            
            // SUMA
            case 1:
                for (int i=0; i<arg_struct->parAV.size(); i++) {
                    if (((arg_struct->parAV.at(i)) + (arg_struct->parBV.at(i))) > 255) {
                        resultadoTmp = arg_struct->parAV.at(i);
                        for (int j = arg_struct->parInm; j>0; j--) {
                            if ((resultadoTmp+1) > 255) {
                                resultadoTmp = 0;
                            }
                            else {
                                resultadoTmp++;
                            }
                        }
                    }
                    else {
                        resultadoTmp = (arg_struct->parAV.at(i)) + (arg_struct->parBV.at[i]);
                    }
                    res.push_back(resultadoTmp);
                }

                break;

            // RESTA
            case 2:
                for (int i=0; i<arg_struct->parAV.size(); i++) {
                    if (((arg_struct->parAV.at(i)) - (arg_struct->parBV.at(i))) < 0) {
                        resultadoTmp = arg_struct->parAV.at(i);
                        for (int j = arg_struct->parInm; j>0; j--) {
                            if ((resultadoTmp-1) < 0) {
                                resultadoTmp = 255;
                            }
                            else {
                                resultadoTmp--;
                            }
                        }
                    }
                    else {
                        resultadoTmp = (arg_struct->parAV.at(i)) - (arg_struct->parBV.at[i]);
                    }
                    res.push_back(resultadoTmp);
                }

                break;

            // SHIFT CIRC DER
            case 3:


                break;

            // SHIFT CIRC IZQ
            case 4:

                break;

            // SHIFT DER
            case 5:
                for (int i=0; i<arg_struct->parAV.size(); i++) {
                    unsigned char opTmp = (unsigned char) (arg_struct->parAV.at(i));
                    unsigned char shNum = opTmp >> (arg_struct->parInm);
                    resultadoTmp = (unsigned short int) (shNum);
                }

                break;

            // SHIFT IZQ
            case 6:
                for (int i=0; i<arg_struct->parAV.size(); i++) {
                    unsigned char opTmp = (unsigned char) (arg_struct->parAV.at(i));
                    unsigned char shNum = opTmp << (arg_struct->parInm);
                    resultadoTmp = (unsigned short int) (shNum);
                }

                break;

            // SUMA INM
            case 7:
                for (int i=0; i<arg_struct->parAV.size(); i++) {
                    resultadoTmp = (arg_struct->parAV.at(i)) + (arg_struct->parInm);
                    res.push_back(resultadoTmp);
                }

                break;

            // RESTA INM
            case 8:
                for (int i=0; i<arg_struct->parAV.size(); i++) {
                    resultadoTmp = (arg_struct->parAV.at(i)) - (arg_struct->parInm);
                    res.push_back(resultadoTmp);
                }

                break;
        }

        arg_struct->resultado = res;

        pthread_exit(0);
    }
} //namespace arqII