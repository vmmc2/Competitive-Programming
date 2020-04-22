#include <cmath>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if((int)s.length() == 0) return 0; //base case
        
        //treating the conner cases
        int n = (int)s.length();
        int answer = 1;
        for(int i = 0; i < n; i++){
            int current = 1;
            unordered_set<char> usei;
            usei.insert(s[i]);
            for(int j = i + 1; j < n; j++){
                if(j == n) break;
                if(usei.find(s[j]) != usei.end()){ //ja achei esse caractere...
                    break;
                }else if(usei.find(s[j]) == usei.end()){ //nao achei esse caractere...
                    usei.insert(s[j]);
                    current++;
                }
            }
            answer = max(answer,current);
        }
        return answer;
    }
};
