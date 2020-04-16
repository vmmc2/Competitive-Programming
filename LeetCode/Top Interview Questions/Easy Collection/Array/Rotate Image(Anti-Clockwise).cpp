class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //first of all we have to check the conner cases...
        if((int)matrix.size() == 0) return;
        if((int)matrix[0].size() == 0) return;
        
        //now we treat the general cases..
        int n = (int)matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (n/2); j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
        //and then we are going to do the transpose of our matrix..
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return;
    }
};
