#include <bits/stdc++.h>
#include <sstream>

using namespace std;

void bfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &dist){
    visited[source] = true;
    dist[source] = 0;
    queue<int> fila;
    fila.push(source);

    while(!fila.empty()){
        int s = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[s].size(); i++){
            int u = adjlist[s][i];
            if(visited[u] == false){
                visited[u] = true;
                dist[u] = dist[s] + 1;
                fila.push(u);
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int vertex, edges;
    int a, b;
    
    cin >> vertex >> edges;
    vector<vector<int>> adjlist(vertex, vector<int>());
    vector<bool> visited(vertex, false);
    vector<int> dist(vertex, 0);

    for(int i = 0; i < edges; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    bfs(0, adjlist, visited, dist);


    return 0;
}
