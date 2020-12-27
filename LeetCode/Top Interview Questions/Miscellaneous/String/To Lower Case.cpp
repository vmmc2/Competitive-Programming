class Solution {
public:
    string toLowerCase(string str) {
        int n = (int)str.size();
        for(int i = 0; i < n; i++){
            if((int)str[i] >= 65 && (int)str[i] <= 90){
                str[i] = (char)((int)str[i] + 32);
            }
        }
        return str;
    }
};
