import sys
input = sys.stdin.readline
s = input()
q = int(input())
count = [[0 for i in range(26)] for _ in range(len(s) + 1)] 

for i in range(1, len(s) + 1):
    for j in range(26):
        if ord(s[i-1])-97 == j:
            count[i][j] = count[i-1][j] + 1
        else:
            count[i][j] = count[i-1][j]

for i in range(q):
    a, l ,r = map(str, input().split())
    result = count[int(r) + 1][ord(a) - 97] - count[int(l)][ord(a) - 97]
    print(result)