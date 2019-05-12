#include <cmath>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <assert.h>

#include "./include/pipeline.hpp"

using namespace std;

//vector<string> memInstr;

class Comp {
    private:
        static size_t blocks;
    public:
        vector<unsigned long long> a;
};

size_t Comp::blocks = 16;


string extZTEST(string n) {

    string z = "00000000000000000000000000000000000000000000000000000000";

    return z.append(n);
}

string opTernTEST(short sel, string in1, string in2) {
    return sel ? in2 : in1;
}

int binToDec(string bin){
    int value = 0;
	int indexCounter = 0;
	for(int i = bin.length()-1; i >= 0; i--) { 
      if(bin[i] == '1') {
          value += pow(2, indexCounter);
    	}
        indexCounter++;
	}
	return value;
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

void* f1() {
    cout << "Hi from f1!" << endl;
}

void* ft1(void* arg) {
    int sum = 0;

    for (int i = 0; i<20; i++) {
        sum++;
    }

    cout << "SUM from " << (intptr_t) arg << "is " << sum << endl;

    pthread_exit(0);
}

void* ft2(void* arg) {
    cout << "executing t2" << endl;
}

void* ft3(void* arg) {
    cout << "executing t3" << endl;
}


// circular bit shift left of integer 'number' by 'n' bit positions
template < typename T > T circular_shift_left( T number, std::size_t n )
{
    static_assert( std::is_integral<T>::value, "an integral type is required" ) ;

    // the corresponding unsigned type if T is a signed integer, T itself otherwise
    using unsigned_type = std::make_unsigned_t<T> ;

    // number of bits in the integral type
    constexpr std::size_t NBITS = 8;

    n %= NBITS ; // bring the number of bit positions to shift by to within a valid range
    const unsigned_type un = number ; // the number interpreted as an unsigned value

    // circular bit shift left of an unsigned NBITS-bit integer by n bit positions
    return ( un << n ) | ( un >> (NBITS-n) ) ;
}

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
        stringstream strTmpV;
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
        stringstream strTmpInm;
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
        stringstream strTmpV1;
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
        stringstream strTmpV2;
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
        stringstream strTmpV3;
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
        stringstream strTmpV1;
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
        stringstream strTmpE;
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
        stringstream strTmpE;
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
        stringstream strTmpInm;
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

    fs << instr << std::endl;;

    fs.close();
}

unsigned char rotl8b (unsigned char x, unsigned char n)
{
  assert (n<8);
  return (x<<n) | (x>>(-n&7));
}

unsigned char rotr8b (unsigned char x, unsigned char n)
{
  assert (n<8);
  return (x>>n) | (x<<(-n&7));
}


