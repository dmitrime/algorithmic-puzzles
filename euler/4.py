p = 998001
for i in range(p, 1, -1):
    if str(i) == str(i)[::-1]:
        for j in range(999, 101, -1):
            if i % j == 0 and int(i/j) <= 999:
                print(i, j, i / j)
                break
        else:
            continue
        break
