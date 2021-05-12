#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 100000000;
const int MOD = 1e9 + 7;
int answer = 0;

void dfs(int ancestor, int source, int counter, int k, vector<vector<int>> &adjlist, vector<int> &hasCat, vector<bool> &visited){
    visited[source] = true;
    if(counter > k) return;
    if(ancestor == -1){
        if(hasCat[source] == 1) counter = 1;
        else counter = 0;
    }else{
        if(hasCat[source] == 1 && hasCat[ancestor] == 1) counter++;
        else if(hasCat[source] == 1 && hasCat[ancestor] == 0) counter = 1;
        else if(hasCat[source] == 0 && hasCat[ancestor] == 0) counter = 0;
        else counter = 0;
    }
    if((int)adjlist[source].size() == 1 && visited[adjlist[source][0]] == true){ //Cheguei numa folha
        if(counter <= k){
            answer++;
        }
        return;
    }
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int u = adjlist[source][i];
        if(visited[u] == false){
            dfs(source, u, counter, k, adjlist, hasCat, visited);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int counter = 0;
    int vertices, k;
    cin >> vertices >> k;

    vector<int> hasCat(vertices + 1, 0);
    vector<bool> visited(vertices + 1, 0);
    vector<vector<int>> adjlist(vertices + 1, vector<int>());
    for(int i = 1; i <= vertices; i++){
        cin >> hasCat[i];
    }
    for(int i = 1; i <= vertices - 1; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(-1, 1, counter, k, adjlist, hasCat, visited);

    cout << answer << "\n";


    return 0;
}
