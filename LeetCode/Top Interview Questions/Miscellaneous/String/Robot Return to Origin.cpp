class Solution {
public:
    bool judgeCircle(string moves) {
        int sx = 0, sy = 0;
        for(int i = 0; i < (int)moves.size(); i++){
            if(moves[i] == 'R'){
                sx++;
            }else if(moves[i] == 'L'){
                sx--;
            }else if(moves[i] == 'U'){
                sy++;
            }else if(moves[i] == 'D'){
                sy--;
            }
        }
        if(sx == 0 && sy == 0) return true;
        return false;
    }
};
