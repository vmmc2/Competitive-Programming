class Solution {
public:
    string reverseVowels(string s) {
        int low = 0;
        int high = (int)s.size() - 1;
        
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
        
        while(low < high){
            if(vowels.find(s[low]) != vowels.end() && vowels.find(s[high]) != vowels.end()){
                char temp = s[low];
                s[low] = s[high];
                s[high] = temp;
                low++;
                high--;
            }
            else if(vowels.find(s[low]) == vowels.end() && vowels.find(s[high]) == vowels.end()){
                low++;
                high--;
            }
            else if(vowels.find(s[low]) != vowels.end() && vowels.find(s[high]) == vowels.end()){
                high--;    
            }
            else if(vowels.find(s[low]) == vowels.end() && vowels.find(s[high]) != vowels.end()){
                low++;
            }
        }
        return s;
    }
};
