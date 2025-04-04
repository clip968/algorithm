n = int(input())
arr = [[] for _ in range(n + 1)]
dp = [0] * (n + 1)

for i in range(1, n + 1):
    arr[i] = int(input())
    
dp[1] = arr[1]

if n > 1:
    dp[2] = arr[1] + arr[2]
if n > 2:
    dp[3] = max(arr[1] + arr[2], arr[2] + arr[3], arr[1] + arr[3])
if n > 3:
    for i in range(4, n + 1):
        dp[i] = max(dp[i-1], arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3])
print(max(dp))
# dp[1] = arr[1]
# dp[2] = arr[2] + arr[1]
# dp[3] = max(arr[1] + arr[2], arr[2] + arr[3], arr[1] + arr[3])
# if n >= 4:
#     for i in range(4, n + 1):
#         dp[i] = max(dp[i-1], arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3])
    
# print(max(dp))
