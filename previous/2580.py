import sys
input = sys.stdin.readline
def row(n, x):
    for i in range(9):
        if array[x][i] == n:
            return False
    return True

def column(n, x):
    for i in range(9):
        if array[i][x] == n:
            return False
    return True

def box(x, y, n):
    x = x // 3 * 3
    y = y // 3 * 3
    for i in range(3):
        for j in range(3):
            if array[x + i][y + j] == n:
                return False
    return True 

def dfs(num):
    if num == len(zero):
        for i in array:
            print(*i)
        exit()
    x = zero[num][0]    
    y = zero[num][1]
    for idx in range(1, 10):
        if row(idx, x) and column(idx, y) and box(x, y, idx):
            array[x][y] = idx
            dfs(num + 1)    
            array[x][y] = 0
        

array = [list(map(int, input().split())) for _ in range(9)]
zero = []
for i in range(9):
    for j in range(9):
        if array[i][j] == 0:
            zero.append([i, j])

dfs(0)