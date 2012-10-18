p = 600851475143
sr = int(p**0.5) + 1
m = 0
a = [2]

for i in range(3, sr, 2):
    for j in a:
        if i % j == 0:
            break
    else:
        a.append(i)
        if p % i == 0:
            p = p / i
            m = max(m, i)
            print("Factor %d, p = %d" % (i,p))
    if p == 1:
        break

print("Answer = %d" % m)

