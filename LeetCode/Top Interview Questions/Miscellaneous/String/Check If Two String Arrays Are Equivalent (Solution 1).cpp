class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for(auto str : word1){
            s1 += str;
        }
        for(auto str : word2){
            s2 += str;
        }
        if(s1 == s2) return true;
        return false;
    }
};
