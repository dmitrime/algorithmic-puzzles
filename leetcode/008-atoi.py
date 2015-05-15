class Solution:
    def myAtoi(self, str):
        s = str.strip()
        if len(s) == 0:
            return 0
            
        neg = False
        if s[0] == '-':
            neg = True
            s = s[1:]
        elif s[0] == '+':
            s = s[1:]
        i = 0
        while i < len(s) and s[i].isdigit():
            i += 1
        s = s[:i]
        
        x, mul = 0, 1
        for i in range(len(s)-1, -1, -1):
            x += int(s[i]) * mul
            mul *= 10
            
        if neg:
            x *= -1
            if x < -2**31:
                return -2**31
            return x
        else:
            if x > 2**31-1:
                return 2**31-1
            return x
