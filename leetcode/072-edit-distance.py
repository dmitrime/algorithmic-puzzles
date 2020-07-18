class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        N, M = len(word1), len(word2)
        tab = [[0]*(N+1) for _ in range(M+1)]
        
        for i in range(N+1):
            tab[0][i] = i
        for j in range(M+1):
            tab[j][0] = j
        
        for i in range(1, M+1):
            for j in range(1, N+1):
                if word1[j-1] != word2[i-1]:
                    tab[i][j] = min(tab[i-1][j], tab[i][j-1], tab[i-1][j-1]) + 1
                    print(word1[j-1], word2[i-1], tab[i][j])
                else:
                    tab[i][j] = tab[i-1][j-1]
        return tab[M][N]
