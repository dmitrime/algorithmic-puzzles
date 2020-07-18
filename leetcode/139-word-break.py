class Solution:
    def wordBreak(self, s: str, words: List[str]) -> bool:
        tab = [True] + [False]*len(s)
        
        for i in range(1, len(s)+1):
            pref = s[:i]
            for w in words:
                if pref.endswith(w):
                    tab[i] = tab[i] or tab[i-len(w)]
                    
        return tab[-1]
