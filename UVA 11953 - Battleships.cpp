#include <bits/stdc++.h>

using namespace std;

int ordem;
char grid[120][120];
int visitados[120][120];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int answer;

void floods(int lin, int col){
    int tempx, tempy;
    visitados[lin][col] = 1;
    for(int i = 0; i < 4; i++){
        tempx = lin + dx[i];
        tempy = col + dy[i];
        if((tempx >= 0) && (tempx < ordem) && (tempy >= 0) && (tempy < ordem) && (grid[tempx][tempy] == 'x' || grid[tempx][tempy] == '@') && visitados[tempx][tempy] == 0){
            floods(tempx, tempy);
        }
    }
}

int main(){
    int numcasos;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        answer = 0;
        memset(visitados, 0, sizeof visitados);
        scanf("%d", &ordem);
        for(int i = 0; i < ordem; i++){
            for(int j = 0; j < ordem; j++){
                scanf(" %c", &grid[i][j]);
            }
        }
        //iniciando o algoritmo de floodfill
        for(int i = 0; i < ordem; i++){
            for(int j = 0; j < ordem; j++){
                if(grid[i][j] == 'x' && visitados[i][j] == 0){
                    answer++;
                    floods(i, j);
                }
            }
        }
        printf("Case %d: %d\n", a, answer);
    }
    return 0;
}
