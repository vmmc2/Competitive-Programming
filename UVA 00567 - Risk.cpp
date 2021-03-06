#include <bits/stdc++.h>
#include <cmath>
#define INF 999999

using namespace std;

int adjmat[25][25];


int main(){
    int qtdvizinhos;
    int paraonde;
    int caso = 1;
    int numqueries;
    int a, b;
    while(scanf("%d", &qtdvizinhos) == 1){ //aqui eu to pegando a quantidade de vizinhos do primeiro vertice (vertice 1). eh o inicio de cada caso de test
        memset(adjmat, INF, sizeof adjmat);
        for(int opa = 1; opa <= 20; opa++){
            adjmat[opa][opa] = 0;
        }
        for(int i = 1; i <= qtdvizinhos; i++){
            scanf("%d", &paraonde);
            adjmat[1][paraonde] = 1;
            adjmat[paraonde][1] = 1;
        }
        //agora tem que montar a matriz para os outros 18 vizinhos (2, 3, 4,...., 18, 19)
        for(int i = 2; i <= 19; i++){
            scanf("%d", &qtdvizinhos);
            for(int j = 1; j <= qtdvizinhos; j++){
                scanf("%d", &paraonde);
                adjmat[i][paraonde] = 1;
                adjmat[paraonde][i] = 1;
            }
        }
        //massa, agora roda floyd-warshall
        for(int k = 1; k <= 20; k++){
            for(int i = 1; i <= 20; i++){
                for(int j = 1; j <= 20; j++){
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
                }
            }
        }
        scanf("%d", &numqueries);
        printf("Test Set #%d\n", caso);
        for(int i = 1; i <= numqueries; i++){
            scanf("%d %d", &a, &b);
            if(a < 10 && b < 10){
                printf(" %d to  %d: %d\n", a, b, adjmat[a][b]);
            }
            else if(a >= 10 && b < 10){
                printf("%d to  %d: %d\n", a, b, adjmat[a][b]);
            }
            else if(a < 10 && b >= 10){
                printf(" %d to %d: %d\n", a, b, adjmat[a][b]);
            }
            else if(a >= 10 && b >= 10){
                printf("%d to %d: %d\n", a, b, adjmat[a][b]);
            }
        }
        printf("\n");
        caso++;
    }
    return 0;
}
