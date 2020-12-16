class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int answer = 0;
        
        for(int i = 0; i < m; i++){
            int qtd = n;
            if(grid[i][0] < 0){
                answer += qtd;
            }else{
                int low = 0;
                int high = n - 1;
                while(low <= high){
                    int mid = low + (high - low)/2;
                    if(grid[i][mid] >= 0){
                        qtd = mid;
                        low = mid + 1;
                    }else{
                        high = mid - 1;
                    }
                }
                answer += (n - (qtd + 1));
            }
        }
        return answer;
    }
};
