#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int graph[1005][1005];
int dx[4] = {1,-1, 0,0};
int dy[4] = {0, 0,-1,1};

void reset(){
    for(int i = 0; i < 1005; i++){
        for(int j = 0; j < 1005; j++){
            graph[i][j] = -1;
        }
    }
    return;
}

//Se n for necessario, n faca verificacao dos visitados... pode afetar bastante a complexidade.
void bfs(int startx, int starty, int endx, int endy, int rows, int cols){
    queue<pair<int,int>> fila;
    graph[startx][starty] = 0;
    fila.push(mp(startx, starty));
    while(!fila.empty()){
        pair<int,int> u = fila.front();
        fila.pop();
        for(int i = 0; i < 4; i++){
            int newx = u.first + dx[i];
            int newy = u.second + dy[i];
            if(newx >= 0 && newx < rows && newy >= 0 && newy <= cols && graph[newx][newy] == -1){
                graph[newx][newy] = graph[u.first][u.second] + 1;
                fila.push(mp(newx, newy));
                if(newx == endx && newy == endy){
                    return;
                }
            }
        }
    }
    return;
}

int main(){
    int row, col;
    while(true){
        scanf("%d %d", &row, &col);
        if(row == 0 && col == 0) break;
        reset();
        int rowsbomb;
        scanf("%d", &rowsbomb);
        int id, numbombs, y;
        for(int i = 0; i < rowsbomb; i++){
            scanf("%d", &id);
            scanf("%d", &numbombs);
            for(int j = 1; j <= numbombs; j++){
                scanf("%d", &y);
                graph[id][y] = INF;
            }
        }
        int startx, starty;
        int endx, endy;
        scanf("%d %d", &startx, &starty);
        scanf("%d %d", &endx, &endy);
        bfs(startx, starty, endx, endy, row, col);
        printf("%d\n", graph[endx][endy]);
        //pronto ja terei montado meu grafo...
    }
    return 0;
}
