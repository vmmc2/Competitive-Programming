    #include <bits/stdc++.h>
    #include <sstream>
    #define pb push_back
    #define mp make_pair
    #define vi vector<int>
    #define pii pair<int,int>
     
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
     
    const ll INF = 100000000;
    const int MOD = 1e9 + 7;
     
    ll numVertices = 0;
    ll numEdges = 0;
     
    void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited){
        visited[source] = true;
        numVertices++;
     
        numEdges += (int)adjlist[source].size();
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
     
        int a, b;
        int vertices, edges;
        cin >> vertices >> edges;
     
        vector<vector<int>> adjlist(vertices + 1, vector<int>());
        vector<bool> visited(vertices + 1, false);
     
        for(int x = 1; x <= edges; x++){
            cin >> a >> b;
            adjlist[a].pb(b);
            adjlist[b].pb(a);
        }
     
        for(int i = 1; i <= vertices; i++){
            if(visited[i] == false){
                numVertices = 0;
                numEdges = 0;
                dfs(i, adjlist, visited);
                if(numEdges != numVertices * (numVertices - 1)){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
     
        cout << "YES" << endl;
     
        return 0;
    }
