class Solution:
    def cycle(self, G, seen, start, rec):
        seen[start] = True
        rec[start] = True
        
        for nei in G[start]:
            if not seen[nei]:
                if self.cycle(G, seen, nei, rec):
                    return True
            elif rec[nei]:
                return True

        rec[start] = False
        return False
               
    def canFinish(self, N: int, reqs: List[List[int]]) -> bool:
        seen = [False] * N
        rec = [False] * N
        G = defaultdict(list)
        for r in reqs:
            G[r[1]].append(r[0])
        
        for start in list(G):
            if not seen[start]:
                if self.cycle(G, seen, start, rec):
                    return False
        return True
