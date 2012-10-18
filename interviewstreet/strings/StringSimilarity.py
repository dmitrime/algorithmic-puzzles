'''
Created on 18.07.2012

@author: dmitri
'''

N = int(raw_input())
while N > 0:
    N -= 1
    s = raw_input()
    ls = len(s)
    counter = ls
    for i in xrange(1, ls):
        start = 0
        for j in xrange(i, ls):
            if s[j] == s[start]:
                counter += 1
                start += 1
            else:
                break 
    print(counter)
