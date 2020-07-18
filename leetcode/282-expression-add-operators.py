class Solution:
    
    def helper(self, num, idx, t, s, ev, prev, results):
        if idx == len(num):
            if ev == t:
                results.append(s)
        else:
            for i in range(idx, len(num)):
                next = num[idx:i+1]
                if len(next) > 1 and next[0] == '0':
                    break
                n = int(next)
                if idx == 0:
                    self.helper(num, i+1, t, s+next, n, n, results)
                else:
                    self.helper(num, i+1, t, s+'+'+next, ev+n, n, results)
                    self.helper(num, i+1, t, s+'-'+next, ev-n, -n, results)
                    self.helper(num, i+1, t, s+'*'+next, ev-prev+n*prev, n*prev, results)
    
    def addOperators(self, num: str, target: int) -> List[str]:
        if not num:
            return []
        
        results = []
        self.helper(num, 0, target, '', 0, 0, results)
        return results
