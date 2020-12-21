class Solution {
public:
    bool backspaceCompare(string S, string T) {
        bool answer = true;
        string fs = "", ft = "";
        vector<char> ss, tt;
        for(int i = 0; i < (int)S.size(); i++){
            if(S[i] >= 'a' && S[i] <= 'z'){
                ss.push_back(S[i]);
            }else if(S[i] == '#'){
                if((int)ss.size() > 0) ss.pop_back();
            }
        }
        for(int i = 0; i < (int)T.size(); i++){
            if(T[i] >= 'a' && T[i] <= 'z'){
                tt.push_back(T[i]);
            }else if(T[i] == '#'){
                if((int)tt.size() > 0) tt.pop_back();
            }
        }
        for(auto x : ss) fs += x;
        for(auto y : tt) ft += y;
        if(fs != ft) answer = false;
        return answer;
    }
};
