class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal;
        pascal.resize(rowIndex + 1);
        
        pascal[0].push_back(1);
        if(rowIndex == 0) return pascal[0];
        
        pascal[1].push_back(1);
        pascal[1].push_back(1);
        int currentLength = 3;
        for(int i = 2; i < pascal.size(); i++){
            for(int j = 0; j < currentLength; j++){
                if(j == 0){
                    pascal[i].push_back(1);
                }else if(j == currentLength - 1){
                    pascal[i].push_back(1);
                }else{
                    pascal[i].push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
                }
            }
            currentLength++;
        }
        
        return pascal[rowIndex];
    }
};
