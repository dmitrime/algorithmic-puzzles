sr = 2000000
a = [2]
sum = 2

for i in range(3, sr, 2):
    for j in range(3, 1+int(i**0.5), 2):
        if i % j == 0:
            break
    else:
        sum = sum + i

print("Answer = %d" % sum)
