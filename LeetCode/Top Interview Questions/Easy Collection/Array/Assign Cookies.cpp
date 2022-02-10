class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int answer = 0;
        int currg = 0, currs = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(currg < (int)g.size() && currs < (int)s.size()){
            if(g[currg] > s[currs]){
                currs++;
            }else{
                answer++;
                currg++;
                currs++;
            }
        }
        
        return answer;
    }
};
