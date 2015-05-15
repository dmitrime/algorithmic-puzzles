class Solution:
    def isPalindrome(self, x):
        s = str(x)
        for i in range(len(s) / 2):
            if s[i] != s[len(s)-1-i]:
                return False
        return True
