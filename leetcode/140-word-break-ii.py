class Solution:
    def __init__(self):
        self.cache = dict()
        
    def canUse(self, s, words):
        for i in range(len(s)):
            if s[i:] in words:
                return True
        return False
    
    def wordBreak(self, s: str, words: List[str]) -> List[str]:
        return self._wordBreak(s, set(words))
    
    def _wordBreak(self, s, words):
        if s in self.cache:
            return self.cache[s]
        
        result = []
        if s in words:
            result.append(s)
        
        for i in range(1, len(s)):
            pref, suf = s[:i], s[i:]
            if pref in words and self.canUse(suf, words):
                ws = self._wordBreak(suf, words)
                result.extend([pref + ' ' + w for w in ws])

        self.cache[s] = result
        return result
