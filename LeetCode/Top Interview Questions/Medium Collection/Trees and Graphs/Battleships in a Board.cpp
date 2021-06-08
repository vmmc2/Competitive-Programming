class Solution {
public:
    int dx[4] = {1, -1, 0,  0};
    int dy[4] = {0,  0, 1, -1};
    
    void floodfill(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &visited, int m, int n){
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n && board[newx][newy] == 'X' && visited[newx][newy] == false){
                floodfill(newx, newy, board, visited, m, n);
            }
        }
        
        return;
    }
    int countBattleships(vector<vector<char>>& board) {
        int answer = 0;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X' && visited[i][j] == false){
                    answer++;
                    floodfill(i, j, board, visited, m, n);
                }
            }
        }
        
        return answer;
    }
};
