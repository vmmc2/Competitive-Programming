class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        copy = [[0 for i in range(0, n)] for j in range(0, m)]
        
        dx = [-1,-1,-1,0,1,1, 1, 0]
        dy = [-1, 0, 1,1,1,0,-1,-1]
        
        for i in range(0, m):
            for j in range(0, n):
                neighbours = 0
                for k in range(0, 8):
                    newx = i + dx[k]
                    newy = j + dy[k]
                    if newx >= 0 and newx < m and newy >= 0 and newy < n:
                        neighbours += board[newx][newy]
                if board[i][j] == 0:
                    if neighbours == 3:
                        copy[i][j] = 1
                    else:
                        copy[i][j] = 0
                elif board[i][j] == 1:
                    if neighbours < 2:
                        copy[i][j] = 0
                    elif neighbours == 2 or neighbours == 3:
                        copy[i][j] = 1
                    else:
                        copy[i][j] = 0
        for i in range(0, m):
            for j in range(0, n):
                board[i][j] = copy[i][j]
        return
                    
                
        
