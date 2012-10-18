m = 0
a = 0
for x in range(1, 1000001):
    n = x
    s = 0
    while n > 1:
        if n % 2 != 0:
            n = 3*n + 1
        else:
            n = n/2
        s = s + 1
    if s > m:
        a = x
        m = s
    #print("i = %d, m = %d" % (x,s))

print("Answer = %d with %d" % (a, m))
