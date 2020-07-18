class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        stack = [0]
        ans = heights[0]
        for i in range(1, len(heights)):
            while len(stack) > 0 and heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i if len(stack) == 0 else i-stack[-1]-1
                ans = max(ans, h*w)
            stack.append(i)
            
        return ans
