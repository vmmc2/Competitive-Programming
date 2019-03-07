#include <bits/stdc++.h>

using namespace std;

bool answerb;
int ordem;
int dx[6] = {-1,-1,0,0,1,1};
int dy[6] = {-1,0,-1,1,1,0};
int visitados[220][220];
char grid[220][220];

void floodfill(int linha, int coluna){
    int temp1;
    int temp2;
    visitados[linha][coluna] = 1;
    if(linha == ordem-1){
        answerb = true;
    }
    for(int i = 0; i < 6; i++){
        temp1 = linha + dx[i];
        temp2 = coluna + dy[i];
        if(grid[temp1][temp2] == 'b' && (temp1 >= 0 && temp1 < ordem) && (temp2 >= 0 && temp2 < ordem) && visitados[temp1][temp2] == 0){
            visitados[temp1][temp2] = 1;
            floodfill(temp1, temp2);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int caso = 1;
    while(true){
        cin >> ordem;
        if(ordem == 0){
            break;
        }
        answerb = false;
        memset(visitados, 0, sizeof visitados);
        for(int i = 0; i < ordem; i++){
            for(int j = 0; j < ordem; j++){
                cin >> grid[i][j];
            }
        }
        for(int i = 0; i < ordem; i++){
            if(grid[0][i] == 'b'){
                floodfill(0, i);
            }
        }
        if(answerb == true){
            cout << caso << " " << "B" << endl;
        }else{
            cout << caso << " " << "W" << endl;
        }
        caso++;
    }
    return 0;
}
