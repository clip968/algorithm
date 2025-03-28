N = int(input())
arr = []

for i in range(N):
    a, b = map(int, input().split())
    arr.append((a, b))

arr.sort(key=lambda x: (x[0], x[1]))

for i in arr:
    print(i[0], end=' ')
    print(i[1])