class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> answer;
        map<string, int> freq;
        int n = (int)s.size();
            
        if(n <= 10) return answer;
        
        for(int i = 0; i <= n - 10; i++){
            freq[s.substr(i, 10)]++; 
        }
        for(map<string,int>::iterator it = freq.begin(); it != freq.end(); it++){
            if(it->second > 1){
                answer.push_back(it->first);
            }
        }
        
        return answer;
    }
};
