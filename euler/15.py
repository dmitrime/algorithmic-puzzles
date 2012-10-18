n = 21
a = [[0 for x in range(0, n)] for y in range(0, n)]

a[0][0] = 1
for i in range(0, n):
    for j in range(0, n):
        if j > 0:
            a[i][j] = a[i][j] + a[i][j-1]
        if i > 0:
            a[i][j] = a[i][j] + a[i-1][j]

print(a[n-1][n-1])

