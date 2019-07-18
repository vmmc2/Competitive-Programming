#include <bits/stdc++.h>
#include <cmath>
#define INF 1000000

using namespace std;

int adjmat[110][110];

int main(){
    int numcasos;
    int numvertices, numedges;
    int x, y;
    int source, destiny;
    int limite = 0;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        limite = 0;
        scanf("%d", &numvertices);
        scanf("%d", &numedges);
        for(int i = 0; i < numvertices; i++){
            for(int j = 0; j < numvertices; j++){
                adjmat[i][j] = INF;
                if(i == j){
                    adjmat[i][j] = 0;
                }
            }
        }
        for(int b = 1; b <= numedges; b++){
            scanf("%d %d", &x, &y);
            adjmat[x][y] = 1;
            adjmat[y][x] = 1;
        }
        scanf("%d %d", &source, &destiny);
        for(int k = 0; k < numvertices; k++){
            for(int i = 0; i < numvertices; i++){
                for(int j = 0; j < numvertices; j++){
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
                }
            }
        }
        for(int i = 0; i < numvertices; i++){
            limite = max(limite, adjmat[source][i] + adjmat[i][destiny]);
        }
        printf("Case %d: %d\n", a, limite);
    }
    return 0;
}
