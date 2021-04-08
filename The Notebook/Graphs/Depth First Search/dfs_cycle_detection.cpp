#include <bits/stdc++.h>
#include <sstream>

using namespace std;

bool dfsCheckCycle(int source, int parent, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[source] = true;
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int u = adjlist[source][i];
        if(visited[u] == true){ //Checo se o no da minha lista de adjacencia atual foi visitado
            if(u != parent) return true; //Se tiver sido visitado ja e ele nao coincidir com o meu no-pai, quer dizer que tem um ciclo.
        }else if(visited[u] == false){
            if(dfsCheckCycle(u, source, adjlist, visited) == true) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int numVertex = 18;
    int numEdges = 12;
    vector<vector<int>> adjlist(numVertex, vector<int>());
    vector<bool> visited(numVertex, false);

    for(int i = 0; i < numEdges; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    bool hasCycle = dfsCheckCycle(0, -1, adjlist, visited);
    if(hasCycle){
        cout << "The graph has a cycle!" << endl;
    }else{
        cout << "The graph does not have a cycle!" << endl;
    }

    return 0;
}
