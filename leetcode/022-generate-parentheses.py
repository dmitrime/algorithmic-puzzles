class Solution:
    def helper(self, s, n, open, close, result):
        if len(s) == 2*n:
            result.append(s)
        else:
            if open < n:
                self.helper(s + '(', n, open+1, close, result)
            if close < open:
                self.helper(s + ')', n, open, close+1, result)

    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.helper('', n, 0, 0, result)
        return result
