class Solution {
public:
    int maxDepth(string s) {
        int answer = 0;
        int current = 0;
        for(auto ch : s){
            if(ch == '('){
                current++;
                answer = max(answer, current);
            }else if(ch == ')'){
                current--;
            }
        }
        return answer;
    }
};
