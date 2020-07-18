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
            return False
        
        if self.rank[xr] < self.rank[yr]:
            self.p[xr]  = yr
        elif self.rank[xr] > self.rank[yr]:
            self.p[yr] = xr
        elif self.rank[xr] == self.rank[yr]:
            self.p[xr]  = yr
            self.rank[yr] += 1
            
        return True

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        ds = DSet(1001)
        
        for e in edges:
            if not ds.union(e[0], e[1]):
                return e
        
        return []
