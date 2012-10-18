'''
Created on 19.07.2012

@author: dmitri
'''
#import random

substitutes = {"ab":"c", "ac":"b", "bc": "a", "ba":"c", "ca":"b",
               "cb": "a", "aa":"aa", "bb":"bb", "cc":"cc"}
reduction = {}
def sub(s):
    if s[0] == s[1]:
        return s
    else:
        return substitutes[s]
    
def reduced(s):
    if s in reduction:
        return reduction[s]
    t = s
    change = True
    while change:
        change = False
        for j in xrange(0, len(t)-1):
            if len(sub(t[j:j+2])) < 2:
                t = t[:j] + sub(t[j:j+2]) + t[j+2:]
                change = True
                break
    reduction[s] = t
    return reduction[s]
    
def solve(s):
    ls = len(s)
    dp = [['' for _ in xrange(ls)] for _ in xrange(ls)]
    for i in xrange(ls):
        dp[i][i] = s[i]
    for L in xrange(2, ls+1):
        for i in xrange(ls-L+1):
            j = i+L-1
            dp[i][j] = s
            for k in xrange(i, j):
                t = reduced(dp[i][k] + dp[k+1][j])
                if len(t) < len(dp[i][j]):
                    dp[i][j] = t
    #print(dp[0][-1])
    return len(dp[0][-1])

#def gen():
#    abc = ["a", "b", "c"]
#    ln = random.randint(1, 100)
#    return "".join([abc[random.randint(0,2)] for x in xrange(ln)])

N = int(raw_input())
#N = 100
while N > 0:
    N -= 1
    s = raw_input()
    #s = gen()
    print(solve(s))
