class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int perimeter = 0;
        
        int firstRow = 0;
        int lastRow = m - 1;
        int firstColumn = 0;
        int lastColumn = n - 1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(i - 1 >= firstRow){
                        if(grid[i - 1][j] != 1) perimeter++;
                    }else{
                        perimeter++;
                    }
                    if(i + 1 <= lastRow){
                        if(grid[i + 1][j] != 1) perimeter++;
                    }else{
                        perimeter++;
                    }
                    if(j - 1 >= firstColumn){
                        if(grid[i][j - 1] != 1) perimeter++;
                    }else{
                        perimeter++;
                    }
                    if(j + 1 <= lastColumn){
                        if(grid[i][j + 1] != 1) perimeter++;
                    }else{
                        perimeter++;
                    }
                }
            }
        }
        
        return perimeter;
    }
};
