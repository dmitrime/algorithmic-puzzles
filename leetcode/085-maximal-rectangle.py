class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        
        ans = 0
        cols = len(matrix[0])
        height = [0] * (cols+1)
        for row in matrix:
            for i in range(cols):
                height[i] = height[i] + 1 if row[i] == '1' else 0
            print(height)
            
            stack = [-1]
            for i in range(cols+1):
                while height[i] < height[stack[-1]]:
                    h = height[stack.pop()]
                    w = i-stack[-1]-1
                    ans = max(ans, h*w)
                stack.append(i)
                print()
        
        return ans
