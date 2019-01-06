#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, vetor[5];
	char auxiliar[20];
	while(scanf("%d", &n) == 1 && n) {
		string str;
		map<string, int> dicionario;
		while(n--) {
			scanf("%d %d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4]);
			sort(vetor, vetor+5);
			sprintf(auxiliar, "%d%d%d%d%d", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4]);
			str = auxiliar;
			dicionario[str]++;
            //pronto, adicionei um novo registro ao meu map
		}
		int max = 0;
    int maxNum = 0;
        //Agora eu tenho que iterar sobre o meu map e encontrar qual chave
        //apresenta a maior quantidade de registros
		for(map<string, int>::iterator i = dicionario.begin(); i != dicionario.end(); i++) {
			if(i->second > max)
				max = i->second, maxNum = 0;
			if(i->second == max)
				maxNum += max;
		}
		printf("%d\n", maxNum);
	}
    return 0;
}
