m, n = map(int, input().split())

chessboard = [list(input().rstrip()) for _ in range(m)]
result = []

for i in range(m-7):
    for j in range(n-7):
        black = 0
        white = 0
        for a in range(i, i+8):
            for b in range(j, j+8):
                if (i + j) % 2 == 0:
                    if chessboard[i][j] == 'B':
                        white += 1
                    else:
                        black += 1
                else:
                    if chessboard[i][j] == 'B':
                        black += 1
                    else:
                        white += 1
        result.append(black)
        result.append(white)
print(min(result))
            
    