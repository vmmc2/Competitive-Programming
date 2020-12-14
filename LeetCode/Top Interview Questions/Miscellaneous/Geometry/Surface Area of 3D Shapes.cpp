class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        if((int) grid.size() == 0 || (int)grid[0].size() == 0) return area;
        
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int frow = 0;
        int fcol = 0;
        int lrow = m - 1;
        int lcol = n - 1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                else area++;
                if(i - 1 < frow){ //to na primeira linha
                    area += grid[i][j];
                }else{
                    if(grid[i][j] > grid[i - 1][j]) area += (grid[i][j] - grid[i - 1][j]);
                }
                if(i + 1 > lrow){
                    area += grid[i][j];
                }else{
                    if(grid[i][j] > grid[i + 1][j]) area += (grid[i][j] - grid[i + 1][j]);
                }
                if(j - 1 < fcol){
                    area += grid[i][j];
                }else{
                    if(grid[i][j] > grid[i][j - 1]) area += (grid[i][j] - grid[i][j - 1]);
                }
                if(j + 1 > lcol){
                    area += grid[i][j];
                }else{
                    if(grid[i][j] > grid[i][j + 1]) area += (grid[i][j] - grid[i][j + 1]);
                }
                area++;
            }
        }
        return area;
    }
};
