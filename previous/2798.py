n, m = map(int, input().split())
arr = list(map(int, input().split()))  
cnt = []

for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            result = arr[i] + arr[j] + arr[k]
            if result > m:
                continue
            else:
                cnt.append(result)

print(max(cnt))