#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(){
    int numcasos;
    char matriz[200][200];
    int linhas, colunas, ocorrencias;
    int j, k;
    int x, y; //x = linha e y = coluna
    int diflinhasup, diflinhainf, difcolesq, difcoldir;
    int linhasuperior, linhainferior, colunaesquerda, colunadireita;
    int menordif;
    int limite;
    char aux;
    int contador;
    int flag;
    int answer;
    scanf("%d", &numcasos);
    while(numcasos--){
        scanf("%d %d %d", &linhas, &colunas, &ocorrencias);
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                scanf(" %c", &matriz[i][j]);
            }
        }
        printf("%d %d %d\n", linhas, colunas, ocorrencias);
        for(int i = 1; i <= ocorrencias; i++){
            answer = -3;
            scanf("%d %d", &x, &y);
            diflinhasup = fabs(x - 0);
            diflinhainf = fabs(x - (linhas - 1));
            difcolesq = fabs(y - 0);
            difcoldir = fabs(y - (colunas - 1));
            menordif = min(diflinhasup, diflinhainf);
            menordif = min(menordif, difcolesq);
            menordif = min(menordif, difcoldir);
            //printf("menordif: %d\n", menordif);
            //limite = 2*menordif; //vai ser o limite do meu quadrado
            linhasuperior = x - menordif;
            linhainferior = x + menordif;
            colunaesquerda = y - menordif;
            colunadireita = y + menordif;
            for(int a = 1; a <= menordif + 1; a++){
                answer = -3;
                flag = 0;
                contador = 0;
                aux = matriz[linhasuperior][colunaesquerda];
                for(j  = linhasuperior; j <= linhainferior; j++){
                    for(k = colunaesquerda; k <= colunadireita; k++){
                        if(aux == matriz[j][k]){
                            contador++;
                        }
                        else{
                            flag = 1;
                        }
                    }
                }
                if(flag == 0){
                    answer = contador;
                    break;
                }
                linhasuperior++;
                linhainferior--;
                colunaesquerda++;
                colunadireita--;
            }
            printf("%d\n", (int)sqrt(answer));
        }
    }
    return 0;
}
