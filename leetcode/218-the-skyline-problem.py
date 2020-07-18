from heapq import *

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for b in buildings:
            start, end, height = b
            events.append([start, -height, end])
            events.append([end, 0, None])
                
        pq = [(0, float('inf'))]
        result = []
        
        for pos, height, end in sorted(events):
            while pos >= pq[0][1]:
                heappop(pq)
            if height != 0:
                heappush(pq, (height, end))
            
            if not result or result[-1][1] != -pq[0][0]:
                result.append([pos, -pq[0][0]])
            
        return result
