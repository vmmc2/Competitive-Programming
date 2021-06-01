class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groupThePeople;
        map<int,vector<int>> group;
        
        for(int i = 0; i < (int)groupSizes.size(); i++){
            group[groupSizes[i]].push_back(i);
        }
        for(map<int,vector<int>>::iterator it = group.begin(); it != group.end(); it++){
            vector<int> indexes = it->second;
            vector<int> curr;
            for(int i = 0; i < indexes.size(); i++){
                curr.push_back(indexes[i]);
                if(curr.size() == it->first){
                    groupThePeople.push_back(curr);
                    curr.clear();
                }
            }
        }
        return groupThePeople;
    }
};
