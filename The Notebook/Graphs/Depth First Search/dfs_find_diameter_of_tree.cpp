#include <bits/stdc++.h>
#include <sstream>

/*
Objetivo: Encontrar o diametro de uma arvore (tree)

* O que eh o diametro de uma arvore? Eh a maior distancia entre dois
vertices quaisquer presentes nessa arvore (tree).

1) Solucao Naive
-- Para cada vertice da arvore, roda uma dfs a partir dele e guardar o vertice
mais distante da origem e qual eh essa distancia.
-- Vai atualizando o valor dessa variavel a medida que for necessario.
-- Complexidade: O(V*(V + E))

2) Solucao Otima
-- Escolhe um vertice qualquer da arvore e roda uma dfs a partir dele.
-- Pega o vertice que ta mais longe desse primeiro vertice e guarda ele.
-- Roda uma segunda dfs a partir desse segundo vertice. O vertice que estiver
mais longe dessa segunda origem e sua respectiva distancia eh o diametro da arvore.
-- Complexidade: O(V + E)
*/

using namespace std;

void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &dist){
    visited[source] = true;
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int u = adjlist[source][i];
        if(visited[u] == false){
            dist[u] = dist[source] + 1;
            dfs(u, adjlist, visited, dist);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> adjlist(vertex, vector<int>());
    vector<bool> visited(vertex, false);
    vector<int> dist(vertex, 0);

    for(int x = 0; x < edges; x++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int firstRoot = 0;
    int secondRoot, maxDist = -1;
    dfs(firstRoot, adjlist, visited, dist);
    for(int i = 0; i < vertex; i++){
        if(dist[i] > maxDist){
            maxDist = dist[i];
            secondRoot = i;
        }
    }
    visited.assign(vertex, false);
    dist.assign(vertex, 0);
    dfs(secondRoot, adjlist, visited, dist);
    int diameter = -1;
    for(int i = 0; i < vertex; i++){
        diameter = max(diameter, dist[i]);
    }

    cout << "The diameter of the tree is: " << diameter << endl;

    return 0;
}
