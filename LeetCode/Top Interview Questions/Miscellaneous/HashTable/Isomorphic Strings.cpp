class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //corner case
        if(s == t) return true;
        bool can = true;
        map<char,char> dicio;
        map<char,char> dicio2;
        
        for(int i = 0; i < (int)s.size(); i++){
            if(dicio.find(s[i]) == dicio.end() && dicio2.find(t[i]) == dicio2.end()){ //Ainda nao fiz esse mapeamento
                dicio[s[i]] = t[i];
                dicio2[t[i]] = s[i];
            }else{
                if(dicio[s[i]] != t[i] || dicio2[t[i]] != s[i]){
                    can = false;
                    break;
                }
            }
        }
        return can;
    }
};
