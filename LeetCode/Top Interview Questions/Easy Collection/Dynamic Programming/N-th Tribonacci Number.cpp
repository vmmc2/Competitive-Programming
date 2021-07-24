class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribonacci(n + 1, 0);
        for(int i = 0; i < (int)tribonacci.size(); i++){
            if(i == 0) tribonacci[i] = 0;
            else if(i == 1 || i == 2) tribonacci[i] = 1;
            else{
                tribonacci[i] = tribonacci[i - 1] + tribonacci[i - 2] + tribonacci[i - 3];
            }
        }
        return tribonacci[n];
    }
};
