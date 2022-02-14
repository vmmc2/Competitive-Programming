class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int row = 0, col = 0, count = 0, currNum = 1;
        string direction = "right";
        
        while(count < n*n){
            if(matrix[row][col] == 0){
                matrix[row][col] = currNum;
                count++;
                currNum++;
            }
            
            if(direction == "right"){
                if(col + 1 >= n || matrix[row][col + 1] != 0) direction = "bottom";
                else col++;
            }else if(direction == "bottom"){
                if(row + 1 >= n || matrix[row + 1][col] != 0) direction = "left";
                else row++;
            }else if(direction == "left"){
                if(col - 1 < 0 || matrix[row][col - 1] != 0) direction = "top";
                else col--;
            }else if(direction == "top"){
                if(row - 1 < 0 || matrix[row - 1][col] != 0) direction = "right";
                else row--;
            }
        }
        
        return matrix;
    }
};
