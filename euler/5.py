p = 2520
r = [x for x in range(3,21)]

for i in range(p,2432902008176640002,2):
    for x in r:
        if i%x != 0:
            break
    else:
        print(i)
        break



