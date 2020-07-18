class Solution:
    def numDecodings(self, s: str) -> int:
        N = len(s)
        tab = [1] + [0] * N
        for i in range(1, N+1):
            a = int(s[i-1])
            b = -1 if i == 1 else int(s[i-2:i])
            
            if 1 <= a <= 9:
                tab[i] += tab[i-1]
            if b != -1 and 10 <= b <= 26:
                tab[i] += tab[i-2]
                    
        return tab[N]
