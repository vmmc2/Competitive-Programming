typedef unsigned long long ull;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int add = 1;
        int flag = 0;
        int carry = 0;
        for(int i = 0; i < (int)digits.size(); i++){
            if(i == 0){
                digits[i] += add;
                if(digits[i] >= 10){
                    digits[i] = 0;
                    carry = 1;
                }
            }
            else{
                if(carry == 1){
                    digits[i] += carry;
                    if(digits[i] >= 10){
                        digits[i] = 0;
                    }
                    else{
                        carry = 0;
                    }
                }
            }
            if(carry == 1 && i == (int)digits.size() - 1){
                    flag = 1;
            }
        }
        if(flag) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
