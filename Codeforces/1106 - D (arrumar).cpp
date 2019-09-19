#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[100100];
int visitados[100100] = {0};
vector<int> path;

void dfs(int x){
    visitados[x] = 1;
    path.pb(x);
    for(int i = 0; i < (int)adjlist[x].size(); i++){
        int u = adjlist[x][i];
        if(visitados[u] == 0){
            dfs(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    int a, b;
    cin >> n >> m;
    vector<pair<int,int>> edges;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        edges.pb({a, b});
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < m; i++){
        adjlist[edges[i].first].pb(edges[i].second);
        adjlist[edges[i].second].pb(edges[i].first);
    }
    dfs(1);
    for(int i = 0; i < (int)path.size(); i++){
        cout << path[i] << " ";
    }
    cout << "\n";
    return 0;
}
