class Solution {
public:
    bool isPathCrossing(string path) {
        bool pathCrossed = false;
        pair<int,int> curr = make_pair(0,0);
        set<pair<int,int>> positions;
        
        positions.insert(curr);
        for(auto ch : path){
            if(ch == 'N'){
                curr.second++;
            }else if(ch == 'S'){
                curr.second--;
            }else if(ch == 'E'){
                curr.first++;
            }else{
                curr.first--;
            }
            if(positions.find(curr) != positions.end()){
                pathCrossed = true;
                break;
            }else{
                positions.insert(curr);
            }
        }
        
        return pathCrossed;
    }
};
