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

void reset_visdist(){
    for(int i = 0; i < 100000; i++){
        visitados[i] = 0;
        dist[i] = INF;
    }
    return;
}

void bfs(int source){
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
            }
        }
    }
    return;
}

int main(){
    int numedges;
    int counter = 1;
    while(cin >>numedges){
        reset_graph();
        set<int> vertices_existentes;
        if(numedges == 0) break; //fim do programa.
        int x, y;
        for(int a = 1; a <= numedges; a++){
            cin >> x >> y;
            vertices_existentes.insert(x);
            vertices_existentes.insert(y);
            adjlist[x].pb(y);
            adjlist[y].pb(x);
        }
        int initnode, ttl;
        while(true){
            cin >> initnode >> ttl;
            reset_visdist();
            if(initnode == 0 && ttl == 0) break;
            bfs(initnode);
            int not_reached = 0;
            for(set<int>::iterator it = vertices_existentes.begin(); it != vertices_existentes.end(); it++){
                if(dist[*it] > ttl) not_reached++;
            }
            cout << "Case " << counter << ": " << not_reached << " nodes not reachable from node " << initnode << " with TTL = " << ttl << ".\n";
            counter++;
        }
    }
    return 0;
}
