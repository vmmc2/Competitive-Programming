class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int answer = -1;
        multiset<int> numeros;
        for(int i = 0; i < (int)nums.size(); i++){
            numeros.insert(nums[i]);
        }
        multiset<int>::iterator left = numeros.begin();
        multiset<int>::iterator right = numeros.end();
        right--;
        
        while(left != numeros.end()){
            int num1 = *left;
            int num2 = *right;
            answer = max(answer, num1 + num2);
            left++, right--;
        }
        
        return answer;
    }
};
