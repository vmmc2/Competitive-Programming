#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;

ll compSize = 0;
const int MOD = 1000000007;

void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[source] = true;
    compSize++;
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

    int numcases;
    cin >> numcases;
    
    while(numcases--){
        int a, b;
        int numVertex, numEdges;
        cin >> numVertex >> numEdges;

        vector<vector<int>> adjlist(numVertex + 1, vector<int>());
        vector<bool> visited(numVertex + 1, false);
        vector<ll> preProcess;
        for(int i = 0; i < numEdges; i++){
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        int nComponents = 0;
        for(int i = 1; i <= numVertex; i++){
            if(visited[i] == false){
                nComponents++;
                compSize = 0;
                dfs(i, adjlist, visited);
                preProcess.push_back(compSize);
            }
        }
        ll answer = 1;
        for(int i = 0; i < (int)preProcess.size(); i++){
            answer = (answer * preProcess[i]) % MOD;
        }
        cout << nComponents << " " << answer << "\n";
    }

    return 0;
}
