def dfs(s):
    if len(arr) == m:
        print(' '.join(map(str, arr)))
        return
    for i in range(s, n + 1):
        if visited[i]:
            continue
        else:
            visited[i] = True
            arr.append(i)
            dfs(i + 1)
            arr.pop()
            visited[i] = False
            

n, m = map(int, input().split())    
arr = []
visited = [False] *  (n + 1)

dfs(1)
