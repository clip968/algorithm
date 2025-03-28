import sys, heapq
input = sys.stdin.readline

n = int(input())
arr = []
result = 0

for i in range(n):
    heapq.heappush(arr, int(input()))
    
if len(arr) == 1:
    print(0)
else:
    while len(arr) > 1:
        a = heapq.heappop(arr)
        b = heapq.heappop(arr)
        result += (a + b)
        heapq.heappush(arr, a + b)
    print(result)
        