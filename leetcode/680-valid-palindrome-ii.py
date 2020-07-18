class Solution:
    def isPal(self, s):
        return s == s[::-1]
    
    def validPalindrome(self, s: str) -> bool:
        i, j = 0, len(s)-1
        while i < j:
            if s[i] != s[j]:
                return self.isPal(s[i+1:j+1]) or self.isPal(s[i:j])
            i += 1
            j -= 1
        return True
