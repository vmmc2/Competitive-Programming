class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groupThePeople;
        vector<pair<int,int>> gp;
        for(int i = 0; i < (int)groupSizes.size(); i++){
            gp.push_back({groupSizes[i], i});
        }
        sort(gp.begin(), gp.end());
        vector<int> curr;
        for(int i = 0; i < (int)gp.size(); i++){
            curr.push_back(gp[i].second);
            
            if(curr.size() == gp[i].first){
                groupThePeople.push_back(curr);
                curr.clear();
            }
        }
        return groupThePeople;
    }
};
