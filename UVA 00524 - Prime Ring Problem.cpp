#include <bits/stdc++.h>

using namespace std;
int resposta[20] = {1};
int primos[13] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
int n;
void preprocessa(bool visitados[]){
    int i;
    for(i = 0; i < 20; i++){
        visitados[i] = 0;
    }
}
bool ChecaPrimo(int n){//Funcao para checar se um certo numero eh um numero primo, baseando-se no meu
//array de primos
    int i;
    for(int i = 0; i < 13; i++){
        if(n == primos[i]){
            return true;//achei o primo
        }
    }
    return false;//o numero n nao eh um primo
}
void Soluciona(int numero, bool visitados[]){
    if(numero == n){
        if(!ChecaPrimo(resposta[n-1]+1)){//acabou a recorrencia
            return;
        }
        printf("1");//sempre comeca no numero 1
        for(int i = 1; i < n; i++){
            printf(" %d", resposta[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 2; i <= n; i++){
        if(visitados[i]){//continuo procurando pelos prox numeros, pois ja encontrei esse
            continue;
        }
        if(ChecaPrimo(i+resposta[numero-1])){
            visitados[i] = 1;
            resposta[numero] = i;
            Soluciona(numero+1, visitados);
            visitados[i] = 0;
        }
    }
}
int main(){
    int Caso = 0;
    bool visitados[20] = {0};//esse vetor eh responsavel por guardar os numeros que eu ja visitei.
    //fazendo uma marcacao
    while(scanf("%d", &n) != EOF){
        if(Caso++){
            putchar('\n');
        }
        printf("Case %d:\n", Caso);
        preprocessa(visitados);
        Soluciona(1, visitados);
    }
    return 0;
}
