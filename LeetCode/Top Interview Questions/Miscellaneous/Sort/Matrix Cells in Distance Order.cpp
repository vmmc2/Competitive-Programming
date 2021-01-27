class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> answer;
        vector<vector<int>> visited(R, vector<int>(C, 0));
        int dx[4] = {1, -1, 0, 0 };
        int dy[4] = {0, 0, 1, -1};
        
        queue<pair<int,int>> fila;
        fila.push({r0,c0});
        while(!fila.empty()){
            pair<int,int> curr = fila.front();
            visited[curr.first][curr.second] = 1;
            fila.pop();
            vector<int> cc(2);
            cc[0] = curr.first;
            cc[1] = curr.second;
            answer.push_back(cc);
            for(int i = 0; i < 4; i++){
                int newR = curr.first + dx[i];
                int newC = curr.second + dy[i];
                if(newR >= 0 && newR < R && newC >= 0 && newC < C && visited[newR][newC] == 0){
                    visited[newR][newC] = 1;
                    fila.push({newR, newC});
                }
            }
        }
        return answer;
    }
};
