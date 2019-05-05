#include <cmath>
#include <algorithm>

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
    cout << "executing t1   " << (long) arg << endl;

    pthread_exit(0);
}

void* ft2(void* arg) {
    cout << "executing t2" << endl;
}

void* ft3(void* arg) {
    cout << "executing t3" << endl;
}

int main(int argc, char *argv[]) {
    
/*     int a = 5;

    short int b = a;

    cout << "int: " << a << endl << "short: " << b << endl; */









  /*   string bin = "0100";

    int dec = strtol(bin.c_str(), NULL, 2);

    cout << dec << endl; */










    /* pthread_t tid;

    pthread_attr_t attr;
	pthread_attr_init(&attr);

    pthread_create(&tid, &attr, ft1, (void*) 1);

    pthread_join(tid, NULL); */
    

   
    







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