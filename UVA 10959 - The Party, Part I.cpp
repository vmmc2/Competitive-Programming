#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[100000];
int visitados[100000];
int dist[100000];

void reset_all(){
    for(int i = 0; i < 100000; i++){
        adjlist[i].clear();
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
                fila.push(x);
                dist[x] = min(dist[x], dist[u] + 1);
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
        reset_all();
        int numvertices, numedges;
        int c, d;
        cin >> numvertices >> numedges;
        for(int b = 1; b <= numedges; b++){
            cin >> c >> d;
            adjlist[c].pb(d);
            adjlist[d].pb(c);
        }
        bfs(0);
        for(int i = 1; i < numvertices; i++){
            cout << dist[i] << "\n";
        }
        if(a != numcasos){
            cout << "\n";
        }
    }
    return 0;
}
