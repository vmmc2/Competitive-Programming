#include <bits/stdc++.h>
#define MAXN 110
#define INF 99999999

using namespace std;
int adjmatrix[MAXN][MAXN];

void preprocess(){
    int i, j;
    for(i = 0; i <= MAXN; i++){
        for(j = 0; j <= MAXN; j++){
            adjmatrix[i][j] = INF;
        }
    }
}

void FloydWarshall(int n){
    int i, j, k;
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][k]+adjmatrix[k][j]);
            }
        }
    }
}

int main(){
    int numcasos, i, j;
    int a, b, w;
    int chegada;
    int limite, ratinhos;
    int n, m;//n = numero de vertices, m = numero de arestas
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        preprocess();
        cin.ignore();
        scanf("%d", &n);
        ratinhos = n;
        scanf("%d", &chegada);
        scanf("%d", &limite);
        scanf("%d", &m);
        for(j = 1; j <= m; j++){
            scanf("%d %d %d", &a, &b, &w);
            adjmatrix[a][b] = w;
        }
        FloydWarshall(n);
        for(j = 1; j <= n; j++){
            if(limite < adjmatrix[j][chegada]){
               ratinhos--;                                       
            }
        }
        printf("%d\n", ratinhos+1);
    }
    return 0;
}
