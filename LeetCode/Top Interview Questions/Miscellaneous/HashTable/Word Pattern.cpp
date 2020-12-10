#include <sstream>
#include <iostream>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> dicio1;
        map<string,char> dicio2;
        vector<string> words;
        bool answer = true;
        
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        
        if((int)pattern.size() != (int)words.size()){
            answer = false;
        }else{
            for(int i = 0; i < (int)pattern.size(); i++){
                if(dicio1.find(pattern[i]) == dicio1.end() && dicio2.find(words[i]) == dicio2.end()){
                    dicio1[pattern[i]] = words[i];
                    dicio2[words[i]] = pattern[i];
                }else{
                    if(dicio1[pattern[i]] != words[i] || dicio2[words[i]] != pattern[i]){
                        answer = false;
                        break;
                    }
                }
            }
        }
        
        return answer;
    }
};
