#include <bits/stdc++.h>

using namespace std;

int linhas, colunas;
char grid[120][120];
int visitados[120][120];
int dx[8] = {-1,-1, 0,0,1,1,-1, 1};
int dy[8] = {-1, 0,-1,1,1,0, 1,-1};

void floodfill(int linha, int coluna){
    int temp1;
    int temp2;
    visitados[linha][coluna] = 1;
    for(int i = 0; i < 8; i++){
        temp1 = linha + dx[i];
        temp2 = coluna + dy[i];
        if((grid[temp1][temp2] == '@') && (temp1 >= 0 && temp1 < linhas) && (temp2 >= 0 && temp2 < colunas) && visitados[temp1][temp2] == 0){
            floodfill(temp1, temp2);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int components;
    while(true){
        cin >> linhas >> colunas;
        if(linhas == 0){
            break; //fim dos casos
        }
        components = 0;
        memset(visitados, 0, sizeof visitados);
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                cin >> grid[i][j];
            }
        }
        //vou ter que chamar o floodfill para cada uma das celulas do tipo '@' que representam
        //um deposito de petroleo
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                if(grid[i][j] == '@' && visitados[i][j] == 0){
                    components++;
                    floodfill(i, j);
                }
            }
        }
        cout << components << endl;
    }
    return 0;
}
