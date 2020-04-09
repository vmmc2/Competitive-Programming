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

/*************************************************************************************/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if((int)matrix.size() == 0) return;
        if((int)matrix[0].size() == 0) return;
        int n = (int)matrix.size();
        for(int layer = 0; layer < n/2; layer++){
            int first = layer;
            int last = n - 1 - layer;
            for(int i = first; i < last; i++){
                int offset = i - first;
                int temp = matrix[first][i];
                matrix[first][i] = matrix[last - offset][first];
                matrix[last - offset][first] = matrix[last][last - offset];
                matrix[last][last - offset] = matrix[i][last];
                matrix[i][last] = temp;
            }
        }
        return;
    }
};
