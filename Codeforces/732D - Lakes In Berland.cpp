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

const ll MOD = 1e9 + 7;
int counter = 0;
const int dx[4] = {1, -1, 0,  0};
const int dy[4] = {0,  0, 1, -1};

void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited, int n, int m, bool count = false, bool change = false){
    if(count == true){
        counter++;
    }
    if(change == true){
        grid[x][y] = '*';
    }
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && visited[nextx][nexty] == false && grid[nextx][nexty] == '.'){
            dfs(nextx, nexty, grid, visited, n, m, count, change);
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    //Passo 1: Desconsiderar todas as porcoes de agua que se conectam ao oceano.
    for(int i = 0; i < n; i++){
        if(visited[i][0] == false && grid[i][0] == '.') dfs(i, 0, grid, visited, n, m, false, false);
    }
    for(int i = 0; i < n; i++){
        if(visited[i][m - 1] == false && grid[i][m - 1] == '.') dfs(i, m - 1, grid, visited, n, m, false, false);
    }
    for(int i = 0; i < m; i++){
        if(visited[0][i] == false && grid[0][i] == '.') dfs(0, i, grid, visited, n, m, false, false);
    }
    for(int i = 0; i < m; i++){
        if(visited[n - 1][i] == false && grid[n - 1][i] == '.') dfs(n - 1, i, grid, visited, n, m, false, false);
    }
    //Passo 2: Contar quantos laguinhos existem e os seus respectivos tamanhos
    vector<pair<int,pair<int,int>>> lakesSize;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(grid[i][j] == '.' && visited[i][j] == false){
                counter = 0;
                dfs(i, j, grid, visited, n, m, true, false);
                lakesSize.pb({counter, {i, j}});
            }
        }
    }
    if(k == (int)lakesSize.size()){
        cout << "0" << endl;
    }else{
        sort(lakesSize.begin(), lakesSize.end());
        vector<vector<bool>> visited2(n, vector<bool>(m, false));
        int num = (int)lakesSize.size() - k;
        int answer = 0;
        for(int i = 0; i < num; i++){
            answer += lakesSize[i].first;
            dfs(lakesSize[i].second.first, lakesSize[i].second.second, grid, visited2, n, m, false, true);
        }
        cout << answer << endl;
    }
    for(auto ss : grid){
        for(auto s : ss){
            cout << s;
        }
        cout << endl;
    }

    return 0;
}
