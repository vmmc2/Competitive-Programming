#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	int vetor[1000];
	int contests, i;
	int davez;
	int best = 1, worst = 1;
	int amazing = 0;
	scanf("%d", &contests);
	for(i = 0; i < contests; i++){
		scanf("%d", &vetor[i]);
	}
	for(davez = 1; davez < contests; davez++){
		best = 1; // assumo que ja encontrei a melhor
		worst = 1;//assumo que ja encontrei a pior
		for(i = 0; i < davez; i++){
			if(vetor[davez] <= vetor[i]){
				best = 0;
			}
			if(vetor[davez] >= vetor[i]){
				worst = 0;
			}
		}
		if(best != 0 || worst != 0){
			amazing++;
		}
	}
	printf("%d\n", amazing);
	return 0;
}
