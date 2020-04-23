#include <cmath>

class Solution {
public:
    int expandAroundCenter(string &s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        //first of all, we must check for corner cases...
        if((int)s.length() == 0 || s == "") return "";
        
        //now, we treat the general cases...
        int n = (int)s.length();
        int start = 0;
        int end = 0;
        for(int i = 0; i < n; i++){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len - 1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end - start + 1); //this method receives the index of the first character of the
        //substring we want to find, and also receives the length of this substring that we want to return
        //we can find the length of this substring by calculating: end - start + 1.
        //Because "start" and "end" are the first and final index of our substring, respectively.
    }
};
