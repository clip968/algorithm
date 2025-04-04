import sys
input = sys.stdin.readline

def papers(x, y, n):
    global white, blue
    fcolor = arr[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if fcolor != arr[i][j]:
                papers(x, y, n // 2)
                papers(x + n // 2, y, n // 2)
                papers(x, y + n // 2, n // 2)
                papers(x + n // 2, y + n // 2, n // 2)
                return
    if fcolor == 0:
        white += 1
    else:
        blue += 1


n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
white, blue = 0, 0

papers(0, 0, n)
print(white)
print(blue)