//Quando um Grafo eh uma Arvore?

// 1) Quando, para quaisquer dois vertices escolhidos nesse grafo, existe
// um caminho entre eles. Ou seja, o grafo possui APENAS 1 componente conexa
// 2) Quando o grafo nao possui ciclos. 

// Ou seja, da pra checar se um grafo fornecido eh uma arvore verificando:
// - Se o numero de componentes conexas eh 1 
// - Se o numero de arestas eh (numVertices - 1)
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[source] = true;
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int u = adjlist[source][i];
        if(visited[u] == false){
            dfs(u, adjlist, visited);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numVertex, numEdges;
    cin >> numVertex >> numEdges;

    vector<vector<int>> adjlist(numVertex + 1, vector<int>());
    vector<bool> visited(numVertex + 1, false);

    int a, b;
    for(int i = 1; i <= numEdges; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int numComponents = 0;
    for(int i = 1; i <= numVertex; i++){
        if(visited[i] == false){
            dfs(i, adjlist, visited);
            numComponents++;
            if(numComponents > 1){
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    if(numEdges != numVertex - 1){
        cout << "NO" << "\n";
    }else{
        cout << "YES" << "\n";
    }

    return 0;
}
