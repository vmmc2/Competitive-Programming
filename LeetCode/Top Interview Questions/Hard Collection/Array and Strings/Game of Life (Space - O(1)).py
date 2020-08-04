class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # This version will have a space-complexity of O(1) instead of O(m*n)
        # Se uma celula que era viva (1) morrer, eu transformo ela em -1.
        # Se uma celula que era morta (0) nascer, eu transformo ela em 2
        m = len(board)
        n = len(board[0])
        
        dx = [-1,-1,-1,0,1,1, 1, 0]
        dy = [-1, 0, 1,1,1,0,-1,-1]
        
        for i in range(0, m):
            for j in range(0, n):
                neighbours = 0
                for k in range(0, 8):
                    newx = i + dx[k]
                    newy = j + dy[k]
                    if newx >= 0 and newx < m and newy >= 0 and newy < n:
                        if board[newx][newy] == -1: # Tenho uma celula viva mas que na proxima geracao vai morrer.
                            neighbours += 1
                        elif board[newx][newy] == 1: # Celula viva.
                            neighbours += 1 
                if board[i][j] == 0:
                    if neighbours == 3:
                        board[i][j] = 2
                elif board[i][j] == 1:
                    if neighbours < 2:
                        board[i][j] = -1
                    elif neighbours == 2 or neighbours == 3:
                        board[i][j] = 1
                    else:
                        board[i][j] = -1
        for i in range(0, m):
            for j in range(0, n):
                if board[i][j] == -1:
                    board[i][j] = 0
                elif board[i][j] == 2:
                    board[i][j] = 1
        return
