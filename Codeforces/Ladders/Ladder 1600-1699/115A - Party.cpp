#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;

void dfs(int source, int curr_depth, vector<int> &depth, vector<vector<int>> &graph, vector<bool> &visited){
    visited[source] = true;
    depth[source] = max(curr_depth, depth[source]);
    
    for(int i = 0; i < (int)graph[source].size(); i++){
        int nxt = graph[source][i];
        dfs(nxt, curr_depth + 1, depth, graph, visited);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, superior, answer = -1;
    
    cin >> n;

    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> depth(n);

    for(int i = 0; i < n; i++){
        cin >> superior;
        superior--;
        if(superior != -2) graph[superior].push_back(i);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, 1, depth, graph, visited);
        }
    }

    for(auto x : depth) answer = max(answer, x);

    cout << answer << endl;
 
    return 0;
}
