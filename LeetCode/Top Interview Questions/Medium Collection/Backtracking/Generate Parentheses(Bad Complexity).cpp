#include <stack>

class Solution {
public:
    bool check_valid(string ss){
        stack<char> pilha;
        for(int i = 0; i < (int)ss.length(); i++){
            if(ss[i] == '('){
                pilha.push('(');
            }else{
                if(pilha.empty()) return false;
                else{
                    pilha.pop();
                }
            }
        }
        if(!pilha.empty()) return false;
        return true;
    }
    void helper(int cursor, int finale, string s, vector<string> &answer){
        if(cursor >= finale){
            if(check_valid(s)){ //se for uma combinacao valida, eu guardo no vector e retorno.
                answer.push_back(s);
                return;
            }
            return; //se nao for, eu so retorno.
        }
        helper(cursor + 1, finale, s + '(', answer);
        helper(cursor + 1, finale, s + ')', answer);
        return;
    }
    vector<string> generateParenthesis(int n) {
        int tam = 2*n;
        vector<string> answer;
        
        //treating the conner case
        if(tam == 0) return answer;
        
        //treating the general cases...
        int cursor = 0;
        int finale = 2*n;
        string s = "";
        helper(cursor, finale, s, answer);
        return answer;
    }
};
