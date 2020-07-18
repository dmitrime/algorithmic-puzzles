from heapq import *

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        time, h = 0, []
        for _, c in Counter(tasks).items():
            heappush(h, -c)
        while h:
            i, newh = 0, []
            while i <= n:
                time += 1
                if h:
                    el = heappop(h)
                    if el < -1: newh.append(el + 1)
                if not h and not newh:
                    break
                else:
                    i += 1
            for c in newh:
                heappush(h, c)
        return time
