import random

limit = 1458
primes = {}
dp = [ [ 0 for _ in range(10)] for _ in range(limit)]
def miller_rabin_pass(a, s, d, n):
    a_to_power = pow(a, d, n)
    if a_to_power == 1:
        return True
    for i in xrange(s-1):
        if a_to_power == n - 1:
            return True
        a_to_power = (a_to_power * a_to_power) % n
    return a_to_power == n - 1

def miller_rabin(n):
    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1
    for repeat in xrange(30):
        a = 0
        while a == 0:
            a = random.randrange(n)
        if not miller_rabin_pass(a, s, d, n):
            return False
    return True

def is_lucky(nums):
    return (sum(nums) in primes) and (sum(map(lambda x: x*x, nums)) in primes)

def digits(n):
    d = []
    while n > 0:
        d.append(n % 10)
        n = n // 10
    return d

def solve(p, times, mx, first, sq):
    if p < 0 or times > 17:
        return False
    if dp[p][mx]:
        return True
    if p == 0 and sq in primes:
        return True
    for di in xrange(0, mx+1):
        if first and di == 0:
            continue
        if solve(p-di, times+1, di, False, sq + di*di):
            dp[p][di] = times+1

def decompose():
    for p in xrange(1, limit):
        solve(p, 1, 9, True, 0)
        
    for x in dp[:20]:
        print(x)

if __name__ == "__main__":
    for n in xrange(2, limit):
        if miller_rabin(n):
            primes[n] = True
    for p in xrange(limit):
        print("primes[%d]=%d;" % (p, int(p in primes)))
#    decompose()
    
#N = int(raw_input())
#while N > 0:
#    N -= 1
#    s = raw_input().split()
#    A,B = int(s[0]), int(s[1])
#    inp = "Args: N=%d A=%d B=%d" % (N,A,B)
#    raise MemoryError(inp)

#N = 10000
#print(N)
#for i in xrange(N):
#    A, B = (random.randint(10**16, 10**18), random.randint(10**16,10**18))
#    print("%d %d" % (min(A,B),max(A,B)))
