#include <bits/stdc++.h>

using namespace std;

int lin, col;
char grid[200][200];
int visitados[200][200];
map <char, int> dictionary;
set <char> registro;
vector<pair<int,char>> saida;
int dx[4] = {1,-1, 0, 0};  //linha change
int dy[4] = {0, 0, 1, -1}; //coluna change

void floodfill(int linha, int coluna){
    visitados[linha][coluna] = 1;
    int tempx, tempy;
    for(int b = 0; b < 4; b++){
        tempx = linha + dx[b];
        tempy = coluna + dy[b];
        if((visitados[tempx][tempy] == 0) && (grid[linha][coluna] == grid[tempx][tempy])){
            floodfill(tempx, tempy);
        }
    }
}

bool compara(const pair<int,char> &a, const pair<int,char> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(){
    int numcasos;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        memset(visitados, 0, sizeof visitados);
        dictionary.clear();
        registro.clear();
        saida.clear();
        scanf("%d %d", &lin, &col);
        for(int i = 0; i < lin; i++){
            for(int j = 0; j < col; j++){
                scanf(" %c", &grid[i][j]);
                if(registro.find(grid[i][j]) == registro.end()){
                    registro.insert(grid[i][j]);
                }
            }
        }
        for(int i = 0; i < lin; i++){
            for(int j = 0; j < col; j++){
                if(visitados[i][j] == 0){
                    dictionary[grid[i][j]]++;
                    floodfill(i, j);
                }
            }
        }
        for(map<char,int>:: iterator it = dictionary.begin(); it != dictionary.end(); ++it){
            saida.push_back({it->second, it->first});
        }
        printf("World #%d\n", a);
        sort(saida.begin(), saida.end(), compara);
        for(int k = 0; k < (int)saida.size(); k++){
            printf("%c: %d\n", saida[k].second, saida[k].first);
        }
    }
    return 0;
}
