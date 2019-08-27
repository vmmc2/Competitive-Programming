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
            if(palavra[i] == '0' || palavra[i] == '1' || palavra[i] == '2' || palavra[i] == '3') return false;
            if(palavra[i] == '4' || palavra[i] == '5' || palavra[i] == '6' || palavra[i] == '7') return false;
            if(palavra[i] == '8' || palavra[i] == '9') return false;
            //if((int)palavra[i] >= 60 && palavra[i] <= 96) return false;
            if((int)palavra[i] >= 35 && palavra[i] <= 38) return false;
            if((int)palavra[i] == 42 && palavra[i] == 43) return false;
            if((int)palavra[i] == 47) return false;
        }
    }else{
        for(int i = 0; i < (int)palavra.size() - 1; i++){
            if(palavra[i] == '0' || palavra[i] == '1' || palavra[i] == '2' || palavra[i] == '3') return false;
            if(palavra[i] == '4' || palavra[i] == '5' || palavra[i] == '6' || palavra[i] == '7') return false;
            if(palavra[i] == '8' || palavra[i] == '9') return false;
            //if((int)palavra[i] >= 60 && palavra[i] <= 96) return false;
            if((int)palavra[i] >= 35 && palavra[i] <= 38) return false;
            if((int)palavra[i] == 42 && palavra[i] == 43) return false;
            if((int)palavra[i] == 47) return false;
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
    string trash = "()!,.':;";
    while(getline(cin, frase)){
        stringstream ss(frase);
        string palavra;
        while(ss >> palavra){
            if(palavra == "E-N-D") continue;
            if(checka(palavra)){ // todas as letras da minha string sao minusculas...
                //tem que checkar se temos caracteres indevidos
                int dale = 0;
                for(int i = 0; i < (int)trash.size(); i++){
                    if(palavra.find(trash[i]) != string::npos){
                        dale++;
                    }
                }
                if((int)palavra.size() - dale > maior){
                    maior = (int)palavra.size() - dale;
                    answer = palavra;
                }
            }else{
                continue;
            }
        }
    }
    for(int i = 0; i < (int)answer.size(); i++){
        if((answer[i] >= 97 && answer[i] <=122) || answer[i] == '-'){
            cout << answer[i];
        }else if(answer[i] >= 65 && answer[i] <= 90){
            cout << char(answer[i] + 32);
        }
    }
    return 0;
}
