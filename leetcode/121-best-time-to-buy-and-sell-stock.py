class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prof = 0
        minp = float('inf')
        for p in prices:
            minp = min(p, minp)
            prof = max(prof, p-minp)
            
        return prof
