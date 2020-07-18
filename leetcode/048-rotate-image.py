class Solution:
    def rotate(self, m: List[List[int]]) -> None:
        N = len(m)
        m.reverse()
        for i in range(N):
            for j in range(i+1, N):
                m[i][j], m[j][i] = m[j][i], m[i][j]

