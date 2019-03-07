#include <bits/stdc++.h>

using namespace std;

int main(){
    int vivos = 1;
    int indice = 0;
    int i, pessoas;
    int vetor[1000000];
    int auxiliar[1000000];
    scanf("%d", &pessoas);
    for(i = 0; i < pessoas; i++){
        scanf("%d", &vetor[i]);
    }
    int aux2 = pessoas-1;
    for(i = 0; i < pessoas; i++){
        auxiliar[i] = vetor[aux2];
        aux2--;
    }
    indice = auxiliar[0];
    for(i = 1; i < pessoas; i++){
        if(i <= indice){
            if(auxiliar[i] + i > indice ){   
                indice = auxiliar[i] + i;
            }
        }
        if(i > indice){
            vivos++;
            if(auxiliar[i] + i > indice ){
                indice = auxiliar[i] + i;
            }
        }
    }
    printf("%d\n", vivos);

    return 0;
}
