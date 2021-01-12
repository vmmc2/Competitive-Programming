class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int answer = -1;
        vector<vector<int>> indexes(26, vector<int>());
        
        for(int i = 0; i < (int)s.size(); i++){
            indexes[(int)s[i] - (int)'a'].push_back(i);
        }
        for(auto vec : indexes){
            if((int)vec.size() <= 1) continue;
            else{
                answer = max(answer, vec[vec.size() - 1] - vec[0] - 1);
            }
        }
        
        return answer;
    }
};
