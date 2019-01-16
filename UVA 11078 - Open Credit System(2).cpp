#include <bits/stdc++.h>
#include <sstream>

//SOLUTION: O(n)

using namespace std;

int main(){
    int numcasos;
    int vetor[200000];
    int qtd;
    int maior;
    int max_diff;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        maior = - 9999999;
        max_diff = -9999999;
        scanf("%d", &qtd);
        for(int j = 0; j < qtd; j++){
            scanf("%d", &vetor[j]);
        }
        for(int j = 0; j < qtd - 1; j++){
            if(vetor[j] > maior){
                maior = vetor[j];
            }
            if(maior - vetor[j+1] > max_diff){
                max_diff = maior - vetor[j+1];
            }
        }
        printf("%d\n", max_diff);
    }    
    return 0;
}
