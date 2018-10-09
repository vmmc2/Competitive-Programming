#include <bits/stdc++.h>

using namespace std;

int main(){
    string iowa;
    int i, tamanho, contador = 0;
    while(getline(cin,iowa)){
        tamanho = iowa.length();
        for(i = 0; i < tamanho; i++){
            if(iowa[i] == '"' && contador%2 == 0){
                cout << "``";
                contador++;
            }
            else if(iowa[i] == '"' && contador%2 != 0){
                cout <<"''";
                contador++;
            }
            else{
                cout << iowa[i];
            }
        }
        cout << "\n";
    }
    return 0;
}