import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
maximum = 100000
distance = [0] * (100001)

def bfs():
    
    q = deque()
    q.append(n)
    while q:
        x = q.popleft()
        if x == k:
            print(distance[x])
            break
        for i in (x - 1, x + 1, x * 2):
            if 0 <= i <= maximum and not distance[i]:
                distance[i] = distance[x] + 1
                q.append(i)

bfs()