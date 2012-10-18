'''
Created on 21.07.2012

@author: dmitri
'''

def solve3(K, s1, s2):
    l1 = len(s1)
    mx = 0
    for k in range(1,l1+1):
        one, two = [], []
        for i in range(l1-k+1):
            one.append(s1[i:i+k])
            two.append(s2[i:i+k])
        one = sorted(one)
        two = sorted(two)
        for i in range(len(one)):
            
    return mx

def subseq(seq, K):
    l1 = len(seq)
    mx = 0
    for i in xrange(l1):
        j = i
        k = K
        while j < l1:
            if seq[j] == 0 and k == 0:
                break
            else:
                if seq[j] == 0: 
                    k -= 1
                j += 1
        mx = max(mx, j-i)
    return mx

def solve2(K, s1, s2):
    l1 = len(s1)
    M = [ [ 0 for _ in xrange(l1)] for _ in xrange(l1)]
    for i in xrange(l1):
        for j in xrange(l1):
            if s1[i] == s2[j]:
                M[i][j] = 1
    diag = []
    mx = 0
    for i in xrange(l1):
        diag1,diag2 = [], []
        for j in xrange(l1-i):
            diag1.append(M[i+j][j])
            diag2.append(M[j][i+j])
            
        if (sum(diag1)+len(diag1) > mx):
            mx = sum(diag1)+len(diag1)
            diag = diag1
            
        if (sum(diag2)+len(diag2) > mx):
            mx = sum(diag2)+len(diag2)
            diag = diag1
            
    res = subseq(diag, K)
    return res

def solve(K, s1, s2):
    l1 = len(s1)
    M = [ [ 0 for _ in xrange(l1)] for _ in xrange(l1)]
    for i in xrange(l1):
        for j in xrange(l1):
            if s1[i] != s2[j]:
                M[i][j] = 1
    res = 0
    for k in xrange(2, l1+1):
        for i in xrange(l1-k+1):
            for j in xrange(l1-k+1):
                if s1[i+k-1] != s2[j+k-1]:
                    M[i][j] += 1
                if M[i][j] <= K:
                    res = max(res, k)
    return res
  
N = int(raw_input())
while N > 0:
    N -= 1
    s = raw_input().split()
    K, s1, s2 = int(s[0]), s[1], s[2]
    print(solve3(K,s1,s2))