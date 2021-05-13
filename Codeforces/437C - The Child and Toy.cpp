#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 100000000;
const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int vertices, edges;
    cin >> vertices >> edges;

    vector<pair<int,int>> v(vertices + 1, {0,0});
    vector<vector<pair<int,int>>> adjlist(vertices + 1, vector<pair<int,int>>());

    for(int i = 1; i <= vertices; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    vector<pair<int,int>> v1 = v;
    for(int i = 1; i <= edges; i++){
        cin >> a >> b;
        adjlist[a].push_back({b, 0});
        adjlist[b].push_back({a, 0});
    }   
    sort(v.begin(), v.end());
    ll answer = 0;
    for(int i = (int)v.size() - 1; i >= 0; i--){
        int curr_part = v[i].second;
        for(int j = 0; j < (int)adjlist[curr_part].size(); j++){
            if(adjlist[curr_part][j].second == 0){
                adjlist[curr_part][j].second = 1;
                int vertice = adjlist[curr_part][j].first;
                answer += (long long)(v1[vertice].first);
                for(int k = 0; k < (int)adjlist[vertice].size(); k++){
                    int child = adjlist[vertice][k].first;
                    if(child == curr_part){
                        adjlist[vertice][k].second = 1;
                    }
                }
            }
        }
    }
    cout << answer << endl;

    return 0;
}