int main(int argc, char *argv[]) {

/*     unsigned short int a = 255;
    unsigned short int n = 7;

    unsigned char a_c = (unsigned char) a;
    unsigned char n_c = (unsigned char) n;

    unsigned char res = rotl8b (a_c, n_c);

    unsigned short int res_si = (unsigned short int) res;

    cout << res_si << endl;


    unsigned char res2 = rotr8b (res, n_c);

    unsigned short int res_si2 = (unsigned short int) res2;

    cout << res_si2 << endl; */











/* 
    // Abre el archivo a ejecutar, con el nombre dado por el argumento argv[1]
    std::ifstream myfile;
    myfile.open(argv[1]);

    if(myfile.is_open()) {
        // Linea leida
        std::string temp_string;
        while (getline (myfile,temp_string)) {

            // Compilar linea
            compile(temp_string);



            // Agregar instruccion a la memoria
            //arqII::memInstr.push_back(temp_string);
        }
        myfile.close();
    } else {
        std::cerr << "Error al abrir archivo fuente" << std::endl;
    } */










    
/*     
    std::vector<std::vector<unsigned short int>> memV1;
    std::vector<unsigned short int> data;
    for (int i=0; i<65536; i++) {
        memV1.push_back(data);
    }
    std::vector<unsigned short int> dataIn;
    dataIn.push_back(12);
    dataIn.push_back(22);
    dataIn.push_back(32);
    dataIn.push_back(42);
    dataIn.push_back(52);
    dataIn.push_back(62);
    dataIn.push_back(72);
    dataIn.push_back(82);
    unsigned short index = 3;
    memV1.at(index) = dataIn;

    for (int i=0; i<dataIn.size(); i++) {
        cout << memV1.at(index).at(i) << "    ";
    }
    cout << endl;

    std::vector<unsigned short int> dataIn2;
    dataIn2.push_back(1);
    dataIn2.push_back(2);
    dataIn2.push_back(3);
    dataIn2.push_back(4);
    dataIn2.push_back(5);
    dataIn2.push_back(6);
    dataIn2.push_back(7);
    dataIn2.push_back(8);

    memV1.at(index) = dataIn2;

    for (int i=0; i<dataIn.size(); i++) {
        cout << memV1.at(index).at(i) << "    ";
    }

    cout << endl; */












     unsigned short int z = 5;

    unsigned char a = (unsigned char) z;

    short int k = 3;

    unsigned char b = a << k;

    unsigned short int c = (unsigned short int) b;

    cout << c << endl;








/* 
    unsigned short int num = 254;
    string numS = to_string(num);

    

    cout << numS << endl << numH << endl; */
    
    /* unsigned char x =0x7F;
    cout << " Original: " << (int) x << endl;
    x = ( x << 1 ) + ( x >> 7 );                                                                                   
    cout << " Final:    " << (int) x << endl; */

    








/* 
    int x = 12;     // binary: 1100
    int y = 10;     // binary: 1010
    int z = x ^ y;  // binary: 0110, or decimal 6
    int r = z ^ y;  // binary: 1100, or decimal 12

    cout << "XOR1: " << z << endl;
    cout << "XOR2: " << r << endl; */










/*     std::vector<unsigned short int> ALUAop;
    ALUAop.push_back(1);
    ALUAop.push_back(2);
    ALUAop.push_back(3);

    std::vector<unsigned short int> lane1AOp;
    std::vector<unsigned short int> lane2AOp;
    std::vector<unsigned short int> lane3AOp;
    std::vector<unsigned short int> lane4AOp;

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

    cout << "lane 1 : " << endl;

    for (int i=0; i<lane1AOp.size(); i++) {
        cout << lane1AOp.at(i) << "     ";
    }
    cout << endl;

    cout << "lane 2 : " << endl;

    for (int i=0; i<lane2AOp.size(); i++) {
        cout << lane2AOp.at(i) << "     ";
    }
    cout << endl;

    cout << "lane 3 : " << endl;

    for (int i=0; i<lane3AOp.size(); i++) {
        cout << lane3AOp.at(i) << "     ";
    }
    cout << endl;

    cout << "lane 4 : " << endl;

    for (int i=0; i<lane4AOp.size(); i++) {
        cout << lane4AOp.at(i) << "     ";
    }
    cout << endl; */










/* 
    std::vector<unsigned short int> VA;
    VA.push_back(1);

    if (VA.size() == 0) {
        cout << "VECTOR NULO" << endl;
    } */









/* 
    clock_t start, end;

    start = clock();

    for (int i=0; i<10000; i++) {}

    end = clock();

    clock_t total = end - start;

    cout << "clock ticks total " << total << endl; */







    
/*     int a = 5;

    short int b = a;

    cout << "int: " << a << endl << "short: " << b << endl; */









  /*   string bin = "0100";

    int dec = strtol(bin.c_str(), NULL, 2);

    cout << dec << endl; */









/* 
    pthread_t tid1;
    pthread_t tid2;

    pthread_attr_t attr;
	pthread_attr_init(&attr);

    pthread_create(&tid1, &attr, ft1, (void*) 1);
    pthread_create(&tid2, &attr, ft1, (void*) 2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL); */
    

   
    







    /* arqII::memInstr.clear();
    //memInstr.clear();

    string filename;
    filename = string(argv[1]);

    ifstream myfile;
    myfile.open(argv[1]);

    if(myfile.is_open()) {
        string temp_string;
        while (getline (myfile,temp_string)) {
            arqII::memInstr.push_back(temp_string);
            cout << temp_string << '\n';
        }
        cout << arqII::memInstr.size() << endl;
        myfile.close();
        int i = 0;
        while (i<arqII::memInstr.size()){
            cout << arqII::memInstr.at(i) << endl;
            i++;
        }
    } else {
        cout << "NO abriio ni picha" << endl;
    } */






   /*  thread t1(f1);
    t1.join(); */






/*     string bin = decToBin(6000);
    cout << "Dec to Bin: " << bin << endl; */





    // int res = binToDec("1111111111111111");

    // cout << "Bin to dec: " << res << endl;






/*     string ret = opTernTEST(1, "0000000000", "111111111111");

    cout << "Resultado Operador ternario: " << ret << endl; */







    /* size_t a = 67000;

    cout << "Size_t: " << a << endl; */










    /* vector<string> a;

    a.push_back("1010101010101011");

    cout << "Vector[0] = " << a[0] << endl; */






    /* string bin = "10101010";
    string ret = extZTEST(bin);

    cout << "String sin extender: " << bin << endl;

    cout << "String extendido: " << ret << endl;

    cout << "String extendido length: " << ret.length() << endl; */






    /* Comp c;
    c.a.push_back(0b1111111111111111111111111111111111111111111111110000000000000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111000000000000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111100000000000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111110000000000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111000000000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111100000000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111110000000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111000000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111100000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111110000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111111000000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111111100000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111111110000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111111111000);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111111111100);
    c.a.push_back(0b1111111111111111111111111111111111111111111111111111111111111110);

    cout << c.a.at(14) << "\n" << "Size: " << sizeof(Comp) << "\n" << "Elements: " << c.a.size() << endl; */
    return 0;
}