class Solution:    
    def ladderLength(self, b: str, e: str, ws: List[str]) -> int:
        ws = set(ws)
        alp = [chr(x) for x in range(ord('a'), ord('z') + 1)]
        q = [(b, 1)]
        while q:
            w, x = q.pop(0)
            if w == e:
                return x
            for i in range(len(w)):
                for a in alp:
                    new = w[:i] + a + w[i+1:]
                    if new in ws:
                        q.append((new, x+1))
                        ws.remove(new)
        return 0
