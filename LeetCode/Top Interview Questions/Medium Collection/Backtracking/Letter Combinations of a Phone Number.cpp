#include <map>

class Solution {
public:
    void helper(int cursor, int n, map<char,vector<char>> &dict, vector<string> &answer, string now, string &digits){
        if(cursor >= n){
            answer.push_back(now);
            return;
        }
        vector<char> mp = dict[digits[cursor]];
        for(int i = 0; i < (int)mp.size(); i++){
            helper(cursor + 1, n, dict, answer, now + mp[i], digits);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> dict;
        vector<string> answer;
        dict['2'] = {'a','b','c'};
        dict['3'] = {'d','e','f'};
        dict['4'] = {'g','h','i'};
        dict['5'] = {'j','k','l'};
        dict['6'] = {'m','n','o'};
        dict['7'] = {'p','q','r','s'};
        dict['8'] = {'t','u','v'};
        dict['9'] = {'w','x','y','z'};
        
        //conner case
        int n = (int)digits.length();
        if(n == 0) return answer;
        
        //treating the general cases
        int cursor = 0;
        string now = "";
        helper(cursor, n, dict, answer, now, digits);
        return answer;
    }
};
