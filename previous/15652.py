def dfs(s):
    if len(arr) == m:
        print(' '.join(map(str, arr)))
        return
    for i in range(s, n + 1):
        visited[i] = True
        arr.append(i)
        dfs(i)
        arr.pop()
        visited[i] = False
            

n, m = map(int, input().split())    
arr = []
visited = [False] *  (n + 1)

dfs(1)