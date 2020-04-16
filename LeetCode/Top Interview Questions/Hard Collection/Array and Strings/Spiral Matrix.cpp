class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        //first we have to treat the conner cases...
        if((int)matrix.size() == 0) return answer;
        if((int)matrix[0].size() == 0) return answer;
        int m = (int)matrix.size(); //number of rows.
        int n = (int)matrix[0].size(); //number of columns.
        bool visited[m][n];
        memset(visited, false, sizeof(visited));
        int dr[4] = {0,1, 0,-1};
        int dc[4] = {1,0,-1, 0};
        int r = 0;
        int c = 0;
        int di = 0;
        for(int i = 0; i < m*n; i++){
            answer.push_back(matrix[r][c]);
            visited[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            if(cr >= 0 && cr < m && cc >= 0 && cc < n && visited[cr][cc] == false){
                r = cr;
                c = cc;
            }else{
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        return answer;
    }
};
