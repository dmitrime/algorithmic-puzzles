class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        m = dict(zip(range(2, 10), ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" ]))
        res = [[]]
        for d in digits:
            res += [x + [j] for x in res for j in m[int(d)]]
        return [''.join(x) for x in res if len(x) == len(digits)]
