#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int a;
int auxiliar;
int xp, yp;
int colunas, linhas;
int x, y;
char grid[300][300];
int visitados[300][300];
int dx[8] = {0 ,-1, 1, 0, -1, -1, 1, 1};
int dy[8] = {-1, 0, 0, 1, -1,  1, 1, -1};

void floodfill(int lin, int col){
    int newx, newy;
    visitados[lin][col] = 1;
    for(int i = 0; i < 8; i++){
        newx = lin + dx[i];
        newy = col + dy[i];
        if((grid[newx][newy] == ' ') && (newx >= 0) && (newy >= 0) && (visitados[newx][newy] == 0)){
            grid[newx][newy] = '#';
            //printmatriz();
            floodfill(newx, newy);
        }
    }
}

int main(){
    int numcasos;
    char aux[300];
    char lixeira[300];
    scanf("%d", &numcasos);
    for(a = 0; a < numcasos; a++){
        memset(grid, 'V', sizeof grid);
        memset(visitados, 0, sizeof visitados);
        auxiliar = 0;
        while(true){
            scanf(" %[^\n]", aux);
            if(aux[0] == '_'){
                strcpy(lixeira, aux);
                break;
            }
            for(int j = 0; j < (int)strlen(aux); j++){
                grid[auxiliar][j] = aux[j];
                if(grid[auxiliar][j] == '*'){
                    grid[auxiliar][j] = '#';
                    xp = auxiliar;
                    yp = j;
                }
            }
            auxiliar++;
        }
        floodfill(xp, yp);
        cin.ignore();
        for(int i = 0; i < auxiliar; i++){
            for(int j = 0; grid[i][j] != 'V'; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
        printf("%s\n", lixeira);
    }
    return 0;
}
