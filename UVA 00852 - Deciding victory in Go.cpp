#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>

using namespace std;

char grid[10][10];
int visitados[10][10];
int black, white;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
int flagblack = 0;
int flagwhite = 0;
int somador;

void floodfill(int lin, int col, char mark){
    visitados[lin][col] = 1;
    if(mark == 'X'){
        black++;
    }
    if(mark == 'O'){
        white++;
    }
    int tempx, tempy;
    for(int i = 0; i < 4; i++){
        tempx = lin + dx[i];
        tempy = col + dy[i];
        if(tempx >= 0 && tempy >= 0 && tempx < 9 && tempy < 9 && visitados[tempx][tempy] == 0 && grid[tempx][tempy] == grid[lin][col]){
            floodfill(tempx, tempy, grid[tempx][tempy]);
        }
    }
}

void pantera(int lin, int col){
    somador++;
    int tempx, tempy;
    visitados[lin][col] = 2;
    if(grid[lin][col - 1] == 'X'){
        flagblack = 1;
    }
    if(grid[lin][col + 1] == 'X'){
        flagblack = 1;
    }
    if(grid[lin - 1][col] == 'X'){
        flagblack = 1;
    }
    if(grid[lin + 1][col] == 'X'){
        flagblack = 1;
    }
    //
    //
    if(grid[lin][col - 1] == 'O'){
        flagwhite = 1;
    }
    if(grid[lin][col + 1] == 'O'){
        flagwhite = 1;
    }
    if(grid[lin - 1][col] == 'O'){
        flagwhite = 1;
    }
    if(grid[lin + 1][col] == 'O'){
        flagwhite = 1;
    }
    for(int i = 0; i < 4; i++){
        tempx = lin + dx[i];
        tempy = col + dy[i];
        if(tempx >= 0 && tempy >= 0 && tempx < 9 && tempy < 9 && visitados[tempx][tempy] == 0 && grid[tempx][tempy] == '.'){
            pantera(tempx, tempy);
        }
    }
    
}

int main(){
    char aux[15];
    int numcasos;
    int qtdlinhas;
    int sentinela;
    scanf("%d", &numcasos);
    for(int a = 0; a < numcasos; a++){
        black = 0;
        white = 0;
        memset(visitados, 0, sizeof visitados);
        sentinela = 0;
        for(int b = 0; b < 9; b++){
            scanf(" %s", aux);
            strcpy(grid[sentinela], aux);
            sentinela++;
        }
        //Primeiro passo: Contar a quantidade de pedras pretas e pedras brancas;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if((grid[i][j] == 'X' || grid[i][j] == 'O') && visitados[i][j] == 0){
                    floodfill(i, j, grid[i][j]);
                }
            }
        }
        //Segundo passo: Contar as regioes cercadas
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if((grid[i][j] == '.') && visitados[i][j] == 0){
                    somador = 0;
                    flagblack = 0;
                    flagwhite = 0;
                    pantera(i, j);
                    if(flagwhite == 1 && flagblack == 0){
                        white += somador;
                    }
                    if(flagwhite == 0 && flagblack == 1){
                        black += somador;
                    }
                }
            }
        }
        
        printf("Black %d White %d\n", black, white);
    }
    return 0;
}
