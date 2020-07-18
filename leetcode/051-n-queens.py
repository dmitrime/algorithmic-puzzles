class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        self.helper(n, 0, [], result)
        ans = self.display(n, result)
        for a in ans:
            for r in a:
                print(r)
            print()
        return ans
    
    def display(self, n, results):
        answer = []
        for sol in results:
            s = []
            for q in sol:
                s.append(['.']*n)
                s[-1][q[1]] = 'Q'
                s[-1] = ''.join(s[-1])
            answer.append(s)
        return answer
    
    def validPos(self, pos, q):
        y, x = pos
        qy, qx = q
        return x != qx and y-x != qy-qx and y+x != qy+qx
    
    def helper(self, n, row, queens, result):
        if n == row:
            result.append([q for q in queens])
            return
        
        for col in range(n):
            isValid = True
            for q in queens:
                if not self.validPos((row, col), q):
                    isValid = False
                    break
            
            if isValid:
                queens.append((row, col))
                self.helper(n, row+1, queens, result)
                queens.pop()
