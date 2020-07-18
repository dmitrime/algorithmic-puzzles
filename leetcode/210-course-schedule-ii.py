class Solution:             
    def findOrder(self, N: int, reqs: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        for r in reqs:
            g[r[1]].append(r[0])
            
        seen = defaultdict(int)
        
        def topSort(start):
            if seen[start] == 1:
                return False
            if seen[start] == 2:
                return True
            
            seen[start] = 1
            ret = True
            for v in g[start]:
                if not topSort(v):
                    return False
            result.insert(0, start)
            seen[start] = 2
            return True
        
        result = []
        for start in range(N):
            if seen[start] == 0:
                if not topSort(start):
                    return []
        return result
