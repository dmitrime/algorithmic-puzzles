class Solution:
    def dfs(self, x, y, b, w, idx):
        if idx == len(w):
            return True
        if x >= 0 and x < len(b) and y >= 0 and y < len(b[0]) and b[x][y] == w[idx]:
            b[x][y] = '#'
            res = self.dfs(x+1, y, b, w, idx+1) or \
                  self.dfs(x, y+1, b, w, idx+1) or \
                  self.dfs(x-1, y, b, w, idx+1) or \
                  self.dfs(x, y-1, b, w, idx+1)
            b[x][y] = w[idx]
            return res
        return False
        
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not word:
            return False
        
        N, M = len(board), len(board[0])
        for i in range(N):
            for j in range(M):
                if board[i][j] == word[0]:
                    if self.dfs(i, j, board, word, 0):
                        return True
        return False
