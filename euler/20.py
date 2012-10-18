sum = 0
for x in str(reduce(lambda x,y: x*y, range(1,101))):
    sum = sum + int(x)

print(sum)

