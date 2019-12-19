#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[100000];
int visitados[100000];
int dist[100000];

void reset_graph(){
    for(int i = 0; i < 100000; i++){
        adjlist[i].clear();
        visitados[i] = 0;
        dist[i] = INF;
    }
    return;
}

void bfs(int source, int dest){
    queue<int> fila;
    visitados[source] = 1;
    dist[source] = 0;
    fila.push(source);
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[u].size(); i++){
            int x = adjlist[u][i];
            if(visitados[x] == 0){
                visitados[x] = 1;
                dist[x] = min(dist[x], dist[u] + 1);
                fila.push(x);
                if(x == dest){
                    return;
                }
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        int numvertices;
        int lixeira, neigh;
        cin >> numvertices;
        reset_graph();
        for(int i = 0; i < numvertices; i++){
            cin >> lixeira >> neigh;
            int n;
            for(int b = 0; b < neigh; b++){
                cin >> n;
                adjlist[lixeira].pb(n);
            }
        }
        //pronto terminou de montar o grafo...
        int partida, chegada;
        cin >> partida >> chegada;
        bfs(partida, chegada);
        int finale = (dist[chegada] + 1) - 2;
        cout << partida << " " << chegada << " " << finale << "\n";
        if(a != numcasos){
            cout << "\n";
        }
    }
    return 0;
}
