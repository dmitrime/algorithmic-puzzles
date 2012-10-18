def isLeap(y):
    return y % 4 == 0 and (y % 100 != 0 or y % 400 == 0)

months = [31,28,31,30,31,30,31,31,30,31,30,31]
day = 1
sundays = 0
for y in range(1901, 2000 + 1):
    for m in months:
        if day == 6:
            sundays = sundays + 1

        if m == 28 and isLeap(y):
            m = m + 1
        day = (day + m) % 7

print(sundays)

