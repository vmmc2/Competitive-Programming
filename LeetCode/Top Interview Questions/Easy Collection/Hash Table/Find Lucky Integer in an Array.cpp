class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> freq;
        for(auto x : arr){
            freq[x]++;
        }
        int answer = -1;
        for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            if(it->first == it->second){
                answer = it->first;
            }
        }
        return answer;
    }
};
