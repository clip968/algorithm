n, m = map(int, input().split())   
dicts = {} 
listen = []
cnt = 0
result = []
for i in range(n):
    a = input()
    dicts[a] = 0
for j in range(m):
    listen.append(input())
    
for check in listen:
    if dicts.get(check) != None:
        cnt += 1
        result.append(check)
    else:
        continue
result.sort()
print(cnt)
for i in result:
    print(i)
    