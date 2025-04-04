n, k = map(int, input().split())    
coin = []

for _ in range(n):
    coin.append(int(input()))

result = 0
for i in reversed(range(n)):
    result += k // coin[i]
    k = k % coin[i]

print(result)