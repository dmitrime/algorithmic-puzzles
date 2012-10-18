i = 0
j = 1
while True:
    i = i + j
    div = 2
    to = int(i**0.5)
    for k in range(2, to+1):
        if i%k == 0:
            div = div + 2

    if div > 500:
        break
    print("i = %d, div = %d" % (i,div))

    j = j + 1

print("i = %d" % i)
