ds = 0
to = 0
for i in range(10001, 99999 + 1):
    if i % 5 == 0:
        continue
    if i % 7 == 0:
        ds = ds + 1
    to = to + 1

print("%d out of %d" % (ds, to))
print((0.0+ds)/to)
