#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(int source, unordered_map<int,int> &visited, vector<vector<int>> &adjlist){
    if(visited[source] == 1){
        return;
    }
    visited[source] = 1;
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int x = adjlist[source][i];
        if(visited[x] == 0){
            dfs(x, visited, adjlist);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, l;
    cin >> n >> k >> l;
    
    vector<vector<int>> adjlistroad(n + 1);
    vector<vector<int>> adjlistrail(n + 1);
    unordered_map<int,int> visitedroad;
    unordered_map<int,int> visitedrail;
    vector<int> answer(n + 1, 0);
    
    int from, to;
    for(int i = 0; i < k; i++){
        cin >> from >> to;
        adjlistroad[from].push_back(to);
        adjlistroad[to].push_back(from);
    }
    for(int i = 0; i < l; i++){
        cin >> from >> to;
        adjlistrail[from].push_back(to);
        adjlistrail[to].push_back(from);
    }
    
    for(int i = 1; i <= n; i++){
        visitedroad.clear();
        visitedrail.clear();
        dfs(i, visitedroad, adjlistroad);
        dfs(i, visitedrail, adjlistrail);
        /*cout << "Partindo da cidade " << i << ": " << endl;
        for(int k = 1; k <= n; k++){
            cout << visitedroad[k] << " ";
        }
        cout << endl;
        for(int k = 1; k <= n; k++){
            cout << visitedrail[k] << " ";
        }*/
        /*cout << endl;
        cout << endl;*/
        for(unordered_map<int,int>::iterator it = visitedroad.begin(); it != visitedroad.end(); it++){
            if(visitedrail[it->first] == 1){
                answer[i]++;
            }
        }
        
    }
    
    for(int i = 1; i <= n; i++){
        cout << answer[i] << " ";
    }
    
    
    return 0;
}
