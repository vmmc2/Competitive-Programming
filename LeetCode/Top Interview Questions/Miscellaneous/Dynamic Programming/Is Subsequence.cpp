class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = (int)s.size();
        int n2 = (int)t.size();
        if(n1 > n2) return false;
        if(n1 == n2 && s == t) return true;
        if(n1 == n2 && s != t) return false;
        
        int c1 = 0, c2 = 0;
        while(c2 < t.size()){
            if(s[c1] == t[c2]){
                c1++;
                c2++;
            }else{
                c2++;
            }
        }
        if(c1 == s.size()) return true;
        return false;
    }
};
