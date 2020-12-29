class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string answer = "";
        for(int i = 0; i < (int)indices.size(); i++){
            answer += " ";
        }
        for(int i = 0; i < (int)s.size(); i++){
            answer[indices[i]] = s[i];
        }
        s = answer;
        return s;
    }
};
