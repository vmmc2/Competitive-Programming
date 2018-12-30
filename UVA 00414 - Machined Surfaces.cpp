#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    int vetor[15];
    int flag;
    int linhas;
    char line[50];
    int answer;
    int contador;
    int sentinel;
    scanf("%d", &linhas);
    while(linhas != 0){
        memset(vetor, 0, sizeof(vetor));
        answer = 0;
        for(int i = 0; i < linhas; i++){
            contador = 0;
            scanf(" %[^\n]", line);
            for(int j = 0; j < strlen(line); j++){
                if(line[j] != 'X'){
                    contador++;
                }
            }
            vetor[i] = contador;
        }
        sort(vetor, vetor+linhas);
        sentinel = vetor[0];
        for(int i = 1; i < linhas; i++){
            answer += (vetor[i] - sentinel);
        }
        printf("%d\n", answer);
        scanf("%d", &linhas);
    }
    return 0;
}
