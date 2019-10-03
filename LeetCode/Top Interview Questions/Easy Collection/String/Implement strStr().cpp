class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int tamn = (int)needle.size();
        int tamh = (int)haystack.size();
        for(int i = 0; i <= tamh - tamn ; i++){
            int ok = 1;
            if(needle[0] == haystack[i]){
                int iowa = i;
                for(int j = 0; j < (int)needle.size(); j++){
                    if(needle[j] != haystack[iowa]) ok = 0;
                    iowa++;
                }
                if(ok == 1){
                    return i;
                }
            }
        }
        return -1;
    }
};
