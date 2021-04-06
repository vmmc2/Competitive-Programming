#include <bits/stdc++.h>
#include <sstream>

using namespace std;

bool dfsCheckBipartite(int source, int color, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &colors){
    visited[source] = 1;
    colors[source] = color;
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int u = adjlist[source][i];
        if(visited[u] == false){
            if(dfsCheckBipartite(u, color ^ 1, adjlist, visited, colors) == false) return false;
        }else{
            if(colors[source] == colors[u]) return false;
        }
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int scenarios;
    cin >> scenarios;

    for(int x = 0; x < scenarios; x++){
        int vertex, edges;
        int a, b;
        cin >> vertex >> edges;
        vector<vector<int>> adjlist(vertex + 1, vector<int>());
        vector<bool> visited(vertex + 1, false);
        vector<int> colors(vertex + 1, -1);

        for(int y = 0; y < edges; y++){
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        cout << "Scenario #" << (x + 1) << ":\n";
        bool everythingOk = true;
        for(int i = 1; i <= vertex; i++){
            if(visited[i] == false){
                if(dfsCheckBipartite(i, 0, adjlist, visited, colors) == false){
                    everythingOk = false;
                    break;
                }
            }
        }
        if(everythingOk == true){
            cout << "No suspicious bugs found!" << "\n";
        }else{
            cout << "Suspicious bugs found!" << "\n";
        }
    }
    return 0;
}
