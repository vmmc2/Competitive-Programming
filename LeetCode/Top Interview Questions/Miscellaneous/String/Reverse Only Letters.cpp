class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n = (int)S.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            while(left < right && !(S[left] >= 65 && S[left] <= 90) && !(S[left] >= 97 && S[left] <= 122))left++;
            while(left < right && !(S[right] >= 65 && S[right] <= 90) && !(S[right] >= 97 && S[right] <= 122))right--;
            if(left >= right) break;
            char temp = S[left];
            S[left] = S[right];
            S[right] = temp;
            left++;
            right--;
        }
        
        return S;
    }
};
