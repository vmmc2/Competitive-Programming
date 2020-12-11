class Solution {
public:
    int longestPalindrome(string s) {
        bool allEven = true;
        bool allOdd = true;
        vector<int> freq(256, 0);
        vector<int> numberOfOdds;
        int lengthOfEven = 0;
        int lengthOfOdd = 0;
        
        for(int i = 0; i < (int)s.size(); i++){
            freq[(int)s[i]]++;
        }
        
        for(int i = 0; i < 256; i++){
            if(freq[i] % 2 == 0){
                allOdd = false; 
                lengthOfEven += freq[i];
            } 
            if(freq[i] % 2 != 0){
                allEven = false;
                numberOfOdds.push_back(freq[i]);
            } 
        }
        if(allEven == true) return (int)s.size();
        sort(numberOfOdds.begin(), numberOfOdds.end());
        for(int i = (int)numberOfOdds.size() - 1; i >= 0; i--){
            if(i == (int)numberOfOdds.size() - 1){
                lengthOfOdd += numberOfOdds[i];    
            }else{
                lengthOfOdd += (numberOfOdds[i] - 1);
            }
        }
        if(allOdd == true) return lengthOfOdd;
        return (lengthOfEven + lengthOfOdd);
        
    }
};
