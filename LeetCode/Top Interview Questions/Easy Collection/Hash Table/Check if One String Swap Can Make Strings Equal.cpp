class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        
        vector<int> indexes;
        bool canDoIt = false;
        int differBy = 0;
        for(int i = 0; i < (int)s1.size(); i++){
            if(s1[i] != s2[i]){
                differBy++;
                indexes.push_back(i);
            }
        }
        if(differBy != 2) return canDoIt;
        
        if(s1[indexes[0]] == s2[indexes[1]] && s1[indexes[1]] == s2[indexes[0]]){
            canDoIt = true;
        }
        
        return canDoIt;
    }
};
