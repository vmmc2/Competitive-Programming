class Solution {
public:
    bool isValid(string s) {
        if((int)s.size() == 0){
            return true;
        }
        stack<char> pilha;
        bool ans = true; //vamos supor que ta tudo certo inicialmente e tentar provar que da merda.
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == '('){
                pilha.push(s[i]);
            }else if(s[i] == '{'){
                pilha.push(s[i]);
            }else if(s[i] == '['){
                pilha.push(s[i]);
            }else if(s[i] == ')'){
                if(pilha.empty()) return false;
                else{
                    if(pilha.top() == '('){
                        pilha.pop();
                    }else{
                        return false;
                    }
                }
            }else if(s[i] == '}'){
                if(pilha.empty()) return false;
                else{
                    if(pilha.top() == '{'){
                        pilha.pop();
                    }else{
                        return false;
                    }
                }
                
            }else if(s[i] == ']'){
                if(pilha.empty()) return false;
                else{
                    if(pilha.top() == '['){
                        pilha.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(!pilha.empty()) return false;
        return true;
    }
};
