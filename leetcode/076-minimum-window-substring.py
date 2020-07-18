class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m = defaultdict(int, Counter(t))
        minLen, minStart = float('inf'), 0
        counter = len(t)
        start, end = 0, 0

        while end < len(s):
            # char in s exist in t ?
            if m[s[end]] > 0:
                counter -= 1
            m[s[end]] -= 1 # can get negative

            end += 1
            # found a valid window, move start to minimize it
            while counter == 0:
                # check new minimum
                if end - start < minLen:
                    minLen = end - start
                    minStart = start
                m[s[start]] += 1
                # char in s exists in t?
                if m[s[start]] > 0:
                    counter += 1
                start += 1
                
        if minLen < float('inf'):
            return s[minStart:minStart+minLen]
        return ""
