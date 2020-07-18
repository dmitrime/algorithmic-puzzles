class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        st = []
        for n in num:
            while k and st and st[-1] > n:
                st.pop()
                k -= 1
            st.append(n)
        
        for _ in range(k):
            st.pop()

        ret = ''.join(st).lstrip('0')
        return ret if ret else "0"
