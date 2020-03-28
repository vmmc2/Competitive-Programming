class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //primeira coisa a fazer eh ordenar o array para poder usar a tecnica de two pointers.
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int tam = (int)nums.size();
        for(int i = 0; i < tam - 2; i++){ //iterando pelo array ate o (terceiro do fim para o inicio)
            if(i == 0 ||(i > 0 && nums[i] != nums[i - 1])){
                int low = i + 1;
                int high = tam - 1;
                int sum = 0 - nums[i];
                
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        vector<int> p;
                        p.push_back(nums[i]);
                        p.push_back(nums[low]);
                        p.push_back(nums[high]);
                        ans.push_back(p);
                        //tem que retirar as duplicatas
                        while(low < high && nums[low] == nums[low + 1]) low++;
                        while(low < high && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    }else if(nums[low] + nums[high] > sum){
                        high--;
                    }else if(nums[low] + nums[high] < sum){
                        low++;
                    }
                }
            }
        }
        return ans;
    }
};
