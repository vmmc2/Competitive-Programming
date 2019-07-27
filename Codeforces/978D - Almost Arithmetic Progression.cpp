#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int numelements;
    vector<int> sequencia;
    sequencia.pb(0);
    int aux;
    
    scanf("%d", &numelements);
    for(int i = 1; i <= numelements; i++){
        scanf("%d", &aux);
        sequencia.pb(aux);
    }
    if(numelements <= 2){
        printf("0\n");
        return 0;
    }
    int cont = 0;
    int answer = 10000000;
    int razao;
    int termo;
    int impossible = 1;
    int k;
    int primeirotermo;
    int kthtermo;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            cont = abs(i) + abs(j);
            razao = (sequencia[2] + j) - (sequencia[1] + i);
            primeirotermo = sequencia[1] + i;
            //printf("i: %d --- j: %d --- razao: %d\n", i, j, razao);
            for(k = 3; k <= numelements; k++){
                kthtermo = primeirotermo + ((k - 1) * razao);
                if(kthtermo - sequencia[k] == 0){
                    //faz nada;
                }
                else if(abs(kthtermo - sequencia[k]) > 1){
                    //impossible
                    break;
                }
                else{
                    cont++;
                }
            }
            if(k == numelements + 1){
                impossible = 0;
                answer = min(answer, cont);
            }
        }
    }
    if(impossible == 1){
        printf("-1\n");
    }
    else{
        printf("%d\n", answer);
    }
    
    return 0;
}
