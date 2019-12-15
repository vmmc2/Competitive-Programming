#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[1000000];
int visited[1000000];
int pred[1000000];

void reset_graph(){
    for(int i = 0; i < 1000000; i++){
        visited[i] = 0;
        adjlist[i].clear();
    }
}
void reset_visited(){
    for(int i = 0; i < 1000000; i++){
        visited[i] = 0;
    }
}
void reset_path(){
    for(int i = 0; i < 1000000; i++){
        pred[i] = i;
    }
}
void bfs(int source, int dest){
    queue<int> fila;
    visited[source] = 1;
    fila.push(source);
    while(!fila.empty()){
        int x = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[x].size(); i++){
            int u = adjlist[x][i];
            if(visited[u] == 0){
                visited[u] = 1;
                fila.push(u);
                pred[u] = x;
            }
            if(u == dest){
                return;
            }
        }
    }
    return;
}


int main(){
    int numvertex;
    while(cin >> numvertex){
        reset_graph();
        int x;
        for(int a = 1; a <= numvertex; a++){
            cin >> x;
            char lixo;
            int y;
            string line;
            getline(cin, line);
            stringstream ss(line);
            while(ss >> lixo >> y){
                adjlist[x].push_back(y);
            }
        }
        int numqueries;
        cin >> numqueries;
        int partida, chegada;
        printf("-----\n");
        for(int a = 1; a <= numqueries; a++){
            reset_visited();
            reset_path();
            cin >> partida >> chegada;
            bfs(partida, chegada);
            if(visited[chegada] == 0){
                printf("connection impossible\n");
            }else{
                vector<int> path;
                int b;
                for(b = chegada; b != partida; b = pred[b]){
                    path.push_back(b);
                }
                path.push_back(partida);
                reverse(path.begin(), path.end());
                for(int i = 0; i < (int)path.size(); i++){
                    if(i != (int)path.size() - 1){
                        printf("%d ", path[i]);
                    }else{
                        printf("%d", path[i]);
                    }
                }
                printf("\n");
            }
        }
        
    }
    return 0;
}
