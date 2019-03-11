#include <bits/stdc++.h>

using namespace std;

int lin, col;
char grid[200][200];
int visitados[200][200];
int dx[8] = {1,-1, 0, 0,-1,-1, 1, 1};  //linha change
int dy[8] = {0, 0, 1,-1,-1, 1,-1, 1}; //coluna change
int answer;

void floodfill(int linha, int coluna){
    int newx, newy;
    visitados[lin][col] = 1;
    for(int i = 0; i < 8; i++){
        newx = linha + dx[i];
        newy = coluna + dy[i];
        if(visitados[newx][newy] == 0 && grid[newx][newy] == '*' && newx >= 0 && newx < lin && newy >= 0 && newy < col){
            return;
        }
    }
    answer++;
    return;
}

int main(){
    while(true){
        answer = 0;
        memset(visitados, 0, sizeof visitados);
        scanf("%d %d", &lin, &col);
        if(lin == 0 && col == 0){
            break;
        }
        for(int i = 0; i < lin; i++){
            for(int j = 0; j < col; j++){
                scanf(" %c", &grid[i][j]);
            }
        }
        for(int i = 0; i < lin; i++){
            for(int j = 0; j < col; j++){
                if(visitados[i][j] == 0 && grid[i][j] == '*'){
                    floodfill(i, j);
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
