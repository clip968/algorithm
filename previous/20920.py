import sys
import collections
input = sys.stdin.readline

n, m = map(int, input().split())
arr = []

for i in range(n):
    arr.append(input())

dic = dict(collections.Counter(arr))

result = dict(sorted(dic.items(), key = lambda x : (-x[1], -len(x[0]), x[0])))

for key in result.keys():
    if len(key) >= m + 1:
        print(key, end='')