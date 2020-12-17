class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0) return 0;
        long low = 1;
        long high = (long)num;
        while(low <= high){
            long mid = low + (high - low)/2;
            if(mid * mid == num){
                return true;
            }else if(mid * mid < num){
                low = mid + 1;
            }else if(mid * mid > num){
                high = mid - 1;
            }
        }
        
        return false;
    }
};
