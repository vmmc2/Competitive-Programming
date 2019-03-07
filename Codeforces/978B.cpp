#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
    char string[100];
    int i, contador = 0;
    int tamstring, tam;
    scanf("%d", &tamstring);
    scanf(" %s", string);
    tam = strlen(string);
    for(i = 0; i <=tam-3; i++){
        if(string[i] == 'x'){
            if(string[i+1] == 'x' && string[i+2] == 'x'){
                contador++;
            }
        }
    }
    printf("%d\n", contador);

    return 0;
}
