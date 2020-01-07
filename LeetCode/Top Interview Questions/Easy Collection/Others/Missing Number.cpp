class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Oq a gente tem eh o seguinte: Um vetor com n elementos: os elementos vao de 0 ate N
        //So que ta faltando 1 elemento.
        //Ideia faz a soma da P.A de 0 ate N
        int n = (int)nums.size();
        int sum = ((1 + n)*n)/2;
        int realsum = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            realsum += nums[i];
        }
        int ans = sum - realsum;
        return ans;
    }
};
