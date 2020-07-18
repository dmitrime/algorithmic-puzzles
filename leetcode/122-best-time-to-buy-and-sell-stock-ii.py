class Solution:
    def maxProfit(self, p: List[int]) -> int:
        return sum([max(0, p[i+1] - p[i]) for i in range(len(p)-1)])
        
