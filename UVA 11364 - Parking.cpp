#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos, i, j, tamanho;
    int vetor[25];
    int menor, maior;
    int answer;
    scanf("%d", &numcasos);
    for(i = 0; i < numcasos; i++){
        scanf("%d", &tamanho);
        for(j = 0; j < tamanho; j++){
            scanf("%d", &vetor[j]);
        }
        menor = 99999999;
        maior = -69;
        for(j = 0; j < tamanho; j++){
            if(vetor[j] < menor){
                menor = vetor[j];
            }
            if(vetor[j] > maior){
                maior = vetor[j];
            }
        }
        answer = 2*(maior - menor);
        printf("%d\n", answer);
    }
    return 0;
}