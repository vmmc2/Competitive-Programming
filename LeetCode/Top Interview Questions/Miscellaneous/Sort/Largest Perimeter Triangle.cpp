class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = (int)A.size();
        int answer = 0;
        
        for(int i = n - 1; i >= 2; i--){
            int l1 = A[i];
            int l2 = A[i - 1];
            int l3 = A[i - 2];
            if((l1 < l2 + l3) && (l2 < l1 + l3) && (l3 < l1 + l2)){
                answer = l1 + l2 + l3;
                break;
            }
        }
        
        return answer;
    }
};
