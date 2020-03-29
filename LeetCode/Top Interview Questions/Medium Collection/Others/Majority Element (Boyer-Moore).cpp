class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Outra maneira de resolver esse problema:
        //Usando o Algoritmo de Boyer-Moore (voltado para votacao)
        //Complexidade Temporal -> O(n).
        //Complexidade Espacial -> O(1).
        int count = 0;
        int candidate = nums[0];
        for(int i = 0; i < (int)nums.size(); i++){
            if(count == 0) candidate = nums[i];
            count += (candidate == nums[i])? 1 : -1;
        }
        return candidate;
    }
};
