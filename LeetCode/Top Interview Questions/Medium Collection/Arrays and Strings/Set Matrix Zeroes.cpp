class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //invalid input
        if((int)matrix.size() == 0) return;
        
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        bool firstrowzero = false; //isso aqui vai me indicar se eu devo setar a primeira linha inteira para 0
        bool firstcolzero = false; //isso aqui vai me indicar se eu devo setar a primeira coluna inteira para 0
        
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0){
                firstrowzero = true;
                break;
            }
        }
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                firstcolzero = true;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        if(firstrowzero == true){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        if(firstcolzero == true){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        return;
    }
};
