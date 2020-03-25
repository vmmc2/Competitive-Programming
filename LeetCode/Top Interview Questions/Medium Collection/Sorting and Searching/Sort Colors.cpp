class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0;
        int ones = 0;
        int twos = 0;
        int tam = (int)nums.size();
        for(int i = 0; i < tam; i++){
            if(nums[i] == 0) zeroes++;
            else if(nums[i] == 1) ones++;
            else twos++;
        }
        int cursor = 0;
        while(zeroes != 0){
            nums[cursor] = 0;
            cursor++;
            zeroes--;
        }
        while(ones != 0){
            nums[cursor] = 1;
            cursor++;
            ones--;
        }
        while(twos != 0){
            nums[cursor] = 2;
            cursor++;
            twos--;
        }
        return;
    }
};
