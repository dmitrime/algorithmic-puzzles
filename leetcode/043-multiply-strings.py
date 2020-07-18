class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1, n2 = len(num1), len(num2)
        res = [0] * (n1+n2+1)
        
        pos = len(res)-1
        
        for i in num1[::-1]:
            for off, j in enumerate(num2[::-1]):
                res[pos-off] += int(i)*int(j)
                res[pos-1-off] += res[pos-off] // 10
                res[pos-off] %= 10
            pos -= 1
        
        res = ''.join([str(x) for x in res]).lstrip('0')
        return '0' if not res else res
