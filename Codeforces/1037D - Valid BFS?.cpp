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
    vector<int> relativeOrder;
     
    vector<int> bfs(int src, vector<vector<int>> &adjlist, vector<bool> &visited){
        visited[src] = true;
        vector<int> ordering;
        queue<int> fila;
        fila.push(src);
     
        while(!fila.empty()){
            int currv = fila.front();
            ordering.push_back(currv);
            fila.pop();
     
            for(int i = 0; i < (int)adjlist[currv].size(); i++){
                int u = adjlist[currv][i];
                if(visited[u] == false){
                    visited[u] = true;
                    fila.push(u);
                }
            }
        }
        return ordering;
    }
     
    bool comp(int a, int b){
        return relativeOrder[a] < relativeOrder[b];
    }
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int a, b;
        int vertices;
        cin >> vertices;
     
        vector<vector<int>> adjlist(vertices + 1, vector<int>());
        vector<bool> visited(vertices + 1, false);
        vector<int> bfsorder(vertices);
        relativeOrder.resize(vertices + 1);
     
        for(int i = 1; i <= vertices - 1; i++){
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        for(int i = 0; i < vertices; i++){
            cin >> bfsorder[i];
            relativeOrder[bfsorder[i]] = i;
        }
        for(int i = 0; i < (int)adjlist.size(); i++){
            sort(adjlist[i].begin(), adjlist[i].end(), comp);
        }
        vector<int> answer = bfs(1, adjlist, visited);
        bool deuRuim = false;
        for(int i = 0; i < vertices; i++){
            if(answer[i] != bfsorder[i]){
                deuRuim = true;
                break;
            }
        }
        if(deuRuim == true){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
        return 0;
    }
