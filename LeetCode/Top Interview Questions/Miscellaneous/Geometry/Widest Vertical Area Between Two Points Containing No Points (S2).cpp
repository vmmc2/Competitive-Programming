class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int answer = 0;
        map<int,int> xp;
        for(int i = 0; i < (int)points.size(); i++){
            xp[points[i][0]]++;
        }
        int prev = -1;
        for(map<int,int>::iterator it = xp.begin(); it != xp.end(); it++){
            if(prev == -1){
                prev = it->first;
            }else{
                answer = max(answer, it->first - prev);
                prev = it->first;
            }
        }
        
        return answer;
    }
};
