class Solution {
public:
    int dx[4] = {1, -1, 0,  0};
    int dy[4] = {0,  0, 1, -1};
    
    int floodfill(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n){
        int size = 0;
        queue<pair<int,int>> fila;
        
        fila.push({x,y});
        visited[x][y] = true;
        size++;
        while(!fila.empty()){
            pair<int,int> curr = fila.front();
            fila.pop();
            
            for(int i = 0; i < 4; i++){
                int newx = curr.first + dx[i];
                int newy = curr.second + dy[i];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1 && visited[newx][newy] == false){
                    visited[newx][newy] = true;
                    size++;
                    fila.push({newx, newy});
                }
            }
        }
        
        return size;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int answer = 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    answer = max(answer, floodfill(i, j, grid, visited, m, n));
                }
            }
        }
        
        return answer;
    }
};
