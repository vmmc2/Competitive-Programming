#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(){
    int maximo = -10;
    int length;
    string frase;
    string answer;
    cin >> length;
    cin >> frase;
    map<string,int> ocurrences;
    string aux = "";
    for(int i = 0; i < (int)frase.length()-1; i++){
        aux = frase[i];
        aux += frase[i + 1];
        ocurrences[aux] = 0;
    }
    for(map<string,int>::iterator it = ocurrences.begin(); it != ocurrences.end(); ++it){
        for(int i = 0; i < (int)frase.length() - 1; i++){
            aux = frase[i];
            aux += frase[i + 1];
            if(it->first == aux){
                ocurrences[it->first]++;
            }
        }
    }
    for(map<string,int>::iterator it = ocurrences.begin(); it != ocurrences.end(); ++it){
        if(it->second > maximo){
            maximo = it->second;
            answer = it->first;
        }
    }
    cout << answer << endl;
    return 0;
}
