import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
maximum = 100000
distance = [0] * (100001)
cnt = 0
result = 0
def bfs():
    global result, cnt
    q = deque()
    q.append(n)
    while q:
        x = q.popleft()
        if x == k:
            result = distance[x]
            cnt += 1
            continue
        for i in (x - 1, x + 1, x * 2):
            if 0 <= i <= maximum and (distance[i] == 0 or distance[i] == distance[x] + 1):
                distance[i] = distance[x] + 1
                q.append(i)

bfs()
print(result)
print(cnt)