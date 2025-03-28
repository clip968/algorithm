import sys
input = sys.stdin.readline

n, m = map(int, input().split())
array = list(map(int, input().split()))

for i in range(n - 1):
    array[i + 1] += array[i]
array = [0] + array

for i in range(m):
    a, b = map(int, input().split())
    print(array[b] - array[a - 1])
    