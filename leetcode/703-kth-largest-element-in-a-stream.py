from heapq import *

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.h = nums
        self.k = k
        heapify(self.h)
        for _ in range(len(nums) - k):
            heappop(self.h)

    def add(self, val: int) -> int:
        if len(self.h) < self.k:
            heappush(self.h, val)
        else:
            heappushpop(self.h, val)
        return self.h[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
