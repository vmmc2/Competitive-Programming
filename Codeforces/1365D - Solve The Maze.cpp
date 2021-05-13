#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 100000000;
const int MOD = 1e9 + 7;
int counterGood = 0;
int counterBad = 0;
const int DX[4] = {1, -1, 0,  0};
const int DY[4] = {0,  0, 1, -1};


void bfs(int sourceX, int sourceY, vector<vector<char>> &grid, vector<vector<bool>> &visited, int limitX, int limitY){
    if(grid[sourceX][sourceY] == '#') return;
    visited[sourceX][sourceY] = true;
    queue<pair<int,int>> fila;
    fila.push({sourceX, sourceY});
    while(!fila.empty()){
        pair<int,int> curr = fila.front();
        fila.pop();
        for(int i = 0; i < 4; i++){
            int nextX = curr.first + DX[i];
            int nextY = curr.second + DY[i];
            if(nextX >= 0 && nextX < limitX && nextY >= 0 && nextY < limitY && grid[nextX][nextY] != '#' && visited[nextX][nextY] == false){
                visited[nextX][nextY] = true;
                if(grid[nextX][nextY] == 'G') counterGood++;
                else if(grid[nextX][nextY] == 'B') counterBad++;
                fila.push({nextX, nextY});
            }
        }
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int testcases;
    cin >> testcases;

    while(testcases--){
        cin >> n >> m;
        counterBad = 0;
        counterGood = 0;
        int numGoodPeople = 0, numBadPeople = 0;
        vector<vector<char>> grid(n, vector<char>(m));
        vector<pair<int,int>> badPeopleLocation;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 'G') numGoodPeople++;
                else if(grid[i][j] == 'B'){
                    numBadPeople++;
                    badPeopleLocation.push_back({i, j});
                }
            }
        }
        if(grid[n - 1][m - 1] == '#') cout << "No" << endl;
        else{
            bfs(n - 1, m - 1, grid, visited, n, m);
            if(counterGood < numGoodPeople) cout << "No" << endl; //De cara, nem todas as pessoas boas conseguem sair.
            else{
                //Hora de bloquear as pessoas ruins.
                for(pair<int,int> curr : badPeopleLocation){
                    int x = curr.first, y = curr.second;
                    for(int i = 0; i < 4; i++){
                        int nextX = x + DX[i];
                        int nextY = y + DY[i];
                        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && grid[nextX][nextY] == '.'){
                            grid[nextX][nextY] = '#';
                        }
                    }
                }
                //Reseta os contadores e roda a bfs de novo.
                counterGood = 0;
                counterBad = 0;
                vector<vector<bool>> newvisited(n, vector<bool>(m, false));
                bfs(n - 1, m - 1, grid, newvisited, n, m);
                if(counterBad == 0 && counterGood == numGoodPeople) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
    }


    return 0;
}
