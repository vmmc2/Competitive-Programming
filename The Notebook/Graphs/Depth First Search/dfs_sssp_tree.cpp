#include <bits/stdc++.h>
#include <sstream>

//Se recebemos uma arvore (grafo sem ciclos) e queremos saber a distancia
//de um vertice em especifico para todos os outros, podemos simplesmente
//rodar uma dfs partindo desse vertice especifico. Isso da certo, pois, em
//uma arvore, dados dois vertices quaisquer, existe apenas um caminho entre
//eles.

void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &dist){
    visited[source] = true;
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int u = adjlist[source][i];
        if(visited[u] == false){
            dist[u] = 1 + dist[source];
            dfs(u, adjlist, visited, dist);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numVertex;
    int a, b;
    cin >> numVertex;

    vector<vector<int>> adjlist(numVertex, vector<int>());
    vector<bool> visited(numVertex, false);
    vector<int> dist(numVertex, 0);

    for(int i = 1; i <= numVertex - 1; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(1, adjlist, visited, dist);


    return 0;
}
