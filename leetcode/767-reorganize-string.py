class Solution:
    def reorganizeString(self, S: str) -> str:
        ct = collections.Counter(S)
        N = len(S)
        ans = [None] * N
        
        ct = sorted(ct.items(), key=lambda x: x[1], reverse=True)
        t = 0
        for k, v in ct:
            if v > (N+1) / 2:
                return ""
            else:
                for i in range(v):
                    ans[t % N] = k
                    t += 2
                    if (t == N): t += 1
        
        return "".join(ans)
