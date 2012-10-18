'''
Created on 18.07.2012

@author: dmitri
'''

'''
5 2
1 5 3 4 2
'''

def binsearch(start, numbers, K):
    hi = len(numbers)-1
    lo = start
    while lo <= hi:
        mid = lo + ((hi-lo) // 2)
        diff = numbers[mid] - numbers[start]
        
        if diff > K:
            hi = mid-1
        elif diff < K:
            lo = mid+1
        elif diff == K:
            count = 1
            ind = mid-1
            while ind > start and (numbers[ind] - numbers[start] == K):
                count += 1
                ind -= 1
            ind = mid+1
            while ind < len(numbers) and (numbers[ind] - numbers[start] == K):
                count += 1
                ind += 1
            return count
    else:
        return 0

N, K = (int(x) for x in raw_input().split())
numbers = sorted([int(x) for x in raw_input().split()])
#with open("input01.txt") as f:
#    N, K = (int(x) for x in f.readline().split())
#    numbers = sorted([int(x) for x in f.readline().split()])       
counter = 0
for i in range(len(numbers)):
    counter += binsearch(i, numbers, K)
print(counter)