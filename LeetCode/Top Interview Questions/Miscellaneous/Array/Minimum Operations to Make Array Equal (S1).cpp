class Solution {
public:
    int minOperations(int n) {
        if(n == 1) return 0;
        
        int answer = 0;
        vector<long long> nums(n);
        for(int i = 0, j = 1; i < n; i++, j += 2){
            nums[i] = j;
        }
        if(n % 2 == 1){
            int limit = n/2;
            for(int i = 0; i < limit; i++){
                answer += abs(nums[limit] - nums[i]);
            }
        }else{
            int limit = n/2;
            int x = (nums[limit] + nums[limit - 1])/2;
            for(int i = 0; i <= limit - 1; i++){
                answer += abs(x - nums[i]);
            }
        }
        
        return answer;
    }
};
