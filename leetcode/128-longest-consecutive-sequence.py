class DSet:
    def __init__(self, N):
        self.tab = list(range(N))
        self.rank = [1] * N
        self.topElem = 1
        self.elems = [1] * N
        
    def find(self, x):
        if x != self.tab[x]:
            self.tab[x] = self.find(self.tab[x])
        return self.tab[x]
    
    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        
        if xr == yr:
            return
        
        if self.rank[xr] < self.rank[yr]:
            self.tab[xr] = yr
        elif self.rank[yr] < self.rank[xr]:
            self.tab[yr] = xr
        else:
            self.tab[xr] = yr
            self.rank[yr] += 1
        
        total = self.elems[xr] + self.elems[yr]
        self.elems[xr] = self.elems[yr] = total
        self.topElem = max(self.topElem, total)

class Solution:
    
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        ds = DSet(len(nums))
        m = {}
        for i in range(len(nums)):
            n = nums[i]
            if n in m:
                continue
            if n-1 in m:
                ds.union(i, m[n-1])
            if n+1 in m:
                ds.union(i, m[n+1])
            m[n] = i
            
        return ds.topElem
            
        
        
        
        
