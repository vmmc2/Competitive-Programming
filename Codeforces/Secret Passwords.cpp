#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll p = 31;
const ll MOD = 1000000007;
const int dx[4] = {1, -1, 0,  0};
const int dy[4] = {0,  0, 1, -1};

void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[source] = true;
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

    int n;
    cin >> n;

    int answer = 0;
    vector<string> passwords(n);
    vector<vector<int>> adjlist(26 + n, vector<int>());
    vector<bool> visited(26 + n);

    for(int i = 0; i < n; i++){
        cin >> passwords[i];
    }

    for(int i = 0; i < n; i++){
        auto ss = passwords[i];
        for(int j = 0; j < (int)ss.size(); j++){
            adjlist[i + 26].push_back((int)(ss[j] - 'a'));
            adjlist[(int)(ss[j] - 'a')].push_back(i + 26);
        }
    }

    for(int i = 26; i < (int)adjlist.size(); i++){
        if(visited[i] == false){
            dfs(i, adjlist, visited);
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
