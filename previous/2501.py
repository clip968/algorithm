import sys
input = sys.stdin.readline

n, m = map(int, input().split())
array = []
for i in range(1, n + 1):
    if n % i == 0:
        array.append(i)
try:
    print(array[m - 1])
except:
    print(0)
    