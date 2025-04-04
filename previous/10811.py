n, m = map(int, input().split())    
array = [0] * (n + 1)

for i in range(1, n + 1):
    array[i] = i

for i in range(m):
    a, b = map(int, input().split())
    c = array[a:b+1]
    c.reverse()
    array[a:b+1] = c

for i in range(1, n+1):
    print(array[i], end=' ')
    

