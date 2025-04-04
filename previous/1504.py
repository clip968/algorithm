import sys, heapq
input = sys.stdin.readline
INF = int(1e9)  

n, e = map(int, input().split())
graph = [[] for i in range(n + 1)]
            
for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

def dijkstra(start, end):
    q = []
    heapq.heappush(q, (0, start))
    distance = [INF] * (n + 1)
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    
    return distance[end]

x1, x2 = map(int, input().split())  

route_1 = dijkstra(1, x1) + dijkstra(x1, x2) + dijkstra(x2, n)
route_2 = dijkstra(1, x2) + dijkstra(x2, x1) + dijkstra(x1, n)

result = min(route_1, route_2)
print(result if result < INF else -1)