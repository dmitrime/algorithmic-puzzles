class DSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1]*n
        
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        xp = self.find(x)
        yp = self.find(y)

        
        if self.rank[xp] < self.rank[yp]:
            self.parent[xp] = yp
        elif self.rank[xp] > self.rank[yp]:
            self.parent[yp] = xp
        else:
            self.parent[xp] = yp
            self.rank[yp] += 1
            

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        ds = DSet(10001)
        mp, ep = {}, {}
        mails = 0
        for l in accounts:
            name, emails = l[0], l[1:]
            for e in emails:
                ep[e] = name
                if e not in mp:
                    mp[e] = mails
                    mails += 1
                ds.union(mp[l[1]], mp[e])
        
        out = collections.defaultdict(list)
        for e in ep:
            out[ds.find(mp[e])].append(e)
        return [[ep[v[0]]] + sorted(v) for k,v in out.items()]
        
