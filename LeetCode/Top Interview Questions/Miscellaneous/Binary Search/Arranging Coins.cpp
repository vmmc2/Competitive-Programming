class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 1) return n;
        long low = 0;
        long high = (long)2*(n - 1);
        long answer;
        while(low <= high){
            long mid = low + (high - low)/2;
            if((2 + mid)*(mid - 1) <= (long)2*(n - 1)){
                answer = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return (int)answer;
    }
};
