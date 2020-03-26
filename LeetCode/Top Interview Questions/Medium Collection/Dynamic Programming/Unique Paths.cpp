class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        //base cases:
        dp[0][0] = 1; //de onde ele comeca so tem uma forma de chegar...
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){ //caso base da primeira linha ou primeira coluna: So tem uma forma de chegar nesse local. Porque o robot nao pode nem subir e nem vir pela esquerda.
                    dp[i][j] = 1;
                }else if(i != 0 && j != 0){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
