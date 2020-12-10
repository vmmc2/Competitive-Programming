class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //Solucao mais idiota possivel. Sorting
        vector<pair<int,int>> v;
        for(int i = 0; i < (int)nums.size(); i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        bool found = false;
        for(int i = 0; i < (int)nums.size() - 1; i++){
            if(v[i].first == v[i + 1].first){
                if(abs(v[i].second - v[i + 1].second) <= k){
                    found = true;
                    break;
                }
            }
        }
        return found;
    }
};
