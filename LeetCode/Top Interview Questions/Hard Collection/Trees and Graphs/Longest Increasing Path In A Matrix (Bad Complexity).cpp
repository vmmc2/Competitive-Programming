#include <cmath>

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1};
    int visited[300][300];
    
    void floodfill(int row, int col, vector<vector<int>> &matrix, int tracker, int m, int n, int &maximo){
        maximo = max(maximo, tracker);
        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && matrix[nrow][ncol] > matrix[row][col]){
                floodfill(nrow, ncol, matrix, tracker + 1, m, n, maximo);
                visited[nrow][ncol] = 0;
            }
        }
        return;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //taking care of the conner cases...
        if((int)matrix.size() == 0) return 0;
        if((int)matrix[0].size() == 0) return 0;
        
        //taking care of the general cases...
        int maximo = 1;
        int tracker;
        int m = (int)matrix.size(); //numero de linhas
        int n = (int)matrix[0].size(); //numero de colunas
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                floodfill(i, j, matrix, 1, m, n, maximo);
            }
        }
        return maximo;
    }
};
