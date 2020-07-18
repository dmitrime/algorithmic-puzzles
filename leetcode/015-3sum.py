class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        N = len(nums)
        for i in range(N):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            t = -nums[i]
            s, e = i+1, N-1
            while s < e:
                if nums[s] + nums[e] == t:
                    res.append([nums[i], nums[s], nums[e]])
                    s += 1
                    while s < e and nums[s] == nums[s-1]:
                        s += 1
                    e -= 1
                    while s < e and nums[e] == nums[e+1]:
                        e -= 1
                elif nums[s] + nums[e] < t:
                    s += 1
                else:
                    e -= 1
        return list(res)
