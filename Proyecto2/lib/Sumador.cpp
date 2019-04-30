/**
 * Clase que define el componente sumador con un numero binario + 1
 * Autor: Jeremy Rodriguez Solorzano
 */

#include "Sumador.hpp"

string Sumador::sum(string data) {

    int decData = binToDec(data);
    int res = decData+1;

    string bin = decToBin(res);

    return bin;
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