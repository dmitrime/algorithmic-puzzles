class Solution:
    def helper(self, n):
        if n < 0:
            return []
        if n == 0:
            return ["0"]
        if n == 1:
            return ["0", "1"]
        prev = self.helper(n-1)
        return ["0" + p for p in prev] + ["1" + r for r in prev[::-1]]
    
    def grayCodeX(self, n: int) -> List[int]:
        def toInt(s):
            n, two = 0, 1
            for i in range(len(s)-1, -1, -1):
                n += two*int(s[i])
                two <<= 1
            return n
        return [toInt(x) for x in self.helper(n)]
    
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        begin = [0, 1]
        for i in range(1, n):
            add = [x | (1 << i) for x in reversed(begin)]
            begin += add
        return begin
