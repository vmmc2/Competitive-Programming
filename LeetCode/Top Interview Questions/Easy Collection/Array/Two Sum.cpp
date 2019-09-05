bool comp(pair<int,int> p1, pair<int,int> p2){
        if(p1.first != p2.first){
            return p1.first < p2.first;
        }else{
            return p1.second < p2.second;
        }
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //trying two pointers...
        //primeiro eu vou fazer uma hash
        vector<pair<int,int>> nums2;
        for(int i = 0; i < (int)nums.size(); i++){
            nums2.push_back({nums[i], i});
        }
        int start = 0;
        int end = (int)nums2.size() - 1;
        sort(nums2.begin(), nums2.end(), comp);
        vector<int> answer;
        while(start != end){
            if(nums2[start].first + nums2[end].first > target){
                end--;
            }else if(nums2[start].first + nums2[end].first < target){
                start++;
            }else if(nums2[start].first + nums2[end].first == target){
                answer.push_back(nums2[start].second);
                answer.push_back(nums2[end].second);
                break;
            }
        }
        return answer;
    }
};
