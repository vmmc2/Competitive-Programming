#include <bits/stdc++.h>
#include <sstream>

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

    int vertex;
    int a, b;
    cin >> vertex;

    vector<vector<int>> adjlist(vertex + 1, vector<int>());
    vector<bool> visited(vertex + 1, false);
    vector<int> dist(vertex + 1, 0);

    for(int i = 0; i < vertex - 1; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int firstRoot = 1;
    dfs(firstRoot, adjlist, visited, dist);
    int secondRoot = -1, maxDist = -1, diameter = -1;
    for(int i = 1; i <= vertex; i++){
        if(dist[i] > maxDist){
            maxDist = dist[i];
            secondRoot = i;
        }
    }
    visited.assign(vertex + 1, false);
    dist.assign(vertex + 1, 0);
    dfs(secondRoot, adjlist, visited, dist);
    for(int i = 1; i <= vertex; i++){
        diameter = max(diameter, dist[i]);
    }

    cout << diameter << "\n";

    return 0;
}
