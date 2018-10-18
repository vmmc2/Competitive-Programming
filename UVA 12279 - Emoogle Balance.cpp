#include <bits/stdc++.h>

using namespace std;

int main(){
    int j = 1;
    int i, tam, lixo, ouro;
    int vetor[1010];
    int answer;
    scanf("%d", &tam);
    while(tam != 0){
        lixo = 0;
        ouro = 0;
        for(i = 0; i < tam; i++){
            scanf("%d", &vetor[i]);
            if(vetor[i] == 0){
                lixo++;
            }
            else{
                ouro++;
            }
        }
        answer = ouro - lixo;
        printf("Case %d: %d\n", j, answer);
        scanf("%d", &tam);
        j++;
    }
    return 0;
}
