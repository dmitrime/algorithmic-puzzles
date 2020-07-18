class Solution:
    def myPow(self, x: float, n: int) -> float:
        isNeg = n < 0
        n = abs(n)
        pow = 1        
        while n > 0:
            if n % 2 == 1:
                pow *= x
            x *= x # 4 (2^2) 16 (2^4) 256 (2^8) ..
            n >>= 1
        return 1./pow if isNeg else pow
