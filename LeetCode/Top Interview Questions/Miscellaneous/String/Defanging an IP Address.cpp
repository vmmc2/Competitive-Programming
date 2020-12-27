class Solution {
public:
    string defangIPaddr(string address) {
        string answer = "";
        for(auto ch : address){
            if(ch != '.') answer += ch;
            else{
                answer += "[.]";
            }
        }
        return answer;
    }
};
