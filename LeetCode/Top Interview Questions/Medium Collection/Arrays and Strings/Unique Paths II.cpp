class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        
        for(int i = 0; i < m; i++){
            if(i == 0) dp[i][0] = 1;
            else{
                if(obstacleGrid[i][0] == 1){
                    break;
                }else{
                    dp[i][0] = dp[i - 1][0];
                }   
            }
        }
        for(int i = 0; i < n; i++){
            if(i == 0) dp[0][i] = 1;
            else{
                if(obstacleGrid[0][i] == 1){
                    break;
                }else{
                    dp[0][i] = dp[0][i - 1];
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        
        return dp[m - 1][n - 1];
    }
};
