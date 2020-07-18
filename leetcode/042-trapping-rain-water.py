class Solution:
    def trapTLE(self, height: List[int]) -> int:
        def findMin(off):
            m = float('inf')
            for i in range(len(height)):
                if (height[i]-off) > 0:
                    m = min(m, (height[i]-off))
            return m if m < float('inf') else 0
        
        ans = 0
        minh = findMin(0)
        mina = 0
        while minh > 0:
            st = []
            for i in range(len(height)):
                if (height[i]-mina) > 0:
                    if st:
                        ans += minh * (i - st.pop() - 1)
                    st.append(i)
            mina += minh
            minh = findMin(mina)
        
        return ans
    
    def trap(self, height):
        ans = 0
        st = []
        i = 0
        while i < len(height):
            if not st or height[i] < height[st[-1]]:
                st.append(i)
                i += 1
            else:
                prev = st.pop()
                if st:
                    minh = min(height[i], height[st[-1]])
                    ans += (minh - height[prev]) * (i - st[-1] - 1)
        return ans
