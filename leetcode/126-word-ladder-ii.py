class Solution:
    def findLadders(self, b: str, e: str, ws: List[str]) -> List[List[str]]:
        alp = [chr(x) for x in range(ord('a'), ord('z') + 1)]
        ws = set(ws)
        row = {b: [[b]]}
        
        while row:
            newrow = defaultdict(list)
            
            for w in row:
                if w == e:
                    return row[w]
                else:
                    for i in range(len(w)):
                        for a in alp:
                            nw = w[:i] + a + w[i+1:]
                            if nw in ws:
                                newrow[nw] += [j+[nw] for j in row[w]]
            
            ws -= set(newrow.keys())
            row = newrow
