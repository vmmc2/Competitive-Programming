#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 9999999

using namespace std;

typedef long long ll;

bool checka(string palavra){
    bool ok = true;
    if(palavra.find(".") == string::npos){
        for(int i = 0; i < (int)palavra.size(); i++){
            if((int)palavra[i] >= 65 && palavra[i] <= 90) return false;
        }
    }else{
        for(int i = 0; i < (int)palavra.size() - 1; i++){
            if((int)palavra[i] >= 65 && palavra[i] <= 90) return false;
        }
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string frase;
    int maior = -20;
    string answer;
    string finale = "";
    while(getline(cin, frase)){
        stringstream ss(frase);
        string palavra;
        while(ss >> palavra){
            if(palavra == "E-N-D") continue;
            if(checka(palavra)){ // todas as letras da minha string sao minusculas...
                //tem que checkar se temos caracteres indevidos
                if(palavra.find("(") != string::npos && palavra.find(")") != string::npos){
                    if((int)palavra.size() - 2 > maior){
                        maior = (int)palavra.size() - 2;
                        answer = palavra;
                    }
                }
                if(palavra.find(".") != string::npos){ //se tem um ponto na minha frase eu tenho que desconsiderar ele do seu tamanho...
                    if((int)palavra.size() - 1 > maior){
                        maior = (int)palavra.size() - 1;
                        answer = palavra;
                    }
                }else{//caso contrario eu posso considerar o tamanho da palavra inteiro.
                    if((int)palavra.size() > maior){
                        maior = (int)palavra.size();
                        answer = palavra;
                    }
                }
            }else{
                continue;
            }
        }
    }
    if(maior != answer.size()){
        for(int i = 0; i < (int)answer.size() - 1; i++){
            cout << answer[i];
        }
    }else{
        for(int i = 0; i < (int)answer.size(); i++){
            
        }
    }
    return 0;
}
