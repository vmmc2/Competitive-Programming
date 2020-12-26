class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freqChars(26, 0);
        int answer = 0;
        
        for(int i = 0; i < (int)chars.size(); i++){
            freqChars[(int)chars[i] - (int)'a']++;
        }
        for(auto str : words){
            vector<int> freq(26, 0);
            for(int i = 0; i < (int)str.size(); i++){
                freq[(int)str[i] - (int)'a']++;
            }
            bool ok = true;
            for(int i = 0; i < 26; i++){
                if(freq[i] > freqChars[i]){
                    ok = false;
                    break;
                }
            }
            if(ok == true) answer += (int)str.size();
        }
        return answer;
    }
};
