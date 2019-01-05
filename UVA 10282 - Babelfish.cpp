#include <bits/stdc++.h>
#include <string.h>
#include <sstream>

using namespace std;

int main(){
    map<string,string> dictionary;
    string palavra1;
    string linha;
    string palavra2;
    string aux;
    while(getline(cin, linha)){
        if(linha == ""){
            break;
        }
        else{
            istringstream sin(linha);
            sin >> palavra1 >> palavra2;
            dictionary[palavra2] = palavra1;
        }    
    }
    while(cin >> aux){
        if(dictionary.find(aux) == dictionary.end()){
            cout << "eh" << endl;
        }
        else{
            cout << dictionary[aux] << endl;
        }
    }
    return 0;
}
