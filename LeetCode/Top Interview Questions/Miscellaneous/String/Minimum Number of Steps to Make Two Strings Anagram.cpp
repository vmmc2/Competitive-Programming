class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);
        if(s == t) return 0;
        for(int i = 0; i < (int)s.size(); i++){
            freqS[(int)s[i] - (int)'a']++;
        }
        for(int j = 0; j < (int)t.size(); j++){
            freqT[(int)t[j] - (int)'a']++;
        }
        int answer = 0;
        for(int i = 0; i < 26; i++){
            if(freqS[i] > freqT[i]) answer += (freqS[i] - freqT[i]);    
        }
        return answer;
    }
};
