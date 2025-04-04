def find_parent(parent, x):
    if parent[x] != x:
        return find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
result = []
cnt = 0
n = int(input())
m = int(input())
parent = [0] * (n + 1)

for i in range(1, n + 1):
    parent[i] = i

for i in range(m):
    a, b = map(int, input().split())
    union_parent(parent, a, b)

for i in range(1, n + 1):
    result.append(find_parent(parent, i))

for i in result:
    if i == 1:
        cnt += 1

print(cnt - 1)
    