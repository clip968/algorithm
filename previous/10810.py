n, m = map(int, input().split())
array = [0] * (n + 1)
for i in range(m):
    a, b, c = map(int, input().split())
    for j in range(a, b + 1):
        array[j] = c

for i in array[1:]:
    print(i, end=' ')