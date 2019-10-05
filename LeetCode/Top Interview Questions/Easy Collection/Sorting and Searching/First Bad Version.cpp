// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isBadVersion(mid) == 0){
                start = mid + 1;
            }else if(isBadVersion(mid) == 1){
                end = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
