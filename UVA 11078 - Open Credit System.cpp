#include <bits/stdc++.h>
#include <sstream>

//SOLUTION: O(n*log(n))

using namespace std;

int main(){
    int numcasos;
    vector <int> dados;
    vector <int> roubo;
    int aux;
    int numstudents;
    int maior, menor, until;
    int indice;
    int flag;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        flag = 0;
        scanf("%d", &numstudents);
        for(int j = 1; j <= numstudents; j++){
            scanf("%d", &aux);
            dados.push_back(aux);
            roubo.push_back(aux);
        }
        stable_sort(roubo.begin(), roubo.end());
        for(int k = 0; k < (int)roubo.size(); k++){
            if(dados[k] != roubo[k])flag = 1;
        }
        if(flag == 0){
            until = -9999999;
            for(int k = 0; k < (int)roubo.size()-1; k++){
                if(roubo[k]-roubo[k+1] > until){
                    until = roubo[k] - roubo[k+1];   
                }    
            }
        }
        else{
        maior = -99999999;
        menor = 99999999;
        until = -9999999;
        for(int j = 0; j < (int)dados.size(); j++){
            if(dados[j] > maior){
                if(j > 0){
                    if(maior - dados[j] > until){
                        //printf("entrei -- j: %d\n", j);
                        //printf("j: %d\n", j);
                        until = maior - dados[j];
                        indice = j;
                        //printf("hey Ind: %d --- j: %d\n", j);
                    }
                }
                maior = dados[j];
                menor = 99999999;
            }
            if(dados[j] < menor){
                menor = dados[j];
                if(j > 0){
                    if(maior - menor > until){
                        until = maior - menor;
                    }
                }    
            }
            //printf("until: %d\n", until);
        }
        }
        printf("%d\n", until);
        dados.clear();
        roubo.clear();
    }
    return 0;
}
