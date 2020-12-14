class Solution {
public:
    long int calcDet(int x0, int y0, int x1, int y1, int x2, int y2){
        long int pt1 = (x0*y1 + x2*y0 + x1*y2)*1L;
        long int pt2 = (x2*y1 + x0*y2 + x1*y0)*1L;
        long int answer = pt1 - pt2;
        return answer;
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool answer = true;
        if((int)coordinates.size() == 2) return answer;
        
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        for(int i = 2; i < (int)coordinates.size(); i++){
            int x2 = coordinates[i][0];
            int y2 = coordinates[i][1];
            if(calcDet(x0, y0, x1, y1, x2, y2) != 0){
                answer = false;
                break;
            }
        }
        return answer;
    }
};
