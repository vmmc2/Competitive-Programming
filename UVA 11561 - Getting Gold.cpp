#include <bits/stdc++.h>

using namespace std;

int gold;
int colunas, linhas;
int x, y;
char grid[60][60];
int visitados[60][60];
int dx[4] = {0 ,-1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

void floodfill(int lin, int col){
    int newx, newy;
    visitados[lin][col] = 1;
    if(grid[lin][col] == 'G'){
        gold++;
    }
    //tem que checar agr pra ver se tem uma armadilha por perto
    //se tiver uma armadilha em uma das celulas adjacentes e um caminho possivel
    //eu devo retroceder para a celula anterior.
    for(int i = 0; i < 4; i++){
        newx = lin + dx[i];
        newy = col + dy[i];
        if(grid[newx][newy] == 'T'){
            for(int j = 0; j < 4; j++){
                newx = lin + dx[j];
                newy = col + dy[j];
                if(!visitados[newx][newy] && grid[newx][newy] != 'T'){
                    return;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++){
        newx = lin + dx[i];
        newy = col + dy[i];
        if(!visitados[newx][newy] && (grid[newx][newy] == '.' || grid[newx][newy] == 'G')){
            floodfill(newx, newy);
        }
    }
}

int main(){
    while(scanf("%d %d", &colunas, &linhas) == 2){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == 'P'){
                    x = i;
                    y = j;
                }
            }
        }
        gold = 0;
        floodfill(x, y);
        printf("%d\n", gold);
        memset(visitados, 0, sizeof visitados);
        memset(grid, '.', sizeof grid);
    }
    
    return 0;
}
