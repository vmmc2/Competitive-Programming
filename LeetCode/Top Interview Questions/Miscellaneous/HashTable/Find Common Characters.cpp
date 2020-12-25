class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = (int)A.size();
        vector<string> answer;
        vector<vector<int>> freqs(n, vector<int>(26, 0));
        
        for(int i = 0; i < (int)A.size(); i++){
            string current = A[i];
            for(int j = 0; j < (int)current.size(); j++){
                freqs[i][(int)current[j] - (int)'a']++;
            }
        }
        for(int i = 0; i < 26; i++){
            int minimum = 1e7;
            for(int j = 0; j < n; j++){
                minimum = min(minimum, freqs[j][i]);
            }
            if(minimum != 0){
                for(int k = 0; k < minimum; k++){
                    string aux = "";
                    aux.push_back((char)(i + 97));
                    answer.push_back(aux);
                }
            }
        }
        return answer;
    }
};
