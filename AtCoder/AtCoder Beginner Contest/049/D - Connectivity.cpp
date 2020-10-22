#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> adjlistroad[300005];
vector<int> adjlistrail[300005];
int answer[300005] = {1};
int visitados[3000]

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, l;
    int from, to;
    
    cin >> n >> k >> l;
    vector<pair<int,int>> edges1(k);
    vector<pair<int,int>> edges2(l);
    
    for(int i = 0; i < k; i++){
        cin >> edges1[i].first >> edges1[i].second;
    }
    sort(edges1.begin(), edges1.end());
    for(int i = 0; i < k; i++){
        adjlistroad[edges1[i].first].push_back(edges1[i].second);
        adjlistroad[edges1[i].second].push_back(edges1[i].first);
    }
    
    for(int i = 0; i < l; i++){
        cin >> edges2[i].first >> edges[i].second;
    }
    sort(edges2.begin(), edges2.end());
    for(int i = 0; i < l; i++){
        adjlistrail[edges2[i].first].push_back(edges2[i].second);
        adjlistrail[edges2[i].second].push_back(edges2[i].first);
    }
    
    for(int i = 1; i <= n; i++){
        
    }
    
    
    return 0;
}
