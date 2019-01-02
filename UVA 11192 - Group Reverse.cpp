#include <bits/stdc++.h>
#include <string.h>
#include <math.h>

using namespace std;


int main(){
    int numgroups;
    char frase[110];
    int inicio;
    int fim;
    int tamanho;
    int tamfrase;
    int meio;
    int tamaux;
    char aux;
    int flag;
    while(1){
        scanf("%d", &numgroups);
        if(numgroups == 0) break;
        scanf(" %[^\n]", frase);
        tamfrase = strlen(frase);
        tamanho = floor(tamfrase/numgroups);
        inicio = 0;
        fim = tamanho-1;
        flag = 0;
        while(true){
            if(inicio >= tamfrase){
                printf("%s\n", frase);
                break;
            }
            meio = floor((inicio+fim)/2);
            int current = inicio;
            tamaux = fim;
            while(true){
                //printf("tamaux: %d\n", tamaux);
                //printf("%s\n", frase);
                if(current > meio) break;
                aux = frase[current];
                frase[current] = frase[tamaux];
                frase[tamaux] = aux;
                tamaux--;
                current++;
            }
            inicio = fim + 1;
            fim = fim + tamanho;
        }
    }
    return 0;
}
