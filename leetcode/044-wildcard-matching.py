class Solution:
    def replaceAllStars(self, pat):
        prev, p = 0, ''
        for x in pat:
            if not (prev == '*' and x == '*'):
                p = p + x
            prev = x
        return p
    
    def isMatch(self, s: str, p: str) -> bool:
        p = self.replaceAllStars(p)
        Ns, Np = len(s), len(p)
        
        tab = [[False] * (Np+1) for _ in range(Ns+1)]
        tab[0][0] = True
        if Np > 0 and p[0] == '*':
            tab[0][1] = True
        
        for i in range(1, Ns+1):
            for j in range(1, Np+1):
                if p[j-1] == '*':
                    tab[i][j] = tab[i-1][j] or tab[i][j-1]
                elif p[j-1] == '?' or p[j-1] == s[i-1]:
                    tab[i][j] = tab[i-1][j-1]
        return tab[Ns][Np]
