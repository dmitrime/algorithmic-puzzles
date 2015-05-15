class Solution:

    def reverse(self, x):
        neg = x < 0
        r = str(x)[::-1]
        if neg:
            x = int('-'+r[:-1])
        else:
            x = int(r)

        if -2**31 <= x <= 2**31-1:
            return x
        return 0
