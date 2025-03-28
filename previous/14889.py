n = int(input())
array = [list(map(int, input().split())) for _ in range(4)]

minimum = 101

def dfs(cnt, result, j):
    global  minimum
    
    if cnt == n:
        minimum = min(minimum, result)
        return
    
    for i in range(0, n):
        dfs(cnt + 1, array[i][j] + array[j][i], j + 1)
    
dfs(1, 0, 0)

print(minimum)