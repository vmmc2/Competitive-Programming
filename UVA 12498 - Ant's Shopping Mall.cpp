#include <bits/stdc++.h>

using namespace std;

int main(){
    int p, q;
    int numcasos;
    char matriz[105][105];
    int linhas, colunas;
    int i, j;
    int qtduns;
    bool solucao;
    int sentinela;
    int answer = 99999999;
    int atual;
    scanf("%d", &numcasos);
    for(int k = 1; k <= numcasos; k++){
        scanf("%d %d", &linhas, &colunas);
        for(i = 0; i < linhas; i++){
            scanf(" %s", matriz[i]);
        }
        answer = 99999999;
        //comecou
        for(i = 0; i < colunas; i++){
            int sub = 0;
            for(j = 0; j < linhas; j++){
                int left = 0xfffffff, right = 0xfffffff;
                if(matriz[j][i] == '0'){
                    continue;
                }
                p = i;
                while(p >= 0 && matriz[j][p] == '1'){
                    p--;
                }
                q = i;
                while(q < colunas && matriz[j][q] == '1'){
                    q++;
                }
                if(p >= 0){
                    left = i - p;
                }
                if(q < colunas){
                    right = q - i;
                }
                if(left == 0xfffffff && right == 0xfffffff)
                    break;
                sub += min(left, right);
            }
            if(j == linhas){
                answer = min(answer,sub);
            }
        }
        if(answer == 99999999){
           answer = -1;
        }
        printf("Case %d: %d\n", k, answer);
    }
    return 0;
}
