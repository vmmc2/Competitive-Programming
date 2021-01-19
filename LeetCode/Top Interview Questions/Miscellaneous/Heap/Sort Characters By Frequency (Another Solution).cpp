class Solution {
public:
    string frequencySort(string s) {
        string answer = "";
        unordered_map<char,int> freq;
        vector<pair<int,char>> letters;
        for(int i = 0; i < (int)s.size(); i++){
            freq[s[i]]++;
        }
        for(unordered_map<char,int>::iterator it = freq.begin(); it != freq.end(); it++){
            letters.push_back({it->second, it->first});
        }
        sort(letters.begin(), letters.end());
        for(int i = (int)letters.size() - 1; i >= 0; i--){
            for(int j = 0; j < letters[i].first; j++){
                answer += letters[i].second;
            }
        }
        return answer;
    }
};
