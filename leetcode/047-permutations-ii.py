class Solution:
    def helper(self, idx, N, count, res, results):
        if idx == N:
            results.append([r for r in res])
        else:
            for ch in count:
                if count[ch]:
                    count[ch] -= 1
                    res[idx] = ch
                    self.helper(idx+1, N, count, res, results)
                    count[ch] += 1
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        count = Counter(nums)
        results = []
        self.helper(0, len(nums), count, [0]*len(nums), results)
        return results
