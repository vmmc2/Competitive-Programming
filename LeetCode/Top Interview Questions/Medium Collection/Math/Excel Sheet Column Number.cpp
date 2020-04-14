class Solution {
public:
    long long int titleToNumber(string s) {
        //conner case in which we receive an empty string as an input...
        if((int)s.size() == 0) return 0;
        //treating the general cases..
        long long int resposta = 0;
        long long int multiplier = 1;
        int n = (int)s.size();
        for(int i = n - 1; i >= 0; i--, multiplier *= 26){
            resposta += (s[i] - 'A' + 1)*(multiplier);
        }
        return resposta;
    }
};
