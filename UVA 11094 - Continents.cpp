#include <bits/stdc++.h>

using namespace std;

char grid[70][70];
int visitados[70][70];
int numlinhas, numcolunas;
int px, py;
int resposta;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0,-1, 1};
int answer;
char land;

void floodfill(int lin, int col){
    if(col < 0){
        col = numcolunas - 1;
    }
    if(col >= numcolunas){
        col = 0;
    }
    if(lin < 0 || lin >= numlinhas){
        return;
    }
    visitados[lin][col] = 1;
    resposta++;
    int tempx, tempy;
    for(int i = 0; i < 4; i++){
        tempx = lin + dx[i];
        tempy = col + dy[i];
        if(tempy < 0){
            tempy = numcolunas - 1;
        }
        if(tempy >= numcolunas){
            tempy = 0;
        }
        if((visitados[tempx][tempy] == 0) && (grid[tempx][tempy] == grid[lin][col])){
            floodfill(tempx, tempy);
        }
    }
}

void floods(int lin, int col){
    visitados[lin][col] = 2;
    int tempx, tempy;
    if(col < 0){
        col = numcolunas - 1;
    }
    if(col >= numcolunas){
        col = 0;
    }
    if(lin < 0 || lin >= numlinhas){
        return;
    }
    for(int i = 0; i < 4; i++){
        tempx = lin + dx[i];
        tempy = col + dy[i];
        if(tempy < 0){
            tempy = numcolunas - 1;
        }
        if(tempy >= numcolunas){
            tempy = 0;
        }
        if((visitados[tempx][tempy] == 0) && (grid[tempx][tempy] == land)){
            floods(tempx, tempy);
        }
    }
}



int main(){
    while(scanf("%d %d", &numlinhas, &numcolunas) == 2){
        memset(visitados, 0, sizeof visitados);
        answer = 0;
        for(int i = 0 ; i < numlinhas; i++){
            for(int j = 0; j < numcolunas; j++){
                scanf(" %c", &grid[i][j]);
            }
        }
        scanf("%d %d", &px, &py);
        land = grid[px][py];
        floods(px, py);
        for(int i = 0 ; i < numlinhas; i++){
            for(int j = 0; j < numcolunas; j++){
                if(grid[i][j] == land && visitados[i][j] == 0){
                    resposta = 0;
                    floodfill(i,j);
                    if(resposta > answer){
                        answer = resposta;
                    }
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
