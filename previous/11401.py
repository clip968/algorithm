import math, sys
input = sys.stdin.readline
p = 1000000007

def factorial(n):
    a = 1
    for i in range(2, n + 1):
        a = (a * i) % p
    return a

def func(n, k):
    if k == 0:
        return 1
    elif k == 1:
        return n
    
    temp = func(n, k//2)
    if k % 2:
        return temp * temp * n % p
    else:
        return temp * temp % p


n, k = map(int, input().split())

print(factorial(n) * func(factorial(n-k) * factorial(k) % p, p - 2) % p)

