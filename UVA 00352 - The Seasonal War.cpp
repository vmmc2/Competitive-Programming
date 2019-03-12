#include <bits/stdc++.h>

using namespace std;

char grid[50][50];
int visitados[50][50];
int ordem;
int dx[8] = {0 ,-1, 1, 0, -1, -1, 1, 1};
int dy[8] = {-1, 0, 0, 1, -1,  1, 1, -1};

void floodfill(int lin, int col){
    visitados[lin][col] = 1;
    int newx, newy;
    for(int i = 0; i < 8; i++){
        newx = lin + dx[i];
        newy = col + dy[i];
        if((grid[newx][newy] == '1') && (visitados[newx][newy] == 0) && (newx >= 0) && (newx < ordem) && (newy >= 0) && (newy < ordem)){
            floodfill(newx, newy);
        }
    }
}

int main(){
    int answer;
    int caso = 1;
    while(scanf("%d", &ordem) == 1){
        answer = 0;
        memset(visitados, 0, sizeof visitados);
        for(int i = 0; i < ordem; i++){
            for(int j = 0; j < ordem; j++){
                scanf(" %c", &grid[i][j]);
            }
        }
        for(int i = 0; i < ordem; i++){
            for(int j = 0; j < ordem; j++){
                if(visitados[i][j] == 0 && grid[i][j] == '1'){
                    answer++;
                    floodfill(i, j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", caso, answer);
        caso++;
    }
    return 0;
}
