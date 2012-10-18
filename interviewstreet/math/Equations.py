'''
Created on 20.07.2012

@author: dmitri
'''
import random 

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

def multiplicity(N, prime):
    scratch = N
    mul = 0
    while scratch != 0:
        scratch = scratch // prime
        mul += scratch
    return mul
    
N = int(raw_input())
primes, factors = [], {}
for n in xrange(2, N+1):
    if miller_rabin(n):
        primes.append(n)

res = 1
for p in primes:
    mul = multiplicity(N, p)
    if mul > 0:
        res = res * (2*mul+1)
        res = res % 1000007
print(res)
