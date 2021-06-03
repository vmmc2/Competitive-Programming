class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int answer = -1;
        vector<pair<int,int>> pp((int)points.size());
        for(int i = 0; i < (int)points.size(); i++){
            pp[i].first = points[i][0];
            pp[i].second = points[i][1];
        }
        sort(pp.begin(), pp.end());
        
        for(int i = 1; i < points.size(); i++){
            answer = max(answer, pp[i].first - pp[i - 1].first);
        }
        
        return answer;
    }
};
