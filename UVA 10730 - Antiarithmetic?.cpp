#include <bits/stdc++.h>

using namespace std;

int qtdnums;
vector <int> dados;

bool solve(){
    int seen[100000];
    for(int i = 0; i < qtdnums; i++){
        memset(seen, 0, sizeof(seen));
        for(int w = 0; w <= i; w++){ // vetor de frequencia para eu marcar quais eu ja vi durante
            seen[dados[w]] = 1;      // a travessia do array
        }
        for(int j = i+1; j < qtdnums; j++){
            seen[dados[j]] = 1; //marco o elemento como visitado
            int prox = dados[j] + dados[j] - dados[i]; //calculo do prox termo da P.A.
            if(prox >= 0 && prox < qtdnums && j < qtdnums - 1){
                if(!seen[prox]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int aux;
    while(scanf("%d: ", &qtdnums) && qtdnums){
        for(int i = 0; i < qtdnums; i++){
            scanf("%d", &aux);
            dados.push_back(aux);
        }
        if(solve()){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
        dados.clear();
    }
    return 0;
}
