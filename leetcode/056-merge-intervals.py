class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        result = []
        
        for v in intervals:
            if not result or result[-1][1] < v[0]:
                result.append(v)
            else:
                p = result.pop()
                result.append([p[0], max(v[1], p[1])])
        return result
