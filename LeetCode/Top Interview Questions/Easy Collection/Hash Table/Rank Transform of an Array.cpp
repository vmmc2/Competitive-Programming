class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> rank;
        vector<int> sortedArr = arr;
        int currRank = 1;
        
        sort(sortedArr.begin(), sortedArr.end());
        for(int i = 0; i < (int)sortedArr.size(); i++){
            if(rank.find(sortedArr[i]) == rank.end()){
                rank[sortedArr[i]] = currRank;
                currRank++;
            }
        }
        for(int i = 0; i < (int)arr.size(); i++){
            arr[i] = rank[arr[i]];
        }
        
        return arr;
    }
};
