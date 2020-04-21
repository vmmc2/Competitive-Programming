class Solution {
public:
    int dx[4] = {1,-1,0, 0};
    int dy[4] = {0, 0,1,-1};
    bool visited[205][205];
    
    void floodfill(int row, int col, int cursor, string &word, vector<vector<char>> &board, bool &answer, int m, int n){
        visited[row][col] = true;
        if(cursor == (int)word.length() - 1 && board[row][col] == word[cursor]){ //achei a palavra
            answer = true;
            return;
        }
        if(board[row][col] != word[cursor]){ //nao eh a letra q eu estou procurando. desmarco ela e retorno.
            visited[row][col] = false;
            return;
        }
        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] == false){
                floodfill(nrow, ncol, cursor + 1, word, board, answer, m, n);
                if(answer == true) return;
            }
        }
        visited[row][col] = false;
        return;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //conner cases...
        if((int)board.size() == 0) return false;
        if((int)board[0].size() == 0) return false;
        
        //treating the general cases...
        int m = (int)board.size(); //numero de linhas
        int n = (int)board[0].size(); //numero de colunas
        memset(visited, false, sizeof(visited));
        bool answer = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    floodfill(i, j, 0, word, board, answer, m, n);
                    if(answer == true) return answer;
                }
            }
        }
        
        return answer;
    }
};
