class Solution:
    def simplifyPath(self, path: str) -> str:
        st = []
        for p in path.split('/'):
            if not p or p == '.':
                continue
            elif len(st) > 0 and p == '..':
                st.pop()
            elif p != '..':
                st.append(p)
        
        return '/' + '/'.join(st)
