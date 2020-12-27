class Solution {
public:
    string interpret(string command) {
        string answer = "";
        for(int i = 0; i < (int)command.size(); i++){
            if(command[i] == 'G'){
                answer += 'G';
            }else if(command[i] == '('){
                if(i + 1 < (int)command.size() && command[i + 1] == ')'){
                    answer += 'o';
                }else{
                    answer += "al";
                }
            }    
        }
        return answer;
    }
};
