#include <bits/stdc++.h>
#include <sstream>
#define INF 1e8

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    pair<int,int> source;
    pair<int,int> goal;
    map<char,vector<pair<int,int>>> dict;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<vector<int>> dist(h, vector<int>(w, INF));
    for(int i = 0 ; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                source = {i, j};
                dist[i][j] = 0;
            }else if(grid[i][j] == 'G'){
                goal = {i, j};
            }
            else if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                dict[grid[i][j]].push_back({i, j});
            }
        }
    }

    queue<pair<int,int>> fila;
    fila.push(source);
    visited[source.first][source.second] = true;
    while(!fila.empty()){
        auto daVez = fila.front();
        fila.pop();
        for(int i = 0; i < 4; i++){
            int newx = daVez.first + dx[i];
            int newy = daVez.second + dy[i];
            if(newx >= 0 && newx < h && newy >= 0 && newy < w && grid[newx][newy] != '#' && visited[newx][newy] == false){
                if(grid[newx][newy] == '.' || grid[newx][newy] == 'G'){
                    visited[newx][newy] = true;
                    dist[newx][newy] = min(dist[newx][newy], 1 + dist[daVez.first][daVez.second]);
                    fila.push({newx, newy});
                }else if(grid[newx][newy] >= 'a' && grid[newx][newy] <= 'z'){
                    visited[newx][newy] = true;
                    dist[newx][newy] = min(dist[newx][newy], 1 + dist[daVez.first][daVez.second]);
                    fila.push({newx, newy});
                    vector<pair<int,int>> lista = dict[grid[newx][newy]];
                    //cout << "Lista Size: " << lista.size() << " pertence a letra: " << grid[newx][newy] << endl;
                    for(auto par : lista){
                        if(visited[par.first][par.second] == false){
                            //cout << "Dale" << endl;
                            visited[par.first][par.second] = true;
                            dist[par.first][par.second] = min(dist[par.first][par.second], 1 + dist[newx][newy]);
                            fila.push({par.first, par.second});
                        }
                    }
                }

            }
        }
    }
    /*
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */


    if(dist[goal.first][goal.second] != INF){
        cout << dist[goal.first][goal.second] << endl;
    }else{
        cout << "-1" << endl;
    }

    return 0;
}
