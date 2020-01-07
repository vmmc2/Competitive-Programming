class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        bool por3 = true;
        while(true){
            if(n == 1) return true;
            if(n % 3 != 0){
                return false;
            }else{
                n = n/3;
            }
        }
    }
};
