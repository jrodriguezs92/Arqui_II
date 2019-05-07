#include <cmath>
#include <algorithm>
#include <cstdint>
#include <cstdint>

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

string decToBin(int dec){
    int n = dec;
    string res;
    while(n>0) {
        int a = n%2;
        res.append(to_string(a));    
        n= n/2;
    }
    reverse(res.begin(), res.end());

    cout << res.length() << endl;

    if (res.length()<16) {
        string z = "";
        int longitud = res.length();
        while(longitud<16){
            cout << z << endl;
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


int main(int argc, char *argv[]) {

    unsigned short int z = 255;

    unsigned char a = (unsigned char) z;

    unsigned char b = a << 3;

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