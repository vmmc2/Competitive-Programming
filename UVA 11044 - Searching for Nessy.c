#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int numcasos;
    int comprimento, altura;
    scanf("%d", &numcasos);
    while(numcasos--){
        scanf("%d %d", &comprimento, &altura);
        printf("%d\n", (comprimento/3)*(altura/3));
    }
    return 0;
}