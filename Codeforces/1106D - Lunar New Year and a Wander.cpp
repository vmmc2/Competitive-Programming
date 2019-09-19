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
 
void travel(int x){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(x);
    visitados[x] = 1;
    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        path.pb(v);
        for(int i = 0; i < (int)adjlist[v].size(); i++){
            int u = adjlist[v][i];
            if(visitados[u] == 0){
                visitados[u] = 1;
                pq.push(u);
            }
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
    travel(1);
    for(int i = 0; i < (int)path.size(); i++){
        cout << path[i] << " ";
    }
    cout << "\n";
    return 0;
}
