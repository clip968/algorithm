import sys

n, m, k = map(int, input().split())
chessboard = [input().rstrip() for _ in range(n)]

bCheck = [[0] * (m + 1) for _ in range(n + 1)]
wCheck = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        if (i + j) % 2 == 0:
            if chessboard[i-1][j-1] == 'B':
                bCheck[i][j] = bCheck[i-1][j] + bCheck[i][j-1] - bCheck[i-1][j-1]
                wCheck[i][j] = wCheck[i-1][j] + wCheck[i][j-1] - wCheck[i-1][j-1] + 1
            else:
                bCheck[i][j] = bCheck[i-1][j] + bCheck[i][j-1] - bCheck[i-1][j-1] + 1
                wCheck[i][j] = wCheck[i-1][j] + wCheck[i][j-1] - wCheck[i-1][j-1]
        else:
            if chessboard[i-1][j-1] == 'B':
                bCheck[i][j] = bCheck[i-1][j] + bCheck[i][j-1] - bCheck[i-1][j-1] + 1
                wCheck[i][j] = wCheck[i-1][j] + wCheck[i][j-1] - wCheck[i-1][j-1]
            else:
                bCheck[i][j] = bCheck[i-1][j] + bCheck[i][j-1] - bCheck[i-1][j-1] 
                wCheck[i][j] = wCheck[i-1][j] + wCheck[i][j-1] - wCheck[i-1][j-1] + 1
result = 1e9
for i in range(k, n + 1):
    for j in range(k, m + 1):
        bSum = bCheck[i][j] - bCheck[i-k][j] - bCheck[i][j-k] + bCheck[i-k][j-k]
        wSum = wCheck[i][j] - wCheck[i-k][j] - wCheck[i][j-k] + wCheck[i-k][j-k]
        result = min(bSum, wSum, result)
print(result)