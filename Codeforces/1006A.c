#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	int numero, tamanho;
	scanf("%d", &tamanho);
	while(scanf("%d", &numero) != EOF){
		if(numero%2 == 0){
			numero--;
			printf("%d ", numero);
		}
		else if(numero%2 != 0){
			printf("%d ", numero);
		}
	}
	return 0;
}
