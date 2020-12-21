class Solution {
public:
    string addBinary(string a, string b) {
        string answer = "";
        int i = (int)a.size() - 1;
        int j = (int)b.size() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0){
                sum += (int)a[i] - (int)'0';
                i--;
            }
            if(j >= 0){
                sum += (int)b[j] - (int)'0';
                j--;
            }
            int result = sum % 2;
            answer += (char)(result + (int)'0');
            carry = sum/2;
        }
        if(carry > 0) answer += '1';
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
