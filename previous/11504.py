n = int(input())
arr = list(map(int, input().split()))

increase = [1] * n
decrease = [1] * n

for i in range(n):
    for j in range(i):
        if arr[i] > arr[j]:
            increase[i] = max(increase[i], increase[j] + 1)

for i in range(n-1, -1, -1):
    for j in range(i, n):
        if arr[i] > arr[j]:
            decrease[i] = max(decrease[i], decrease[j] + 1)

result = []

for i in range(n):
    result.append(increase[i] + decrease[i])
    
print(max(result) - 1)