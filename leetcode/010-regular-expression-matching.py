class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        Ns, Np = len(s), len(p)
        tab = [[False] * (Np+1) for _ in range(Ns+1)]
        
        tab[0][0] = True
        for j in range(1, Np+1):
            if p[j-1] == '*':
                tab[0][j] = tab[0][j-2]
        
        for i in range(1, Ns+1):
            for j in range(1, Np+1):
                if p[j-1] == '*':
                    tab[i][j] = tab[i][j-2]
                    if p[j-2] == s[i-1] or p[j-2] == '.':
                        tab[i][j] |= tab[i-1][j]
                elif p[j-1] == '.' or p[j-1] == s[i-1]:
                    tab[i][j] = tab[i-1][j-1]
        return tab[Ns][Np]
