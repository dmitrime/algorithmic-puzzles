class Solution:
    def insert(self, ints: List[List[int]], new: List[int]) -> List[List[int]]:
        i = 0
        while i < len(ints) and new[0] > ints[i][1]:
            i += 1
        
        while i < len(ints) and ints[i][0] <= new[1]:
            new = [min(new[0], ints[i][0]), max(new[1], ints[i][1])]
            ints.pop(i)

        ints.insert(i, new)
        return ints
