#include <bits/stdc++.h>
#include <cmath>
#define INF 0xffffff

using namespace std;

int adjmatrix[110][110];

void preprocess(){
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            adjmatrix[i][j] = INF;
        }
    }
}

int main(){
    int a, b, weight;
    int deonde, paraonde;
    int numvertices, numedges, numqueries;
    int cases = 0;
    int ok = 0;
    while(true){
        scanf("%d %d %d", &numvertices, &numedges, &numqueries);
        if(numvertices == 0 && numedges == 0 && numqueries == 0){
            break;
        }
        preprocess();
        for(int i = 0; i < numedges; i++){
            scanf("%d %d %d", &a, &b, &weight);
            adjmatrix[a][b] = min(adjmatrix[a][b], weight);
            adjmatrix[b][a] = adjmatrix[a][b];
        }
        //roda o floyd-warshall modificado agr...
        for(int k = 1; k <= numvertices; k++){
            for(int i = 1; i <= numvertices; i++){
                for(int j = 1; j <= numvertices; j++){
                    adjmatrix[i][j] = min(adjmatrix[i][j], max(adjmatrix[i][k], adjmatrix[k][j]));
                }
            }
        }
        if(cases){
            puts("");
        }
        printf("Case #%d\n", ++cases);
        for(int i = 1; i <= numqueries; i++){
            scanf("%d %d", &deonde, &paraonde);
            if(adjmatrix[deonde][paraonde] != INF){
                printf("%d\n", adjmatrix[deonde][paraonde]);
            }else{
                puts("no path");
            }
        }
        ok++;
    }
    return 0;
}
