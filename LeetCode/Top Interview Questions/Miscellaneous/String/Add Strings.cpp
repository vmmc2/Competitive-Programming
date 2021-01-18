class Solution {
public:
    
    string addStrings(string num1, string num2) {
        string answer = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int l1 = 0, l2 = 0;
        int carry = 0;
        while(l1 < (int)num1.size() && l2 < num2.size()){
            int sum = (int)(num1[l1] - '0') + (int)(num2[l2] - '0') + carry;
            if(sum >= 10){
                answer += (char)((sum % 10) + (int)'0');
                carry = sum/10;
            }else{
                answer += (char)(sum + (int)'0');
                carry = 0;
            }
            l1++;
            l2++;
        }
        while(l1 < (int)num1.size()){
            int sum = (int)(num1[l1] - '0') + carry;
            if(sum >= 10){
                answer += (char)((sum % 10) + (int)'0');
                carry = sum/10;
            }else{
                answer += (char)(sum + (int)'0');
                carry = 0;
            }
            l1++;
        }
        while(l2 < (int)num2.size()){
            int sum = (int)(num2[l2] - '0') + carry;
            if(sum >= 10){
                answer += (char)((sum % 10) + (int)'0');
                carry = sum/10;
            }else{
                answer += (char)(sum + (int)'0');
                carry = 0;
            }
            l2++;
        }
        if(carry > 0){
            answer += (char)(carry + (int)'0');
        }
        
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
