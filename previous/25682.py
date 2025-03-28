import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
chessboard = [list(input().rstrip()) for _ in range(n)]

result = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, m + 1):
        if (i + j) % 2 == 0:
            if chessboard[i-1][j-1] == 'B':
                result[i][j] = result[i][j-1] + result[i-1][j] - result[i-1][j-1]
            else:
                result[i][j] = result[i][j-1] + result[i-1][j] - result[i-1][j-1] + 1
        else:
            if chessboard[i-1][j-1] == 'W':
                result[i][j] = result[i][j-1] + result[i-1][j] - result[i-1][j-1]
            else:
                result[i][j] = result[i][j-1] + result[i-1][j] - result[i-1][j-1] + 1
        
minimum = 1e9
maximum = -1e9

for i in range(k, n + 1):
    for j in range(k, m + 1):
        minimum = min(result[i][j] - result[i-k][j] - result[i][j-k] + result[i-k][j-k], minimum)
        maximum = max(result[i][j] - result[i-k][j] - result[i][j-k] + result[i-k][j-k], maximum)
print(min(minimum, k*k-minimum, maximum, k*k-maximum))

