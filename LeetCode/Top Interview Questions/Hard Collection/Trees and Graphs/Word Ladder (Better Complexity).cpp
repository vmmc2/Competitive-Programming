#include <set>
#include <queue>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(int i = 0; i < (int)wordList.size(); i++){
            s.insert(wordList[i]);
        }
        //conner case: the endword is not present in the wordlist
        if(s.find(endWord) == s.end()) return 0;
        
        //treating the general cases
        queue<string> fila;
        fila.push(beginWord);
        int level = 1;
        while(!fila.empty()){
            int tam = (int)fila.size();
            for(int i = 1; i <= tam; i++){
                string current_word = fila.front();
                fila.pop();
                for(int j = 0; j < (int)current_word.size(); j++){
                    char ogch = current_word[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        if(current_word[j] == c) continue;
                        current_word[j] = c;
                        string nova_word = current_word;
                        if(nova_word == endWord) return level + 1;
                        if(s.find(nova_word) != s.end()){
                            fila.push(nova_word);
                            s.erase(nova_word);
                        }
                    }
                    current_word[j] = ogch;
                }
            }
            level++;
        }
        return 0;
    }
};
