bool comparator(int a, int b){
    if(a <= b){
        return false;
    }
    return true;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> answer;
        map<int,int> freq; //mapeia os inteiros para as suas respectivas frequencias.
        map<int, vector<int>> whichNumbers; //mapeia frequencias especificas para a list de numeros que as possuem.
        for(int i = 0; i < (int)nums.size(); i++){
            freq[nums[i]]++;
        }
        for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            whichNumbers[it->second].push_back(it->first);
        }
        for(map<int,vector<int>>::iterator it = whichNumbers.begin(); it != whichNumbers.end(); it++){
            sort(whichNumbers[it->first].begin(), whichNumbers[it->first].end(), comparator);
        }
        for(map<int,vector<int>>::iterator it = whichNumbers.begin(); it != whichNumbers.end(); it++){
            vector<int> curr = whichNumbers[it->first];
            for(int i = 0; i < (int)curr.size(); i++){
                for(int j = 0; j < it->first; j++){
                    answer.push_back(curr[i]);
                }    
            }
        }
        
        return answer;
    }
};
