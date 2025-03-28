n, k, m = map(int, input().split())
def factorial(n):
    a = 1
    for i in range(2, n + 1):
        a = (a * i) % m
    return a

def func(n, k):
    if k == 0:
        return 1
    if k == 1:
        return n
    temp = func(n, k // 2)
    if k % 2:
        return temp * temp * n % m
    else:
        return temp * temp % m
    
print(factorial(n) * func(factorial(n-k) * factorial(k) % m, m - 2) % m)
