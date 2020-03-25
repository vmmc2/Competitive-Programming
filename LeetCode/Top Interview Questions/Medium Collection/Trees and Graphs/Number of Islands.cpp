class Solution {
public:
    int dx[4] = {0 ,1,0,-1};
    int dy[4] = {-1,0,1, 0};
    int visited[1000][1000];
    void floodfill(vector<vector<char>>& grid1, int i, int j, int m, int n){
        visited[i][j] = 1;
        for(int i1 = 0; i1 < 4; i1++){
            int newx = i + dx[i1];
            int newy = j + dy[i1];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n){
                if(visited[newx][newy] == 0 && grid1[newx][newy] == '1'){
                    floodfill(grid1, newx, newy, m, n);
                }
            }
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        //temos que descobrir o tamanho (M e N) desse grid
        if(grid.size() == 0) return 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int qtdilhas = 0;
        memset(visited, 0, sizeof(visited));
        
        //iteracting through each cell of this grid.
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    if(visited[i][j] == 0){
                        qtdilhas++;
                        floodfill(grid, i, j, m, n);
                    }
                }
            }
        }
        return qtdilhas;
    }
};
