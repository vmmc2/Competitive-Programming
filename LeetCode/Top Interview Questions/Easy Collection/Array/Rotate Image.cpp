class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix[0].size();
        int num_cycles = floor((int)matrix[0].size()/2);
        int temp;
        for(int i = 0; i < num_cycles; i++){
            for(int j = i; j < n - i - 1; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    
    }
};
