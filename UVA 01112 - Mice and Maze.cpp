#include <bits/stdc++.h>
#include <cmath>
#define INF 0xffffff

using namespace std;

int adjmatrix[110][110];
int numvertices;

void preprocess(){
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            adjmatrix[i][j] = INF;
            if(i == j){
                adjmatrix[i][j] = 0;
            }
        }
    }
}

void floyd_warshall(){
    for(int k = 1; k <= numvertices; k++){
        for(int i = 1; i <= numvertices; i++){
            for(int j = 1; j <= numvertices; j++){
                adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][k] + adjmatrix[k][j]);
            }
        }
    }
}

int main(){
    int numcasos;
    int numedges, tle;
    int numexit;
    int a, b, weight;
    int rats;
    scanf("%d", &numcasos);
    while(numcasos--){
        preprocess();
        rats = 0;
        scanf("%d", &numvertices);
        scanf("%d", &numexit);
        scanf("%d", &tle);
        scanf("%d", &numedges);
        for(int i = 1 ; i <= numedges; i++){
            scanf("%d %d %d", &a, &b, &weight);
            adjmatrix[a][b] = weight;
        }
        floyd_warshall();
        for(int i = 1; i <= numvertices; i++){
            if(adjmatrix[i][numexit] <= tle || i == numexit){
                rats++;
            }
        }
        printf("%d\n", rats);
        if(numcasos){
            printf("\n");
        }
    }
    return 0;
}
