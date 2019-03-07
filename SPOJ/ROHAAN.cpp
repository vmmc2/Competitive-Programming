#include <bits/stdc++.h>
#define INF 9999999
#define MAXN 60

using namespace std;

int adjmatrix[MAXN][MAXN];

void preprocess(){
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            adjmatrix[i][j] = INF;
        }
    }
}

void FloydWarshall(int tam){
    int i, j, k;
    for(k = 0; k < tam; k++){
        for(i = 0; i < tam; i++){
            for(j = 0; j < tam; j++){
                adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][k]+adjmatrix[k][j]);
            }
        }
    }
}

int main(){
    int numcasos, armystations, i;
    int orders;
    int partida, chegada;
    int j, k;
    int distotal;
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        distotal = 0;
        preprocess();
        scanf("%d", &armystations);
        for(j = 0; j < armystations; j++){
            for(k = 0; k < armystations; k++){
                scanf("%d", &adjmatrix[j][k]);
            }
        }
        scanf("%d", &orders);
        FloydWarshall(armystations);
        for(int l = 1; l <= orders; l++){
            scanf("%d %d", &partida, &chegada);
            distotal += adjmatrix[partida-1][chegada-1];
        }
        printf("Case #%d: %d\n", i, distotal);
    } 
    return 0;
}
