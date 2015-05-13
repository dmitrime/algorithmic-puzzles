class Solution:

    def lengthOfLongestSubstring(self, s):
        start, longest = 0, 0
        chars = set()
        pos = [-1]*128
        for i, c in enumerate(s):
            c = ord(c)
            if c in chars:
                before_c = [ord(x) for x in s[start:pos[c]+1]]
                chars = chars.difference(set(before_c))
                start = pos[c]+1
            chars.add(c)
            pos[c] = i
            longest = max(longest, len(chars))

        return longest

        
if __name__ == '__main__':
    print Solution().lengthOfLongestSubstring('pwwkew')
