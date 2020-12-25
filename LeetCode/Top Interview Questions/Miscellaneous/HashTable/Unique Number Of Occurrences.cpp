class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool answer = true;
        unordered_map<int,int> freq;
        unordered_map<int,int> NumberOfFreq;
        for(int i = 0; i < (int)arr.size(); i++){
            freq[arr[i]]++;
        }
        for(unordered_map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            NumberOfFreq[it->second]++;
        }
        for(unordered_map<int,int>::iterator it = NumberOfFreq.begin(); it != NumberOfFreq.end(); it++){
            if(it->second > 1){
                answer = false;
                break;
            } 
        }
        return answer;
    }
};
