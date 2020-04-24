class Solution {
public:
    bool visited[300][300];
    int dx[4] = {1,-1,0, 0};
    int dy[4] = {0, 0,1,-1};
    //The "floodfill" function receives a parameter called flag which is going to decide whether we must replace
    //the 'O' with an 'A' or with a 'X'.
    //flag = 0 -> put an 'A'.
    //flag = 1 -> put a 'X'.
    void floodfill(int row, int col, vector<vector<char>> &board, int flag, int m, int n){
        visited[row][col] = true;
        if(flag == 0){
            board[row][col] = 'A';
        }else{
            board[row][col] = 'X';
        }
        for(int i = 0; i < 4; i++){
            int newr = row + dx[i];
            int newc = col + dy[i];
            if(newr >= 0 && newr < m && newc >= 0 && newc < n && board[newr][newc] == 'O' && visited[newr][newc] == false){
               floodfill(newr, newc, board, flag, m, n); 
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        //treating the corner cases
        if((int)board.size() == 0) return;
        if((int)board[0].size() == 0) return;
        
        //now treating the general cases...
        memset(visited, false, sizeof(visited));
        //here is what I am going to do: I am going to iterate through each cell that is on any border of the
        //grid. If I find one cell that contains an 'O' then I will do a floodfill algorithm changing each of
        //these cells to an 'A' and also marking than as visited
        int m = (int)board.size(); //number of lines.
        int n = (int)board[0].size(); //number of columns.
        //Iterating at each border...
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O' && visited[0][i] == false){
                floodfill(0, i, board, 0, m, n);
            }
        }
        for(int i = 0; i < n; i++){
            if(board[m - 1][i] == 'O' && visited[m - 1][i] == false){
                floodfill(m - 1, i, board, 0, m, n);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && visited[i][0] == false){
                floodfill(i, 0, board, 0, m, n);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[i][n - 1] == 'O' && visited[i][n - 1] == false){
                floodfill(i, n - 1, board, 0, m, n);
            }
        }
        //Iterating at the space left...
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(board[i][j] == 'O' && visited[i][j] == false){
                    floodfill(i, j, board, 1, m, n);
                }
            }
        }
        //final traversal.. changing from 'A' to 'O'
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};
