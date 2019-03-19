#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

char grid[110][110];
int visitados[110][110];
int xp, yp;
int numlinhas, numcolunas;
int contador;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0,-1, 1};

void floodfill(int lin, int col){
    contador++;
    visitados[lin][col] = 1;
    int tempx, tempy;
    for(int i = 0; i < 4; i++){
        tempx = lin + dx[i];
        tempy = col + dy[i];
        if(tempx >= 0 && tempy >= 0 && tempx < numlinhas && tempy < numcolunas && visitados[tempx][tempy] == 0 && grid[tempx][tempy] == grid[lin][col]){
            floodfill(tempx, tempy);
        }
    }
}


int main(){
    char input[110];
    int numcasos;
    scanf("%d", &numcasos);
    while(numcasos--){
        contador = 0;
        numlinhas = 0;
        memset(visitados, 0, sizeof visitados);
        scanf("%d %d\n", &xp, &yp);
        xp--;
        yp--;
        while(gets(input) && strlen(input) > 0){
            numcolunas = strlen(input);
            strcpy(grid[numlinhas], input);
            numlinhas++;
        }
        floodfill(xp, yp);
        printf("%d\n", contador);
        if(numcasos){
            printf("\n");
        }
    }
    return 0;
}
