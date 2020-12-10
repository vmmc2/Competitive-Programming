class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> freq1;
        unordered_map<int,bool> freq2;
        vector<int> answer;
        
        for(int i = 0; i < (int)nums1.size(); i++){
            freq1[nums1[i]] = true;
        }
        for(int i = 0; i < (int)nums2.size(); i++){
            freq2[nums2[i]] = true;
        }
        
        for(unordered_map<int,bool>::iterator it = freq1.begin(); it != freq1.end(); it++){
            if(freq2[it->first] == true){
                answer.push_back(it->first);
            }
        }
        
        return answer;
    }
};
