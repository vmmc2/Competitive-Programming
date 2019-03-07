#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int numcasos;
    char string[256];
    int i, j, y, tamanho, palindromo;
    int aux1, aux2;
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        palindromo = 1; // assumo que a minha palavra eh um palindromo
        scanf("%d", &tamanho);
        scanf(" %[^\n]", string);
        for(j = 0, y = tamanho-1; j <= (tamanho/2)-1; j++, y--){
            aux1 = (int)string[j];
            aux2 = (int)string[y];
            if((aux1-1 != aux2-1) && (aux1-1 != aux2+1) && (aux1+1 != aux2-1) && (aux1+1 != aux2+1)){
                palindromo = 0;
                break;
            }
        }
        if(palindromo == 0){
            printf("NO\n");
        }
        else if(palindromo == 1){
            printf("YES\n");
        }
    }
}
