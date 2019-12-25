#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adjlist[100010];
int visitados[100010] = {0};
vector<pair<int,int>> cost;

void dfs(int source){
    visitados[source] = 1;
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int x = adjlist[source][i];
        if(visitados[x] == 0){
            dfs(x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numvertex, numedges;
    int a, b, x;
    cin >> numvertex >> numedges;
    for(int i = 1; i <= numvertex; i++){
        cin >> x;
        cost.pb(mp(x,i));
        //cost.first -> custo daquele vertice...
        //cost.second -> indice/id daquele vertice...
    }
    for(int i = 0; i < numedges; i++){
        cin >> a >> b;
        adjlist[a].pb(b);
        adjlist[b].pb(a);
    }
    ll answer = 0;
    sort(cost.begin(), cost.end());
    for(int i = 0; i < (int)cost.size(); i++){
        if(visitados[cost[i].second] == 0){
            answer += cost[i].first;
            dfs(cost[i].second);
        }
        
    }
    cout << answer << "\n";
    
    return 0;
}
