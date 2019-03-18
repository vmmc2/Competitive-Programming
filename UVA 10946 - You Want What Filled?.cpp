#include <bits/stdc++.h>

using namespace std;

char grid[70][70];
int visitados[70][70];
int numlinhas, numcolunas;
vector<pair<char,int>> registro;
int resposta;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0,-1, 1};

void floodfill(int lin, int col){
    visitados[lin][col] = 1;
    resposta++;
    int tempx, tempy;
    for(int i = 0; i < 4; i++){
        tempx = lin + dx[i];
        tempy = col + dy[i];
        if((tempx >= 0) && (tempy >= 0) && (tempx < numlinhas) && (tempy < numcolunas) && (visitados[tempx][tempy] == 0) && (grid[tempx][tempy] == grid[lin][col])){
            floodfill(tempx, tempy);
        }
    }
}

bool comp(const pair<char,int> &a, const pair<char,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    int caso = 1;
    while(true){
        scanf("%d %d", &numlinhas, &numcolunas);
        if(numlinhas == 0 && numcolunas == 0){
            break;
        }
        for(int i = 0; i < numlinhas; i++){
            for(int j = 0; j < numcolunas; j++){
                scanf(" %c", &grid[i][j]);
            }
        }
        for(int i = 0; i < numlinhas; i++){
            for(int j = 0; j < numcolunas; j++){
                if(grid[i][j] != '.' && visitados[i][j] == 0){
                    resposta = 0;
                    floodfill(i, j);
                    registro.push_back({grid[i][j],resposta});
                }
            }
        }
        printf("Problem %d:\n", caso);
        sort(registro.begin(), registro.end(), comp);
        for(int a = 0; a < (int)registro.size(); a++){
            printf("%c %d\n", registro[a].first, registro[a].second);
        }
        memset(visitados, 0, sizeof visitados);
        registro.clear();
        caso++;
    }
    return 0;
}
