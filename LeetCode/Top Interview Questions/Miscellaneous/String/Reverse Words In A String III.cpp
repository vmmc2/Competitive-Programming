class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = (int)s.size();
        
        while(i < n){
            while(s[i] == ' ') i++;
            int left = i;
            while(left + 1 < n && s[left + 1] != ' '){
                left++;
            }
            int cont = left + 1;
            while(i < left){
                char aux = s[i];
                s[i] = s[left];
                s[left] = aux;
                i++;
                left--;
            }
            i = cont;
        }
        return s;
    }
};
