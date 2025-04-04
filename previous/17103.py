import sys
input = sys.stdin.readline

prime = [True] * 1000001
prime[0] = False
prime[1] = False

for i in range(2, 1000001):
    if prime[i]:
        for j in range(i * 2, 1000001, i):
            prime[j] = False

T = int(input())

for i in range(T):
    count = 0
    n = int(input())
    for j in range(2, n // 2 + 1):
        if prime[j] and prime[n - j]:
            count += 1
            
    print(count)