class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> dict;
        int answer = 0;
        
        for(auto x : allowed){
            dict.insert(x);
        }
        for(auto word: words){
            bool ok = true;
            for(int i = 0; i < (int)word.size(); i++){
                if(dict.find(word[i]) == dict.end()){
                    ok = false;
                    break;
                }
            }
            if(ok == true) answer++;
        }
        
        return answer;
    }
    // n-> quantidade de strings no vector "words"
    // |s| -> tamanho da maior string em "words"
    // Time Complexity = O(26) + O(n*|s|) = O(1) + O(n*|s|) = O(n*|s|)
};
