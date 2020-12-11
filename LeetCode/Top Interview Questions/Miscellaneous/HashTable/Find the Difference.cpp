class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freqs(256, 0);
        vector<int> freqt(256, 0);
        char answer;
        
        for(int i = 0; i < (int)s.size(); i++) freqs[(int)s[i]]++;
        for(int i = 0; i < (int)t.size(); i++) freqt[(int)t[i]]++;
        
        for(int i = 0; i < 256; i++){
            if(freqs[i] != freqt[i]){
                answer = (char) i;
                break;
            }
        }
        
        return answer;
    }
};
