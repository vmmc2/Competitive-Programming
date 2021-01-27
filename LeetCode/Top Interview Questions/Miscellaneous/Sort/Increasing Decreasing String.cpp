class Solution {
public:
    bool noMoreCharsLeft(vector<int> &freq){
        bool answer = true;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                answer = false;
                break;
            }
        }
        return answer;
    }
    string sortString(string s) {
        bool ok = true;
        string answer = "";
        vector<int> freq(26, 0);
        
        for(int i = 0; i < (int)s.size(); i++){
            freq[(int)s[i] - (int)'a']++;
        }
        while(noMoreCharsLeft(freq) == false){
            for(int i = 0; i < 26; i++){
                if(freq[i] > 0){
                    freq[i]--;
                    answer += (char)(i + (int)'a');
                }
            }
            if(noMoreCharsLeft(freq) == true) break;
            for(int i = 25; i >= 0; i--){
                if(freq[i] > 0){
                    freq[i]--;
                    answer += (char)(i + (int)'a');
                }
            }
        }
        for(int i = 0; i < 26; i++){
            cout << freq[i] << "\n";
        }
        
        return answer;
    }
};
