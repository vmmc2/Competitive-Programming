class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
    //Time Complexity: O(log n) -> At base 10.
};
