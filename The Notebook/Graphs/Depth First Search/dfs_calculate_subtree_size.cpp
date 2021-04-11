#include <bits/stdc++.h>
#include <sstream>

/*
Tarefa: Dada uma arvore (tree), construa um array subSize[], onde
subSize[V] guarda o tamanho da subarvore enraizada no vertice V.
Admite-se que uma folha (leaf) tem subSize[leaf] = 1
*/

using namespace std;

int dfs(int root, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &subTreeSize){
    visited[root] = true;
    int currentSize = 1;
    for(int i = 0; i < (int)adjlist[root].size(); i++){
        int u = adjlist[root][i];
        if(visited[u] == false){
            currentSize += dfs(u, adjlist, visited, subTreeSize);
        }
    }
    subTreeSize[root] = currentSize;
    return currentSize;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numVertex, a, b;
    cin >> numVertex;

    vector<vector<int>> adjlist(numVertex, vector<int>());
    vector<bool> visited(numVertex, false);
    vector<int> subTreeSize(numVertex, 0);

    for(int i = 0; i < numVertex - 1; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int root = 2;
    dfs(root, adjlist, visited, subTreeSize);

    for(int i = 0; i < numVertex; i++){
        cout << "The size of the subtree rooted on " << i << " is: " << subTreeSize[i] << "\n";
    }

    return 0;
}
