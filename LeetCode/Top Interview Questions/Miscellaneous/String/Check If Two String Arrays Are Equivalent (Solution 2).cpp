class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int p1 = 0, p2  = 0;
        int i = 0, j = 0;
        bool ok  = true;
        
        if((int)word1.size() == 0 && (int)word2.size() != 0) return false;
        if((int)word1.size() != 0 && (int)word2.size() == 0) return false;
        
        while(i < (int)word1.size() && j < (int)word2.size()){
            if(word1[i][p1] != word2[j][p2]){
                ok = false;
                break;
            }else{
                p1++;
                if(p1 == (int)word1[i].size()){
                    p1 = 0;
                    i++;
                }
                p2++;
                if(p2 == (int)word2[j].size()){
                    p2 = 0;
                    j++;
                }
            }
        }
        if(i < (int)word1.size() && j >= (int)word2.size()) ok = false;
        if(j < (int)word2.size() && i >= (int)word1.size()) ok = false;
        
        return ok;
    }
};
