class Solution:
    def longestValidParentheses(self, s: str) -> List[str]:        
        ans = 0
        st = [-1]
        for i in range(len(s)):
            if s[i] == ')' and len(st) > 1 and s[st[-1]] == '(':
                st.pop()
                ans = max(ans, i - st[-1])
            else:
                st.append(i)
        return ans
