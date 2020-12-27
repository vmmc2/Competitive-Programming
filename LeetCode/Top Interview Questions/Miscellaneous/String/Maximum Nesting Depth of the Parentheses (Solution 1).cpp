class Solution {
public:
    int maxDepth(string s) {
        string s1 = "";
        int answer = 0;
        stack<char> pilha;
        
        for(auto ch : s){
            if(ch == '(' || ch == ')') s1 += ch;
        }

        for(int i = 0; i < (int)s1.size(); i++){
            if(s1[i] == '('){
                pilha.push(s[i]);
                answer = max(answer, (int)pilha.size());
            }else if(s1[i] == ')'){
                pilha.pop();
            }
        }
        return answer;
    }
};
