#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Declaracion de componentes estaticos

extern vector<string> memInstr;                         // Memoria de instruciones
extern vector<vector<unsigned short int>> memV;         // Memoria de datos vectoriales
extern vector<short int> memE;                          // Memoria de datos escalares
extern vector< vector<unsigned short int>> bancRegsV;   // Banco de registros vectoriales
extern vector<unsigned short int> bancRegsE;            // Banco de registros escalares

// Registros pipeline

struct IFID {
    string instruccion;                                 // Instruccion
};

extern struct IFID ifid;


struct IDEX {
    vector<vector<unsigned short int>> DOAV;            // Dato A de salida del banco de registro vectorial
    vector<vector<unsigned short int>> DOBV;            // Dato A de salida del banco de registro vectorial
    unsigned short int DOAE;                            // Dato A de salida del banco de registro escalar
    short int dst1;                                     // Datos dst de [11,8], formatos I y R
    short int dst2;                                     // Datos dst de [11,7], formato LE
    short int inm1;                                     // Dato Inm de [7,0], formato I
    short int inm2;                                     // Dato Inm de [6,0], formato LE

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
        short int MuxABancRegV;                         // Senyal de control: MUX a la entrada DirA del banco de registros vectoriales
        short int MuxBALU;                              // Senyal de control: MUX a la entrada B de la ALU
        short int MuxWB;                                // Senyal de control: MUX en segmento WB
    }control;
};

extern struct IDEX idex;


struct EXMEM {
    vector<vector<unsigned short int>> ALUOut;          // Dato resultado de unidad Funcional
    vector<vector<unsigned short int>> DOAV;            // Dato A de salida del banco de registro vectorial
    unsigned short int DOAE;                            // Dato A de salida del banco de registro escalar
    short int dst1;                                     // Datos dst de [11,8], formatos I y R
    short int dst2;                                     // Datos dst de [11,7], formato LE
    short int inm2;                                     // Dato Inm de [6,0], formato LE

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
    }control;

};

extern struct EXMEM exmem;


struct MEMWB {
    vector<vector<unsigned short int>> ALUOut;          // Dato resultado de unidad Funcional
    vector<vector<unsigned short int>> DOMemV;          // Dato de salida la memoria vectorial
    unsigned short int DOMemE;                          // Dato de salida la memoria escalar
    short int dst1;                                     // Datos dst de [11,8], formatos I y R
    short int dst2;                                     // Datos dst de [11,7], formato LE

    // Senyales de control
    struct {
        unsigned short int RegVWrite;                   // Senyal de control: Escritura en banco de registros vectorial
        unsigned short int RegVRead;                    // Senyal de control: Lectura en banco de registros vectorial
        unsigned short int RegEWrite;                   // Senyal de control: Escritura en banco de registros escalar
        unsigned short int RegERead;                    // Senyal de control: Lectura en banco de registros vectorial
    }control;
};

extern struct MEMWB memwb;