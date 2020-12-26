class Solution {
public:
    int subtractProductAndSum(int n) {
        int answer, a = 1, b = 0;
        while(n != 0){
            int digit = n % 10;
            a = a * digit;
            b = b + digit;
            n = n/10;
        }
        answer = a - b;
        return answer;
    }
    //Time Complexity: O(log n) -> At base 10.
};
