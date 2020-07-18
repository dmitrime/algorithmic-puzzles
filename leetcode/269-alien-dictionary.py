class Solution:
    def alienOrder(self, words):
        g = defaultdict(list) # key < [values]
        alp = list(set([c for w in words for c in w]))
        indeg = {c: 0 for c in alp}
        for i in range(len(words)-1):
            w1, w2 = words[i], words[i+1]
            for j in range(min(len(w1), len(w2))):
                if w1[j] != w2[j]:
                    g[w1[j]].append(w2[j])
                    indeg[w2[j]] += 1
                    break
        
        S = [a for a in alp if indeg.get(a, -1) == 0]
        ans = []
        while indeg:
            noLoop = False
            for start in S:
                noLoop = True
                for nei in g[start]:
                    indeg[nei] -= 1 
                ans.append(start)
                del indeg[start]
            if not noLoop:
                return ''
            S = [a for a in alp if indeg.get(a, -1) == 0]
        return ''.join(ans)
