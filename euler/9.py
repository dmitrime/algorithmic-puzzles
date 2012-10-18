for a in range(1, 1000):
    for b in range(1, 1000):
        c = 1000 - a - b
        if a < b and b < c and c*c == a*a + b*b:
            print("a = %d, b = %d, c = %d, p = %d" %(a,b,c,
                                                     (a*b*c)))
