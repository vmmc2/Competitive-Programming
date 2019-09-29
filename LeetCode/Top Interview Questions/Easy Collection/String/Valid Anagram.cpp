class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int shash[124] = {0};
        int thash[124] = {0};
        for(int i = 0; i < s.size(); i++){
            shash[(int)s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            thash[(int)t[i]]++;
        }
        for(int i = 0; i < 124; i++){
            if(shash[i] != thash[i]) return false;
        }
        return true;
    }
};
