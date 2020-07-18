class DSet:
    def __init__(self, n):
        self.p = list(range(n))
        self.rank = [1]*n
    
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        
        if xr == yr:
            return
        
        if self.rank[xr] < self.rank[yr]:
            self.p[xr] = yr
        elif self.rank[xr] > self.rank[yr]:
            self.p[yr] = xr
        else:
            self.p[xr] = yr
            self.rank[yr] += 1

class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        ds = DSet(n)
        
        for i in range(n):
            for j in range(i+1, len(M[i])):
                if M[i][j] == 1:
                    ds.union(i, j)
        
        uniq = set()
        for i in range(n):
            uniq.add(ds.find(i))
        
        return len(uniq)
