class Solution:
    def isValid(self, s):
        count = 0
        for x in s:
            if x == '(': count += 1
            if x == ')':
                if count > 0: count -= 1
                else: return False
        return count == 0
        
    def removeInvalidParentheses(self, s: str) -> List[str]:        
        result = []
        q = [(s,0)]
        seen = dict()
        while q:
            sol, idx = q.pop(0)
            seen[sol] = True
            if self.isValid(sol):
                result.append(sol)
            elif not result:
                for i in range(idx, len(sol)):
                    if sol[i] != '(' and sol[i] != ')':
                        continue
                    if i == idx or sol[i] != sol[i-1]:
                        x = sol[:i] + sol[i+1:]
                        if x not in seen:
                            q.append((x, i))
        return result
