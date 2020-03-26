class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size(); //m -> linhas
        if(m == 0) return false;
        int n = (int)matrix[0].size(); // n -> colunas
        if(n == 0) return false;
        
        int row = 0;
        int column = n - 1;
        while(row < m && column >= 0){
            if(matrix[row][column] == target) return true;
            else if(matrix[row][column] > target){
                column--;
            }else if(matrix[row][column] < target){
                row++;
            }
        }
        return false;
    }
};
